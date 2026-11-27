# WebSocket Feeds

The feeder library (`upstox_client/feeder/`, CMake target `upstox_feeder`) connects to the Upstox WebSocket feeds for live market data and portfolio updates:

1. **Market data streamer V3** (`market_data_streamer_v3.h`): real-time market updates for the instruments you subscribe to, decoded from protobuf.
2. **Portfolio data streamer** (`portfolio_data_streamer.h`): real-time order, position, holding and GTT order updates as JSON.

Both streamers authenticate with the access token of the `apiClient_t` you pass in, reconnect automatically after an abnormal disconnect, and replay your market data subscriptions after every reconnect.

The feeder needs [protobuf-c](https://github.com/protobuf-c/protobuf-c) and a libcurl built with WebSocket support (7.86 or later), e.g. on macOS:

```sh
brew install curl protobuf-c
cmake -S . -B build -DCMAKE_PREFIX_PATH=$(brew --prefix curl) -DUPSTOX_BUILD_EXAMPLES=ON
cmake --build build
```

Runnable samples (read the token from `UPSTOX_ACCESS_TOKEN`):

- [market_data/v3](market_data/v3) streams market data for Nifty 50 and Nifty Bank.
- [order_updates](order_updates) streams order updates.

## Market data streamer V3

```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/market_data_streamer_v3.h"

static volatile sig_atomic_t stop = 0;

static void on_signal(int sig) {
    (void)sig;
    stop = 1;
}

static void on_message(const upstox_feed_response_t *feed, void *user_data) {
    (void)user_data;
    for (size_t i = 0; i < feed->n_feeds; i++) {
        printf("update for %s\n", feed->feeds[i]->key);
    }
}

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    const char *keys[] = {"NSE_INDEX|Nifty 50", "NSE_INDEX|Nifty Bank"};
    market_data_streamer_v3_t *streamer = market_data_streamer_v3_create(client, keys, 2, UPSTOX_MODE_FULL);
    market_data_streamer_v3_set_callbacks(streamer, NULL, on_message);
    if (market_data_streamer_v3_connect(streamer) == 0) {
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
```

You authenticate with an access token, create the streamer with instrument keys and a mode, and connect. Each update arrives as a `upstox_feed_response_t` (the protobuf-c `FeedResponse` type from `feeder/marketdatav3/MarketDataFeedV3.pb-c.h`), valid only during the callback. [market_data/v3/main.c](market_data/v3/main.c) shows how to read the last traded price from each feed mode.

### Modes

- `UPSTOX_MODE_LTPC` (`ltpc`): the latest trade only: last traded price, time and quantity, and the previous close.
- `UPSTOX_MODE_FULL` (`full`): latest trade prices, D5 depth, 1-minute, 30-minute and daily candles, plus additional details.
- `UPSTOX_MODE_OPTION_GREEKS` (`option_greeks`): option greeks only.
- `UPSTOX_MODE_FULL_D30` (`full_d30`): full mode data plus 30 market level quotes.

### Functions

1. `market_data_streamer_v3_create(client, keys, count, mode)`: creates the streamer; the keys are copied and subscribed in `mode` on connect. Pass `NULL, 0` to subscribe later. Returns `NULL` for an invalid mode.
2. `market_data_streamer_v3_set_callbacks(streamer, callbacks, on_message)`: sets the lifecycle callbacks (may be `NULL`) and the message callback.
3. `market_data_streamer_v3_connect(streamer)`: authorizes and connects on a background thread; returns 0 on success.
4. `market_data_streamer_v3_subscribe(streamer, keys, count, mode)`: subscribes the keys in the given mode; -1 when not connected.
5. `market_data_streamer_v3_unsubscribe(streamer, keys, count)`: stops updates for the keys.
6. `market_data_streamer_v3_change_mode(streamer, keys, count, mode)`: switches already subscribed keys to another mode.
7. `market_data_streamer_v3_clear_subscriptions(streamer)`: forgets tracked subscriptions so they are not replayed on reconnect.
8. `market_data_streamer_v3_disconnect(streamer)`: closes the connection without reconnecting and waits for the background thread.
9. `market_data_streamer_v3_auto_reconnect(streamer, enable, interval_seconds, retry_count)`: configures auto-reconnect. Defaults: enabled, 1 second, 5 retries.
10. `market_data_streamer_v3_free(streamer)`: disconnects if needed and frees the streamer.

### Callbacks

Set in an `upstox_streamer_callbacks_t` (from `streamer.h`); any may be `NULL`, and `user_data` is passed to each.

- `on_open(user_data)`: the connection is established (also after each reconnect).
- `on_close(status_code, reason, user_data)`: the connection closed.
- `on_error(error, user_data)`: a connection, decode or reconnect error occurred.
- `on_reconnecting(message, user_data)`: a reconnect attempt is starting.
- `on_auto_reconnect_stopped(message, user_data)`: auto-reconnect stopped (retries exhausted, disabled by the client, or the token was rejected).
- `on_message(feed, user_data)` (set separately): a market update arrived.

Callbacks run on the streamer's background thread, so keep them short and hand heavy work to another thread.

### Subscribe, change mode and unsubscribe

```c
#include <stdio.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/market_data_streamer_v3.h"

static const char *keys[] = {"NSE_EQ|INE020B01018", "NSE_EQ|INE467B01029"};

static void on_open(void *user_data) {
    market_data_streamer_v3_t *streamer = user_data;
    printf("Connected. Subscribing to instrument keys.\n");
    if (market_data_streamer_v3_subscribe(streamer, keys, 2, UPSTOX_MODE_FULL) != 0) {
        printf("subscribe failed\n");
    }
}

static void on_message(const upstox_feed_response_t *feed, void *user_data) {
    (void)user_data;
    printf("%zu feeds\n", feed->n_feeds);
}

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    market_data_streamer_v3_t *streamer = market_data_streamer_v3_create(client, NULL, 0, UPSTOX_MODE_FULL);
    upstox_streamer_callbacks_t callbacks = {.on_open = on_open, .user_data = streamer};
    market_data_streamer_v3_set_callbacks(streamer, &callbacks, on_message);
    if (market_data_streamer_v3_connect(streamer) == 0) {
        sleep(5);
        printf("Changing subscription mode to ltpc...\n");
        market_data_streamer_v3_change_mode(streamer, keys, 2, UPSTOX_MODE_LTPC);

        sleep(5);
        printf("Unsubscribing from instrument keys.\n");
        market_data_streamer_v3_unsubscribe(streamer, keys, 2);
    }

    market_data_streamer_v3_free(streamer);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

### Auto-reconnect

```c
#include <stdio.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/market_data_streamer_v3.h"

static void on_reconnecting(const char *message, void *user_data) {
    (void)user_data;
    printf("reconnecting: %s\n", message);
}

static void on_auto_reconnect_stopped(const char *message, void *user_data) {
    (void)user_data;
    printf("%s\n", message);
}

static void on_message(const upstox_feed_response_t *feed, void *user_data) {
    (void)feed;
    (void)user_data;
}

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    const char *keys[] = {"NSE_INDEX|Nifty 50"};
    market_data_streamer_v3_t *streamer = market_data_streamer_v3_create(client, keys, 1, UPSTOX_MODE_LTPC);
    upstox_streamer_callbacks_t callbacks = {.on_reconnecting = on_reconnecting, .on_auto_reconnect_stopped = on_auto_reconnect_stopped};
    market_data_streamer_v3_set_callbacks(streamer, &callbacks, on_message);

    // Retry every 10 seconds, at most 3 times; use (streamer, 0, 0, 0) to disable
    market_data_streamer_v3_auto_reconnect(streamer, 1, 10, 3);

    if (market_data_streamer_v3_connect(streamer) == 0) {
        sleep(60);
    }

    market_data_streamer_v3_free(streamer);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Portfolio data streamer

```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "upstox_client/upstox.h"
#include "upstox_client/feeder/portfolio_data_streamer.h"

static volatile sig_atomic_t stop = 0;

static void on_signal(int sig) {
    (void)sig;
    stop = 1;
}

static void on_open(void *user_data) {
    (void)user_data;
    printf("connection opened\n");
}

static void on_message(const char *message, void *user_data) {
    (void)user_data;
    printf("%s\n", message);
}

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Order, position, holding and GTT order updates
    portfolio_data_streamer_t *streamer = portfolio_data_streamer_create(client, 1, 1, 1, 1);
    upstox_streamer_callbacks_t callbacks = {.on_open = on_open};
    portfolio_data_streamer_set_callbacks(streamer, &callbacks, on_message);
    if (portfolio_data_streamer_connect(streamer) == 0) {
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
```

`portfolio_data_streamer_create(client, order_update, position_update, holding_update, gtt_update)` selects the update types; each flag is 0 or 1. Messages are delivered as raw JSON text, valid only during the callback. `portfolio_data_streamer_connect`, `_disconnect`, `_auto_reconnect`, `_free` and the lifecycle callbacks behave as for the market data streamer.
