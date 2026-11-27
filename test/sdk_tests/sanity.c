// sanity.c: port of the Python SDK's test/sdk_tests/sanity.py; calls the live Upstox API and reports failed checks.
// Like sanity.py it runs account-changing calls ungated; IPO and payout writes stay off via constants.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "upstox_client/upstox.h"
#include "upstox_client/external/cJSON.h"
#include "upstox_client/api/ChargeAPI.h"
#include "upstox_client/api/ExpiredInstrumentAPI.h"
#include "upstox_client/api/FundamentalsAPI.h"
#include "upstox_client/api/HistoryAPI.h"
#include "upstox_client/api/HistoryV3API.h"
#include "upstox_client/api/InstrumentsAPI.h"
#include "upstox_client/api/IPOAPI.h"
#include "upstox_client/api/LoginAPI.h"
#include "upstox_client/api/MarketHolidaysAndTimingsAPI.h"
#include "upstox_client/api/MarketQuoteAPI.h"
#include "upstox_client/api/MarketQuoteV3API.h"
#include "upstox_client/api/MutualFundAPI.h"
#include "upstox_client/api/NewsAPI.h"
#include "upstox_client/api/OptionsAPI.h"
#include "upstox_client/api/OrderAPI.h"
#include "upstox_client/api/OrderV3API.h"
#include "upstox_client/api/PortfolioAPI.h"
#include "upstox_client/api/PostTradeAPI.h"
#include "upstox_client/api/TradeProfitAndLossAPI.h"
#include "upstox_client/api/USMarketHolidaysAndTimingsAPI.h"
#include "upstox_client/api/USStocksChargesAPI.h"
#include "upstox_client/api/USStocksFundsAPI.h"
#include "upstox_client/api/USStocksOrderAPI.h"
#include "upstox_client/api/USStocksPortfolioAPI.h"
#include "upstox_client/api/UserAPI.h"
#include "data_token.h"

// Same switches as sanity.py: IPO apply/cancel blocks funds via UPI, payout writes move real money.
#define RUN_DESTRUCTIVE_IPO_TESTS 0
#define RUN_DESTRUCTIVE_PAYOUT_TESTS 0

// Vodafone Idea, the instrument most Python calls use.
#define IDEA_KEY "NSE_EQ|INE669E01016"
#define NIFTY_KEY "NSE_INDEX|Nifty 50"
// Python's sanity tag for bulk cancel/exit.
#define PYTHON_TAG "sdk_python_tag"
#define ALGO DATA_TOKEN_ALGO_NAME

static apiClient_t *c;
static int checks, failed;

// ---- reporting -------------------------------------------------------------

// Counts a failure and prints msg.
static void fail_msg(const char *msg) {
    failed++;
    printf("%s\n", msg);
}

// Counts a failed call and prints msg with the HTTP status and error body.
static void fail_call(const char *msg) {
    failed++;
    printf("%s: HTTP %ld %s\n", msg, c->response_code, c->errorBody ? c->errorBody : "(no response)");
}

// Prints label followed by j (consumed), like Python's print(api_response).
static void show_json(const char *label, cJSON *j) {
    char *s = j ? cJSON_PrintUnformatted(j) : NULL;
    printf("%s%s\n", label, s ? s : "(unprintable)");
    free(s);
    cJSON_Delete(j);
}

// Counts one response check: exc_msg when the call failed, msg when status or data is wrong.
static void check_response(int returned, int good, const char *exc_msg, const char *msg) {
    checks++;
    if (!returned) {
        fail_call(exc_msg);
    } else if (!good) {
        fail_msg(msg);
    }
}

// Counts an in-memory model check.
static void check_model(int good, const char *msg) {
    checks++;
    if (!good) {
        fail_msg(msg);
    }
}

// True when the last error body's errors[0].errorCode (or error_code) is in the NULL-terminated codes.
static int has_code(const char *const *codes) {
    cJSON *body = c->errorBody ? cJSON_Parse(c->errorBody) : NULL;
    cJSON *first = cJSON_GetArrayItem(cJSON_GetObjectItemCaseSensitive(body, "errors"), 0);
    cJSON *code = cJSON_GetObjectItemCaseSensitive(first, "errorCode");
    if (!cJSON_IsString(code)) {
        code = cJSON_GetObjectItemCaseSensitive(first, "error_code");
    }
    int found = 0;
    for (; cJSON_IsString(code) && *codes; codes++) {
        if (strcmp(code->valuestring, *codes) == 0) {
            found = 1;
            break;
        }
    }
    cJSON_Delete(body);
    return found;
}

enum { PROBE_FAILED, PROBE_SUCCESS, PROBE_EXPECTED_ERROR };

// Counts an expected-error probe: passes on success or on one of codes.
static int expect_codes(int returned, const char *msg, const char *const *codes) {
    checks++;
    if (returned) {
        return PROBE_SUCCESS;
    }
    if (has_code(codes)) {
        return PROBE_EXPECTED_ERROR;
    }
    fail_call(msg);
    return PROBE_FAILED;
}

// Prints Python's "[ok] <name>: ..." line for a passing algo-name probe.
static void report_algo(int result, const char *name) {
    if (result == PROBE_SUCCESS) {
        printf("[ok] %s: Success\n", name);
    } else if (result == PROBE_EXPECTED_ERROR) {
        printf("[ok] %s: Expected error response\n", name);
    }
}

#define CODES(...) ((const char *const[]){__VA_ARGS__, NULL})
#define GOOD(type, r) ((r)->status == upstox_client_##type##_STATUS_success && (r)->data != NULL)

// A call that must succeed with status success and non-NULL data.
#define OK(type, call, exc_msg, msg) OK_IF(type, call, 1, exc_msg, msg)

// OK plus an extra condition on the response r_.
#define OK_IF(type, call, cond, exc_msg, msg)                                     \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        check_response(r_ != NULL, r_ != NULL && GOOD(type, r_) && (cond), exc_msg, msg); \
        type##_free(r_);                                                          \
    } while (0)

// An expected-error probe; a successful response is printed like Python's print(api_response).
#define EXPECT(type, call, msg, ...)                                              \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        if (expect_codes(r_ != NULL, msg, CODES(__VA_ARGS__)) == PROBE_SUCCESS) { \
            show_json("", type##_convertToJSON(r_));                              \
        }                                                                         \
        type##_free(r_);                                                          \
    } while (0)

// EXPECT for the algo-name block, printing Python's "[ok]" lines.
#define EXPECT_ALGO(type, call, name, msg, ...)                                   \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        report_algo(expect_codes(r_ != NULL, msg, CODES(__VA_ARGS__)), name);    \
        type##_free(r_);                                                          \
    } while (0)

// An expected-error probe whose success must also have status success and data.
#define EXPECT_OK(type, call, msg, status_msg, ...)                               \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        if (expect_codes(r_ != NULL, msg, CODES(__VA_ARGS__)) == PROBE_SUCCESS && !GOOD(type, r_)) { \
            fail_msg(status_msg);                                                 \
        }                                                                         \
        type##_free(r_);                                                          \
    } while (0)

