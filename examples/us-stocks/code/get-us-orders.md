## Get US order book

Lists today's US orders in every state.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Today's orders in every state

    us_order_book_response_t *resp = USStocksOrderAPI_getUsOrderBook(client, NULL);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_getUsOrderBook: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            us_order_book_data_t *order = entry->data;
            printf("%s %s %s %g\n", order->order_id, order->trading_symbol, us_order_book_data_status_ToString(order->status),
                   order->filled_quantity ? *order->filled_quantity : 0);
        }
        us_order_book_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US order book filtered by tag

Lists today's US orders placed with a given tag.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Exact, case-sensitive match on the tag set when placing the order

    us_order_book_response_t *resp = USStocksOrderAPI_getUsOrderBook(client, "my-us-order");
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_getUsOrderBook: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            us_order_book_data_t *order = entry->data;
            printf("%s %s %s\n", order->order_id, order->tag, us_order_book_data_status_ToString(order->status));
        }
        us_order_book_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US order details by order id

Fetches the status of one US order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    us_order_details_response_t *resp = USStocksOrderAPI_getUsOrderDetails(client, "{us_order_id}");
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_getUsOrderDetails: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("%s %s\n", us_order_book_data_status_ToString(resp->data->status), resp->data->status_message);
        }
        us_order_details_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
