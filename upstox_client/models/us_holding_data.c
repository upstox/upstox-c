#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_holding_data.h"



static us_holding_data_t *us_holding_data_create_internal(
    char *exchange,
    double *quantity,
    double *pnl,
    char *instrument_key,
    char *trading_symbol,
    char *company_name,
    double *average_price,
    double *available_quantity,
    char *transaction_type,
    double *invested_value,
    double *last_price,
    double *previous_close,
    double *current_value,
    double *day_pnl
    ) {
    us_holding_data_t *us_holding_data_local_var = malloc(sizeof(us_holding_data_t));
    if (!us_holding_data_local_var) {
        return NULL;
    }
    memset(us_holding_data_local_var, 0, sizeof(us_holding_data_t));
    us_holding_data_local_var->_library_owned = 1;
    us_holding_data_local_var->exchange = exchange;
    us_holding_data_local_var->quantity = quantity;
    us_holding_data_local_var->pnl = pnl;
    us_holding_data_local_var->instrument_key = instrument_key;
    us_holding_data_local_var->trading_symbol = trading_symbol;
    us_holding_data_local_var->company_name = company_name;
    us_holding_data_local_var->average_price = average_price;
    us_holding_data_local_var->available_quantity = available_quantity;
    us_holding_data_local_var->transaction_type = transaction_type;
    us_holding_data_local_var->invested_value = invested_value;
    us_holding_data_local_var->last_price = last_price;
    us_holding_data_local_var->previous_close = previous_close;
    us_holding_data_local_var->current_value = current_value;
    us_holding_data_local_var->day_pnl = day_pnl;
    return us_holding_data_local_var;
}

us_holding_data_t *us_holding_data_create(
    char *exchange,
    double *quantity,
    double *pnl,
    char *instrument_key,
    char *trading_symbol,
    char *company_name,
    double *average_price,
    double *available_quantity,
    char *transaction_type,
    double *invested_value,
    double *last_price,
    double *previous_close,
    double *current_value,
    double *day_pnl
    ) {
    double *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(double));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *pnl_copy = NULL;
    if (pnl) {
        pnl_copy = malloc(sizeof(double));
        if (pnl_copy) *pnl_copy = *pnl;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    double *available_quantity_copy = NULL;
    if (available_quantity) {
        available_quantity_copy = malloc(sizeof(double));
        if (available_quantity_copy) *available_quantity_copy = *available_quantity;
    }
    double *invested_value_copy = NULL;
    if (invested_value) {
        invested_value_copy = malloc(sizeof(double));
        if (invested_value_copy) *invested_value_copy = *invested_value;
    }
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    double *previous_close_copy = NULL;
    if (previous_close) {
        previous_close_copy = malloc(sizeof(double));
        if (previous_close_copy) *previous_close_copy = *previous_close;
    }
    double *current_value_copy = NULL;
    if (current_value) {
        current_value_copy = malloc(sizeof(double));
        if (current_value_copy) *current_value_copy = *current_value;
    }
    double *day_pnl_copy = NULL;
    if (day_pnl) {
        day_pnl_copy = malloc(sizeof(double));
        if (day_pnl_copy) *day_pnl_copy = *day_pnl;
    }
    us_holding_data_t *result = us_holding_data_create_internal (
        exchange,
        quantity_copy,
        pnl_copy,
        instrument_key,
        trading_symbol,
        company_name,
        average_price_copy,
        available_quantity_copy,
        transaction_type,
        invested_value_copy,
        last_price_copy,
        previous_close_copy,
        current_value_copy,
        day_pnl_copy
        );
    if (!result) {
        free(quantity_copy);
        free(pnl_copy);
        free(average_price_copy);
        free(available_quantity_copy);
        free(invested_value_copy);
        free(last_price_copy);
        free(previous_close_copy);
        free(current_value_copy);
        free(day_pnl_copy);
    }
    return result;
}

