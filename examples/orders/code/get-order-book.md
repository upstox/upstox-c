## Get all orders for the day

Lists every order placed today.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_order_book_response_t *resp = OrderAPI_getOrderBook(client);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_getOrderBook: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_order_book_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_order_book_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
