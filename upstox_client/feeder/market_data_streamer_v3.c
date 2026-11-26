#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "market_data_streamer_v3.h"
#include "streamer_internal.h"
#include "../api/WebsocketAPI.h"
#include "../external/cJSON.h"

#define MODE_COUNT 4

static const char *const modes[MODE_COUNT] = {
    UPSTOX_MODE_LTPC, UPSTOX_MODE_FULL, UPSTOX_MODE_OPTION_GREEKS, UPSTOX_MODE_FULL_D30,
};

// A set of instrument keys, kept in insertion order.
typedef struct key_set_t {
    char **keys;
    size_t count;
    size_t cap;
} key_set_t;

struct market_data_streamer_v3_t {
    upstox_ws_t ws; // must stay first: the core's callbacks cast it back
    key_set_t subscriptions[MODE_COUNT];
    void (*on_message)(const upstox_feed_response_t *feed, void *user_data);
};

static int mode_index(const char *mode) {
    for (int i = 0; mode && i < MODE_COUNT; i++) {
        if (strcmp(mode, modes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int upstox_mdv3_valid_mode(const char *mode) {
    return mode_index(mode) >= 0;
}

static void key_set_add(key_set_t *set, const char *key) {
    if (key == NULL) {
        return;
    }
    for (size_t i = 0; i < set->count; i++) {
        if (strcmp(set->keys[i], key) == 0) {
            return;
        }
    }
    if (set->count == set->cap) {
        size_t cap = set->cap ? set->cap * 2 : 8;
        char **grown = realloc(set->keys, cap * sizeof(char *));
        if (grown == NULL) {
            return;
        }
        set->keys = grown;
        set->cap = cap;
    }
    char *copy = strdup(key);
    if (copy) {
        set->keys[set->count++] = copy;
    }
}

static void key_set_remove(key_set_t *set, const char *key) {
    for (size_t i = 0; key && i < set->count; i++) {
        if (strcmp(set->keys[i], key) == 0) {
            free(set->keys[i]);
            memmove(&set->keys[i], &set->keys[i + 1], (set->count - i - 1) * sizeof(char *));
            set->count--;
            return;
        }
    }
}

static void key_set_free(key_set_t *set) {
    for (size_t i = 0; i < set->count; i++) {
        free(set->keys[i]);
    }
    free(set->keys);
    memset(set, 0, sizeof(*set));
}

// Fills out with a random RFC 4122 version 4 UUID, like Python's uuid.uuid4().
static void make_guid(char out[37]) {
    unsigned char b[16];
    size_t got = 0;
    FILE *f = fopen("/dev/urandom", "rb");
    if (f) {
        got = fread(b, 1, sizeof(b), f);
        fclose(f);
    }
    if (got != sizeof(b)) {
        static unsigned int seed;
        if (seed == 0) {
            seed = (unsigned int)time(NULL) ^ (unsigned int)getpid();
        }
        for (size_t i = 0; i < sizeof(b); i++) {
            b[i] = (unsigned char)rand_r(&seed);
        }
    }
    b[6] = (unsigned char)((b[6] & 0x0f) | 0x40);
    b[8] = (unsigned char)((b[8] & 0x3f) | 0x80);
    snprintf(out, 37, "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x", b[0], b[1], b[2], b[3], b[4],
             b[5], b[6], b[7], b[8], b[9], b[10], b[11], b[12], b[13], b[14], b[15]);
}

char *upstox_mdv3_build_request(const char *method, const char *const *instrument_keys, size_t count, const char *mode) {
    if (method == NULL || (count > 0 && instrument_keys == NULL)) {
        return NULL;
    }
    char guid[37];
    make_guid(guid);
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "guid", guid);
    cJSON_AddStringToObject(root, "method", method);
    cJSON *data = cJSON_AddObjectToObject(root, "data");
    cJSON *keys = cJSON_AddArrayToObject(data, "instrumentKeys");
    for (size_t i = 0; i < count; i++) {
        cJSON_AddItemToArray(keys, cJSON_CreateString(instrument_keys[i] ? instrument_keys[i] : ""));
    }
    if (mode) {
        cJSON_AddStringToObject(data, "mode", mode);
    }
    char *json = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);
    return json;
}

// Sends a request as a binary frame, as market_data_feeder_v3.py does; the caller holds the lock.
static int send_request_locked(market_data_streamer_v3_t *streamer, const char *method, const char *const *keys, size_t count,
                               const char *mode) {
    char *json = upstox_mdv3_build_request(method, keys, count, mode);
    if (json == NULL) {
        return -1;
    }
    int rc = upstox_ws_send_binary_locked(&streamer->ws, json, strlen(json));
    free(json);
    return rc;
}

// Subscribes every tracked key on (re)open, like subscribe_to_initial_keys.
static void handle_open(upstox_ws_t *ws) {
    market_data_streamer_v3_t *streamer = (market_data_streamer_v3_t *)ws;
    for (int i = 0; i < MODE_COUNT; i++) {
        key_set_t *set = &streamer->subscriptions[i];
        if (set->count > 0) {
            send_request_locked(streamer, "sub", (const char *const *)set->keys, set->count, modes[i]);
        }
    }
}

static void handle_message(upstox_ws_t *ws, const unsigned char *data, size_t len, int binary) {
    (void)binary;
    market_data_streamer_v3_t *streamer = (market_data_streamer_v3_t *)ws;
    upstox_feed_response_t *feed = com__upstox__marketdatafeederv3udapi__rpc__proto__feed_response__unpack(NULL, len, data);
    if (feed == NULL) {
        upstox_ws_emit_error(ws, "Failed to decode market data feed message");
        return;
    }
    pthread_mutex_lock(&ws->lock);
    void (*on_message)(const upstox_feed_response_t *, void *) = streamer->on_message;
    void *user_data = ws->cb.user_data;
    pthread_mutex_unlock(&ws->lock);
    if (on_message) {
        on_message(feed, user_data);
    }
    com__upstox__marketdatafeederv3udapi__rpc__proto__feed_response__free_unpacked(feed, NULL);
}

static char *authorize(upstox_ws_t *ws) {
    return upstox_ws_take_redirect_uri(WebsocketAPI_getMarketDataFeedAuthorizeV3(ws->apiClient));
}

static const upstox_ws_ops_t market_ops = { authorize, handle_open, handle_message };

market_data_streamer_v3_t *market_data_streamer_v3_create(apiClient_t *apiClient, const char *const *instrument_keys,
                                                          size_t count, const char *mode) {
    int idx = mode_index(mode);
    if (apiClient == NULL || idx < 0 || (count > 0 && instrument_keys == NULL)) {
        return NULL;
    }
    market_data_streamer_v3_t *streamer = calloc(1, sizeof(*streamer));
    if (streamer == NULL) {
        return NULL;
    }
    upstox_ws_init(&streamer->ws, apiClient, &market_ops);
    for (size_t i = 0; i < count; i++) {
        if (instrument_keys[i]) {
            key_set_add(&streamer->subscriptions[idx], instrument_keys[i]);
        }
    }
    return streamer;
}

void market_data_streamer_v3_set_callbacks(market_data_streamer_v3_t *streamer, const upstox_streamer_callbacks_t *callbacks,
                                           void (*on_message)(const upstox_feed_response_t *feed, void *user_data)) {
    if (streamer == NULL) {
        return;
    }
    upstox_ws_set_callbacks(&streamer->ws, callbacks);
    pthread_mutex_lock(&streamer->ws.lock);
    streamer->on_message = on_message;
    pthread_mutex_unlock(&streamer->ws.lock);
}

int market_data_streamer_v3_connect(market_data_streamer_v3_t *streamer) {
    return streamer ? upstox_ws_connect(&streamer->ws) : -1;
}

// Emits the Python SDK's invalid-mode error; 1 when the mode is invalid.
static int invalid_mode(market_data_streamer_v3_t *streamer, const char *mode) {
    if (mode_index(mode) >= 0) {
        return 0;
    }
    char msg[160];
    snprintf(msg, sizeof(msg), "Invalid mode provided %s", mode ? mode : "(null)");
    upstox_ws_emit_error(&streamer->ws, msg);
    return 1;
}

int market_data_streamer_v3_subscribe(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count,
                                      const char *mode) {
    if (streamer == NULL || invalid_mode(streamer, mode)) {
        return -1;
    }
    pthread_mutex_lock(&streamer->ws.lock);
    int rc = send_request_locked(streamer, "sub", instrument_keys, count, mode);
    for (size_t i = 0; rc == 0 && i < count; i++) {
        key_set_add(&streamer->subscriptions[mode_index(mode)], instrument_keys[i]);
    }
    pthread_mutex_unlock(&streamer->ws.lock);
    return rc;
}

int market_data_streamer_v3_unsubscribe(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count) {
    if (streamer == NULL) {
        return -1;
    }
    pthread_mutex_lock(&streamer->ws.lock);
    int rc = send_request_locked(streamer, "unsub", instrument_keys, count, NULL);
    for (size_t i = 0; rc == 0 && i < count; i++) {
        for (int m = 0; m < MODE_COUNT; m++) {
            key_set_remove(&streamer->subscriptions[m], instrument_keys[i]);
        }
    }
    pthread_mutex_unlock(&streamer->ws.lock);
    return rc;
}

int market_data_streamer_v3_change_mode(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count,
                                        const char *mode) {
    if (streamer == NULL || invalid_mode(streamer, mode)) {
        return -1;
    }
    pthread_mutex_lock(&streamer->ws.lock);
    int rc = send_request_locked(streamer, "change_mode", instrument_keys, count, mode);
    for (size_t i = 0; rc == 0 && i < count; i++) {
        for (int m = 0; m < MODE_COUNT; m++) {
            key_set_remove(&streamer->subscriptions[m], instrument_keys[i]);
        }
        key_set_add(&streamer->subscriptions[mode_index(mode)], instrument_keys[i]);
    }
    pthread_mutex_unlock(&streamer->ws.lock);
    return rc;
}

void market_data_streamer_v3_auto_reconnect(market_data_streamer_v3_t *streamer, int enable, int interval_seconds, int retry_count) {
    if (streamer) {
        upstox_ws_auto_reconnect(&streamer->ws, enable, interval_seconds, retry_count);
    }
}

void market_data_streamer_v3_disconnect(market_data_streamer_v3_t *streamer) {
    if (streamer) {
        upstox_ws_disconnect(&streamer->ws);
    }
}

void market_data_streamer_v3_free(market_data_streamer_v3_t *streamer) {
    if (streamer == NULL) {
        return;
    }
    upstox_ws_destroy(&streamer->ws);
    for (int i = 0; i < MODE_COUNT; i++) {
        key_set_free(&streamer->subscriptions[i]);
    }
    free(streamer);
}
