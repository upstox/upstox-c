// sandbox_sanity.c: port of the Python SDK's test/sdk_tests/sandbox_sanity.py against the Upstox sandbox.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "upstox_client/upstox.h"
#include "upstox_client/external/cJSON.h"
#include "upstox_client/api/OrderAPI.h"
#include "upstox_client/api/OrderV3API.h"
#include "data_token.h"

#define IDEA_KEY "NSE_EQ|INE669E01016"

static apiClient_t *c;
static int checks, failed;

// Counts a failed call and prints msg with the HTTP status and error body.
static void fail_call(const char *msg) {
    failed++;
    printf("%s: HTTP %ld %s\n", msg, c->response_code, c->errorBody ? c->errorBody : "(no response)");
}

// Prints j (consumed), like Python's print(api_response).
static void show_json(cJSON *j) {
    char *s = j ? cJSON_PrintUnformatted(j) : NULL;
    printf("%s\n", s ? s : "(unprintable)");
    free(s);
    cJSON_Delete(j);
}

// True when the last error body's errors[0].errorCode (or error_code) equals want.
static int has_code(const char *want) {
    cJSON *body = c->errorBody ? cJSON_Parse(c->errorBody) : NULL;
    cJSON *first = cJSON_GetArrayItem(cJSON_GetObjectItemCaseSensitive(body, "errors"), 0);
    cJSON *code = cJSON_GetObjectItemCaseSensitive(first, "errorCode");
    if (!cJSON_IsString(code)) {
        code = cJSON_GetObjectItemCaseSensitive(first, "error_code");
    }
    int found = cJSON_IsString(code) && strcmp(code->valuestring, want) == 0;
    cJSON_Delete(body);
    return found;
}

// Prints the response; an error counts as a failure.
#define SHOW(type, call, exc_msg)                                                 \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        checks++;                                                                 \
        if (r_ != NULL) {                                                         \
            show_json(type##_convertToJSON(r_));                                  \
        } else {                                                                  \
            fail_call(exc_msg);                                                   \
        }                                                                         \
        type##_free(r_);                                                          \
    } while (0)

// An expected-error probe: passes on success or on error code.
#define EXPECT(type, call, msg, code)                                             \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        checks++;                                                                 \
        if (r_ == NULL && !has_code(code)) {                                      \
            fail_call(msg);                                                       \
        }                                                                         \
        type##_free(r_);                                                          \
    } while (0)

// Parses json into a new model in var (NULL, with a message, when it does not parse).
#define PARSE(type, var, json)                                                    \
    do {                                                                          \
        cJSON *j_ = cJSON_Parse(json);                                            \
        var = j_ ? type##_parseFromJSON(j_) : NULL;                               \
        cJSON_Delete(j_);                                                         \
        if (var == NULL) {                                                        \
            printf("could not build %s from %s\n", #type, json);                  \
        }                                                                         \
    } while (0)

// Runs sandbox_sanity.py's calls in order; returns the number of failed checks.
static int run_sandbox_sanity(apiClient_t *client) {
    c = client;

    place_order_request_t *place;
    PARSE(place_order_request, place, "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":12.0,"
          "\"tag\":\"string\",\"instrument_token\":\"NSE_EQ|INE528G01035\",\"order_type\":\"LIMIT\","
          "\"transaction_type\":\"BUY\",\"disclosed_quantity\":0,\"trigger_price\":0.0,\"is_amo\":false}");
    SHOW(place_order_response, OrderAPI_placeOrder(c, place, NULL), "exception in place order");
    place_order_request_free(place);

    modify_order_request_t *modify;
    PARSE(modify_order_request, modify, "{\"quantity\":2,\"validity\":\"DAY\",\"price\":0,\"order_id\":\"250121112512866\","
          "\"order_type\":\"MARKET\",\"disclosed_quantity\":0,\"trigger_price\":0}");
    EXPECT(modify_order_response, OrderAPI_modifyOrder(c, modify, NULL), "modify order giving wrong response", "UDAPI100010");
    modify_order_request_free(modify);

    cJSON *legs = cJSON_Parse(
        "[{\"quantity\":1,\"product\":\"I\",\"validity\":\"DAY\",\"price\":0,\"tag\":\"kg_python_sdk\",\"slice\":false,"
        "\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"MARKET\",\"transaction_type\":\"BUY\","
        "\"disclosed_quantity\":0,\"trigger_price\":0,\"is_amo\":true,\"correlation_id\":\"1\"},"
        "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":8.9,\"tag\":\"kg_python_sdk1\",\"slice\":false,"
        "\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\","
        "\"disclosed_quantity\":0,\"trigger_price\":0,\"is_amo\":true,\"correlation_id\":\"2\"}]");
    list_t *multi = list_createList();
    cJSON *leg;
    cJSON_ArrayForEach(leg, legs) {
        multi_order_request_t *m = multi_order_request_parseFromJSON(leg);
        if (m != NULL) {
            list_addElement(multi, m);
        }
    }
    cJSON_Delete(legs);
    SHOW(multi_order_response, OrderAPI_placeMultiOrder(c, multi, NULL, NULL), "Exception when calling OrderApi->place_order");
    listEntry_t *e;
    list_ForEach(e, multi) {
        multi_order_request_free(e->data);
    }
    list_freeList(multi);

    EXPECT(cancel_order_response, OrderAPI_cancelOrder(c, "2501211126016789", NULL), "cancel order giving wrong response", "UDAPI100010");

    place_order_v3_request_t *place_v3;
    PARSE(place_order_v3_request, place_v3, "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":9.12,"
          "\"tag\":\"string\",\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\","
          "\"disclosed_quantity\":0,\"trigger_price\":0.0,\"is_amo\":true,\"slice\":true}");
    SHOW(place_order_v3_response, OrderV3API_placeOrderV3(c, place_v3, NULL), "Exception when calling OrderApi->place_order");
    place_order_v3_request_free(place_v3);

    PARSE(modify_order_request, modify, "{\"quantity\":3,\"validity\":\"DAY\",\"price\":9.12,\"order_id\":\"250120010373947\","
          "\"order_type\":\"LIMIT\",\"disclosed_quantity\":0,\"trigger_price\":0}");
    EXPECT(modify_order_v3_response, OrderV3API_modifyOrderV3(c, modify, NULL), "modify order giving wrong response", "UDAPI100010");
    modify_order_request_free(modify);

    EXPECT(cancel_order_v3_response, OrderV3API_cancelOrderV3(c, "25012112309073", NULL), "cancel order giving wrong response", "UDAPI100010");

    printf("%d checks, %d failed\n", checks, failed);
    return failed;
}

int main(void) {
    const char *token = data_token_sandbox_access_token();
    if (token[0] == '\0') {
        printf("no sandbox token: set UPSTOX_SANDBOX_ACCESS_TOKEN, or DATA_TOKEN_SANDBOX_ACCESS_TOKEN in "
               "test/sdk_tests/data_token.h (never commit it)\n");
        return 1;
    }
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_sandbox_client_create(token);
    int bad = run_sandbox_sanity(client);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return bad > 0 ? 1 : 0;
}
