# us_funds_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**cash** | **double** | Cash in the wallet | [optional] [readonly] 
**available_to_trade** | **double** | Buying power; includes unsettled instant-funding credit | [optional] [readonly] 
**available_to_withdraw** | **double** | Settled cash that can be withdrawn | [optional] [readonly] 
**unsettled_cash** | **double** | Cash not yet settled: cash minus available_to_withdraw | [optional] [readonly] 
**exchange_rate** | **double** | Indicative USD to INR rate, for display only | [optional] [readonly] 
**available_to_trade_inr** | **double** | available_to_trade x exchange_rate | [optional] [readonly] 
**available_to_withdraw_inr** | **double** | available_to_withdraw x exchange_rate | [optional] [readonly] 
**cash_inr** | **double** | cash x exchange_rate | [optional] [readonly] 
**unsettled_cash_inr** | **double** | unsettled_cash x exchange_rate | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


