#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../models/api_gateway_error_response.h"
#include "../models/indie_user_init_token_response.h"
#include "../models/indie_user_token_request.h"
#include "../models/logout_response.h"
#include "../models/o_auth_client_exception.h"
#include "../models/token_response.h"
#include "../models/totp_pin_token_request.h"


// Authorize API
//
// This provides details on the login endpoint.
//
void
LoginAPI_authorize(apiClient_t *apiClient, char *client_id, char *redirect_uri, char *state, char *scope);


// Generate token using TOTP and PIN
//
// This API generates an access token for an automation client using the app's API key together with the user's 6-digit PIN and 6-digit TOTP
//
token_response_t*
LoginAPI_generateTokenViaTotpAndPin(apiClient_t *apiClient, char *x_api_key, totp_pin_token_request_t *totp_pin_token_request, char *x_user_id);


// Init token API
//
// This API provides the initialize the generate token and it's expiry for an indie user
//
indie_user_init_token_response_t*
LoginAPI_initTokenRequestForIndieUser(apiClient_t *apiClient, char *client_id, indie_user_token_request_t *indie_user_token_request);


// Logout
//
// Logout
//
logout_response_t*
LoginAPI_logout(apiClient_t *apiClient);


// Get token API
//
// This API provides the functionality to obtain opaque token from authorization_code exchange and also provides the user’s profile in the same response.
//
token_response_t*
LoginAPI_token(apiClient_t *apiClient, char *code, char *client_id, char *client_secret, char *redirect_uri, char *grant_type, int *refresh_extended_token);


