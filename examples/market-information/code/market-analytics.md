## Get OI Data

Open interest of Nifty 50 options for one expiry on one date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getOiData(client, "NSE_INDEX|Nifty 50", "2026-05-29", "2026-05-12");
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getOiData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get Change in OI Data

Change in open interest over 5-minute intervals.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int interval = 5;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getChangeOiData(client, "NSE_INDEX|Nifty 50", "2026-05-29", "2026-05-12", &interval);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getChangeOiData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get PCR Data

Put-call ratio in 30-minute buckets.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int bucket_interval = 30;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getPcrData(client, "NSE_INDEX|Nifty 50", "2026-05-29", "2026-05-12", &bucket_interval);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getPcrData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get Max Pain Data

Max pain strike in 30-minute buckets.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int bucket_interval = 30;

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getMaxPainData(client, "NSE_INDEX|Nifty 50", "2026-05-29", "2026-05-12", &bucket_interval);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getMaxPainData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get FII Data

Daily FII activity in the NSE cash segment.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getFiiData(client, "NSE_EQ|CASH", "1D", NULL);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getFiiData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get FII Data with Date Filter

Monthly FII activity in index futures since 2026-01-01.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getFiiData(client, "NSE_FO|INDEX_FUTURES", "1M", "2026-01-01");
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getFiiData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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

## Get DII Data

Daily DII activity in the NSE cash segment.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    analytics_response_t *resp = MarketHolidaysAndTimingsAPI_getDiiData(client, "NSE_EQ|CASH", "1D", NULL);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getDiiData: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
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
