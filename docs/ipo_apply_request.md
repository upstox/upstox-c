# ipo_apply_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | IPO id (slug) to apply for, as returned in &#x60;id&#x60; by the IPO listing and details APIs | 
**upi** | **char \*** | UPI id used to block the application amount | 
**category** | **upstox_client_ipo_apply_request_CATEGORY_e** | Investor category to apply under. Must be one the issue accepts — see &#x60;investors[].category&#x60; in the IPO details API | 
**bids** | [**list_t**](ipo_bid_request.md) \* | List of bids for the application (1 to 3 bids) | 

[Back to Model list] [Back to API list] [Back to README]


