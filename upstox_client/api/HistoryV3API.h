#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_historical_candle_response.h"
#include "../models/get_intra_day_candle_response.h"


// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options
//
get_historical_candle_response_t*
HistoryV3API_getHistoricalCandleDataRange(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date, char *from_date);


// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options.
//
get_historical_candle_response_t*
HistoryV3API_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date);


// Intra day candle data
//
// Get OHLC values for all instruments for the present trading day
//
get_intra_day_candle_response_t*
HistoryV3API_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval);


