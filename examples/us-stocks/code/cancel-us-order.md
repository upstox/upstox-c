## Cancel an open order

Cancels an open US stock order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    us_order_response_t *resp = USStocksOrderAPI_cancelUsOrder(client, "{us_order_id}");
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_cancelUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("cancelled order id: %s\n", resp->data->order_id);
        }
        us_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
