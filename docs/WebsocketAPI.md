# WebsocketAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WebsocketAPI_getMarketDataFeed**](WebsocketAPI.md#WebsocketAPI_getMarketDataFeed) | **GET** /v2/feed/market-data-feed | Market Data Feed
[**WebsocketAPI_getMarketDataFeedAuthorize**](WebsocketAPI.md#WebsocketAPI_getMarketDataFeedAuthorize) | **GET** /v2/feed/market-data-feed/authorize | Market Data Feed Authorize
[**WebsocketAPI_getMarketDataFeedAuthorizeV3**](WebsocketAPI.md#WebsocketAPI_getMarketDataFeedAuthorizeV3) | **GET** /v3/feed/market-data-feed/authorize | Market Data Feed Authorize (V3)
[**WebsocketAPI_getMarketDataFeedV3**](WebsocketAPI.md#WebsocketAPI_getMarketDataFeedV3) | **GET** /v3/feed/market-data-feed | Market Data Feed (V3)
[**WebsocketAPI_getPortfolioStreamFeed**](WebsocketAPI.md#WebsocketAPI_getPortfolioStreamFeed) | **GET** /v2/feed/portfolio-stream-feed | Portfolio Stream Feed
[**WebsocketAPI_getPortfolioStreamFeedAuthorize**](WebsocketAPI.md#WebsocketAPI_getPortfolioStreamFeedAuthorize) | **GET** /v2/feed/portfolio-stream-feed/authorize | Portfolio Stream Feed Authorize


# **WebsocketAPI_getMarketDataFeed**
```c
// Market Data Feed
//
//  This API redirects the client to the respective socket endpoint to receive Market updates.
//
void WebsocketAPI_getMarketDataFeed(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **WebsocketAPI_getMarketDataFeedAuthorize**
```c
// Market Data Feed Authorize
//
// This API provides the functionality to retrieve the socket endpoint URI for Market updates.
//
websocket_auth_redirect_response_t* WebsocketAPI_getMarketDataFeedAuthorize(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[websocket_auth_redirect_response_t](websocket_auth_redirect_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **WebsocketAPI_getMarketDataFeedAuthorizeV3**
```c
// Market Data Feed Authorize (V3)
//
// This API provides the functionality to retrieve the socket endpoint URI for Market updates.
//
websocket_auth_redirect_response_t* WebsocketAPI_getMarketDataFeedAuthorizeV3(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[websocket_auth_redirect_response_t](websocket_auth_redirect_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **WebsocketAPI_getMarketDataFeedV3**
```c
// Market Data Feed (V3)
//
//  This API redirects the client to the respective socket endpoint to receive Market updates.
//
void WebsocketAPI_getMarketDataFeedV3(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **WebsocketAPI_getPortfolioStreamFeed**
```c
// Portfolio Stream Feed
//
// This API redirects the client to the respective socket endpoint to receive Portfolio updates.
//
void WebsocketAPI_getPortfolioStreamFeed(apiClient_t *apiClient, char *update_types);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_types** | **char \*** | Identifiers separated by commas denote the types of updates to receive. | [optional] 

### Return type

void

### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **WebsocketAPI_getPortfolioStreamFeedAuthorize**
```c
// Portfolio Stream Feed Authorize
//
//  This API provides the functionality to retrieve the socket endpoint URI for Portfolio updates.
//
websocket_auth_redirect_response_t* WebsocketAPI_getPortfolioStreamFeedAuthorize(apiClient_t *apiClient, char *update_types);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_types** | **char \*** | Identifiers separated by commas denote the types of updates to receive. | [optional] 

### Return type

[websocket_auth_redirect_response_t](websocket_auth_redirect_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

