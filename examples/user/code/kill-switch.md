## Get kill switch status

Kill switch state of every segment.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    kill_switch_response_t *resp = UserAPI_getKillSwitch(client);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_getKillSwitch: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = kill_switch_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        kill_switch_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Update kill switch

Disables trading in the NSE_EQ and NSE_FO segments.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/UserAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    list_t *segments = list_createList();
    list_addElement(segments, kill_switch_segment_update_request_create(upstox_client_kill_switch_segment_update_request_SEGMENT_NSE_EQ, upstox_client_kill_switch_segment_update_request_ACTION_DISABLE));
    list_addElement(segments, kill_switch_segment_update_request_create(upstox_client_kill_switch_segment_update_request_SEGMENT_NSE_FO, upstox_client_kill_switch_segment_update_request_ACTION_DISABLE));

    kill_switch_response_t *resp = UserAPI_updateKillSwitch(client, segments);
    if (resp == NULL) {
        printf("Exception when calling UserAPI_updateKillSwitch: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = kill_switch_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        kill_switch_response_free(resp);
    }

    listEntry_t *entry;
    list_ForEach(entry, segments) {
        kill_switch_segment_update_request_free(entry->data);
    }
    list_freeList(segments);

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
