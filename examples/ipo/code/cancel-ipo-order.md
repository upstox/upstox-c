## Cancel an IPO order

Withdraws an IPO application by its order id.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // The order id comes from IPOAPI_applyForIpo or IPOAPI_getIpoOrders
    char *order_id = "{ipo_order_id}";

    ipo_cancel_response_t *resp = IPOAPI_cancelIpoOrder(client, order_id);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_cancelIpoOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("cancelled order id: %s\n", resp->data->order_id);
            printf("status: %s\n", resp->data->status);
        }
        ipo_cancel_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Apply, then cancel the same IPO order

Applies for an IPO and immediately withdraws that application.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 10;
    double price = 150.0;
    list_t *bids = list_createList();
    list_addElement(bids, ipo_bid_request_create(&quantity, &price));
    ipo_apply_request_t *body = ipo_apply_request_create(strdup("{ipo_slug_id}"), strdup("{your_upi_id}"),
                                                         upstox_client_ipo_apply_request_CATEGORY_IND, bids);

    ipo_apply_response_t *apply = IPOAPI_applyForIpo(client, body);
    if (apply == NULL) {
        printf("Exception when calling IPOAPI_applyForIpo: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else if (apply->data == NULL) {
        printf("no data returned\n");
    } else {
        char *order_id = apply->data->order_id;
        printf("applied, order id: %s\n", order_id);

        ipo_cancel_response_t *cancel = IPOAPI_cancelIpoOrder(client, order_id);
        if (cancel == NULL) {
            printf("Exception when calling IPOAPI_cancelIpoOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
        } else {
            if (cancel->data != NULL) {
                printf("cancelled: %s\n", cancel->data->status);
            }
            ipo_cancel_response_free(cancel);
        }
    }
    if (apply != NULL) {
        ipo_apply_response_free(apply);
    }
    ipo_apply_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

> Note: cancellation is only accepted while the IPO bidding window is still
> open. Once the issue closes, the order can no longer be withdrawn — check
> `bidding_end_date` from `IPOAPI_getIpoDetails` before cancelling.
