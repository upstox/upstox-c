## Get user IPs

Static IPs registered for order placement.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    user_ip_response_t *resp = UserAPI_getUserIps(client);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getUserIps: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = user_ip_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        user_ip_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Update user IP

Sets the primary static IP.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    update_user_ip_request_t *body = update_user_ip_request_create(strdup("1.2.3.4"), NULL);

    user_ip_response_t *resp = UserAPI_updateUserIp(client, body);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_updateUserIp: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = user_ip_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        user_ip_response_free(resp);
    }

    update_user_ip_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
