## Get margin details for equity delivery orders

Required margin for a delivery BUY of 5 units of a equity instrument.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 5;
    list_t *instruments = list_createList();
    list_addElement(instruments, instrument_create(strdup("NSE_EQ|INE528G01035"), &quantity, strdup("D"), strdup("BUY"), NULL));
    margin_request_t *body = margin_request_create(instruments);

    post_margin_response_t *resp = ChargeAPI_postMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_postMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = post_margin_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        post_margin_response_free(resp);
    }

    margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get margin details for future delivery orders

Required margin for a delivery BUY of 5 units of a futures instrument.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 5;
    list_t *instruments = list_createList();
    list_addElement(instruments, instrument_create(strdup("NSE_FO|35000"), &quantity, strdup("D"), strdup("BUY"), NULL));
    margin_request_t *body = margin_request_create(instruments);

    post_margin_response_t *resp = ChargeAPI_postMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_postMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = post_margin_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        post_margin_response_free(resp);
    }

    margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get margin details for option delivery orders

Required margin for a delivery BUY of 5 units of a options instrument.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 5;
    list_t *instruments = list_createList();
    list_addElement(instruments, instrument_create(strdup("NSE_FO|54524"), &quantity, strdup("D"), strdup("BUY"), NULL));
    margin_request_t *body = margin_request_create(instruments);

    post_margin_response_t *resp = ChargeAPI_postMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_postMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = post_margin_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        post_margin_response_free(resp);
    }

    margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get margin details for MCX delivery orders

Required margin for a delivery BUY of 5 units of a MCX instrument.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 5;
    list_t *instruments = list_createList();
    list_addElement(instruments, instrument_create(strdup("MCX_FO|435356"), &quantity, strdup("D"), strdup("BUY"), NULL));
    margin_request_t *body = margin_request_create(instruments);

    post_margin_response_t *resp = ChargeAPI_postMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_postMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = post_margin_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        post_margin_response_free(resp);
    }

    margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get margin details for currency delivery orders

Required margin for a delivery BUY of 5 units of a currency instrument.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ChargeAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 5;
    list_t *instruments = list_createList();
    list_addElement(instruments, instrument_create(strdup("NCD_FO|15758"), &quantity, strdup("D"), strdup("BUY"), NULL));
    margin_request_t *body = margin_request_create(instruments);

    post_margin_response_t *resp = ChargeAPI_postMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling ChargeAPI_postMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = post_margin_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        post_margin_response_free(resp);
    }

    margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
