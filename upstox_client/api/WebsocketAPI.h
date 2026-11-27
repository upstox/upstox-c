#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/websocket_auth_redirect_response.h"


// Market Data Feed
//
//  This API redirects the client to the respective socket endpoint to receive Market updates.
//
void
WebsocketAPI_getMarketDataFeed(apiClient_t *apiClient);


// Market Data Feed Authorize
//
// This API provides the functionality to retrieve the socket endpoint URI for Market updates.
//
websocket_auth_redirect_response_t*
WebsocketAPI_getMarketDataFeedAuthorize(apiClient_t *apiClient);


// Market Data Feed Authorize (V3)
//
// This API provides the functionality to retrieve the socket endpoint URI for Market updates.
//
websocket_auth_redirect_response_t*
WebsocketAPI_getMarketDataFeedAuthorizeV3(apiClient_t *apiClient);


// Market Data Feed (V3)
//
//  This API redirects the client to the respective socket endpoint to receive Market updates.
//
void
WebsocketAPI_getMarketDataFeedV3(apiClient_t *apiClient);


// Portfolio Stream Feed
//
// This API redirects the client to the respective socket endpoint to receive Portfolio updates.
//
void
WebsocketAPI_getPortfolioStreamFeed(apiClient_t *apiClient, char *update_types);


// Portfolio Stream Feed Authorize
//
//  This API provides the functionality to retrieve the socket endpoint URI for Portfolio updates.
//
websocket_auth_redirect_response_t*
WebsocketAPI_getPortfolioStreamFeedAuthorize(apiClient_t *apiClient, char *update_types);


