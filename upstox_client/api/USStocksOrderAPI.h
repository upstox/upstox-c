#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/us_order_book_response.h"
#include "../models/us_order_details_response.h"
#include "../models/us_order_estimate_request.h"
#include "../models/us_order_estimate_response.h"
#include "../models/us_order_response.h"
#include "../models/us_place_order_request.h"


// Cancel US stocks order
//
// Cancels an open US stocks order.
//
us_order_response_t*
USStocksOrderAPI_cancelUsOrder(apiClient_t *apiClient, char *order_id);


// Estimate US stocks order charges
//
// Returns the brokerage, GST and US fees for an order before it is placed; nothing is placed. A market order is estimated at the price sent.
//
us_order_estimate_response_t*
USStocksOrderAPI_estimateUsOrder(apiClient_t *apiClient, us_order_estimate_request_t *us_order_estimate_request);


// Get US stocks order book
//
// Returns the user's US stocks orders for the day, in every state; optionally only those with a tag.
//
us_order_book_response_t*
USStocksOrderAPI_getUsOrderBook(apiClient_t *apiClient, char *tag);


// Get US stocks order details
//
// Returns the latest state of one US stocks order.
//
us_order_details_response_t*
USStocksOrderAPI_getUsOrderDetails(apiClient_t *apiClient, char *order_id);


// Place US stocks order
//
// Places a market or limit order for a US stock, sized by quantity or by USD amount.
//
us_order_response_t*
USStocksOrderAPI_placeUsOrder(apiClient_t *apiClient, us_place_order_request_t *us_place_order_request);


