# TradeProfitAndLossAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**TradeProfitAndLossAPI_getProfitAndLossCharges**](TradeProfitAndLossAPI.md#TradeProfitAndLossAPI_getProfitAndLossCharges) | **GET** /v2/trade/profit-loss/charges | Get profit and loss on trades
[**TradeProfitAndLossAPI_getTradeWiseProfitAndLossData**](TradeProfitAndLossAPI.md#TradeProfitAndLossAPI_getTradeWiseProfitAndLossData) | **GET** /v2/trade/profit-loss/data | Get Trade-wise Profit and Loss Report Data
[**TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData**](TradeProfitAndLossAPI.md#TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData) | **GET** /v2/trade/profit-loss/metadata | Get profit and loss meta data on trades


# **TradeProfitAndLossAPI_getProfitAndLossCharges**
```c
// Get profit and loss on trades
//
// This API gives the charges incurred by users for their trades
//
get_profit_and_loss_charges_response_t* TradeProfitAndLossAPI_getProfitAndLossCharges(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**segment** | **char \*** | Segment for which data is requested can be from the following options EQ - Equity,   FO - Futures and Options,   COM  - Commodity,   CD - Currency Derivatives | 
**financial_year** | **char \*** | Financial year for which data has been requested. Concatenation of last 2 digits of from year and to year Sample:for 2021-2022, financial_year will be 2122 | 
**from_date** | **char \*** | Date from which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 
**to_date** | **char \*** | Date till which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 

### Return type

[get_profit_and_loss_charges_response_t](get_profit_and_loss_charges_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **TradeProfitAndLossAPI_getTradeWiseProfitAndLossData**
```c
// Get Trade-wise Profit and Loss Report Data
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_data_response_t* TradeProfitAndLossAPI_getTradeWiseProfitAndLossData(apiClient_t *apiClient, char *segment, char *financial_year, int *page_number, int *page_size, char *from_date, char *to_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**segment** | **char \*** | Segment for which data is requested can be from the following options EQ - Equity,   FO - Futures and Options,   COM  - Commodity,   CD - Currency Derivatives | 
**financial_year** | **char \*** | Financial year for which data has been requested. Concatenation of last 2 digits of from year and to year Sample:for 2021-2022, financial_year will be 2122 | 
**page_number** | **int \*** | Page Number, the pages are starting from 1 | 
**page_size** | **int \*** | Page size for pagination. The maximum page size value is obtained from P and L report metadata API. | 
**from_date** | **char \*** | Date from which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 
**to_date** | **char \*** | Date till which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 

### Return type

[get_trade_wise_profit_and_loss_data_response_t](get_trade_wise_profit_and_loss_data_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData**
```c
// Get profit and loss meta data on trades
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_meta_data_response_t* TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**segment** | **char \*** | Segment for which data is requested can be from the following options EQ - Equity,   FO - Futures and Options,   COM  - Commodity,   CD - Currency Derivatives | 
**financial_year** | **char \*** | Financial year for which data has been requested. Concatenation of last 2 digits of from year and to year Sample:for 2021-2022, financial_year will be 2122 | 
**from_date** | **char \*** | Date from which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 
**to_date** | **char \*** | Date till which data needs to be fetched. from_date and to_date should fall under the same financial year as mentioned in financial_year attribute. Date in dd-mm-yyyy format | [optional] 

### Return type

[get_trade_wise_profit_and_loss_meta_data_response_t](get_trade_wise_profit_and_loss_meta_data_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

