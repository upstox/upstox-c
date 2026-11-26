#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mutual_fund_order_data.h"



static mutual_fund_order_data_t *mutual_fund_order_data_create_internal(
    char *status,
    char *folio,
    char *fund,
    double *amount,
    char *variety,
    double *quantity,
    double *price,
    char *order_id,
    char *exchange_order_id,
    char *instrument_key,
    char *status_message,
    char *order_timestamp,
    char *exchange_timestamp,
    char *settlement_id,
    char *transaction_type,
    char *purchase_type,
    double *last_price,
    double *average_price,
    char *last_price_date
    ) {
    mutual_fund_order_data_t *mutual_fund_order_data_local_var = malloc(sizeof(mutual_fund_order_data_t));
    if (!mutual_fund_order_data_local_var) {
        return NULL;
    }
    memset(mutual_fund_order_data_local_var, 0, sizeof(mutual_fund_order_data_t));
    mutual_fund_order_data_local_var->_library_owned = 1;
    mutual_fund_order_data_local_var->status = status;
    mutual_fund_order_data_local_var->folio = folio;
    mutual_fund_order_data_local_var->fund = fund;
    mutual_fund_order_data_local_var->amount = amount;
    mutual_fund_order_data_local_var->variety = variety;
    mutual_fund_order_data_local_var->quantity = quantity;
    mutual_fund_order_data_local_var->price = price;
    mutual_fund_order_data_local_var->order_id = order_id;
    mutual_fund_order_data_local_var->exchange_order_id = exchange_order_id;
    mutual_fund_order_data_local_var->instrument_key = instrument_key;
    mutual_fund_order_data_local_var->status_message = status_message;
    mutual_fund_order_data_local_var->order_timestamp = order_timestamp;
    mutual_fund_order_data_local_var->exchange_timestamp = exchange_timestamp;
    mutual_fund_order_data_local_var->settlement_id = settlement_id;
    mutual_fund_order_data_local_var->transaction_type = transaction_type;
    mutual_fund_order_data_local_var->purchase_type = purchase_type;
    mutual_fund_order_data_local_var->last_price = last_price;
    mutual_fund_order_data_local_var->average_price = average_price;
    mutual_fund_order_data_local_var->last_price_date = last_price_date;
    return mutual_fund_order_data_local_var;
}

mutual_fund_order_data_t *mutual_fund_order_data_create(
    char *status,
    char *folio,
    char *fund,
    double *amount,
    char *variety,
    double *quantity,
    double *price,
    char *order_id,
    char *exchange_order_id,
    char *instrument_key,
    char *status_message,
    char *order_timestamp,
    char *exchange_timestamp,
    char *settlement_id,
    char *transaction_type,
    char *purchase_type,
    double *last_price,
    double *average_price,
    char *last_price_date
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    double *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(double));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    mutual_fund_order_data_t *result = mutual_fund_order_data_create_internal (
        status,
        folio,
        fund,
        amount_copy,
        variety,
        quantity_copy,
        price_copy,
        order_id,
        exchange_order_id,
        instrument_key,
        status_message,
        order_timestamp,
        exchange_timestamp,
        settlement_id,
        transaction_type,
        purchase_type,
        last_price_copy,
        average_price_copy,
        last_price_date
        );
    if (!result) {
        free(amount_copy);
        free(quantity_copy);
        free(price_copy);
        free(last_price_copy);
        free(average_price_copy);
    }
    return result;
}

