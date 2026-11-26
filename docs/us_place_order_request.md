# us_place_order_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**quantity** | **double** | Shares, up to 9 decimals; fractions only on fractionable stocks | [optional] 
**amount** | **double** | USD to invest, up to 2 decimals | [optional] 
**price** | **double** | Limit price in USD; not allowed for a market order | [optional] 
**validity** | **upstox_client_us_place_order_request_VALIDITY_e** |  | 
**tag** | **char \*** | Free-form order tag, up to 40 characters | [optional] 
**instrument_key** | **char \*** | US instrument key | 
**transaction_type** | **upstox_client_us_place_order_request_TRANSACTIONTYPE_e** |  | 
**order_type** | **upstox_client_us_place_order_request_ORDERTYPE_e** |  | 

[Back to Model list] [Back to API list] [Back to README]


