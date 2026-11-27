#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "streamer_internal.h"
#include "../upstox.h"

#define RECV_CHUNK 16384
#define POLL_MS 100
#define SEND_TIMEOUT_MS 10000
#define CONNECT_TIMEOUT_S 30L
#define CONTROL_MAX 125

static upstox_streamer_callbacks_t snapshot(upstox_ws_t *ws) {
    pthread_mutex_lock(&ws->lock);
    upstox_streamer_callbacks_t cb = ws->cb;
    pthread_mutex_unlock(&ws->lock);
    return cb;
}

void upstox_ws_emit_error(upstox_ws_t *ws, const char *error) {
    upstox_streamer_callbacks_t cb = snapshot(ws);
    if (cb.on_error) {
        cb.on_error(error, cb.user_data);
    }
}

static void emit_open(upstox_ws_t *ws) {
    upstox_streamer_callbacks_t cb = snapshot(ws);
    if (cb.on_open) {
        cb.on_open(cb.user_data);
    }
}

static void emit_close(upstox_ws_t *ws, int status, const char *reason) {
    upstox_streamer_callbacks_t cb = snapshot(ws);
    if (cb.on_close) {
        cb.on_close(status, reason, cb.user_data);
    }
}

static void emit_reconnecting(upstox_ws_t *ws, const char *message) {
    upstox_streamer_callbacks_t cb = snapshot(ws);
    if (cb.on_reconnecting) {
        cb.on_reconnecting(message, cb.user_data);
    }
}

static void emit_stopped(upstox_ws_t *ws, const char *message) {
    upstox_streamer_callbacks_t cb = snapshot(ws);
    if (cb.on_auto_reconnect_stopped) {
        cb.on_auto_reconnect_stopped(message, cb.user_data);
    }
}

int upstox_ws_should_reconnect(int enable_auto_reconnect, int user_disconnect, int status_code) {
    return enable_auto_reconnect && !user_disconnect && status_code != UPSTOX_WS_CLOSE_NORMAL;
}

void upstox_ws_reconnect_message(char *buf, size_t size, int attempt, int retry_count) {
    snprintf(buf, size, "Auto reconnect attempt %d/%d", attempt, retry_count);
}

int upstox_ws_curl_has_wss(void) {
    const curl_version_info_data *info = curl_version_info(CURLVERSION_NOW);
    for (const char *const *p = info ? info->protocols : NULL; p && *p; p++) {
        if (strcmp(*p, "wss") == 0) {
            return 1;
        }
    }
    return 0;
}

char *upstox_ws_take_redirect_uri(websocket_auth_redirect_response_t *response) {
    char *uri = NULL;
    if (response && response->data && response->data->authorized_redirect_uri) {
        uri = strdup(response->data->authorized_redirect_uri);
    }
    if (response) {
        websocket_auth_redirect_response_free(response);
    }
    return uri;
}

void upstox_ws_init(upstox_ws_t *ws, apiClient_t *apiClient, const upstox_ws_ops_t *ops) {
    memset(ws, 0, sizeof(*ws));
    ws->apiClient = apiClient;
    ws->ops = ops;
    pthread_mutex_init(&ws->lock, NULL);
    pthread_cond_init(&ws->wake, NULL);
    ws->enable_auto_reconnect = 1;
    ws->interval = 1;
    ws->retry_count = 5;
}

void upstox_ws_destroy(upstox_ws_t *ws) {
    upstox_ws_disconnect(ws);
    free(ws->pending_url);
    ws->pending_url = NULL;
    pthread_cond_destroy(&ws->wake);
    pthread_mutex_destroy(&ws->lock);
}

void upstox_ws_set_callbacks(upstox_ws_t *ws, const upstox_streamer_callbacks_t *callbacks) {
    pthread_mutex_lock(&ws->lock);
    if (callbacks) {
        ws->cb = *callbacks;
    } else {
        memset(&ws->cb, 0, sizeof(ws->cb));
    }
    pthread_mutex_unlock(&ws->lock);
}

void upstox_ws_auto_reconnect(upstox_ws_t *ws, int enable, int interval_seconds, int retry_count) {
    pthread_mutex_lock(&ws->lock);
    ws->enable_auto_reconnect = enable;
    ws->interval = interval_seconds < 0 ? 0 : interval_seconds;
    ws->retry_count = retry_count;
    pthread_mutex_unlock(&ws->lock);
    if (!enable) {
        emit_stopped(ws, "Disabled by client.");
    }
}

// Waits until the socket is ready for events or timeout_ms passes.
static void wait_socket(curl_socket_t sock, short events, int timeout_ms) {
    if (sock == CURL_SOCKET_BAD) {
        poll(NULL, 0, timeout_ms);
        return;
    }
    struct pollfd pfd = { .fd = sock, .events = events, .revents = 0 };
    poll(&pfd, 1, timeout_ms);
}

