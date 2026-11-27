// Offline unit tests for the websocket feeder; the end-to-end cases use a loopback mock server, never the Upstox API.

#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include "../upstox.h"
#include "../external/cJSON.h"
#include "market_data_streamer_v3.h"
#include "portfolio_data_streamer.h"
#include "streamer_internal.h"

static int failures = 0;

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            fprintf(stderr, "%s:%d: check failed: %s\n", __FILE__, __LINE__, #cond); \
            failures++;                                                      \
        }                                                                    \
    } while (0)

// ---- callback recorder ----

typedef struct events_t {
    pthread_mutex_t lock;
    int opens, closes, last_close, errors, reconnecting, stopped, messages;
    char last_reason[128], last_error[512], last_reconnecting[128], last_stopped[128];
    char last_key[64], last_text[256];
    double last_ltp;
} events_t;

static events_t ev = { .lock = PTHREAD_MUTEX_INITIALIZER };

static void reset_events(void) {
    pthread_mutex_lock(&ev.lock);
    pthread_mutex_t lock = ev.lock;
    memset(&ev, 0, sizeof(ev));
    ev.lock = lock;
    pthread_mutex_unlock(&ev.lock);
}

static void copy(char *dst, size_t size, const char *src) {
    snprintf(dst, size, "%s", src ? src : "");
}

static void on_open(void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.opens++;
    pthread_mutex_unlock(&ev.lock);
}

static void on_close(int status, const char *reason, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.closes++;
    ev.last_close = status;
    copy(ev.last_reason, sizeof(ev.last_reason), reason);
    pthread_mutex_unlock(&ev.lock);
}

static void on_error(const char *error, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.errors++;
    copy(ev.last_error, sizeof(ev.last_error), error);
    pthread_mutex_unlock(&ev.lock);
}

static void on_reconnecting(const char *message, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.reconnecting++;
    copy(ev.last_reconnecting, sizeof(ev.last_reconnecting), message);
    pthread_mutex_unlock(&ev.lock);
}

static void on_stopped(const char *message, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.stopped++;
    copy(ev.last_stopped, sizeof(ev.last_stopped), message);
    pthread_mutex_unlock(&ev.lock);
}

static void on_feed(const upstox_feed_response_t *feed, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.messages++;
    if (feed->n_feeds == 1 && feed->feeds[0]->value && feed->feeds[0]->value->ltpc) {
        copy(ev.last_key, sizeof(ev.last_key), feed->feeds[0]->key);
        ev.last_ltp = feed->feeds[0]->value->ltpc->ltp;
    }
    pthread_mutex_unlock(&ev.lock);
}

static void on_text(const char *message, void *ud) {
    (void)ud;
    pthread_mutex_lock(&ev.lock);
    ev.messages++;
    copy(ev.last_text, sizeof(ev.last_text), message);
    pthread_mutex_unlock(&ev.lock);
}

static const upstox_streamer_callbacks_t callbacks = { on_open, on_close, on_error, on_reconnecting, on_stopped, NULL };

// Polls until *counter reaches want or 10 s pass; returns 1 on success.
static int wait_for(int *counter, int want) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&ev.lock);
        int v = *counter;
        pthread_mutex_unlock(&ev.lock);
        if (v >= want) {
            return 1;
        }
        usleep(10000);
    }
    return 0;
}

// ---- protobuf helper ----

static size_t pack_feed(unsigned char **out, const char *key, double ltp) {
    Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__LTPC ltpc = COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__LTPC__INIT;
    ltpc.ltp = ltp;
    ltpc.ltt = 1700000000000;
    ltpc.cp = 2490.25;
    Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__Feed feed = COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED__INIT;
    feed.feed_union_case = COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED__FEED_UNION_LTPC;
    feed.ltpc = &ltpc;
    Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__FeedResponse__FeedsEntry entry =
        COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED_RESPONSE__FEEDS_ENTRY__INIT;
    entry.key = (char *)key;
    entry.value = &feed;
    Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__FeedResponse__FeedsEntry *entries[1] = { &entry };
    upstox_feed_response_t resp = COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED_RESPONSE__INIT;
    resp.type = COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__TYPE__live_feed;
    resp.n_feeds = 1;
    resp.feeds = entries;
    resp.currentts = 1700000000123;
    size_t len = com__upstox__marketdatafeederv3udapi__rpc__proto__feed_response__get_packed_size(&resp);
    *out = malloc(len);
    com__upstox__marketdatafeederv3udapi__rpc__proto__feed_response__pack(&resp, *out);
    return len;
}

