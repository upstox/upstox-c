## Get historical candle data with a 1-minute interval

V2 `1minute` candles between 2023-11-12 and 2023-11-13.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "1minute";
    char *to_date = "2023-11-13";
    char *from_date = "2023-11-12";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData1(client, instrument_key, interval, to_date, from_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData1: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 30-minute interval

V2 `30minute` candles between 2023-11-12 and 2023-11-13.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "30minute";
    char *to_date = "2023-11-13";
    char *from_date = "2023-11-12";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData1(client, instrument_key, interval, to_date, from_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData1: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `day` candles between 2023-11-12 and 2023-11-13.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "day";
    char *to_date = "2023-11-13";
    char *from_date = "2023-11-12";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData1(client, instrument_key, interval, to_date, from_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData1: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `week` candles between 2023-10-13 and 2023-11-13.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "week";
    char *to_date = "2023-11-13";
    char *from_date = "2023-10-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData1(client, instrument_key, interval, to_date, from_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData1: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `month` candles between 2022-10-13 and 2023-11-13.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "month";
    char *to_date = "2023-11-13";
    char *from_date = "2022-10-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData1(client, instrument_key, interval, to_date, from_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData1: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get historical candle data with a 1-minute interval

V2 `1minute` candles up to 2023-11-13 (no from date).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "1minute";
    char *to_date = "2023-11-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData(client, instrument_key, interval, to_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 30-minute interval

V2 `30minute` candles up to 2023-11-13 (no from date).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "30minute";
    char *to_date = "2023-11-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData(client, instrument_key, interval, to_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `day` candles up to 2023-11-13 (no from date).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "day";
    char *to_date = "2023-11-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData(client, instrument_key, interval, to_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `week` candles up to 2023-11-13 (no from date).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "week";
    char *to_date = "2023-11-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData(client, instrument_key, interval, to_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

V2 `month` candles up to 2023-11-13 (no from date).

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    char *instrument_key = "NSE_EQ|INE669E01016";
    char *interval = "month";
    char *to_date = "2023-11-13";

    get_historical_candle_response_t *resp = HistoryAPI_getHistoricalCandleData(client, instrument_key, interval, to_date);
    if (resp == NULL) {
        printf("Exception when calling HistoryAPI_getHistoricalCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
