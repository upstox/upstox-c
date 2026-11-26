#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_profit_and_loss_charges_response.h"
#include "../models/get_trade_wise_profit_and_loss_data_response.h"
#include "../models/get_trade_wise_profit_and_loss_meta_data_response.h"


// Get profit and loss on trades
//
// This API gives the charges incurred by users for their trades
//
get_profit_and_loss_charges_response_t*
TradeProfitAndLossAPI_getProfitAndLossCharges(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date);


// Get Trade-wise Profit and Loss Report Data
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_data_response_t*
TradeProfitAndLossAPI_getTradeWiseProfitAndLossData(apiClient_t *apiClient, char *segment, char *financial_year, int *page_number, int *page_size, char *from_date, char *to_date);


// Get profit and loss meta data on trades
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_meta_data_response_t*
TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date);


