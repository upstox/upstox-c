## Get IPO order details by order id

Fetches one IPO order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // The order id comes from IPOAPI_applyForIpo or IPOAPI_getIpoOrders
    char *order_id = "{ipo_order_id}";

    ipo_order_detail_response_t *resp = IPOAPI_getIpoOrderById(client, order_id);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrderById: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = ipo_order_detail_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        ipo_order_detail_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Read the order and payment status of an IPO order

Prints the status fields and every bid of one IPO order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *order_id = "{ipo_order_id}";

    ipo_order_detail_response_t *resp = IPOAPI_getIpoOrderById(client, order_id);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrderById: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        ipo_order_data_t *order = resp->data;
        if (order == NULL) {
            printf("no data returned\n");
        } else {
            printf("symbol:          %s\n", order->symbol);
            printf("exchange:        %s\n", order->exchange);
            printf("order status:    %s\n", order->order_status);
            printf("payment status:  %s\n", order->payment_status);
            printf("units allotted:  %d\n", order->units_allotted ? *order->units_allotted : 0);
            listEntry_t *entry;
            list_ForEach(entry, order->bids) {
                ipo_order_bid_t *bid = entry->data;
                printf("   bid: %d @ %.2f = %.2f\n", bid->quantity ? *bid->quantity : 0, bid->price ? *bid->price : 0, bid->amount ? *bid->amount : 0);
            }
        }
        ipo_order_detail_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Look up the most recent IPO order

Reads the latest order id from the order list, then fetches its details.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    ipo_order_response_t *orders = IPOAPI_getIpoOrders(client, "1", "1");
    if (orders == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else if (orders->data == NULL || orders->data->count == 0) {
        printf("no IPO orders found\n");
    } else {
        ipo_order_data_t *latest = orders->data->firstEntry->data;
        ipo_order_detail_response_t *resp = IPOAPI_getIpoOrderById(client, latest->order_id);
        if (resp == NULL) {
            printf("Exception when calling IPOAPI_getIpoOrderById: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
        } else {
            if (resp->data == NULL) {
                printf("no data returned\n");
            } else {
                cJSON *json = ipo_order_detail_response_convertToJSON(resp);
                char *out = cJSON_Print(json);
                printf("%s\n", out);
                cJSON_free(out);
                cJSON_Delete(json);
            }
            ipo_order_detail_response_free(resp);
        }
    }
    if (orders != NULL) {
        ipo_order_response_free(orders);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
