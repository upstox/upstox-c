## Apply for an IPO

Submits a single-bid IPO application paid through a UPI mandate.

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
    // id is the IPO slug id returned by IPOAPI_getIpoListing; category is IND or HNI; 1 to 3 bids
    ipo_apply_request_t *body = ipo_apply_request_create(strdup("{ipo_slug_id}"), strdup("{your_upi_id}"),
                                                         upstox_client_ipo_apply_request_CATEGORY_IND, bids);

    ipo_apply_response_t *resp = IPOAPI_applyForIpo(client, body);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_applyForIpo: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("IPO order id: %s\n", resp->data->order_id);
        }
        ipo_apply_response_free(resp);
    }

    ipo_apply_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Apply for an IPO with multiple bids

Submits an HNI application with three bids at different prices.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Build valid bids from the cut-off price and lot size in IPOAPI_getIpoDetails
    int quantities[] = {10, 20, 30};
    double prices[] = {150.0, 155.0, 160.0};
    list_t *bids = list_createList();
    for (int i = 0; i < 3; i++) {
        list_addElement(bids, ipo_bid_request_create(&quantities[i], &prices[i]));
    }
    ipo_apply_request_t *body = ipo_apply_request_create(strdup("{ipo_slug_id}"), strdup("{your_upi_id}"),
                                                         upstox_client_ipo_apply_request_CATEGORY_HNI, bids);

    ipo_apply_response_t *resp = IPOAPI_applyForIpo(client, body);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_applyForIpo: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = ipo_apply_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        ipo_apply_response_free(resp);
    }

    ipo_apply_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

> Note: after a successful application, approve the UPI mandate request in your
> UPI app to block the funds. Until the mandate is approved, the order remains
> pending.
