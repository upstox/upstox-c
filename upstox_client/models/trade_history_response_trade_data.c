#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_history_response_trade_data.h"



static trade_history_response_trade_data_t *trade_history_response_trade_data_create_internal(
    char *exchange,
    char *segment,
    char *option_type,
    int *quantity,
    double *amount,
    char *trade_id,
    char *trade_date,
    char *transaction_type,
    char *scrip_name,
    char *strike_price,
    char *expiry,
    double *price,
    char *isin,
    char *symbol,
    char *instrument_token
    ) {
    trade_history_response_trade_data_t *trade_history_response_trade_data_local_var = malloc(sizeof(trade_history_response_trade_data_t));
    if (!trade_history_response_trade_data_local_var) {
        return NULL;
    }
    memset(trade_history_response_trade_data_local_var, 0, sizeof(trade_history_response_trade_data_t));
    trade_history_response_trade_data_local_var->_library_owned = 1;
    trade_history_response_trade_data_local_var->exchange = exchange;
    trade_history_response_trade_data_local_var->segment = segment;
    trade_history_response_trade_data_local_var->option_type = option_type;
    trade_history_response_trade_data_local_var->quantity = quantity;
    trade_history_response_trade_data_local_var->amount = amount;
    trade_history_response_trade_data_local_var->trade_id = trade_id;
    trade_history_response_trade_data_local_var->trade_date = trade_date;
    trade_history_response_trade_data_local_var->transaction_type = transaction_type;
    trade_history_response_trade_data_local_var->scrip_name = scrip_name;
    trade_history_response_trade_data_local_var->strike_price = strike_price;
    trade_history_response_trade_data_local_var->expiry = expiry;
    trade_history_response_trade_data_local_var->price = price;
    trade_history_response_trade_data_local_var->isin = isin;
    trade_history_response_trade_data_local_var->symbol = symbol;
    trade_history_response_trade_data_local_var->instrument_token = instrument_token;
    return trade_history_response_trade_data_local_var;
}

trade_history_response_trade_data_t *trade_history_response_trade_data_create(
    char *exchange,
    char *segment,
    char *option_type,
    int *quantity,
    double *amount,
    char *trade_id,
    char *trade_date,
    char *transaction_type,
    char *scrip_name,
    char *strike_price,
    char *expiry,
    double *price,
    char *isin,
    char *symbol,
    char *instrument_token
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    trade_history_response_trade_data_t *result = trade_history_response_trade_data_create_internal (
        exchange,
        segment,
        option_type,
        quantity_copy,
        amount_copy,
        trade_id,
        trade_date,
        transaction_type,
        scrip_name,
        strike_price,
        expiry,
        price_copy,
        isin,
        symbol,
        instrument_token
        );
    if (!result) {
        free(quantity_copy);
        free(amount_copy);
        free(price_copy);
    }
    return result;
}

void trade_history_response_trade_data_free(trade_history_response_trade_data_t *trade_history_response_trade_data) {
    if(NULL == trade_history_response_trade_data){
        return ;
    }
    if(trade_history_response_trade_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_history_response_trade_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_history_response_trade_data->exchange) {
        free(trade_history_response_trade_data->exchange);
        trade_history_response_trade_data->exchange = NULL;
    }
    if (trade_history_response_trade_data->segment) {
        free(trade_history_response_trade_data->segment);
        trade_history_response_trade_data->segment = NULL;
    }
    if (trade_history_response_trade_data->option_type) {
        free(trade_history_response_trade_data->option_type);
        trade_history_response_trade_data->option_type = NULL;
    }
    if (trade_history_response_trade_data->quantity) {
        free(trade_history_response_trade_data->quantity);
        trade_history_response_trade_data->quantity = NULL;
    }
    if (trade_history_response_trade_data->amount) {
        free(trade_history_response_trade_data->amount);
        trade_history_response_trade_data->amount = NULL;
    }
    if (trade_history_response_trade_data->trade_id) {
        free(trade_history_response_trade_data->trade_id);
        trade_history_response_trade_data->trade_id = NULL;
    }
    if (trade_history_response_trade_data->trade_date) {
        free(trade_history_response_trade_data->trade_date);
        trade_history_response_trade_data->trade_date = NULL;
    }
    if (trade_history_response_trade_data->transaction_type) {
        free(trade_history_response_trade_data->transaction_type);
        trade_history_response_trade_data->transaction_type = NULL;
    }
    if (trade_history_response_trade_data->scrip_name) {
        free(trade_history_response_trade_data->scrip_name);
        trade_history_response_trade_data->scrip_name = NULL;
    }
    if (trade_history_response_trade_data->strike_price) {
        free(trade_history_response_trade_data->strike_price);
        trade_history_response_trade_data->strike_price = NULL;
    }
    if (trade_history_response_trade_data->expiry) {
        free(trade_history_response_trade_data->expiry);
        trade_history_response_trade_data->expiry = NULL;
    }
    if (trade_history_response_trade_data->price) {
        free(trade_history_response_trade_data->price);
        trade_history_response_trade_data->price = NULL;
    }
    if (trade_history_response_trade_data->isin) {
        free(trade_history_response_trade_data->isin);
        trade_history_response_trade_data->isin = NULL;
    }
    if (trade_history_response_trade_data->symbol) {
        free(trade_history_response_trade_data->symbol);
        trade_history_response_trade_data->symbol = NULL;
    }
    if (trade_history_response_trade_data->instrument_token) {
        free(trade_history_response_trade_data->instrument_token);
        trade_history_response_trade_data->instrument_token = NULL;
    }
    free(trade_history_response_trade_data);
}

