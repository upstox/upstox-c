# USStocksChargesAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**USStocksChargesAPI_calculateUsMargin**](USStocksChargesAPI.md#USStocksChargesAPI_calculateUsMargin) | **POST** /v2/us/charges/margin | Calculate US stocks margin


# **USStocksChargesAPI_calculateUsMargin**
```c
// Calculate US stocks margin
//
// Returns the margin up to 20 orders require (trade value + brokerage + GST for a buy), the buying power available, any shortfall, and whether it is sufficient. Takes order estimate bodies; nothing is placed. A market order is valued at the last traded price. No leverage is offered on US stocks.
//
us_margin_response_t* USStocksChargesAPI_calculateUsMargin(apiClient_t *apiClient, us_margin_request_t *us_margin_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**us_margin_request** | **[us_margin_request_t](us_margin_request.md) \*** |  | 

### Return type

[us_margin_response_t](us_margin_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

