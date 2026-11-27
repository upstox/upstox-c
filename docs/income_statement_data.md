# income_statement_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Report type: consolidated or standalone | [optional] [readonly] 
**time_period** | **char \*** | Time period: yearly or quarterly | [optional] [readonly] 
**units_in** | **char \*** | Unit of monetary values | [optional] [readonly] 
**income_statement** | [**list_t**](income_statement_entry.md) \* | Income statement entries grouped by type (Revenue, Operating profit, Net profit) | [optional] [readonly] 
**full_statement** | [**list_t**](financial_statement_entry.md) \* | List of financial statement income statement items with historical values | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


