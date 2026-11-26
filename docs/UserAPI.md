# UserAPI

All URIs are relative to *https://api.upstox.com*

Method | HTTP request | Description
------------- | ------------- | -------------
[**UserAPI_cancelPayout**](UserAPI.md#UserAPI_cancelPayout) | **DELETE** /v2/user/payments/payout/{transaction_id} | 
[**UserAPI_getKillSwitch**](UserAPI.md#UserAPI_getKillSwitch) | **GET** /v2/user/kill-switch | Get kill switch status
[**UserAPI_getPayinHistory**](UserAPI.md#UserAPI_getPayinHistory) | **GET** /v2/user/payments/payin | 
[**UserAPI_getPayoutHistory**](UserAPI.md#UserAPI_getPayoutHistory) | **GET** /v2/user/payments/payout | 
[**UserAPI_getPayoutModes**](UserAPI.md#UserAPI_getPayoutModes) | **GET** /v2/user/payments/payout/modes | 
[**UserAPI_getProfile**](UserAPI.md#UserAPI_getProfile) | **GET** /v2/user/profile | Get profile
[**UserAPI_getUserFundMargin**](UserAPI.md#UserAPI_getUserFundMargin) | **GET** /v2/user/get-funds-and-margin | Get User Fund And Margin
[**UserAPI_getUserFundMarginV3**](UserAPI.md#UserAPI_getUserFundMarginV3) | **GET** /v3/user/get-funds-and-margin | Get User Fund And Margin
[**UserAPI_getUserIps**](UserAPI.md#UserAPI_getUserIps) | **GET** /v2/user/ip | 
[**UserAPI_initiatePayout**](UserAPI.md#UserAPI_initiatePayout) | **POST** /v2/user/payments/payout | 
[**UserAPI_modifyPayout**](UserAPI.md#UserAPI_modifyPayout) | **PUT** /v2/user/payments/payout/{transaction_id} | 
[**UserAPI_updateKillSwitch**](UserAPI.md#UserAPI_updateKillSwitch) | **POST** /v2/user/kill-switch | Update kill switch
[**UserAPI_updateUserIp**](UserAPI.md#UserAPI_updateUserIp) | **PUT** /v2/user/ip | 


# **UserAPI_cancelPayout**
```c
payout_details_response_t* UserAPI_cancelPayout(apiClient_t *apiClient, char *transaction_id);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**transaction_id** | **char \*** | Payout transaction id | 

### Return type

[payout_details_response_t](payout_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getKillSwitch**
```c
// Get kill switch status
//
// Returns the disable/enable status of all trading segments for the user.
//
kill_switch_response_t* UserAPI_getKillSwitch(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[kill_switch_response_t](kill_switch_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getPayinHistory**
```c
payment_history_response_t* UserAPI_getPayinHistory(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[payment_history_response_t](payment_history_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getPayoutHistory**
```c
payment_history_response_t* UserAPI_getPayoutHistory(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[payment_history_response_t](payment_history_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getPayoutModes**
```c
payout_modes_response_t* UserAPI_getPayoutModes(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[payout_modes_response_t](payout_modes_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getProfile**
```c
// Get profile
//
// This API allows to fetch the complete information of the user who is logged in including the products, order types and exchanges enabled for the user
//
get_profile_response_t* UserAPI_getProfile(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_profile_response_t](get_profile_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getUserFundMargin**
```c
// Get User Fund And Margin
//
// Shows the balance of the user in equity and commodity market.
//
get_user_fund_margin_response_t* UserAPI_getUserFundMargin(apiClient_t *apiClient, upstox_client_getUserFundMargin_segment_e segment);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**segment** | **upstox_client_getUserFundMargin_segment_e** |  | [optional] 

### Return type

[get_user_fund_margin_response_t](get_user_fund_margin_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getUserFundMarginV3**
```c
// Get User Fund And Margin
//
// Shows the detailed balance breakdown of the user including cash, pledged margin, available-to-trade, and unavailable-to-trade components.
//
get_user_fund_margin_v3_response_t* UserAPI_getUserFundMarginV3(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[get_user_fund_margin_v3_response_t](get_user_fund_margin_v3_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_getUserIps**
```c
user_ip_response_t* UserAPI_getUserIps(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[user_ip_response_t](user_ip_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_initiatePayout**
```c
payout_details_response_t* UserAPI_initiatePayout(apiClient_t *apiClient, initiate_payout_request_t *initiate_payout_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**initiate_payout_request** | **[initiate_payout_request_t](initiate_payout_request.md) \*** |  | 

### Return type

[payout_details_response_t](payout_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_modifyPayout**
```c
payout_details_response_t* UserAPI_modifyPayout(apiClient_t *apiClient, char *transaction_id, modify_payout_request_t *modify_payout_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**transaction_id** | **char \*** | Payout transaction id | 
**modify_payout_request** | **[modify_payout_request_t](modify_payout_request.md) \*** |  | 

### Return type

[payout_details_response_t](payout_details_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_updateKillSwitch**
```c
// Update kill switch
//
// Enable or disable specific trading segments.
//
kill_switch_response_t* UserAPI_updateKillSwitch(apiClient_t *apiClient, list_t *kill_switch_segment_update_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**kill_switch_segment_update_request** | **[list_t](kill_switch_segment_update_request.md) \*** |  | 

### Return type

[kill_switch_response_t](kill_switch_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json, */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

# **UserAPI_updateUserIp**
```c
user_ip_response_t* UserAPI_updateUserIp(apiClient_t *apiClient, update_user_ip_request_t *update_user_ip_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**update_user_ip_request** | **[update_user_ip_request_t](update_user_ip_request.md) \*** |  | 

### Return type

[user_ip_response_t](user_ip_response.md) *


### Authorization

OAUTH2

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: */*

[[Back to top]](#) [Back to API list] [Back to Model list] [Back to README]