// ---- unit tests ----

static void test_create(apiClient_t *client) {
    const char *keys[] = { "NSE_EQ|INE002A01018", "NSE_INDEX|Nifty 50" };
    CHECK(market_data_streamer_v3_create(client, keys, 2, "bogus") == NULL);
    CHECK(market_data_streamer_v3_create(client, keys, 2, NULL) == NULL);
    CHECK(market_data_streamer_v3_create(NULL, keys, 2, UPSTOX_MODE_LTPC) == NULL);
    const char *valid[] = { UPSTOX_MODE_LTPC, UPSTOX_MODE_FULL, UPSTOX_MODE_OPTION_GREEKS, UPSTOX_MODE_FULL_D30 };
    for (int i = 0; i < 4; i++) {
        market_data_streamer_v3_t *s = market_data_streamer_v3_create(client, keys, 2, valid[i]);
        CHECK(s != NULL);
        market_data_streamer_v3_free(s);
    }
    CHECK(!upstox_mdv3_valid_mode("full_d5"));
    CHECK(portfolio_data_streamer_create(NULL, 1, 0, 0, 0) == NULL);
}

static void test_build_request(void) {
    const char *keys[] = { "NSE_EQ|INE002A01018", "NSE_INDEX|Nifty 50" };
    char *json = upstox_mdv3_build_request("sub", keys, 2, UPSTOX_MODE_FULL);
    CHECK(json != NULL);
    cJSON *root = cJSON_Parse(json);
    CHECK(root != NULL);
    cJSON *guid = cJSON_GetObjectItem(root, "guid");
    CHECK(cJSON_IsString(guid) && strlen(guid->valuestring) == 36 && guid->valuestring[14] == '4');
    CHECK(strcmp(cJSON_GetObjectItem(root, "method")->valuestring, "sub") == 0);
    cJSON *data = cJSON_GetObjectItem(root, "data");
    CHECK(strcmp(cJSON_GetObjectItem(data, "mode")->valuestring, "full") == 0);
    cJSON *arr = cJSON_GetObjectItem(data, "instrumentKeys");
    CHECK(cJSON_GetArraySize(arr) == 2);
    CHECK(strcmp(cJSON_GetArrayItem(arr, 1)->valuestring, "NSE_INDEX|Nifty 50") == 0);
    cJSON_Delete(root);

    char *again = upstox_mdv3_build_request("sub", keys, 2, UPSTOX_MODE_FULL);
    CHECK(again && strncmp(json + 9, again + 9, 36) != 0); // fresh guid per request
    free(again);
    free(json);

    json = upstox_mdv3_build_request("unsub", keys, 1, NULL);
    root = cJSON_Parse(json);
    data = cJSON_GetObjectItem(root, "data");
    CHECK(strcmp(cJSON_GetObjectItem(root, "method")->valuestring, "unsub") == 0);
    CHECK(cJSON_GetObjectItem(data, "mode") == NULL);
    CHECK(cJSON_GetArraySize(cJSON_GetObjectItem(data, "instrumentKeys")) == 1);
    cJSON_Delete(root);
    free(json);

    CHECK(upstox_mdv3_build_request(NULL, keys, 1, NULL) == NULL);
    CHECK(upstox_mdv3_build_request("sub", NULL, 1, NULL) == NULL);
}

static void test_update_types(void) {
    char *s = upstox_portfolio_update_types(1, 0, 0, 0);
    CHECK(s && strcmp(s, "order") == 0);
    free(s);
    s = upstox_portfolio_update_types(1, 1, 1, 1);
    CHECK(s && strcmp(s, "order%2Cholding%2Cposition%2Cgtt_order") == 0);
    free(s);
    s = upstox_portfolio_update_types(0, 1, 0, 1);
    CHECK(s && strcmp(s, "position%2Cgtt_order") == 0);
    free(s);
    CHECK(upstox_portfolio_update_types(0, 0, 0, 0) == NULL);
}

