# MutualFundAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MutualFundAPI_getMutualFundHoldings**](MutualFundAPI.md#MutualFundAPI_getMutualFundHoldings) | **GET** /v2/mf/holdings | Get mutual fund holdings
[**MutualFundAPI_getMutualFundOrder**](MutualFundAPI.md#MutualFundAPI_getMutualFundOrder) | **GET** /v2/mf/orders/{order_id} | Get mutual fund order by id
[**MutualFundAPI_getMutualFundOrders**](MutualFundAPI.md#MutualFundAPI_getMutualFundOrders) | **GET** /v2/mf/orders | Get mutual fund orders
[**MutualFundAPI_getMutualFundSips**](MutualFundAPI.md#MutualFundAPI_getMutualFundSips) | **GET** /v2/mf/sips | Get mutual fund SIPs


# **MutualFundAPI_getMutualFundHoldings**
```c
// Get mutual fund holdings
//
// Returns mutual fund holdings for the authenticated user.
//
get_mutual_fund_holdings_response_t* MutualFundAPI_getMutualFundHoldings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_mutual_fund_holdings_response_t](get_mutual_fund_holdings_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MutualFundAPI_getMutualFundOrder**
```c
// Get mutual fund order by id
//
// Returns a single mutual fund order by order id.
//
get_mutual_fund_order_details_response_t* MutualFundAPI_getMutualFundOrder(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | Mutual fund order id | 

### Return type

[get_mutual_fund_order_details_response_t](get_mutual_fund_order_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MutualFundAPI_getMutualFundOrders**
```c
// Get mutual fund orders
//
// Returns mutual fund orders from the last 7 days for the authenticated user.
//
get_mutual_fund_orders_response_t* MutualFundAPI_getMutualFundOrders(apiClient_t *apiClient, char *status, char *transaction_type, int *page_number, int *records);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **char \*** | Mutual fund order status | [optional] [default to &#39;ALL&#39;]
**transaction_type** | **char \*** | Mutual fund order transaction type | [optional] [default to &#39;ALL&#39;]
**page_number** | **int \*** | Page number for pagination. | [optional] [default to 1]
**records** | **int \*** | no of records in a single page | [optional] [default to 10]

### Return type

[get_mutual_fund_orders_response_t](get_mutual_fund_orders_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MutualFundAPI_getMutualFundSips**
```c
// Get mutual fund SIPs
//
// Returns active and paused SIP orders for the authenticated user.
//
get_mutual_fund_sips_response_t* MutualFundAPI_getMutualFundSips(apiClient_t *apiClient, int *page_number, int *records);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page_number** | **int \*** | Page number for pagination. | [optional] [default to 1]
**records** | **int \*** | no of records in a single page | [optional] [default to 10]

### Return type

[get_mutual_fund_sips_response_t](get_mutual_fund_sips_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