// Prints the response after label; an error counts as a failure only when err_fails.
#define SHOW(type, call, label, exc_msg, err_fails)                               \
    do {                                                                          \
        type##_t *r_ = (call);                                                    \
        checks++;                                                                 \
        if (r_ != NULL) {                                                         \
            show_json(label, type##_convertToJSON(r_));                           \
        } else if (err_fails) {                                                   \
            fail_call(exc_msg);                                                   \
        } else {                                                                  \
            printf("%s: HTTP %ld %s\n", exc_msg, c->response_code, c->errorBody ? c->errorBody : ""); \
        }                                                                         \
        type##_free(r_);                                                          \
    } while (0)

// ---- request and model building ---------------------------------------------

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

// Parses a JSON array into a new list of models.
#define PARSE_LIST(type, var, json)                                               \
    do {                                                                          \
        cJSON *j_ = cJSON_Parse(json), *e_;                                       \
        var = list_createList();                                                  \
        cJSON_ArrayForEach(e_, j_) {                                              \
            type##_t *m_ = type##_parseFromJSON(e_);                              \
            if (m_ == NULL) {                                                     \
                printf("could not build %s from %s\n", #type, json);              \
                continue;                                                         \
            }                                                                     \
            list_addElement(var, m_);                                             \
        }                                                                         \
        cJSON_Delete(j_);                                                         \
    } while (0)

#define FREE_LIST(type, var)                                                      \
    do {                                                                          \
        listEntry_t *e_;                                                          \
        list_ForEach(e_, var) {                                                   \
            type##_free(e_->data);                                                \
        }                                                                         \
        list_freeList(var);                                                       \
    } while (0)

// Builds a model from json and checks cond on it (as m_).
#define MODEL(type, json, cond, msg)                                              \
    do {                                                                          \
        type##_t *m_;                                                             \
        PARSE(type, m_, json);                                                    \
        check_model(m_ != NULL && (cond), msg);                                   \
        type##_free(m_);                                                          \
    } while (0)

// Python's "<Model>() is None" instantiation check.
#define MODEL_NEW(type, msg) MODEL(type, "{}", 1, msg)

// Python's "<Model>(status=\"success\")" status check.
#define MODEL_STATUS(type, msg) \
    MODEL(type, "{\"status\":\"success\"}", m_->status == upstox_client_##type##_STATUS_success, msg)

#define EQ_NUM(p, v) ((p) != NULL && *(p) == (v))
#define EQ_STR(p, s) ((p) != NULL && strcmp((p), (s)) == 0)
#define FIRST(type, list) ((type##_t *)list_first(list))

static void *list_first(list_t *l) {
    return (l != NULL && l->firstEntry != NULL) ? l->firstEntry->data : NULL;
}

// Mirrors Python's is_within_market_hours (09:00-15:30), in IST.
static int in_market_hours(void) {
    time_t now = time(NULL) + 5 * 3600 + 1800;
    struct tm t;
#ifdef _WIN32
    gmtime_s(&t, &now);
#else
    gmtime_r(&now, &t);
#endif
    int m = t.tm_hour * 60 + t.tm_min;
    return m >= 9 * 60 && m <= 15 * 60 + 30;
}

// ---- request bodies -----------------------------------------------------------

#define PLACE_ORDER_JSON                                                          \
    "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":5.0,\"tag\":\"string\","   \
    "\"instrument_token\":\"NSE_EQ|INE528G01035\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\"," \
    "\"disclosed_quantity\":0,\"trigger_price\":0.0,\"is_amo\":true}"

// Python's two-leg Vodafone Idea AMO basket; price is leg 1's limit price.
#define MULTI_ORDER_JSON(price)                                                   \
    "[{\"quantity\":1,\"product\":\"I\",\"validity\":\"DAY\",\"price\":" price ",\"tag\":\"kg_python_sdk\"," \
    "\"slice\":false,\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\"," \
    "\"disclosed_quantity\":0,\"trigger_price\":0,\"is_amo\":true,\"correlation_id\":\"1\"},"  \
    "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":8.9,\"tag\":\"kg_python_sdk1\"," \
    "\"slice\":false,\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\"," \
    "\"disclosed_quantity\":0,\"trigger_price\":0,\"is_amo\":true,\"correlation_id\":\"2\"}]"

#define MODIFY_ORDER_JSON(qty, price, id)                                         \
    "{\"quantity\":" qty ",\"validity\":\"DAY\",\"price\":" price ",\"order_id\":\"" id "\","  \
    "\"order_type\":\"LIMIT\",\"disclosed_quantity\":0,\"trigger_price\":0}"

#define PLACE_V3_JSON                                                             \
    "{\"quantity\":1,\"product\":\"D\",\"validity\":\"DAY\",\"price\":9.12,\"tag\":\"string\"," \
    "\"instrument_token\":\"" IDEA_KEY "\",\"order_type\":\"LIMIT\",\"transaction_type\":\"BUY\"," \
    "\"disclosed_quantity\":0,\"trigger_price\":0.0,\"is_amo\":true,\"slice\":true}"

// Python's three-leg GTT on Vodafone Idea with the given entry trigger.
#define GTT_JSON(entry_type, entry)                                               \
    "{\"type\":\"MULTIPLE\",\"instrument_token\":\"" IDEA_KEY "\",\"product\":\"D\",\"quantity\":1," \
    "\"transaction_type\":\"BUY\",\"rules\":["                                    \
    "{\"strategy\":\"ENTRY\",\"trigger_type\":\"" entry_type "\",\"trigger_price\":" entry "}," \
    "{\"strategy\":\"TARGET\",\"trigger_type\":\"IMMEDIATE\",\"trigger_price\":9}," \
    "{\"strategy\":\"STOPLOSS\",\"trigger_type\":\"IMMEDIATE\",\"trigger_price\":5}]}"

// Python's entry/target/trailing-stop rules for the MTF GTT.
#define TSL_RULES_JSON                                                            \
    "[{\"strategy\":\"ENTRY\",\"trigger_type\":\"BELOW\",\"trigger_price\":60},"  \
    "{\"strategy\":\"TARGET\",\"trigger_type\":\"IMMEDIATE\",\"trigger_price\":90}," \
    "{\"strategy\":\"STOPLOSS\",\"trigger_type\":\"IMMEDIATE\",\"trigger_price\":50,\"trailing_gap\":3}]"

#define TSL_GTT_JSON                                                              \
    "{\"type\":\"MULTIPLE\",\"instrument_token\":\"NSE_EQ|INE584A01023\",\"product\":\"MTF\",\"quantity\":1," \
    "\"transaction_type\":\"BUY\",\"rules\":" TSL_RULES_JSON "}"

// Non-existent IDs Python uses for not-found probes.
#define MISSING_GTT_MODIFY_JSON                                                   \
    "{\"type\":\"MULTIPLE\",\"gtt_order_id\":\"GTT-C2503030018840\",\"quantity\":2,\"rules\":" TSL_RULES_JSON "}"
#define MISSING_GTT_CANCEL_JSON "{\"gtt_order_id\":\"GTT-C250303008840\"}"
#define MISSING_V3_MODIFY_JSON MODIFY_ORDER_JSON("1", "9.12", "25030310405859")
#define MISSING_V3_CANCEL_ID "2501211050101"

#define US_ESTIMATE_JSON \
    "{\"quantity\":1,\"instrument_key\":\"US_EQ|COUR\",\"transaction_type\":\"BUY\",\"order_type\":\"MARKET\"}"

// ---- sections, in sanity.py order ----------------------------------------------

// UserApi block: profile, funds, static IPs and kill switch.
static void user(void) {
    OK(get_profile_response, UserAPI_getProfile(c),
       "Exception when calling UserApi->get_user_fund_margin", "error in get profile API");
    OK(get_user_fund_margin_response, UserAPI_getUserFundMargin(c, upstox_client_getUserFundMargin_SEGMENT_NULL),
       "Exception when calling UserApi->get_user_fund_margin", "Wrong response from get funds and margin");
    OK(get_user_fund_margin_v3_response, UserAPI_getUserFundMarginV3(c),
       "Exception when calling UserApi->get_user_fund_margin_v3", "Wrong response from get_user_fund_margin_v3");
    OK(user_ip_response, UserAPI_getUserIps(c),
       "Exception when calling UserApi->get_user_ips", "Wrong response from get_user_ips");

    update_user_ip_request_t *ip;
    PARSE(update_user_ip_request, ip, "{\"primary_ip\":\"1.2.3.4\"}");
    EXPECT_OK(user_ip_response, UserAPI_updateUserIp(c, ip),
              "update_user_ip giving wrong response", "Wrong response from update_user_ip", "UDAPI100068", "UDAPI100069");
    update_user_ip_request_free(ip);

    OK(kill_switch_response, UserAPI_getKillSwitch(c),
       "Exception when calling UserApi->get_kill_switch", "Wrong response from get_kill_switch");

    list_t *ks;
    PARSE_LIST(kill_switch_segment_update_request, ks, "[{\"segment\":\"NSE_EQ\",\"action\":\"DISABLE\"}]");
    OK(kill_switch_response, UserAPI_updateKillSwitch(c, ks),
       "Exception when calling UserApi->update_kill_switch", "Wrong response from update_kill_switch");
    FREE_LIST(kill_switch_segment_update_request, ks);
}

// ChargeApi block: brokerage and margin.
static void charge(void) {
    OK_IF(get_brokerage_response, ChargeAPI_getBrokerage(c, IDEA_KEY, &(int){10}, "D", "BUY", 13.4),
          r_->data->charges != NULL,
          "Exception when calling ChargeApi->get_brokerage", "Brokerage giving wrong response");

    margin_request_t *margin;
    PARSE(margin_request, margin, "{\"instruments\":["
          "{\"instrument_key\":\"NSE_EQ|INE528G01035\",\"quantity\":12,\"product\":\"D\",\"transaction_type\":\"BUY\"},"
          "{\"instrument_key\":\"NSE_EQ|INE002A01018\",\"quantity\":1,\"product\":\"D\",\"transaction_type\":\"BUY\"}]}");
    OK(post_margin_response, ChargeAPI_postMargin(c, margin), "Exception when calling Margin API", "error in margin api");
    margin_request_free(margin);
}

// OrderApi (v2) block.
static void orders(void) {
    place_order_request_t *place;
    PARSE(place_order_request, place, PLACE_ORDER_JSON);
    place_order_response_t *placed = OrderAPI_placeOrder(c, place, ALGO);
    checks++;
    if (placed != NULL) {
        if (in_market_hours() && !GOOD(place_order_response, placed)) {
            fail_msg("error in place order");
        }
    } else if (!(c->response_code == 400 && in_market_hours())) {
        // Python tolerates a 400 only inside market hours
        fail_call("exception in place order");
    }
    place_order_response_free(placed);
    place_order_request_free(place);

    modify_order_request_t *modify;
    PARSE(modify_order_request, modify, MODIFY_ORDER_JSON("7", "0", "231222010275930"));
    EXPECT(modify_order_response, OrderAPI_modifyOrder(c, modify, ALGO), "modify order giving wrong response", "UDAPI100010");
    modify_order_request_free(modify);

    EXPECT(cancel_or_exit_multi_order_response, OrderAPI_cancelMultiOrder(c, PYTHON_TAG, NULL, ALGO),
           "cancel multi giving wrong response", "UDAPI1109");
    EXPECT(cancel_or_exit_multi_order_response, OrderAPI_exitPositions(c, PYTHON_TAG, NULL, ALGO),
           "exit position giving wrong response", "UDAPI1111", "UDAPI1113");

    list_t *multi;
    PARSE_LIST(multi_order_request, multi, MULTI_ORDER_JSON("5"));
    SHOW(multi_order_response, OrderAPI_placeMultiOrder(c, multi, NULL, ALGO),
         "multi_order=>  ", "Exception when calling OrderApi->multi_place_order", 1);
    FREE_LIST(multi_order_request, multi);

    EXPECT(get_order_details_response, OrderAPI_getOrderStatus(c, "240925010636040"),
           "order details giving wrong response", "UDAPI100010");
    EXPECT(cancel_order_response, OrderAPI_cancelOrder(c, "231221011081579", ALGO),
           "cancel order giving wrong response", "UDAPI100010");
    OK(get_order_book_response, OrderAPI_getOrderBook(c),
       "Exception when calling OrderApi->get_order_book", "get order book giving invalid data");
    EXPECT(get_order_response, OrderAPI_getOrderDetails(c, "240112010371054", NULL),
           "get order details giving wrong response", "UDAPI100010");
    OK(get_trade_response, OrderAPI_getTradeHistory(c),
       "Exception when calling OrderApi->get_trade_history", "get order book giving invalid data");
    OK(get_trade_response, OrderAPI_getTradesByOrder(c, "240112010371054"),
       "Exception when calling OrderApi->get_trades_by_order", "get order book giving invalid data");
}

// PortfolioApi block: convert positions, holdings, positions.
static void portfolio(void) {
    convert_position_request_t *convert;
    PARSE(convert_position_request, convert, "{\"instrument_token\":\"NSE_EQ|INE528G01035\",\"quantity\":1,"
          "\"new_product\":\"D\",\"old_product\":\"I\",\"transaction_type\":\"BUY\"}");
    EXPECT(convert_position_response, PortfolioAPI_convertPositions(c, convert), "convert position giving error", "UDAPI1035");
    convert_position_request_free(convert);

    OK(get_holdings_response, PortfolioAPI_getHoldings(c), "Exception when holding api", "get holding giving wrong response");
    OK(get_position_response, PortfolioAPI_getPositions(c), "Exception when calling position", "get position giving wrong response");
}

// TradeProfitAndLossApi block for FY 2023-24.
static void profit_and_loss(void) {
    const char *exc = "Exception when calling TradeProfitAndLossApi->get_trade_wise_profit_and_loss_data";
    OK(get_trade_wise_profit_and_loss_meta_data_response,
       TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData(c, "EQ", "2324", "02-04-2023", "20-03-2024"),
       exc, "get report meta data giving wrong response");
    OK(get_trade_wise_profit_and_loss_data_response,
       TradeProfitAndLossAPI_getTradeWiseProfitAndLossData(c, "EQ", "2324", &(int){1}, &(int){4}, "02-04-2023", "20-03-2024"),
       exc, "get profit loss report data giving wrong response");
    OK(get_profit_and_loss_charges_response,
       TradeProfitAndLossAPI_getProfitAndLossCharges(c, "EQ", "2324", "02-04-2023", "20-03-2024"),
       exc, "get trade charges giving wrong response");
}

// HistoryApi (v2) block.
static void history(void) {
    const char *exc = "Exception when calling HistoryApi->get_historical_candle_data";
    OK(get_historical_candle_response, HistoryAPI_getHistoricalCandleDataRange(c, IDEA_KEY, "1minute", "2023-11-13", "2023-11-12"),
       exc, "historical api not giving success");
    OK(get_intra_day_candle_response, HistoryAPI_getIntraDayCandleData(c, IDEA_KEY, "1minute"),
       exc, "historical intraday api not giving success");
}

// MarketQuoteApi (v2) block; Python passes the key as "symbol".
static void market_quote(void) {
    const char *exc = "Exception when calling MarketQuoteApi->get_full_market_quote";
    OK(get_full_market_quote_response, MarketQuoteAPI_getFullMarketQuote(c, IDEA_KEY, NULL),
       exc, "market quotes full api not giving success");
    OK(get_market_quote_last_traded_price_response, MarketQuoteAPI_ltp(c, IDEA_KEY, NULL),
       exc, "market quotes ltp api not giving success");
    OK(get_market_quote_ohlc_response, MarketQuoteAPI_getMarketQuoteOHLC(c, "1d", IDEA_KEY, NULL),
       exc, "market quotes ohlc api not giving success");
}

// MarketHolidaysAndTimingsApi block.
static void market_timings(void) {
    const char *exc = "Exception when calling MarketHolidaysAndTimingsApi";
    OK(get_holiday_response, MarketHolidaysAndTimingsAPI_getHolidays(c), exc, "error in get holidays");
    OK(get_holiday_response, MarketHolidaysAndTimingsAPI_getHoliday(c, "2024-01-22"), exc, "error in get holiday on a date");
    OK(get_exchange_timing_response, MarketHolidaysAndTimingsAPI_getExchangeTimings(c, "2024-01-22"), exc, "error get exchange timings");
    OK(get_market_status_response, MarketHolidaysAndTimingsAPI_getMarketStatus(c, "NSE"), exc, "error get market status");
}

// OrderApiV3 block: GTT orders and v3 place/modify/cancel.
static void order_v3(void) {
    gtt_place_order_request_t *gtt;
    PARSE(gtt_place_order_request, gtt, GTT_JSON("ABOVE", "7"));
    SHOW(gtt_trigger_order_response, OrderV3API_placeGTTOrder(c, gtt, NULL, ALGO),
         " gtt_order => ", "Exception when calling OrderApi->gtt_place_order", 1);
    gtt_place_order_request_free(gtt);

    PARSE(gtt_place_order_request, gtt, TSL_GTT_JSON);
    SHOW(gtt_trigger_order_response, OrderV3API_placeGTTOrder(c, gtt, NULL, ALGO),
         " tsl gtt_order => ", "Exception when calling OrderApi->place_order", 1);
    gtt_place_order_request_free(gtt);

    gtt_modify_order_request_t *gtt_modify;
    PARSE(gtt_modify_order_request, gtt_modify, MISSING_GTT_MODIFY_JSON);
    EXPECT(gtt_trigger_order_response, OrderV3API_modifyGTTOrder(c, gtt_modify, NULL, ALGO), "modify gtt giving error", "UDAPI100010");
    gtt_modify_order_request_free(gtt_modify);

    gtt_cancel_order_request_t *gtt_cancel;
    PARSE(gtt_cancel_order_request, gtt_cancel, MISSING_GTT_CANCEL_JSON);
    EXPECT(gtt_trigger_order_response, OrderV3API_cancelGTTOrder(c, gtt_cancel, NULL, ALGO), "cancel gtt giving error", "UDAPI100010");
    gtt_cancel_order_request_free(gtt_cancel);

    // Python's message here really is "get_option_contracts giving error"
    OK(get_gtt_order_response, OrderV3API_getGttOrderDetails(c, "GTT-C25030300128840"),
       "Exception when calling OrderApi->get_gtt_order_details", "get_option_contracts giving error");

    place_order_v3_request_t *place;
    PARSE(place_order_v3_request, place, PLACE_V3_JSON);
    SHOW(place_order_v3_response, OrderV3API_placeOrder(c, place, ALGO),
         "place order v3 => ", "Exception when calling OrderApi->place_orderV3", 1);
    place_order_v3_request_free(place);

    modify_order_request_t *modify;
    PARSE(modify_order_request, modify, MISSING_V3_MODIFY_JSON);
    EXPECT(modify_order_v3_response, OrderV3API_modifyOrder(c, modify, ALGO), "modify v3 giving error", "UDAPI100010");
    modify_order_request_free(modify);

    EXPECT(cancel_order_v3_response, OrderV3API_cancelOrder(c, MISSING_V3_CANCEL_ID, ALGO), "cancel v3 giving error", "UDAPI100010");
}

// OptionsApi block.
static void options(void) {
    const char *exc = "Exception when calling MarketHolidaysAndTimingsApi";
    OK(get_option_contract_response, OptionsAPI_getOptionContracts(c, NIFTY_KEY, NULL), exc, "get_option_contracts giving error");
    OK(get_option_chain_response, OptionsAPI_getPutCallOptionChain(c, NIFTY_KEY, "2024-03-21"), exc,
       "get_put_call_option_chain giving error");
}

// LoginApi.token probe with placeholder credentials; Python's message really is "convert position giving error".
static void login_token(void) {
    EXPECT(token_response, LoginAPI_token(c, "{your_auth_code}", "{your_client_id}", "{your_client_secret}",
                                          "{your_redirect_url}", "grant_type_example", NULL),
           "convert position giving error", "UDAPI100069");
}

// PostTradeApi call.
static void post_trade(void) {
    OK(trade_history_response, PostTradeAPI_getTradesByDateRange(c, "2023-04-01", "2024-03-31", &(int){1}, &(int){1000}, NULL),
       "Exception when calling PostTrade api", "error in post trade api");
}

// get_mtf_positions call.
static void mtf_positions(void) {
    OK(get_position_response, PortfolioAPI_getMtfPositions(c), "Exception when calling mtf positions", "error in get mtf positions api");
}

// HistoryV3Api block.
static void history_v3(void) {
    const char *exc = "Exception when calling historical v3 api";
    OK(get_historical_candle_response, HistoryV3API_getHistoricalCandleData(c, IDEA_KEY, "minutes", &(int){1}, "2025-01-02"),
       exc, "error in get_historical_candle_data api");
    OK(get_historical_candle_response,
       HistoryV3API_getHistoricalCandleDataRange(c, IDEA_KEY, "minutes", &(int){1}, "2025-01-02", "2025-01-02"),
       exc, "error in get_historical_candle_data1 api");
    OK(get_intra_day_candle_response, HistoryV3API_getIntraDayCandleData(c, IDEA_KEY, "minutes", &(int){1}),
       exc, "error in get_intra_day_candle_data api");
}

// MarketQuoteV3Api block; Python reuses the ohlc message for option greeks.
static void market_quote_v3(void) {
    const char *exc = "Exception when calling market quote v3 api";
    OK(get_market_quote_ohlc_response_v3, MarketQuoteV3API_getMarketQuoteOHLC(c, "I1", IDEA_KEY),
       exc, "error in get_market_quote_ohlc api");
    OK(get_market_quote_option_greek_response_v3, MarketQuoteV3API_getMarketQuoteOptionGreek(c, "NSE_FO|38604,NSE_FO|49210"),
       exc, "error in get_market_quote_ohlc api");
    OK(get_market_quote_last_traded_price_response_v3, MarketQuoteV3API_getLtp(c, IDEA_KEY), exc, "error in get_ltp api");
}

// ExpiredInstrumentApi block.
static void expired_instruments(void) {
    const char *exc = "Exception when calling expired instrument v3 api";
    OK(get_expiries_response, ExpiredInstrumentAPI_getExpiries(c, NIFTY_KEY), exc, "error in get_expiries");
    OK(get_option_contract_response, ExpiredInstrumentAPI_getExpiredOptionContracts(c, NIFTY_KEY, "2025-04-30"),
       exc, "error in get_expired_option_contracts");
    OK(get_expired_futures_contract_response, ExpiredInstrumentAPI_getExpiredFutureContracts(c, NIFTY_KEY, "2025-04-24"),
       exc, "error in get_expired_future_contracts");
    OK(get_historical_candle_response,
       ExpiredInstrumentAPI_getExpiredHistoricalCandleData(c, "NSE_FO|54452|24-04-2025", "1minute", "2025-04-24", "2025-04-24"),
       exc, "error in get_expired_historical_candle_data");
}

// "ALGO ID TESTS" block: every order write again, with X-Algo-Name.
static void algo_name(void) {
    printf("\n=== Starting Algo ID Tests ===\n");
    printf("\n--- OrderApi (V2) Tests with algo_name ---\n");

    place_order_request_t *place;
    PARSE(place_order_request, place, PLACE_ORDER_JSON);
    place_order_response_t *placed = OrderAPI_placeOrder(c, place, ALGO);
    int market = in_market_hours();
    checks++;
    if (placed != NULL && !market) {
        printf("[ok] place_order V2 with algo_name: Called successfully (outside market hours)\n");
    } else if (placed != NULL && !GOOD(place_order_response, placed)) {
        fail_msg("error in place order with algo_name");
    } else if (placed != NULL) {
        printf("[ok] place_order V2 with algo_name: Success\n");
    } else if (c->response_code == 400 && !market) {
        printf("[ok] place_order V2 with algo_name: Expected exception outside market hours\n");
    } else {
        fail_call("exception in place order with algo_name");
    }
    place_order_response_free(placed);
    place_order_request_free(place);

    modify_order_request_t *modify;
    PARSE(modify_order_request, modify, MODIFY_ORDER_JSON("2", "5", "231222010275930"));
    EXPECT_ALGO(modify_order_response, OrderAPI_modifyOrder(c, modify, ALGO), "modify_order V2 with algo_name",
                "modify order with algo_name giving wrong response", "UDAPI100010");
    modify_order_request_free(modify);

    EXPECT_ALGO(cancel_or_exit_multi_order_response, OrderAPI_cancelMultiOrder(c, PYTHON_TAG, NULL, ALGO),
                "cancel_multi_order V2 with algo_name", "cancel multi with algo_name giving wrong response", "UDAPI1109");
    EXPECT_ALGO(cancel_or_exit_multi_order_response, OrderAPI_exitPositions(c, PYTHON_TAG, NULL, ALGO),
                "exit_positions V2 with algo_name", "exit position with algo_name giving wrong response",
                "UDAPI1111", "UDAPI1113");

    list_t *multi;
    PARSE_LIST(multi_order_request, multi, MULTI_ORDER_JSON("4"));
    SHOW(multi_order_response, OrderAPI_placeMultiOrder(c, multi, NULL, ALGO),
         "[ok] place_multi_order V2 with algo_name: Success - ", "[ok] place_multi_order V2 with algo_name: Exception handled", 0);
    FREE_LIST(multi_order_request, multi);

    EXPECT_ALGO(cancel_order_response, OrderAPI_cancelOrder(c, "231221011081579", ALGO), "cancel_order V2 with algo_name",
                "cancel order V2 with algo_name giving wrong response", "UDAPI100010");

    printf("\n--- OrderApiV3 Tests with algo_name ---\n");

    place_order_v3_request_t *place_v3;
    PARSE(place_order_v3_request, place_v3, PLACE_V3_JSON);
    SHOW(place_order_v3_response, OrderV3API_placeOrder(c, place_v3, ALGO),
         "[ok] place_order V3 with algo_name: Success - ", "[ok] place_order V3 with algo_name: Exception handled", 0);
    place_order_v3_request_free(place_v3);

    PARSE(modify_order_request, modify, MISSING_V3_MODIFY_JSON);
    EXPECT_ALGO(modify_order_v3_response, OrderV3API_modifyOrder(c, modify, ALGO), "modify_order V3 with algo_name",
                "modify V3 with algo_name giving error", "UDAPI100010");
    modify_order_request_free(modify);

    EXPECT_ALGO(cancel_order_v3_response, OrderV3API_cancelOrder(c, MISSING_V3_CANCEL_ID, ALGO), "cancel_order V3 with algo_name",
                "cancel V3 with algo_name giving error", "UDAPI100010");

    printf("\n--- GTT Tests with algo_name ---\n");

    gtt_place_order_request_t *gtt;
    PARSE(gtt_place_order_request, gtt, GTT_JSON("BELOW", "6"));
    SHOW(gtt_trigger_order_response, OrderV3API_placeGTTOrder(c, gtt, NULL, ALGO),
         "[ok] place_gtt_order with algo_name: Success - ", "[ok] place_gtt_order with algo_name: Exception handled", 0);
    gtt_place_order_request_free(gtt);

    PARSE(gtt_place_order_request, gtt, TSL_GTT_JSON);
    SHOW(gtt_trigger_order_response, OrderV3API_placeGTTOrder(c, gtt, NULL, ALGO),
         "[ok] place_gtt_order (TSL) with algo_name: Success - ", "[ok] place_gtt_order (TSL) with algo_name: Exception handled", 0);
    gtt_place_order_request_free(gtt);

    gtt_modify_order_request_t *gtt_modify;
    PARSE(gtt_modify_order_request, gtt_modify, MISSING_GTT_MODIFY_JSON);
    EXPECT_ALGO(gtt_trigger_order_response, OrderV3API_modifyGTTOrder(c, gtt_modify, NULL, ALGO), "modify_gtt_order with algo_name",
                "modify gtt with algo_name giving error", "UDAPI100010");
    gtt_modify_order_request_free(gtt_modify);

    gtt_cancel_order_request_t *gtt_cancel;
    PARSE(gtt_cancel_order_request, gtt_cancel, MISSING_GTT_CANCEL_JSON);
    EXPECT_ALGO(gtt_trigger_order_response, OrderV3API_cancelGTTOrder(c, gtt_cancel, NULL, ALGO), "cancel_gtt_order with algo_name",
                "cancel gtt with algo_name giving error", "UDAPI100010");
    gtt_cancel_order_request_free(gtt_cancel);

    printf("\n=== Algo ID Tests Complete ===\n");
}

// InstrumentsApi.search_instrument block.
static void instruments(void) {
    OK(search_instrument_response, InstrumentsAPI_searchInstrument(c, "Nifty 50", NULL, NULL, NULL, NULL, NULL, NULL, NULL),
       "Exception when calling InstrumentsApi->search_instrument", "error in search_instrument basic query");
    OK(search_instrument_response, InstrumentsAPI_searchInstrument(c, "Reliance", "NSE", NULL, NULL, NULL, NULL, NULL, NULL),
       "Exception when calling InstrumentsApi->search_instrument with exchange", "error in search_instrument with exchange filter");
    OK(search_instrument_response, InstrumentsAPI_searchInstrument(c, "TCS", NULL, "EQ", NULL, NULL, NULL, NULL, NULL),
       "Exception when calling InstrumentsApi->search_instrument with segment", "error in search_instrument with segment filter");
    OK(search_instrument_response, InstrumentsAPI_searchInstrument(c, "Nifty", NULL, NULL, "INDEX", NULL, NULL, NULL, NULL),
       "Exception when calling InstrumentsApi->search_instrument with instrument_types",
       "error in search_instrument with instrument type filter");
    OK(search_instrument_response,
       InstrumentsAPI_searchInstrument(c, "HDFC", NULL, NULL, NULL, NULL, NULL, &(int){1}, &(int){5}),
       "Exception when calling InstrumentsApi->search_instrument with pagination", "error in search_instrument with pagination");
}

// NewsApi block.
static void news(void) {
    OK(get_news_response, NewsAPI_getNews(c, "instrument_keys", IDEA_KEY, NULL, NULL),
       "Exception when calling NewsApi->get_news with instrument_keys", "error in get_news with instrument_keys category");
    OK(get_news_response, NewsAPI_getNews(c, "positions", NULL, NULL, NULL),
       "Exception when calling NewsApi->get_news with positions", "error in get_news with positions category");
    OK(get_news_response, NewsAPI_getNews(c, "holdings", NULL, NULL, NULL),
       "Exception when calling NewsApi->get_news with holdings", "error in get_news with holdings category");
    OK(get_news_response, NewsAPI_getNews(c, "instrument_keys", "NSE_EQ|INE040A01034", &(int){1}, &(int){5}),
       "Exception when calling NewsApi->get_news with pagination", "error in get_news with pagination");
}

// NewsItemData / GetNewsResponse field checks; published_time is epoch millis in C (2026-04-20T10:00:00Z).
#define NEWS_ITEM_JSON                                                            \
    "{\"heading\":\"Test heading\",\"summary\":\"Test summary\",\"thumbnail\":\"https://example.com/thumb.jpg\"," \
    "\"article_link\":\"https://example.com/article\",\"published_time\":1776679200000}"

static void news_models(void) {
    MODEL(news_item_data, NEWS_ITEM_JSON, EQ_STR(m_->heading, "Test heading"),
          "error: NewsItemData heading field not set correctly");
    MODEL(news_item_data, NEWS_ITEM_JSON, EQ_STR(m_->summary, "Test summary"),
          "error: NewsItemData summary field not set correctly");
    MODEL(news_item_data, NEWS_ITEM_JSON, EQ_STR(m_->article_link, "https://example.com/article"),
          "error: NewsItemData article_link field not set correctly");
    // C's data is a map keyed by instrument, as the API returns it
    MODEL(get_news_response, "{\"status\":\"success\",\"data\":{\"" IDEA_KEY "\":[" NEWS_ITEM_JSON "]}}",
          m_->status == upstox_client_get_news_response_STATUS_success,
          "error: GetNewsResponse status field not set correctly");

    // Python only instantiates these two, without a check
    news_response_meta_data_t *meta;
    news_response_page_data_t *page;
    PARSE(news_response_meta_data, meta, "{}");
    PARSE(news_response_page_data, page, "{}");
    news_response_meta_data_free(meta);
    news_response_page_data_free(page);
}

// init_token_request_for_indie_user probe with a fake client id.
static void indie_token(void) {
    indie_user_token_request_t *body;
    PARSE(indie_user_token_request, body, "{\"client_secret\":\"9rmbdvjsb\"}");
    EXPECT(indie_user_init_token_response,
           LoginAPI_initTokenRequestForIndieUser(c, "fd33050-ac87-4ecb-b4e1-4ec994c70c32", body),
           "indie token request giving error", "UDAPI100069");
    indie_user_token_request_free(body);
}

// MutualFundApi block.
static void mutual_funds(void) {
    OK(get_mutual_fund_holdings_response, MutualFundAPI_getMutualFundHoldings(c),
       "Exception when calling MutualFundApi->get_mutual_fund_holdings", "error in get_mutual_fund_holdings");
    OK(get_mutual_fund_orders_response, MutualFundAPI_getMutualFundOrders(c, NULL, NULL, NULL, NULL),
       "Exception when calling MutualFundApi->get_mutual_fund_orders", "error in get_mutual_fund_orders");
    OK(get_mutual_fund_orders_response, MutualFundAPI_getMutualFundOrders(c, "COMPLETED", "BUY", &(int){1}, &(int){10}),
       "Exception when calling MutualFundApi->get_mutual_fund_orders (filtered)", "error in get_mutual_fund_orders with filters");
    EXPECT_OK(get_mutual_fund_order_details_response, MutualFundAPI_getMutualFundOrder(c, "MF-ORDER-001"),
              "get_mutual_fund_order giving wrong error response", "error in get_mutual_fund_order", "UDAPI100010", "UDAPI100050");
    OK(get_mutual_fund_sips_response, MutualFundAPI_getMutualFundSips(c, NULL, NULL),
       "Exception when calling MutualFundApi->get_mutual_fund_sips", "error in get_mutual_fund_sips");
    OK(get_mutual_fund_sips_response, MutualFundAPI_getMutualFundSips(c, &(int){1}, &(int){10}),
       "Exception when calling MutualFundApi->get_mutual_fund_sips (paginated)", "error in get_mutual_fund_sips with pagination");
}

// Mutual fund model instantiation checks.
static void mutual_fund_models(void) {
    MODEL_NEW(mutual_fund_holding_data, "error: MutualFundHoldingData instantiation failed");
    MODEL_NEW(mutual_fund_meta_data, "error: MutualFundMetaData instantiation failed");
    MODEL_NEW(mutual_fund_order_data, "error: MutualFundOrderData instantiation failed");
    MODEL_NEW(mutual_fund_sip_data, "error: MutualFundSipData instantiation failed");
    MODEL_NEW(family_member_data, "error: FamilyMemberData instantiation failed");
    MODEL_NEW(pagination, "error: Pagination instantiation failed");
    MODEL_NEW(get_mutual_fund_holdings_response, "error: GetMutualFundHoldingsResponse instantiation failed");
    MODEL_NEW(get_mutual_fund_orders_response, "error: GetMutualFundOrdersResponse instantiation failed");
    MODEL_NEW(get_mutual_fund_order_details_response, "error: GetMutualFundOrderDetailsResponse instantiation failed");
    MODEL_NEW(get_mutual_fund_sips_response, "error: GetMutualFundSipsResponse instantiation failed");
}

// Pay-in/pay-out history block.
static void payments(void) {
    OK(payment_history_response, UserAPI_getPayinHistory(c),
       "Exception when calling UserApi->get_payin_history", "error in get_payin_history");
    OK(payment_history_response, UserAPI_getPayoutHistory(c),
       "Exception when calling UserApi->get_payout_history", "error in get_payout_history");
}

#define PAYMENT_JSON                                                              \
    "{\"amount\":1000.0,\"mode\":\"NEFT\",\"status\":\"SUCCESS\",\"last_updated_at\":\"2026-05-04T10:00:00Z\"," \
    "\"bank_name\":\"Test Bank\",\"transaction_id\":\"TXN123456\",\"total_charges\":0.0,\"charges_category\":\"PAYIN\"}"

// PaymentHistoryData / PaymentHistoryResponse checks.
static void payment_models(void) {
    MODEL_NEW(payment_history_data, "error: PaymentHistoryData instantiation failed");
    MODEL(payment_history_data, PAYMENT_JSON, EQ_NUM(m_->amount, 1000.0),
          "error: PaymentHistoryData amount field not set correctly");
    MODEL(payment_history_data, PAYMENT_JSON, EQ_STR(m_->mode, "NEFT"),
          "error: PaymentHistoryData mode field not set correctly");
    MODEL(payment_history_data, PAYMENT_JSON, EQ_STR(m_->transaction_id, "TXN123456"),
          "error: PaymentHistoryData transaction_id field not set correctly");
    MODEL_NEW(payment_history_response, "error: PaymentHistoryResponse instantiation failed");
    MODEL(payment_history_response, "{\"status\":\"success\",\"data\":[" PAYMENT_JSON "]}",
          m_->status == upstox_client_payment_history_response_STATUS_success,
          "error: PaymentHistoryResponse status field not set correctly");
}

// FundamentalsApi block for Vodafone Idea.
static void fundamentals(void) {
    char *isin = "INE669E01016";
    OK(company_profile_response, FundamentalsAPI_getCompanyProfile(c, isin),
       "Exception when calling FundamentalsApi->get_company_profile", "FundamentalsApi->get_company_profile not returning success");
    OK(key_ratios_response, FundamentalsAPI_getKeyRatios(c, isin),
       "Exception when calling FundamentalsApi->get_key_ratios", "FundamentalsApi->get_key_ratios not returning success");
    OK(balance_sheet_response, FundamentalsAPI_getBalanceSheet(c, isin, NULL, NULL),
       "Exception when calling FundamentalsApi->get_balance_sheet", "FundamentalsApi->get_balance_sheet not returning success");
    OK(income_statement_response, FundamentalsAPI_getIncomeStatement(c, isin, NULL, NULL, NULL),
       "Exception when calling FundamentalsApi->get_income_statement", "FundamentalsApi->get_income_statement not returning success");
    OK(cash_flow_response, FundamentalsAPI_getCashFlow(c, isin, NULL, NULL),
       "Exception when calling FundamentalsApi->get_cash_flow", "FundamentalsApi->get_cash_flow not returning success");
    OK(competitors_response, FundamentalsAPI_getCompetitors(c, IDEA_KEY),
       "Exception when calling FundamentalsApi->get_competitors", "FundamentalsApi->get_competitors not returning success");
    OK(corporate_actions_response, FundamentalsAPI_getCorporateActions(c, isin),
       "Exception when calling FundamentalsApi->get_corporate_actions", "FundamentalsApi->get_corporate_actions not returning success");
    OK(share_holdings_response, FundamentalsAPI_getShareHoldings(c, isin),
       "Exception when calling FundamentalsApi->get_share_holdings", "FundamentalsApi->get_share_holdings not returning success");
}

// Python's MarketApi (OI, PCR, max pain, FII/DII) lives in C's MarketHolidaysAndTimingsAPI.
static void market_analytics(void) {
    char *expiry = "2026-05-29", *date = "2026-05-12";
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getOiData(c, NIFTY_KEY, expiry, date),
       "Exception when calling MarketApi->get_oi_data", "MarketApi->get_oi_data not returning success");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getChangeOiData(c, NIFTY_KEY, expiry, date, &(int){5}),
       "Exception when calling MarketApi->get_change_oi_data", "MarketApi->get_change_oi_data not returning success");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getPcrData(c, NIFTY_KEY, expiry, date, &(int){30}),
       "Exception when calling MarketApi->get_pcr_data", "MarketApi->get_pcr_data not returning success");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getMaxPainData(c, NIFTY_KEY, expiry, date, &(int){30}),
       "Exception when calling MarketApi->get_max_pain_data", "MarketApi->get_max_pain_data not returning success");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getFiiData(c, "NSE_EQ|CASH", "1D", NULL),
       "Exception when calling MarketApi->get_fii_data", "MarketApi->get_fii_data not returning success");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getDiiData(c, "NSE_EQ|CASH", "1D", NULL),
       "Exception when calling MarketApi->get_dii_data", "MarketApi->get_dii_data not returning success");
}

