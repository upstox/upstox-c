## Estimate charges for a market order

Charge estimate for buying 1 AAPL share at market.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Nothing is placed
    double quantity = 1;
    us_order_estimate_request_t *body = us_order_estimate_request_create(&quantity, NULL, strdup("US_EQ|AAPL"), upstox_client_us_order_estimate_request_TRANSACTIONTYPE_BUY,
                                                                         upstox_client_us_order_estimate_request_ORDERTYPE_MARKET);

    us_order_estimate_response_t *resp = USStocksOrderAPI_estimateUsOrder(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_estimateUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("total charges: %.4f\n", resp->data->total_charges ? *resp->data->total_charges : 0);
            printf("estimated total: %.4f\n", resp->data->estimated_total ? *resp->data->estimated_total : 0);
        }
        us_order_estimate_response_free(resp);
    }

    us_order_estimate_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Estimate charges for a limit order

Charge estimate for selling 0.5 AAPL shares at 150 USD.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksOrderAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    double quantity = 0.5;
    double price = 150.0;
    us_order_estimate_request_t *body = us_order_estimate_request_create(&quantity, &price, strdup("US_EQ|AAPL"), upstox_client_us_order_estimate_request_TRANSACTIONTYPE_SELL,
                                                                         upstox_client_us_order_estimate_request_ORDERTYPE_LIMIT);

    us_order_estimate_response_t *resp = USStocksOrderAPI_estimateUsOrder(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksOrderAPI_estimateUsOrder: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = us_order_estimate_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        us_order_estimate_response_free(resp);
    }

    us_order_estimate_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Calculate margin for multiple orders

Total margin required for a basket of US orders.

```c
#include <stdio.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksChargesAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Up to 20 orders; nothing is placed
    double aapl_quantity = 1;
    double msft_quantity = 2;
    double msft_price = 100.0;
    list_t *instruments = list_createList();
    list_addElement(instruments, us_order_estimate_request_create(&aapl_quantity, NULL, strdup("US_EQ|AAPL"), upstox_client_us_order_estimate_request_TRANSACTIONTYPE_BUY,
                                                                  upstox_client_us_order_estimate_request_ORDERTYPE_MARKET));
    list_addElement(instruments, us_order_estimate_request_create(&msft_quantity, &msft_price, strdup("US_EQ|MSFT"), upstox_client_us_order_estimate_request_TRANSACTIONTYPE_BUY,
                                                                  upstox_client_us_order_estimate_request_ORDERTYPE_LIMIT));
    us_margin_request_t *body = us_margin_request_create(instruments);

    us_margin_response_t *resp = USStocksChargesAPI_calculateUsMargin(client, body);
    if (resp == NULL) {
        printf("Exception when calling USStocksChargesAPI_calculateUsMargin: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("required margin: %.2f\n", resp->data->required_margin ? *resp->data->required_margin : 0);
            printf("sufficient: %s shortfall: %.2f\n", resp->data->sufficient && *resp->data->sufficient ? "true" : "false",
                   resp->data->shortfall ? *resp->data->shortfall : 0);
        }
        us_margin_response_free(resp);
    }

    us_margin_request_free(body);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
