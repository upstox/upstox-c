# market_quote_symbol_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ohlc** | [**ohlc_t**](ohlc.md) \* |  | [optional] 
**depth** | [**depth_map_t**](depth_map.md) \* |  | [optional] 
**timestamp** | **char \*** | Time in milliseconds at which the feeds was updated | [optional] [readonly] 
**instrument_token** | **char \*** | Key issued by Upstox for the instrument | [optional] [readonly] 
**symbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**last_price** | **double** | The last traded price of symbol | [optional] [readonly] 
**volume** | **long** | The volume traded today on symbol | [optional] [readonly] 
**average_price** | **double** | Average price | [optional] [readonly] 
**oi** | **double** | Total number of outstanding contracts held by market participants exchange-wide (only F&amp;O) | [optional] [readonly] 
**net_change** | **double** | The absolute change from yesterday&#39;s close to last traded price | [optional] [readonly] 
**total_buy_quantity** | **double** | The total number of bid quantity available for trading | [optional] [readonly] 
**total_sell_quantity** | **double** | The total number of ask quantity available for trading | [optional] [readonly] 
**lower_circuit_limit** | **double** | The lower circuit of symbol | [optional] [readonly] 
**upper_circuit_limit** | **double** | The upper circuit of symbol | [optional] [readonly] 
**last_trade_time** | **char \*** | Time in milliseconds at which last trade happened | [optional] [readonly] 
**oi_day_high** | **double** |  | [optional] [readonly] 
**oi_day_low** | **double** |  | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


