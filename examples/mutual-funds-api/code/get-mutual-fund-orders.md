## Get all mutual fund orders

Lists your mutual fund orders.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_mutual_fund_orders_response_t *resp = MutualFundAPI_getMutualFundOrders(client, NULL, NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_mutual_fund_orders_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_mutual_fund_orders_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get mutual fund orders with filters

Lists only completed BUY orders.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_mutual_fund_orders_response_t *resp = MutualFundAPI_getMutualFundOrders(client, "complete", "BUY", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_mutual_fund_orders_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_mutual_fund_orders_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get mutual fund orders with pagination

Lists the first page of 10 orders.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MutualFundAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int records = 10;

    get_mutual_fund_orders_response_t *resp = MutualFundAPI_getMutualFundOrders(client, NULL, NULL, &page_number, &records);
    if (resp == NULL) {
        printf("Exception when calling MutualFundAPI_getMutualFundOrders: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_mutual_fund_orders_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_mutual_fund_orders_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
