# cash_flow_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Report type: consolidated or standalone | [optional] [readonly] 
**time_period** | **char \*** | Time period: yearly or quarterly | [optional] [readonly] 
**units_in** | **char \*** | Unit of monetary values | [optional] [readonly] 
**cash_flow** | [**list_t**](cash_flow_entry.md) \* | Cash flow entries grouped by type (Operating, Investing, Financing) | [optional] [readonly] 
**full_statement** | [**list_t**](financial_statement_entry.md) \* | List of financial statement cash flow items with historical values | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


