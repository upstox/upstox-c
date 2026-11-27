# gtt_modify_order_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **upstox_client_gtt_modify_order_request_TYPE_e** | Type of GTT order. It can be one of the following: SINGLE refers to a single-leg GTT order MULTIPLE refers to a multi-leg GTT order | 
**quantity** | **int** | Quantity with which the order is to be placed | 
**rules** | [**list_t**](gtt_rule.md) \* | List of rules defining the conditions for each leg in the GTT order | 
**gtt_order_id** | **char \*** | Unique identifier of the GTT order to be modified | 

[Back to Model list] [Back to API list] [Back to README]


