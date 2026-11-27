## Place an order with slicing enabled

A large F&O market order that the V3 endpoint slices into freeze-limit chunks.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 4000;
    double price = 0;
    int slice = 1;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 0;
    // Numbers are copied; the request takes ownership of the strdup-ed strings
    place_order_v3_request_t *body = place_order_v3_request_create(&quantity, upstox_client_place_order_v3_request_PRODUCT_D, upstox_client_place_order_v3_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                                   strdup("NSE_FO|43919"), upstox_client_place_order_v3_request_ORDERTYPE_MARKET, upstox_client_place_order_v3_request_TRANSACTIONTYPE_BUY,
                                                                   &disclosed_quantity, &trigger_price, &is_amo, NULL);

    place_order_v3_response_t *resp = OrderV3API_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_v3_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_v3_response_free(resp);
    }

    place_order_v3_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place an order with slicing disabled

An F&O market order placed as a single order.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 75;
    double price = 0;
    int slice = 0;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 0;
    // Numbers are copied; the request takes ownership of the strdup-ed strings
    place_order_v3_request_t *body = place_order_v3_request_create(&quantity, upstox_client_place_order_v3_request_PRODUCT_D, upstox_client_place_order_v3_request_VALIDITY_DAY, &price, strdup("string"), &slice,
                                                                   strdup("NSE_FO|43919"), upstox_client_place_order_v3_request_ORDERTYPE_MARKET, upstox_client_place_order_v3_request_TRANSACTIONTYPE_BUY,
                                                                   &disclosed_quantity, &trigger_price, &is_amo, NULL);

    place_order_v3_response_t *resp = OrderV3API_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_v3_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_v3_response_free(resp);
    }

    place_order_v3_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
