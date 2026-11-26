# OptionsAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OptionsAPI_getOptionContracts**](OptionsAPI.md#OptionsAPI_getOptionContracts) | **GET** /v2/option/contract | Get option contracts
[**OptionsAPI_getPutCallOptionChain**](OptionsAPI.md#OptionsAPI_getPutCallOptionChain) | **GET** /v2/option/chain | Get option chain


# **OptionsAPI_getOptionContracts**
```c
// Get option contracts
//
// This API provides the functionality to retrieve the option contracts
//
get_option_contract_response_t* OptionsAPI_getOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument key for an underlying symbol | 
**expiry_date** | **char \*** | Expiry date in format: YYYY-mm-dd | [optional] 

### Return type

[get_option_contract_response_t](get_option_contract_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **OptionsAPI_getPutCallOptionChain**
```c
// Get option chain
//
// This API provides the functionality to retrieve the option chain
//
get_option_chain_response_t* OptionsAPI_getPutCallOptionChain(apiClient_t *apiClient, char *instrument_key, char *expiry_date);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instrument_key** | **char \*** | Instrument key for an underlying symbol | 
**expiry_date** | **char \*** | Expiry date in format: YYYY-mm-dd | 

### Return type

[get_option_chain_response_t](get_option_chain_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

