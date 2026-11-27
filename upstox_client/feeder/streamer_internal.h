#ifndef UPSTOX_FEEDER_STREAMER_INTERNAL_H
#define UPSTOX_FEEDER_STREAMER_INTERNAL_H

// Private to the feeder: the shared websocket/reconnect core and the builders the unit tests check.

#include <pthread.h>
#include <stddef.h>
#include <curl/curl.h>
#include "../include/apiClient.h"
#include "../models/websocket_auth_redirect_response.h"
#include "streamer.h"

#define UPSTOX_WS_CLOSE_NORMAL 1000
#define UPSTOX_WS_CLOSE_NO_STATUS 1005
#define UPSTOX_WS_CLOSE_ABNORMAL 1006

typedef struct upstox_ws_t upstox_ws_t;

// Feed-specific hooks of the shared core.
typedef struct upstox_ws_ops_t {
    // Returns the authorized wss URL (malloc'd) or NULL; runs without the lock held.
    char *(*authorize)(upstox_ws_t *ws);
    // Runs on the receive thread with ws->lock held, right after the socket opens.
    void (*on_open)(upstox_ws_t *ws);
    // Delivers one complete text or binary message; runs without the lock held.
    void (*on_message)(upstox_ws_t *ws, const unsigned char *data, size_t len, int binary);
} upstox_ws_ops_t;

// Connection, callbacks and reconnect state; both streamers embed it as their first member.
struct upstox_ws_t {
    apiClient_t *apiClient;
    const upstox_ws_ops_t *ops;
    upstox_streamer_callbacks_t cb;
    pthread_mutex_t lock;       // guards curl and every field below
    pthread_cond_t wake;        // interrupts the reconnect wait on disconnect
    CURL *curl;                 // the open connection, NULL otherwise
    struct curl_slist *headers;
    char *pending_url;          // authorized by connect for the thread's first attempt
    pthread_t thread;
    int thread_started;         // thread exists and is not yet joined
    int running;                // thread has not finished
    int stop;                   // user disconnect requested
    int enable_auto_reconnect;
    int interval;
    int retry_count;
    int reconnect_attempts;
};

void upstox_ws_init(upstox_ws_t *ws, apiClient_t *apiClient, const upstox_ws_ops_t *ops);

// Disconnects and releases the core's resources (not the struct itself).
void upstox_ws_destroy(upstox_ws_t *ws);

void upstox_ws_set_callbacks(upstox_ws_t *ws, const upstox_streamer_callbacks_t *callbacks);

// Checks wss support, authorizes on the caller's thread and starts the receive thread; 0 on success.
int upstox_ws_connect(upstox_ws_t *ws);

void upstox_ws_disconnect(upstox_ws_t *ws);

void upstox_ws_auto_reconnect(upstox_ws_t *ws, int enable, int interval_seconds, int retry_count);

// Sends one binary frame; the caller holds ws->lock. 0 on success, -1 when not open or on failure.
int upstox_ws_send_binary_locked(upstox_ws_t *ws, const void *data, size_t len);

// Invokes on_error with the current callbacks; must be called without ws->lock held.
void upstox_ws_emit_error(upstox_ws_t *ws, const char *error);

// Returns a strdup of the response's authorized_redirect_uri (NULL if absent) and frees the response.
char *upstox_ws_take_redirect_uri(websocket_auth_redirect_response_t *response);

// Whether a close starts auto-reconnect, as in streamer.py's handle_close.
int upstox_ws_should_reconnect(int enable_auto_reconnect, int user_disconnect, int status_code);

// Formats "Auto reconnect attempt n/N".
void upstox_ws_reconnect_message(char *buf, size_t size, int attempt, int retry_count);

// Returns 1 when libcurl was built with the wss protocol.
int upstox_ws_curl_has_wss(void);

// Market data feed builders: mode check and the binary JSON request (malloc'd, NULL on bad input).
int upstox_mdv3_valid_mode(const char *mode);
char *upstox_mdv3_build_request(const char *method, const char *const *instrument_keys, size_t count, const char *mode);

// Portfolio update_types query value in Python's order (malloc'd), or NULL when no flag is set.
char *upstox_portfolio_update_types(int order_update, int position_update, int holding_update, int gtt_update);

#endif // UPSTOX_FEEDER_STREAMER_INTERNAL_H
