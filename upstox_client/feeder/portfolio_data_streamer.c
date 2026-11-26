#include <stdlib.h>
#include <string.h>
#include "portfolio_data_streamer.h"
#include "streamer_internal.h"
#include "../api/WebsocketAPI.h"

struct portfolio_data_streamer_t {
    upstox_ws_t ws; // must stay first: the core's callbacks cast it back
    char *update_types;
    void (*on_message)(const char *message, void *user_data);
};

char *upstox_portfolio_update_types(int order_update, int position_update, int holding_update, int gtt_update) {
    // Same order and %2C separator as portfolio_data_feeder.py; the generated client does not re-escape it
    const char *types[4];
    size_t n = 0, len = 0;
    if (order_update) {
        types[n++] = "order";
    }
    if (holding_update) {
        types[n++] = "holding";
    }
    if (position_update) {
        types[n++] = "position";
    }
    if (gtt_update) {
        types[n++] = "gtt_order";
    }
    if (n == 0) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        len += strlen(types[i]) + 3;
    }
    char *out = malloc(len + 1);
    if (out == NULL) {
        return NULL;
    }
    out[0] = '\0';
    for (size_t i = 0; i < n; i++) {
        if (i > 0) {
            strcat(out, "%2C");
        }
        strcat(out, types[i]);
    }
    return out;
}

static void handle_message(upstox_ws_t *ws, const unsigned char *data, size_t len, int binary) {
    (void)len;
    (void)binary;
    portfolio_data_streamer_t *streamer = (portfolio_data_streamer_t *)ws;
    pthread_mutex_lock(&ws->lock);
    void (*on_message)(const char *, void *) = streamer->on_message;
    void *user_data = ws->cb.user_data;
    pthread_mutex_unlock(&ws->lock);
    if (on_message) {
        on_message((const char *)data, user_data); // the core NUL-terminates every message
    }
}

static char *authorize(upstox_ws_t *ws) {
    portfolio_data_streamer_t *streamer = (portfolio_data_streamer_t *)ws;
    return upstox_ws_take_redirect_uri(WebsocketAPI_getPortfolioStreamFeedAuthorize(ws->apiClient, streamer->update_types));
}

static const upstox_ws_ops_t portfolio_ops = { authorize, NULL, handle_message };

portfolio_data_streamer_t *portfolio_data_streamer_create(apiClient_t *apiClient, int order_update, int position_update,
                                                          int holding_update, int gtt_update) {
    if (apiClient == NULL) {
        return NULL;
    }
    portfolio_data_streamer_t *streamer = calloc(1, sizeof(*streamer));
    if (streamer == NULL) {
        return NULL;
    }
    upstox_ws_init(&streamer->ws, apiClient, &portfolio_ops);
    streamer->update_types = upstox_portfolio_update_types(order_update, position_update, holding_update, gtt_update);
    return streamer;
}

void portfolio_data_streamer_set_callbacks(portfolio_data_streamer_t *streamer, const upstox_streamer_callbacks_t *callbacks,
                                           void (*on_message)(const char *message, void *user_data)) {
    if (streamer == NULL) {
        return;
    }
    upstox_ws_set_callbacks(&streamer->ws, callbacks);
    pthread_mutex_lock(&streamer->ws.lock);
    streamer->on_message = on_message;
    pthread_mutex_unlock(&streamer->ws.lock);
}

int portfolio_data_streamer_connect(portfolio_data_streamer_t *streamer) {
    return streamer ? upstox_ws_connect(&streamer->ws) : -1;
}

void portfolio_data_streamer_auto_reconnect(portfolio_data_streamer_t *streamer, int enable, int interval_seconds, int retry_count) {
    if (streamer) {
        upstox_ws_auto_reconnect(&streamer->ws, enable, interval_seconds, retry_count);
    }
}

void portfolio_data_streamer_disconnect(portfolio_data_streamer_t *streamer) {
    if (streamer) {
        upstox_ws_disconnect(&streamer->ws);
    }
}

void portfolio_data_streamer_free(portfolio_data_streamer_t *streamer) {
    if (streamer == NULL) {
        return;
    }
    upstox_ws_destroy(&streamer->ws);
    free(streamer->update_types);
    free(streamer);
}
