#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_symbol_v3.h"



static market_quote_symbol_v3_t *market_quote_symbol_v3_create_internal(
    ohlc_v3_t *ohlc,
    depth_map_t *depth,
    char *timestamp,
    char *instrument_token,
    char *symbol,
    double *last_price,
    long *volume,
    double *average_price,
    double *oi,
    double *net_change,
    double *total_buy_quantity,
    double *total_sell_quantity,
    double *lower_circuit_limit,
    double *upper_circuit_limit,
    char *last_trade_time,
    double *oi_day_high,
    double *oi_day_low,
    double *prev_close_price,
    double *year_high,
    double *year_low,
    double *previous_oi,
    double *indicative_equilibrium_price,
    double *reference_price,
    long *indicative_equilibrium_quantity,
    long *indicative_imbalance_quantity_total,
    long *indicative_imbalance_quantity_market,
    int *cas_eligible
    ) {
    market_quote_symbol_v3_t *market_quote_symbol_v3_local_var = malloc(sizeof(market_quote_symbol_v3_t));
    if (!market_quote_symbol_v3_local_var) {
        return NULL;
    }
    memset(market_quote_symbol_v3_local_var, 0, sizeof(market_quote_symbol_v3_t));
    market_quote_symbol_v3_local_var->_library_owned = 1;
    market_quote_symbol_v3_local_var->ohlc = ohlc;
    market_quote_symbol_v3_local_var->depth = depth;
    market_quote_symbol_v3_local_var->timestamp = timestamp;
    market_quote_symbol_v3_local_var->instrument_token = instrument_token;
    market_quote_symbol_v3_local_var->symbol = symbol;
    market_quote_symbol_v3_local_var->last_price = last_price;
    market_quote_symbol_v3_local_var->volume = volume;
    market_quote_symbol_v3_local_var->average_price = average_price;
    market_quote_symbol_v3_local_var->oi = oi;
    market_quote_symbol_v3_local_var->net_change = net_change;
    market_quote_symbol_v3_local_var->total_buy_quantity = total_buy_quantity;
    market_quote_symbol_v3_local_var->total_sell_quantity = total_sell_quantity;
    market_quote_symbol_v3_local_var->lower_circuit_limit = lower_circuit_limit;
    market_quote_symbol_v3_local_var->upper_circuit_limit = upper_circuit_limit;
    market_quote_symbol_v3_local_var->last_trade_time = last_trade_time;
    market_quote_symbol_v3_local_var->oi_day_high = oi_day_high;
    market_quote_symbol_v3_local_var->oi_day_low = oi_day_low;
    market_quote_symbol_v3_local_var->prev_close_price = prev_close_price;
    market_quote_symbol_v3_local_var->year_high = year_high;
    market_quote_symbol_v3_local_var->year_low = year_low;
    market_quote_symbol_v3_local_var->previous_oi = previous_oi;
    market_quote_symbol_v3_local_var->indicative_equilibrium_price = indicative_equilibrium_price;
    market_quote_symbol_v3_local_var->reference_price = reference_price;
    market_quote_symbol_v3_local_var->indicative_equilibrium_quantity = indicative_equilibrium_quantity;
    market_quote_symbol_v3_local_var->indicative_imbalance_quantity_total = indicative_imbalance_quantity_total;
    market_quote_symbol_v3_local_var->indicative_imbalance_quantity_market = indicative_imbalance_quantity_market;
    market_quote_symbol_v3_local_var->cas_eligible = cas_eligible;
    return market_quote_symbol_v3_local_var;
}

