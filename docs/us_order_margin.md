# us_order_margin_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**brokerage** | **double** | Upstox brokerage | [optional] [readonly] 
**gst** | **double** | GST on brokerage | [optional] [readonly] 
**instrument_key** | **char \*** |  | [optional] [readonly] 
**transaction_type** | **char \*** |  | [optional] [readonly] 
**trade_value** | **double** | quantity x limit price, or quantity x last traded price for a market order | [optional] [readonly] 
**required_margin** | **double** | Buy: trade value + brokerage + GST. Sell: 0 | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


