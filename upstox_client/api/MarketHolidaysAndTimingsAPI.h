#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/analytics_response.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_exchange_timing_response.h"
#include "../models/get_holiday_response.h"
#include "../models/get_market_status_response.h"


// Get Change in OI Data
//
// Fetches change in OI data for the given instrument key, expiry, date and interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getChangeOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *interval);


// Get DII Data
//
// Fetches DII activity data for the given interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getDiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from);


// Get Exchange Timings on particular date
//
// This API provides the functionality to retrieve the exchange timings on particular date
//
get_exchange_timing_response_t*
MarketHolidaysAndTimingsAPI_getExchangeTimings(apiClient_t *apiClient, char *date);


// Get FII Data
//
// Fetches FII activity data for the given data type and interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getFiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from);


// Get Holiday on particular date
//
// This API provides the functionality to retrieve the holiday on particular date
//
get_holiday_response_t*
MarketHolidaysAndTimingsAPI_getHoliday(apiClient_t *apiClient, char *date);


// Get Holiday list of current year
//
// This API provides the functionality to retrieve the holiday list of current year
//
get_holiday_response_t*
MarketHolidaysAndTimingsAPI_getHolidays(apiClient_t *apiClient);


// Get Market status for particular exchange
//
// This API provides the functionality to retrieve the market status for particular exchange
//
get_market_status_response_t*
MarketHolidaysAndTimingsAPI_getMarketStatus(apiClient_t *apiClient, char *exchange);


// Get Max Pain Data
//
// Fetches Max Pain data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getMaxPainData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval);


// Get OI Data
//
// Fetches OI data for the given instrument key, expiry and date.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date);


// Get PCR Data
//
// Fetches PCR (Put-Call Ratio) data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getPcrData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval);


// Get Smartlist Futures
//
// Fetches the smartlist of futures for the given asset type and category.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistFutures(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size);


// Get Smartlist MTF
//
// Fetches the smartlist of MTF (Margin Trade Funding) stocks. Prices are enriched with live LTP data.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistMtf(apiClient_t *apiClient, int *page_number, int *page_size);


// Get Smartlist Options
//
// Fetches the smartlist of options for the given asset type and category.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistOptions(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size);


