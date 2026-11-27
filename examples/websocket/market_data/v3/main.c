// Streams live market data from the Upstox V3 market data feed and prints the last traded price of each update.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/market_data_streamer_v3.h"

typedef Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__Feed feed_t;
typedef Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__LTPC ltpc_t;
typedef Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__FullFeed full_feed_t;

static volatile sig_atomic_t stop = 0;

static void on_signal(int sig) {
    (void)sig;
    stop = 1;
}

// Returns the LTPC block of a feed in any subscription mode, or NULL.
static const ltpc_t *feed_ltpc(const feed_t *feed) {
    switch (feed->feed_union_case) {
    case COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED__FEED_UNION_LTPC:
        return feed->ltpc;
    case COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED__FEED_UNION_FIRST_LEVEL_WITH_GREEKS:
        return feed->firstlevelwithgreeks->ltpc;
    case COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FEED__FEED_UNION_FULL_FEED: {
        const full_feed_t *full = feed->fullfeed;
        if (full->full_feed_union_case == COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FULL_FEED__FULL_FEED_UNION_MARKET_FF) {
            return full->marketff->ltpc;
        }
        if (full->full_feed_union_case == COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__FULL_FEED__FULL_FEED_UNION_INDEX_FF) {
            return full->indexff->ltpc;
        }
        return NULL;
    }
    default:
        return NULL;
    }
}

static void on_message(const upstox_feed_response_t *response, void *user_data) {
    (void)user_data;
    if (response->type == COM__UPSTOX__MARKETDATAFEEDERV3UDAPI__RPC__PROTO__TYPE__market_info) {
        printf("market info update (%zu segments)\n", response->marketinfo ? response->marketinfo->n_segmentstatus : 0);
        return;
    }
    for (size_t i = 0; i < response->n_feeds; i++) {
        const ltpc_t *ltpc = feed_ltpc(response->feeds[i]->value);
        if (ltpc != NULL) {
            printf("%s ltp=%.2f ltt=%lld ltq=%lld cp=%.2f\n", response->feeds[i]->key, ltpc->ltp, (long long)ltpc->ltt, (long long)ltpc->ltq,
                   ltpc->cp);
        }
    }
}

static void on_open(void *user_data) {
    (void)user_data;
    printf("Connection established\n");
}

static void on_error(const char *error, void *user_data) {
    (void)user_data;
    fprintf(stderr, "error: %s\n", error);
}

static void on_close(int status_code, const char *reason, void *user_data) {
    (void)user_data;
    fprintf(stderr, "closed: %d %s\n", status_code, reason ? reason : "");
}

static void on_reconnecting(const char *message, void *user_data) {
    (void)user_data;
    fprintf(stderr, "reconnecting: %s\n", message);
}

static void on_auto_reconnect_stopped(const char *message, void *user_data) {
    (void)user_data;
    fprintf(stderr, "auto reconnect stopped: %s\n", message);
}

int main(void) {
    const char *token = getenv("UPSTOX_ACCESS_TOKEN");
    if (token == NULL || *token == '\0') {
        fprintf(stderr, "Set UPSTOX_ACCESS_TOKEN to your Upstox access token\n");
        return 1;
    }
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(token);

    const char *keys[] = {"NSE_INDEX|Nifty Bank", "NSE_INDEX|Nifty 50"};
    market_data_streamer_v3_t *streamer = market_data_streamer_v3_create(client, keys, 2, UPSTOX_MODE_FULL);
    upstox_streamer_callbacks_t callbacks = {
        .on_open = on_open,
        .on_close = on_close,
        .on_error = on_error,
        .on_reconnecting = on_reconnecting,
        .on_auto_reconnect_stopped = on_auto_reconnect_stopped,
    };
    market_data_streamer_v3_set_callbacks(streamer, &callbacks, on_message);
    market_data_streamer_v3_auto_reconnect(streamer, 1, 5, 10);

    if (market_data_streamer_v3_connect(streamer) != 0) {
        fprintf(stderr, "connect failed\n");
    } else {
        // Stream until Ctrl+C
        signal(SIGINT, on_signal);
        while (!stop) {
            sleep(1);
        }
    }

    market_data_streamer_v3_free(streamer);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