// Fundamentals-market-data model checks.
static void fundamentals_models(void) {
    MODEL_NEW(analytics_response, "error: AnalyticsResponse instantiation failed");
    MODEL_STATUS(analytics_response, "error: AnalyticsResponse status field not set correctly");
    MODEL_NEW(balance_sheet_data, "error: BalanceSheetData instantiation failed");
    MODEL_NEW(balance_sheet_history_item, "error: BalanceSheetHistoryItem instantiation failed");
    MODEL_STATUS(balance_sheet_response, "error: BalanceSheetResponse status field not set correctly");
    MODEL_NEW(cash_flow_data, "error: CashFlowData instantiation failed");
    MODEL_NEW(cash_flow_entry, "error: CashFlowEntry instantiation failed");
    MODEL_STATUS(cash_flow_response, "error: CashFlowResponse status field not set correctly");
    MODEL_NEW(company_profile_data, "error: CompanyProfileData instantiation failed");
    MODEL_STATUS(company_profile_response, "error: CompanyProfileResponse status field not set correctly");
    MODEL_NEW(competitor_data, "error: CompetitorData instantiation failed");
    MODEL_STATUS(competitors_response, "error: CompetitorsResponse status field not set correctly");
    MODEL_NEW(corporate_action_data, "error: CorporateActionData instantiation failed");
    MODEL_NEW(corporate_action_event_detail, "error: CorporateActionEventDetail instantiation failed");
    MODEL_STATUS(corporate_actions_response, "error: CorporateActionsResponse status field not set correctly");
    MODEL_NEW(financial_statement_entry, "error: FinancialStatementEntry instantiation failed");
    MODEL_NEW(history_item, "error: HistoryItem instantiation failed");
    MODEL_NEW(income_statement_data, "error: IncomeStatementData instantiation failed");
    MODEL_NEW(income_statement_entry, "error: IncomeStatementEntry instantiation failed");
    MODEL_STATUS(income_statement_response, "error: IncomeStatementResponse status field not set correctly");
    MODEL_NEW(key_ratio_data, "error: KeyRatioData instantiation failed");
    MODEL_STATUS(key_ratios_response, "error: KeyRatiosResponse status field not set correctly");
    MODEL_NEW(sector_market_cap_amount, "error: SectorMarketCapAmount instantiation failed");
    MODEL_NEW(share_holding_data, "error: ShareHoldingData instantiation failed");
    MODEL_STATUS(share_holdings_response, "error: ShareHoldingsResponse status field not set correctly");
}

