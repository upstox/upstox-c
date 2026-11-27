#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_symbol.h"



static market_quote_symbol_t *market_quote_symbol_create_internal(
    ohlc_t *ohlc,
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
    double *oi_day_low
    ) {
    market_quote_symbol_t *market_quote_symbol_local_var = malloc(sizeof(market_quote_symbol_t));
    if (!market_quote_symbol_local_var) {
        return NULL;
    }
    memset(market_quote_symbol_local_var, 0, sizeof(market_quote_symbol_t));
    market_quote_symbol_local_var->_library_owned = 1;
    market_quote_symbol_local_var->ohlc = ohlc;
    market_quote_symbol_local_var->depth = depth;
    market_quote_symbol_local_var->timestamp = timestamp;
    market_quote_symbol_local_var->instrument_token = instrument_token;
    market_quote_symbol_local_var->symbol = symbol;
    market_quote_symbol_local_var->last_price = last_price;
    market_quote_symbol_local_var->volume = volume;
    market_quote_symbol_local_var->average_price = average_price;
    market_quote_symbol_local_var->oi = oi;
    market_quote_symbol_local_var->net_change = net_change;
    market_quote_symbol_local_var->total_buy_quantity = total_buy_quantity;
    market_quote_symbol_local_var->total_sell_quantity = total_sell_quantity;
    market_quote_symbol_local_var->lower_circuit_limit = lower_circuit_limit;
    market_quote_symbol_local_var->upper_circuit_limit = upper_circuit_limit;
    market_quote_symbol_local_var->last_trade_time = last_trade_time;
    market_quote_symbol_local_var->oi_day_high = oi_day_high;
    market_quote_symbol_local_var->oi_day_low = oi_day_low;
    return market_quote_symbol_local_var;
}

market_quote_symbol_t *market_quote_symbol_create(
    ohlc_t *ohlc,
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
    double *oi_day_low
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
    market_quote_symbol_t *result = market_quote_symbol_create_internal (
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
        oi_day_low_copy
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
    }
    return result;
}

void market_quote_symbol_free(market_quote_symbol_t *market_quote_symbol) {
    if(NULL == market_quote_symbol){
        return ;
    }
    if(market_quote_symbol->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_symbol_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_symbol->ohlc) {
        ohlc_free(market_quote_symbol->ohlc);
        market_quote_symbol->ohlc = NULL;
    }
    if (market_quote_symbol->depth) {
        depth_map_free(market_quote_symbol->depth);
        market_quote_symbol->depth = NULL;
    }
    if (market_quote_symbol->timestamp) {
        free(market_quote_symbol->timestamp);
        market_quote_symbol->timestamp = NULL;
    }
    if (market_quote_symbol->instrument_token) {
        free(market_quote_symbol->instrument_token);
        market_quote_symbol->instrument_token = NULL;
    }
    if (market_quote_symbol->symbol) {
        free(market_quote_symbol->symbol);
        market_quote_symbol->symbol = NULL;
    }
    if (market_quote_symbol->last_price) {
        free(market_quote_symbol->last_price);
        market_quote_symbol->last_price = NULL;
    }
    if (market_quote_symbol->volume) {
        free(market_quote_symbol->volume);
        market_quote_symbol->volume = NULL;
    }
    if (market_quote_symbol->average_price) {
        free(market_quote_symbol->average_price);
        market_quote_symbol->average_price = NULL;
    }
    if (market_quote_symbol->oi) {
        free(market_quote_symbol->oi);
        market_quote_symbol->oi = NULL;
    }
    if (market_quote_symbol->net_change) {
        free(market_quote_symbol->net_change);
        market_quote_symbol->net_change = NULL;
    }
    if (market_quote_symbol->total_buy_quantity) {
        free(market_quote_symbol->total_buy_quantity);
        market_quote_symbol->total_buy_quantity = NULL;
    }
    if (market_quote_symbol->total_sell_quantity) {
        free(market_quote_symbol->total_sell_quantity);
        market_quote_symbol->total_sell_quantity = NULL;
    }
    if (market_quote_symbol->lower_circuit_limit) {
        free(market_quote_symbol->lower_circuit_limit);
        market_quote_symbol->lower_circuit_limit = NULL;
    }
    if (market_quote_symbol->upper_circuit_limit) {
        free(market_quote_symbol->upper_circuit_limit);
        market_quote_symbol->upper_circuit_limit = NULL;
    }
    if (market_quote_symbol->last_trade_time) {
        free(market_quote_symbol->last_trade_time);
        market_quote_symbol->last_trade_time = NULL;
    }
    if (market_quote_symbol->oi_day_high) {
        free(market_quote_symbol->oi_day_high);
        market_quote_symbol->oi_day_high = NULL;
    }
    if (market_quote_symbol->oi_day_low) {
        free(market_quote_symbol->oi_day_low);
        market_quote_symbol->oi_day_low = NULL;
    }
    free(market_quote_symbol);
}

