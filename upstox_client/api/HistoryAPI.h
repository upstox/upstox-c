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
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
HistoryAPI_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date);


// Historical candle data
//
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
HistoryAPI_getHistoricalCandleData1(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date, char *from_date);


// Intra day candle data
//
// Get OHLC values for all instruments for the present trading day
//
get_intra_day_candle_response_t*
HistoryAPI_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval);