// IpoApi block; apply/cancel blocks funds via UPI and stays off unless RUN_DESTRUCTIVE_IPO_TESTS.
static void ipo(void) {
    OK(ipo_listing_response,
       IPOAPI_getIpoListing(c, upstox_client_getIpoListing_STATUS_open, upstox_client_getIpoListing_ISSUETYPE_regular, "1", "20"),
       "Exception when calling IpoApi->get_ipo_listing", "error in get_ipo_listing API");
    OK(ipo_details_response, IPOAPI_getIpoDetails(c, "sample-ipo-slug"),
       "Exception when calling IpoApi->get_ipo_details", "error in get_ipo_details API");
    OK(ipo_order_response, IPOAPI_getIpoOrders(c, NULL, NULL),
       "Exception when calling IpoApi->get_ipo_orders", "error in get_ipo_orders API");
    OK(ipo_order_detail_response, IPOAPI_getIpoOrderById(c, "sample-ipo-order-id"),
       "Exception when calling IpoApi->get_ipo_order_by_id", "error in get_ipo_order_by_id API");

    if (!RUN_DESTRUCTIVE_IPO_TESTS) {
        return;
    }
    const char *exc = "Exception when calling IpoApi ipo order write ops";
    ipo_apply_request_t *body;
    PARSE(ipo_apply_request, body, "{\"id\":\"sample-ipo-slug\",\"upi\":\"someone@upi\",\"category\":\"IND\","
          "\"bids\":[{\"quantity\":10,\"price\":150.0}]}");
    ipo_apply_response_t *applied = IPOAPI_applyForIpo(c, body);
    ipo_apply_request_free(body);
    char *order_id = (applied && applied->data && applied->data->order_id) ? strdup(applied->data->order_id) : NULL;
    check_response(applied != NULL, order_id != NULL, exc, "apply_for_ipo returned no order id");
    ipo_apply_response_free(applied);
    if (order_id == NULL) {
        return;
    }
    ipo_cancel_response_t *cancelled = IPOAPI_cancelIpoOrder(c, order_id);
    check_response(cancelled != NULL, cancelled && GOOD(ipo_cancel_response, cancelled), exc, "error in cancel_ipo_order");
    if (cancelled) {
        printf("ipo apply/cancel cycle: %s\n", ipo_cancel_response_status_ToString(cancelled->status));
    }
    ipo_cancel_response_free(cancelled);
    free(order_id);
}

