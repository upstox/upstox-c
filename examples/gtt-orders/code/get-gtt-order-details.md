## Get GTT Order Details

Fetches the details of one GTT order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_gtt_order_response_t *resp = OrderV3API_getGttOrderDetails(client, "GTT-C25030300128840");
    if (resp == NULL) {
        printf("Exception when calling OrderV3API_getGttOrderDetails: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        printf("GTT order details:\n");
        cJSON *json = get_gtt_order_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_gtt_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
