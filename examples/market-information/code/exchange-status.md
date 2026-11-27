## Get market status for a particular exchange

Current open/close status of NSE.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_market_status_response_t *resp = MarketHolidaysAndTimingsAPI_getMarketStatus(client, "NSE");
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getMarketStatus: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_market_status_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_market_status_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
