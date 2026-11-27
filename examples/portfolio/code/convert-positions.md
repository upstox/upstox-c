## Convert a position from intraday to delivery

Converts 1 unit of an intraday position to delivery.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PortfolioAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    convert_position_request_t *body = convert_position_request_create(strdup("NSE_EQ|INE528G01035"), upstox_client_convert_position_request_NEWPRODUCT_D, upstox_client_convert_position_request_OLDPRODUCT_I,
                                                                       upstox_client_convert_position_request_TRANSACTIONTYPE_BUY, &quantity);

    convert_position_response_t *resp = PortfolioAPI_convertPositions(client, body);
    if (resp == NULL) {
        printf("Exception when calling PortfolioAPI_convertPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = convert_position_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        convert_position_response_free(resp);
    }

    convert_position_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Convert a position from delivery to intraday

Converts 1 unit of a delivery position to intraday.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/PortfolioAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    convert_position_request_t *body = convert_position_request_create(strdup("NSE_EQ|INE528G01035"), upstox_client_convert_position_request_NEWPRODUCT_I, upstox_client_convert_position_request_OLDPRODUCT_D,
                                                                       upstox_client_convert_position_request_TRANSACTIONTYPE_BUY, &quantity);

    convert_position_response_t *resp = PortfolioAPI_convertPositions(client, body);
    if (resp == NULL) {
        printf("Exception when calling PortfolioAPI_convertPositions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = convert_position_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        convert_position_response_free(resp);
    }

    convert_position_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
