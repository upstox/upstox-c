// Places a Bull Butterfly (Bullish) options strategy on Nifty 50.
// Buys an ATM call, sells two ATM+1 calls, and buys an ATM+2 call for the next weekly expiry.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "upstox_client/upstox.h"
#include "upstox_client/api/InstrumentsAPI.h"
#include "upstox_client/api/OrderV3API.h"

// Index whose options are traded; e.g. "Nifty Bank" or "SENSEX".
#define UNDERLYING "Nifty 50"

// One option contract picked by find_option.
typedef struct {
    char instrument_key[64];
    char trading_symbol[64];
    long lot_size;
} leg_t;

// Prints the API error and stops, so no further legs are placed.
static void exit_on_error(apiClient_t *client, const char *call) {
    printf("API error: %s: HTTP %ld %s\n", call, client->response_code, client->errorBody ? client->errorBody : "");
    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    exit(1);
}

// Returns the first UNDERLYING option matching the type, expiry and ATM offset.
static leg_t find_option(apiClient_t *client, char *option_type, char *expiry, int atm_offset) {
    search_instrument_response_t *resp =
        InstrumentsAPI_searchInstrument(client, UNDERLYING, "NSE", "FO", option_type, expiry, &atm_offset, NULL, NULL);
    if (resp == NULL) {
        exit_on_error(client, "InstrumentsAPI_searchInstrument");
    }
    if (resp->data == NULL || resp->data->count == 0) {
        printf("No %s option found for expiry=%s atm_offset=%d\n", option_type, expiry, atm_offset);
        search_instrument_response_free(resp);
        apiClient_free(client);
        apiClient_unsetupGlobalEnv();
        exit(1);
    }
    instrument_data_t *data = resp->data->firstEntry->data;
    leg_t leg = {{0}, {0}, 0};
    snprintf(leg.instrument_key, sizeof leg.instrument_key, "%s", data->instrument_key ? data->instrument_key : "");
    snprintf(leg.trading_symbol, sizeof leg.trading_symbol, "%s", data->trading_symbol ? data->trading_symbol : "");
    leg.lot_size = data->lot_size ? *data->lot_size : 0;
    search_instrument_response_free(resp);
    return leg;
}

// Places a MARKET delivery order for lots x lot size of the leg and prints the order ids.
static void place_order(apiClient_t *client, const leg_t *leg, int lots, const char *transaction_type, const char *label) {
    int quantity = (int)leg->lot_size * lots;
    double price = 0;
    int disclosed_quantity = 0;
    double trigger_price = 0;
    int is_amo = 0;
    double market_protection = -1;
    place_order_v3_request_t *body = place_order_v3_request_create(
        &quantity, upstox_client_place_order_v3_request_PRODUCT_D, upstox_client_place_order_v3_request_VALIDITY_DAY, &price, NULL, NULL,
        strdup(leg->instrument_key), upstox_client_place_order_v3_request_ORDERTYPE_MARKET,
        strcmp(transaction_type, "BUY") == 0 ? upstox_client_place_order_v3_request_TRANSACTIONTYPE_BUY
                                             : upstox_client_place_order_v3_request_TRANSACTIONTYPE_SELL,
        &disclosed_quantity, &trigger_price, &is_amo, &market_protection);
    place_order_v3_response_t *resp = OrderV3API_placeOrderV3(client, body, NULL);
    place_order_v3_request_free(body);
    if (resp == NULL) {
        exit_on_error(client, "OrderV3API_placeOrderV3");
    }
    printf("%s Order ID: [", label);
    if (resp->data != NULL) {
        listEntry_t *entry;
        list_ForEach(entry, resp->data->order_ids) {
            printf(entry == resp->data->order_ids->firstEntry ? "%s" : " %s", (char *)entry->data);
        }
    }
    printf("]\n");
    place_order_v3_response_free(resp);
}

int main(void) {
    const char *token = getenv("UPSTOX_ACCESS_TOKEN");
    if (token == NULL || *token == '\0') {
        fprintf(stderr, "Set UPSTOX_ACCESS_TOKEN to your Upstox access token\n");
        return 1;
    }
    apiClient_setupGlobalEnv();
    apiClient_t *client = upstox_client_create(token);

    // Step 1: Find all three strikes
    leg_t lower_long = find_option(client, "CE", "next_week", 0);
    printf("Lower long  (ATM)   - Trading symbol : %s\n", lower_long.trading_symbol);

    leg_t middle_short = find_option(client, "CE", "next_week", 1);
    printf("Middle short (ATM+1) - Trading symbol : %s\n", middle_short.trading_symbol);

    leg_t upper_long = find_option(client, "CE", "next_week", 2);
    printf("Upper long  (ATM+2) - Trading symbol : %s\n", upper_long.trading_symbol);

    // Step 2: Buy the lower call (ATM)
    place_order(client, &lower_long, 1, "BUY", "Lower long call order placed successfully.");

    // Step 3: Sell two middle calls (ATM+1)
    place_order(client, &middle_short, 2, "SELL", "Middle short call order placed successfully.");

    // Step 4: Buy the upper call (ATM+2)
    place_order(client, &upper_long, 1, "BUY", "Upper long call order placed successfully.");

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