void mutual_fund_order_data_free(mutual_fund_order_data_t *mutual_fund_order_data) {
    if(NULL == mutual_fund_order_data){
        return ;
    }
    if(mutual_fund_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mutual_fund_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mutual_fund_order_data->status) {
        free(mutual_fund_order_data->status);
        mutual_fund_order_data->status = NULL;
    }
    if (mutual_fund_order_data->folio) {
        free(mutual_fund_order_data->folio);
        mutual_fund_order_data->folio = NULL;
    }
    if (mutual_fund_order_data->fund) {
        free(mutual_fund_order_data->fund);
        mutual_fund_order_data->fund = NULL;
    }
    if (mutual_fund_order_data->amount) {
        free(mutual_fund_order_data->amount);
        mutual_fund_order_data->amount = NULL;
    }
    if (mutual_fund_order_data->variety) {
        free(mutual_fund_order_data->variety);
        mutual_fund_order_data->variety = NULL;
    }
    if (mutual_fund_order_data->quantity) {
        free(mutual_fund_order_data->quantity);
        mutual_fund_order_data->quantity = NULL;
    }
    if (mutual_fund_order_data->price) {
        free(mutual_fund_order_data->price);
        mutual_fund_order_data->price = NULL;
    }
    if (mutual_fund_order_data->order_id) {
        free(mutual_fund_order_data->order_id);
        mutual_fund_order_data->order_id = NULL;
    }
    if (mutual_fund_order_data->exchange_order_id) {
        free(mutual_fund_order_data->exchange_order_id);
        mutual_fund_order_data->exchange_order_id = NULL;
    }
    if (mutual_fund_order_data->instrument_key) {
        free(mutual_fund_order_data->instrument_key);
        mutual_fund_order_data->instrument_key = NULL;
    }
    if (mutual_fund_order_data->status_message) {
        free(mutual_fund_order_data->status_message);
        mutual_fund_order_data->status_message = NULL;
    }
    if (mutual_fund_order_data->order_timestamp) {
        free(mutual_fund_order_data->order_timestamp);
        mutual_fund_order_data->order_timestamp = NULL;
    }
    if (mutual_fund_order_data->exchange_timestamp) {
        free(mutual_fund_order_data->exchange_timestamp);
        mutual_fund_order_data->exchange_timestamp = NULL;
    }
    if (mutual_fund_order_data->settlement_id) {
        free(mutual_fund_order_data->settlement_id);
        mutual_fund_order_data->settlement_id = NULL;
    }
    if (mutual_fund_order_data->transaction_type) {
        free(mutual_fund_order_data->transaction_type);
        mutual_fund_order_data->transaction_type = NULL;
    }
    if (mutual_fund_order_data->purchase_type) {
        free(mutual_fund_order_data->purchase_type);
        mutual_fund_order_data->purchase_type = NULL;
    }
    if (mutual_fund_order_data->last_price) {
        free(mutual_fund_order_data->last_price);
        mutual_fund_order_data->last_price = NULL;
    }
    if (mutual_fund_order_data->average_price) {
        free(mutual_fund_order_data->average_price);
        mutual_fund_order_data->average_price = NULL;
    }
    if (mutual_fund_order_data->last_price_date) {
        free(mutual_fund_order_data->last_price_date);
        mutual_fund_order_data->last_price_date = NULL;
    }
    free(mutual_fund_order_data);
}

