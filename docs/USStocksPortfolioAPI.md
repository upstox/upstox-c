# USStocksPortfolioAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**USStocksPortfolioAPI_getUsHoldings**](USStocksPortfolioAPI.md#USStocksPortfolioAPI_getUsHoldings) | **GET** /v2/us/portfolio/holdings | Get US stocks holdings


# **USStocksPortfolioAPI_getUsHoldings**
```c
// Get US stocks holdings
//
// Returns the user's US stocks holdings.
//
us_holdings_response_t* USStocksPortfolioAPI_getUsHoldings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[us_holdings_response_t](us_holdings_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

