## Get market holidays for current year

Lists all exchange holidays of the current year.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_holiday_response_t *resp = MarketHolidaysAndTimingsAPI_getHolidays(client);
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getHolidays: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_holiday_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_holiday_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get market holiday status of a date

Holiday details for one date.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_holiday_response_t *resp = MarketHolidaysAndTimingsAPI_getHoliday(client, "2024-01-22");
    if (resp == NULL) {
        printf("Exception when calling MarketHolidaysAndTimingsAPI_getHoliday: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_holiday_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_holiday_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
