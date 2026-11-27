## Get Historical Candle Data for Expired Instruments

Fetches 1-minute candles for an expired instrument key (`<segment>|<token>|<expiry>`).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/ExpiredInstrumentAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_historical_candle_response_t *resp = ExpiredInstrumentAPI_getExpiredHistoricalCandleData(client, "NSE_FO|54452|24-04-2025", "1minute", "2025-04-24", "2025-04-24");
    if (resp == NULL) {
        printf("Exception when calling ExpiredInstrumentAPI_getExpiredHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_historical_candle_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_historical_candle_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
