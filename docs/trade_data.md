# trade_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exchange** | **upstox_client_trade_data_EXCHANGE_e** | Exchange to which the order is associated | [optional] [readonly] 
**product** | **upstox_client_trade_data_PRODUCT_e** | Shows if the order was either Intraday, Delivery, CO or OCO | [optional] [readonly] 
**tradingsymbol** | **char \*** | Shows the trading symbol which could be a combination of symbol name, instrument, expiry date etc | [optional] [readonly] 
**trading_symbol** | **char \*** | Shows the trading symbol which could be a combination of symbol name, instrument, expiry date etc | [optional] [readonly] 
**instrument_token** | **char \*** | Identifier issued by Upstox used for subscribing to live market quotes | [optional] [readonly] 
**order_type** | **upstox_client_trade_data_ORDERTYPE_e** | Type of order. It can be one of the following MARKET refers to market order&lt;br&gt;LIMIT refers to Limit Order&lt;br&gt;SL refers to Stop Loss Limit&lt;br&gt;SL-M refers to Stop loss market | [optional] [readonly] 
**transaction_type** | **upstox_client_trade_data_TRANSACTIONTYPE_e** | Indicates whether the order was a buy or sell order | [optional] [readonly] 
**quantity** | **int** | The total quantity traded from this particular order | [optional] [readonly] 
**exchange_order_id** | **char \*** | Unique order ID assigned by the exchange for the order placed | [optional] [readonly] 
**order_id** | **char \*** | Unique order ID assigned internally for the order placed | [optional] [readonly] 
**exchange_timestamp** | **char \*** | User readable time at when the trade occurred | [optional] [readonly] 
**average_price** | **double** | Price at which the traded quantity is traded | [optional] [readonly] 
**trade_id** | **char \*** | Trade ID generated from exchange towards traded transaction | [optional] [readonly] 
**order_ref_id** | **char \*** | The order reference ID for which the order must be modified | [optional] [readonly] 
**order_timestamp** | **char \*** | User readable timestamp at which the order was placed | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


