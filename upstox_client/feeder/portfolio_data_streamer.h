#ifndef UPSTOX_FEEDER_PORTFOLIO_DATA_STREAMER_H
#define UPSTOX_FEEDER_PORTFOLIO_DATA_STREAMER_H

#include "../include/apiClient.h"
#include "streamer.h"

typedef struct portfolio_data_streamer_t portfolio_data_streamer_t;

// Returns a streamer for order, position, holding and GTT updates; each flag is 0 or 1 (Python defaults: 1, 0, 0, 0).
portfolio_data_streamer_t *portfolio_data_streamer_create(apiClient_t *apiClient, int order_update, int position_update,
                                                          int holding_update, int gtt_update);

// Sets the lifecycle callbacks and the message callback; message is the raw JSON text, valid only during the call.
void portfolio_data_streamer_set_callbacks(portfolio_data_streamer_t *streamer, const upstox_streamer_callbacks_t *callbacks,
                                           void (*on_message)(const char *message, void *user_data));

// Authorizes and connects on a background thread; 0 on success.
int portfolio_data_streamer_connect(portfolio_data_streamer_t *streamer);

// Reconnects after an abnormal close, retry_count times interval_seconds apart (default: on, 1 s, 5 tries).
void portfolio_data_streamer_auto_reconnect(portfolio_data_streamer_t *streamer, int enable, int interval_seconds, int retry_count);

// Closes the connection without reconnecting and waits for the background thread.
void portfolio_data_streamer_disconnect(portfolio_data_streamer_t *streamer);

// Disconnects if needed and frees the streamer.
void portfolio_data_streamer_free(portfolio_data_streamer_t *streamer);

#endif // UPSTOX_FEEDER_PORTFOLIO_DATA_STREAMER_H
