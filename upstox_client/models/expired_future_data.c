#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expired_future_data.h"



static expired_future_data_t *expired_future_data_create_internal(
    char *name,
    char *segment,
    char *exchange,
    char *expiry,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    long *minimum_lot
    ) {
    expired_future_data_t *expired_future_data_local_var = malloc(sizeof(expired_future_data_t));
    if (!expired_future_data_local_var) {
        return NULL;
    }
    memset(expired_future_data_local_var, 0, sizeof(expired_future_data_t));
    expired_future_data_local_var->_library_owned = 1;
    expired_future_data_local_var->name = name;
    expired_future_data_local_var->segment = segment;
    expired_future_data_local_var->exchange = exchange;
    expired_future_data_local_var->expiry = expiry;
    expired_future_data_local_var->instrument_key = instrument_key;
    expired_future_data_local_var->exchange_token = exchange_token;
    expired_future_data_local_var->trading_symbol = trading_symbol;
    expired_future_data_local_var->tick_size = tick_size;
    expired_future_data_local_var->lot_size = lot_size;
    expired_future_data_local_var->instrument_type = instrument_type;
    expired_future_data_local_var->freeze_quantity = freeze_quantity;
    expired_future_data_local_var->underlying_key = underlying_key;
    expired_future_data_local_var->underlying_type = underlying_type;
    expired_future_data_local_var->underlying_symbol = underlying_symbol;
    expired_future_data_local_var->minimum_lot = minimum_lot;
    return expired_future_data_local_var;
}

expired_future_data_t *expired_future_data_create(
    char *name,
    char *segment,
    char *exchange,
    char *expiry,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    long *minimum_lot
    ) {
    double *tick_size_copy = NULL;
    if (tick_size) {
        tick_size_copy = malloc(sizeof(double));
        if (tick_size_copy) *tick_size_copy = *tick_size;
    }
    long *lot_size_copy = NULL;
    if (lot_size) {
        lot_size_copy = malloc(sizeof(long));
        if (lot_size_copy) *lot_size_copy = *lot_size;
    }
    double *freeze_quantity_copy = NULL;
    if (freeze_quantity) {
        freeze_quantity_copy = malloc(sizeof(double));
        if (freeze_quantity_copy) *freeze_quantity_copy = *freeze_quantity;
    }
    long *minimum_lot_copy = NULL;
    if (minimum_lot) {
        minimum_lot_copy = malloc(sizeof(long));
        if (minimum_lot_copy) *minimum_lot_copy = *minimum_lot;
    }
    expired_future_data_t *result = expired_future_data_create_internal (
        name,
        segment,
        exchange,
        expiry,
        instrument_key,
        exchange_token,
        trading_symbol,
        tick_size_copy,
        lot_size_copy,
        instrument_type,
        freeze_quantity_copy,
        underlying_key,
        underlying_type,
        underlying_symbol,
        minimum_lot_copy
        );
    if (!result) {
        free(tick_size_copy);
        free(lot_size_copy);
        free(freeze_quantity_copy);
        free(minimum_lot_copy);
    }
    return result;
}

