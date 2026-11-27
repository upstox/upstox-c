# FundamentalsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FundamentalsAPI_getBalanceSheet**](FundamentalsAPI.md#FundamentalsAPI_getBalanceSheet) | **GET** /v2/fundamentals/{isin}/balance-sheet | Get Balance Sheet
[**FundamentalsAPI_getCashFlow**](FundamentalsAPI.md#FundamentalsAPI_getCashFlow) | **GET** /v2/fundamentals/{isin}/cash-flow | Get Cash Flow
[**FundamentalsAPI_getCompanyProfile**](FundamentalsAPI.md#FundamentalsAPI_getCompanyProfile) | **GET** /v2/fundamentals/{isin}/profile | Get Company Profile
[**FundamentalsAPI_getCompetitors**](FundamentalsAPI.md#FundamentalsAPI_getCompetitors) | **GET** /v2/fundamentals/{instrument_key}/competitors | Get Competitors
[**FundamentalsAPI_getCorporateActions**](FundamentalsAPI.md#FundamentalsAPI_getCorporateActions) | **GET** /v2/fundamentals/{isin}/corporate-actions | Get Corporate Actions
[**FundamentalsAPI_getIncomeStatement**](FundamentalsAPI.md#FundamentalsAPI_getIncomeStatement) | **GET** /v2/fundamentals/{isin}/income-statement | Get Income Statement
[**FundamentalsAPI_getKeyRatios**](FundamentalsAPI.md#FundamentalsAPI_getKeyRatios) | **GET** /v2/fundamentals/{isin}/key-ratios | Get Key Ratios
[**FundamentalsAPI_getShareHoldings**](FundamentalsAPI.md#FundamentalsAPI_getShareHoldings) | **GET** /v2/fundamentals/{isin}/share-holdings | Get Share Holdings


# **FundamentalsAPI_getBalanceSheet**
```c
// Get Balance Sheet
//
// Fetches balance sheet data for the given ISIN.
//
balance_sheet_response_t* FundamentalsAPI_getBalanceSheet(apiClient_t *apiClient, char *isin, char *type, int *fs);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 
**type** | **char \*** | Report type. Allowed values: consolidated or standalone | [optional] [default to &#39;consolidated&#39;]
**fs** | **int \*** | Whether to include the full financial statement | [optional] [default to false]

### Return type

[balance_sheet_response_t](balance_sheet_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getCashFlow**
```c
// Get Cash Flow
//
// Fetches cash flow data for the given ISIN.
//
cash_flow_response_t* FundamentalsAPI_getCashFlow(apiClient_t *apiClient, char *isin, char *type, int *fs);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 
**type** | **char \*** | Report type. Allowed values: consolidated, standalone | [optional] [default to &#39;consolidated&#39;]
**fs** | **int \*** | Whether to include the full financial statement | [optional] [default to false]

### Return type

[cash_flow_response_t](cash_flow_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getCompanyProfile**
```c
// Get Company Profile
//
// Fetches company profile information for the given ISIN.
//
company_profile_response_t* FundamentalsAPI_getCompanyProfile(apiClient_t *apiClient, char *isin);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 

### Return type

[company_profile_response_t](company_profile_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getCompetitors**
```c
// Get Competitors
//
// Fetches the list of competitors for the given instrument_key.
//
competitors_response_t* FundamentalsAPI_getCompetitors(apiClient_t *apiClient, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument key of the company | 

### Return type

[competitors_response_t](competitors_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getCorporateActions**
```c
// Get Corporate Actions
//
// Fetches corporate actions for the given ISIN.
//
corporate_actions_response_t* FundamentalsAPI_getCorporateActions(apiClient_t *apiClient, char *isin);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 

### Return type

[corporate_actions_response_t](corporate_actions_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getIncomeStatement**
```c
// Get Income Statement
//
// Fetches income statement data for the given ISIN.
//
income_statement_response_t* FundamentalsAPI_getIncomeStatement(apiClient_t *apiClient, char *isin, char *type, char *time_period, int *fs);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 
**type** | **char \*** | Report type. Allowed values: consolidated or standalone | [optional] [default to &#39;consolidated&#39;]
**time_period** | **char \*** | Time period. Allowed values: yearly, quarterly | [optional] [default to &#39;yearly&#39;]
**fs** | **int \*** | Whether to include the full financial statement | [optional] [default to false]

### Return type

[income_statement_response_t](income_statement_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getKeyRatios**
```c
// Get Key Ratios
//
// Fetches key financial ratios for the given ISIN.
//
key_ratios_response_t* FundamentalsAPI_getKeyRatios(apiClient_t *apiClient, char *isin);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 

### Return type

[key_ratios_response_t](key_ratios_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **FundamentalsAPI_getShareHoldings**
```c
// Get Share Holdings
//
// Fetches shareholding pattern for the given ISIN.
//
share_holdings_response_t* FundamentalsAPI_getShareHoldings(apiClient_t *apiClient, char *isin);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**isin** | **char \*** | ISIN of the company | 

### Return type

[share_holdings_response_t](share_holdings_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

