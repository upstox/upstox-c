## Get news by instrument keys

News articles for one or more instrument keys.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/NewsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_news_response_t *resp = NewsAPI_getNews(client, "instrument_keys", "NSE_EQ|INE669E01016", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling NewsAPI_getNews: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_news_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_news_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get news by instrument keys with pagination

First page of 10 articles for an instrument key.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/NewsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    int page_number = 1;
    int page_size = 10;

    get_news_response_t *resp = NewsAPI_getNews(client, "instrument_keys", "NSE_EQ|INE669E01016", &page_number, &page_size);
    if (resp == NULL) {
        printf("Exception when calling NewsAPI_getNews: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_news_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_news_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get news by positions

News for the instruments in your open positions.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/NewsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_news_response_t *resp = NewsAPI_getNews(client, "positions", NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling NewsAPI_getNews: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_news_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_news_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get news by holdings

News for the instruments in your holdings.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/NewsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    get_news_response_t *resp = NewsAPI_getNews(client, "holdings", NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling NewsAPI_getNews: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = get_news_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        get_news_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
