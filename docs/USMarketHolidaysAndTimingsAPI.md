# USMarketHolidaysAndTimingsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**USMarketHolidaysAndTimingsAPI_getUsExchangeTimings**](USMarketHolidaysAndTimingsAPI.md#USMarketHolidaysAndTimingsAPI_getUsExchangeTimings) | **GET** /v2/us/market/timings/{date} | Get US market timings on a date
[**USMarketHolidaysAndTimingsAPI_getUsHoliday**](USMarketHolidaysAndTimingsAPI.md#USMarketHolidaysAndTimingsAPI_getUsHoliday) | **GET** /v2/us/market/holidays/{date} | Get US market holiday on a date
[**USMarketHolidaysAndTimingsAPI_getUsHolidays**](USMarketHolidaysAndTimingsAPI.md#USMarketHolidaysAndTimingsAPI_getUsHolidays) | **GET** /v2/us/market/holidays | Get US market holidays
[**USMarketHolidaysAndTimingsAPI_getUsMarketStatus**](USMarketHolidaysAndTimingsAPI.md#USMarketHolidaysAndTimingsAPI_getUsMarketStatus) | **GET** /v2/us/market/status | Get US market status


# **USMarketHolidaysAndTimingsAPI_getUsExchangeTimings**
```c
// Get US market timings on a date
//
// Returns the US regular and overnight session times on the date, or an empty list when closed.
//
get_us_exchange_timing_response_t* USMarketHolidaysAndTimingsAPI_getUsExchangeTimings(apiClient_t *apiClient, char *date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**date** | **char \*** |  | 

### Return type

[get_us_exchange_timing_response_t](get_us_exchange_timing_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USMarketHolidaysAndTimingsAPI_getUsHoliday**
```c
// Get US market holiday on a date
//
// Returns the US market holiday on the date, or an empty list.
//
get_us_holiday_response_t* USMarketHolidaysAndTimingsAPI_getUsHoliday(apiClient_t *apiClient, char *date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**date** | **char \*** |  | 

### Return type

[get_us_holiday_response_t](get_us_holiday_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USMarketHolidaysAndTimingsAPI_getUsHolidays**
```c
// Get US market holidays
//
// Returns the US market holidays of the current year.
//
get_us_holiday_response_t* USMarketHolidaysAndTimingsAPI_getUsHolidays(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_us_holiday_response_t](get_us_holiday_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **USMarketHolidaysAndTimingsAPI_getUsMarketStatus**
```c
// Get US market status
//
// Returns the live status of the US market.
//
get_market_status_response_t* USMarketHolidaysAndTimingsAPI_getUsMarketStatus(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_market_status_response_t](get_market_status_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

