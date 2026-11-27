# order_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exchange** | **upstox_client_order_data_EXCHANGE_e** | Exchange to which the order is associated | [optional] [readonly] 
**price** | **double** | Price at which the order was placed | [optional] [readonly] 
**product** | **upstox_client_order_data_PRODUCT_e** | Shows if the order was either Intraday, Delivery, CoverOrder or OneCancelsOther | [optional] [readonly] 
**quantity** | **int** | Quantity with which the order was placed | [optional] [readonly] 
**status** | **char \*** | Indicates the current status of the order. Valid order status’ are outlined in the table below | [optional] [readonly] 
**tag** | **char \*** | Tag to uniquely identify an order | [optional] [readonly] 
**validity** | **upstox_client_order_data_VALIDITY_e** | Order validity (DAY- Day and IOC- Immediate or Cancel (IOC) order) | [optional] [readonly] 
**average_price** | **double** | Average price at which the qty got traded | [optional] [readonly] 
**disclosed_quantity** | **int** | The quantity that should be disclosed in the market depth | [optional] [readonly] 
**exchange_order_id** | **char \*** | Unique order ID assigned by the exchange for the order placed | [optional] [readonly] 
**exchange_timestamp** | **char \*** | User readable time at which the order was placed or updated | [optional] [readonly] 
**instrument_token** | **char \*** | Identifier issued by Upstox used for subscribing to live market quotes | [optional] [readonly] 
**is_amo** | **int** | Signifies if the order is an After Market Order | [optional] [readonly] 
**status_message** | **char \*** | Indicates the reason when any order is rejected, not modified or cancelled | [optional] [readonly] 
**order_id** | **char \*** | Unique order ID assigned internally for the order placed | [optional] [readonly] 
**order_request_id** | **char \*** | Apart from 1st order it shows the count of how many requests were sent | [optional] [readonly] 
**order_type** | **upstox_client_order_data_ORDERTYPE_e** | Type of order. It can be one of the following MARKET refers to market order&lt;br&gt;LIMIT refers to Limit Order&lt;br&gt;SL refers to Stop Loss Limit&lt;br&gt;SL-M refers to Stop loss market | [optional] [readonly] 
**parent_order_id** | **char \*** | In case the order is part of the second or third leg of a CO or OCO, the parent order ID is indicated here | [optional] [readonly] 
**tradingsymbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**trading_symbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**order_timestamp** | **char \*** | User readable timestamp at which the order was placed | [optional] [readonly] 
**filled_quantity** | **int** | The total quantity traded from this particular order | [optional] [readonly] 
**transaction_type** | **upstox_client_order_data_TRANSACTIONTYPE_e** | Indicates whether the order was a buy or sell order | [optional] [readonly] 
**trigger_price** | **double** | If the order was a stop loss order then the trigger price set is mentioned here | [optional] [readonly] 
**placed_by** | **char \*** | Uniquely identifies the user | [optional] [readonly] 
**variety** | **char \*** | Order complexity | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


