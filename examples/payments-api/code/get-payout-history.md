## Get Payout History

Lists withdrawals from your trading account.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    payment_history_response_t *resp = UserAPI_getPayoutHistory(client);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getPayoutHistory: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = payment_history_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        payment_history_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
