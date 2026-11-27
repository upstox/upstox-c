// Unit tests for the hand-written Upstox hooks: routing, sandbox, headers, request bodies and error bodies.
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#include "upstox.h"
#include "api/OrderAPI.h"
#include "api/MarketQuoteV3API.h"
#include "api/OrderV3API.h"
#include "api/UserAPI.h"

static int failures = 0;

#define CHECK(cond, ...)                                    \
    do {                                                    \
        if (!(cond)) {                                      \
            failures++;                                     \
            fprintf(stderr, "FAIL %s:%d: ", __FILE__, __LINE__); \
            fprintf(stderr, __VA_ARGS__);                   \
            fprintf(stderr, "\n");                          \
        }                                                   \
    } while (0)

// One-shot HTTP listener: answers each connection with the configured status and body, recording the request.
typedef struct {
    int fd;
    int port;
    int status;
    const char *body;
    char request[16384];
} server_t;

static void *serve_one(void *arg) {
    server_t *s = arg;
    int c = accept(s->fd, NULL, NULL);
    if (c < 0) {
        return NULL;
    }
    size_t len = 0;
    s->request[0] = '\0';
    for (;;) {
        ssize_t n = recv(c, s->request + len, sizeof(s->request) - 1 - len, 0);
        if (n <= 0) {
            break;
        }
        len += (size_t) n;
        s->request[len] = '\0';
        char *end = strstr(s->request, "\r\n\r\n");
        if (end) {
            char *cl = strcasestr(s->request, "Content-Length:");
            size_t want = cl ? (size_t) atoi(cl + 15) : 0;
            if (len - (size_t) (end + 4 - s->request) >= want) {
                break;
            }
        }
    }
    char head[256];
    int n = snprintf(head, sizeof(head),
                     "HTTP/1.1 %d X\r\nContent-Type: application/json\r\nContent-Length: %zu\r\nConnection: close\r\n\r\n",
                     s->status, strlen(s->body));
    send(c, head, (size_t) n, 0);
    send(c, s->body, strlen(s->body), 0);
    close(c);
    return NULL;
}

static void server_open(server_t *s) {
    memset(s, 0, sizeof(*s));
    s->fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr = {.sin_family = AF_INET, .sin_addr.s_addr = htonl(INADDR_LOOPBACK)};
    socklen_t alen = sizeof(addr);
    bind(s->fd, (struct sockaddr *) &addr, sizeof(addr));
    listen(s->fd, 4);
    getsockname(s->fd, (struct sockaddr *) &addr, &alen);
    s->port = ntohs(addr.sin_port);
}

// Starts answering one request; join the returned thread after the call.
static pthread_t server_expect(server_t *s, int status, const char *body) {
    pthread_t t;
    s->status = status;
    s->body = body;
    pthread_create(&t, NULL, serve_one, s);
    return t;
}

static apiClient_t *local_client(server_t *s) {
    char base[64];
    snprintf(base, sizeof(base), "http://127.0.0.1:%d", s->port);
    apiClient_t *c = apiClient_create_with_base_path(base, NULL);
    c->accessToken = strdup("test-token");
    return c;
}

static void test_hft_routing(void) {
    apiClient_t *c = upstox_client_create("t");
    CHECK(strcmp(upstox_route(c, "/v2/order/place"), UPSTOX_ORDER_BASE_PATH) == 0, "v2 place should use HFT");
    CHECK(strcmp(upstox_route(c, "/v3/order/modify"), UPSTOX_ORDER_BASE_PATH) == 0, "v3 modify should use HFT");
    CHECK(strcmp(upstox_route(c, "/v2/order/cancel"), UPSTOX_ORDER_BASE_PATH) == 0, "v2 cancel should use HFT");
    // Same path rule as the Python SDK: multi and GTT orders stay on the main host
    CHECK(strcmp(upstox_route(c, "/v2/order/multi/place"), UPSTOX_DEFAULT_BASE_PATH) == 0, "multi place stays on the main host");
    CHECK(strcmp(upstox_route(c, "/v3/order/gtt/cancel"), UPSTOX_DEFAULT_BASE_PATH) == 0, "GTT cancel stays on the main host");
    CHECK(strcmp(upstox_route(c, "/v2/us/order/place"), UPSTOX_DEFAULT_BASE_PATH) == 0, "US orders stay on the main host");
    CHECK(strcmp(upstox_route(c, "/v2/market-quote/ltp"), UPSTOX_DEFAULT_BASE_PATH) == 0, "quotes stay on the main host");
    CHECK(strcmp(upstox_route(c, "/v2/order/retrieve-all"), UPSTOX_DEFAULT_BASE_PATH) == 0, "order reads stay on the main host");
    apiClient_free(c);
}

