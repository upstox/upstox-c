## Place a delivery market order

Delivery BUY at market price.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 0.0;
    int disclosed_quantity = 0;
    double trigger_price = 0.0;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_D, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_MARKET, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a delivery limit order

Delivery BUY with a limit price of 20.0.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 20.0;
    int disclosed_quantity = 0;
    double trigger_price = 20.1;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_D, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_LIMIT, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a delivery stop-loss order

Delivery stop-loss limit BUY triggered at 19.5.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 20;
    int disclosed_quantity = 0;
    double trigger_price = 19.5;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_D, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_SL, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a delivery stop-loss order market

Delivery stop-loss market BUY triggered at 21.5.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 0.0;
    int disclosed_quantity = 0;
    double trigger_price = 21.5;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_D, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_SL_M, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place an intraday market order

Intraday BUY at market price.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 0.0;
    int disclosed_quantity = 0;
    double trigger_price = 0.0;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_I, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_MARKET, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place an intraday limit order

Intraday BUY with a limit price of 20.0.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 20.0;
    int disclosed_quantity = 0;
    double trigger_price = 20.1;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_I, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_LIMIT, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place an intraday stop-loss order

Intraday stop-loss limit BUY triggered at 19.5.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 20;
    int disclosed_quantity = 0;
    double trigger_price = 19.5;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_I, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_SL, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place an intraday stop-loss market order

Intraday stop-loss market BUY triggered at 21.5.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 0.0;
    int disclosed_quantity = 0;
    double trigger_price = 21.5;
    int is_amo = 0;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_I, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_SL_M, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Place a delivery market amo (after market order)

Delivery market BUY queued as an after-market order.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/OrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int quantity = 1;
    double price = 0.0;
    int disclosed_quantity = 0;
    double trigger_price = 0.0;
    int is_amo = 1;
    place_order_request_t *body = place_order_request_create(&quantity, upstox_client_place_order_request_PRODUCT_D, upstox_client_place_order_request_VALIDITY_DAY, &price, strdup("string"),
                                                             strdup("NSE_EQ|INE528G01035"), upstox_client_place_order_request_ORDERTYPE_MARKET, upstox_client_place_order_request_TRANSACTIONTYPE_BUY,
                                                             &disclosed_quantity, &trigger_price, &is_amo);

    place_order_response_t *resp = OrderAPI_placeOrder(client, body, NULL);
    if (resp == NULL) {
        printf("Exception when calling OrderAPI_placeOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = place_order_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        place_order_response_free(resp);
    }

    place_order_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