cJSON *trade_history_response_trade_data_convertToJSON(trade_history_response_trade_data_t *trade_history_response_trade_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_history_response_trade_data->exchange
    if(trade_history_response_trade_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", trade_history_response_trade_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->segment
    if(trade_history_response_trade_data->segment) {
    if(cJSON_AddStringToObject(item, "segment", trade_history_response_trade_data->segment) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->option_type
    if(trade_history_response_trade_data->option_type) {
    if(cJSON_AddStringToObject(item, "option_type", trade_history_response_trade_data->option_type) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->quantity
    if(trade_history_response_trade_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *trade_history_response_trade_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_trade_data->amount
    if(trade_history_response_trade_data->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *trade_history_response_trade_data->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_trade_data->trade_id
    if(trade_history_response_trade_data->trade_id) {
    if(cJSON_AddStringToObject(item, "trade_id", trade_history_response_trade_data->trade_id) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->trade_date
    if(trade_history_response_trade_data->trade_date) {
    if(cJSON_AddStringToObject(item, "trade_date", trade_history_response_trade_data->trade_date) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->transaction_type
    if(trade_history_response_trade_data->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", trade_history_response_trade_data->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->scrip_name
    if(trade_history_response_trade_data->scrip_name) {
    if(cJSON_AddStringToObject(item, "scrip_name", trade_history_response_trade_data->scrip_name) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->strike_price
    if(trade_history_response_trade_data->strike_price) {
    if(cJSON_AddStringToObject(item, "strike_price", trade_history_response_trade_data->strike_price) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->expiry
    if(trade_history_response_trade_data->expiry) {
    if(cJSON_AddStringToObject(item, "expiry", trade_history_response_trade_data->expiry) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->price
    if(trade_history_response_trade_data->price) {
    if(cJSON_AddNumberToObject(item, "price", *trade_history_response_trade_data->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_trade_data->isin
    if(trade_history_response_trade_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", trade_history_response_trade_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->symbol
    if(trade_history_response_trade_data->symbol) {
    if(cJSON_AddStringToObject(item, "symbol", trade_history_response_trade_data->symbol) == NULL) {
    goto fail; //String
    }
    }


    // trade_history_response_trade_data->instrument_token
    if(trade_history_response_trade_data->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", trade_history_response_trade_data->instrument_token) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trade_history_response_trade_data_t *trade_history_response_trade_data_parseFromJSON(cJSON *trade_history_response_trade_dataJSON){

    trade_history_response_trade_data_t *trade_history_response_trade_data_local_var = NULL;

    char *exchange_local_str = NULL;

    char *segment_local_str = NULL;

    char *option_type_local_str = NULL;

    // define the local variable for trade_history_response_trade_data->quantity
    int *quantity_local_var = NULL;

    // define the local variable for trade_history_response_trade_data->amount
    double *amount_local_var = NULL;

    char *trade_id_local_str = NULL;

    char *trade_date_local_str = NULL;

    char *transaction_type_local_str = NULL;

    char *scrip_name_local_str = NULL;

    char *strike_price_local_str = NULL;

    char *expiry_local_str = NULL;

    // define the local variable for trade_history_response_trade_data->price
    double *price_local_var = NULL;

    char *isin_local_str = NULL;

    char *symbol_local_str = NULL;

    char *instrument_token_local_str = NULL;

    // trade_history_response_trade_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->segment
    cJSON *segment = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "segment");
    if (cJSON_IsNull(segment)) {
        segment = NULL;
    }
    if (segment) { 
    if(!cJSON_IsString(segment) && !cJSON_IsNull(segment))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->option_type
    cJSON *option_type = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "option_type");
    if (cJSON_IsNull(option_type)) {
        option_type = NULL;
    }
    if (option_type) { 
    if(!cJSON_IsString(option_type) && !cJSON_IsNull(option_type))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // trade_history_response_trade_data->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (amount) { 
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    amount_local_var = malloc(sizeof(double));
    if(!amount_local_var)
    {
        goto end;
    }
    *amount_local_var = amount->valuedouble;
    }

    // trade_history_response_trade_data->trade_id
    cJSON *trade_id = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "trade_id");
    if (cJSON_IsNull(trade_id)) {
        trade_id = NULL;
    }
    if (trade_id) { 
    if(!cJSON_IsString(trade_id) && !cJSON_IsNull(trade_id))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->trade_date
    cJSON *trade_date = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "trade_date");
    if (cJSON_IsNull(trade_date)) {
        trade_date = NULL;
    }
    if (trade_date) { 
    if(!cJSON_IsString(trade_date) && !cJSON_IsNull(trade_date))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->scrip_name
    cJSON *scrip_name = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "scrip_name");
    if (cJSON_IsNull(scrip_name)) {
        scrip_name = NULL;
    }
    if (scrip_name) { 
    if(!cJSON_IsString(scrip_name) && !cJSON_IsNull(scrip_name))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->strike_price
    cJSON *strike_price = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "strike_price");
    if (cJSON_IsNull(strike_price)) {
        strike_price = NULL;
    }
    if (strike_price) { 
    if(!cJSON_IsString(strike_price) && !cJSON_IsNull(strike_price))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->expiry
    cJSON *expiry = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "expiry");
    if (cJSON_IsNull(expiry)) {
        expiry = NULL;
    }
    if (expiry) { 
    if(!cJSON_IsString(expiry) && !cJSON_IsNull(expiry))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (price) { 
    if(!cJSON_IsNumber(price))
    {
    goto end; //Numeric
    }
    price_local_var = malloc(sizeof(double));
    if(!price_local_var)
    {
        goto end;
    }
    *price_local_var = price->valuedouble;
    }

    // trade_history_response_trade_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->symbol
    cJSON *symbol = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "symbol");
    if (cJSON_IsNull(symbol)) {
        symbol = NULL;
    }
    if (symbol) { 
    if(!cJSON_IsString(symbol) && !cJSON_IsNull(symbol))
    {
    goto end; //String
    }
    }

    // trade_history_response_trade_data->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(trade_history_response_trade_dataJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }


    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (segment && !cJSON_IsNull(segment)) segment_local_str = strdup(segment->valuestring);
    if (option_type && !cJSON_IsNull(option_type)) option_type_local_str = strdup(option_type->valuestring);
    if (trade_id && !cJSON_IsNull(trade_id)) trade_id_local_str = strdup(trade_id->valuestring);
    if (trade_date && !cJSON_IsNull(trade_date)) trade_date_local_str = strdup(trade_date->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);
    if (scrip_name && !cJSON_IsNull(scrip_name)) scrip_name_local_str = strdup(scrip_name->valuestring);
    if (strike_price && !cJSON_IsNull(strike_price)) strike_price_local_str = strdup(strike_price->valuestring);
    if (expiry && !cJSON_IsNull(expiry)) expiry_local_str = strdup(expiry->valuestring);
    if (isin && !cJSON_IsNull(isin)) isin_local_str = strdup(isin->valuestring);
    if (symbol && !cJSON_IsNull(symbol)) symbol_local_str = strdup(symbol->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    trade_history_response_trade_data_local_var = trade_history_response_trade_data_create_internal (
        exchange_local_str,
        segment_local_str,
        option_type_local_str,
        quantity_local_var,
        amount_local_var,
        trade_id_local_str,
        trade_date_local_str,
        transaction_type_local_str,
        scrip_name_local_str,
        strike_price_local_str,
        expiry_local_str,
        price_local_var,
        isin_local_str,
        symbol_local_str,
        instrument_token_local_str
        );

    if (!trade_history_response_trade_data_local_var) {
        goto end;
    }

    return trade_history_response_trade_data_local_var;
end:
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (segment_local_str) {
        free(segment_local_str);
        segment_local_str = NULL;
    }
    if (option_type_local_str) {
        free(option_type_local_str);
        option_type_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (trade_id_local_str) {
        free(trade_id_local_str);
        trade_id_local_str = NULL;
    }
    if (trade_date_local_str) {
        free(trade_date_local_str);
        trade_date_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (scrip_name_local_str) {
        free(scrip_name_local_str);
        scrip_name_local_str = NULL;
    }
    if (strike_price_local_str) {
        free(strike_price_local_str);
        strike_price_local_str = NULL;
    }
    if (expiry_local_str) {
        free(expiry_local_str);
        expiry_local_str = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (isin_local_str) {
        free(isin_local_str);
        isin_local_str = NULL;
    }
    if (symbol_local_str) {
        free(symbol_local_str);
        symbol_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    return NULL;

}