static void test_custom_base_path_disables_hft(void) {
    apiClient_t *c = apiClient_create_with_base_path("https://proxy.example.com", NULL);
    CHECK(strcmp(upstox_route(c, "/v2/order/place"), "https://proxy.example.com") == 0, "custom base path should not route to HFT");
    apiClient_free(c);
}

static void test_sandbox(void) {
    apiClient_t *c = upstox_sandbox_client_create("t");
    CHECK(strcmp(upstox_route(c, "/v3/order/place"), UPSTOX_SANDBOX_BASE_PATH) == 0, "sandbox order goes to the sandbox host");
    CHECK(strcmp(upstox_route(c, "/v2/order/multi/place"), UPSTOX_SANDBOX_BASE_PATH) == 0, "sandbox multi order goes to the sandbox host");
    get_profile_response_t *r = UserAPI_getProfile(c);
    CHECK(r == NULL && c->response_code == 0, "sandbox should block the profile call without a request");
    apiClient_free(c);
}

static void test_headers_and_profile(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    pthread_t t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":{\"user_name\":\"Test User\",\"email\":\"a@b.c\"}}");
    get_profile_response_t *r = UserAPI_getProfile(c);
    pthread_join(t, NULL);
    CHECK(strstr(s.request, "GET /v2/user/profile ") != NULL, "path: %s", s.request);
    CHECK(strstr(s.request, "Authorization: Bearer test-token\r\n") != NULL, "missing bearer token");
    CHECK(strstr(s.request, "X-Upstox-SDK-Language: c\r\n") != NULL, "missing SDK language header");
    CHECK(strstr(s.request, "X-Upstox-SDK-Version: " UPSTOX_SDK_VERSION "\r\n") != NULL, "missing SDK version header");
    CHECK(strstr(s.request, "User-Agent: upstox-c/" UPSTOX_SDK_VERSION "\r\n") != NULL, "missing User-Agent");
    CHECK(r && r->data && r->data->user_name && strcmp(r->data->user_name, "Test User") == 0, "profile not parsed");
    get_profile_response_free(r);
    apiClient_free(c);
    close(s.fd);
}

static void test_algo_name_header(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    pthread_t t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":{\"order_id\":\"123\"}}");
    cancel_order_response_t *r = OrderAPI_cancelOrder(c, "123", "my-algo");
    pthread_join(t, NULL);
    CHECK(strstr(s.request, "DELETE /v2/order/cancel?order_id=123 ") != NULL, "path: %s", s.request);
    CHECK(strstr(s.request, "X-Algo-Name: my-algo\r\n") != NULL, "missing X-Algo-Name");
    cancel_order_response_free(r);
    apiClient_free(c);
    close(s.fd);
}

static void test_snake_case_body_and_double_prices(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    cJSON *json = cJSON_Parse("{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":2345.65,"
                              "\"instrument_token\":\"NSE_EQ|INE669E01016\",\"order_type\":\"LIMIT\","
                              "\"transaction_type\":\"BUY\",\"disclosed_quantity\":0,\"trigger_price\":0,"
                              "\"is_amo\":false,\"slice\":false,\"market_protection\":2.5}");
    place_order_v3_request_t *req = place_order_v3_request_parseFromJSON(json);
    cJSON_Delete(json);
    CHECK(req && req->price && *req->price == 2345.65, "price should round-trip exactly as a double");
    pthread_t t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":{\"order_ids\":[\"1\"]}}");
    place_order_v3_response_t *r = OrderV3API_placeOrder(c, req, NULL);
    pthread_join(t, NULL);
    CHECK(strstr(s.request, "POST /v3/order/place ") != NULL, "path: %s", s.request);
    CHECK(strstr(s.request, "\"instrument_token\":\"NSE_EQ|INE669E01016\"") != NULL, "body: %s", s.request);
    CHECK(strstr(s.request, "\"price\":2345.65") != NULL, "body: %s", s.request);
    CHECK(strstr(s.request, "\"market_protection\":2.5") != NULL, "body: %s", s.request);
    CHECK(strstr(s.request, "X-Algo-Name") == NULL, "X-Algo-Name sent although not set");
    CHECK(r != NULL, "response not parsed");
    place_order_v3_response_free(r);
    place_order_v3_request_free(req);
    apiClient_free(c);
    close(s.fd);
}

