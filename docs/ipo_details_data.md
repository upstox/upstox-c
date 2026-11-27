# ipo_details_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | IPO id (slug). Pass this as the id to the apply API | [optional] 
**symbol** | **char \*** | Trading symbol of the issuer | [optional] 
**name** | **char \*** | Name of the issuer | [optional] 
**status** | **upstox_client_ipo_details_data_STATUS_e** | Current stage of the IPO | [optional] 
**isin** | **char \*** | ISIN of the issue | [optional] 
**issue_type** | **upstox_client_ipo_details_data_ISSUETYPE_e** | Issue type of the IPO. &#x60;regular&#x60; is a mainboard issue | [optional] 
**issue_size** | **double** | Total issue size in crores | [optional] 
**industry** | **char \*** | Industry the issuer operates in | [optional] 
**minimum_price** | **double** | Lower end of the price band, per share | [optional] 
**maximum_price** | **double** | Upper end of the price band, per share | [optional] 
**bidding_start_date** | **char \*** | Date bidding opens, in yyyy-MM-dd | [optional] 
**bidding_end_date** | **char \*** | Date bidding closes, in yyyy-MM-dd | [optional] 
**daily_start_time** | **char \*** | Time bidding opens each day, in HH:mm IST | [optional] 
**daily_end_time** | **char \*** | Time bidding closes each day, in HH:mm IST | [optional] 
**face_value** | **double** | Face value of one share | [optional] 
**tick_size** | **double** | Minimum price increment for a bid | [optional] 
**lot_size** | **int** | Number of shares in one lot | [optional] 
**minimum_quantity** | **int** | Smallest quantity that can be bid for; bids must be in multiples of the lot size | [optional] 
**cut_off_price** | **double** | Cut-off price for retail applications | [optional] 
**listing_price** | **double** | Price the share listed at; null until listing | [optional] 
**listing_exchange** | **char \*** | Exchange(s) the issue lists on. Comma-separated when the issue lists on more than one | [optional] 
**rhp_url** | **char \*** | Link to the Red Herring Prospectus | [optional] 
**drhp_url** | **char \*** | Link to the Draft Red Herring Prospectus | [optional] 
**timeline** | [**ipo_timeline_t**](ipo_timeline.md) \* | Key dates for the issue, from pre-apply through listing | [optional] 
**registrar_info** | [**ipo_registrar_info_t**](ipo_registrar_info.md) \* | Registrar handling the issue | [optional] 
**total_subscription** | **char \*** | Overall subscription so far; null until the issue opens | [optional] 
**investors** | [**list_t**](ipo_investor_type.md) \* | Investor categories the issue accepts | [optional] 

[Back to Model list] [Back to API list] [Back to README]


