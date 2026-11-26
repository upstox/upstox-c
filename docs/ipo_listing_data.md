# ipo_listing_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | IPO id (slug). Pass this as the id to the IPO details and apply APIs | [optional] 
**symbol** | **char \*** | Trading symbol of the issuer | [optional] 
**name** | **char \*** | Name of the issuer | [optional] 
**status** | **upstox_client_ipo_listing_data_STATUS_e** | Current stage of the IPO | [optional] 
**isin** | **char \*** | ISIN of the issue | [optional] 
**issue_type** | **upstox_client_ipo_listing_data_ISSUETYPE_e** | Issue type of the IPO. &#x60;regular&#x60; is a mainboard issue | [optional] 
**issue_size** | **double** | Total issue size in crores | [optional] 
**industry** | **char \*** | Industry the issuer operates in | [optional] 
**minimum_price** | **double** | Lower end of the price band, per share | [optional] 
**maximum_price** | **double** | Upper end of the price band, per share | [optional] 
**bidding_start_date** | **char \*** | Date bidding opens, in yyyy-MM-dd | [optional] 
**bidding_end_date** | **char \*** | Date bidding closes, in yyyy-MM-dd | [optional] 
**total_subscription** | **char \*** | Overall subscription so far; null until the issue opens | [optional] 
**investors** | [**list_t**](ipo_investor_type.md) \* | Investor categories the issue accepts. Empty when the listing data carries none — the IPO details API is the authoritative source | [optional] 

[Back to Model list] [Back to API list] [Back to README]


