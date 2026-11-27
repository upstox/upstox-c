# token_response_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**email** | **char \*** | E-mail address of the user | [optional] [readonly] 
**exchanges** | **list_t \*** | Lists the exchanges to which the user has access | [optional] [readonly] 
**products** | **list_t \*** | Lists the products types to which the user has access | [optional] [readonly] 
**broker** | **char \*** | The broker ID | [optional] [readonly] 
**user_id** | **char \*** | Uniquely identifies the user | [optional] [readonly] 
**user_name** | **char \*** | Name of the user | [optional] [readonly] 
**order_types** | **list_t \*** | Order types enabled for the user | [optional] [readonly] 
**user_type** | **char \*** |   Identifies the user&#39;s registered role at the broker. This will be individual for all retail users | [optional] [readonly] 
**poa** | **int** |   To depict if the user has given power of attorney for transactions | [optional] [readonly] 
**ddpi** | **int** |   Indicates if DDPI is enabled for trading | [optional] [readonly] 
**is_active** | **int** |   Whether the status of account is active or not | [optional] [readonly] 
**access_token** | **char \*** | The authentication token that is to used with every subsequent API requests | [optional] [readonly] 
**extended_token** | **char \*** | An extended authentication token with a prolonged validity period, intended for specific API requests. Ensure you use this token only with the designated set of APIs. | [optional] [readonly] 
**expires_in** | **int** | The number of seconds until the access token expires | [optional] [readonly] 
**token_type** | **char \*** | The type of token | [optional] [readonly] 
**refresh_token** | **char \*** | The refresh token that can be used to refresh the access token | [optional] [readonly] 
**refresh_token_expires_in** | **int** | The number of seconds until the refresh token expires | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


