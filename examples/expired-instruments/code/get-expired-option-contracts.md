## Get Expired Option Contracts for given instrument with expiry date

Lists the expired option contracts of Nifty 50 for one expiry date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ExpiredInstrumentAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_option_contract_response_t *resp = ExpiredInstrumentAPI_getExpiredOptionContracts(client, "NSE_INDEX|Nifty 50", "2025-04-30");
    if (resp == NULL) {
        printf("Exception when calling ExpiredInstrumentAPI_getExpiredOptionContracts: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_option_contract_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_option_contract_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