void us_holding_data_free(us_holding_data_t *us_holding_data) {
    if(NULL == us_holding_data){
        return ;
    }
    if(us_holding_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_holding_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_holding_data->exchange) {
        free(us_holding_data->exchange);
        us_holding_data->exchange = NULL;
    }
    if (us_holding_data->quantity) {
        free(us_holding_data->quantity);
        us_holding_data->quantity = NULL;
    }
    if (us_holding_data->pnl) {
        free(us_holding_data->pnl);
        us_holding_data->pnl = NULL;
    }
    if (us_holding_data->instrument_key) {
        free(us_holding_data->instrument_key);
        us_holding_data->instrument_key = NULL;
    }
    if (us_holding_data->trading_symbol) {
        free(us_holding_data->trading_symbol);
        us_holding_data->trading_symbol = NULL;
    }
    if (us_holding_data->company_name) {
        free(us_holding_data->company_name);
        us_holding_data->company_name = NULL;
    }
    if (us_holding_data->average_price) {
        free(us_holding_data->average_price);
        us_holding_data->average_price = NULL;
    }
    if (us_holding_data->available_quantity) {
        free(us_holding_data->available_quantity);
        us_holding_data->available_quantity = NULL;
    }
    if (us_holding_data->transaction_type) {
        free(us_holding_data->transaction_type);
        us_holding_data->transaction_type = NULL;
    }
    if (us_holding_data->invested_value) {
        free(us_holding_data->invested_value);
        us_holding_data->invested_value = NULL;
    }
    if (us_holding_data->last_price) {
        free(us_holding_data->last_price);
        us_holding_data->last_price = NULL;
    }
    if (us_holding_data->previous_close) {
        free(us_holding_data->previous_close);
        us_holding_data->previous_close = NULL;
    }
    if (us_holding_data->current_value) {
        free(us_holding_data->current_value);
        us_holding_data->current_value = NULL;
    }
    if (us_holding_data->day_pnl) {
        free(us_holding_data->day_pnl);
        us_holding_data->day_pnl = NULL;
    }
    free(us_holding_data);
}

