# LoginAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LoginAPI_authorize**](LoginAPI.md#LoginAPI_authorize) | **GET** /v2/login/authorization/dialog | Authorize API
[**LoginAPI_generateTokenViaTotpAndPin**](LoginAPI.md#LoginAPI_generateTokenViaTotpAndPin) | **POST** /v2/totp-login/authorization/token | Generate token using TOTP and PIN
[**LoginAPI_initTokenRequestForIndieUser**](LoginAPI.md#LoginAPI_initTokenRequestForIndieUser) | **POST** /v3/login/auth/token/request/{client_id} | Init token API
[**LoginAPI_logout**](LoginAPI.md#LoginAPI_logout) | **DELETE** /v2/logout | Logout
[**LoginAPI_token**](LoginAPI.md#LoginAPI_token) | **POST** /v2/login/authorization/token | Get token API


# **LoginAPI_authorize**
```c
// Authorize API
//
// This provides details on the login endpoint.
//
void LoginAPI_authorize(apiClient_t *apiClient, char *client_id, char *redirect_uri, char *state, char *scope);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**client_id** | **char \*** |  | 
**redirect_uri** | **char \*** |  | 
**state** | **char \*** |  | [optional] 
**scope** | **char \*** |  | [optional] 

### Return type

void

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **LoginAPI_generateTokenViaTotpAndPin**
```c
// Generate token using TOTP and PIN
//
// This API generates an access token for an automation client using the app's API key together with the user's 6-digit PIN and 6-digit TOTP
//
token_response_t* LoginAPI_generateTokenViaTotpAndPin(apiClient_t *apiClient, char *x_api_key, totp_pin_token_request_t *totp_pin_token_request, char *x_user_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**x_api_key** | **char \*** | OAuth API key that identifies the app | 
**totp_pin_token_request** | **[totp_pin_token_request_t](totp_pin_token_request.md) \*** |  | 
**x_user_id** | **char \*** | User id to log in. Required for multi-client apps (6 alphanumeric characters); optional for individual apps, but must match the app&#39;s registered user when supplied | [optional] 

### Return type

[token_response_t](token_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **LoginAPI_initTokenRequestForIndieUser**
```c
// Init token API
//
// This API provides the initialize the generate token and it's expiry for an indie user
//
indie_user_init_token_response_t* LoginAPI_initTokenRequestForIndieUser(apiClient_t *apiClient, char *client_id, indie_user_token_request_t *indie_user_token_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**client_id** | **char \*** |  | 
**indie_user_token_request** | **[indie_user_token_request_t](indie_user_token_request.md) \*** |  | 

### Return type

[indie_user_init_token_response_t](indie_user_init_token_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **LoginAPI_logout**
```c
// Logout
//
// Logout
//
logout_response_t* LoginAPI_logout(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[logout_response_t](logout_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **LoginAPI_token**
```c
// Get token API
//
// This API provides the functionality to obtain opaque token from authorization_code exchange and also provides the user’s profile in the same response.
//
token_response_t* LoginAPI_token(apiClient_t *apiClient, char *code, char *client_id, char *client_secret, char *redirect_uri, char *grant_type, int *refresh_extended_token);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**code** | **char \*** |  | 
**client_id** | **char \*** | OAuth API key that is a public identifier for app | 
**client_secret** | **char \*** | OAuth client secret that is a private secret known only to app and authorization server | 
**redirect_uri** | **char \*** | Authorization server will redirect the user back to the application via redirect url | 
**grant_type** | **char \*** | Type of grant used to get an access token | 
**refresh_extended_token** | **int \*** | Whether to refresh (regenerate) the extended access token. Defaults to false when absent. Set to true to refresh; false or omit to reuse an existing extended token when available. | [optional] 

### Return type

[token_response_t](token_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/x-www-form-urlencoded
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

