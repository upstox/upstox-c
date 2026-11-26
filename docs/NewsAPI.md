# NewsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**NewsAPI_getNews**](NewsAPI.md#NewsAPI_getNews) | **GET** /v2/news | Get News


# **NewsAPI_getNews**
```c
// Get News
//
// Fetches news articles for the given instrument keys, or the user's current positions or holdings.
//
get_news_response_t* NewsAPI_getNews(apiClient_t *apiClient, char *category, char *instrument_keys, int *page_number, int *page_size);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**category** | **char \*** | Category of news to fetch. Allowed values: instrument_keys, positions, holdings | 
**instrument_keys** | **char \*** | Comma-separated list of instrument keys. Required when category is instrument_keys. | [optional] 
**page_number** | **int \*** | Page number for pagination | [optional] [default to 1]
**page_size** | **int \*** | Number of records per page | [optional] [default to 100]

### Return type

[get_news_response_t](get_news_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

