# multi_order_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**quantity** | **int** | Quantity with which the order is to be placed | 
**product** | **upstox_client_multi_order_request_PRODUCT_e** | Signifies if the order was either Intraday, Delivery, CO or OCO | 
**validity** | **upstox_client_multi_order_request_VALIDITY_e** | It can be one of the following - DAY(default), IOC | 
**price** | **double** | Price at which the order will be placed | 
**tag** | **char \*** |  | [optional] 
**slice** | **int** | To divide the order line based on predefined exchange definitions | 
**instrument_token** | **char \*** | Key of the instrument | 
**order_type** | **upstox_client_multi_order_request_ORDERTYPE_e** | Type of order. It can be one of the following MARKET refers to market order LIMIT refers to Limit Order SL refers to Stop Loss Limit SL-M refers to Stop Loss Market | 
**transaction_type** | **upstox_client_multi_order_request_TRANSACTIONTYPE_e** | Indicates whether its a buy or sell order | 
**disclosed_quantity** | **int** | The quantity that should be disclosed in the market depth | 
**trigger_price** | **double** | If the order is a stop loss order then the trigger price to be set is mentioned here | 
**is_amo** | **int** | Signifies if the order is an After Market Order | 
**correlation_id** | **char \*** | A unique identifier for tracking individual orders within the batch | 
**market_protection** | **double** | Optional parameter defining the market protection percentage for the multi order | [optional] 

[Back to Model list] [Back to API list] [Back to README]


