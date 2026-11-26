## Get payout history

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

## Get payout modes

Lists the payout modes available to you.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    payout_modes_response_t *resp = UserAPI_getPayoutModes(client);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getPayoutModes: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = payout_modes_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        payout_modes_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Initiate payout

Requests a withdrawal of 1000 via IMPS (moves real funds).

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    double amount = 1000.0;
    // mode is one of the values returned by UserAPI_getPayoutModes (e.g. IMPS)
    initiate_payout_request_t *body = initiate_payout_request_create(strdup("IMPS"), &amount);

    payout_details_response_t *resp = UserAPI_initiatePayout(client, body);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_initiatePayout: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = payout_details_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        payout_details_response_free(resp);
    }

    initiate_payout_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Modify payout

Changes the amount of a pending withdrawal.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *transaction_id = "{transaction_id}";
    double amount = 2000.0;
    modify_payout_request_t *body = modify_payout_request_create(&amount);

    payout_details_response_t *resp = UserAPI_modifyPayout(client, transaction_id, body);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_modifyPayout: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = payout_details_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        payout_details_response_free(resp);
    }

    modify_payout_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Cancel payout

Cancels a pending withdrawal.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *transaction_id = "{transaction_id}";

    payout_details_response_t *resp = UserAPI_cancelPayout(client, transaction_id);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_cancelPayout: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = payout_details_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        payout_details_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
