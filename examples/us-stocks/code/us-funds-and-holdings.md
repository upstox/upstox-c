## Get US funds

USD balances available to trade and withdraw.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksFundsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    us_funds_response_t *resp = USStocksFundsAPI_getUsFunds(client);
    if (resp == NULL) {
        printf("Exception when calling USStocksFundsAPI_getUsFunds: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            printf("available to trade (USD): %.2f\n", resp->data->available_to_trade ? *resp->data->available_to_trade : 0);
            printf("exchange rate: %.4f\n", resp->data->exchange_rate ? *resp->data->exchange_rate : 0);
        }
        us_funds_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US holdings

Lists your US stock holdings with P&L.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USStocksPortfolioAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    us_holdings_response_t *resp = USStocksPortfolioAPI_getUsHoldings(client);
    if (resp == NULL) {
        printf("Exception when calling USStocksPortfolioAPI_getUsHoldings: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            us_holding_data_t *holding = entry->data;
            printf("%s %g %.2f\n", holding->trading_symbol, holding->quantity ? *holding->quantity : 0, holding->pnl ? *holding->pnl : 0);
        }
        us_holdings_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
