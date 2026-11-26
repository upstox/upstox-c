# us_order_estimate_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**brokerage** | **double** | Upstox brokerage | [optional] [readonly] 
**gst** | **double** | GST on brokerage | [optional] [readonly] 
**trade_value** | **double** | quantity x limit price, or quantity x last traded price for a market order (the request price when there is no last traded price) | [optional] [readonly] 
**regulatory_fee** | **double** | Regulatory fee as charged by the order service | [optional] [readonly] 
**taf_fee** | **double** | FINRA trading activity fee | [optional] [readonly] 
**cat_fee** | **double** | Consolidated audit trail fee | [optional] [readonly] 
**total_charges** | **double** | Sum of the charges above | [optional] [readonly] 
**estimated_total** | **double** | Buy: trade value plus charges. Sell: trade value minus charges. Null when the estimate carries no charges | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