static void test_error_body_kept(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    const char *err = "{\"status\":\"error\",\"errors\":[{\"error_code\":\"UDAPI100050\",\"message\":\"Invalid token\"}]}";
    pthread_t t = server_expect(&s, 401, err);
    get_profile_response_t *r = UserAPI_getProfile(c);
    pthread_join(t, NULL);
    CHECK(r == NULL && c->response_code == 401, "401 should return NULL, got code %ld", c->response_code);
    CHECK(c->errorBody && strcmp(c->errorBody, err) == 0, "error body not kept: %s", c->errorBody ? c->errorBody : "(null)");
    t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":{}}");
    r = UserAPI_getProfile(c);
    pthread_join(t, NULL);
    CHECK(c->errorBody == NULL, "error body should clear on success");
    get_profile_response_free(r);
    apiClient_free(c);
    close(s.fd);
}

static void test_map_response_parsed(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    pthread_t t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":{\"NSE_EQ:INFY\":{\"last_price\":1523.45,"
                                         "\"instrument_token\":\"NSE_EQ|INE009A01021\"}}}");
    get_market_quote_last_traded_price_response_v3_t *r = MarketQuoteV3API_getLtp(c, "NSE_EQ|INE009A01021");
    pthread_join(t, NULL);
    CHECK(r && r->data && r->data->count == 1, "map should hold one entry");
    if (r && r->data && r->data->count == 1) {
        keyValuePair_t *kv = r->data->firstEntry->data;
        market_quote_symbol_ltp_v3_t *ltp = kv->value;
        CHECK(strcmp(kv->key, "NSE_EQ:INFY") == 0, "map key: %s", kv->key);
        CHECK(ltp && ltp->last_price && *ltp->last_price == 1523.45, "map value not parsed");
        cJSON *json = get_market_quote_last_traded_price_response_v3_convertToJSON(r);
        char *text = cJSON_PrintUnformatted(json);
        CHECK(strstr(text, "\"NSE_EQ:INFY\":{\"last_price\":1523.45") != NULL, "map not serialised: %s", text);
        free(text);
        cJSON_Delete(json);
    }
    get_market_quote_last_traded_price_response_v3_free(r);
    apiClient_free(c);
    close(s.fd);
}

static void test_array_body_sent_bare(void) {
    server_t s;
    server_open(&s);
    apiClient_t *c = local_client(&s);
    list_t *orders = list_createList();
    for (int i = 1; i <= 2; i++) {
        char body[512];
        snprintf(body, sizeof(body), "{\"correlation_id\":\"%d\",\"quantity\":%d,\"product\":\"D\",\"validity\":\"DAY\","
                 "\"price\":0,\"instrument_token\":\"NSE_EQ|INE669E01016\",\"order_type\":\"MARKET\",\"transaction_type\":\"BUY\","
                 "\"disclosed_quantity\":0,\"trigger_price\":0,\"is_amo\":false,\"slice\":false}", i, i);
        cJSON *json = cJSON_Parse(body);
        multi_order_request_t *order = multi_order_request_parseFromJSON(json);
        cJSON_Delete(json);
        CHECK(order != NULL, "multi order request %d not parsed", i);
        if (order == NULL) {
            list_freeList(orders);
            apiClient_free(c);
            close(s.fd);
            return;
        }
        list_addElement(orders, order);
    }
    pthread_t t = server_expect(&s, 200, "{\"status\":\"success\",\"data\":[]}");
    multi_order_response_t *r = OrderAPI_placeMultiOrder(c, orders, NULL, NULL);
    pthread_join(t, NULL);
    char *body = strstr(s.request, "\r\n\r\n");
    CHECK(body && strncmp(body + 4, "[{", 2) == 0, "body should be a bare array: %s", body ? body + 4 : "");
    CHECK(body && strstr(body, "\"correlation_id\":\"1\"") && strstr(body, "\"correlation_id\":\"2\""),
          "orders missing: %s", body ? body + 4 : "");
    multi_order_response_free(r);
    listEntry_t *e;
    list_ForEach(e, orders) {
        multi_order_request_free(e->data);
    }
    list_freeList(orders);
    apiClient_free(c);
    close(s.fd);
}

int main(void) {
    apiClient_setupGlobalEnv();
    test_hft_routing();
    test_custom_base_path_disables_hft();
    test_sandbox();
    test_headers_and_profile();
    test_algo_name_header();
    test_snake_case_body_and_double_prices();
    test_error_body_kept();
    test_map_response_parsed();
    test_array_body_sent_bare();
    apiClient_unsetupGlobalEnv();
    if (failures) {
        fprintf(stderr, "%d check(s) failed\n", failures);
        return 1;
    }
    printf("upstox_test: all checks passed\n");
    return 0;
}
