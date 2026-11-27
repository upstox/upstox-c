#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/us_funds_response.h"


// Get US stocks funds
//
// Returns the user's US stocks wallet balance in USD.
//
us_funds_response_t*
USStocksFundsAPI_getUsFunds(apiClient_t *apiClient);


