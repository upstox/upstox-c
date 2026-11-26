## Get IPO orders

Lists your IPO applications.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    ipo_order_response_t *resp = IPOAPI_getIpoOrders(client, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = ipo_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        ipo_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get IPO orders with pagination

Lists the first page of 20 IPO applications and prints the page metadata.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    ipo_order_response_t *resp = IPOAPI_getIpoOrders(client, "1", "20");
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = ipo_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        if (resp->meta_data != NULL && resp->meta_data->page != NULL) {
            pagination_t *page = resp->meta_data->page;
            printf("page: %d of %d, %d records of %d\n", page->page_number ? *page->page_number : 0, page->total_pages ? *page->total_pages : 0,
                   page->records ? *page->records : 0, page->total_records ? *page->total_records : 0);
        }
        ipo_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Iterate over IPO orders and their bids

Prints each IPO order with its bids.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    ipo_order_response_t *resp = IPOAPI_getIpoOrders(client, "1", "50");
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            ipo_order_data_t *order = entry->data;
            printf("%s %s %s %s\n", order->order_id, order->symbol, order->order_status, order->payment_status);
            listEntry_t *bidEntry;
            list_ForEach(bidEntry, order->bids) {
                ipo_order_bid_t *bid = bidEntry->data;
                printf("   bid: %d @ %.2f = %.2f\n", bid->quantity ? *bid->quantity : 0, bid->price ? *bid->price : 0, bid->amount ? *bid->amount : 0);
            }
        }
        ipo_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
