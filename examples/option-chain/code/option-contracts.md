## Get option contracts of an instrument key

All option contracts of Nifty 50 across expiries.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OptionsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_option_contract_response_t *resp = OptionsAPI_getOptionContracts(client, "NSE_INDEX|Nifty 50", NULL);
    if (resp == NULL) {
        printf("Exception when calling OptionsAPI_getOptionContracts: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get option contracts of an instrument key with expiry date

Nifty 50 option contracts for a single expiry.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OptionsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_option_contract_response_t *resp = OptionsAPI_getOptionContracts(client, "NSE_INDEX|Nifty 50", "2024-10-31");
    if (resp == NULL) {
        printf("Exception when calling OptionsAPI_getOptionContracts: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
