## Get user holdings

Lists your long-term holdings.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PortfolioAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_holdings_response_t *resp = PortfolioAPI_getHoldings(client);
    if (resp == NULL) {
        printf("Exception when calling PortfolioAPI_getHoldings: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_holdings_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_holdings_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
