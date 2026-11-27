## Get ohlc (open, high, low, close) market quotes

V2 daily OHLC of one instrument.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *interval = "1d";

    get_market_quote_ohlc_response_t *resp = MarketQuoteAPI_getMarketQuoteOHLC(client, interval, "NSE_EQ|INE669E01016", NULL);
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteAPI_getMarketQuoteOHLC: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_ohlc_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_ohlc_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get ohlc (open, high, low, close) market quotes for multiple instrument keys

V2 daily OHLC for a comma-separated list of instruments.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *interval = "1d";

    get_market_quote_ohlc_response_t *resp = MarketQuoteAPI_getMarketQuoteOHLC(client, interval, "NSE_EQ|INE669E01016,NSE_EQ|INE848E01016", NULL);
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteAPI_getMarketQuoteOHLC: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_ohlc_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_ohlc_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
