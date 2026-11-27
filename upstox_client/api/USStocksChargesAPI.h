#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/us_margin_request.h"
#include "../models/us_margin_response.h"


// Calculate US stocks margin
//
// Returns the margin up to 20 orders require (trade value + brokerage + GST for a buy), the buying power available, any shortfall, and whether it is sufficient. Takes order estimate bodies; nothing is placed. A market order is valued at the last traded price. No leverage is offered on US stocks.
//
us_margin_response_t*
USStocksChargesAPI_calculateUsMargin(apiClient_t *apiClient, us_margin_request_t *us_margin_request);


