#ifndef UPSTOX_FEEDER_STREAMER_H
#define UPSTOX_FEEDER_STREAMER_H

// Lifecycle callbacks shared by the market data and portfolio streamers; any may be NULL.
// Callbacks run on the streamer's background thread.
typedef struct upstox_streamer_callbacks_t {
    void (*on_open)(void *user_data);
    void (*on_close)(int status_code, const char *reason, void *user_data);
    void (*on_error)(const char *error, void *user_data);
    void (*on_reconnecting)(const char *message, void *user_data);
    void (*on_auto_reconnect_stopped)(const char *message, void *user_data);
    void *user_data;
} upstox_streamer_callbacks_t;

#endif // UPSTOX_FEEDER_STREAMER_H
