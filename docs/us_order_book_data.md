# us_order_book_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** |  | [optional] [readonly] 
**exchange** | **char \*** |  | [optional] [readonly] 
**validity** | **char \*** |  | [optional] [readonly] 
**price** | **double** | Limit price in USD | [optional] [readonly] 
**quantity** | **double** | Ordered shares | [optional] [readonly] 
**amount** | **double** | USD amount for an amount order | [optional] [readonly] 
**status** | **upstox_client_us_order_book_data_STATUS_e** | Order status, normalised from the US order book; an open order is scheduled while the market is closed | [optional] [readonly] 
**fractionable** | **int** | Whether the stock allows fractional quantities; null when the stock is not in the US instrument list | [optional] [readonly] 
**variety** | **char \*** |  | [optional] [readonly] 
**tag** | **char \*** |  | [optional] [readonly] 
**order_id** | **char \*** | Order id | [optional] [readonly] 
**instrument_key** | **char \*** | US instrument key | [optional] [readonly] 
**trading_symbol** | **char \*** |  | [optional] [readonly] 
**order_type** | **upstox_client_us_order_book_data_ORDERTYPE_e** |  | [optional] [readonly] 
**transaction_type** | **char \*** |  | [optional] [readonly] 
**average_price** | **double** | Average traded price in USD | [optional] [readonly] 
**filled_quantity** | **double** | Traded shares | [optional] [readonly] 
**pending_quantity** | **double** | Shares still to be traded | [optional] [readonly] 
**status_message** | **char \*** |  | [optional] [readonly] 
**status_message_raw** | **char \*** |  | [optional] [readonly] 
**order_timestamp** | **char \*** | When the order was placed, IST, yyyy-MM-dd HH:mm:ss | [optional] [readonly] 
**exchange_timestamp** | **char \*** | When the order was last updated, IST, yyyy-MM-dd HH:mm:ss | [optional] [readonly] 
**is_amo** | **int** |  | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


