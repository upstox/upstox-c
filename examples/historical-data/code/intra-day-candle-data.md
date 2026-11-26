## Get intraday candle data with a 1-minute interval

Today's V2 `1minute` candles.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "1minute";

    get_intra_day_candle_response_t *resp = HistoryAPI_getIntraDayCandleData(client, instrument_key, interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_intra_day_candle_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_intra_day_candle_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get intraday candle data with a 30-minute interval

Today's V2 `30minute` candles.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "30minute";

    get_intra_day_candle_response_t *resp = HistoryAPI_getIntraDayCandleData(client, instrument_key, interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_intra_day_candle_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_intra_day_candle_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
