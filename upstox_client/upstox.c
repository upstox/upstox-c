#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "upstox.h"

// The only endpoints the sandbox environment serves.
static const char *sandbox_paths[] = {
    "/v2/order/place", "/v2/order/modify", "/v2/order/cancel", "/v2/order/multi/place",
    "/v3/order/place", "/v3/order/modify", "/v3/order/cancel", NULL,
};

static apiClient_t *create(const char *basePath, const char *accessToken, int sandbox) {
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, NULL);
    if (accessToken != NULL) {
        apiClient->accessToken = strdup(accessToken);
    }
    apiClient->sandbox = sandbox;
    return apiClient;
}

apiClient_t *upstox_client_create(const char *accessToken) {
    return create(UPSTOX_DEFAULT_BASE_PATH, accessToken, 0);
}

apiClient_t *upstox_sandbox_client_create(const char *accessToken) {
    return create(UPSTOX_SANDBOX_BASE_PATH, accessToken, 1);
}

static int is_order_path(const char *path) {
    // US stock orders are served by the main host, not HFT
    if (strncmp(path, "/v2/us/", 7) == 0) {
        return 0;
    }
    return strstr(path, "/order/place") || strstr(path, "/order/modify") || strstr(path, "/order/cancel");
}

const char *upstox_route(apiClient_t *apiClient, const char *path) {
    if (apiClient->sandbox) {
        for (int i = 0; sandbox_paths[i]; i++) {
            if (strcmp(path, sandbox_paths[i]) == 0) {
                return UPSTOX_SANDBOX_BASE_PATH;
            }
        }
        fprintf(stderr, "upstox: %s is not available in sandbox mode\n", path);
        apiClient->response_code = 0;
        return NULL;
    }
    // A custom base path (e.g. a proxy or test server) disables HFT routing
    if (strcmp(apiClient->basePath, UPSTOX_DEFAULT_BASE_PATH) == 0 && is_order_path(path)) {
        if (apiClient->orderBasePath == NULL) {
            apiClient->orderBasePath = strdup(UPSTOX_ORDER_BASE_PATH);
        }
        return apiClient->orderBasePath;
    }
    return apiClient->basePath;
}

struct curl_slist *upstox_append_headers(apiClient_t *apiClient, struct curl_slist *headers) {
    if (apiClient->accessToken != NULL) {
        size_t n = strlen("Authorization: Bearer ") + strlen(apiClient->accessToken) + 1;
        char *auth = malloc(n);
        snprintf(auth, n, "Authorization: Bearer %s", apiClient->accessToken);
        headers = curl_slist_append(headers, auth);
        free(auth);
    }
    headers = curl_slist_append(headers, "X-Upstox-SDK-Language: c");
    headers = curl_slist_append(headers, "X-Upstox-SDK-Version: " UPSTOX_SDK_VERSION);
    headers = curl_slist_append(headers, "User-Agent: upstox-c/" UPSTOX_SDK_VERSION);
    return headers;
}

void upstox_keep_error_body(apiClient_t *apiClient) {
    if (apiClient->response_code >= 200 && apiClient->response_code < 300) {
        return;
    }
    // malloc + memcpy rather than strndup, which MSVC lacks
    if (apiClient->dataReceived != NULL && (apiClient->errorBody = malloc(apiClient->dataReceivedLen + 1)) != NULL) {
        memcpy(apiClient->errorBody, apiClient->dataReceived, apiClient->dataReceivedLen);
        apiClient->errorBody[apiClient->dataReceivedLen] = '\0';
    }
}
