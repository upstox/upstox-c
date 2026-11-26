#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_mutual_fund_holdings_response.h"
#include "../models/get_mutual_fund_order_details_response.h"
#include "../models/get_mutual_fund_orders_response.h"
#include "../models/get_mutual_fund_sips_response.h"


// Get mutual fund holdings
//
// Returns mutual fund holdings for the authenticated user.
//
get_mutual_fund_holdings_response_t*
MutualFundAPI_getMutualFundHoldings(apiClient_t *apiClient);


// Get mutual fund order by id
//
// Returns a single mutual fund order by order id.
//
get_mutual_fund_order_details_response_t*
MutualFundAPI_getMutualFundOrder(apiClient_t *apiClient, char *order_id);


// Get mutual fund orders
//
// Returns mutual fund orders from the last 7 days for the authenticated user.
//
get_mutual_fund_orders_response_t*
MutualFundAPI_getMutualFundOrders(apiClient_t *apiClient, char *status, char *transaction_type, int *page_number, int *records);


// Get mutual fund SIPs
//
// Returns active and paused SIP orders for the authenticated user.
//
get_mutual_fund_sips_response_t*
MutualFundAPI_getMutualFundSips(apiClient_t *apiClient, int *page_number, int *records);


