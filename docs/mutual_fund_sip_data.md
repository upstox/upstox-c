# mutual_fund_sip_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**fund** | **char \*** | Display name of the fund. | [optional] 
**status** | **char \*** | ACTIVE, PAUSED, or CANCELLED. | [optional] 
**created** | **char \*** | Timestamp when the SIP was registered. | [optional] 
**frequency** | **char \*** | Frequency (e.g. monthly, weekly). | [optional] 
**instalments** | **long** | Total number of instalments when applicable; -1 if open-ended. | [optional] 
**sip_id** | **char \*** | Unique SIP identifier. | [optional] 
**sip_reg_number** | **char \*** | SIP registration number when available. | [optional] 
**instrument_key** | **char \*** | ISIN of the fund, when available. | [optional] 
**dividend_type** | **char \*** | Dividend option when available (e.g. growth, idcw). | [optional] 
**transaction_type** | **char \*** | BUY or SELL. | [optional] 
**next_instalment** | **char \*** | Next instalment date. | [optional] 
**instalment_amount** | **double** | Amount per instalment. | [optional] 
**last_instalment** | **char \*** | Last triggered instalment timestamp. | [optional] 
**pending_instalments** | **long** | Pending instalments when applicable. | [optional] 
**instalment_day** | **long** | Day of month for monthly SIPs when applicable. | [optional] 
**completed_instalments** | **long** | Completed instalment count when available. | [optional] 
**trigger_price** | **double** | Trigger price when applicable. | [optional] 
**sip_type** | **char \*** | SIP channel/type (e.g. sip, amc_sip). | [optional] 

[Back to Model list] [Back to API list] [Back to README]