// Smartlist block (Python's MarketApi).
static void smartlist(void) {
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getSmartlistOptions(c, "INDEX", "TOP_TRADED", &(int){1}, &(int){50}),
       "Exception when calling MarketApi->get_smartlist_options", "error in get_smartlist_options API");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getSmartlistFutures(c, "STOCK", "MOST_ACTIVE", &(int){1}, &(int){50}),
       "Exception when calling MarketApi->get_smartlist_futures", "error in get_smartlist_futures API");
    OK(analytics_response, MarketHolidaysAndTimingsAPI_getSmartlistMtf(c, &(int){1}, &(int){50}),
       "Exception when calling MarketApi->get_smartlist_mtf", "error in get_smartlist_mtf API");
}

// Payout block; initiate/modify/cancel move real funds and stay off unless RUN_DESTRUCTIVE_PAYOUT_TESTS.
static void payout(void) {
    OK(payment_history_response, UserAPI_getPayoutHistory(c),
       "Exception when calling UserApi->get_payout_history", "error in get_payout_history API");
    OK(payout_modes_response, UserAPI_getPayoutModes(c),
       "Exception when calling UserApi->get_payout_modes", "error in get_payout_modes API");

    if (!RUN_DESTRUCTIVE_PAYOUT_TESTS) {
        return;
    }
    const char *exc = "Exception when calling UserApi payout write ops";
    initiate_payout_request_t *init;
    PARSE(initiate_payout_request, init, "{\"mode\":\"IMPS\",\"amount\":1.0}");
    payout_details_response_t *initiated = UserAPI_initiatePayout(c, init);
    initiate_payout_request_free(init);
    char *id = (initiated && initiated->data && initiated->data->transaction_id) ? strdup(initiated->data->transaction_id) : NULL;
    check_response(initiated != NULL, id != NULL, exc, "initiate_payout returned no transaction id");
    payout_details_response_free(initiated);
    if (id == NULL) {
        return;
    }

    modify_payout_request_t *modify;
    PARSE(modify_payout_request, modify, "{\"amount\":2.0}");
    OK(payout_details_response, UserAPI_modifyPayout(c, id, modify), exc, "error in modify_payout");
    modify_payout_request_free(modify);

    payout_details_response_t *cancelled = UserAPI_cancelPayout(c, id);
    check_response(cancelled != NULL, cancelled && GOOD(payout_details_response, cancelled), exc, "error in cancel_payout");
    if (cancelled) {
        printf("payout initiate/modify/cancel cycle: %s\n", payout_details_response_status_ToString(cancelled->status));
    }
    payout_details_response_free(cancelled);
    free(id);
}

