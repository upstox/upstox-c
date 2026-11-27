# us_margin_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**margins** | [**list_t**](us_order_margin.md) \* | One entry per order, in request order | [optional] [readonly] 
**shortfall** | **double** | required_margin minus available_to_invest, never below 0 | [optional] [readonly] 
**sufficient** | **int** | Whether available_to_invest covers required_margin | [optional] [readonly] 
**required_margin** | **double** | Sum of required margin across the orders | [optional] [readonly] 
**available_to_invest** | **double** | Buying power in the US wallet | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