cJSON *mutual_fund_order_data_convertToJSON(mutual_fund_order_data_t *mutual_fund_order_data) {
    cJSON *item = cJSON_CreateObject();

    // mutual_fund_order_data->status
    if(mutual_fund_order_data->status) {
    if(cJSON_AddStringToObject(item, "status", mutual_fund_order_data->status) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->folio
    if(mutual_fund_order_data->folio) {
    if(cJSON_AddStringToObject(item, "folio", mutual_fund_order_data->folio) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->fund
    if(mutual_fund_order_data->fund) {
    if(cJSON_AddStringToObject(item, "fund", mutual_fund_order_data->fund) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->amount
    if(mutual_fund_order_data->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *mutual_fund_order_data->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_order_data->variety
    if(mutual_fund_order_data->variety) {
    if(cJSON_AddStringToObject(item, "variety", mutual_fund_order_data->variety) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->quantity
    if(mutual_fund_order_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *mutual_fund_order_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_order_data->price
    if(mutual_fund_order_data->price) {
    if(cJSON_AddNumberToObject(item, "price", *mutual_fund_order_data->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_order_data->order_id
    if(mutual_fund_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", mutual_fund_order_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->exchange_order_id
    if(mutual_fund_order_data->exchange_order_id) {
    if(cJSON_AddStringToObject(item, "exchange_order_id", mutual_fund_order_data->exchange_order_id) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->instrument_key
    if(mutual_fund_order_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", mutual_fund_order_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->status_message
    if(mutual_fund_order_data->status_message) {
    if(cJSON_AddStringToObject(item, "status_message", mutual_fund_order_data->status_message) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->order_timestamp
    if(mutual_fund_order_data->order_timestamp) {
    if(cJSON_AddStringToObject(item, "order_timestamp", mutual_fund_order_data->order_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->exchange_timestamp
    if(mutual_fund_order_data->exchange_timestamp) {
    if(cJSON_AddStringToObject(item, "exchange_timestamp", mutual_fund_order_data->exchange_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->settlement_id
    if(mutual_fund_order_data->settlement_id) {
    if(cJSON_AddStringToObject(item, "settlement_id", mutual_fund_order_data->settlement_id) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->transaction_type
    if(mutual_fund_order_data->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", mutual_fund_order_data->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->purchase_type
    if(mutual_fund_order_data->purchase_type) {
    if(cJSON_AddStringToObject(item, "purchase_type", mutual_fund_order_data->purchase_type) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_order_data->last_price
    if(mutual_fund_order_data->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *mutual_fund_order_data->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_order_data->average_price
    if(mutual_fund_order_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *mutual_fund_order_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_order_data->last_price_date
    if(mutual_fund_order_data->last_price_date) {
    if(cJSON_AddStringToObject(item, "last_price_date", mutual_fund_order_data->last_price_date) == NULL) {
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

mutual_fund_order_data_t *mutual_fund_order_data_parseFromJSON(cJSON *mutual_fund_order_dataJSON){

    mutual_fund_order_data_t *mutual_fund_order_data_local_var = NULL;

    char *status_local_str = NULL;

    char *folio_local_str = NULL;

    char *fund_local_str = NULL;

    // define the local variable for mutual_fund_order_data->amount
    double *amount_local_var = NULL;

    char *variety_local_str = NULL;

    // define the local variable for mutual_fund_order_data->quantity
    double *quantity_local_var = NULL;

    // define the local variable for mutual_fund_order_data->price
    double *price_local_var = NULL;

    char *order_id_local_str = NULL;

    char *exchange_order_id_local_str = NULL;

    char *instrument_key_local_str = NULL;

    char *status_message_local_str = NULL;

    char *order_timestamp_local_str = NULL;

    char *exchange_timestamp_local_str = NULL;

    char *settlement_id_local_str = NULL;

    char *transaction_type_local_str = NULL;

    char *purchase_type_local_str = NULL;

    // define the local variable for mutual_fund_order_data->last_price
    double *last_price_local_var = NULL;

    // define the local variable for mutual_fund_order_data->average_price
    double *average_price_local_var = NULL;

    char *last_price_date_local_str = NULL;

    // mutual_fund_order_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->folio
    cJSON *folio = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "folio");
    if (cJSON_IsNull(folio)) {
        folio = NULL;
    }
    if (folio) { 
    if(!cJSON_IsString(folio) && !cJSON_IsNull(folio))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->fund
    cJSON *fund = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "fund");
    if (cJSON_IsNull(fund)) {
        fund = NULL;
    }
    if (fund) { 
    if(!cJSON_IsString(fund) && !cJSON_IsNull(fund))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "amount");
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

    // mutual_fund_order_data->variety
    cJSON *variety = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "variety");
    if (cJSON_IsNull(variety)) {
        variety = NULL;
    }
    if (variety) { 
    if(!cJSON_IsString(variety) && !cJSON_IsNull(variety))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "quantity");
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

    // mutual_fund_order_data->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "price");
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

    // mutual_fund_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->exchange_order_id
    cJSON *exchange_order_id = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "exchange_order_id");
    if (cJSON_IsNull(exchange_order_id)) {
        exchange_order_id = NULL;
    }
    if (exchange_order_id) { 
    if(!cJSON_IsString(exchange_order_id) && !cJSON_IsNull(exchange_order_id))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->status_message
    cJSON *status_message = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "status_message");
    if (cJSON_IsNull(status_message)) {
        status_message = NULL;
    }
    if (status_message) { 
    if(!cJSON_IsString(status_message) && !cJSON_IsNull(status_message))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->order_timestamp
    cJSON *order_timestamp = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "order_timestamp");
    if (cJSON_IsNull(order_timestamp)) {
        order_timestamp = NULL;
    }
    if (order_timestamp) { 
    if(!cJSON_IsString(order_timestamp) && !cJSON_IsNull(order_timestamp))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->exchange_timestamp
    cJSON *exchange_timestamp = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "exchange_timestamp");
    if (cJSON_IsNull(exchange_timestamp)) {
        exchange_timestamp = NULL;
    }
    if (exchange_timestamp) { 
    if(!cJSON_IsString(exchange_timestamp) && !cJSON_IsNull(exchange_timestamp))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->settlement_id
    cJSON *settlement_id = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "settlement_id");
    if (cJSON_IsNull(settlement_id)) {
        settlement_id = NULL;
    }
    if (settlement_id) { 
    if(!cJSON_IsString(settlement_id) && !cJSON_IsNull(settlement_id))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->purchase_type
    cJSON *purchase_type = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "purchase_type");
    if (cJSON_IsNull(purchase_type)) {
        purchase_type = NULL;
    }
    if (purchase_type) { 
    if(!cJSON_IsString(purchase_type) && !cJSON_IsNull(purchase_type))
    {
    goto end; //String
    }
    }

    // mutual_fund_order_data->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "last_price");
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

    // mutual_fund_order_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "average_price");
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

    // mutual_fund_order_data->last_price_date
    cJSON *last_price_date = cJSON_GetObjectItemCaseSensitive(mutual_fund_order_dataJSON, "last_price_date");
    if (cJSON_IsNull(last_price_date)) {
        last_price_date = NULL;
    }
    if (last_price_date) { 
    if(!cJSON_IsString(last_price_date) && !cJSON_IsNull(last_price_date))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (folio && !cJSON_IsNull(folio)) folio_local_str = strdup(folio->valuestring);
    if (fund && !cJSON_IsNull(fund)) fund_local_str = strdup(fund->valuestring);
    if (variety && !cJSON_IsNull(variety)) variety_local_str = strdup(variety->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (exchange_order_id && !cJSON_IsNull(exchange_order_id)) exchange_order_id_local_str = strdup(exchange_order_id->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (status_message && !cJSON_IsNull(status_message)) status_message_local_str = strdup(status_message->valuestring);
    if (order_timestamp && !cJSON_IsNull(order_timestamp)) order_timestamp_local_str = strdup(order_timestamp->valuestring);
    if (exchange_timestamp && !cJSON_IsNull(exchange_timestamp)) exchange_timestamp_local_str = strdup(exchange_timestamp->valuestring);
    if (settlement_id && !cJSON_IsNull(settlement_id)) settlement_id_local_str = strdup(settlement_id->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);
    if (purchase_type && !cJSON_IsNull(purchase_type)) purchase_type_local_str = strdup(purchase_type->valuestring);
    if (last_price_date && !cJSON_IsNull(last_price_date)) last_price_date_local_str = strdup(last_price_date->valuestring);

    mutual_fund_order_data_local_var = mutual_fund_order_data_create_internal (
        status_local_str,
        folio_local_str,
        fund_local_str,
        amount_local_var,
        variety_local_str,
        quantity_local_var,
        price_local_var,
        order_id_local_str,
        exchange_order_id_local_str,
        instrument_key_local_str,
        status_message_local_str,
        order_timestamp_local_str,
        exchange_timestamp_local_str,
        settlement_id_local_str,
        transaction_type_local_str,
        purchase_type_local_str,
        last_price_local_var,
        average_price_local_var,
        last_price_date_local_str
        );

    if (!mutual_fund_order_data_local_var) {
        goto end;
    }

    return mutual_fund_order_data_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (folio_local_str) {
        free(folio_local_str);
        folio_local_str = NULL;
    }
    if (fund_local_str) {
        free(fund_local_str);
        fund_local_str = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (variety_local_str) {
        free(variety_local_str);
        variety_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (exchange_order_id_local_str) {
        free(exchange_order_id_local_str);
        exchange_order_id_local_str = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (status_message_local_str) {
        free(status_message_local_str);
        status_message_local_str = NULL;
    }
    if (order_timestamp_local_str) {
        free(order_timestamp_local_str);
        order_timestamp_local_str = NULL;
    }
    if (exchange_timestamp_local_str) {
        free(exchange_timestamp_local_str);
        exchange_timestamp_local_str = NULL;
    }
    if (settlement_id_local_str) {
        free(settlement_id_local_str);
        settlement_id_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (purchase_type_local_str) {
        free(purchase_type_local_str);
        purchase_type_local_str = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (last_price_date_local_str) {
        free(last_price_date_local_str);
        last_price_date_local_str = NULL;
    }
    return NULL;

}
