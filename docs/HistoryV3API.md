# HistoryV3API

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**HistoryV3API_getHistoricalCandleData1**](HistoryV3API.md#HistoryV3API_getHistoricalCandleData1) | **GET** /v3/historical-candle/{instrumentKey}/{unit}/{interval}/{to_date}/{from_date} | Historical candle data
[**HistoryV3API_getHistoricalCandleData**](HistoryV3API.md#HistoryV3API_getHistoricalCandleData) | **GET** /v3/historical-candle/{instrumentKey}/{unit}/{interval}/{to_date} | Historical candle data
[**HistoryV3API_getIntraDayCandleData**](HistoryV3API.md#HistoryV3API_getIntraDayCandleData) | **GET** /v3/historical-candle/intraday/{instrumentKey}/{unit}/{interval} | Intra day candle data


# **HistoryV3API_getHistoricalCandleData1**
```c
// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options
//
get_historical_candle_response_t* HistoryV3API_getHistoricalCandleData1(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date, char *from_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**unit** | **char \*** |  | 
**interval** | **int \*** |  | 
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

# **HistoryV3API_getHistoricalCandleData**
```c
// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options.
//
get_historical_candle_response_t* HistoryV3API_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**unit** | **char \*** |  | 
**interval** | **int \*** |  | 
**to_date** | **char \*** |  | 

### Return type

[get_historical_candle_response_t](get_historical_candle_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **HistoryV3API_getIntraDayCandleData**
```c
// Intra day candle data
//
// Get OHLC values for all instruments for the present trading day
//
get_intra_day_candle_response_t* HistoryV3API_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrumentKey** | **char \*** |  | 
**unit** | **char \*** |  | 
**interval** | **int \*** |  | 

### Return type

[get_intra_day_candle_response_t](get_intra_day_candle_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

