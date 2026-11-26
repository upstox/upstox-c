## Get Company Profile

Company profile for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    company_profile_response_t *resp = FundamentalsAPI_getCompanyProfile(client, "INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getCompanyProfile: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = company_profile_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        company_profile_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Key Ratios

Key financial ratios for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    key_ratios_response_t *resp = FundamentalsAPI_getKeyRatios(client, "INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getKeyRatios: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = key_ratios_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        key_ratios_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Balance Sheet

Balance sheet for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    balance_sheet_response_t *resp = FundamentalsAPI_getBalanceSheet(client, "INE669E01016", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getBalanceSheet: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = balance_sheet_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        balance_sheet_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Income Statement

Income statement for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    income_statement_response_t *resp = FundamentalsAPI_getIncomeStatement(client, "INE669E01016", NULL, NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getIncomeStatement: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = income_statement_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        income_statement_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Cash Flow

Cash flow statement for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    cash_flow_response_t *resp = FundamentalsAPI_getCashFlow(client, "INE669E01016", NULL, NULL);
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getCashFlow: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        if (resp->data == NULL) {
            printf("no data returned\n");
        } else {
            cJSON *json = cash_flow_response_convertToJSON(resp);
            char *out = cJSON_Print(json);
            printf("%s\n", out);
            cJSON_free(out);
            cJSON_Delete(json);
        }
        cash_flow_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Competitors

Peer companies for an instrument key.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    competitors_response_t *resp = FundamentalsAPI_getCompetitors(client, "NSE_EQ|INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getCompetitors: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = competitors_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        competitors_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Corporate Actions

Dividends, splits, bonuses and other corporate actions for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    corporate_actions_response_t *resp = FundamentalsAPI_getCorporateActions(client, "INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getCorporateActions: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = corporate_actions_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        corporate_actions_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```

## Get Share Holdings

Shareholding pattern for an ISIN.

```c
#include <stdio.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/FundamentalsAPI.h"

int main(void) {
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create("{your_access_token}");

    share_holdings_response_t *resp = FundamentalsAPI_getShareHoldings(client, "INE669E01016");
    if (resp == NULL) {
        printf("Exception when calling FundamentalsAPI_getShareHoldings: HTTP %ld %s\n", client->response_code, client->errorBody ? client->errorBody : "");
    } else {
        cJSON *json = share_holdings_response_convertToJSON(resp);
        char *out = cJSON_Print(json);
        printf("%s\n", out);
        cJSON_free(out);
        cJSON_Delete(json);
        share_holdings_response_free(resp);
    }

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
```
