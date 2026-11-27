## Cancel GTT Order

Cancels a GTT order by its GTT order id.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    gtt_cancel_order_request_t *body = gtt_cancel_order_request_create(strdup("GTT-C250303008840"));

    gtt_trigger_order_response_t *resp = OrderV3API_cancelGTTOrder(client, body, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_cancelGTTOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("GTT order canceled:\n");
            cJSON *json = gtt_trigger_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        gtt_trigger_order_response_free(resp);
    }

    gtt_cancel_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
