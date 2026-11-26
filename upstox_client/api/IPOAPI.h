#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/ipo_apply_request.h"
#include "../models/ipo_apply_response.h"
#include "../models/ipo_cancel_response.h"
#include "../models/ipo_details_response.h"
#include "../models/ipo_listing_response.h"
#include "../models/ipo_order_detail_response.h"
#include "../models/ipo_order_response.h"

// Enum STATUS for IPOAPI_getIpoListing
typedef enum  { upstox_client_getIpoListing_STATUS_NULL = 0, upstox_client_getIpoListing_STATUS_open, upstox_client_getIpoListing_STATUS_closed, upstox_client_getIpoListing_STATUS_listed, upstox_client_getIpoListing_STATUS_upcoming } upstox_client_getIpoListing_status_e;

// Enum ISSUETYPE for IPOAPI_getIpoListing
typedef enum  { upstox_client_getIpoListing_ISSUETYPE_NULL = 0, upstox_client_getIpoListing_ISSUETYPE_regular, upstox_client_getIpoListing_ISSUETYPE_sme } upstox_client_getIpoListing_issue_type_e;


// Apply for IPO
//
// Places an IPO application for the authenticated user.
//
ipo_apply_response_t*
IPOAPI_applyForIpo(apiClient_t *apiClient, ipo_apply_request_t *ipo_apply_request);


// Cancel IPO Order
//
// Cancels/deletes an IPO order of the authenticated user by order id.
//
ipo_cancel_response_t*
IPOAPI_cancelIpoOrder(apiClient_t *apiClient, char *order_id);


// Get IPO Details
//
// Fetches detailed information for an IPO by its slug ID.
//
ipo_details_response_t*
IPOAPI_getIpoDetails(apiClient_t *apiClient, char *id);


// Get IPO Listing
//
// Fetches list of IPOs filtered by status.
//
ipo_listing_response_t*
IPOAPI_getIpoListing(apiClient_t *apiClient, upstox_client_getIpoListing_status_e status, upstox_client_getIpoListing_issue_type_e issue_type, char *page_number, char *records);


// Get IPO Order
//
// Fetches a single IPO order of the authenticated user by order id.
//
ipo_order_detail_response_t*
IPOAPI_getIpoOrderById(apiClient_t *apiClient, char *order_id);


// Get IPO Orders
//
// Fetches the authenticated user's IPO orders/applications.
//
ipo_order_response_t*
IPOAPI_getIpoOrders(apiClient_t *apiClient, char *page_number, char *records);


