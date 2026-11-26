## Get user positions

Lists your open short-term positions.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PortfolioAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_position_response_t *resp = PortfolioAPI_getPositions(client);
    if (resp == NULL) {
        printf("Exception when calling PortfolioAPI_getPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_position_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_position_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