market_quote_symbol_v3_t *market_quote_symbol_v3_create(
    ohlc_v3_t *ohlc,
    depth_map_t *depth,
    char *timestamp,
    char *instrument_token,
    char *symbol,
    double *last_price,
    long *volume,
    double *average_price,
    double *oi,
    double *net_change,
    double *total_buy_quantity,
    double *total_sell_quantity,
    double *lower_circuit_limit,
    double *upper_circuit_limit,
    char *last_trade_time,
    double *oi_day_high,
    double *oi_day_low,
    double *prev_close_price,
    double *year_high,
    double *year_low,
    double *previous_oi,
    double *indicative_equilibrium_price,
    double *reference_price,
    long *indicative_equilibrium_quantity,
    long *indicative_imbalance_quantity_total,
    long *indicative_imbalance_quantity_market,
    int *cas_eligible
    ) {
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    long *volume_copy = NULL;
    if (volume) {
        volume_copy = malloc(sizeof(long));
        if (volume_copy) *volume_copy = *volume;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    double *oi_copy = NULL;
    if (oi) {
        oi_copy = malloc(sizeof(double));
        if (oi_copy) *oi_copy = *oi;
    }
    double *net_change_copy = NULL;
    if (net_change) {
        net_change_copy = malloc(sizeof(double));
        if (net_change_copy) *net_change_copy = *net_change;
    }
    double *total_buy_quantity_copy = NULL;
    if (total_buy_quantity) {
        total_buy_quantity_copy = malloc(sizeof(double));
        if (total_buy_quantity_copy) *total_buy_quantity_copy = *total_buy_quantity;
    }
    double *total_sell_quantity_copy = NULL;
    if (total_sell_quantity) {
        total_sell_quantity_copy = malloc(sizeof(double));
        if (total_sell_quantity_copy) *total_sell_quantity_copy = *total_sell_quantity;
    }
    double *lower_circuit_limit_copy = NULL;
    if (lower_circuit_limit) {
        lower_circuit_limit_copy = malloc(sizeof(double));
        if (lower_circuit_limit_copy) *lower_circuit_limit_copy = *lower_circuit_limit;
    }
    double *upper_circuit_limit_copy = NULL;
    if (upper_circuit_limit) {
        upper_circuit_limit_copy = malloc(sizeof(double));
        if (upper_circuit_limit_copy) *upper_circuit_limit_copy = *upper_circuit_limit;
    }
    double *oi_day_high_copy = NULL;
    if (oi_day_high) {
        oi_day_high_copy = malloc(sizeof(double));
        if (oi_day_high_copy) *oi_day_high_copy = *oi_day_high;
    }
    double *oi_day_low_copy = NULL;
    if (oi_day_low) {
        oi_day_low_copy = malloc(sizeof(double));
        if (oi_day_low_copy) *oi_day_low_copy = *oi_day_low;
    }
    double *prev_close_price_copy = NULL;
    if (prev_close_price) {
        prev_close_price_copy = malloc(sizeof(double));
        if (prev_close_price_copy) *prev_close_price_copy = *prev_close_price;
    }
    double *year_high_copy = NULL;
    if (year_high) {
        year_high_copy = malloc(sizeof(double));
        if (year_high_copy) *year_high_copy = *year_high;
    }
    double *year_low_copy = NULL;
    if (year_low) {
        year_low_copy = malloc(sizeof(double));
        if (year_low_copy) *year_low_copy = *year_low;
    }
    double *previous_oi_copy = NULL;
    if (previous_oi) {
        previous_oi_copy = malloc(sizeof(double));
        if (previous_oi_copy) *previous_oi_copy = *previous_oi;
    }
    double *indicative_equilibrium_price_copy = NULL;
    if (indicative_equilibrium_price) {
        indicative_equilibrium_price_copy = malloc(sizeof(double));
        if (indicative_equilibrium_price_copy) *indicative_equilibrium_price_copy = *indicative_equilibrium_price;
    }
    double *reference_price_copy = NULL;
    if (reference_price) {
        reference_price_copy = malloc(sizeof(double));
        if (reference_price_copy) *reference_price_copy = *reference_price;
    }
    long *indicative_equilibrium_quantity_copy = NULL;
    if (indicative_equilibrium_quantity) {
        indicative_equilibrium_quantity_copy = malloc(sizeof(long));
        if (indicative_equilibrium_quantity_copy) *indicative_equilibrium_quantity_copy = *indicative_equilibrium_quantity;
    }
    long *indicative_imbalance_quantity_total_copy = NULL;
    if (indicative_imbalance_quantity_total) {
        indicative_imbalance_quantity_total_copy = malloc(sizeof(long));
        if (indicative_imbalance_quantity_total_copy) *indicative_imbalance_quantity_total_copy = *indicative_imbalance_quantity_total;
    }
    long *indicative_imbalance_quantity_market_copy = NULL;
    if (indicative_imbalance_quantity_market) {
        indicative_imbalance_quantity_market_copy = malloc(sizeof(long));
        if (indicative_imbalance_quantity_market_copy) *indicative_imbalance_quantity_market_copy = *indicative_imbalance_quantity_market;
    }
    int *cas_eligible_copy = NULL;
    if (cas_eligible) {
        cas_eligible_copy = malloc(sizeof(int));
        if (cas_eligible_copy) *cas_eligible_copy = *cas_eligible;
    }
    market_quote_symbol_v3_t *result = market_quote_symbol_v3_create_internal (
        ohlc,
        depth,
        timestamp,
        instrument_token,
        symbol,
        last_price_copy,
        volume_copy,
        average_price_copy,
        oi_copy,
        net_change_copy,
        total_buy_quantity_copy,
        total_sell_quantity_copy,
        lower_circuit_limit_copy,
        upper_circuit_limit_copy,
        last_trade_time,
        oi_day_high_copy,
        oi_day_low_copy,
        prev_close_price_copy,
        year_high_copy,
        year_low_copy,
        previous_oi_copy,
        indicative_equilibrium_price_copy,
        reference_price_copy,
        indicative_equilibrium_quantity_copy,
        indicative_imbalance_quantity_total_copy,
        indicative_imbalance_quantity_market_copy,
        cas_eligible_copy
        );
    if (!result) {
        free(last_price_copy);
        free(volume_copy);
        free(average_price_copy);
        free(oi_copy);
        free(net_change_copy);
        free(total_buy_quantity_copy);
        free(total_sell_quantity_copy);
        free(lower_circuit_limit_copy);
        free(upper_circuit_limit_copy);
        free(oi_day_high_copy);
        free(oi_day_low_copy);
        free(prev_close_price_copy);
        free(year_high_copy);
        free(year_low_copy);
        free(previous_oi_copy);
        free(indicative_equilibrium_price_copy);
        free(reference_price_copy);
        free(indicative_equilibrium_quantity_copy);
        free(indicative_imbalance_quantity_total_copy);
        free(indicative_imbalance_quantity_market_copy);
        free(cas_eligible_copy);
    }
    return result;
}

void market_quote_symbol_v3_free(market_quote_symbol_v3_t *market_quote_symbol_v3) {
    if(NULL == market_quote_symbol_v3){
        return ;
    }
    if(market_quote_symbol_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_symbol_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_symbol_v3->ohlc) {
        ohlc_v3_free(market_quote_symbol_v3->ohlc);
        market_quote_symbol_v3->ohlc = NULL;
    }
    if (market_quote_symbol_v3->depth) {
        depth_map_free(market_quote_symbol_v3->depth);
        market_quote_symbol_v3->depth = NULL;
    }
    if (market_quote_symbol_v3->timestamp) {
        free(market_quote_symbol_v3->timestamp);
        market_quote_symbol_v3->timestamp = NULL;
    }
    if (market_quote_symbol_v3->instrument_token) {
        free(market_quote_symbol_v3->instrument_token);
        market_quote_symbol_v3->instrument_token = NULL;
    }
    if (market_quote_symbol_v3->symbol) {
        free(market_quote_symbol_v3->symbol);
        market_quote_symbol_v3->symbol = NULL;
    }
    if (market_quote_symbol_v3->last_price) {
        free(market_quote_symbol_v3->last_price);
        market_quote_symbol_v3->last_price = NULL;
    }
    if (market_quote_symbol_v3->volume) {
        free(market_quote_symbol_v3->volume);
        market_quote_symbol_v3->volume = NULL;
    }
    if (market_quote_symbol_v3->average_price) {
        free(market_quote_symbol_v3->average_price);
        market_quote_symbol_v3->average_price = NULL;
    }
    if (market_quote_symbol_v3->oi) {
        free(market_quote_symbol_v3->oi);
        market_quote_symbol_v3->oi = NULL;
    }
    if (market_quote_symbol_v3->net_change) {
        free(market_quote_symbol_v3->net_change);
        market_quote_symbol_v3->net_change = NULL;
    }
    if (market_quote_symbol_v3->total_buy_quantity) {
        free(market_quote_symbol_v3->total_buy_quantity);
        market_quote_symbol_v3->total_buy_quantity = NULL;
    }
    if (market_quote_symbol_v3->total_sell_quantity) {
        free(market_quote_symbol_v3->total_sell_quantity);
        market_quote_symbol_v3->total_sell_quantity = NULL;
    }
    if (market_quote_symbol_v3->lower_circuit_limit) {
        free(market_quote_symbol_v3->lower_circuit_limit);
        market_quote_symbol_v3->lower_circuit_limit = NULL;
    }
    if (market_quote_symbol_v3->upper_circuit_limit) {
        free(market_quote_symbol_v3->upper_circuit_limit);
        market_quote_symbol_v3->upper_circuit_limit = NULL;
    }
    if (market_quote_symbol_v3->last_trade_time) {
        free(market_quote_symbol_v3->last_trade_time);
        market_quote_symbol_v3->last_trade_time = NULL;
    }
    if (market_quote_symbol_v3->oi_day_high) {
        free(market_quote_symbol_v3->oi_day_high);
        market_quote_symbol_v3->oi_day_high = NULL;
    }
    if (market_quote_symbol_v3->oi_day_low) {
        free(market_quote_symbol_v3->oi_day_low);
        market_quote_symbol_v3->oi_day_low = NULL;
    }
    if (market_quote_symbol_v3->prev_close_price) {
        free(market_quote_symbol_v3->prev_close_price);
        market_quote_symbol_v3->prev_close_price = NULL;
    }
    if (market_quote_symbol_v3->year_high) {
        free(market_quote_symbol_v3->year_high);
        market_quote_symbol_v3->year_high = NULL;
    }
    if (market_quote_symbol_v3->year_low) {
        free(market_quote_symbol_v3->year_low);
        market_quote_symbol_v3->year_low = NULL;
    }
    if (market_quote_symbol_v3->previous_oi) {
        free(market_quote_symbol_v3->previous_oi);
        market_quote_symbol_v3->previous_oi = NULL;
    }
    if (market_quote_symbol_v3->indicative_equilibrium_price) {
        free(market_quote_symbol_v3->indicative_equilibrium_price);
        market_quote_symbol_v3->indicative_equilibrium_price = NULL;
    }
    if (market_quote_symbol_v3->reference_price) {
        free(market_quote_symbol_v3->reference_price);
        market_quote_symbol_v3->reference_price = NULL;
    }
    if (market_quote_symbol_v3->indicative_equilibrium_quantity) {
        free(market_quote_symbol_v3->indicative_equilibrium_quantity);
        market_quote_symbol_v3->indicative_equilibrium_quantity = NULL;
    }
    if (market_quote_symbol_v3->indicative_imbalance_quantity_total) {
        free(market_quote_symbol_v3->indicative_imbalance_quantity_total);
        market_quote_symbol_v3->indicative_imbalance_quantity_total = NULL;
    }
    if (market_quote_symbol_v3->indicative_imbalance_quantity_market) {
        free(market_quote_symbol_v3->indicative_imbalance_quantity_market);
        market_quote_symbol_v3->indicative_imbalance_quantity_market = NULL;
    }
    if (market_quote_symbol_v3->cas_eligible) {
        free(market_quote_symbol_v3->cas_eligible);
        market_quote_symbol_v3->cas_eligible = NULL;
    }
    free(market_quote_symbol_v3);
}

cJSON *market_quote_symbol_v3_convertToJSON(market_quote_symbol_v3_t *market_quote_symbol_v3) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_symbol_v3->ohlc
    if(market_quote_symbol_v3->ohlc) {
    cJSON *ohlc_local_JSON = ohlc_v3_convertToJSON(market_quote_symbol_v3->ohlc);
    if(ohlc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ohlc", ohlc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_symbol_v3->depth
    if(market_quote_symbol_v3->depth) {
    cJSON *depth_local_JSON = depth_map_convertToJSON(market_quote_symbol_v3->depth);
    if(depth_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "depth", depth_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_symbol_v3->timestamp
    if(market_quote_symbol_v3->timestamp) {
    if(cJSON_AddStringToObject(item, "timestamp", market_quote_symbol_v3->timestamp) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol_v3->instrument_token
    if(market_quote_symbol_v3->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_symbol_v3->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol_v3->symbol
    if(market_quote_symbol_v3->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", market_quote_symbol_v3->symbol) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol_v3->last_price
    if(market_quote_symbol_v3->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_symbol_v3->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->volume
    if(market_quote_symbol_v3->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *market_quote_symbol_v3->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->average_price
    if(market_quote_symbol_v3->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *market_quote_symbol_v3->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->oi
    if(market_quote_symbol_v3->oi) {
    if(cJSON_AddNumberToObject(item, "oi", *market_quote_symbol_v3->oi) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->net_change
    if(market_quote_symbol_v3->net_change) {
    if(cJSON_AddNumberToObject(item, "net_change", *market_quote_symbol_v3->net_change) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->total_buy_quantity
    if(market_quote_symbol_v3->total_buy_quantity) {
    if(cJSON_AddNumberToObject(item, "total_buy_quantity", *market_quote_symbol_v3->total_buy_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->total_sell_quantity
    if(market_quote_symbol_v3->total_sell_quantity) {
    if(cJSON_AddNumberToObject(item, "total_sell_quantity", *market_quote_symbol_v3->total_sell_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->lower_circuit_limit
    if(market_quote_symbol_v3->lower_circuit_limit) {
    if(cJSON_AddNumberToObject(item, "lower_circuit_limit", *market_quote_symbol_v3->lower_circuit_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->upper_circuit_limit
    if(market_quote_symbol_v3->upper_circuit_limit) {
    if(cJSON_AddNumberToObject(item, "upper_circuit_limit", *market_quote_symbol_v3->upper_circuit_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->last_trade_time
    if(market_quote_symbol_v3->last_trade_time) {
    if(cJSON_AddStringToObject(item, "last_trade_time", market_quote_symbol_v3->last_trade_time) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol_v3->oi_day_high
    if(market_quote_symbol_v3->oi_day_high) {
    if(cJSON_AddNumberToObject(item, "oi_day_high", *market_quote_symbol_v3->oi_day_high) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->oi_day_low
    if(market_quote_symbol_v3->oi_day_low) {
    if(cJSON_AddNumberToObject(item, "oi_day_low", *market_quote_symbol_v3->oi_day_low) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->prev_close_price
    if(market_quote_symbol_v3->prev_close_price) {
    if(cJSON_AddNumberToObject(item, "prev_close_price", *market_quote_symbol_v3->prev_close_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->year_high
    if(market_quote_symbol_v3->year_high) {
    if(cJSON_AddNumberToObject(item, "year_high", *market_quote_symbol_v3->year_high) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->year_low
    if(market_quote_symbol_v3->year_low) {
    if(cJSON_AddNumberToObject(item, "year_low", *market_quote_symbol_v3->year_low) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->previous_oi
    if(market_quote_symbol_v3->previous_oi) {
    if(cJSON_AddNumberToObject(item, "previous_oi", *market_quote_symbol_v3->previous_oi) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->indicative_equilibrium_price
    if(market_quote_symbol_v3->indicative_equilibrium_price) {
    if(cJSON_AddNumberToObject(item, "indicative_equilibrium_price", *market_quote_symbol_v3->indicative_equilibrium_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->reference_price
    if(market_quote_symbol_v3->reference_price) {
    if(cJSON_AddNumberToObject(item, "reference_price", *market_quote_symbol_v3->reference_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->indicative_equilibrium_quantity
    if(market_quote_symbol_v3->indicative_equilibrium_quantity) {
    if(cJSON_AddNumberToObject(item, "indicative_equilibrium_quantity", *market_quote_symbol_v3->indicative_equilibrium_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->indicative_imbalance_quantity_total
    if(market_quote_symbol_v3->indicative_imbalance_quantity_total) {
    if(cJSON_AddNumberToObject(item, "indicative_imbalance_quantity_total", *market_quote_symbol_v3->indicative_imbalance_quantity_total) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->indicative_imbalance_quantity_market
    if(market_quote_symbol_v3->indicative_imbalance_quantity_market) {
    if(cJSON_AddNumberToObject(item, "indicative_imbalance_quantity_market", *market_quote_symbol_v3->indicative_imbalance_quantity_market) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_v3->cas_eligible
    if(market_quote_symbol_v3->cas_eligible) {
    if(cJSON_AddBoolToObject(item, "cas_eligible", *market_quote_symbol_v3->cas_eligible) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

market_quote_symbol_v3_t *market_quote_symbol_v3_parseFromJSON(cJSON *market_quote_symbol_v3JSON){

    market_quote_symbol_v3_t *market_quote_symbol_v3_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->ohlc
    ohlc_v3_t *ohlc_local_nonprim = NULL;

    // define the local variable for market_quote_symbol_v3->depth
    depth_map_t *depth_local_nonprim = NULL;

    char *timestamp_local_str = NULL;

    char *instrument_token_local_str = NULL;

    char *symbol_local_str = NULL;

    // define the local variable for market_quote_symbol_v3->last_price
    double *last_price_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->volume
    long *volume_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->average_price
    double *average_price_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->oi
    double *oi_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->net_change
    double *net_change_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->total_buy_quantity
    double *total_buy_quantity_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->total_sell_quantity
    double *total_sell_quantity_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->lower_circuit_limit
    double *lower_circuit_limit_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->upper_circuit_limit
    double *upper_circuit_limit_local_var = NULL;

    char *last_trade_time_local_str = NULL;

    // define the local variable for market_quote_symbol_v3->oi_day_high
    double *oi_day_high_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->oi_day_low
    double *oi_day_low_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->prev_close_price
    double *prev_close_price_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->year_high
    double *year_high_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->year_low
    double *year_low_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->previous_oi
    double *previous_oi_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->indicative_equilibrium_price
    double *indicative_equilibrium_price_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->reference_price
    double *reference_price_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->indicative_equilibrium_quantity
    long *indicative_equilibrium_quantity_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->indicative_imbalance_quantity_total
    long *indicative_imbalance_quantity_total_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->indicative_imbalance_quantity_market
    long *indicative_imbalance_quantity_market_local_var = NULL;

    // define the local variable for market_quote_symbol_v3->cas_eligible
    int *cas_eligible_local_var = NULL;

    // market_quote_symbol_v3->ohlc
    cJSON *ohlc = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "ohlc");
    if (cJSON_IsNull(ohlc)) {
        ohlc = NULL;
    }
    if (ohlc) { 
    ohlc_local_nonprim = ohlc_v3_parseFromJSON(ohlc); //nonprimitive
    }

    // market_quote_symbol_v3->depth
    cJSON *depth = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "depth");
    if (cJSON_IsNull(depth)) {
        depth = NULL;
    }
    if (depth) { 
    depth_local_nonprim = depth_map_parseFromJSON(depth); //nonprimitive
    }

    // market_quote_symbol_v3->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "timestamp");
    if (cJSON_IsNull(timestamp)) {
        timestamp = NULL;
    }
    if (timestamp) { 
    if(!cJSON_IsString(timestamp) && !cJSON_IsNull(timestamp))
    {
    goto end; //String
    }
    }

    // market_quote_symbol_v3->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // market_quote_symbol_v3->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // market_quote_symbol_v3->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "last_price");
    if (cJSON_IsNull(last_price)) {
        last_price = NULL;
    }
    if (last_price) { 
    if(!cJSON_IsNumber(last_price))
    {
    goto end; //Numeric
    }
    last_price_local_var = malloc(sizeof(double));
    if(!last_price_local_var)
    {
        goto end;
    }
    *last_price_local_var = last_price->valuedouble;
    }

    // market_quote_symbol_v3->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    if(!cJSON_IsNumber(volume))
    {
    goto end; //Numeric
    }
    volume_local_var = malloc(sizeof(long));
    if(!volume_local_var)
    {
        goto end;
    }
    *volume_local_var = volume->valuedouble;
    }

    // market_quote_symbol_v3->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "average_price");
    if (cJSON_IsNull(average_price)) {
        average_price = NULL;
    }
    if (average_price) { 
    if(!cJSON_IsNumber(average_price))
    {
    goto end; //Numeric
    }
    average_price_local_var = malloc(sizeof(double));
    if(!average_price_local_var)
    {
        goto end;
    }
    *average_price_local_var = average_price->valuedouble;
    }

    // market_quote_symbol_v3->oi
    cJSON *oi = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "oi");
    if (cJSON_IsNull(oi)) {
        oi = NULL;
    }
    if (oi) { 
    if(!cJSON_IsNumber(oi))
    {
    goto end; //Numeric
    }
    oi_local_var = malloc(sizeof(double));
    if(!oi_local_var)
    {
        goto end;
    }
    *oi_local_var = oi->valuedouble;
    }

    // market_quote_symbol_v3->net_change
    cJSON *net_change = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "net_change");
    if (cJSON_IsNull(net_change)) {
        net_change = NULL;
    }
    if (net_change) { 
    if(!cJSON_IsNumber(net_change))
    {
    goto end; //Numeric
    }
    net_change_local_var = malloc(sizeof(double));
    if(!net_change_local_var)
    {
        goto end;
    }
    *net_change_local_var = net_change->valuedouble;
    }

    // market_quote_symbol_v3->total_buy_quantity
    cJSON *total_buy_quantity = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "total_buy_quantity");
    if (cJSON_IsNull(total_buy_quantity)) {
        total_buy_quantity = NULL;
    }
    if (total_buy_quantity) { 
    if(!cJSON_IsNumber(total_buy_quantity))
    {
    goto end; //Numeric
    }
    total_buy_quantity_local_var = malloc(sizeof(double));
    if(!total_buy_quantity_local_var)
    {
        goto end;
    }
    *total_buy_quantity_local_var = total_buy_quantity->valuedouble;
    }

    // market_quote_symbol_v3->total_sell_quantity
    cJSON *total_sell_quantity = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "total_sell_quantity");
    if (cJSON_IsNull(total_sell_quantity)) {
        total_sell_quantity = NULL;
    }
    if (total_sell_quantity) { 
    if(!cJSON_IsNumber(total_sell_quantity))
    {
    goto end; //Numeric
    }
    total_sell_quantity_local_var = malloc(sizeof(double));
    if(!total_sell_quantity_local_var)
    {
        goto end;
    }
    *total_sell_quantity_local_var = total_sell_quantity->valuedouble;
    }

    // market_quote_symbol_v3->lower_circuit_limit
    cJSON *lower_circuit_limit = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "lower_circuit_limit");
    if (cJSON_IsNull(lower_circuit_limit)) {
        lower_circuit_limit = NULL;
    }
    if (lower_circuit_limit) { 
    if(!cJSON_IsNumber(lower_circuit_limit))
    {
    goto end; //Numeric
    }
    lower_circuit_limit_local_var = malloc(sizeof(double));
    if(!lower_circuit_limit_local_var)
    {
        goto end;
    }
    *lower_circuit_limit_local_var = lower_circuit_limit->valuedouble;
    }

    // market_quote_symbol_v3->upper_circuit_limit
    cJSON *upper_circuit_limit = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "upper_circuit_limit");
    if (cJSON_IsNull(upper_circuit_limit)) {
        upper_circuit_limit = NULL;
    }
    if (upper_circuit_limit) { 
    if(!cJSON_IsNumber(upper_circuit_limit))
    {
    goto end; //Numeric
    }
    upper_circuit_limit_local_var = malloc(sizeof(double));
    if(!upper_circuit_limit_local_var)
    {
        goto end;
    }
    *upper_circuit_limit_local_var = upper_circuit_limit->valuedouble;
    }

    // market_quote_symbol_v3->last_trade_time
    cJSON *last_trade_time = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "last_trade_time");
    if (cJSON_IsNull(last_trade_time)) {
        last_trade_time = NULL;
    }
    if (last_trade_time) { 
    if(!cJSON_IsString(last_trade_time) && !cJSON_IsNull(last_trade_time))
    {
    goto end; //String
    }
    }

    // market_quote_symbol_v3->oi_day_high
    cJSON *oi_day_high = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "oi_day_high");
    if (cJSON_IsNull(oi_day_high)) {
        oi_day_high = NULL;
    }
    if (oi_day_high) { 
    if(!cJSON_IsNumber(oi_day_high))
    {
    goto end; //Numeric
    }
    oi_day_high_local_var = malloc(sizeof(double));
    if(!oi_day_high_local_var)
    {
        goto end;
    }
    *oi_day_high_local_var = oi_day_high->valuedouble;
    }

    // market_quote_symbol_v3->oi_day_low
    cJSON *oi_day_low = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "oi_day_low");
    if (cJSON_IsNull(oi_day_low)) {
        oi_day_low = NULL;
    }
    if (oi_day_low) { 
    if(!cJSON_IsNumber(oi_day_low))
    {
    goto end; //Numeric
    }
    oi_day_low_local_var = malloc(sizeof(double));
    if(!oi_day_low_local_var)
    {
        goto end;
    }
    *oi_day_low_local_var = oi_day_low->valuedouble;
    }

    // market_quote_symbol_v3->prev_close_price
    cJSON *prev_close_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "prev_close_price");
    if (cJSON_IsNull(prev_close_price)) {
        prev_close_price = NULL;
    }
    if (prev_close_price) { 
    if(!cJSON_IsNumber(prev_close_price))
    {
    goto end; //Numeric
    }
    prev_close_price_local_var = malloc(sizeof(double));
    if(!prev_close_price_local_var)
    {
        goto end;
    }
    *prev_close_price_local_var = prev_close_price->valuedouble;
    }

    // market_quote_symbol_v3->year_high
    cJSON *year_high = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "year_high");
    if (cJSON_IsNull(year_high)) {
        year_high = NULL;
    }
    if (year_high) { 
    if(!cJSON_IsNumber(year_high))
    {
    goto end; //Numeric
    }
    year_high_local_var = malloc(sizeof(double));
    if(!year_high_local_var)
    {
        goto end;
    }
    *year_high_local_var = year_high->valuedouble;
    }

    // market_quote_symbol_v3->year_low
    cJSON *year_low = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "year_low");
    if (cJSON_IsNull(year_low)) {
        year_low = NULL;
    }
    if (year_low) { 
    if(!cJSON_IsNumber(year_low))
    {
    goto end; //Numeric
    }
    year_low_local_var = malloc(sizeof(double));
    if(!year_low_local_var)
    {
        goto end;
    }
    *year_low_local_var = year_low->valuedouble;
    }

    // market_quote_symbol_v3->previous_oi
    cJSON *previous_oi = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "previous_oi");
    if (cJSON_IsNull(previous_oi)) {
        previous_oi = NULL;
    }
    if (previous_oi) { 
    if(!cJSON_IsNumber(previous_oi))
    {
    goto end; //Numeric
    }
    previous_oi_local_var = malloc(sizeof(double));
    if(!previous_oi_local_var)
    {
        goto end;
    }
    *previous_oi_local_var = previous_oi->valuedouble;
    }

    // market_quote_symbol_v3->indicative_equilibrium_price
    cJSON *indicative_equilibrium_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "indicative_equilibrium_price");
    if (cJSON_IsNull(indicative_equilibrium_price)) {
        indicative_equilibrium_price = NULL;
    }
    if (indicative_equilibrium_price) { 
    if(!cJSON_IsNumber(indicative_equilibrium_price))
    {
    goto end; //Numeric
    }
    indicative_equilibrium_price_local_var = malloc(sizeof(double));
    if(!indicative_equilibrium_price_local_var)
    {
        goto end;
    }
    *indicative_equilibrium_price_local_var = indicative_equilibrium_price->valuedouble;
    }

    // market_quote_symbol_v3->reference_price
    cJSON *reference_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "reference_price");
    if (cJSON_IsNull(reference_price)) {
        reference_price = NULL;
    }
    if (reference_price) { 
    if(!cJSON_IsNumber(reference_price))
    {
    goto end; //Numeric
    }
    reference_price_local_var = malloc(sizeof(double));
    if(!reference_price_local_var)
    {
        goto end;
    }
    *reference_price_local_var = reference_price->valuedouble;
    }

    // market_quote_symbol_v3->indicative_equilibrium_quantity
    cJSON *indicative_equilibrium_quantity = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "indicative_equilibrium_quantity");
    if (cJSON_IsNull(indicative_equilibrium_quantity)) {
        indicative_equilibrium_quantity = NULL;
    }
    if (indicative_equilibrium_quantity) { 
    if(!cJSON_IsNumber(indicative_equilibrium_quantity))
    {
    goto end; //Numeric
    }
    indicative_equilibrium_quantity_local_var = malloc(sizeof(long));
    if(!indicative_equilibrium_quantity_local_var)
    {
        goto end;
    }
    *indicative_equilibrium_quantity_local_var = indicative_equilibrium_quantity->valuedouble;
    }

    // market_quote_symbol_v3->indicative_imbalance_quantity_total
    cJSON *indicative_imbalance_quantity_total = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "indicative_imbalance_quantity_total");
    if (cJSON_IsNull(indicative_imbalance_quantity_total)) {
        indicative_imbalance_quantity_total = NULL;
    }
    if (indicative_imbalance_quantity_total) { 
    if(!cJSON_IsNumber(indicative_imbalance_quantity_total))
    {
    goto end; //Numeric
    }
    indicative_imbalance_quantity_total_local_var = malloc(sizeof(long));
    if(!indicative_imbalance_quantity_total_local_var)
    {
        goto end;
    }
    *indicative_imbalance_quantity_total_local_var = indicative_imbalance_quantity_total->valuedouble;
    }

    // market_quote_symbol_v3->indicative_imbalance_quantity_market
    cJSON *indicative_imbalance_quantity_market = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "indicative_imbalance_quantity_market");
    if (cJSON_IsNull(indicative_imbalance_quantity_market)) {
        indicative_imbalance_quantity_market = NULL;
    }
    if (indicative_imbalance_quantity_market) { 
    if(!cJSON_IsNumber(indicative_imbalance_quantity_market))
    {
    goto end; //Numeric
    }
    indicative_imbalance_quantity_market_local_var = malloc(sizeof(long));
    if(!indicative_imbalance_quantity_market_local_var)
    {
        goto end;
    }
    *indicative_imbalance_quantity_market_local_var = indicative_imbalance_quantity_market->valuedouble;
    }

    // market_quote_symbol_v3->cas_eligible
    cJSON *cas_eligible = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_v3JSON, "cas_eligible");
    if (cJSON_IsNull(cas_eligible)) {
        cas_eligible = NULL;
    }
    if (cas_eligible) { 
    if(!cJSON_IsBool(cas_eligible))
    {
    goto end; //Bool
    }
    cas_eligible_local_var = malloc(sizeof(int));
    if(!cas_eligible_local_var)
    {
        goto end;
    }
    *cas_eligible_local_var = cas_eligible->valueint;
    }


    if (timestamp && !cJSON_IsNull(timestamp)) timestamp_local_str = strdup(timestamp->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (symbol && !cJSON_IsNull(symbol)) symbol_local_str = strdup(symbol->valuestring);
    if (last_trade_time && !cJSON_IsNull(last_trade_time)) last_trade_time_local_str = strdup(last_trade_time->valuestring);

    market_quote_symbol_v3_local_var = market_quote_symbol_v3_create_internal (
        ohlc ? ohlc_local_nonprim : NULL,
        depth ? depth_local_nonprim : NULL,
        timestamp_local_str,
        instrument_token_local_str,
        symbol_local_str,
        last_price_local_var,
        volume_local_var,
        average_price_local_var,
        oi_local_var,
        net_change_local_var,
        total_buy_quantity_local_var,
        total_sell_quantity_local_var,
        lower_circuit_limit_local_var,
        upper_circuit_limit_local_var,
        last_trade_time_local_str,
        oi_day_high_local_var,
        oi_day_low_local_var,
        prev_close_price_local_var,
        year_high_local_var,
        year_low_local_var,
        previous_oi_local_var,
        indicative_equilibrium_price_local_var,
        reference_price_local_var,
        indicative_equilibrium_quantity_local_var,
        indicative_imbalance_quantity_total_local_var,
        indicative_imbalance_quantity_market_local_var,
        cas_eligible_local_var
        );

    if (!market_quote_symbol_v3_local_var) {
        goto end;
    }

    return market_quote_symbol_v3_local_var;
end:
    if (ohlc_local_nonprim) {
        ohlc_v3_free(ohlc_local_nonprim);
        ohlc_local_nonprim = NULL;
    }
    if (depth_local_nonprim) {
        depth_map_free(depth_local_nonprim);
        depth_local_nonprim = NULL;
    }
    if (timestamp_local_str) {
        free(timestamp_local_str);
        timestamp_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (symbol_local_str) {
        free(symbol_local_str);
        symbol_local_str = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (volume_local_var) {
        free(volume_local_var);
        volume_local_var = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (oi_local_var) {
        free(oi_local_var);
        oi_local_var = NULL;
    }
    if (net_change_local_var) {
        free(net_change_local_var);
        net_change_local_var = NULL;
    }
    if (total_buy_quantity_local_var) {
        free(total_buy_quantity_local_var);
        total_buy_quantity_local_var = NULL;
    }
    if (total_sell_quantity_local_var) {
        free(total_sell_quantity_local_var);
        total_sell_quantity_local_var = NULL;
    }
    if (lower_circuit_limit_local_var) {
        free(lower_circuit_limit_local_var);
        lower_circuit_limit_local_var = NULL;
    }
    if (upper_circuit_limit_local_var) {
        free(upper_circuit_limit_local_var);
        upper_circuit_limit_local_var = NULL;
    }
    if (last_trade_time_local_str) {
        free(last_trade_time_local_str);
        last_trade_time_local_str = NULL;
    }
    if (oi_day_high_local_var) {
        free(oi_day_high_local_var);
        oi_day_high_local_var = NULL;
    }
    if (oi_day_low_local_var) {
        free(oi_day_low_local_var);
        oi_day_low_local_var = NULL;
    }
    if (prev_close_price_local_var) {
        free(prev_close_price_local_var);
        prev_close_price_local_var = NULL;
    }
    if (year_high_local_var) {
        free(year_high_local_var);
        year_high_local_var = NULL;
    }
    if (year_low_local_var) {
        free(year_low_local_var);
        year_low_local_var = NULL;
    }
    if (previous_oi_local_var) {
        free(previous_oi_local_var);
        previous_oi_local_var = NULL;
    }
    if (indicative_equilibrium_price_local_var) {
        free(indicative_equilibrium_price_local_var);
        indicative_equilibrium_price_local_var = NULL;
    }
    if (reference_price_local_var) {
        free(reference_price_local_var);
        reference_price_local_var = NULL;
    }
    if (indicative_equilibrium_quantity_local_var) {
        free(indicative_equilibrium_quantity_local_var);
        indicative_equilibrium_quantity_local_var = NULL;
    }
    if (indicative_imbalance_quantity_total_local_var) {
        free(indicative_imbalance_quantity_total_local_var);
        indicative_imbalance_quantity_total_local_var = NULL;
    }
    if (indicative_imbalance_quantity_market_local_var) {
        free(indicative_imbalance_quantity_market_local_var);
        indicative_imbalance_quantity_market_local_var = NULL;
    }
    if (cas_eligible_local_var) {
        free(cas_eligible_local_var);
        cas_eligible_local_var = NULL;
    }
    return NULL;

}
