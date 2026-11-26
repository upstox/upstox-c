## Cancel all the open orders

Cancels every open order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Arguments: tag, segment, algo name (NULL to omit)

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_cancelMultiOrder(client, NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_cancelMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = cancel_or_exit_multi_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        cancel_or_exit_multi_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Cancel all the open orders for a given segment

Cancels open orders in the NSE_FO segment only.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_cancelMultiOrder(client, NULL, "NSE_FO", NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_cancelMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = cancel_or_exit_multi_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        cancel_or_exit_multi_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Cancel all the open orders for a given tag

Cancels open orders placed with tag `xyz`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_cancelMultiOrder(client, "xyz", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_cancelMultiOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = cancel_or_exit_multi_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        cancel_or_exit_multi_order_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
