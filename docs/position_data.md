# position_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exchange** | **upstox_client_position_data_EXCHANGE_e** | Exchange to which the order is associated | [optional] [readonly] 
**multiplier** | **double** | The quantity/lot size multiplier used for calculating P&amp;Ls | [optional] [readonly] 
**value** | **double** | Net value of the position | [optional] [readonly] 
**pnl** | **double** | Profit and loss - net returns on the position | [optional] [readonly] 
**product** | **char \*** | Shows if the order was either Intraday, Delivery, CO or OCO | [optional] [readonly] 
**instrument_token** | **char \*** | Key issued by Upstox for the instrument | [optional] [readonly] 
**average_price** | **double** | Average price at which the net position quantity was acquired | [optional] [readonly] 
**buy_value** | **double** | Net value of the bought quantities | [optional] [readonly] 
**overnight_quantity** | **int** | Quantity held previously and carried forward over night | [optional] [readonly] 
**day_buy_value** | **double** | Amount at which the quantity is bought during the day | [optional] [readonly] 
**day_buy_price** | **double** | Average price at which the day qty was bought. Default is empty string | [optional] [readonly] 
**overnight_buy_amount** | **double** | Amount at which the quantity was bought in the previous session | [optional] [readonly] 
**overnight_buy_quantity** | **int** | Quantity bought in the previous session | [optional] [readonly] 
**day_buy_quantity** | **int** | Quantity bought during the day | [optional] [readonly] 
**day_sell_value** | **double** | Amount at which the quantity is sold during the day | [optional] [readonly] 
**day_sell_price** | **double** | Average price at which the day quantity was sold | [optional] [readonly] 
**overnight_sell_amount** | **double** | Amount at which the quantity was sold in the previous session | [optional] [readonly] 
**overnight_sell_quantity** | **int** | Quantity sold short in the previous session | [optional] [readonly] 
**day_sell_quantity** | **int** | Quantity sold during the day | [optional] [readonly] 
**quantity** | **int** | Quantity left after nullifying Day and CF buy quantity towards Day and CF sell quantity | [optional] [readonly] 
**last_price** | **double** | Last traded market price of the instrument | [optional] [readonly] 
**unrealised** | **double** | Day PnL generated against open positions | [optional] [readonly] 
**realised** | **double** | Day PnL generated against closed positions | [optional] [readonly] 
**sell_value** | **double** | Net value of the sold quantities | [optional] [readonly] 
**tradingsymbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**trading_symbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**close_price** | **double** | Closing price of the instrument from the last trading day | [optional] [readonly] 
**buy_price** | **double** | Average price at which quantities were bought | [optional] [readonly] 
**sell_price** | **double** | Average price at which quantities were sold | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


