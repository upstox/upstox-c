#ifndef UPSTOX_FEEDER_MARKET_DATA_STREAMER_V3_H
#define UPSTOX_FEEDER_MARKET_DATA_STREAMER_V3_H

#include <stddef.h>
#include "../include/apiClient.h"
#include "streamer.h"
#include "marketdatav3/MarketDataFeedV3.pb-c.h"

// Subscription modes, as in the Python SDK's MarketDataStreamerV3.Mode.
#define UPSTOX_MODE_LTPC "ltpc"
#define UPSTOX_MODE_FULL "full"
#define UPSTOX_MODE_OPTION_GREEKS "option_greeks"
#define UPSTOX_MODE_FULL_D30 "full_d30"

// Decoded market data feed message (protobuf-c type from MarketDataFeedV3.proto).
typedef Com__Upstox__Marketdatafeederv3udapi__Rpc__Proto__FeedResponse upstox_feed_response_t;

typedef struct market_data_streamer_v3_t market_data_streamer_v3_t;

// Returns a streamer for the V3 market data feed, or NULL for an invalid mode; the keys are copied.
market_data_streamer_v3_t *market_data_streamer_v3_create(apiClient_t *apiClient, const char *const *instrument_keys,
                                                          size_t count, const char *mode);

// Sets the lifecycle callbacks and the message callback; the feed is valid only during the call.
void market_data_streamer_v3_set_callbacks(market_data_streamer_v3_t *streamer, const upstox_streamer_callbacks_t *callbacks,
                                           void (*on_message)(const upstox_feed_response_t *feed, void *user_data));

// Authorizes and connects on a background thread, subscribing the initial keys once open; 0 on success.
int market_data_streamer_v3_connect(market_data_streamer_v3_t *streamer);

// Subscription changes on an open connection; 0 on success, -1 when not open or the mode is invalid.
int market_data_streamer_v3_subscribe(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count,
                                      const char *mode);
int market_data_streamer_v3_unsubscribe(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count);
int market_data_streamer_v3_change_mode(market_data_streamer_v3_t *streamer, const char *const *instrument_keys, size_t count,
                                        const char *mode);

// Forgets the tracked subscriptions so a reconnect does not resubscribe them; sends nothing to the server.
void market_data_streamer_v3_clear_subscriptions(market_data_streamer_v3_t *streamer);

// Reconnects after an abnormal close, retry_count times interval_seconds apart (default: on, 1 s, 5 tries).
void market_data_streamer_v3_auto_reconnect(market_data_streamer_v3_t *streamer, int enable, int interval_seconds, int retry_count);

// Closes the connection without reconnecting and waits for the background thread.
void market_data_streamer_v3_disconnect(market_data_streamer_v3_t *streamer);

// Disconnects if needed and frees the streamer.
void market_data_streamer_v3_free(market_data_streamer_v3_t *streamer);

#endif // UPSTOX_FEEDER_MARKET_DATA_STREAMER_V3_H
