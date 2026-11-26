## Place Single Leg GTT Order

Places a GTT order with only an entry trigger.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double entry_price = 7;
    list_t *rules = list_createList();
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_ENTRY, upstox_client_gtt_rule_TRIGGERTYPE_ABOVE, &entry_price, NULL, NULL));
    // The request takes ownership of rules and the strdup-ed instrument token
    gtt_place_order_request_t *body = gtt_place_order_request_create(
        upstox_client_gtt_place_order_request_TYPE_SINGLE, &quantity, upstox_client_gtt_place_order_request_PRODUCT_D, rules,
        strdup("NSE_EQ|INE669E01016"), upstox_client_gtt_place_order_request_TRANSACTIONTYPE_BUY);

    gtt_trigger_order_response_t *resp = OrderV3API_placeGTTOrder(client, body, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_placeGTTOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("GTT order response:\n");
            cJSON *json = gtt_trigger_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        gtt_trigger_order_response_free(resp);
    }

    gtt_place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place Multiple Leg GTT Order

Places a GTT order with entry, target and stop-loss legs.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double entry_price = 7;
    double target_price = 9;
    double stoploss_price = 5;
    list_t *rules = list_createList();
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_ENTRY, upstox_client_gtt_rule_TRIGGERTYPE_ABOVE, &entry_price, NULL, NULL));
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_TARGET, upstox_client_gtt_rule_TRIGGERTYPE_IMMEDIATE, &target_price, NULL, NULL));
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_STOPLOSS, upstox_client_gtt_rule_TRIGGERTYPE_IMMEDIATE, &stoploss_price, NULL, NULL));
    gtt_place_order_request_t *body = gtt_place_order_request_create(
        upstox_client_gtt_place_order_request_TYPE_MULTIPLE, &quantity, upstox_client_gtt_place_order_request_PRODUCT_D, rules,
        strdup("NSE_EQ|INE669E01016"), upstox_client_gtt_place_order_request_TRANSACTIONTYPE_BUY);

    gtt_trigger_order_response_t *resp = OrderV3API_placeGTTOrder(client, body, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_placeGTTOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("GTT order response:\n");
            cJSON *json = gtt_trigger_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        gtt_trigger_order_response_free(resp);
    }

    gtt_place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
