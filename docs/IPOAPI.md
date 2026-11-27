# IPOAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**IPOAPI_applyForIpo**](IPOAPI.md#IPOAPI_applyForIpo) | **POST** /v2/ipos/orders | Apply for IPO
[**IPOAPI_cancelIpoOrder**](IPOAPI.md#IPOAPI_cancelIpoOrder) | **DELETE** /v2/ipos/orders/{order_id} | Cancel IPO Order
[**IPOAPI_getIpoDetails**](IPOAPI.md#IPOAPI_getIpoDetails) | **GET** /v2/ipos/{id} | Get IPO Details
[**IPOAPI_getIpoListing**](IPOAPI.md#IPOAPI_getIpoListing) | **GET** /v2/ipos | Get IPO Listing
[**IPOAPI_getIpoOrderById**](IPOAPI.md#IPOAPI_getIpoOrderById) | **GET** /v2/ipos/orders/{order_id} | Get IPO Order
[**IPOAPI_getIpoOrders**](IPOAPI.md#IPOAPI_getIpoOrders) | **GET** /v2/ipos/orders | Get IPO Orders


# **IPOAPI_applyForIpo**
```c
// Apply for IPO
//
// Places an IPO application for the authenticated user.
//
ipo_apply_response_t* IPOAPI_applyForIpo(apiClient_t *apiClient, ipo_apply_request_t *ipo_apply_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**ipo_apply_request** | **[ipo_apply_request_t](ipo_apply_request.md) \*** |  | 

### Return type

[ipo_apply_response_t](ipo_apply_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **IPOAPI_cancelIpoOrder**
```c
// Cancel IPO Order
//
// Cancels/deletes an IPO order of the authenticated user by order id.
//
ipo_cancel_response_t* IPOAPI_cancelIpoOrder(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | IPO application id, as returned in &#x60;order_id&#x60; by the apply and orders APIs | 

### Return type

[ipo_cancel_response_t](ipo_cancel_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **IPOAPI_getIpoDetails**
```c
// Get IPO Details
//
// Fetches detailed information for an IPO by its slug ID.
//
ipo_details_response_t* IPOAPI_getIpoDetails(apiClient_t *apiClient, char *id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**id** | **char \*** | IPO id (slug), as returned in &#x60;id&#x60; by the IPO listing API | 

### Return type

[ipo_details_response_t](ipo_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **IPOAPI_getIpoListing**
```c
// Get IPO Listing
//
// Fetches list of IPOs filtered by status.
//
ipo_listing_response_t* IPOAPI_getIpoListing(apiClient_t *apiClient, upstox_client_getIpoListing_status_e status, upstox_client_getIpoListing_issue_type_e issue_type, char *page_number, char *records);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**status** | **upstox_client_getIpoListing_status_e** | IPO status to filter by | [optional] 
**issue_type** | **upstox_client_getIpoListing_issue_type_e** | Issue type filter. &#x60;regular&#x60; is a mainboard issue. Returns both when omitted | [optional] 
**page_number** | **char \*** | Page number, starting at 1 | [optional] 
**records** | **char \*** | Number of records per page | [optional] 

### Return type

[ipo_listing_response_t](ipo_listing_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **IPOAPI_getIpoOrderById**
```c
// Get IPO Order
//
// Fetches a single IPO order of the authenticated user by order id.
//
ipo_order_detail_response_t* IPOAPI_getIpoOrderById(apiClient_t *apiClient, char *order_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**order_id** | **char \*** | IPO application id, as returned in &#x60;order_id&#x60; by the apply and orders APIs | 

### Return type

[ipo_order_detail_response_t](ipo_order_detail_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **IPOAPI_getIpoOrders**
```c
// Get IPO Orders
//
// Fetches the authenticated user's IPO orders/applications.
//
ipo_order_response_t* IPOAPI_getIpoOrders(apiClient_t *apiClient, char *page_number, char *records);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page_number** | **char \*** | Page number, starting at 1 | [optional] 
**records** | **char \*** | Number of records per page | [optional] 

### Return type

[ipo_order_response_t](ipo_order_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

