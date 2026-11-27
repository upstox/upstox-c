## Get Option Greek fields

Delta, gamma, theta, vega and IV of one option contract.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For a single instrument

    get_market_quote_option_greek_response_v3_t *resp = MarketQuoteV3API_getMarketQuoteOptionGreek(client, "NSE_FO|43885");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getMarketQuoteOptionGreek: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_option_greek_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_option_greek_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Option Greek fields for multiple instruments keys

Greeks for a comma-separated list of option contracts.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For multiple instruments

    get_market_quote_option_greek_response_v3_t *resp = MarketQuoteV3API_getMarketQuoteOptionGreek(client, "NSE_FO|38604,NSE_FO|49210");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getMarketQuoteOptionGreek: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_market_quote_option_greek_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_market_quote_option_greek_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
