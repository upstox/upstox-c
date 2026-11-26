# PostTradeAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PostTradeAPI_getTradesByDateRange**](PostTradeAPI.md#PostTradeAPI_getTradesByDateRange) | **GET** /v2/charges/historical-trades | Get historical trades


# **PostTradeAPI_getTradesByDateRange**
```c
// Get historical trades
//
// This API retrieves the trade history for a specified time interval.
//
trade_history_response_t* PostTradeAPI_getTradesByDateRange(apiClient_t *apiClient, char *start_date, char *end_date, int *page_number, int *page_size, char *segment);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**start_date** | **char \*** | Date from which trade history needs to be fetched. Date in YYYY-mm-dd format | 
**end_date** | **char \*** | Date till which history needs needs to be fetched. Date in YYYY-mm-dd format | 
**page_number** | **int \*** | Page number for which you want to fetch trade history  | 
**page_size** | **int \*** | How many records you want for a page  | 
**segment** | **char \*** | Segment for which data is requested can be from the following options EQ - Equity,   FO - Futures and Options,   COM  - Commodity,   CD - Currency Derivatives MF - Mutual Funds | [optional] [default to &#39;&#39;]

### Return type

[trade_history_response_t](trade_history_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

