## Get Expiries for given instrument

Lists every past expiry date available for Nifty 50.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ExpiredInstrumentAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_expiries_response_t *resp = ExpiredInstrumentAPI_getExpiries(client, "NSE_INDEX|Nifty 50");
    if (resp == NULL) {
        printf("Exception when calling ExpiredInstrumentAPI_getExpiries: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_expiries_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_expiries_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