static int send_frame_locked(upstox_ws_t *ws, const void *data, size_t len, unsigned int flags) {
    if (ws->curl == NULL) {
        return -1;
    }
    const unsigned char *p = data;
    size_t off = 0;
    int waited = 0;
    for (;;) {
        size_t sent = 0;
        CURLcode rc = curl_ws_send(ws->curl, p + off, len - off, &sent, 0, flags);
        off += sent;
        if (rc == CURLE_OK && off >= len) {
            return 0;
        }
        if (rc != CURLE_OK && rc != CURLE_AGAIN) {
            return -1;
        }
        if (waited >= SEND_TIMEOUT_MS) {
            return -1;
        }
        curl_socket_t sock = CURL_SOCKET_BAD;
        curl_easy_getinfo(ws->curl, CURLINFO_ACTIVESOCKET, &sock);
        wait_socket(sock, POLLOUT, POLL_MS);
        waited += POLL_MS;
    }
}

int upstox_ws_send_binary_locked(upstox_ws_t *ws, const void *data, size_t len) {
    return send_frame_locked(ws, data, len, CURLWS_BINARY);
}

static void send_close_locked(upstox_ws_t *ws, int status) {
    unsigned char payload[2] = { (unsigned char)(status >> 8), (unsigned char)(status & 0xff) };
    send_frame_locked(ws, payload, sizeof(payload), CURLWS_CLOSE);
}

// Aborts a handshake in progress once disconnect is requested.
static int handshake_progress(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    (void)dltotal; (void)dlnow; (void)ultotal; (void)ulnow;
    upstox_ws_t *ws = clientp;
    pthread_mutex_lock(&ws->lock);
    int stop = ws->stop;
    pthread_mutex_unlock(&ws->lock);
    return stop;
}

// Runs ops->authorize, reporting a failure through on_error; *unauthorized is set on HTTP 401.
static char *authorize(upstox_ws_t *ws, int *unauthorized) {
    char *url = ws->ops->authorize(ws);
    if (url) {
        return url;
    }
    long code = ws->apiClient->response_code;
    const char *body = ws->apiClient->errorBody;
    char msg[1024];
    snprintf(msg, sizeof(msg), "WebSocket authorization failed (HTTP %ld%s)%s%s", code, code == 401 ? " Unauthorized" : "",
             body ? ": " : "", body ? body : "");
    *unauthorized = code == 401;
    upstox_ws_emit_error(ws, msg);
    return NULL;
}

// Performs the websocket handshake; on failure reports through on_error and returns NULL.
static CURL *open_socket(upstox_ws_t *ws, const char *url, struct curl_slist **headers_out, int *unauthorized) {
    CURL *curl = curl_easy_init();
    if (curl == NULL) {
        upstox_ws_emit_error(ws, "WebSocket connect failed: curl_easy_init returned NULL");
        return NULL;
    }
    char errbuf[CURL_ERROR_SIZE] = "";
    struct curl_slist *headers = upstox_append_headers(ws->apiClient, NULL);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CONNECT_ONLY, 2L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, CONNECT_TIMEOUT_S);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, handshake_progress);
    curl_easy_setopt(curl, CURLOPT_XFERINFODATA, ws);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    sslConfig_t *ssl = ws->apiClient->sslConfig;
    if (ssl) {
        if (ssl->clientCertFile) {
            curl_easy_setopt(curl, CURLOPT_SSLCERT, ssl->clientCertFile);
        }
        if (ssl->clientKeyFile) {
            curl_easy_setopt(curl, CURLOPT_SSLKEY, ssl->clientKeyFile);
        }
        if (ssl->CACertFile) {
            curl_easy_setopt(curl, CURLOPT_CAINFO, ssl->CACertFile);
        }
        if (ssl->insecureSkipTlsVerify) {
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        }
    }
    if (ws->apiClient->curlConfig && ws->apiClient->curlConfig->verbose) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    }

    CURLcode rc = curl_easy_perform(curl);
    // errbuf and the progress hook must not outlive this call
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, NULL);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    if (rc == CURLE_OK) {
        *headers_out = headers;
        return curl;
    }
    long code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
    char msg[CURL_ERROR_SIZE + 128];
    snprintf(msg, sizeof(msg), "WebSocket connect failed: %s (HTTP %ld%s)", errbuf[0] ? errbuf : curl_easy_strerror(rc), code,
             code == 401 ? " Unauthorized" : "");
    *unauthorized = code == 401;
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    upstox_ws_emit_error(ws, msg);
    return NULL;
}

