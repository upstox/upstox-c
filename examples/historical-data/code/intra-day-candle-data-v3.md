## Get data with a 1-minute interval

Today's candles using unit `minutes` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "minutes", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 3-minute interval

Today's candles using unit `minutes` and interval `3`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 3;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "minutes", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 5-minute interval

Today's candles using unit `minutes` and interval `5`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 5;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "minutes", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 15-minute interval

Today's candles using unit `minutes` and interval `15`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 15;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "minutes", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 30-minute interval

Today's candles using unit `minutes` and interval `30`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 30;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "minutes", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 1-hour interval

Today's candles using unit `hours` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "hours", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get data with a 2-hour interval

Today's candles using unit `hours` and interval `2`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 2;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "hours", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get current day data

Today's candles using unit `days` and interval `1`.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/HistoryV3API.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 1;

    get_intra_day_candle_response_t *resp = HistoryV3API_getIntraDayCandleData(client, "NSE_EQ|INE848E01016", "days", &interval);
    if (resp == NULL) {
        printf("Exception when calling HistoryV3API_getIntraDayCandleData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
