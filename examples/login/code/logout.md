## Logout Request

Invalidates the current access token.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/LoginAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    logout_response_t *resp = LoginAPI_logout(client);
    if (resp == NULL) {
        printf("Exception when calling LoginAPI_logout: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        printf("logged out: %s\n", resp->data && *resp->data ? "true" : "false");
        logout_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
