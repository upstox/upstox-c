## Get report meta data for equity segment

Row count and page size of the equity P&L report.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/TradeProfitAndLossAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Financial year is the last 2 digits of both years, e.g. 2324 for 2023-24
    char *financial_year = "2324";
    // Dates are dd-mm-yyyy and must fall inside the financial year

    get_trade_wise_profit_and_loss_meta_data_response_t *resp = TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData(client, "EQ", financial_year, "02-04-2023", "20-03-2024");
    if (resp == NULL) {
        printf("Exception when calling TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_trade_wise_profit_and_loss_meta_data_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_trade_wise_profit_and_loss_meta_data_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
