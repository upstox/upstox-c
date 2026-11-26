#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_book_data.h"


char* us_order_book_data_status_ToString(upstox_client_us_order_book_data_STATUS_e status) {
    char* statusArray[] =  { "NULL", "complete", "open", "queued", "cancelled", "cancelled_partially", "failed", "failed_partially", "expired", "partially_complete", "scheduled" };
    return statusArray[status];
}

upstox_client_us_order_book_data_STATUS_e us_order_book_data_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "complete", "open", "queued", "cancelled", "cancelled_partially", "failed", "failed_partially", "expired", "partially_complete", "scheduled" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* us_order_book_data_order_type_ToString(upstox_client_us_order_book_data_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT" };
    return order_typeArray[order_type];
}

upstox_client_us_order_book_data_ORDERTYPE_e us_order_book_data_order_type_FromString(char* order_type){
    int stringToReturn = 0;
    char *order_typeArray[] =  { "NULL", "MARKET", "LIMIT" };
    size_t sizeofArray = sizeof(order_typeArray) / sizeof(order_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(order_type, order_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static us_order_book_data_t *us_order_book_data_create_internal(
    char *name,
    char *exchange,
    char *validity,
    double *price,
    double *quantity,
    double *amount,
    upstox_client_us_order_book_data_STATUS_e status,
    int *fractionable,
    char *variety,
    char *tag,
    char *order_id,
    char *instrument_key,
    char *trading_symbol,
    upstox_client_us_order_book_data_ORDERTYPE_e order_type,
    char *transaction_type,
    double *average_price,
    double *filled_quantity,
    double *pending_quantity,
    char *status_message,
    char *status_message_raw,
    char *order_timestamp,
    char *exchange_timestamp,
    int *is_amo
    ) {
    us_order_book_data_t *us_order_book_data_local_var = malloc(sizeof(us_order_book_data_t));
    if (!us_order_book_data_local_var) {
        return NULL;
    }
    memset(us_order_book_data_local_var, 0, sizeof(us_order_book_data_t));
    us_order_book_data_local_var->_library_owned = 1;
    us_order_book_data_local_var->name = name;
    us_order_book_data_local_var->exchange = exchange;
    us_order_book_data_local_var->validity = validity;
    us_order_book_data_local_var->price = price;
    us_order_book_data_local_var->quantity = quantity;
    us_order_book_data_local_var->amount = amount;
    us_order_book_data_local_var->status = status;
    us_order_book_data_local_var->fractionable = fractionable;
    us_order_book_data_local_var->variety = variety;
    us_order_book_data_local_var->tag = tag;
    us_order_book_data_local_var->order_id = order_id;
    us_order_book_data_local_var->instrument_key = instrument_key;
    us_order_book_data_local_var->trading_symbol = trading_symbol;
    us_order_book_data_local_var->order_type = order_type;
    us_order_book_data_local_var->transaction_type = transaction_type;
    us_order_book_data_local_var->average_price = average_price;
    us_order_book_data_local_var->filled_quantity = filled_quantity;
    us_order_book_data_local_var->pending_quantity = pending_quantity;
    us_order_book_data_local_var->status_message = status_message;
    us_order_book_data_local_var->status_message_raw = status_message_raw;
    us_order_book_data_local_var->order_timestamp = order_timestamp;
    us_order_book_data_local_var->exchange_timestamp = exchange_timestamp;
    us_order_book_data_local_var->is_amo = is_amo;
    return us_order_book_data_local_var;
}

us_order_book_data_t *us_order_book_data_create(
    char *name,
    char *exchange,
    char *validity,
    double *price,
    double *quantity,
    double *amount,
    upstox_client_us_order_book_data_STATUS_e status,
    int *fractionable,
    char *variety,
    char *tag,
    char *order_id,
    char *instrument_key,
    char *trading_symbol,
    upstox_client_us_order_book_data_ORDERTYPE_e order_type,
    char *transaction_type,
    double *average_price,
    double *filled_quantity,
    double *pending_quantity,
    char *status_message,
    char *status_message_raw,
    char *order_timestamp,
    char *exchange_timestamp,
    int *is_amo
    ) {
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    double *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(double));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    int *fractionable_copy = NULL;
    if (fractionable) {
        fractionable_copy = malloc(sizeof(int));
        if (fractionable_copy) *fractionable_copy = *fractionable;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    double *filled_quantity_copy = NULL;
    if (filled_quantity) {
        filled_quantity_copy = malloc(sizeof(double));
        if (filled_quantity_copy) *filled_quantity_copy = *filled_quantity;
    }
    double *pending_quantity_copy = NULL;
    if (pending_quantity) {
        pending_quantity_copy = malloc(sizeof(double));
        if (pending_quantity_copy) *pending_quantity_copy = *pending_quantity;
    }
    int *is_amo_copy = NULL;
    if (is_amo) {
        is_amo_copy = malloc(sizeof(int));
        if (is_amo_copy) *is_amo_copy = *is_amo;
    }
    us_order_book_data_t *result = us_order_book_data_create_internal (
        name,
        exchange,
        validity,
        price_copy,
        quantity_copy,
        amount_copy,
        status,
        fractionable_copy,
        variety,
        tag,
        order_id,
        instrument_key,
        trading_symbol,
        order_type,
        transaction_type,
        average_price_copy,
        filled_quantity_copy,
        pending_quantity_copy,
        status_message,
        status_message_raw,
        order_timestamp,
        exchange_timestamp,
        is_amo_copy
        );
    if (!result) {
        free(price_copy);
        free(quantity_copy);
        free(amount_copy);
        free(fractionable_copy);
        free(average_price_copy);
        free(filled_quantity_copy);
        free(pending_quantity_copy);
        free(is_amo_copy);
    }
    return result;
}

void us_order_book_data_free(us_order_book_data_t *us_order_book_data) {
    if(NULL == us_order_book_data){
        return ;
    }
    if(us_order_book_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_book_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_book_data->name) {
        free(us_order_book_data->name);
        us_order_book_data->name = NULL;
    }
    if (us_order_book_data->exchange) {
        free(us_order_book_data->exchange);
        us_order_book_data->exchange = NULL;
    }
    if (us_order_book_data->validity) {
        free(us_order_book_data->validity);
        us_order_book_data->validity = NULL;
    }
    if (us_order_book_data->price) {
        free(us_order_book_data->price);
        us_order_book_data->price = NULL;
    }
    if (us_order_book_data->quantity) {
        free(us_order_book_data->quantity);
        us_order_book_data->quantity = NULL;
    }
    if (us_order_book_data->amount) {
        free(us_order_book_data->amount);
        us_order_book_data->amount = NULL;
    }
    if (us_order_book_data->fractionable) {
        free(us_order_book_data->fractionable);
        us_order_book_data->fractionable = NULL;
    }
    if (us_order_book_data->variety) {
        free(us_order_book_data->variety);
        us_order_book_data->variety = NULL;
    }
    if (us_order_book_data->tag) {
        free(us_order_book_data->tag);
        us_order_book_data->tag = NULL;
    }
    if (us_order_book_data->order_id) {
        free(us_order_book_data->order_id);
        us_order_book_data->order_id = NULL;
    }
    if (us_order_book_data->instrument_key) {
        free(us_order_book_data->instrument_key);
        us_order_book_data->instrument_key = NULL;
    }
    if (us_order_book_data->trading_symbol) {
        free(us_order_book_data->trading_symbol);
        us_order_book_data->trading_symbol = NULL;
    }
    if (us_order_book_data->transaction_type) {
        free(us_order_book_data->transaction_type);
        us_order_book_data->transaction_type = NULL;
    }
    if (us_order_book_data->average_price) {
        free(us_order_book_data->average_price);
        us_order_book_data->average_price = NULL;
    }
    if (us_order_book_data->filled_quantity) {
        free(us_order_book_data->filled_quantity);
        us_order_book_data->filled_quantity = NULL;
    }
    if (us_order_book_data->pending_quantity) {
        free(us_order_book_data->pending_quantity);
        us_order_book_data->pending_quantity = NULL;
    }
    if (us_order_book_data->status_message) {
        free(us_order_book_data->status_message);
        us_order_book_data->status_message = NULL;
    }
    if (us_order_book_data->status_message_raw) {
        free(us_order_book_data->status_message_raw);
        us_order_book_data->status_message_raw = NULL;
    }
    if (us_order_book_data->order_timestamp) {
        free(us_order_book_data->order_timestamp);
        us_order_book_data->order_timestamp = NULL;
    }
    if (us_order_book_data->exchange_timestamp) {
        free(us_order_book_data->exchange_timestamp);
        us_order_book_data->exchange_timestamp = NULL;
    }
    if (us_order_book_data->is_amo) {
        free(us_order_book_data->is_amo);
        us_order_book_data->is_amo = NULL;
    }
    free(us_order_book_data);
}

cJSON *us_order_book_data_convertToJSON(us_order_book_data_t *us_order_book_data) {
    cJSON *item = cJSON_CreateObject();

    // us_order_book_data->name
    if(us_order_book_data->name) {
    if(cJSON_AddStringToObject(item, "name", us_order_book_data->name) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->exchange
    if(us_order_book_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", us_order_book_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->validity
    if(us_order_book_data->validity) {
    if(cJSON_AddStringToObject(item, "validity", us_order_book_data->validity) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->price
    if(us_order_book_data->price) {
    if(cJSON_AddNumberToObject(item, "price", *us_order_book_data->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->quantity
    if(us_order_book_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *us_order_book_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->amount
    if(us_order_book_data->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *us_order_book_data->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->status
    if(us_order_book_data->status != upstox_client_us_order_book_data_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", us_order_book_data_status_ToString(us_order_book_data->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // us_order_book_data->fractionable
    if(us_order_book_data->fractionable) {
    if(cJSON_AddBoolToObject(item, "fractionable", *us_order_book_data->fractionable) == NULL) {
    goto fail; //Bool
    }
    }


    // us_order_book_data->variety
    if(us_order_book_data->variety) {
    if(cJSON_AddStringToObject(item, "variety", us_order_book_data->variety) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->tag
    if(us_order_book_data->tag) {
    if(cJSON_AddStringToObject(item, "tag", us_order_book_data->tag) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->order_id
    if(us_order_book_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", us_order_book_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->instrument_key
    if(us_order_book_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", us_order_book_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->trading_symbol
    if(us_order_book_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", us_order_book_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->order_type
    if(us_order_book_data->order_type != upstox_client_us_order_book_data_ORDERTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "order_type", us_order_book_data_order_type_ToString(us_order_book_data->order_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // us_order_book_data->transaction_type
    if(us_order_book_data->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", us_order_book_data->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->average_price
    if(us_order_book_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *us_order_book_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->filled_quantity
    if(us_order_book_data->filled_quantity) {
    if(cJSON_AddNumberToObject(item, "filled_quantity", *us_order_book_data->filled_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->pending_quantity
    if(us_order_book_data->pending_quantity) {
    if(cJSON_AddNumberToObject(item, "pending_quantity", *us_order_book_data->pending_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_book_data->status_message
    if(us_order_book_data->status_message) {
    if(cJSON_AddStringToObject(item, "status_message", us_order_book_data->status_message) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->status_message_raw
    if(us_order_book_data->status_message_raw) {
    if(cJSON_AddStringToObject(item, "status_message_raw", us_order_book_data->status_message_raw) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->order_timestamp
    if(us_order_book_data->order_timestamp) {
    if(cJSON_AddStringToObject(item, "order_timestamp", us_order_book_data->order_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->exchange_timestamp
    if(us_order_book_data->exchange_timestamp) {
    if(cJSON_AddStringToObject(item, "exchange_timestamp", us_order_book_data->exchange_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // us_order_book_data->is_amo
    if(us_order_book_data->is_amo) {
    if(cJSON_AddBoolToObject(item, "is_amo", *us_order_book_data->is_amo) == NULL) {
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

us_order_book_data_t *us_order_book_data_parseFromJSON(cJSON *us_order_book_dataJSON){

    us_order_book_data_t *us_order_book_data_local_var = NULL;

    char *name_local_str = NULL;

    char *exchange_local_str = NULL;

    char *validity_local_str = NULL;

    // define the local variable for us_order_book_data->price
    double *price_local_var = NULL;

    // define the local variable for us_order_book_data->quantity
    double *quantity_local_var = NULL;

    // define the local variable for us_order_book_data->amount
    double *amount_local_var = NULL;

    // define the local variable for us_order_book_data->fractionable
    int *fractionable_local_var = NULL;

    char *variety_local_str = NULL;

    char *tag_local_str = NULL;

    char *order_id_local_str = NULL;

    char *instrument_key_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    char *transaction_type_local_str = NULL;

    // define the local variable for us_order_book_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for us_order_book_data->filled_quantity
    double *filled_quantity_local_var = NULL;

    // define the local variable for us_order_book_data->pending_quantity
    double *pending_quantity_local_var = NULL;

    char *status_message_local_str = NULL;

    char *status_message_raw_local_str = NULL;

    char *order_timestamp_local_str = NULL;

    char *exchange_timestamp_local_str = NULL;

    // define the local variable for us_order_book_data->is_amo
    int *is_amo_local_var = NULL;

    // us_order_book_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // us_order_book_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // us_order_book_data->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    if (validity) { 
    if(!cJSON_IsString(validity) && !cJSON_IsNull(validity))
    {
    goto end; //String
    }
    }

    // us_order_book_data->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "price");
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

    // us_order_book_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "quantity");
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

    // us_order_book_data->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "amount");
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

    // us_order_book_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_us_order_book_data_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = us_order_book_data_status_FromString(status->valuestring);
    }

    // us_order_book_data->fractionable
    cJSON *fractionable = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "fractionable");
    if (cJSON_IsNull(fractionable)) {
        fractionable = NULL;
    }
    if (fractionable) { 
    if(!cJSON_IsBool(fractionable))
    {
    goto end; //Bool
    }
    fractionable_local_var = malloc(sizeof(int));
    if(!fractionable_local_var)
    {
        goto end;
    }
    *fractionable_local_var = fractionable->valueint;
    }

    // us_order_book_data->variety
    cJSON *variety = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "variety");
    if (cJSON_IsNull(variety)) {
        variety = NULL;
    }
    if (variety) { 
    if(!cJSON_IsString(variety) && !cJSON_IsNull(variety))
    {
    goto end; //String
    }
    }

    // us_order_book_data->tag
    cJSON *tag = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "tag");
    if (cJSON_IsNull(tag)) {
        tag = NULL;
    }
    if (tag) { 
    if(!cJSON_IsString(tag) && !cJSON_IsNull(tag))
    {
    goto end; //String
    }
    }

    // us_order_book_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // us_order_book_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // us_order_book_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // us_order_book_data->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    upstox_client_us_order_book_data_ORDERTYPE_e order_typeVariable;
    if (order_type) { 
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = us_order_book_data_order_type_FromString(order_type->valuestring);
    }

    // us_order_book_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // us_order_book_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "average_price");
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

    // us_order_book_data->filled_quantity
    cJSON *filled_quantity = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "filled_quantity");
    if (cJSON_IsNull(filled_quantity)) {
        filled_quantity = NULL;
    }
    if (filled_quantity) { 
    if(!cJSON_IsNumber(filled_quantity))
    {
    goto end; //Numeric
    }
    filled_quantity_local_var = malloc(sizeof(double));
    if(!filled_quantity_local_var)
    {
        goto end;
    }
    *filled_quantity_local_var = filled_quantity->valuedouble;
    }

    // us_order_book_data->pending_quantity
    cJSON *pending_quantity = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "pending_quantity");
    if (cJSON_IsNull(pending_quantity)) {
        pending_quantity = NULL;
    }
    if (pending_quantity) { 
    if(!cJSON_IsNumber(pending_quantity))
    {
    goto end; //Numeric
    }
    pending_quantity_local_var = malloc(sizeof(double));
    if(!pending_quantity_local_var)
    {
        goto end;
    }
    *pending_quantity_local_var = pending_quantity->valuedouble;
    }

    // us_order_book_data->status_message
    cJSON *status_message = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "status_message");
    if (cJSON_IsNull(status_message)) {
        status_message = NULL;
    }
    if (status_message) { 
    if(!cJSON_IsString(status_message) && !cJSON_IsNull(status_message))
    {
    goto end; //String
    }
    }

    // us_order_book_data->status_message_raw
    cJSON *status_message_raw = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "status_message_raw");
    if (cJSON_IsNull(status_message_raw)) {
        status_message_raw = NULL;
    }
    if (status_message_raw) { 
    if(!cJSON_IsString(status_message_raw) && !cJSON_IsNull(status_message_raw))
    {
    goto end; //String
    }
    }

    // us_order_book_data->order_timestamp
    cJSON *order_timestamp = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "order_timestamp");
    if (cJSON_IsNull(order_timestamp)) {
        order_timestamp = NULL;
    }
    if (order_timestamp) { 
    if(!cJSON_IsString(order_timestamp) && !cJSON_IsNull(order_timestamp))
    {
    goto end; //String
    }
    }

    // us_order_book_data->exchange_timestamp
    cJSON *exchange_timestamp = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "exchange_timestamp");
    if (cJSON_IsNull(exchange_timestamp)) {
        exchange_timestamp = NULL;
    }
    if (exchange_timestamp) { 
    if(!cJSON_IsString(exchange_timestamp) && !cJSON_IsNull(exchange_timestamp))
    {
    goto end; //String
    }
    }

    // us_order_book_data->is_amo
    cJSON *is_amo = cJSON_GetObjectItemCaseSensitive(us_order_book_dataJSON, "is_amo");
    if (cJSON_IsNull(is_amo)) {
        is_amo = NULL;
    }
    if (is_amo) { 
    if(!cJSON_IsBool(is_amo))
    {
    goto end; //Bool
    }
    is_amo_local_var = malloc(sizeof(int));
    if(!is_amo_local_var)
    {
        goto end;
    }
    *is_amo_local_var = is_amo->valueint;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (validity && !cJSON_IsNull(validity)) validity_local_str = strdup(validity->valuestring);
    if (variety && !cJSON_IsNull(variety)) variety_local_str = strdup(variety->valuestring);
    if (tag && !cJSON_IsNull(tag)) tag_local_str = strdup(tag->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);
    if (status_message && !cJSON_IsNull(status_message)) status_message_local_str = strdup(status_message->valuestring);
    if (status_message_raw && !cJSON_IsNull(status_message_raw)) status_message_raw_local_str = strdup(status_message_raw->valuestring);
    if (order_timestamp && !cJSON_IsNull(order_timestamp)) order_timestamp_local_str = strdup(order_timestamp->valuestring);
    if (exchange_timestamp && !cJSON_IsNull(exchange_timestamp)) exchange_timestamp_local_str = strdup(exchange_timestamp->valuestring);

    us_order_book_data_local_var = us_order_book_data_create_internal (
        name_local_str,
        exchange_local_str,
        validity_local_str,
        price_local_var,
        quantity_local_var,
        amount_local_var,
        status ? statusVariable : upstox_client_us_order_book_data_STATUS_NULL,
        fractionable_local_var,
        variety_local_str,
        tag_local_str,
        order_id_local_str,
        instrument_key_local_str,
        trading_symbol_local_str,
        order_type ? order_typeVariable : upstox_client_us_order_book_data_ORDERTYPE_NULL,
        transaction_type_local_str,
        average_price_local_var,
        filled_quantity_local_var,
        pending_quantity_local_var,
        status_message_local_str,
        status_message_raw_local_str,
        order_timestamp_local_str,
        exchange_timestamp_local_str,
        is_amo_local_var
        );

    if (!us_order_book_data_local_var) {
        goto end;
    }

    return us_order_book_data_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (validity_local_str) {
        free(validity_local_str);
        validity_local_str = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (fractionable_local_var) {
        free(fractionable_local_var);
        fractionable_local_var = NULL;
    }
    if (variety_local_str) {
        free(variety_local_str);
        variety_local_str = NULL;
    }
    if (tag_local_str) {
        free(tag_local_str);
        tag_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (filled_quantity_local_var) {
        free(filled_quantity_local_var);
        filled_quantity_local_var = NULL;
    }
    if (pending_quantity_local_var) {
        free(pending_quantity_local_var);
        pending_quantity_local_var = NULL;
    }
    if (status_message_local_str) {
        free(status_message_local_str);
        status_message_local_str = NULL;
    }
    if (status_message_raw_local_str) {
        free(status_message_raw_local_str);
        status_message_raw_local_str = NULL;
    }
    if (order_timestamp_local_str) {
        free(order_timestamp_local_str);
        order_timestamp_local_str = NULL;
    }
    if (exchange_timestamp_local_str) {
        free(exchange_timestamp_local_str);
        exchange_timestamp_local_str = NULL;
    }
    if (is_amo_local_var) {
        free(is_amo_local_var);
        is_amo_local_var = NULL;
    }
    return NULL;

}