void expired_future_data_free(expired_future_data_t *expired_future_data) {
    if(NULL == expired_future_data){
        return ;
    }
    if(expired_future_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "expired_future_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (expired_future_data->name) {
        free(expired_future_data->name);
        expired_future_data->name = NULL;
    }
    if (expired_future_data->segment) {
        free(expired_future_data->segment);
        expired_future_data->segment = NULL;
    }
    if (expired_future_data->exchange) {
        free(expired_future_data->exchange);
        expired_future_data->exchange = NULL;
    }
    if (expired_future_data->expiry) {
        free(expired_future_data->expiry);
        expired_future_data->expiry = NULL;
    }
    if (expired_future_data->instrument_key) {
        free(expired_future_data->instrument_key);
        expired_future_data->instrument_key = NULL;
    }
    if (expired_future_data->exchange_token) {
        free(expired_future_data->exchange_token);
        expired_future_data->exchange_token = NULL;
    }
    if (expired_future_data->trading_symbol) {
        free(expired_future_data->trading_symbol);
        expired_future_data->trading_symbol = NULL;
    }
    if (expired_future_data->tick_size) {
        free(expired_future_data->tick_size);
        expired_future_data->tick_size = NULL;
    }
    if (expired_future_data->lot_size) {
        free(expired_future_data->lot_size);
        expired_future_data->lot_size = NULL;
    }
    if (expired_future_data->instrument_type) {
        free(expired_future_data->instrument_type);
        expired_future_data->instrument_type = NULL;
    }
    if (expired_future_data->freeze_quantity) {
        free(expired_future_data->freeze_quantity);
        expired_future_data->freeze_quantity = NULL;
    }
    if (expired_future_data->underlying_key) {
        free(expired_future_data->underlying_key);
        expired_future_data->underlying_key = NULL;
    }
    if (expired_future_data->underlying_type) {
        free(expired_future_data->underlying_type);
        expired_future_data->underlying_type = NULL;
    }
    if (expired_future_data->underlying_symbol) {
        free(expired_future_data->underlying_symbol);
        expired_future_data->underlying_symbol = NULL;
    }
    if (expired_future_data->minimum_lot) {
        free(expired_future_data->minimum_lot);
        expired_future_data->minimum_lot = NULL;
    }
    free(expired_future_data);
}

