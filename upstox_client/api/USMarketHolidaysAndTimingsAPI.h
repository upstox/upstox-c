#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_market_status_response.h"
#include "../models/get_us_exchange_timing_response.h"
#include "../models/get_us_holiday_response.h"


// Get US market timings on a date
//
// Returns the US regular and overnight session times on the date, or an empty list when closed.
//
get_us_exchange_timing_response_t*
USMarketHolidaysAndTimingsAPI_getUsExchangeTimings(apiClient_t *apiClient, char *date);


// Get US market holiday on a date
//
// Returns the US market holiday on the date, or an empty list.
//
get_us_holiday_response_t*
USMarketHolidaysAndTimingsAPI_getUsHoliday(apiClient_t *apiClient, char *date);


// Get US market holidays
//
// Returns the US market holidays of the current year.
//
get_us_holiday_response_t*
USMarketHolidaysAndTimingsAPI_getUsHolidays(apiClient_t *apiClient);


// Get US market status
//
// Returns the live status of the US market.
//
get_market_status_response_t*
USMarketHolidaysAndTimingsAPI_getUsMarketStatus(apiClient_t *apiClient);


