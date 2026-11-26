## Get ltp (last traded price) market quotes

Last traded price of one instrument.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For a single instrument

    get_market_quote_last_traded_price_response_v3_t *resp = MarketQuoteV3API_getLtp(client, "NSE_EQ|INE848E01016");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getLtp: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_last_traded_price_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_last_traded_price_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get ltp (last traded price) market quotes for multiple instruments keys

Last traded prices for a comma-separated list of instruments.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For multiple instruments

    get_market_quote_last_traded_price_response_v3_t *resp = MarketQuoteV3API_getLtp(client, "NSE_EQ|INE848E01016,NSE_EQ|INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getLtp: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_last_traded_price_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_last_traded_price_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
