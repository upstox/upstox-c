## Get IPO listing

Lists IPOs.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    ipo_listing_response_t *resp = IPOAPI_getIpoListing(client, upstox_client_getIpoListing_STATUS_NULL, upstox_client_getIpoListing_ISSUETYPE_NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoListing: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = ipo_listing_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        ipo_listing_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get IPO listing with filters and pagination

Lists open regular (non-SME) IPOs, 20 per page.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // Status: open | closed | listed | upcoming; issue type: regular | sme

    ipo_listing_response_t *resp = IPOAPI_getIpoListing(client, upstox_client_getIpoListing_STATUS_open, upstox_client_getIpoListing_ISSUETYPE_regular, "1", "20");
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoListing: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = ipo_listing_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        ipo_listing_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get IPO details by id

Fetches price band, lot size and dates for one IPO.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/IPOAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    // The id is the IPO slug id returned by IPOAPI_getIpoListing
    char *ipo_id = "{ipo_slug_id}";

    ipo_details_response_t *resp = IPOAPI_getIpoDetails(client, ipo_id);
    if (resp == NULL) {
        printf("Exception when calling IPOAPI_getIpoDetails: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = ipo_details_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        ipo_details_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
