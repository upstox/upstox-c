## Get put/call option chain

Put and call legs per strike for one Nifty 50 expiry.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OptionsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_option_chain_response_t *resp = OptionsAPI_getPutCallOptionChain(client, "NSE_INDEX|Nifty 50", "2024-10-31");
    if (resp == NULL) {
        printf("Exception when calling OptionsAPI_getPutCallOptionChain: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_option_chain_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_option_chain_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
