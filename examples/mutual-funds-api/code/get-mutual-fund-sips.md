## Get all mutual fund SIPs

Lists your SIPs.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_mutual_fund_sips_response_t *resp = MutualFundAPI_getMutualFundSips(client, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundSips: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_mutual_fund_sips_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_mutual_fund_sips_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get mutual fund SIPs with pagination

Lists the first page of 10 SIPs.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int records = 10;

    get_mutual_fund_sips_response_t *resp = MutualFundAPI_getMutualFundSips(client, &page_number, &records);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundSips: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_mutual_fund_sips_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_mutual_fund_sips_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
