## Get access token using auth code

Exchanges the authorization code from the login redirect for an access token.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/LoginAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(NULL);

    char *code = "{your_auth_code}";
    char *client_id = "{your_client_id}";
    char *client_secret = "{your_client_secret}";
    char *redirect_uri = "{your_redirect_url}";
    char *grant_type = "authorization_code";

    token_response_t *resp = LoginAPI_token(client, code, client_id, client_secret, redirect_uri, grant_type, NULL);
    if (resp == NULL) {
        printf("Exception when calling LoginAPI_token: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = token_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        token_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
