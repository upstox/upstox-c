## Place a multi order

Places a single order through the multi-order endpoint.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 25;
    double price = 0;
    int slice = 0;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 1;
    list_t *orders = list_createList();
    list_addElement(orders, multi_order_request_create(&quantity, upstox_client_multi_order_request_PRODUCT_D, upstox_client_multi_order_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                     strdup("NSE_FO|44166"), upstox_client_multi_order_request_ORDERTYPE_MARKET, upstox_client_multi_order_request_TRANSACTIONTYPE_BUY,
                                                     &disclosed_quantity, &trigger_price, &is_amo, strdup("1"), NULL));

    multi_order_response_t *resp = OrderAPI_placeMultiOrder(client, orders, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = multi_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        multi_order_response_free(resp);
    }

    listEntry_t *entry;
    list_ForEach(entry, orders) {
        multi_order_request_free(entry->data);
    }
    list_freeList(orders);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place Multiple BUY and SELL Orders

Places a BUY and a SELL leg in one request; each leg needs a unique correlation id.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 25;
    double price = 0;
    int slice = 0;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 1;
    list_t *orders = list_createList();
    list_addElement(orders, multi_order_request_create(&quantity, upstox_client_multi_order_request_PRODUCT_D, upstox_client_multi_order_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                     strdup("NSE_FO|44166"), upstox_client_multi_order_request_ORDERTYPE_MARKET, upstox_client_multi_order_request_TRANSACTIONTYPE_BUY,
                                                     &disclosed_quantity, &trigger_price, &is_amo, strdup("1"), NULL));
    list_addElement(orders, multi_order_request_create(&quantity, upstox_client_multi_order_request_PRODUCT_D, upstox_client_multi_order_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                     strdup("NSE_FO|44122"), upstox_client_multi_order_request_ORDERTYPE_MARKET, upstox_client_multi_order_request_TRANSACTIONTYPE_SELL,
                                                     &disclosed_quantity, &trigger_price, &is_amo, strdup("2"), NULL));

    multi_order_response_t *resp = OrderAPI_placeMultiOrder(client, orders, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = multi_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        multi_order_response_free(resp);
    }

    listEntry_t *entry;
    list_ForEach(entry, orders) {
        multi_order_request_free(entry->data);
    }
    list_freeList(orders);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place Multiple Orders with Auto Slicing enabled

Lets the exchange freeze-quantity limit split the order automatically.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 25;
    double price = 0;
    int slice = 1;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 1;
    list_t *orders = list_createList();
    list_addElement(orders, multi_order_request_create(&quantity, upstox_client_multi_order_request_PRODUCT_D, upstox_client_multi_order_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                     strdup("NSE_FO|44166"), upstox_client_multi_order_request_ORDERTYPE_MARKET, upstox_client_multi_order_request_TRANSACTIONTYPE_BUY,
                                                     &disclosed_quantity, &trigger_price, &is_amo, strdup("1"), NULL));

    multi_order_response_t *resp = OrderAPI_placeMultiOrder(client, orders, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = multi_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        multi_order_response_free(resp);
    }

    listEntry_t *entry;
    list_ForEach(entry, orders) {
        multi_order_request_free(entry->data);
    }
    list_freeList(orders);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
