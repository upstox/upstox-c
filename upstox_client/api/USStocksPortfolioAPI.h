#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/us_holdings_response.h"


// Get US stocks holdings
//
// Returns the user's US stocks holdings.
//
us_holdings_response_t*
USStocksPortfolioAPI_getUsHoldings(apiClient_t *apiClient);


