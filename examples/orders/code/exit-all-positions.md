## Exit all the open positions

Squares off every open position.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Arguments: tag, segment, algo name (NULL to omit)

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_exitPositions(client, NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_exitPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Exit all the open positions for a given segment

Squares off positions in the NSE_FO segment only.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_exitPositions(client, NULL, "NSE_FO", NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_exitPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Exit all the open positions for a given tag

Squares off positions opened with tag `xyz`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    cancel_or_exit_multi_order_response_t *resp = OrderAPI_exitPositions(client, "xyz", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_exitPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
