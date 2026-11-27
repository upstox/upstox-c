# ChargeAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ChargeAPI_getBrokerage**](ChargeAPI.md#ChargeAPI_getBrokerage) | **GET** /v2/charges/brokerage | Brokerage details
[**ChargeAPI_postMargin**](ChargeAPI.md#ChargeAPI_postMargin) | **POST** /v2/charges/margin | Calculate Margin


# **ChargeAPI_getBrokerage**
```c
// Brokerage details
//
// Compute Brokerage Charges
//
get_brokerage_response_t* ChargeAPI_getBrokerage(apiClient_t *apiClient, char *instrument_token, int *quantity, char *product, char *transaction_type, double price);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_token** | **char \*** | Key of the instrument | 
**quantity** | **int \*** | Quantity with which the order is to be placed | 
**product** | **char \*** | Product with which the order is to be placed | 
**transaction_type** | **char \*** | Indicates whether its a BUY or SELL order | 
**price** | **double** | Price with which the order is to be placed | 

### Return type

[get_brokerage_response_t](get_brokerage_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **ChargeAPI_postMargin**
```c
// Calculate Margin
//
// Compute Margin
//
post_margin_response_t* ChargeAPI_postMargin(apiClient_t *apiClient, margin_request_t *margin_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**margin_request** | **[margin_request_t](margin_request.md) \*** |  | 

### Return type

[post_margin_response_t](post_margin_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

