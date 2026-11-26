# market_quote_symbol_v3_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ohlc** | [**ohlc_v3_t**](ohlc_v3.md) \* |  | [optional] 
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
**oi_day_high** | **double** | The highest open interest recorded on symbol during the day | [optional] [readonly] 
**oi_day_low** | **double** | The lowest open interest recorded on symbol during the day | [optional] [readonly] 
**prev_close_price** | **double** | The close price of the symbol from the previous session of trading | [optional] [readonly] 
**year_high** | **double** | The highest price of the symbol over the trailing year | [optional] [readonly] 
**year_low** | **double** | The lowest price of the symbol over the trailing year | [optional] [readonly] 
**previous_oi** | **double** | The open interest of the symbol from the previous session (only F&amp;O) | [optional] [readonly] 
**indicative_equilibrium_price** | **double** | The indicative equilibrium price discovered during the call auction session | [optional] [readonly] 
**reference_price** | **double** | The reference price against which the call auction price band is applied | [optional] [readonly] 
**indicative_equilibrium_quantity** | **long** | The indicative equilibrium quantity matched at the indicative equilibrium price | [optional] [readonly] 
**indicative_imbalance_quantity_total** | **long** | The total indicative imbalance quantity in the call auction order book | [optional] [readonly] 
**indicative_imbalance_quantity_market** | **long** | The market-order component of the indicative imbalance quantity in the call auction order book | [optional] [readonly] 
**cas_eligible** | **int** | Whether the symbol is eligible for the call auction session | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


