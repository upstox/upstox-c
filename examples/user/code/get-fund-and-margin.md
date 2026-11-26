## Get equity and commodity funds

Funds and margin for both segments.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_user_fund_margin_response_t *resp = UserAPI_getUserFundMargin(client, upstox_client_getUserFundMargin_SEGMENT_NULL);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getUserFundMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_user_fund_margin_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_user_fund_margin_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get equity funds

Funds and margin for the securities (SEC) segment.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_user_fund_margin_response_t *resp = UserAPI_getUserFundMargin(client, upstox_client_getUserFundMargin_SEGMENT_SEC);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getUserFundMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_user_fund_margin_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_user_fund_margin_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get commodity funds

Funds and margin for the commodity (COM) segment.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_user_fund_margin_response_t *resp = UserAPI_getUserFundMargin(client, upstox_client_getUserFundMargin_SEGMENT_COM);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getUserFundMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_user_fund_margin_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_user_fund_margin_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
