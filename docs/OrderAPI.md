# OrderAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OrderAPI_cancelMultiOrder**](OrderAPI.md#OrderAPI_cancelMultiOrder) | **DELETE** /v2/order/multi/cancel | Cancel multi order
[**OrderAPI_cancelOrder**](OrderAPI.md#OrderAPI_cancelOrder) | **DELETE** /v2/order/cancel | Cancel order
[**OrderAPI_exitPositions**](OrderAPI.md#OrderAPI_exitPositions) | **POST** /v2/order/positions/exit | Exit all positions
[**OrderAPI_getOrderBook**](OrderAPI.md#OrderAPI_getOrderBook) | **GET** /v2/order/retrieve-all | Get order book
[**OrderAPI_getOrderDetails**](OrderAPI.md#OrderAPI_getOrderDetails) | **GET** /v2/order/history | Get order history
[**OrderAPI_getOrderStatus**](OrderAPI.md#OrderAPI_getOrderStatus) | **GET** /v2/order/details | Get order details
[**OrderAPI_getTradeHistory**](OrderAPI.md#OrderAPI_getTradeHistory) | **GET** /v2/order/trades/get-trades-for-day | Get trades
[**OrderAPI_getTradesByOrder**](OrderAPI.md#OrderAPI_getTradesByOrder) | **GET** /v2/order/trades | Get trades for order
[**OrderAPI_modifyOrder**](OrderAPI.md#OrderAPI_modifyOrder) | **PUT** /v2/order/modify | Modify order
[**OrderAPI_placeMultiOrder**](OrderAPI.md#OrderAPI_placeMultiOrder) | **POST** /v2/order/multi/place | Place multi order
[**OrderAPI_placeOrder**](OrderAPI.md#OrderAPI_placeOrder) | **POST** /v2/order/place | Place order


# **OrderAPI_cancelMultiOrder**
```c
// Cancel multi order
//
// API to cancel all the open or pending orders which can be applied to both AMO and regular orders.
//
cancel_or_exit_multi_order_response_t* OrderAPI_cancelMultiOrder(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**tag** | **char \*** | The tag associated with the orders for which the orders must be cancelled | [optional] 
**segment** | **char \*** | The segment for which the orders must be cancelled | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[cancel_or_exit_multi_order_response_t](cancel_or_exit_multi_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_cancelOrder**
```c
// Cancel order
//
// Cancel order API can be used for two purposes: Cancelling an open order which could be an AMO or a normal order It is also used to EXIT a CO or OCO(bracket order)
//
cancel_order_response_t* OrderAPI_cancelOrder(apiClient_t *apiClient, char *order_id, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order ID for which the order must be cancelled | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[cancel_order_response_t](cancel_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_exitPositions**
```c
// Exit all positions
//
// This API provides the functionality to exit all the positions 
//
cancel_or_exit_multi_order_response_t* OrderAPI_exitPositions(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**tag** | **char \*** | The tag associated with the positions for which the positions must be exit | [optional] 
**segment** | **char \*** | The segment for which the positions must be exit | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[cancel_or_exit_multi_order_response_t](cancel_or_exit_multi_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_getOrderBook**
```c
// Get order book
//
// This API provides the list of orders placed by the user. The orders placed by the user is transient for a day and is cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.
//
get_order_book_response_t* OrderAPI_getOrderBook(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_order_book_response_t](get_order_book_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_getOrderDetails**
```c
// Get order history
//
// This API provides the details of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.  The order history can be requested either using order_id or tag.  If both the options are passed, the history of the order which precisely matches both the order_id and tag will be returned in the response.  If only the tag is passed, the history of all the associated orders which matches the tag will be shared in the response.
//
get_order_response_t* OrderAPI_getOrderDetails(apiClient_t *apiClient, char *order_id, char *tag);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order reference ID for which the order history is required | [optional] 
**tag** | **char \*** | The unique tag of the order for which the order history is being requested | [optional] 

### Return type

[get_order_response_t](get_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_getOrderStatus**
```c
// Get order details
//
// This API provides the recent detail of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session.\\n\\nThe order details can be requested using order_id.  
//
get_order_details_response_t* OrderAPI_getOrderStatus(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order reference ID for which the order details is required | [optional] 

### Return type

[get_order_details_response_t](get_order_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_getTradeHistory**
```c
// Get trades
//
// Retrieve the trades executed for the day
//
get_trade_response_t* OrderAPI_getTradeHistory(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_trade_response_t](get_trade_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_getTradesByOrder**
```c
// Get trades for order
//
// Retrieve the trades executed for an order
//
get_trade_response_t* OrderAPI_getTradesByOrder(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | The order ID for which the order to get order trades | 

### Return type

[get_trade_response_t](get_trade_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_modifyOrder**
```c
// Modify order
//
// This API allows you to modify an order. For modification orderId is mandatory. With orderId you need to send the optional parameter which needs to be modified. In case the optional parameters aren't sent, the default will be considered from the original order
//
modify_order_response_t* OrderAPI_modifyOrder(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**modify_order_request** | **[modify_order_request_t](modify_order_request.md) \*** |  | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[modify_order_response_t](modify_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_placeMultiOrder**
```c
// Place multi order
//
// This API allows you to place multiple orders to the exchange via Upstox.
//
multi_order_response_t* OrderAPI_placeMultiOrder(apiClient_t *apiClient, list_t *multi_order_request, char *Origin, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**multi_order_request** | **[list_t](multi_order_request.md) \*** |  | 
**Origin** | **char \*** |  | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[multi_order_response_t](multi_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderAPI_placeOrder**
```c
// Place order
//
// This API allows you to place an order to the exchange via Upstox.
//
place_order_response_t* OrderAPI_placeOrder(apiClient_t *apiClient, place_order_request_t *place_order_request, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**place_order_request** | **[place_order_request_t](place_order_request.md) \*** |  | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[place_order_response_t](place_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

