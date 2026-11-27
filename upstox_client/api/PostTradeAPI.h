#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/trade_history_response.h"


// Get historical trades
//
// This API retrieves the trade history for a specified time interval.
//
trade_history_response_t*
PostTradeAPI_getTradesByDateRange(apiClient_t *apiClient, char *start_date, char *end_date, int *page_number, int *page_size, char *segment);


