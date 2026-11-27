// Places a Put Ratio Back Spread (Bearish) options strategy on Nifty 50.
// Sells one ATM put and buys two OTM puts (ATM-1) for the next weekly expiry.
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

    // Step 1: Find the ATM put (short leg)
    leg_t short_put = find_option(client, "PE", "next_week", 0);
    printf("Short put (ATM)   - Trading symbol : %s\n", short_put.trading_symbol);
    printf("Short put (ATM)   - Instrument key : %s\n", short_put.instrument_key);

    // Step 2: Find the OTM put (long leg — 2x quantity)
    leg_t long_put = find_option(client, "PE", "next_week", -1);
    printf("Long put  (ATM-1) - Trading symbol : %s\n", long_put.trading_symbol);
    printf("Long put  (ATM-1) - Instrument key : %s\n", long_put.instrument_key);

    // Step 3: Sell 1x ATM put
    place_order(client, &short_put, 1, "SELL", "Short put order placed successfully.");

    // Step 4: Buy 2x OTM put
    place_order(client, &long_put, 2, "BUY", "Long put order placed successfully.");

    apiClient_free(client);
    apiClient_unsetupGlobalEnv();
    return 0;
}