cJSON *us_holding_data_convertToJSON(us_holding_data_t *us_holding_data) {
    cJSON *item = cJSON_CreateObject();

    // us_holding_data->exchange
    if(us_holding_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", us_holding_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // us_holding_data->quantity
    if(us_holding_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *us_holding_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->pnl
    if(us_holding_data->pnl) {
    if(cJSON_AddNumberToObject(item, "pnl", *us_holding_data->pnl) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->instrument_key
    if(us_holding_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", us_holding_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // us_holding_data->trading_symbol
    if(us_holding_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", us_holding_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // us_holding_data->company_name
    if(us_holding_data->company_name) {
    if(cJSON_AddStringToObject(item, "company_name", us_holding_data->company_name) == NULL) {
    goto fail; //String
    }
    }


    // us_holding_data->average_price
    if(us_holding_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *us_holding_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->available_quantity
    if(us_holding_data->available_quantity) {
    if(cJSON_AddNumberToObject(item, "available_quantity", *us_holding_data->available_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->transaction_type
    if(us_holding_data->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", us_holding_data->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // us_holding_data->invested_value
    if(us_holding_data->invested_value) {
    if(cJSON_AddNumberToObject(item, "invested_value", *us_holding_data->invested_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->last_price
    if(us_holding_data->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *us_holding_data->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->previous_close
    if(us_holding_data->previous_close) {
    if(cJSON_AddNumberToObject(item, "previous_close", *us_holding_data->previous_close) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->current_value
    if(us_holding_data->current_value) {
    if(cJSON_AddNumberToObject(item, "current_value", *us_holding_data->current_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_holding_data->day_pnl
    if(us_holding_data->day_pnl) {
    if(cJSON_AddNumberToObject(item, "day_pnl", *us_holding_data->day_pnl) == NULL) {
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

us_holding_data_t *us_holding_data_parseFromJSON(cJSON *us_holding_dataJSON){

    us_holding_data_t *us_holding_data_local_var = NULL;

    char *exchange_local_str = NULL;

    // define the local variable for us_holding_data->quantity
    double *quantity_local_var = NULL;

    // define the local variable for us_holding_data->pnl
    double *pnl_local_var = NULL;

    char *instrument_key_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    char *company_name_local_str = NULL;

    // define the local variable for us_holding_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for us_holding_data->available_quantity
    double *available_quantity_local_var = NULL;

    char *transaction_type_local_str = NULL;

    // define the local variable for us_holding_data->invested_value
    double *invested_value_local_var = NULL;

    // define the local variable for us_holding_data->last_price
    double *last_price_local_var = NULL;

    // define the local variable for us_holding_data->previous_close
    double *previous_close_local_var = NULL;

    // define the local variable for us_holding_data->current_value
    double *current_value_local_var = NULL;

    // define the local variable for us_holding_data->day_pnl
    double *day_pnl_local_var = NULL;

    // us_holding_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // us_holding_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(double));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // us_holding_data->pnl
    cJSON *pnl = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "pnl");
    if (cJSON_IsNull(pnl)) {
        pnl = NULL;
    }
    if (pnl) { 
    if(!cJSON_IsNumber(pnl))
    {
    goto end; //Numeric
    }
    pnl_local_var = malloc(sizeof(double));
    if(!pnl_local_var)
    {
        goto end;
    }
    *pnl_local_var = pnl->valuedouble;
    }

    // us_holding_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // us_holding_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // us_holding_data->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "company_name");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // us_holding_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "average_price");
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

    // us_holding_data->available_quantity
    cJSON *available_quantity = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "available_quantity");
    if (cJSON_IsNull(available_quantity)) {
        available_quantity = NULL;
    }
    if (available_quantity) { 
    if(!cJSON_IsNumber(available_quantity))
    {
    goto end; //Numeric
    }
    available_quantity_local_var = malloc(sizeof(double));
    if(!available_quantity_local_var)
    {
        goto end;
    }
    *available_quantity_local_var = available_quantity->valuedouble;
    }

    // us_holding_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // us_holding_data->invested_value
    cJSON *invested_value = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "invested_value");
    if (cJSON_IsNull(invested_value)) {
        invested_value = NULL;
    }
    if (invested_value) { 
    if(!cJSON_IsNumber(invested_value))
    {
    goto end; //Numeric
    }
    invested_value_local_var = malloc(sizeof(double));
    if(!invested_value_local_var)
    {
        goto end;
    }
    *invested_value_local_var = invested_value->valuedouble;
    }

    // us_holding_data->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "last_price");
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

    // us_holding_data->previous_close
    cJSON *previous_close = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "previous_close");
    if (cJSON_IsNull(previous_close)) {
        previous_close = NULL;
    }
    if (previous_close) { 
    if(!cJSON_IsNumber(previous_close))
    {
    goto end; //Numeric
    }
    previous_close_local_var = malloc(sizeof(double));
    if(!previous_close_local_var)
    {
        goto end;
    }
    *previous_close_local_var = previous_close->valuedouble;
    }

    // us_holding_data->current_value
    cJSON *current_value = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "current_value");
    if (cJSON_IsNull(current_value)) {
        current_value = NULL;
    }
    if (current_value) { 
    if(!cJSON_IsNumber(current_value))
    {
    goto end; //Numeric
    }
    current_value_local_var = malloc(sizeof(double));
    if(!current_value_local_var)
    {
        goto end;
    }
    *current_value_local_var = current_value->valuedouble;
    }

    // us_holding_data->day_pnl
    cJSON *day_pnl = cJSON_GetObjectItemCaseSensitive(us_holding_dataJSON, "day_pnl");
    if (cJSON_IsNull(day_pnl)) {
        day_pnl = NULL;
    }
    if (day_pnl) { 
    if(!cJSON_IsNumber(day_pnl))
    {
    goto end; //Numeric
    }
    day_pnl_local_var = malloc(sizeof(double));
    if(!day_pnl_local_var)
    {
        goto end;
    }
    *day_pnl_local_var = day_pnl->valuedouble;
    }


    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);

    us_holding_data_local_var = us_holding_data_create_internal (
        exchange_local_str,
        quantity_local_var,
        pnl_local_var,
        instrument_key_local_str,
        trading_symbol_local_str,
        company_name_local_str,
        average_price_local_var,
        available_quantity_local_var,
        transaction_type_local_str,
        invested_value_local_var,
        last_price_local_var,
        previous_close_local_var,
        current_value_local_var,
        day_pnl_local_var
        );

    if (!us_holding_data_local_var) {
        goto end;
    }

    return us_holding_data_local_var;
end:
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (pnl_local_var) {
        free(pnl_local_var);
        pnl_local_var = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (available_quantity_local_var) {
        free(available_quantity_local_var);
        available_quantity_local_var = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (invested_value_local_var) {
        free(invested_value_local_var);
        invested_value_local_var = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (previous_close_local_var) {
        free(previous_close_local_var);
        previous_close_local_var = NULL;
    }
    if (current_value_local_var) {
        free(current_value_local_var);
        current_value_local_var = NULL;
    }
    if (day_pnl_local_var) {
        free(day_pnl_local_var);
        day_pnl_local_var = NULL;
    }
    return NULL;

}