// US Stocks block; estimate and margin place nothing.
static void us_stocks(void) {
    OK(get_market_status_response, USMarketHolidaysAndTimingsAPI_getUsMarketStatus(c),
       "Exception when calling UsMarketHolidaysAndTimingsApi->get_us_market_status", "error in get_us_market_status API");
    OK(get_us_holiday_response, USMarketHolidaysAndTimingsAPI_getUsHolidays(c),
       "Exception when calling UsMarketHolidaysAndTimingsApi->get_us_holidays", "error in get_us_holidays API");
    OK(get_us_holiday_response, USMarketHolidaysAndTimingsAPI_getUsHoliday(c, "2026-11-26"),
       "Exception when calling UsMarketHolidaysAndTimingsApi->get_us_holiday", "error in get_us_holiday API");
    OK(get_us_exchange_timing_response, USMarketHolidaysAndTimingsAPI_getUsExchangeTimings(c, "2026-11-27"),
       "Exception when calling UsMarketHolidaysAndTimingsApi->get_us_exchange_timings", "error in get_us_exchange_timings API");
    OK(us_funds_response, USStocksFundsAPI_getUsFunds(c),
       "Exception when calling UsStocksFundsApi->get_us_funds", "error in get_us_funds API");
    OK(us_holdings_response, USStocksPortfolioAPI_getUsHoldings(c),
       "Exception when calling UsStocksPortfolioApi->get_us_holdings", "error in get_us_holdings API");
    OK(us_order_book_response, USStocksOrderAPI_getUsOrderBook(c, NULL),
       "Exception when calling UsStocksOrderApi->get_us_order_book", "error in get_us_order_book API");
    OK(us_order_details_response, USStocksOrderAPI_getUsOrderDetails(c, "sample-us-order-id"),
       "Exception when calling UsStocksOrderApi->get_us_order_details", "error in get_us_order_details API");

    us_order_estimate_request_t *estimate;
    PARSE(us_order_estimate_request, estimate, US_ESTIMATE_JSON);
    OK(us_order_estimate_response, USStocksOrderAPI_estimateUsOrder(c, estimate),
       "Exception when calling UsStocksOrderApi->estimate_us_order", "error in estimate_us_order API");
    us_order_estimate_request_free(estimate);

    us_margin_request_t *margin;
    PARSE(us_margin_request, margin, "{\"instruments\":[" US_ESTIMATE_JSON "]}");
    OK(us_margin_response, USStocksChargesAPI_calculateUsMargin(c, margin),
       "Exception when calling UsStocksChargesApi->calculate_us_margin", "error in calculate_us_margin API");
    us_margin_request_free(margin);
}

