# holdings_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**isin** | **char \*** | The standard ISIN representing stocks listed on multiple exchanges | [optional] [readonly] 
**cnc_used_quantity** | **int** | Quantity either blocked towards open or completed order | [optional] [readonly] 
**collateral_type** | **char \*** | Category of collateral assigned by RMS | [optional] [readonly] 
**company_name** | **char \*** | Name of the company | [optional] [readonly] 
**haircut** | **double** | This is the haircut percentage applied from RMS (applicable incase of collateral) | [optional] [readonly] 
**product** | **char \*** | Shows if the order was either Intraday, Delivery, CO or OCO | [optional] [readonly] 
**quantity** | **int** | The total holding qty | [optional] [readonly] 
**tradingsymbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**last_price** | **double** | The last traded price of the instrument | [optional] [readonly] 
**close_price** | **double** | Closing price of the instrument from the last trading day | [optional] [readonly] 
**pnl** | **double** | Profit and Loss | [optional] [readonly] 
**day_change** | **double** | Day&#39;s change in absolute value for the stock | [optional] [readonly] 
**day_change_percentage** | **double** | Day&#39;s change in percentage for the stock | [optional] [readonly] 
**instrument_token** | **char \*** | Key issued by Upstox for the instrument | [optional] [readonly] 
**average_price** | **double** | Average price at which the net holding quantity was acquired | [optional] [readonly] 
**collateral_quantity** | **int** | Quantity marked as collateral by RMS on users request | [optional] [readonly] 
**collateral_update_quantity** | **int** |  | [optional] [readonly] 
**trading_symbol** | **char \*** | Shows the trading symbol of the instrument | [optional] [readonly] 
**t1_quantity** | **int** | Quantity on T+1 day after order execution | [optional] [readonly] 
**exchange** | **upstox_client_holdings_data_EXCHANGE_e** | Exchange of the trading symbol | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


