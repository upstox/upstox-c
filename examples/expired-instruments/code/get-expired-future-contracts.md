## Get Expired Future Contracts for given instrument with expiry date

Lists the expired future contracts of Nifty 50 for one expiry date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ExpiredInstrumentAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_expired_futures_contract_response_t *resp = ExpiredInstrumentAPI_getExpiredFutureContracts(client, "NSE_INDEX|Nifty 50", "2024-11-27");
    if (resp == NULL) {
        printf("Exception when calling ExpiredInstrumentAPI_getExpiredFutureContracts: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_expired_futures_contract_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_expired_futures_contract_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