#define IPO_META_JSON "{\"page\":{\"page_number\":1}}"
#define IPO_LISTING_JSON "{\"symbol\":\"XYZ\",\"status\":\"open\"}"
#define IPO_INVESTOR_JSON "{\"category\":\"IND\",\"description\":\"Individual Investor\"}"
#define IPO_BID_JSON "{\"quantity\":10,\"price\":150.5}"
#define IPO_ORDER_BID_JSON "{\"quantity\":10,\"price\":150.5,\"amount\":1505.0,\"message\":\"accepted\"}"
#define IPO_ORDER_JSON                                                            \
    "{\"id\":\"abc\",\"symbol\":\"XYZ\",\"exchange\":\"NSE\",\"order_id\":\"O1\",\"order_status\":\"COMPLETE\"," \
    "\"category\":\"IND\",\"issue_type\":\"regular\",\"units_allotted\":10,\"bids\":[" IPO_ORDER_BID_JSON "]}"
#define IPO_DETAILS_JSON                                                          \
    "{\"id\":\"abc\",\"symbol\":\"XYZ\",\"lot_size\":10,\"timeline\":{\"listing_date\":\"2026-07-01\"}," \
    "\"registrar_info\":{\"name\":\"Registrar Co\"}}"
#define IPO_CANCEL_JSON "{\"order_id\":\"O1\",\"status\":\"CANCELLED\"}"
#define PAYOUT_JSON "{\"status\":\"SUCCESS\",\"transaction_id\":\"T1\",\"amount\":500.0}"
#define US_BOOK_JSON "{\"order_id\":\"O1\",\"status\":\"open\",\"quantity\":1.5,\"fractionable\":true}"