cJSON *market_quote_symbol_convertToJSON(market_quote_symbol_t *market_quote_symbol) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_symbol->ohlc
    if(market_quote_symbol->ohlc) {
    cJSON *ohlc_local_JSON = ohlc_convertToJSON(market_quote_symbol->ohlc);
    if(ohlc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ohlc", ohlc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_symbol->depth
    if(market_quote_symbol->depth) {
    cJSON *depth_local_JSON = depth_map_convertToJSON(market_quote_symbol->depth);
    if(depth_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "depth", depth_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_symbol->timestamp
    if(market_quote_symbol->timestamp) {
    if(cJSON_AddStringToObject(item, "timestamp", market_quote_symbol->timestamp) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol->instrument_token
    if(market_quote_symbol->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_symbol->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol->symbol
    if(market_quote_symbol->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", market_quote_symbol->symbol) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol->last_price
    if(market_quote_symbol->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_symbol->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->volume
    if(market_quote_symbol->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *market_quote_symbol->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->average_price
    if(market_quote_symbol->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *market_quote_symbol->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->oi
    if(market_quote_symbol->oi) {
    if(cJSON_AddNumberToObject(item, "oi", *market_quote_symbol->oi) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->net_change
    if(market_quote_symbol->net_change) {
    if(cJSON_AddNumberToObject(item, "net_change", *market_quote_symbol->net_change) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->total_buy_quantity
    if(market_quote_symbol->total_buy_quantity) {
    if(cJSON_AddNumberToObject(item, "total_buy_quantity", *market_quote_symbol->total_buy_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->total_sell_quantity
    if(market_quote_symbol->total_sell_quantity) {
    if(cJSON_AddNumberToObject(item, "total_sell_quantity", *market_quote_symbol->total_sell_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->lower_circuit_limit
    if(market_quote_symbol->lower_circuit_limit) {
    if(cJSON_AddNumberToObject(item, "lower_circuit_limit", *market_quote_symbol->lower_circuit_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->upper_circuit_limit
    if(market_quote_symbol->upper_circuit_limit) {
    if(cJSON_AddNumberToObject(item, "upper_circuit_limit", *market_quote_symbol->upper_circuit_limit) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->last_trade_time
    if(market_quote_symbol->last_trade_time) {
    if(cJSON_AddStringToObject(item, "last_trade_time", market_quote_symbol->last_trade_time) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol->oi_day_high
    if(market_quote_symbol->oi_day_high) {
    if(cJSON_AddNumberToObject(item, "oi_day_high", *market_quote_symbol->oi_day_high) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol->oi_day_low
    if(market_quote_symbol->oi_day_low) {
    if(cJSON_AddNumberToObject(item, "oi_day_low", *market_quote_symbol->oi_day_low) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

market_quote_symbol_t *market_quote_symbol_parseFromJSON(cJSON *market_quote_symbolJSON){

    market_quote_symbol_t *market_quote_symbol_local_var = NULL;

    // define the local variable for market_quote_symbol->ohlc
    ohlc_t *ohlc_local_nonprim = NULL;

    // define the local variable for market_quote_symbol->depth
    depth_map_t *depth_local_nonprim = NULL;

    char *timestamp_local_str = NULL;

    char *instrument_token_local_str = NULL;

    char *symbol_local_str = NULL;

    // define the local variable for market_quote_symbol->last_price
    double *last_price_local_var = NULL;

    // define the local variable for market_quote_symbol->volume
    long *volume_local_var = NULL;

    // define the local variable for market_quote_symbol->average_price
    double *average_price_local_var = NULL;

    // define the local variable for market_quote_symbol->oi
    double *oi_local_var = NULL;

    // define the local variable for market_quote_symbol->net_change
    double *net_change_local_var = NULL;

    // define the local variable for market_quote_symbol->total_buy_quantity
    double *total_buy_quantity_local_var = NULL;

    // define the local variable for market_quote_symbol->total_sell_quantity
    double *total_sell_quantity_local_var = NULL;

    // define the local variable for market_quote_symbol->lower_circuit_limit
    double *lower_circuit_limit_local_var = NULL;

    // define the local variable for market_quote_symbol->upper_circuit_limit
    double *upper_circuit_limit_local_var = NULL;

    char *last_trade_time_local_str = NULL;

    // define the local variable for market_quote_symbol->oi_day_high
    double *oi_day_high_local_var = NULL;

    // define the local variable for market_quote_symbol->oi_day_low
    double *oi_day_low_local_var = NULL;

    // market_quote_symbol->ohlc
    cJSON *ohlc = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "ohlc");
    if (cJSON_IsNull(ohlc)) {
        ohlc = NULL;
    }
    if (ohlc) { 
    ohlc_local_nonprim = ohlc_parseFromJSON(ohlc); //nonprimitive
    }

    // market_quote_symbol->depth
    cJSON *depth = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "depth");
    if (cJSON_IsNull(depth)) {
        depth = NULL;
    }
    if (depth) { 
    depth_local_nonprim = depth_map_parseFromJSON(depth); //nonprimitive
    }

    // market_quote_symbol->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "timestamp");
    if (cJSON_IsNull(timestamp)) {
        timestamp = NULL;
    }
    if (timestamp) { 
    if(!cJSON_IsString(timestamp) && !cJSON_IsNull(timestamp))
    {
    goto end; //String
    }
    }

    // market_quote_symbol->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // market_quote_symbol->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // market_quote_symbol->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "last_price");
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

    // market_quote_symbol->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "volume");
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

    // market_quote_symbol->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "average_price");
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

    // market_quote_symbol->oi
    cJSON *oi = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "oi");
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

    // market_quote_symbol->net_change
    cJSON *net_change = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "net_change");
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

    // market_quote_symbol->total_buy_quantity
    cJSON *total_buy_quantity = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "total_buy_quantity");
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

    // market_quote_symbol->total_sell_quantity
    cJSON *total_sell_quantity = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "total_sell_quantity");
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

    // market_quote_symbol->lower_circuit_limit
    cJSON *lower_circuit_limit = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "lower_circuit_limit");
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

    // market_quote_symbol->upper_circuit_limit
    cJSON *upper_circuit_limit = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "upper_circuit_limit");
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

    // market_quote_symbol->last_trade_time
    cJSON *last_trade_time = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "last_trade_time");
    if (cJSON_IsNull(last_trade_time)) {
        last_trade_time = NULL;
    }
    if (last_trade_time) { 
    if(!cJSON_IsString(last_trade_time) && !cJSON_IsNull(last_trade_time))
    {
    goto end; //String
    }
    }

    // market_quote_symbol->oi_day_high
    cJSON *oi_day_high = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "oi_day_high");
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

    // market_quote_symbol->oi_day_low
    cJSON *oi_day_low = cJSON_GetObjectItemCaseSensitive(market_quote_symbolJSON, "oi_day_low");
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


    if (timestamp && !cJSON_IsNull(timestamp)) timestamp_local_str = strdup(timestamp->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (symbol && !cJSON_IsNull(symbol)) symbol_local_str = strdup(symbol->valuestring);
    if (last_trade_time && !cJSON_IsNull(last_trade_time)) last_trade_time_local_str = strdup(last_trade_time->valuestring);

    market_quote_symbol_local_var = market_quote_symbol_create_internal (
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
        oi_day_low_local_var
        );

    if (!market_quote_symbol_local_var) {
        goto end;
    }

    return market_quote_symbol_local_var;
end:
    if (ohlc_local_nonprim) {
        ohlc_free(ohlc_local_nonprim);
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
    return NULL;

}
