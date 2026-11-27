// Streams live order updates from the Upstox portfolio stream feed.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/portfolio_data_streamer.h"

static volatile sig_atomic_t stop = 0;

static void on_signal(int sig) {
    (void)sig;
    stop = 1;
}

static void on_message(const char *message, void *user_data) {
    (void)user_data;
    printf("%s\n", message);
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

int main(void) {
    const char *token = getenv("UPSTOX_ACCESS_TOKEN");
    if (token == NULL || *token == '\0') {
        fprintf(stderr, "Set UPSTOX_ACCESS_TOKEN to your Upstox access token\n");
        return 1;
    }
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(token);

    // Order updates only; set position, holding or GTT to 1 to receive those too
    portfolio_data_streamer_t *streamer = portfolio_data_streamer_create(client, 1, 0, 0, 0);
    upstox_streamer_callbacks_t callbacks = {
        .on_open = on_open,
        .on_close = on_close,
        .on_error = on_error,
    };
    portfolio_data_streamer_set_callbacks(streamer, &callbacks, on_message);

    if (portfolio_data_streamer_connect(streamer) != 0) {
        fprintf(stderr, "connect failed\n");
    } else {
        // Stream until Ctrl+C
        signal(SIGINT, on_signal);
        while (!stop) {
            sleep(1);
        }
    }

    portfolio_data_streamer_free(streamer);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
