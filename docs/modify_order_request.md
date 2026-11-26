# modify_order_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**quantity** | **int** | Quantity with which the order was placed | [optional] 
**validity** | **upstox_client_modify_order_request_VALIDITY_e** | Order validity (DAY- Day and IOC- Immediate or Cancel (IOC) order) | 
**price** | **double** | Price at which the order was placed | 
**order_id** | **char \*** | The order ID for which the order must be modified | 
**order_type** | **upstox_client_modify_order_request_ORDERTYPE_e** | Type of order. It can be one of the following MARKET refers to market order LIMILT refers to Limit Order SL refers to Stop Loss Limit SL-M refers to Stop Loss Market | 
**disclosed_quantity** | **int** | The quantity that should be disclosed in the market depth | [optional] 
**trigger_price** | **double** | If the order is a stop loss order then the trigger price to be set is mentioned here | 
**market_protection** | **double** | Optional market price protection percentage; -1 lets the exchange decide | [optional] 

[Back to Model list] [Back to API list] [Back to README]


