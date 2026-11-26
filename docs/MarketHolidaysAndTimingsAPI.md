# MarketHolidaysAndTimingsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MarketHolidaysAndTimingsAPI_getChangeOiData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getChangeOiData) | **GET** /v2/market/change-oi | Get Change in OI Data
[**MarketHolidaysAndTimingsAPI_getDiiData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getDiiData) | **GET** /v2/market/dii | Get DII Data
[**MarketHolidaysAndTimingsAPI_getExchangeTimings**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getExchangeTimings) | **GET** /v2/market/timings/{date} | Get Exchange Timings on particular date
[**MarketHolidaysAndTimingsAPI_getFiiData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getFiiData) | **GET** /v2/market/fii | Get FII Data
[**MarketHolidaysAndTimingsAPI_getHoliday**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getHoliday) | **GET** /v2/market/holidays/{date} | Get Holiday on particular date
[**MarketHolidaysAndTimingsAPI_getHolidays**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getHolidays) | **GET** /v2/market/holidays | Get Holiday list of current year
[**MarketHolidaysAndTimingsAPI_getMarketStatus**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getMarketStatus) | **GET** /v2/market/status/{exchange} | Get Market status for particular exchange
[**MarketHolidaysAndTimingsAPI_getMaxPainData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getMaxPainData) | **GET** /v2/market/max-pain | Get Max Pain Data
[**MarketHolidaysAndTimingsAPI_getOiData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getOiData) | **GET** /v2/market/oi | Get OI Data
[**MarketHolidaysAndTimingsAPI_getPcrData**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getPcrData) | **GET** /v2/market/pcr | Get PCR Data
[**MarketHolidaysAndTimingsAPI_getSmartlistFutures**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getSmartlistFutures) | **GET** /v2/market/smartlist/futures | Get Smartlist Futures
[**MarketHolidaysAndTimingsAPI_getSmartlistMtf**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getSmartlistMtf) | **GET** /v2/market/smartlist/mtf | Get Smartlist MTF
[**MarketHolidaysAndTimingsAPI_getSmartlistOptions**](MarketHolidaysAndTimingsAPI.md#MarketHolidaysAndTimingsAPI_getSmartlistOptions) | **GET** /v2/market/smartlist/options | Get Smartlist Options


# **MarketHolidaysAndTimingsAPI_getChangeOiData**
```c
// Get Change in OI Data
//
// Fetches change in OI data for the given instrument key, expiry, date and interval.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getChangeOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *interval);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Underlying asset instrument key | 
**expiry** | **char \*** | Expiry date in YYYY-MM-DD format | 
**date** | **char \*** | Date in YYYY-MM-DD format for which change OI data is required | 
**interval** | **int \*** | Number of days for which difference in OI is required | 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getDiiData**
```c
// Get DII Data
//
// Fetches DII activity data for the given interval.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getDiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**data_type** | **char \*** | Data type. Allowed value: NSE_EQ|CASH | 
**interval** | **char \*** | Interval. Allowed values: 1D, 1M | 
**from** | **char \*** | Start date in YYYY-MM-DD format (optional) | [optional] 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getExchangeTimings**
```c
// Get Exchange Timings on particular date
//
// This API provides the functionality to retrieve the exchange timings on particular date
//
get_exchange_timing_response_t* MarketHolidaysAndTimingsAPI_getExchangeTimings(apiClient_t *apiClient, char *date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**date** | **char \*** |  | 

### Return type

[get_exchange_timing_response_t](get_exchange_timing_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getFiiData**
```c
// Get FII Data
//
// Fetches FII activity data for the given data type and interval.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getFiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**data_type** | **char \*** | Data type. Allowed values: NSE_FO|INDEX_FUTURES, NSE_FO|STOCK_FUTURES, NSE_FO|INDEX_OPTIONS, NSE_FO|STOCK_OPTIONS, NSE_EQ|CASH | 
**interval** | **char \*** | Interval. Allowed values: 1D, 1M | 
**from** | **char \*** | Start date in YYYY-MM-DD format (optional) | [optional] 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getHoliday**
```c
// Get Holiday on particular date
//
// This API provides the functionality to retrieve the holiday on particular date
//
get_holiday_response_t* MarketHolidaysAndTimingsAPI_getHoliday(apiClient_t *apiClient, char *date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**date** | **char \*** |  | 

### Return type

[get_holiday_response_t](get_holiday_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getHolidays**
```c
// Get Holiday list of current year
//
// This API provides the functionality to retrieve the holiday list of current year
//
get_holiday_response_t* MarketHolidaysAndTimingsAPI_getHolidays(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_holiday_response_t](get_holiday_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getMarketStatus**
```c
// Get Market status for particular exchange
//
// This API provides the functionality to retrieve the market status for particular exchange
//
get_market_status_response_t* MarketHolidaysAndTimingsAPI_getMarketStatus(apiClient_t *apiClient, char *exchange);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**exchange** | **char \*** |  | 

### Return type

[get_market_status_response_t](get_market_status_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getMaxPainData**
```c
// Get Max Pain Data
//
// Fetches Max Pain data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getMaxPainData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Underlying asset instrument key | 
**expiry** | **char \*** | Expiry date in YYYY-MM-DD format | 
**date** | **char \*** | Date in YYYY-MM-DD format for which Max Pain data is required | 
**bucket_interval** | **int \*** | Bucket interval in minutes for the insights list | 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getOiData**
```c
// Get OI Data
//
// Fetches OI data for the given instrument key, expiry and date.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Underlying asset instrument key | 
**expiry** | **char \*** | Expiry date in YYYY-MM-DD format | 
**date** | **char \*** | Date in YYYY-MM-DD format for which OI data is required | 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getPcrData**
```c
// Get PCR Data
//
// Fetches PCR (Put-Call Ratio) data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getPcrData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Underlying asset instrument key | 
**expiry** | **char \*** | Expiry date in YYYY-MM-DD format | 
**date** | **char \*** | Date in YYYY-MM-DD format for which PCR data is required | 
**bucket_interval** | **int \*** | Bucket interval in minutes for the insights list | 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getSmartlistFutures**
```c
// Get Smartlist Futures
//
// Fetches the smartlist of futures for the given asset type and category.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getSmartlistFutures(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**asset_type** | **char \*** | Asset type. Allowed values: INDEX, STOCK, COMMODITY | [optional] 
**category** | **char \*** | Category. Allowed values: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS, PRICE_GAINERS, PRICE_LOSERS, PREMIUM, DISCOUNT (COMMODITY supports only: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS) | [optional] 
**page_number** | **int \*** | Page number (optional, 1-indexed) | [optional] 
**page_size** | **int \*** | Page size (optional, max 50) | [optional] 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getSmartlistMtf**
```c
// Get Smartlist MTF
//
// Fetches the smartlist of MTF (Margin Trade Funding) stocks. Prices are enriched with live LTP data.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getSmartlistMtf(apiClient_t *apiClient, int *page_number, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**page_number** | **int \*** | Page number (optional, 1-indexed) | [optional] 
**page_size** | **int \*** | Page size (optional, max 50) | [optional] 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketHolidaysAndTimingsAPI_getSmartlistOptions**
```c
// Get Smartlist Options
//
// Fetches the smartlist of options for the given asset type and category.
//
analytics_response_t* MarketHolidaysAndTimingsAPI_getSmartlistOptions(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**asset_type** | **char \*** | Asset type. Allowed values: INDEX, STOCK, COMMODITY | [optional] 
**category** | **char \*** | Category. Allowed values: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS, PRICE_GAINERS, PRICE_LOSERS, IV_GAINERS, IV_LOSERS, UNDER_5000, UNDER_10000 (COMMODITY supports only: TOP_TRADED, MOST_ACTIVE, OI_GAINERS, OI_LOSERS) | [optional] 
**page_number** | **int \*** | Page number (optional, 1-indexed) | [optional] 
**page_size** | **int \*** | Page size (optional, max 50) | [optional] 

### Return type

[analytics_response_t](analytics_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

