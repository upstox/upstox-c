#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_full_market_quote_response.h"
#include "../models/get_market_quote_last_traded_price_response.h"
#include "../models/get_market_quote_ohlc_response.h"


// Market quotes and instruments - Full market quotes
//
// This API provides the functionality to retrieve the full market quotes for one or more instruments.This API returns the complete market data snapshot of up to 500 instruments in one go.
//
get_full_market_quote_response_t*
MarketQuoteAPI_getFullMarketQuote(apiClient_t *apiClient, char *symbol, char *instrument_key);


// Market quotes and instruments - OHLC quotes
//
// This API provides the functionality to retrieve the OHLC quotes for one or more instruments.This API returns the OHLC snapshots of up to 1000 instruments in one go.
//
get_market_quote_ohlc_response_t*
MarketQuoteAPI_getMarketQuoteOHLC(apiClient_t *apiClient, char *interval, char *symbol, char *instrument_key);


// Market quotes and instruments - LTP quotes.
//
// This API provides the functionality to retrieve the LTP quotes for one or more instruments.This API returns the LTPs of up to 1000 instruments in one go.
//
get_market_quote_last_traded_price_response_t*
MarketQuoteAPI_ltp(apiClient_t *apiClient, char *symbol, char *instrument_key);


