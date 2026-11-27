#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_expired_futures_contract_response.h"
#include "../models/get_expiries_response.h"
#include "../models/get_historical_candle_response.h"
#include "../models/get_option_contract_response.h"


// Expired instruments - Get future contracts
//
// This API provides the functionality to retrieve expired future contracts for a given instrument key and expiry date.
//
get_expired_futures_contract_response_t*
ExpiredInstrumentAPI_getExpiredFutureContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);


// Expired Historical candle data
//
// Get Expired OHLC values for all instruments across various timeframes. Expired Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
ExpiredInstrumentAPI_getExpiredHistoricalCandleData(apiClient_t *apiClient, char *expired_instrument_key, char *interval, char *to_date, char *from_date);


// Get expired option contracts
//
// This API provides the functionality to retrieve the expired option contracts
//
get_option_contract_response_t*
ExpiredInstrumentAPI_getExpiredOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date);


// Expired instruments - Get expiries
//
// This API provides the functionality to retrieve expiry dates for a given instrument key.
//
get_expiries_response_t*
ExpiredInstrumentAPI_getExpiries(apiClient_t *apiClient, char *instrument_key);


