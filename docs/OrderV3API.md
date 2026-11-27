# OrderV3API

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OrderV3API_cancelGTTOrder**](OrderV3API.md#OrderV3API_cancelGTTOrder) | **DELETE** /v3/order/gtt/cancel | Cancel GTT order
[**OrderV3API_cancelOrder**](OrderV3API.md#OrderV3API_cancelOrder) | **DELETE** /v3/order/cancel | 
[**OrderV3API_getGttOrderDetails**](OrderV3API.md#OrderV3API_getGttOrderDetails) | **GET** /v3/order/gtt | Get GTT order details
[**OrderV3API_modifyGTTOrder**](OrderV3API.md#OrderV3API_modifyGTTOrder) | **PUT** /v3/order/gtt/modify | Modify GTT order
[**OrderV3API_modifyOrder**](OrderV3API.md#OrderV3API_modifyOrder) | **PUT** /v3/order/modify | 
[**OrderV3API_placeGTTOrder**](OrderV3API.md#OrderV3API_placeGTTOrder) | **POST** /v3/order/gtt/place | Place GTT order
[**OrderV3API_placeOrder**](OrderV3API.md#OrderV3API_placeOrder) | **POST** /v3/order/place | 


# **OrderV3API_cancelGTTOrder**
```c
// Cancel GTT order
//
// This API allows you to cancel GTT orders.
//
gtt_trigger_order_response_t* OrderV3API_cancelGTTOrder(apiClient_t *apiClient, gtt_cancel_order_request_t *gtt_cancel_order_request, char *Origin, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gtt_cancel_order_request** | **[gtt_cancel_order_request_t](gtt_cancel_order_request.md) \*** |  | 
**Origin** | **char \*** |  | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[gtt_trigger_order_response_t](gtt_trigger_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_cancelOrder**
```c
cancel_order_v3_response_t* OrderV3API_cancelOrder(apiClient_t *apiClient, char *order_id, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** |  | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[cancel_order_v3_response_t](cancel_order_v3_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_getGttOrderDetails**
```c
// Get GTT order details
//
// GTT_ORDER_DESCRIPTION
//
get_gtt_order_response_t* OrderV3API_getGttOrderDetails(apiClient_t *apiClient, char *gtt_order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gtt_order_id** | **char \*** | Unique identifier of the GTT order for which the order history is required | [optional] 

### Return type

[get_gtt_order_response_t](get_gtt_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_modifyGTTOrder**
```c
// Modify GTT order
//
// This API allows you to modify GTT orders.
//
gtt_trigger_order_response_t* OrderV3API_modifyGTTOrder(apiClient_t *apiClient, gtt_modify_order_request_t *gtt_modify_order_request, char *Origin, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gtt_modify_order_request** | **[gtt_modify_order_request_t](gtt_modify_order_request.md) \*** |  | 
**Origin** | **char \*** |  | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[gtt_trigger_order_response_t](gtt_trigger_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_modifyOrder**
```c
modify_order_v3_response_t* OrderV3API_modifyOrder(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**modify_order_request** | **[modify_order_request_t](modify_order_request.md) \*** |  | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[modify_order_v3_response_t](modify_order_v3_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_placeGTTOrder**
```c
// Place GTT order
//
// This API allows you to place GTT orders.
//
gtt_trigger_order_response_t* OrderV3API_placeGTTOrder(apiClient_t *apiClient, gtt_place_order_request_t *gtt_place_order_request, char *Origin, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**gtt_place_order_request** | **[gtt_place_order_request_t](gtt_place_order_request.md) \*** |  | 
**Origin** | **char \*** |  | [optional] 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[gtt_trigger_order_response_t](gtt_trigger_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OrderV3API_placeOrder**
```c
place_order_v3_response_t* OrderV3API_placeOrder(apiClient_t *apiClient, place_order_v3_request_t *place_order_v3_request, char *X_Algo_Name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**place_order_v3_request** | **[place_order_v3_request_t](place_order_v3_request.md) \*** |  | 
**X_Algo_Name** | **char \*** | Algorithm name, used to track and manage orders | [optional] 

### Return type

[place_order_v3_response_t](place_order_v3_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