static void test_reconnect_rules(void) {
    CHECK(upstox_ws_should_reconnect(1, 0, 1006));
    CHECK(upstox_ws_should_reconnect(1, 0, 1001));
    CHECK(!upstox_ws_should_reconnect(1, 0, 1000));
    CHECK(!upstox_ws_should_reconnect(1, 1, 1006));
    CHECK(!upstox_ws_should_reconnect(0, 0, 1006));
    char buf[64];
    upstox_ws_reconnect_message(buf, sizeof(buf), 2, 5);
    CHECK(strcmp(buf, "Auto reconnect attempt 2/5") == 0);
}

static void test_decode_and_offline_calls(apiClient_t *client) {
    const char *keys[] = { "NSE_EQ|INE002A01018" };
    market_data_streamer_v3_t *s = market_data_streamer_v3_create(client, keys, 1, UPSTOX_MODE_LTPC);
    market_data_streamer_v3_set_callbacks(s, &callbacks, on_feed);
    reset_events();

    // The streamer embeds the core first, so the message hook can be driven directly
    upstox_ws_t *ws = (upstox_ws_t *)s;
    unsigned char *buf = NULL;
    size_t len = pack_feed(&buf, keys[0], 2501.5);
    ws->ops->on_message(ws, buf, len, 1);
    free(buf);
    CHECK(ev.messages == 1 && ev.last_ltp == 2501.5 && strcmp(ev.last_key, keys[0]) == 0);

    const unsigned char junk[] = { 0xff, 0xff, 0xff, 0xff, 0x0f };
    ws->ops->on_message(ws, junk, sizeof(junk), 1);
    CHECK(ev.errors == 1 && strstr(ev.last_error, "decode") != NULL);

    // Not connected: subscription calls fail; invalid modes also report on_error
    CHECK(market_data_streamer_v3_subscribe(s, keys, 1, UPSTOX_MODE_FULL) == -1);
    CHECK(market_data_streamer_v3_unsubscribe(s, keys, 1) == -1);
    CHECK(market_data_streamer_v3_change_mode(s, keys, 1, UPSTOX_MODE_FULL) == -1);
    CHECK(market_data_streamer_v3_subscribe(s, keys, 1, "bogus") == -1);
    CHECK(ev.errors == 2 && strcmp(ev.last_error, "Invalid mode provided bogus") == 0);
    CHECK(market_data_streamer_v3_change_mode(s, keys, 1, "bogus") == -1 && ev.errors == 3);

    market_data_streamer_v3_auto_reconnect(s, 0, 1, 5);
    CHECK(ev.stopped == 1 && strcmp(ev.last_stopped, "Disabled by client.") == 0);

    market_data_streamer_v3_disconnect(s); // never connected: a no-op
    market_data_streamer_v3_free(s);

    portfolio_data_streamer_t *p = portfolio_data_streamer_create(client, 1, 0, 0, 0);
    portfolio_data_streamer_set_callbacks(p, &callbacks, on_text);
    reset_events();
    ws = (upstox_ws_t *)p;
    const char text[] = "{\"type\":\"order\"}";
    ws->ops->on_message(ws, (const unsigned char *)text, strlen(text), 0);
    CHECK(ev.messages == 1 && strcmp(ev.last_text, text) == 0);
    portfolio_data_streamer_disconnect(p);
    portfolio_data_streamer_free(p);
}

// ---- loopback mock server (plain ws://) ----

static uint32_t rol(uint32_t v, int n) {
    return (v << n) | (v >> (32 - n));
}

