# MarketQuoteV3API

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MarketQuoteV3API_getFullMarketQuoteV3**](MarketQuoteV3API.md#MarketQuoteV3API_getFullMarketQuoteV3) | **GET** /v3/market-quote/quotes | Market quotes and instruments - Full market quotes
[**MarketQuoteV3API_getLtp**](MarketQuoteV3API.md#MarketQuoteV3API_getLtp) | **GET** /v3/market-quote/ltp | Market quotes and instruments - LTP quotes.
[**MarketQuoteV3API_getMarketQuoteOHLCV3**](MarketQuoteV3API.md#MarketQuoteV3API_getMarketQuoteOHLCV3) | **GET** /v3/market-quote/ohlc | Market quotes and instruments - OHLC quotes
[**MarketQuoteV3API_getMarketQuoteOptionGreek**](MarketQuoteV3API.md#MarketQuoteV3API_getMarketQuoteOptionGreek) | **GET** /v3/market-quote/option-greek | Market quotes and instruments - Option Greek


# **MarketQuoteV3API_getFullMarketQuoteV3**
```c
// Market quotes and instruments - Full market quotes
//
// This API provides the functionality to retrieve the full market quotes for one or more instruments.This API returns the complete market data snapshot of up to 500 instruments in one go, widened to carry every field published on the upstream extended feed.
//
get_full_market_quote_response_v3_t* MarketQuoteV3API_getFullMarketQuoteV3(apiClient_t *apiClient, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_full_market_quote_response_v3_t](get_full_market_quote_response_v3.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketQuoteV3API_getLtp**
```c
// Market quotes and instruments - LTP quotes.
//
// This API provides the functionality to retrieve the LTP quotes for one or more instruments.This API returns the LTPs of up to 500 instruments in one go.
//
get_market_quote_last_traded_price_response_v3_t* MarketQuoteV3API_getLtp(apiClient_t *apiClient, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_market_quote_last_traded_price_response_v3_t](get_market_quote_last_traded_price_response_v3.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketQuoteV3API_getMarketQuoteOHLCV3**
```c
// Market quotes and instruments - OHLC quotes
//
// This API provides the functionality to retrieve the OHLC quotes for one or more instruments.This API returns the OHLC snapshots of up to 500 instruments in one go.
//
get_market_quote_ohlc_response_v3_t* MarketQuoteV3API_getMarketQuoteOHLCV3(apiClient_t *apiClient, char *interval, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interval** | **char \*** | Interval to get ohlc data | 
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_market_quote_ohlc_response_v3_t](get_market_quote_ohlc_response_v3.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketQuoteV3API_getMarketQuoteOptionGreek**
```c
// Market quotes and instruments - Option Greek
//
// This API provides the functionality to retrieve the Option Greek data for one or more instruments.This API returns the Option Greek data of up to 500 instruments in one go.
//
get_market_quote_option_greek_response_v3_t* MarketQuoteV3API_getMarketQuoteOptionGreek(apiClient_t *apiClient, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_market_quote_option_greek_response_v3_t](get_market_quote_option_greek_response_v3.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

