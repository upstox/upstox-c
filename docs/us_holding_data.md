# us_holding_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exchange** | **char \*** |  | [optional] [readonly] 
**quantity** | **double** | Shares held | [optional] [readonly] 
**pnl** | **double** | Unrealised P&amp;L in USD: current_value minus invested_value, negated for a short | [optional] [readonly] 
**instrument_key** | **char \*** | US instrument key | [optional] [readonly] 
**trading_symbol** | **char \*** |  | [optional] [readonly] 
**company_name** | **char \*** |  | [optional] [readonly] 
**average_price** | **double** | Average buy price in USD | [optional] [readonly] 
**available_quantity** | **double** | Shares free to sell | [optional] [readonly] 
**transaction_type** | **char \*** | Position direction as sent by the holdings service: long or short | [optional] [readonly] 
**invested_value** | **double** | quantity x average_price, in USD | [optional] [readonly] 
**last_price** | **double** | Last traded price in USD; null when market data is unavailable | [optional] [readonly] 
**previous_close** | **double** | Previous close in USD; null when market data is unavailable | [optional] [readonly] 
**current_value** | **double** | quantity x last_price, in USD | [optional] [readonly] 
**day_pnl** | **double** | Today&#39;s P&amp;L in USD: quantity x (last_price minus previous_close), negated for a short | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


