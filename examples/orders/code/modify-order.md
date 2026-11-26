## Modify a delivery order

Changes an open order to a MARKET order for 2 units through the V2 endpoint.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 2;
    double price = 0;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    modify_order_request_t *body = modify_order_request_create(&quantity, upstox_client_modify_order_request_VALIDITY_DAY, &price, strdup("231222010275930"),
                                                               upstox_client_modify_order_request_ORDERTYPE_MARKET, &disclosed_quantity,
                                                               &trigger_price, NULL);

    modify_order_response_t *resp = OrderAPI_modifyOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_modifyOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = modify_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        modify_order_response_free(resp);
    }

    modify_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
