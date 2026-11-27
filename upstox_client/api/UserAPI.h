#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/get_profile_response.h"
#include "../models/get_user_fund_margin_response.h"
#include "../models/get_user_fund_margin_v3_response.h"
#include "../models/initiate_payout_request.h"
#include "../models/kill_switch_response.h"
#include "../models/kill_switch_segment_update_request.h"
#include "../models/modify_payout_request.h"
#include "../models/payment_history_response.h"
#include "../models/payout_details_response.h"
#include "../models/payout_modes_response.h"
#include "../models/update_user_ip_request.h"
#include "../models/user_ip_response.h"

// Enum SEGMENT for UserAPI_getUserFundMargin
typedef enum  { upstox_client_getUserFundMargin_SEGMENT_NULL = 0, upstox_client_getUserFundMargin_SEGMENT_SEC, upstox_client_getUserFundMargin_SEGMENT_COM } upstox_client_getUserFundMargin_segment_e;


payout_details_response_t*
UserAPI_cancelPayout(apiClient_t *apiClient, char *transaction_id);


// Get kill switch status
//
// Returns the disable/enable status of all trading segments for the user.
//
kill_switch_response_t*
UserAPI_getKillSwitch(apiClient_t *apiClient);


payment_history_response_t*
UserAPI_getPayinHistory(apiClient_t *apiClient);


payment_history_response_t*
UserAPI_getPayoutHistory(apiClient_t *apiClient);


payout_modes_response_t*
UserAPI_getPayoutModes(apiClient_t *apiClient);


// Get profile
//
// This API allows to fetch the complete information of the user who is logged in including the products, order types and exchanges enabled for the user
//
get_profile_response_t*
UserAPI_getProfile(apiClient_t *apiClient);


// Get User Fund And Margin
//
// Shows the balance of the user in equity and commodity market.
//
get_user_fund_margin_response_t*
UserAPI_getUserFundMargin(apiClient_t *apiClient, upstox_client_getUserFundMargin_segment_e segment);


// Get User Fund And Margin
//
// Shows the detailed balance breakdown of the user including cash, pledged margin, available-to-trade, and unavailable-to-trade components.
//
get_user_fund_margin_v3_response_t*
UserAPI_getUserFundMarginV3(apiClient_t *apiClient);


user_ip_response_t*
UserAPI_getUserIps(apiClient_t *apiClient);


payout_details_response_t*
UserAPI_initiatePayout(apiClient_t *apiClient, initiate_payout_request_t *initiate_payout_request);


payout_details_response_t*
UserAPI_modifyPayout(apiClient_t *apiClient, char *transaction_id, modify_payout_request_t *modify_payout_request);


// Update kill switch
//
// Enable or disable specific trading segments.
//
kill_switch_response_t*
UserAPI_updateKillSwitch(apiClient_t *apiClient, list_t *kill_switch_segment_update_request);


user_ip_response_t*
UserAPI_updateUserIp(apiClient_t *apiClient, update_user_ip_request_t *update_user_ip_request);


