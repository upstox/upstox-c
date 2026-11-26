# PortfolioAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**PortfolioAPI_convertPositions**](PortfolioAPI.md#PortfolioAPI_convertPositions) | **PUT** /v2/portfolio/convert-position | Convert Positions
[**PortfolioAPI_getHoldings**](PortfolioAPI.md#PortfolioAPI_getHoldings) | **GET** /v2/portfolio/long-term-holdings | Get Holdings
[**PortfolioAPI_getMtfPositions**](PortfolioAPI.md#PortfolioAPI_getMtfPositions) | **GET** /v3/portfolio/mtf-positions | Get MTF positions
[**PortfolioAPI_getPositions**](PortfolioAPI.md#PortfolioAPI_getPositions) | **GET** /v2/portfolio/short-term-positions | Get Positions


# **PortfolioAPI_convertPositions**
```c
// Convert Positions
//
// Convert the margin product of an open position
//
convert_position_response_t* PortfolioAPI_convertPositions(apiClient_t *apiClient, convert_position_request_t *convert_position_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**convert_position_request** | **[convert_position_request_t](convert_position_request.md) \*** |  | 

### Return type

[convert_position_response_t](convert_position_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **PortfolioAPI_getHoldings**
```c
// Get Holdings
//
// Fetches the holdings which the user has bought/sold in previous trading sessions.
//
get_holdings_response_t* PortfolioAPI_getHoldings(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_holdings_response_t](get_holdings_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **PortfolioAPI_getMtfPositions**
```c
// Get MTF positions
//
// This API allows you to get MTF positions.
//
get_position_response_t* PortfolioAPI_getMtfPositions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_position_response_t](get_position_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **PortfolioAPI_getPositions**
```c
// Get Positions
//
// Fetches the current positions for the user for the current day.
//
get_position_response_t* PortfolioAPI_getPositions(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_position_response_t](get_position_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

