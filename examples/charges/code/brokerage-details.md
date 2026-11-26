## Get brokerage details for equity delivery orders

Brokerage and charges for an equity delivery BUY of 10 shares.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 10;

    get_brokerage_response_t *resp = ChargeAPI_getBrokerage(client, "NSE_EQ|INE669E01016", &quantity, "D", "BUY", 13.4);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_getBrokerage: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_brokerage_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_brokerage_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get brokerage details for equity intraday orders

Brokerage and charges for an equity intraday BUY of 10 shares.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 10;

    get_brokerage_response_t *resp = ChargeAPI_getBrokerage(client, "NSE_EQ|INE669E01016", &quantity, "I", "BUY", 13.4);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_getBrokerage: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_brokerage_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_brokerage_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get brokerage details for equity futures and options delivery orders

Brokerage and charges for an F&O delivery BUY of 10 units.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 10;

    get_brokerage_response_t *resp = ChargeAPI_getBrokerage(client, "NSE_FO|35271", &quantity, "D", "BUY", 1333.4);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_getBrokerage: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_brokerage_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_brokerage_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get brokerage details for equity futures and options intraday orders

Brokerage and charges for an F&O intraday BUY of 10 units.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 10;

    get_brokerage_response_t *resp = ChargeAPI_getBrokerage(client, "NSE_FO|35271", &quantity, "I", "BUY", 1333.4);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_getBrokerage: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_brokerage_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_brokerage_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