cJSON *expired_future_data_convertToJSON(expired_future_data_t *expired_future_data) {
    cJSON *item = cJSON_CreateObject();

    // expired_future_data->name
    if(expired_future_data->name) {
    if(cJSON_AddStringToObject(item, "name", expired_future_data->name) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->segment
    if(expired_future_data->segment) {
    if(cJSON_AddStringToObject(item, "segment", expired_future_data->segment) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->exchange
    if(expired_future_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", expired_future_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->expiry
    if(expired_future_data->expiry) {
    if(cJSON_AddStringToObject(item, "expiry", expired_future_data->expiry) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->instrument_key
    if(expired_future_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", expired_future_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->exchange_token
    if(expired_future_data->exchange_token) {
    if(cJSON_AddStringToObject(item, "exchange_token", expired_future_data->exchange_token) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->trading_symbol
    if(expired_future_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", expired_future_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->tick_size
    if(expired_future_data->tick_size) {
    if(cJSON_AddNumberToObject(item, "tick_size", *expired_future_data->tick_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // expired_future_data->lot_size
    if(expired_future_data->lot_size) {
    if(cJSON_AddNumberToObject(item, "lot_size", *expired_future_data->lot_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // expired_future_data->instrument_type
    if(expired_future_data->instrument_type) {
    if(cJSON_AddStringToObject(item, "instrument_type", expired_future_data->instrument_type) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->freeze_quantity
    if(expired_future_data->freeze_quantity) {
    if(cJSON_AddNumberToObject(item, "freeze_quantity", *expired_future_data->freeze_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // expired_future_data->underlying_key
    if(expired_future_data->underlying_key) {
    if(cJSON_AddStringToObject(item, "underlying_key", expired_future_data->underlying_key) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->underlying_type
    if(expired_future_data->underlying_type) {
    if(cJSON_AddStringToObject(item, "underlying_type", expired_future_data->underlying_type) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->underlying_symbol
    if(expired_future_data->underlying_symbol) {
    if(cJSON_AddStringToObject(item, "underlying_symbol", expired_future_data->underlying_symbol) == NULL) {
    goto fail; //String
    }
    }


    // expired_future_data->minimum_lot
    if(expired_future_data->minimum_lot) {
    if(cJSON_AddNumberToObject(item, "minimum_lot", *expired_future_data->minimum_lot) == NULL) {
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

expired_future_data_t *expired_future_data_parseFromJSON(cJSON *expired_future_dataJSON){

    expired_future_data_t *expired_future_data_local_var = NULL;

    char *name_local_str = NULL;

    char *segment_local_str = NULL;

    char *exchange_local_str = NULL;

    char *expiry_local_str = NULL;

    char *instrument_key_local_str = NULL;

    char *exchange_token_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    // define the local variable for expired_future_data->tick_size
    double *tick_size_local_var = NULL;

    // define the local variable for expired_future_data->lot_size
    long *lot_size_local_var = NULL;

    char *instrument_type_local_str = NULL;

    // define the local variable for expired_future_data->freeze_quantity
    double *freeze_quantity_local_var = NULL;

    char *underlying_key_local_str = NULL;

    char *underlying_type_local_str = NULL;

    char *underlying_symbol_local_str = NULL;

    // define the local variable for expired_future_data->minimum_lot
    long *minimum_lot_local_var = NULL;

    // expired_future_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // expired_future_data->segment
    cJSON *segment = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "segment");
    if (cJSON_IsNull(segment)) {
        segment = NULL;
    }
    if (segment) { 
    if(!cJSON_IsString(segment) && !cJSON_IsNull(segment))
    {
    goto end; //String
    }
    }

    // expired_future_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // expired_future_data->expiry
    cJSON *expiry = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "expiry");
    if (cJSON_IsNull(expiry)) {
        expiry = NULL;
    }
    if (expiry) { 
    if(!cJSON_IsString(expiry) && !cJSON_IsNull(expiry))
    {
    goto end; //String
    }
    }

    // expired_future_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // expired_future_data->exchange_token
    cJSON *exchange_token = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "exchange_token");
    if (cJSON_IsNull(exchange_token)) {
        exchange_token = NULL;
    }
    if (exchange_token) { 
    if(!cJSON_IsString(exchange_token) && !cJSON_IsNull(exchange_token))
    {
    goto end; //String
    }
    }

    // expired_future_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // expired_future_data->tick_size
    cJSON *tick_size = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "tick_size");
    if (cJSON_IsNull(tick_size)) {
        tick_size = NULL;
    }
    if (tick_size) { 
    if(!cJSON_IsNumber(tick_size))
    {
    goto end; //Numeric
    }
    tick_size_local_var = malloc(sizeof(double));
    if(!tick_size_local_var)
    {
        goto end;
    }
    *tick_size_local_var = tick_size->valuedouble;
    }

    // expired_future_data->lot_size
    cJSON *lot_size = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "lot_size");
    if (cJSON_IsNull(lot_size)) {
        lot_size = NULL;
    }
    if (lot_size) { 
    if(!cJSON_IsNumber(lot_size))
    {
    goto end; //Numeric
    }
    lot_size_local_var = malloc(sizeof(long));
    if(!lot_size_local_var)
    {
        goto end;
    }
    *lot_size_local_var = lot_size->valuedouble;
    }

    // expired_future_data->instrument_type
    cJSON *instrument_type = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "instrument_type");
    if (cJSON_IsNull(instrument_type)) {
        instrument_type = NULL;
    }
    if (instrument_type) { 
    if(!cJSON_IsString(instrument_type) && !cJSON_IsNull(instrument_type))
    {
    goto end; //String
    }
    }

    // expired_future_data->freeze_quantity
    cJSON *freeze_quantity = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "freeze_quantity");
    if (cJSON_IsNull(freeze_quantity)) {
        freeze_quantity = NULL;
    }
    if (freeze_quantity) { 
    if(!cJSON_IsNumber(freeze_quantity))
    {
    goto end; //Numeric
    }
    freeze_quantity_local_var = malloc(sizeof(double));
    if(!freeze_quantity_local_var)
    {
        goto end;
    }
    *freeze_quantity_local_var = freeze_quantity->valuedouble;
    }

    // expired_future_data->underlying_key
    cJSON *underlying_key = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "underlying_key");
    if (cJSON_IsNull(underlying_key)) {
        underlying_key = NULL;
    }
    if (underlying_key) { 
    if(!cJSON_IsString(underlying_key) && !cJSON_IsNull(underlying_key))
    {
    goto end; //String
    }
    }

    // expired_future_data->underlying_type
    cJSON *underlying_type = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "underlying_type");
    if (cJSON_IsNull(underlying_type)) {
        underlying_type = NULL;
    }
    if (underlying_type) { 
    if(!cJSON_IsString(underlying_type) && !cJSON_IsNull(underlying_type))
    {
    goto end; //String
    }
    }

    // expired_future_data->underlying_symbol
    cJSON *underlying_symbol = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "underlying_symbol");
    if (cJSON_IsNull(underlying_symbol)) {
        underlying_symbol = NULL;
    }
    if (underlying_symbol) { 
    if(!cJSON_IsString(underlying_symbol) && !cJSON_IsNull(underlying_symbol))
    {
    goto end; //String
    }
    }

    // expired_future_data->minimum_lot
    cJSON *minimum_lot = cJSON_GetObjectItemCaseSensitive(expired_future_dataJSON, "minimum_lot");
    if (cJSON_IsNull(minimum_lot)) {
        minimum_lot = NULL;
    }
    if (minimum_lot) { 
    if(!cJSON_IsNumber(minimum_lot))
    {
    goto end; //Numeric
    }
    minimum_lot_local_var = malloc(sizeof(long));
    if(!minimum_lot_local_var)
    {
        goto end;
    }
    *minimum_lot_local_var = minimum_lot->valuedouble;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (segment && !cJSON_IsNull(segment)) segment_local_str = strdup(segment->valuestring);
    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (expiry && !cJSON_IsNull(expiry)) expiry_local_str = strdup(expiry->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (exchange_token && !cJSON_IsNull(exchange_token)) exchange_token_local_str = strdup(exchange_token->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (instrument_type && !cJSON_IsNull(instrument_type)) instrument_type_local_str = strdup(instrument_type->valuestring);
    if (underlying_key && !cJSON_IsNull(underlying_key)) underlying_key_local_str = strdup(underlying_key->valuestring);
    if (underlying_type && !cJSON_IsNull(underlying_type)) underlying_type_local_str = strdup(underlying_type->valuestring);
    if (underlying_symbol && !cJSON_IsNull(underlying_symbol)) underlying_symbol_local_str = strdup(underlying_symbol->valuestring);

    expired_future_data_local_var = expired_future_data_create_internal (
        name_local_str,
        segment_local_str,
        exchange_local_str,
        expiry_local_str,
        instrument_key_local_str,
        exchange_token_local_str,
        trading_symbol_local_str,
        tick_size_local_var,
        lot_size_local_var,
        instrument_type_local_str,
        freeze_quantity_local_var,
        underlying_key_local_str,
        underlying_type_local_str,
        underlying_symbol_local_str,
        minimum_lot_local_var
        );

    if (!expired_future_data_local_var) {
        goto end;
    }

    return expired_future_data_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (segment_local_str) {
        free(segment_local_str);
        segment_local_str = NULL;
    }
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (expiry_local_str) {
        free(expiry_local_str);
        expiry_local_str = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (exchange_token_local_str) {
        free(exchange_token_local_str);
        exchange_token_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (tick_size_local_var) {
        free(tick_size_local_var);
        tick_size_local_var = NULL;
    }
    if (lot_size_local_var) {
        free(lot_size_local_var);
        lot_size_local_var = NULL;
    }
    if (instrument_type_local_str) {
        free(instrument_type_local_str);
        instrument_type_local_str = NULL;
    }
    if (freeze_quantity_local_var) {
        free(freeze_quantity_local_var);
        freeze_quantity_local_var = NULL;
    }
    if (underlying_key_local_str) {
        free(underlying_key_local_str);
        underlying_key_local_str = NULL;
    }
    if (underlying_type_local_str) {
        free(underlying_type_local_str);
        underlying_type_local_str = NULL;
    }
    if (underlying_symbol_local_str) {
        free(underlying_symbol_local_str);
        underlying_symbol_local_str = NULL;
    }
    if (minimum_lot_local_var) {
        free(minimum_lot_local_var);
        minimum_lot_local_var = NULL;
    }
    return NULL;

}
