## Access token request

Starts the access-token request flow for an individual (indie) user.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/LoginAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(NULL);

    indie_user_token_request_t *body = indie_user_token_request_create(NULL, strdup("****"), NULL);

    indie_user_init_token_response_t *resp = LoginAPI_initTokenRequestForIndieUser(client, "*****", body);
    if (resp == NULL) {
        printf("Exception when calling LoginAPI_initTokenRequestForIndieUser: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = indie_user_init_token_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        indie_user_init_token_response_free(resp);
    }

    indie_user_token_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
