# MarketQuoteAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**MarketQuoteAPI_getFullMarketQuote**](MarketQuoteAPI.md#MarketQuoteAPI_getFullMarketQuote) | **GET** /v2/market-quote/quotes | Market quotes and instruments - Full market quotes
[**MarketQuoteAPI_getMarketQuoteOHLC**](MarketQuoteAPI.md#MarketQuoteAPI_getMarketQuoteOHLC) | **GET** /v2/market-quote/ohlc | Market quotes and instruments - OHLC quotes
[**MarketQuoteAPI_ltp**](MarketQuoteAPI.md#MarketQuoteAPI_ltp) | **GET** /v2/market-quote/ltp | Market quotes and instruments - LTP quotes.


# **MarketQuoteAPI_getFullMarketQuote**
```c
// Market quotes and instruments - Full market quotes
//
// This API provides the functionality to retrieve the full market quotes for one or more instruments.This API returns the complete market data snapshot of up to 500 instruments in one go.
//
get_full_market_quote_response_t* MarketQuoteAPI_getFullMarketQuote(apiClient_t *apiClient, char *symbol, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**symbol** | **char \*** | Comma separated list of symbols | [optional] 
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_full_market_quote_response_t](get_full_market_quote_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketQuoteAPI_getMarketQuoteOHLC**
```c
// Market quotes and instruments - OHLC quotes
//
// This API provides the functionality to retrieve the OHLC quotes for one or more instruments.This API returns the OHLC snapshots of up to 1000 instruments in one go.
//
get_market_quote_ohlc_response_t* MarketQuoteAPI_getMarketQuoteOHLC(apiClient_t *apiClient, char *interval, char *symbol, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**interval** | **char \*** | Interval to get ohlc data | 
**symbol** | **char \*** | Comma separated list of symbols | [optional] 
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_market_quote_ohlc_response_t](get_market_quote_ohlc_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **MarketQuoteAPI_ltp**
```c
// Market quotes and instruments - LTP quotes.
//
// This API provides the functionality to retrieve the LTP quotes for one or more instruments.This API returns the LTPs of up to 1000 instruments in one go.
//
get_market_quote_last_traded_price_response_t* MarketQuoteAPI_ltp(apiClient_t *apiClient, char *symbol, char *instrument_key);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**symbol** | **char \*** | Comma separated list of symbols | [optional] 
**instrument_key** | **char \*** | Comma separated list of instrument keys | [optional] 

### Return type

[get_market_quote_last_traded_price_response_t](get_market_quote_last_traded_price_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

