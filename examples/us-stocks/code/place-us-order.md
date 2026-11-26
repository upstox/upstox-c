## Place a market order by quantity

Buys 1.5 shares of AAPL at market.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Fractional quantities are allowed only on fractionable stocks
    double quantity = 1.5;
    us_place_order_request_t *body = us_place_order_request_create(&quantity, NULL, NULL, upstox_client_us_place_order_request_VALIDITY_DAY, NULL, strdup("US_EQ|AAPL"),
                                                                   upstox_client_us_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_us_place_order_request_ORDERTYPE_MARKET);

    us_order_response_t *resp = USStocksOrderAPI_placeUsOrder(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_placeUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("order id: %s\n", resp->data->order_id);
        }
        us_order_response_free(resp);
    }

    us_place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a market order by USD amount

Buys 50 USD worth of AAPL at market.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Size the order by USD amount instead of quantity
    double amount = 50.0;
    us_place_order_request_t *body = us_place_order_request_create(NULL, &amount, NULL, upstox_client_us_place_order_request_VALIDITY_DAY, NULL, strdup("US_EQ|AAPL"),
                                                                   upstox_client_us_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_us_place_order_request_ORDERTYPE_MARKET);

    us_order_response_t *resp = USStocksOrderAPI_placeUsOrder(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_placeUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("order id: %s\n", resp->data->order_id);
        }
        us_order_response_free(resp);
    }

    us_place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a limit order

Buys 2 shares of AAPL with a limit price of 150.25 USD.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    double quantity = 2;
    double price = 150.25;
    us_place_order_request_t *body = us_place_order_request_create(&quantity, NULL, &price, upstox_client_us_place_order_request_VALIDITY_DAY, strdup("my-us-order"),
                                                                   strdup("US_EQ|AAPL"), upstox_client_us_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_us_place_order_request_ORDERTYPE_LIMIT);

    us_order_response_t *resp = USStocksOrderAPI_placeUsOrder(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_placeUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("order id: %s\n", resp->data->order_id);
        }
        us_order_response_free(resp);
    }

    us_place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