static int append(unsigned char **buf, size_t *len, size_t *cap, const unsigned char *data, size_t n) {
    if (*len + n + 1 > *cap) {
        size_t next = *cap ? *cap : RECV_CHUNK;
        while (next < *len + n + 1) {
            next *= 2;
        }
        unsigned char *grown = realloc(*buf, next);
        if (grown == NULL) {
            return -1;
        }
        *buf = grown;
        *cap = next;
    }
    memcpy(*buf + *len, data, n);
    *len += n;
    (*buf)[*len] = '\0';
    return 0;
}

// Reads until close, error or disconnect; returns the close status and sets *reason (malloc'd or NULL).
static int recv_loop(upstox_ws_t *ws, char **reason) {
    unsigned char *chunk = malloc(RECV_CHUNK);
    unsigned char *msg = NULL;
    size_t msg_len = 0, msg_cap = 0;
    unsigned char ctrl[CONTROL_MAX];
    size_t ctrl_len = 0;
    int status = UPSTOX_WS_CLOSE_ABNORMAL;
    if (chunk == NULL) {
        *reason = strdup("out of memory");
        return status;
    }
    for (;;) {
        size_t n = 0;
        const struct curl_ws_frame *meta = NULL;
        curl_socket_t sock = CURL_SOCKET_BAD;
        int flags = 0;
        curl_off_t left = 0;

        pthread_mutex_lock(&ws->lock);
        if (ws->stop) {
            pthread_mutex_unlock(&ws->lock);
            status = UPSTOX_WS_CLOSE_NORMAL;
            break;
        }
        CURLcode rc = curl_ws_recv(ws->curl, chunk, RECV_CHUNK, &n, &meta);
        if (rc == CURLE_OK && meta) {
            flags = meta->flags;
            left = meta->bytesleft;
        } else if (rc == CURLE_AGAIN) {
            curl_easy_getinfo(ws->curl, CURLINFO_ACTIVESOCKET, &sock);
        }
        pthread_mutex_unlock(&ws->lock);

        if (rc == CURLE_AGAIN) {
            // poll without the lock so senders are not blocked while idle
            wait_socket(sock, POLLIN, POLL_MS);
            continue;
        }
        if (rc != CURLE_OK) {
            *reason = strdup(curl_easy_strerror(rc));
            upstox_ws_emit_error(ws, *reason);
            break;
        }
        if (flags & CURLWS_CLOSE) {
            size_t take = n < CONTROL_MAX - ctrl_len ? n : CONTROL_MAX - ctrl_len;
            memcpy(ctrl + ctrl_len, chunk, take);
            ctrl_len += take;
            if (left > 0) {
                continue;
            }
            status = ctrl_len >= 2 ? (ctrl[0] << 8) | ctrl[1] : UPSTOX_WS_CLOSE_NO_STATUS;
            if (ctrl_len > 2) {
                *reason = strndup((const char *)ctrl + 2, ctrl_len - 2);
            }
            pthread_mutex_lock(&ws->lock);
            send_close_locked(ws, status == UPSTOX_WS_CLOSE_NO_STATUS ? UPSTOX_WS_CLOSE_NORMAL : status);
            pthread_mutex_unlock(&ws->lock);
            break;
        }
        if (!(flags & (CURLWS_TEXT | CURLWS_BINARY))) {
            continue; // libcurl answers pings itself
        }
        if (append(&msg, &msg_len, &msg_cap, chunk, n) != 0) {
            *reason = strdup("out of memory");
            upstox_ws_emit_error(ws, *reason);
            break;
        }
        if (left == 0 && !(flags & CURLWS_CONT)) {
            if (ws->ops->on_message) {
                ws->ops->on_message(ws, msg, msg_len, (flags & CURLWS_BINARY) != 0);
            }
            msg_len = 0;
        }
    }
    free(msg);
    free(chunk);
    return status;
}

// Sleeps interval seconds unless disconnect wakes it; returns 1 when stopped.
static int wait_interval(upstox_ws_t *ws, int seconds) {
    struct timeval now;
    gettimeofday(&now, NULL);
    struct timespec until = { .tv_sec = now.tv_sec + seconds, .tv_nsec = (long)now.tv_usec * 1000 };
    pthread_mutex_lock(&ws->lock);
    while (!ws->stop) {
        if (pthread_cond_timedwait(&ws->wake, &ws->lock, &until) == ETIMEDOUT) {
            break;
        }
    }
    int stop = ws->stop;
    pthread_mutex_unlock(&ws->lock);
    return stop;
}

