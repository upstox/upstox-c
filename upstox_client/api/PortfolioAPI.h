#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/convert_position_request.h"
#include "../models/convert_position_response.h"
#include "../models/get_holdings_response.h"
#include "../models/get_position_response.h"


// Convert Positions
//
// Convert the margin product of an open position
//
convert_position_response_t*
PortfolioAPI_convertPositions(apiClient_t *apiClient, convert_position_request_t *convert_position_request);


// Get Holdings
//
// Fetches the holdings which the user has bought/sold in previous trading sessions.
//
get_holdings_response_t*
PortfolioAPI_getHoldings(apiClient_t *apiClient);


// Get MTF positions
//
// This API allows you to get MTF positions.
//
get_position_response_t*
PortfolioAPI_getMtfPositions(apiClient_t *apiClient);


// Get Positions
//
// Fetches the current positions for the user for the current day.
//
get_position_response_t*
PortfolioAPI_getPositions(apiClient_t *apiClient);


