# balance_sheet_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Report type: consolidated or standalone | [optional] [readonly] 
**time_period** | **char \*** | Time period: yearly or quarterly | [optional] [readonly] 
**units_in** | **char \*** | Unit of monetary values | [optional] [readonly] 
**history** | [**list_t**](balance_sheet_history_item.md) \* | Historical balance sheet entries | [optional] [readonly] 
**full_statement** | [**list_t**](financial_statement_entry.md) \* | List of financial statement balance sheet items with historical values | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