static void sha1(const unsigned char *data, size_t len, unsigned char out[20]) {
    uint32_t h[5] = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 };
    size_t total = ((len + 8) / 64 + 1) * 64;
    unsigned char *msg = calloc(total, 1);
    memcpy(msg, data, len);
    msg[len] = 0x80;
    uint64_t bits = (uint64_t)len * 8;
    for (int i = 0; i < 8; i++) {
        msg[total - 1 - i] = (unsigned char)(bits >> (8 * i));
    }
    for (size_t off = 0; off < total; off += 64) {
        uint32_t w[80];
        for (int i = 0; i < 16; i++) {
            const unsigned char *p = msg + off + 4 * i;
            w[i] = (uint32_t)p[0] << 24 | (uint32_t)p[1] << 16 | (uint32_t)p[2] << 8 | p[3];
        }
        for (int i = 16; i < 80; i++) {
            w[i] = rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4];
        for (int i = 0; i < 80; i++) {
            uint32_t f, k;
            if (i < 20) {
                f = (b & c) | (~b & d), k = 0x5A827999;
            } else if (i < 40) {
                f = b ^ c ^ d, k = 0x6ED9EBA1;
            } else if (i < 60) {
                f = (b & c) | (b & d) | (c & d), k = 0x8F1BBCDC;
            } else {
                f = b ^ c ^ d, k = 0xCA62C1D6;
            }
            uint32_t t = rol(a, 5) + f + e + k + w[i];
            e = d, d = c, c = rol(b, 30), b = a, a = t;
        }
        h[0] += a, h[1] += b, h[2] += c, h[3] += d, h[4] += e;
    }
    free(msg);
    for (int i = 0; i < 20; i++) {
        out[i] = (unsigned char)(h[i / 4] >> (24 - 8 * (i % 4)));
    }
}

