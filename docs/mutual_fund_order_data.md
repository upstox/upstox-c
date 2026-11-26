# mutual_fund_order_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | Current status of the order. | [optional] 
**folio** | **char \*** | Folio number, when allotted. | [optional] 
**fund** | **char \*** | Display name of the fund. | [optional] 
**amount** | **double** | Order amount. | [optional] 
**variety** | **char \*** | Order variety or channel-specific classification, if available. | [optional] 
**quantity** | **double** | Units allotted or sold. | [optional] 
**price** | **double** | Price or NAV used for the transaction, when available. | [optional] 
**order_id** | **char \*** | Unique order identifier. | [optional] 
**exchange_order_id** | **char \*** | Exchange-generated order id, if available. | [optional] 
**instrument_key** | **char \*** | ISIN of the fund, when available. | [optional] 
**status_message** | **char \*** | Human-readable status or rejection reason. | [optional] 
**order_timestamp** | **char \*** | Timestamp when the order was registered. | [optional] 
**exchange_timestamp** | **char \*** | Exchange date for the order, if available. | [optional] 
**settlement_id** | **char \*** | Exchange settlement id, if available. | [optional] 
**transaction_type** | **char \*** | BUY or SELL. | [optional] 
**purchase_type** | **char \*** | FRESH or ADDITIONAL for buys, when available. | [optional] 
**last_price** | **double** | Last known NAV. | [optional] 
**average_price** | **double** | Allotted or sold NAV. | [optional] 
**last_price_date** | **char \*** | Date for which last NAV is available. | [optional] 

[Back to Model list] [Back to API list] [Back to README]


