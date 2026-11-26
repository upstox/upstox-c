#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/cancel_order_v3_response.h"
#include "../models/get_gtt_order_response.h"
#include "../models/gtt_cancel_order_request.h"
#include "../models/gtt_modify_order_request.h"
#include "../models/gtt_place_order_request.h"
#include "../models/gtt_trigger_order_response.h"
#include "../models/modify_order_request.h"
#include "../models/modify_order_v3_response.h"
#include "../models/place_order_v3_request.h"
#include "../models/place_order_v3_response.h"


// Cancel GTT order
//
// This API allows you to cancel GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_cancelGTTOrder(apiClient_t *apiClient, gtt_cancel_order_request_t *gtt_cancel_order_request, char *Origin, char *X_Algo_Name);


cancel_order_v3_response_t*
OrderV3API_cancelOrderV3(apiClient_t *apiClient, char *order_id, char *X_Algo_Name);


// Get GTT order details
//
// GTT_ORDER_DESCRIPTION
//
get_gtt_order_response_t*
OrderV3API_getGttOrderDetails(apiClient_t *apiClient, char *gtt_order_id);


// Modify GTT order
//
// This API allows you to modify GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_modifyGTTOrder(apiClient_t *apiClient, gtt_modify_order_request_t *gtt_modify_order_request, char *Origin, char *X_Algo_Name);


modify_order_v3_response_t*
OrderV3API_modifyOrderV3(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name);


// Place GTT order
//
// This API allows you to place GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_placeGTTOrder(apiClient_t *apiClient, gtt_place_order_request_t *gtt_place_order_request, char *Origin, char *X_Algo_Name);


place_order_v3_response_t*
OrderV3API_placeOrderV3(apiClient_t *apiClient, place_order_v3_request_t *place_order_v3_request, char *X_Algo_Name);


