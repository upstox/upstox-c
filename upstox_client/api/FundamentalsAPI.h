#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/balance_sheet_response.h"
#include "../models/cash_flow_response.h"
#include "../models/company_profile_response.h"
#include "../models/competitors_response.h"
#include "../models/corporate_actions_response.h"
#include "../models/income_statement_response.h"
#include "../models/key_ratios_response.h"
#include "../models/share_holdings_response.h"


// Get Balance Sheet
//
// Fetches balance sheet data for the given ISIN.
//
balance_sheet_response_t*
FundamentalsAPI_getBalanceSheet(apiClient_t *apiClient, char *isin, char *type, int *fs);


// Get Cash Flow
//
// Fetches cash flow data for the given ISIN.
//
cash_flow_response_t*
FundamentalsAPI_getCashFlow(apiClient_t *apiClient, char *isin, char *type, int *fs);


// Get Company Profile
//
// Fetches company profile information for the given ISIN.
//
company_profile_response_t*
FundamentalsAPI_getCompanyProfile(apiClient_t *apiClient, char *isin);


// Get Competitors
//
// Fetches the list of competitors for the given instrument_key.
//
competitors_response_t*
FundamentalsAPI_getCompetitors(apiClient_t *apiClient, char *instrument_key);


// Get Corporate Actions
//
// Fetches corporate actions for the given ISIN.
//
corporate_actions_response_t*
FundamentalsAPI_getCorporateActions(apiClient_t *apiClient, char *isin);


// Get Income Statement
//
// Fetches income statement data for the given ISIN.
//
income_statement_response_t*
FundamentalsAPI_getIncomeStatement(apiClient_t *apiClient, char *isin, char *type, char *time_period, int *fs);


// Get Key Ratios
//
// Fetches key financial ratios for the given ISIN.
//
key_ratios_response_t*
FundamentalsAPI_getKeyRatios(apiClient_t *apiClient, char *isin);


// Get Share Holdings
//
// Fetches shareholding pattern for the given ISIN.
//
share_holdings_response_t*
FundamentalsAPI_getShareHoldings(apiClient_t *apiClient, char *isin);


