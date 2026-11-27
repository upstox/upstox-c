# HistoryAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HistoryAPI_getHistoricalCandleData**](HistoryAPI.md#HistoryAPI_getHistoricalCandleData) | **GET** /v2/historical-candle/{instrumentKey}/{interval}/{to_date} | Historical candle data
[**HistoryAPI_getHistoricalCandleData1**](HistoryAPI.md#HistoryAPI_getHistoricalCandleData1) | **GET** /v2/historical-candle/{instrumentKey}/{interval}/{to_date}/{from_date} | Historical candle data
[**HistoryAPI_getIntraDayCandleData**](HistoryAPI.md#HistoryAPI_getIntraDayCandleData) | **GET** /v2/historical-candle/intraday/{instrumentKey}/{interval} | Intra day candle data


# **HistoryAPI_getHistoricalCandleData**
```c
// Historical candle data
//
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t* HistoryAPI_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**interval** | **char \*** |  | 
**to_date** | **char \*** |  | 

### Return type

[get_historical_candle_response_t](get_historical_candle_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **HistoryAPI_getHistoricalCandleData1**
```c
// Historical candle data
//
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t* HistoryAPI_getHistoricalCandleData1(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date, char *from_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**interval** | **char \*** |  | 
**to_date** | **char \*** |  | 
**from_date** | **char \*** |  | 

### Return type

[get_historical_candle_response_t](get_historical_candle_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **HistoryAPI_getIntraDayCandleData**
```c
// Intra day candle data
//
// Get OHLC values for all instruments for the present trading day
//
get_intra_day_candle_response_t* HistoryAPI_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**interval** | **char \*** |  | 

### Return type

[get_intra_day_candle_response_t](get_intra_day_candle_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

