## Get US market status

Current open/close status of the US market.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USMarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_market_status_response_t *resp = USMarketHolidaysAndTimingsAPI_getUsMarketStatus(client);
    if (resp == NULL) {
        printf("Exception when calling USMarketHolidaysAndTimingsAPI_getUsMarketStatus: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = get_market_status_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        get_market_status_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US market holidays for the year

Lists all US market holidays of the current year.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USMarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_us_holiday_response_t *resp = USMarketHolidaysAndTimingsAPI_getUsHolidays(client);
    if (resp == NULL) {
        printf("Exception when calling USMarketHolidaysAndTimingsAPI_getUsHolidays: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        listEntry_t *entry;
        list_ForEach(entry, resp->data) {
            us_holiday_data_t *holiday = entry->data;
            printf("%s %s\n", holiday->date, us_holiday_data_holiday_type_ToString(holiday->holiday_type));
        }
        get_us_holiday_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US market holiday on a date

Holiday details for one date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USMarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Empty list when the date is not a holiday

    get_us_holiday_response_t *resp = USMarketHolidaysAndTimingsAPI_getUsHoliday(client, "2026-11-26");
    if (resp == NULL) {
        printf("Exception when calling USMarketHolidaysAndTimingsAPI_getUsHoliday: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_us_holiday_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_us_holiday_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get US market timings on a date

US trading sessions on one date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/USMarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Regular and overnight sessions; empty list when the market is closed

    get_us_exchange_timing_response_t *resp = USMarketHolidaysAndTimingsAPI_getUsExchangeTimings(client, "2026-11-27");
    if (resp == NULL) {
        printf("Exception when calling USMarketHolidaysAndTimingsAPI_getUsExchangeTimings: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_us_exchange_timing_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_us_exchange_timing_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
