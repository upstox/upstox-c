## Modify Single Leg GTT Order

Changes the entry trigger and quantity of a single-leg GTT order.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double entry_price = 7.3;
    list_t *rules = list_createList();
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_ENTRY, upstox_client_gtt_rule_TRIGGERTYPE_ABOVE, &entry_price, NULL, NULL));
    // The request takes ownership of rules and the strdup-ed id
    gtt_modify_order_request_t *body = gtt_modify_order_request_create(upstox_client_gtt_modify_order_request_TYPE_SINGLE, &quantity, rules,
                                                                       strdup("GTT-C25270200137952"));

    gtt_trigger_order_response_t *resp = OrderV3API_modifyGTTOrder(client, body, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_modifyGTTOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

    gtt_modify_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Modify Multiple Leg GTT Order

Changes the entry, target and stop-loss legs of a multi-leg GTT order.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double entry_price = 7.3;
    double target_price = 7.64;
    double stoploss_price = 7.1;
    list_t *rules = list_createList();
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_ENTRY, upstox_client_gtt_rule_TRIGGERTYPE_ABOVE, &entry_price, NULL, NULL));
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_TARGET, upstox_client_gtt_rule_TRIGGERTYPE_IMMEDIATE, &target_price, NULL, NULL));
    list_addElement(rules, gtt_rule_create(upstox_client_gtt_rule_STRATEGY_STOPLOSS, upstox_client_gtt_rule_TRIGGERTYPE_IMMEDIATE, &stoploss_price, NULL, NULL));
    gtt_modify_order_request_t *body = gtt_modify_order_request_create(upstox_client_gtt_modify_order_request_TYPE_MULTIPLE, &quantity, rules,
                                                                       strdup("GTT-C25280200137522"));

    gtt_trigger_order_response_t *resp = OrderV3API_modifyGTTOrder(client, body, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_modifyGTTOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

    gtt_modify_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
