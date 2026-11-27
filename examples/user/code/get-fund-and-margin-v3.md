## Get equity and commodity funds (v3)

Available funds and margin used through the V3 endpoint.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_user_fund_margin_v3_response_t *resp = UserAPI_getUserFundMarginV3(client);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getUserFundMarginV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_user_fund_margin_v3_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_user_fund_margin_v3_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
