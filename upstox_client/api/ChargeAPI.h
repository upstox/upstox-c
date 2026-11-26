#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_brokerage_response.h"
#include "../models/margin_request.h"
#include "../models/post_margin_response.h"


// Brokerage details
//
// Compute Brokerage Charges
//
get_brokerage_response_t*
ChargeAPI_getBrokerage(apiClient_t *apiClient, char *instrument_token, int *quantity, char *product, char *transaction_type, double price);


// Calculate Margin
//
// Compute Margin
//
post_margin_response_t*
ChargeAPI_postMargin(apiClient_t *apiClient, margin_request_t *margin_request);


