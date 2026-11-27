## Get mutual fund order by id

Fetches one mutual fund order.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *order_id = "{your_mf_order_id}";

    get_mutual_fund_order_details_response_t *resp = MutualFundAPI_getMutualFundOrder(client, order_id);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_mutual_fund_order_details_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_mutual_fund_order_details_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
