# user_fund_margin_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**used_margin** | **double** | Positive values denote the amount blocked into an Open order or position.  Negative value denotes the amount being released. | [optional] [readonly] 
**payin_amount** | **double** | Instant payin will reflect here | [optional] [readonly] 
**span_margin** | **double** | Amount blocked on futures and options towards SPAN | [optional] [readonly] 
**adhoc_margin** | **double** | Payin amount credited through a manual process | [optional] [readonly] 
**notional_cash** | **double** | The amount maintained for withdrawal | [optional] [readonly] 
**available_margin** | **double** | Total margin available for trading | [optional] [readonly] 
**exposure_margin** | **double** | Amount blocked on futures and options towards Exposure | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


