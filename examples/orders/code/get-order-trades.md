## Get trades for an order number

Trades executed against one order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *order_id = "{your_order_id}";

    get_trade_response_t *resp = OrderAPI_getTradesByOrder(client, order_id);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_getTradesByOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_trade_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_trade_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