static void base64(const unsigned char *in, size_t len, char *out) {
    static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t o = 0;
    for (size_t i = 0; i < len; i += 3) {
        uint32_t v = (uint32_t)in[i] << 16 | (i + 1 < len ? (uint32_t)in[i + 1] << 8 : 0) | (i + 2 < len ? in[i + 2] : 0);
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = i + 1 < len ? tbl[(v >> 6) & 63] : '=';
        out[o++] = i + 2 < len ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
}

static void ws_accept_key(const char *key, char out[32]) {
    char buf[128];
    snprintf(buf, sizeof(buf), "%s258EAFA5-E914-47DA-95CA-C5AB0DC85B11", key);
    unsigned char digest[20];
    sha1((const unsigned char *)buf, strlen(buf), digest);
    base64(digest, 20, out);
}

enum { SCENARIO_MARKET, SCENARIO_RETRIES, SCENARIO_PORTFOLIO, SCENARIO_CLEARED };

typedef struct mock_server_t {
    int scenario;
    int listen_fd;
    int port;
    char auth_request[256];  // request line of the first authorize call
    int upgrade_had_auth;    // the upgrade carried the Bearer token
    char frames[3][512];     // client data frames, in order
    int frame_count;
    int close_code;          // code of the client's close frame, -1 if none
    char error[128];
} mock_server_t;

static int accept_client(mock_server_t *s) {
    struct pollfd pfd = { .fd = s->listen_fd, .events = POLLIN, .revents = 0 };
    if (poll(&pfd, 1, 10000) <= 0) {
        return -1;
    }
    int fd = accept(s->listen_fd, NULL, NULL);
    struct timeval tv = { .tv_sec = 10, .tv_usec = 0 };
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    return fd;
}

static int read_full(int fd, void *buf, size_t len) {
    size_t got = 0;
    while (got < len) {
        ssize_t n = recv(fd, (char *)buf + got, len - got, 0);
        if (n <= 0) {
            return -1;
        }
        got += (size_t)n;
    }
    return 0;
}

static int read_http_request(int fd, char *buf, size_t size) {
    size_t len = 0;
    while (len + 1 < size) {
        if (recv(fd, buf + len, 1, 0) != 1) {
            return -1;
        }
        buf[++len] = '\0';
        if (len >= 4 && strcmp(buf + len - 4, "\r\n\r\n") == 0) {
            return 0;
        }
    }
    return -1;
}

static void write_all(int fd, const void *buf, size_t len) {
    if (send(fd, buf, len, 0) != (ssize_t)len) {
        perror("mock send");
    }
}

static int serve_authorize(mock_server_t *s, int record) {
    int fd = accept_client(s);
    if (fd < 0) {
        return -1;
    }
    char req[2048];
    if (read_http_request(fd, req, sizeof(req)) != 0) {
        close(fd);
        return -1;
    }
    if (record) {
        snprintf(s->auth_request, sizeof(s->auth_request), "%.*s", (int)strcspn(req, "\r"), req);
    }
    char body[256], resp[512];
    snprintf(body, sizeof(body), "{\"status\":\"success\",\"data\":{\"authorized_redirect_uri\":\"ws://127.0.0.1:%d/feed?code=x\"}}",
             s->port);
    snprintf(resp, sizeof(resp),
             "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: %zu\r\nConnection: close\r\n\r\n%s",
             strlen(body), body);
    write_all(fd, resp, strlen(resp));
    close(fd);
    return 0;
}

static int serve_upgrade(mock_server_t *s) {
    int fd = accept_client(s);
    if (fd < 0) {
        return -1;
    }
    char req[4096];
    if (read_http_request(fd, req, sizeof(req)) != 0) {
        close(fd);
        return -1;
    }
    if (strstr(req, "Authorization: Bearer test-token\r\n")) {
        s->upgrade_had_auth = 1;
    }
    const char *k = strcasestr(req, "Sec-WebSocket-Key:");
    char key[64] = "";
    if (k) {
        k += strlen("Sec-WebSocket-Key:");
        while (*k == ' ') {
            k++;
        }
        snprintf(key, sizeof(key), "%.*s", (int)strcspn(k, "\r"), k);
    }
    char accept_key[32], resp[256];
    ws_accept_key(key, accept_key);
    snprintf(resp, sizeof(resp),
             "HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\nSec-WebSocket-Accept: %s\r\n\r\n",
             accept_key);
    write_all(fd, resp, strlen(resp));
    return fd;
}

// Reads one masked client frame; returns its opcode or -1.
static int read_frame(int fd, unsigned char *payload, size_t cap, size_t *len) {
    unsigned char hdr[2], mask[4], ext[8];
    if (read_full(fd, hdr, 2) != 0) {
        return -1;
    }
    uint64_t n = hdr[1] & 0x7f;
    if (n == 126) {
        if (read_full(fd, ext, 2) != 0) {
            return -1;
        }
        n = (uint64_t)ext[0] << 8 | ext[1];
    } else if (n == 127) {
        if (read_full(fd, ext, 8) != 0) {
            return -1;
        }
        n = 0;
        for (int i = 0; i < 8; i++) {
            n = n << 8 | ext[i];
        }
    }
    if (n >= cap || ((hdr[1] & 0x80) && read_full(fd, mask, 4) != 0) || read_full(fd, payload, (size_t)n) != 0) {
        return -1;
    }
    for (size_t i = 0; (hdr[1] & 0x80) && i < n; i++) {
        payload[i] ^= mask[i % 4];
    }
    payload[n] = '\0';
    *len = (size_t)n;
    return hdr[0] & 0x0f;
}

static void write_frame(int fd, int opcode, const void *data, size_t len) {
    unsigned char hdr[4] = { (unsigned char)(0x80 | opcode) };
    size_t hlen = 2;
    if (len < 126) {
        hdr[1] = (unsigned char)len;
    } else {
        hdr[1] = 126, hdr[2] = (unsigned char)(len >> 8), hdr[3] = (unsigned char)len;
        hlen = 4;
    }
    write_all(fd, hdr, hlen);
    write_all(fd, data, len);
}

static int record_data_frame(mock_server_t *s, int fd) {
    unsigned char buf[512];
    size_t len = 0;
    int op = read_frame(fd, buf, sizeof(buf), &len);
    if (op != 2 || s->frame_count >= 3) {
        return -1;
    }
    copy(s->frames[s->frame_count++], sizeof(s->frames[0]), (const char *)buf);
    return 0;
}

// Records further data frames until the client's close frame.
static void await_close(mock_server_t *s, int fd) {
    unsigned char buf[512];
    size_t len = 0;
    for (;;) {
        int op = read_frame(fd, buf, sizeof(buf), &len);
        if (op == 8) {
            s->close_code = len >= 2 ? (buf[0] << 8 | buf[1]) : 1005;
            return;
        }
        if (op != 2 || s->frame_count >= 3) {
            return;
        }
        copy(s->frames[s->frame_count++], sizeof(s->frames[0]), (const char *)buf);
    }
}

static void send_feed(int fd, double ltp) {
    unsigned char *buf = NULL;
    size_t len = pack_feed(&buf, "NSE_EQ|INE002A01018", ltp);
    write_frame(fd, 2, buf, len);
    free(buf);
}

static void *mock_server_run(void *arg) {
    mock_server_t *s = arg;
    int fd = -1;
#define STEP(cond, what)                                    \
    if (!(cond)) {                                          \
        copy(s->error, sizeof(s->error), what);             \
        goto done;                                          \
    }
    STEP(serve_authorize(s, 1) == 0, "first authorize");
    STEP((fd = serve_upgrade(s)) >= 0, "first upgrade");
    if (s->scenario == SCENARIO_PORTFOLIO) {
        const char *text = "{\"update_type\":\"order\",\"status\":\"complete\"}";
        write_frame(fd, 1, text, strlen(text));
        const char close_payload[] = "\x03\xe8" "bye";
        write_frame(fd, 8, close_payload, 5);
        await_close(s, fd);
        goto done;
    }
    if (s->scenario == SCENARIO_CLEARED) {
        send_feed(fd, 2500.5);
        await_close(s, fd); // records any subscribe the client sends
        goto done;
    }
    STEP(record_data_frame(s, fd) == 0, "initial subscribe");
    send_feed(fd, 2500.5);
    if (s->scenario == SCENARIO_RETRIES) {
        close(s->listen_fd); // every reconnect attempt is refused from here on
        s->listen_fd = -1;
    }
    close(fd); // abnormal drop, no close frame
    fd = -1;
    if (s->scenario == SCENARIO_RETRIES) {
        goto done;
    }
    STEP(serve_authorize(s, 0) == 0, "reconnect authorize");
    STEP((fd = serve_upgrade(s)) >= 0, "reconnect upgrade");
    STEP(record_data_frame(s, fd) == 0, "resubscribe");
    send_feed(fd, 2510.75);
    await_close(s, fd);
done:
    if (fd >= 0) {
        close(fd);
    }
    return NULL;
}

static int mock_server_start(mock_server_t *s, int scenario, pthread_t *thread) {
    memset(s, 0, sizeof(*s));
    s->scenario = scenario;
    s->close_code = -1;
    s->listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = { .sin_family = AF_INET, .sin_port = 0 };
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    socklen_t alen = sizeof(addr);
    if (bind(s->listen_fd, (struct sockaddr *)&addr, sizeof(addr)) != 0 || listen(s->listen_fd, 4) != 0 ||
        getsockname(s->listen_fd, (struct sockaddr *)&addr, &alen) != 0) {
        return -1;
    }
    s->port = ntohs(addr.sin_port);
    return pthread_create(thread, NULL, mock_server_run, s);
}

static void mock_server_stop(mock_server_t *s, pthread_t thread) {
    pthread_join(thread, NULL);
    if (s->listen_fd >= 0) {
        close(s->listen_fd);
    }
    if (s->error[0]) {
        fprintf(stderr, "mock server failed at: %s\n", s->error);
        failures++;
    }
}

static apiClient_t *mock_client(int port) {
    char base[64];
    snprintf(base, sizeof(base), "http://127.0.0.1:%d", port);
    apiClient_t *client = upstox_client_create("test-token");
    free(client->basePath);
    client->basePath = strdup(base);
    return client;
}

// Open, drop, auto-reconnect with resubscribe, user subscribe, then a clean disconnect.
static void test_market_end_to_end(void) {
    mock_server_t srv;
    pthread_t thread;
    CHECK(mock_server_start(&srv, SCENARIO_MARKET, &thread) == 0);
    apiClient_t *client = mock_client(srv.port);
    const char *keys[] = { "NSE_EQ|INE002A01018" };
    market_data_streamer_v3_t *s = market_data_streamer_v3_create(client, keys, 1, UPSTOX_MODE_FULL);
    market_data_streamer_v3_set_callbacks(s, &callbacks, on_feed);
    reset_events();

    CHECK(market_data_streamer_v3_connect(s) == 0);
    CHECK(wait_for(&ev.messages, 2));
    CHECK(wait_for(&ev.opens, 2));
    pthread_mutex_lock(&ev.lock);
    CHECK(ev.last_ltp == 2510.75 && strcmp(ev.last_key, keys[0]) == 0);
    CHECK(ev.closes == 1 && ev.last_close == 1006);
    CHECK(ev.reconnecting == 1 && strcmp(ev.last_reconnecting, "Auto reconnect attempt 1/5") == 0);
    pthread_mutex_unlock(&ev.lock);

    const char *more[] = { "NSE_INDEX|Nifty 50" };
    CHECK(market_data_streamer_v3_subscribe(s, more, 1, UPSTOX_MODE_LTPC) == 0);
    market_data_streamer_v3_disconnect(s);
    CHECK(ev.closes == 2 && ev.last_close == 1000 && ev.stopped == 0);
    CHECK(market_data_streamer_v3_subscribe(s, more, 1, UPSTOX_MODE_LTPC) == -1);
    market_data_streamer_v3_free(s);
    mock_server_stop(&srv, thread);

    CHECK(strcmp(srv.auth_request, "GET /v3/feed/market-data-feed/authorize HTTP/1.1") == 0);
    CHECK(srv.upgrade_had_auth);
    CHECK(srv.frame_count == 3);
    for (int i = 0; i < 2; i++) {
        CHECK(strstr(srv.frames[i], "\"method\":\"sub\"") && strstr(srv.frames[i], "\"mode\":\"full\"") &&
              strstr(srv.frames[i], "NSE_EQ|INE002A01018"));
    }
    CHECK(strstr(srv.frames[2], "\"mode\":\"ltpc\"") && strstr(srv.frames[2], "Nifty 50"));
    CHECK(srv.close_code == 1000);
    apiClient_free(client);
}

// clear_subscriptions drops the initial keys, so the open sends no subscribe (as in Python).
static void test_clear_subscriptions(void) {
    market_data_streamer_v3_clear_subscriptions(NULL);
    mock_server_t srv;
    pthread_t thread;
    CHECK(mock_server_start(&srv, SCENARIO_CLEARED, &thread) == 0);
    apiClient_t *client = mock_client(srv.port);
    const char *keys[] = { "NSE_EQ|INE002A01018", "NSE_INDEX|Nifty 50" };
    market_data_streamer_v3_t *s = market_data_streamer_v3_create(client, keys, 2, UPSTOX_MODE_FULL);
    market_data_streamer_v3_set_callbacks(s, &callbacks, on_feed);
    reset_events();
    market_data_streamer_v3_clear_subscriptions(s);
    CHECK(market_data_streamer_v3_connect(s) == 0);
    CHECK(wait_for(&ev.messages, 1));
    market_data_streamer_v3_disconnect(s);
    market_data_streamer_v3_free(s);
    mock_server_stop(&srv, thread);
    CHECK(srv.frame_count == 0);
    CHECK(srv.close_code == 1000);
    apiClient_free(client);
}

// Every reconnect attempt fails: attempts are reported, then auto_reconnect_stopped.
static void test_retries_exhausted(void) {
    mock_server_t srv;
    pthread_t thread;
    CHECK(mock_server_start(&srv, SCENARIO_RETRIES, &thread) == 0);
    apiClient_t *client = mock_client(srv.port);
    const char *keys[] = { "NSE_EQ|INE002A01018" };
    market_data_streamer_v3_t *s = market_data_streamer_v3_create(client, keys, 1, UPSTOX_MODE_LTPC);
    market_data_streamer_v3_set_callbacks(s, &callbacks, on_feed);
    market_data_streamer_v3_auto_reconnect(s, 1, 0, 2);
    reset_events();

    CHECK(market_data_streamer_v3_connect(s) == 0);
    CHECK(wait_for(&ev.stopped, 1));
    pthread_mutex_lock(&ev.lock);
    CHECK(ev.opens == 1 && ev.messages == 1 && ev.closes == 1 && ev.last_close == 1006);
    CHECK(ev.reconnecting == 2 && strcmp(ev.last_reconnecting, "Auto reconnect attempt 2/2") == 0);
    CHECK(strcmp(ev.last_stopped, "retryCount of 2 exhausted.") == 0);
    CHECK(strstr(ev.last_error, "authorization failed") != NULL);
    pthread_mutex_unlock(&ev.lock);
    market_data_streamer_v3_free(s);
    mock_server_stop(&srv, thread);
    apiClient_free(client);
}

// Portfolio: update_types query, text delivery, and a server close 1000 that does not reconnect.
static void test_portfolio_end_to_end(void) {
    mock_server_t srv;
    pthread_t thread;
    CHECK(mock_server_start(&srv, SCENARIO_PORTFOLIO, &thread) == 0);
    apiClient_t *client = mock_client(srv.port);
    portfolio_data_streamer_t *p = portfolio_data_streamer_create(client, 1, 1, 0, 0);
    portfolio_data_streamer_set_callbacks(p, &callbacks, on_text);
    reset_events();

    CHECK(portfolio_data_streamer_connect(p) == 0);
    CHECK(wait_for(&ev.closes, 1));
    pthread_mutex_lock(&ev.lock);
    CHECK(ev.opens == 1 && ev.messages == 1 && strstr(ev.last_text, "\"update_type\":\"order\""));
    CHECK(ev.last_close == 1000 && strcmp(ev.last_reason, "bye") == 0);
    pthread_mutex_unlock(&ev.lock);
    mock_server_stop(&srv, thread);
    CHECK(ev.reconnecting == 0);
    portfolio_data_streamer_free(p);

    CHECK(strcmp(srv.auth_request, "GET /v2/feed/portfolio-stream-feed/authorize?update_types=order%2Cposition HTTP/1.1") == 0);
    CHECK(srv.close_code == 1000);
    apiClient_free(client);
}

static void test_connect_failures(void) {
    // Port 1 on loopback refuses: authorize fails on the caller's thread, so connect returns -1
    apiClient_t *client = mock_client(1);
    portfolio_data_streamer_t *p = portfolio_data_streamer_create(client, 1, 0, 0, 0);
    portfolio_data_streamer_set_callbacks(p, &callbacks, on_text);
    reset_events();
    CHECK(portfolio_data_streamer_connect(p) == -1);
    CHECK(ev.errors == 1 && strstr(ev.last_error, "authorization failed (HTTP 0)") != NULL);
    CHECK(ev.opens == 0 && ev.closes == 0);
    portfolio_data_streamer_free(p);
    apiClient_free(client);
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);
    setenv("NO_PROXY", "127.0.0.1,localhost", 1);
    setenv("no_proxy", "127.0.0.1,localhost", 1);
    apiClient_setupGlobalEnv();

    char accept_key[32];
    ws_accept_key("dGhlIHNhbXBsZSBub25jZQ==", accept_key); // RFC 6455 example
    CHECK(strcmp(accept_key, "s3pPLMBiTxaQ9kYGzzhZRbK+xOo=") == 0);

    apiClient_t *client = upstox_client_create("test-token");
    test_create(client);
    test_build_request();
    test_update_types();
    test_reconnect_rules();
    test_decode_and_offline_calls(client);
    apiClient_free(client);

    if (upstox_ws_curl_has_wss()) {
        test_connect_failures();
        test_market_end_to_end();
        test_clear_subscriptions();
        test_retries_exhausted();
        test_portfolio_end_to_end();
    } else {
        // Without wss support connect must refuse up front
        client = upstox_client_create("test-token");
        portfolio_data_streamer_t *p = portfolio_data_streamer_create(client, 1, 0, 0, 0);
        portfolio_data_streamer_set_callbacks(p, &callbacks, on_text);
        reset_events();
        CHECK(portfolio_data_streamer_connect(p) == -1 && ev.errors == 1 && strstr(ev.last_error, "wss"));
        portfolio_data_streamer_free(p);
        apiClient_free(client);
        printf("feeder_test: libcurl lacks wss; skipped the loopback websocket tests\n");
    }

    apiClient_unsetupGlobalEnv();
    if (failures) {
        fprintf(stderr, "feeder_test: %d check(s) failed\n", failures);
        return 1;
    }
    printf("feeder_test: all checks passed\n");
    return 0;
}
