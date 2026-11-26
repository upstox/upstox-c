# ExpiredInstrumentAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**ExpiredInstrumentAPI_getExpiredFutureContracts**](ExpiredInstrumentAPI.md#ExpiredInstrumentAPI_getExpiredFutureContracts) | **GET** /v2/expired-instruments/future/contract | Expired instruments - Get future contracts
[**ExpiredInstrumentAPI_getExpiredHistoricalCandleData**](ExpiredInstrumentAPI.md#ExpiredInstrumentAPI_getExpiredHistoricalCandleData) | **GET** /v2/expired-instruments/historical-candle/{expired_instrument_key}/{interval}/{to_date}/{from_date} | Expired Historical candle data
[**ExpiredInstrumentAPI_getExpiredOptionContracts**](ExpiredInstrumentAPI.md#ExpiredInstrumentAPI_getExpiredOptionContracts) | **GET** /v2/expired-instruments/option/contract | Get expired option contracts
[**ExpiredInstrumentAPI_getExpiriesResponse**](ExpiredInstrumentAPI.md#ExpiredInstrumentAPI_getExpiriesResponse) | **GET** /v2/expired-instruments/expiries | Expired instruments - Get expiries


# **ExpiredInstrumentAPI_getExpiredFutureContracts**
```c
// Expired instruments - Get future contracts
//
// This API provides the functionality to retrieve expired future contracts for a given instrument key and expiry date.
//
get_expired_futures_contract_response_t* ExpiredInstrumentAPI_getExpiredFutureContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument Key of asset | 
**expiry_date** | **char \*** | Expiry date of the instrument | 

### Return type

[get_expired_futures_contract_response_t](get_expired_futures_contract_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **ExpiredInstrumentAPI_getExpiredHistoricalCandleData**
```c
// Expired Historical candle data
//
// Get Expired OHLC values for all instruments across various timeframes. Expired Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t* ExpiredInstrumentAPI_getExpiredHistoricalCandleData(apiClient_t *apiClient, char *expired_instrument_key, char *interval, char *to_date, char *from_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**expired_instrument_key** | **char \*** | Expired Instrument Key of asset | 
**interval** | **char \*** | Interval to get expired ohlc data | 
**to_date** | **char \*** | to date | 
**from_date** | **char \*** | from date | 

### Return type

[get_historical_candle_response_t](get_historical_candle_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **ExpiredInstrumentAPI_getExpiredOptionContracts**
```c
// Get expired option contracts
//
// This API provides the functionality to retrieve the expired option contracts
//
get_option_contract_response_t* ExpiredInstrumentAPI_getExpiredOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument key for an underlying symbol | 
**expiry_date** | **char \*** | Expiry date in format: YYYY-mm-dd | 

### Return type

[get_option_contract_response_t](get_option_contract_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **ExpiredInstrumentAPI_getExpiriesResponse**
```c
// Expired instruments - Get expiries
//
// This API provides the functionality to retrieve expiry dates for a given instrument key.
//
get_expiries_response_t* ExpiredInstrumentAPI_getExpiriesResponse(apiClient_t *apiClient, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument Key of asset | 

### Return type

[get_expiries_response_t](get_expiries_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

