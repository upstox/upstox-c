#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/cancel_or_exit_multi_order_response.h"
#include "../models/cancel_order_response.h"
#include "../models/get_order_book_response.h"
#include "../models/get_order_details_response.h"
#include "../models/get_order_response.h"
#include "../models/get_trade_response.h"
#include "../models/modify_order_request.h"
#include "../models/modify_order_response.h"
#include "../models/multi_order_request.h"
#include "../models/multi_order_response.h"
#include "../models/place_order_request.h"
#include "../models/place_order_response.h"


// Cancel multi order
//
// API to cancel all the open or pending orders which can be applied to both AMO and regular orders.
//
cancel_or_exit_multi_order_response_t*
OrderAPI_cancelMultiOrder(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name);


// Cancel order
//
// Cancel order API can be used for two purposes: Cancelling an open order which could be an AMO or a normal order It is also used to EXIT a CO or OCO(bracket order)
//
cancel_order_response_t*
OrderAPI_cancelOrder(apiClient_t *apiClient, char *order_id, char *X_Algo_Name);


// Exit all positions
//
// This API provides the functionality to exit all the positions 
//
cancel_or_exit_multi_order_response_t*
OrderAPI_exitPositions(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name);


// Get order book
//
// This API provides the list of orders placed by the user. The orders placed by the user is transient for a day and is cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.
//
get_order_book_response_t*
OrderAPI_getOrderBook(apiClient_t *apiClient);


// Get order history
//
// This API provides the details of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.  The order history can be requested either using order_id or tag.  If both the options are passed, the history of the order which precisely matches both the order_id and tag will be returned in the response.  If only the tag is passed, the history of all the associated orders which matches the tag will be shared in the response.
//
get_order_response_t*
OrderAPI_getOrderDetails(apiClient_t *apiClient, char *order_id, char *tag);


// Get order details
//
// This API provides the recent detail of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session.\\n\\nThe order details can be requested using order_id.  
//
get_order_details_response_t*
OrderAPI_getOrderStatus(apiClient_t *apiClient, char *order_id);


// Get trades
//
// Retrieve the trades executed for the day
//
get_trade_response_t*
OrderAPI_getTradeHistory(apiClient_t *apiClient);


// Get trades for order
//
// Retrieve the trades executed for an order
//
get_trade_response_t*
OrderAPI_getTradesByOrder(apiClient_t *apiClient, char *order_id);


// Modify order
//
// This API allows you to modify an order. For modification orderId is mandatory. With orderId you need to send the optional parameter which needs to be modified. In case the optional parameters aren't sent, the default will be considered from the original order
//
modify_order_response_t*
OrderAPI_modifyOrder(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name);


// Place multi order
//
// This API allows you to place multiple orders to the exchange via Upstox.
//
multi_order_response_t*
OrderAPI_placeMultiOrder(apiClient_t *apiClient, list_t *multi_order_request, char *Origin, char *X_Algo_Name);


// Place order
//
// This API allows you to place an order to the exchange via Upstox.
//
place_order_response_t*
OrderAPI_placeOrder(apiClient_t *apiClient, place_order_request_t *place_order_request, char *X_Algo_Name);


