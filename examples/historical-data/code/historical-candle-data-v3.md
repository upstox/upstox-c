## Get data with a 1-minute interval

Historical candles from 2025-01-01 to 2025-01-02 using unit `minutes` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "minutes", &interval, "2025-01-02", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 3-minute interval

Historical candles from 2025-01-01 to 2025-01-02 using unit `minutes` and interval `3`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 3;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "minutes", &interval, "2025-01-02", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 15-minute interval

Historical candles from 2025-01-01 to 2025-01-04 using unit `minutes` and interval `15`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 15;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "minutes", &interval, "2025-01-04", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 1-hour interval

Historical candles from 2025-01-01 to 2025-02-01 using unit `hours` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "hours", &interval, "2025-02-01", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 4-hour interval

Historical candles from 2025-01-01 to 2025-02-01 using unit `hours` and interval `4`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 4;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "hours", &interval, "2025-02-01", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a daily interval

Historical candles from 2025-01-01 to 2025-03-01 using unit `days` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "days", &interval, "2025-03-01", "2025-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a weekly interval

Historical candles from 2024-01-01 to 2025-01-01 using unit `weeks` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "weeks", &interval, "2025-01-01", "2024-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a monthly interval

Historical candles from 2010-01-01 to 2025-01-01 using unit `months` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_historical_candle_response_t *resp = HistoryV3API_getHistoricalCandleDataRangeV3(client, "NSE_EQ|INE848E01016", "months", &interval, "2025-01-01", "2010-01-01");
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getHistoricalCandleDataRangeV3: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