// Receive thread: connects, reads, and auto-reconnects as streamer.py does.
static void *run(void *arg) {
    upstox_ws_t *ws = arg;
    pthread_mutex_lock(&ws->lock);
    char *url = ws->pending_url;
    ws->pending_url = NULL;
    pthread_mutex_unlock(&ws->lock);
    int reconnecting = 0;

    for (;;) {
        int unauthorized = 0;
        if (url == NULL) {
            url = authorize(ws, &unauthorized);
        }
        struct curl_slist *headers = NULL;
        CURL *curl = url ? open_socket(ws, url, &headers, &unauthorized) : NULL;
        free(url);
        url = NULL;

        int status = UPSTOX_WS_CLOSE_ABNORMAL;
        char *reason = NULL;
        pthread_mutex_lock(&ws->lock);
        if (curl && ws->stop) {
            pthread_mutex_unlock(&ws->lock);
            curl_easy_cleanup(curl);
            curl_slist_free_all(headers);
            break;
        }
        if (curl) {
            ws->curl = curl;
            ws->headers = headers;
            ws->reconnect_attempts = 0;
            reconnecting = 0;
            if (ws->ops->on_open) {
                ws->ops->on_open(ws);
            }
            pthread_mutex_unlock(&ws->lock);
            emit_open(ws);
            status = recv_loop(ws, &reason);
            pthread_mutex_lock(&ws->lock);
            curl_easy_cleanup(ws->curl);
            curl_slist_free_all(ws->headers);
            ws->curl = NULL;
            ws->headers = NULL;
        }
        int stop = ws->stop;
        int enable = ws->enable_auto_reconnect;
        int retries = ws->retry_count;
        int interval = ws->interval;
        int attempts = ws->reconnect_attempts;
        pthread_mutex_unlock(&ws->lock);

        // Like streamer.py, close is not reported for failed reconnect attempts
        if (curl || !reconnecting) {
            emit_close(ws, stop ? UPSTOX_WS_CLOSE_NORMAL : status, reason ? reason : "");
        }
        free(reason);
        if (stop || unauthorized) {
            break;
        }
        if (!reconnecting && !upstox_ws_should_reconnect(enable, stop, status)) {
            break;
        }
        if (attempts >= retries) {
            char msg[64];
            snprintf(msg, sizeof(msg), "retryCount of %d exhausted.", retries);
            emit_stopped(ws, msg);
            break;
        }
        if (!enable || (reconnecting && wait_interval(ws, interval))) {
            break;
        }

        pthread_mutex_lock(&ws->lock);
        attempts = ++ws->reconnect_attempts;
        pthread_mutex_unlock(&ws->lock);
        reconnecting = 1;
        char msg[64];
        upstox_ws_reconnect_message(msg, sizeof(msg), attempts, retries);
        emit_reconnecting(ws, msg);
    }

    free(url);
    pthread_mutex_lock(&ws->lock);
    ws->running = 0;
    pthread_mutex_unlock(&ws->lock);
    return NULL;
}

int upstox_ws_connect(upstox_ws_t *ws) {
    if (!upstox_ws_curl_has_wss()) {
        upstox_ws_emit_error(ws, "libcurl has no WebSocket (wss) support; use curl >= 7.86 built with websockets");
        return -1;
    }
    pthread_mutex_lock(&ws->lock);
    if (ws->thread_started && ws->running) {
        pthread_mutex_unlock(&ws->lock);
        return 0;
    }
    int join = ws->thread_started;
    ws->thread_started = 0;
    pthread_mutex_unlock(&ws->lock);
    if (join) {
        pthread_join(ws->thread, NULL);
    }

    int unauthorized = 0;
    char *url = authorize(ws, &unauthorized);
    if (url == NULL) {
        return -1;
    }
    pthread_mutex_lock(&ws->lock);
    ws->stop = 0;
    ws->reconnect_attempts = 0;
    ws->pending_url = url;
    ws->running = 1;
    ws->thread_started = 1;
    if (pthread_create(&ws->thread, NULL, run, ws) != 0) {
        ws->running = 0;
        ws->thread_started = 0;
        free(ws->pending_url);
        ws->pending_url = NULL;
        pthread_mutex_unlock(&ws->lock);
        upstox_ws_emit_error(ws, "WebSocket connect failed: could not start the receive thread");
        return -1;
    }
    pthread_mutex_unlock(&ws->lock);
    return 0;
}

void upstox_ws_disconnect(upstox_ws_t *ws) {
    pthread_mutex_lock(&ws->lock);
    ws->stop = 1;
    if (ws->curl) {
        send_close_locked(ws, UPSTOX_WS_CLOSE_NORMAL);
    }
    pthread_cond_broadcast(&ws->wake);
    // A callback calling disconnect cannot join its own thread; the next connect or free joins it
    int join = ws->thread_started && !pthread_equal(ws->thread, pthread_self());
    if (join) {
        ws->thread_started = 0;
    }
    pthread_mutex_unlock(&ws->lock);
    if (join) {
        pthread_join(ws->thread, NULL);
    }
}
