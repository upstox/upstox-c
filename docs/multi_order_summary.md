# multi_order_summary_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**total** | **int** | The total number of order lines present in the payload. | [optional] [readonly] 
**success** | **int** | The number of order lines that were successfully placed without any errors. | [optional] [readonly] 
**error** | **int** | The number of order lines that encountered errors during processing, despite their payloads being valid. | [optional] [readonly] 
**payload_error** | **int** | The number of order lines with payload errors, indicating formatting or data validity issues.&lt;br/&gt;&lt;br/&gt;&lt;b&gt;Note&lt;/b&gt;: Orders are processed only if the entire batch is free of payload_error, ensuring error-free transactions. | [optional] [readonly] 

[Back to Model list] [Back to API list] [Back to README]


