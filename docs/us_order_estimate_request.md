# us_order_estimate_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**quantity** | **double** | Shares, up to 9 decimals; fractions only on fractionable stocks | 
**price** | **double** | Limit price in USD; required for a limit order. Optional for a market order, which is estimated at the last traded price and falls back to this price | [optional] 
**instrument_key** | **char \*** | US instrument key | 
**transaction_type** | **upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e** |  | 
**order_type** | **upstox_client_us_order_estimate_request_ORDERTYPE_e** |  | 

[Back to Model list] [Back to API list] [Back to README]


