## Get trade history for equity segment

Past equity trades between 2023-04-01 and 2025-03-31, first page of 1000.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PostTradeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int page_size = 1000;

    trade_history_response_t *resp = PostTradeAPI_getTradesByDateRange(client, "2023-04-01", "2025-03-31", &page_number, &page_size, "EQ");
    if (resp == NULL) {
        printf("Exception when calling PostTradeAPI_getTradesByDateRange: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = trade_history_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        trade_history_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get trade history for futures and options segment

Past F&O trades between 2023-04-01 and 2025-03-31, first page of 1000.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PostTradeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int page_size = 1000;

    trade_history_response_t *resp = PostTradeAPI_getTradesByDateRange(client, "2023-04-01", "2025-03-31", &page_number, &page_size, "FO");
    if (resp == NULL) {
        printf("Exception when calling PostTradeAPI_getTradesByDateRange: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = trade_history_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        trade_history_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
