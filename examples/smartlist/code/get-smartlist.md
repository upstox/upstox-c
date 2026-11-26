## Get smartlist options

Top traded index options, first page of 50.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // asset_type: INDEX | STOCK | COMMODITY
    // category: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS, PRICE_GAINERS, PRICE_LOSERS, IV_GAINERS, IV_LOSERS, UNDER_5000, UNDER_10000
    int page_number = 1;
    int page_size = 50;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getSmartlistOptions(client, "INDEX", "TOP_TRADED", &page_number, &page_size);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getSmartlistOptions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = analytics_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        analytics_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get smartlist futures

Most active stock futures, first page of 50.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // asset_type: INDEX | STOCK | COMMODITY
    // category: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS, PRICE_GAINERS, PRICE_LOSERS, PREMIUM, DISCOUNT
    int page_number = 1;
    int page_size = 50;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getSmartlistFutures(client, "STOCK", "MOST_ACTIVE", &page_number, &page_size);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getSmartlistFutures: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = analytics_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        analytics_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get smartlist MTF

MTF (Margin Trade Funding) stocks enriched with live LTP, first page of 50.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int page_size = 50;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getSmartlistMtf(client, &page_number, &page_size);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getSmartlistMtf: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = analytics_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        analytics_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
