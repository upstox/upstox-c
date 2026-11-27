# USStocksFundsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**USStocksFundsAPI_getUsFunds**](USStocksFundsAPI.md#USStocksFundsAPI_getUsFunds) | **GET** /v2/us/funds | Get US stocks funds


# **USStocksFundsAPI_getUsFunds**
```c
// Get US stocks funds
//
// Returns the user's US stocks wallet balance in USD.
//
us_funds_response_t* USStocksFundsAPI_getUsFunds(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[us_funds_response_t](us_funds_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

