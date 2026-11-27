## Get full market quote

Full quote (OHLC, depth, OI, circuit limits) for one instrument.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For a single instrument

    get_full_market_quote_response_v3_t *resp = MarketQuoteV3API_getFullMarketQuoteV3(client, "NSE_EQ|INE848E01016");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getFullMarketQuoteV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_full_market_quote_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_full_market_quote_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get full market quote for multiple instrument keys

Pass a comma-separated list of instrument keys.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // For multiple instruments (up to 500 in one call)

    get_full_market_quote_response_v3_t *resp = MarketQuoteV3API_getFullMarketQuoteV3(client, "NSE_EQ|INE848E01016,NSE_EQ|INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getFullMarketQuoteV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_full_market_quote_response_v3_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_full_market_quote_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Read fields from the full market quote response

Walks the quote map and prints the main fields, OHLC and market depth.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketQuoteV3API.h"

// Reads an optional number, 0 when absent.
static double num(const double *value) {
    return value ? *value : 0;
}

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_full_market_quote_response_v3_t *resp = MarketQuoteV3API_getFullMarketQuoteV3(client, "NSE_EQ|INE848E01016");
    if (resp == NULL) {
        printf("Exception when calling MarketQuoteV3API_getFullMarketQuoteV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        // data is a map keyed by "<exchange>:<trading_symbol>": a list of keyValuePair_t
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            keyValuePair_t *pair = entry->data;
            market_quote_symbol_v3_t *quote = pair->value;
            printf("%s\n", pair->key);
            printf("  symbol                : %s\n", quote->symbol);
            printf("  instrument_token      : %s\n", quote->instrument_token);
            printf("  last_price            : %.2f\n", num(quote->last_price));
            printf("  volume                : %ld\n", quote->volume ? *quote->volume : 0);
            printf("  average_price         : %.2f\n", num(quote->average_price));
            printf("  net_change            : %.2f\n", num(quote->net_change));
            printf("  prev_close_price      : %.2f\n", num(quote->prev_close_price));
            printf("  lower_circuit_limit   : %.2f\n", num(quote->lower_circuit_limit));
            printf("  upper_circuit_limit   : %.2f\n", num(quote->upper_circuit_limit));
            printf("  year_high / year_low  : %.2f / %.2f\n", num(quote->year_high), num(quote->year_low));
            printf("  oi / previous_oi      : %.0f / %.0f\n", num(quote->oi), num(quote->previous_oi));
            printf("  cas_eligible          : %s\n", quote->cas_eligible && *quote->cas_eligible ? "true" : "false");
            // Nested OHLC snapshot
            if (quote->ohlc != NULL) {
                printf("  ohlc                  : %.2f %.2f %.2f %.2f\n", num(quote->ohlc->open), num(quote->ohlc->high), num(quote->ohlc->low),
                       num(quote->ohlc->close));
            }
            // Nested market depth (top 5 bids and asks)
            if (quote->depth != NULL) {
                listEntry_t *level;
                list_ForEach(level, quote->depth->buy) {
                    depth_t *bid = level->data;
                    printf("  bid: %.2f %d %d\n", num(bid->price), bid->quantity ? *bid->quantity : 0, bid->orders ? *bid->orders : 0);
                }
                list_ForEach(level, quote->depth->sell) {
                    depth_t *ask = level->data;
                    printf("  ask: %.2f %d %d\n", num(ask->price), ask->quantity ? *ask->quantity : 0, ask->orders ? *ask->orders : 0);
                }
            }
        }
        get_full_market_quote_response_v3_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
