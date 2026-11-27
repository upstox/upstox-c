# ipo_order_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Reference id of the IPO the application was placed against | [optional] 
**symbol** | **char \*** | Trading symbol of the issuer | [optional] 
**exchange** | **char \*** | Exchange the application was submitted to. Casing follows the exchange feed and may vary | [optional] 
**request_id** | **char \*** | Id of the request that created the application | [optional] 
**order_id** | **char \*** | Application id. Pass this as order_id to the get-order and cancel-order APIs | [optional] 
**status** | **char \*** | Lifecycle stage of the application. Known values: awaiting_mandate, ipo_allotted, ipo_not_allotted, application_deleted | [optional] 
**order_status** | **char \*** | Outcome of the application. Known values: success, allotted, not_allotted | [optional] 
**payment_status** | **char \*** | State of the UPI mandate backing the application. Known values: pending, mandate_accepted | [optional] 
**category** | **char \*** | Investor category the application was placed under. IND (individual) and HNI can be applied for; EMP appears on employee-quota applications | [optional] 
**issue_type** | **upstox_client_ipo_order_data_ISSUETYPE_e** | Issue type of the IPO. &#x60;regular&#x60; is a mainboard issue | [optional] 
**reason** | **char \*** | Free-text reason from the exchange or registrar explaining the current status | [optional] 
**upi** | **char \*** | UPI id the mandate was raised against | [optional] 
**upi_amount_blocked** | **char \*** | Amount blocked in the applicant&#39;s bank account for this application, as a decimal string. Absent until the mandate is accepted | [optional] 
**nse_submitted_date** | **char \*** | When the application was submitted to NSE, in yyyy-MM-dd&#39;T&#39;HH:mm:ss; null if not submitted there | [optional] 
**bse_submitted_date** | **char \*** | When the application was submitted to BSE, in yyyy-MM-dd&#39;T&#39;HH:mm:ss; null if not submitted there | [optional] 
**mandate_approved_date** | **char \*** | When the UPI mandate was approved; null until approved | [optional] 
**rejection_date** | **char \*** | When the application was rejected; null unless rejected | [optional] 
**mandate_rejection_date** | **char \*** | When the UPI mandate was rejected; null unless rejected | [optional] 
**cancel_requested_date** | **char \*** | When cancellation was requested; null unless a cancellation was raised | [optional] 
**cancel_accepted_date** | **char \*** | When cancellation was accepted; null unless the cancellation completed | [optional] 
**units_allotted** | **int** | Shares allotted. 0 until allotment completes, and on applications that were not allotted | [optional] 
**bids** | [**list_t**](ipo_order_bid.md) \* | Bids placed in this application | [optional] 
**created_at** | **char \*** | When the application was created, in yyyy-MM-dd&#39;T&#39;HH:mm:ss | [optional] 
**last_updated_at** | **char \*** | When the application was last updated, in yyyy-MM-dd&#39;T&#39;HH:mm:ss | [optional] 

[Back to Model list] [Back to API list] [Back to README]


