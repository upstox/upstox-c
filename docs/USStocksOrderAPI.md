# USStocksOrderAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**USStocksOrderAPI_cancelUsOrder**](USStocksOrderAPI.md#USStocksOrderAPI_cancelUsOrder) | **DELETE** /v2/us/order/cancel | Cancel US stocks order
[**USStocksOrderAPI_estimateUsOrder**](USStocksOrderAPI.md#USStocksOrderAPI_estimateUsOrder) | **POST** /v2/us/order/estimate | Estimate US stocks order charges
[**USStocksOrderAPI_getUsOrderBook**](USStocksOrderAPI.md#USStocksOrderAPI_getUsOrderBook) | **GET** /v2/us/order/retrieve-all | Get US stocks order book
[**USStocksOrderAPI_getUsOrderDetails**](USStocksOrderAPI.md#USStocksOrderAPI_getUsOrderDetails) | **GET** /v2/us/order/details | Get US stocks order details
[**USStocksOrderAPI_placeUsOrder**](USStocksOrderAPI.md#USStocksOrderAPI_placeUsOrder) | **POST** /v2/us/order/place | Place US stocks order


# **USStocksOrderAPI_cancelUsOrder**
```c
// Cancel US stocks order
//
// Cancels an open US stocks order.
//
us_order_response_t* USStocksOrderAPI_cancelUsOrder(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order id to cancel | 

### Return type

[us_order_response_t](us_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USStocksOrderAPI_estimateUsOrder**
```c
// Estimate US stocks order charges
//
// Returns the brokerage, GST and US fees for an order before it is placed; nothing is placed. A market order is estimated at the price sent.
//
us_order_estimate_response_t* USStocksOrderAPI_estimateUsOrder(apiClient_t *apiClient, us_order_estimate_request_t *us_order_estimate_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**us_order_estimate_request** | **[us_order_estimate_request_t](us_order_estimate_request.md) \*** |  | 

### Return type

[us_order_estimate_response_t](us_order_estimate_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USStocksOrderAPI_getUsOrderBook**
```c
// Get US stocks order book
//
// Returns the user's US stocks orders for the day, in every state; optionally only those with a tag.
//
us_order_book_response_t* USStocksOrderAPI_getUsOrderBook(apiClient_t *apiClient, char *tag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**tag** | **char \*** | Return only orders placed with this tag; exact, case-sensitive match | [optional] 

### Return type

[us_order_book_response_t](us_order_book_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USStocksOrderAPI_getUsOrderDetails**
```c
// Get US stocks order details
//
// Returns the latest state of one US stocks order.
//
us_order_details_response_t* USStocksOrderAPI_getUsOrderDetails(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order id to fetch | 

### Return type

[us_order_details_response_t](us_order_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USStocksOrderAPI_placeUsOrder**
```c
// Place US stocks order
//
// Places a market or limit order for a US stock, sized by quantity or by USD amount.
//
us_order_response_t* USStocksOrderAPI_placeUsOrder(apiClient_t *apiClient, us_place_order_request_t *us_place_order_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**us_place_order_request** | **[us_place_order_request_t](us_place_order_request.md) \*** |  | 

### Return type

[us_order_response_t](us_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