// IPO, payout and US stocks model checks.
static void new_models(void) {
    MODEL(ipo_listing_data, IPO_LISTING_JSON, EQ_STR(m_->symbol, "XYZ"), "error: IpoListingData fields not set correctly");
    MODEL(ipo_meta_data, IPO_META_JSON, m_->page && EQ_NUM(m_->page->page_number, 1),
          "error: IpoMetaData fields not set correctly");
    MODEL(ipo_listing_response, "{\"status\":\"success\",\"data\":[" IPO_LISTING_JSON "],\"meta_data\":" IPO_META_JSON "}",
          m_->status == upstox_client_ipo_listing_response_STATUS_success,
          "error: IpoListingResponse status field not set correctly");
    MODEL(ipo_timeline, "{\"listing_date\":\"2026-07-01\"}", EQ_STR(m_->listing_date, "2026-07-01"),
          "error: IpoTimeline fields not set correctly");
    MODEL(ipo_registrar_info, "{\"name\":\"Registrar Co\"}", EQ_STR(m_->name, "Registrar Co"),
          "error: IpoRegistrarInfo fields not set correctly");
    MODEL(ipo_details_data, IPO_DETAILS_JSON, EQ_NUM(m_->lot_size, 10), "error: IpoDetailsData fields not set correctly");
    MODEL(ipo_details_response, "{\"status\":\"success\",\"data\":" IPO_DETAILS_JSON "}",
          m_->status == upstox_client_ipo_details_response_STATUS_success,
          "error: IpoDetailsResponse status field not set correctly");
    MODEL(ipo_investor_type, IPO_INVESTOR_JSON, m_->category == upstox_client_ipo_investor_type_CATEGORY_IND,
          "error: IpoInvestorType fields not set correctly");
    MODEL(ipo_details_data, "{\"id\":\"abc\",\"investors\":[" IPO_INVESTOR_JSON "]}",
          FIRST(ipo_investor_type, m_->investors) &&
              FIRST(ipo_investor_type, m_->investors)->category == upstox_client_ipo_investor_type_CATEGORY_IND,
          "error: IpoDetailsData investors field not set correctly");
    MODEL(ipo_listing_data, "{\"symbol\":\"XYZ\",\"investors\":[" IPO_INVESTOR_JSON "]}",
          FIRST(ipo_investor_type, m_->investors) &&
              EQ_STR(FIRST(ipo_investor_type, m_->investors)->description, "Individual Investor"),
          "error: IpoListingData investors field not set correctly");
    MODEL(ipo_bid_request, IPO_BID_JSON, EQ_NUM(m_->quantity, 10) && EQ_NUM(m_->price, 150.5),
          "error: IpoBidRequest fields not set correctly");
    MODEL(ipo_apply_request, "{\"id\":\"sample-ipo-slug\",\"upi\":\"someone@upi\",\"category\":\"IND\",\"bids\":[" IPO_BID_JSON "]}",
          EQ_STR(m_->upi, "someone@upi") && m_->bids && m_->bids->count == 1,
          "error: IpoApplyRequest fields not set correctly");
    MODEL(ipo_apply_data, "{\"order_id\":\"O1\"}", EQ_STR(m_->order_id, "O1"), "error: IpoApplyData fields not set correctly");
    MODEL(ipo_apply_response, "{\"status\":\"success\",\"data\":{\"order_id\":\"O1\"}}",
          m_->status == upstox_client_ipo_apply_response_STATUS_success,
          "error: IpoApplyResponse status field not set correctly");
    MODEL(ipo_order_bid, IPO_ORDER_BID_JSON, EQ_NUM(m_->amount, 1505.0), "error: IpoOrderBid fields not set correctly");
    MODEL(ipo_order_data, IPO_ORDER_JSON, EQ_STR(m_->order_id, "O1") && EQ_NUM(m_->units_allotted, 10),
          "error: IpoOrderData fields not set correctly");
    MODEL(ipo_order_response, "{\"status\":\"success\",\"data\":[" IPO_ORDER_JSON "],\"meta_data\":" IPO_META_JSON "}",
          m_->status == upstox_client_ipo_order_response_STATUS_success,
          "error: IpoOrderResponse status field not set correctly");
    MODEL(ipo_order_detail_response, "{\"status\":\"success\",\"data\":" IPO_ORDER_JSON "}",
          m_->data && EQ_STR(m_->data->symbol, "XYZ"), "error: IpoOrderDetailResponse fields not set correctly");
    MODEL(ipo_cancel_data, IPO_CANCEL_JSON, EQ_STR(m_->status, "CANCELLED"), "error: IpoCancelData fields not set correctly");
    MODEL(ipo_cancel_response, "{\"status\":\"success\",\"data\":" IPO_CANCEL_JSON "}",
          m_->data && EQ_STR(m_->data->order_id, "O1"), "error: IpoCancelResponse fields not set correctly");

    MODEL(initiate_payout_request, "{\"mode\":\"IMPS\",\"amount\":500.0}", EQ_NUM(m_->amount, 500.0),
          "error: InitiatePayoutRequest fields not set correctly");
    MODEL(modify_payout_request, "{\"amount\":750.0}", EQ_NUM(m_->amount, 750.0),
          "error: ModifyPayoutRequest fields not set correctly");
    MODEL(payout_details, PAYOUT_JSON, EQ_STR(m_->transaction_id, "T1"), "error: PayoutDetails fields not set correctly");
    MODEL(payout_details_response, "{\"status\":\"success\",\"data\":" PAYOUT_JSON "}",
          m_->status == upstox_client_payout_details_response_STATUS_success,
          "error: PayoutDetailsResponse status field not set correctly");
    // C has no PayoutModesData model; data is free-form JSON
    MODEL(payout_modes_response, "{\"status\":\"success\",\"data\":{}}",
          m_->status == upstox_client_payout_modes_response_STATUS_success,
          "error: PayoutModesResponse status field not set correctly");

    MODEL(us_place_order_request, "{\"amount\":25.0,\"validity\":\"DAY\",\"instrument_key\":\"K\",\"transaction_type\":\"BUY\","
          "\"order_type\":\"MARKET\"}", EQ_NUM(m_->amount, 25.0), "error: UsPlaceOrderRequest fields not set correctly");
    MODEL(us_margin_request, "{\"instruments\":[{\"quantity\":1.25,\"instrument_key\":\"K\",\"transaction_type\":\"BUY\","
          "\"order_type\":\"MARKET\"}]}",
          FIRST(us_order_estimate_request, m_->instruments) &&
              EQ_NUM(FIRST(us_order_estimate_request, m_->instruments)->quantity, 1.25),
          "error: UsMarginRequest fields not set correctly");
    MODEL(us_order_response, "{\"status\":\"success\",\"data\":{\"order_id\":\"O1\"}}",
          m_->data && EQ_STR(m_->data->order_id, "O1"), "error: UsOrderResponse fields not set correctly");
    MODEL(us_order_estimate_response, "{\"status\":\"success\",\"data\":{\"total_charges\":1.5,\"estimated_total\":101.5}}",
          m_->data && EQ_NUM(m_->data->estimated_total, 101.5), "error: UsOrderEstimateResponse fields not set correctly");

    us_order_book_response_t *book;
    us_order_details_response_t *book_details;
    PARSE(us_order_book_response, book, "{\"status\":\"success\",\"data\":[" US_BOOK_JSON "]}");
    PARSE(us_order_details_response, book_details, "{\"status\":\"success\",\"data\":" US_BOOK_JSON "}");
    check_model(book && FIRST(us_order_book_data, book->data) &&
                    FIRST(us_order_book_data, book->data)->status == upstox_client_us_order_book_data_STATUS_open &&
                    book_details && book_details->data && EQ_NUM(book_details->data->quantity, 1.5),
                "error: UsOrderBookResponse/UsOrderDetailsResponse fields not set correctly");
    us_order_book_response_free(book);
    us_order_details_response_free(book_details);

    MODEL(us_margin_response, "{\"status\":\"success\",\"data\":{\"margins\":[{\"instrument_key\":\"K\","
          "\"required_margin\":101.2}],\"sufficient\":true}}",
          m_->data && FIRST(us_order_margin, m_->data->margins) &&
              EQ_NUM(FIRST(us_order_margin, m_->data->margins)->required_margin, 101.2),
          "error: UsMarginResponse fields not set correctly");
    MODEL(us_funds_response, "{\"status\":\"success\",\"data\":{\"cash\":100.0,\"exchange_rate\":88.5}}",
          m_->data && EQ_NUM(m_->data->exchange_rate, 88.5), "error: UsFundsResponse fields not set correctly");
    MODEL(us_holdings_response, "{\"status\":\"success\",\"data\":[{\"instrument_key\":\"K\",\"quantity\":2.5}]}",
          FIRST(us_holding_data, m_->data) && EQ_NUM(FIRST(us_holding_data, m_->data)->quantity, 2.5),
          "error: UsHoldingsResponse fields not set correctly");
    MODEL(get_us_holiday_response, "{\"status\":\"success\",\"data\":[{\"date\":\"2026-11-26\",\"holiday_type\":\"TRADING_HOLIDAY\"}]}",
          FIRST(us_holiday_data, m_->data) && EQ_STR(FIRST(us_holiday_data, m_->data)->date, "2026-11-26"),
          "error: GetUsHolidayResponse fields not set correctly");
    MODEL(get_us_exchange_timing_response, "{\"status\":\"success\",\"data\":[{\"exchange\":\"US\",\"start_time\":1,\"end_time\":2}]}",
          FIRST(us_exchange_timing_data, m_->data) && EQ_NUM(FIRST(us_exchange_timing_data, m_->data)->end_time, 2),
          "error: GetUsExchangeTimingResponse fields not set correctly");
}

// Final logout; it invalidates the token.
static void logout(void) {
    logout_response_t *r = LoginAPI_logout(c);
    check_response(r != NULL, r && GOOD(logout_response, r), "Exception when calling LoginApi->logout", "error in logout");
    if (r) {
        show_json("", logout_response_convertToJSON(r));
        printf("successfully logged out\n");
    }
    logout_response_free(r);
}

// Runs every section in sanity.py order against client; returns the number of failed checks.
static int run_sanity(apiClient_t *client) {
    c = client;
    user();
    charge();
    orders();
    portfolio();
    profit_and_loss();
    history();
    market_quote();
    market_timings();
    order_v3();
    options();
    login_token();
    post_trade();
    mtf_positions();
    history_v3();
    market_quote_v3();
    expired_instruments();
    algo_name();
    instruments();
    news();
    news_models();
    indie_token();
    mutual_funds();
    mutual_fund_models();
    payments();
    payment_models();
    fundamentals();
    market_analytics();
    fundamentals_models();
    ipo();
    smartlist();
    payout();
    us_stocks();
    new_models();
    logout();
    printf("%d checks, %d failed\n", checks, failed);
    return failed;
}

int main(void) {
    const char *token = data_token_access_token();
    if (token[0] == '\0') {
        printf("no access token: set UPSTOX_ACCESS_TOKEN, or DATA_TOKEN_ACCESS_TOKEN in test/sdk_tests/data_token.h "
               "(never commit it)\n");
        return 1;
    }
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(token);
    int bad = run_sanity(client);
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return bad > 0 ? 1 : 0;
}
