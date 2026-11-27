# gtt_place_order_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **upstox_client_gtt_place_order_request_TYPE_e** | Type of GTT order. It can be one of the following: SINGLE refers to a single-leg GTT order MULTIPLE refers to a multi-leg GTT order | 
**quantity** | **int** | Quantity with which the order is to be placed | 
**product** | **upstox_client_gtt_place_order_request_PRODUCT_e** | Signifies if the order was either Intraday, Delivery or MTF | 
**rules** | [**list_t**](gtt_rule.md) \* | List of rules defining the conditions for each leg in the GTT order | 
**instrument_token** | **char \*** | Key of the instrument | 
**transaction_type** | **upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e** | Indicates whether its a buy or sell order | 

[Back to Model list] [Back to API list] [Back to README]


