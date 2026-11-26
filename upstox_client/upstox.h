#ifndef UPSTOX_H
#define UPSTOX_H

#include <curl/curl.h>
#include "include/apiClient.h"

// Version of this SDK, sent with every request.
#define UPSTOX_SDK_VERSION "1.0.0"

#define UPSTOX_DEFAULT_BASE_PATH "https://api.upstox.com"
#define UPSTOX_ORDER_BASE_PATH "https://api-hft.upstox.com"
#define UPSTOX_SANDBOX_BASE_PATH "https://api-sandbox.upstox.com"

// Returns a client for the live API that sends accessToken as a Bearer token.
apiClient_t *upstox_client_create(const char *accessToken);

// Returns a client that sends every call to the Upstox sandbox.
apiClient_t *upstox_sandbox_client_create(const char *accessToken);

// Picks the base path for a call; NULL (and response_code 0) when sandbox mode does not serve the path.
const char *upstox_route(apiClient_t *apiClient, const char *path);

// Appends the Authorization and SDK identification headers.
struct curl_slist *upstox_append_headers(apiClient_t *apiClient, struct curl_slist *headers);

// Copies a non-2xx response body to apiClient->errorBody before the API function frees it.
void upstox_keep_error_body(apiClient_t *apiClient);

#endif // UPSTOX_H
