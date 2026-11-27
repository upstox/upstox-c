# InstrumentsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**InstrumentsAPI_searchInstrument**](InstrumentsAPI.md#InstrumentsAPI_searchInstrument) | **GET** /v2/instruments/search | Search instruments


# **InstrumentsAPI_searchInstrument**
```c
// Search instruments
//
// This API provides the functionality to retrieve the instrument details for searched query
//
search_instrument_response_t* InstrumentsAPI_searchInstrument(apiClient_t *apiClient, char *query, char *exchanges, char *segments, char *instrument_types, char *expiry, int *atm_offset, int *page_number, int *records);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**query** | **char \*** | natural language query | 
**exchanges** | **char \*** | Comma separated exchanges | [optional] 
**segments** | **char \*** | Comma separated segments | [optional] 
**instrument_types** | **char \*** | Comma separated instrument types | [optional] 
**expiry** | **char \*** | expiry in format: yyyy-MM-dd | [optional] 
**atm_offset** | **int \*** | page number greater than or equal to 1 | [optional] 
**page_number** | **int \*** | ATM offset number for queries like ATM, ATM+1, ATM-1, etc. | [optional] [default to 1]
**records** | **int \*** | no of records in a single page | [optional] [default to 10]

### Return type

[search_instrument_response_t](search_instrument_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

