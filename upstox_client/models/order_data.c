#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_data.h"


char* order_data_exchange_ToString(upstox_client_order_data_EXCHANGE_e exchange) {
    char* exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangeArray[exchange];
}

upstox_client_order_data_EXCHANGE_e order_data_exchange_FromString(char* exchange){
    int stringToReturn = 0;
    char *exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    size_t sizeofArray = sizeof(exchangeArray) / sizeof(exchangeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(exchange, exchangeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* order_data_product_ToString(upstox_client_order_data_PRODUCT_e product) {
    char* productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return productArray[product];
}

upstox_client_order_data_PRODUCT_e order_data_product_FromString(char* product){
    int stringToReturn = 0;
    char *productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    size_t sizeofArray = sizeof(productArray) / sizeof(productArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(product, productArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* order_data_validity_ToString(upstox_client_order_data_VALIDITY_e validity) {
    char* validityArray[] =  { "NULL", "DAY", "IOC", "EOS" };
    return validityArray[validity];
}

upstox_client_order_data_VALIDITY_e order_data_validity_FromString(char* validity){
    int stringToReturn = 0;
    char *validityArray[] =  { "NULL", "DAY", "IOC", "EOS" };
    size_t sizeofArray = sizeof(validityArray) / sizeof(validityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(validity, validityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* order_data_order_type_ToString(upstox_client_order_data_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typeArray[order_type];
}

upstox_client_order_data_ORDERTYPE_e order_data_order_type_FromString(char* order_type){
    int stringToReturn = 0;
    char *order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    size_t sizeofArray = sizeof(order_typeArray) / sizeof(order_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(order_type, order_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* order_data_transaction_type_ToString(upstox_client_order_data_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_order_data_TRANSACTIONTYPE_e order_data_transaction_type_FromString(char* transaction_type){
    int stringToReturn = 0;
    char *transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    size_t sizeofArray = sizeof(transaction_typeArray) / sizeof(transaction_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(transaction_type, transaction_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static order_data_t *order_data_create_internal(
    upstox_client_order_data_EXCHANGE_e exchange,
    double *price,
    upstox_client_order_data_PRODUCT_e product,
    int *quantity,
    char *status,
    char *tag,
    upstox_client_order_data_VALIDITY_e validity,
    double *average_price,
    int *disclosed_quantity,
    char *exchange_order_id,
    char *exchange_timestamp,
    char *instrument_token,
    int *is_amo,
    char *status_message,
    char *order_id,
    char *order_request_id,
    upstox_client_order_data_ORDERTYPE_e order_type,
    char *parent_order_id,
    char *tradingsymbol,
    char *trading_symbol,
    char *order_timestamp,
    int *filled_quantity,
    upstox_client_order_data_TRANSACTIONTYPE_e transaction_type,
    double *trigger_price,
    char *placed_by,
    char *variety
    ) {
    order_data_t *order_data_local_var = malloc(sizeof(order_data_t));
    if (!order_data_local_var) {
        return NULL;
    }
    memset(order_data_local_var, 0, sizeof(order_data_t));
    order_data_local_var->_library_owned = 1;
    order_data_local_var->exchange = exchange;
    order_data_local_var->price = price;
    order_data_local_var->product = product;
    order_data_local_var->quantity = quantity;
    order_data_local_var->status = status;
    order_data_local_var->tag = tag;
    order_data_local_var->validity = validity;
    order_data_local_var->average_price = average_price;
    order_data_local_var->disclosed_quantity = disclosed_quantity;
    order_data_local_var->exchange_order_id = exchange_order_id;
    order_data_local_var->exchange_timestamp = exchange_timestamp;
    order_data_local_var->instrument_token = instrument_token;
    order_data_local_var->is_amo = is_amo;
    order_data_local_var->status_message = status_message;
    order_data_local_var->order_id = order_id;
    order_data_local_var->order_request_id = order_request_id;
    order_data_local_var->order_type = order_type;
    order_data_local_var->parent_order_id = parent_order_id;
    order_data_local_var->tradingsymbol = tradingsymbol;
    order_data_local_var->trading_symbol = trading_symbol;
    order_data_local_var->order_timestamp = order_timestamp;
    order_data_local_var->filled_quantity = filled_quantity;
    order_data_local_var->transaction_type = transaction_type;
    order_data_local_var->trigger_price = trigger_price;
    order_data_local_var->placed_by = placed_by;
    order_data_local_var->variety = variety;
    return order_data_local_var;
}

order_data_t *order_data_create(
    upstox_client_order_data_EXCHANGE_e exchange,
    double *price,
    upstox_client_order_data_PRODUCT_e product,
    int *quantity,
    char *status,
    char *tag,
    upstox_client_order_data_VALIDITY_e validity,
    double *average_price,
    int *disclosed_quantity,
    char *exchange_order_id,
    char *exchange_timestamp,
    char *instrument_token,
    int *is_amo,
    char *status_message,
    char *order_id,
    char *order_request_id,
    upstox_client_order_data_ORDERTYPE_e order_type,
    char *parent_order_id,
    char *tradingsymbol,
    char *trading_symbol,
    char *order_timestamp,
    int *filled_quantity,
    upstox_client_order_data_TRANSACTIONTYPE_e transaction_type,
    double *trigger_price,
    char *placed_by,
    char *variety
    ) {
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    int *disclosed_quantity_copy = NULL;
    if (disclosed_quantity) {
        disclosed_quantity_copy = malloc(sizeof(int));
        if (disclosed_quantity_copy) *disclosed_quantity_copy = *disclosed_quantity;
    }
    int *is_amo_copy = NULL;
    if (is_amo) {
        is_amo_copy = malloc(sizeof(int));
        if (is_amo_copy) *is_amo_copy = *is_amo;
    }
    int *filled_quantity_copy = NULL;
    if (filled_quantity) {
        filled_quantity_copy = malloc(sizeof(int));
        if (filled_quantity_copy) *filled_quantity_copy = *filled_quantity;
    }
    double *trigger_price_copy = NULL;
    if (trigger_price) {
        trigger_price_copy = malloc(sizeof(double));
        if (trigger_price_copy) *trigger_price_copy = *trigger_price;
    }
    order_data_t *result = order_data_create_internal (
        exchange,
        price_copy,
        product,
        quantity_copy,
        status,
        tag,
        validity,
        average_price_copy,
        disclosed_quantity_copy,
        exchange_order_id,
        exchange_timestamp,
        instrument_token,
        is_amo_copy,
        status_message,
        order_id,
        order_request_id,
        order_type,
        parent_order_id,
        tradingsymbol,
        trading_symbol,
        order_timestamp,
        filled_quantity_copy,
        transaction_type,
        trigger_price_copy,
        placed_by,
        variety
        );
    if (!result) {
        free(price_copy);
        free(quantity_copy);
        free(average_price_copy);
        free(disclosed_quantity_copy);
        free(is_amo_copy);
        free(filled_quantity_copy);
        free(trigger_price_copy);
    }
    return result;
}

void order_data_free(order_data_t *order_data) {
    if(NULL == order_data){
        return ;
    }
    if(order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_data->price) {
        free(order_data->price);
        order_data->price = NULL;
    }
    if (order_data->quantity) {
        free(order_data->quantity);
        order_data->quantity = NULL;
    }
    if (order_data->status) {
        free(order_data->status);
        order_data->status = NULL;
    }
    if (order_data->tag) {
        free(order_data->tag);
        order_data->tag = NULL;
    }
    if (order_data->average_price) {
        free(order_data->average_price);
        order_data->average_price = NULL;
    }
    if (order_data->disclosed_quantity) {
        free(order_data->disclosed_quantity);
        order_data->disclosed_quantity = NULL;
    }
    if (order_data->exchange_order_id) {
        free(order_data->exchange_order_id);
        order_data->exchange_order_id = NULL;
    }
    if (order_data->exchange_timestamp) {
        free(order_data->exchange_timestamp);
        order_data->exchange_timestamp = NULL;
    }
    if (order_data->instrument_token) {
        free(order_data->instrument_token);
        order_data->instrument_token = NULL;
    }
    if (order_data->is_amo) {
        free(order_data->is_amo);
        order_data->is_amo = NULL;
    }
    if (order_data->status_message) {
        free(order_data->status_message);
        order_data->status_message = NULL;
    }
    if (order_data->order_id) {
        free(order_data->order_id);
        order_data->order_id = NULL;
    }
    if (order_data->order_request_id) {
        free(order_data->order_request_id);
        order_data->order_request_id = NULL;
    }
    if (order_data->parent_order_id) {
        free(order_data->parent_order_id);
        order_data->parent_order_id = NULL;
    }
    if (order_data->tradingsymbol) {
        free(order_data->tradingsymbol);
        order_data->tradingsymbol = NULL;
    }
    if (order_data->trading_symbol) {
        free(order_data->trading_symbol);
        order_data->trading_symbol = NULL;
    }
    if (order_data->order_timestamp) {
        free(order_data->order_timestamp);
        order_data->order_timestamp = NULL;
    }
    if (order_data->filled_quantity) {
        free(order_data->filled_quantity);
        order_data->filled_quantity = NULL;
    }
    if (order_data->trigger_price) {
        free(order_data->trigger_price);
        order_data->trigger_price = NULL;
    }
    if (order_data->placed_by) {
        free(order_data->placed_by);
        order_data->placed_by = NULL;
    }
    if (order_data->variety) {
        free(order_data->variety);
        order_data->variety = NULL;
    }
    free(order_data);
}

cJSON *order_data_convertToJSON(order_data_t *order_data) {
    cJSON *item = cJSON_CreateObject();

    // order_data->exchange
    if(order_data->exchange != upstox_client_order_data_EXCHANGE_NULL) {
    if(cJSON_AddStringToObject(item, "exchange", order_data_exchange_ToString(order_data->exchange)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // order_data->price
    if(order_data->price) {
    if(cJSON_AddNumberToObject(item, "price", *order_data->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->product
    if(order_data->product != upstox_client_order_data_PRODUCT_NULL) {
    if(cJSON_AddStringToObject(item, "product", order_data_product_ToString(order_data->product)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // order_data->quantity
    if(order_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *order_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->status
    if(order_data->status) {
    if(cJSON_AddStringToObject(item, "status", order_data->status) == NULL) {
    goto fail; //String
    }
    }


    // order_data->tag
    if(order_data->tag) {
    if(cJSON_AddStringToObject(item, "tag", order_data->tag) == NULL) {
    goto fail; //String
    }
    }


    // order_data->validity
    if(order_data->validity != upstox_client_order_data_VALIDITY_NULL) {
    if(cJSON_AddStringToObject(item, "validity", order_data_validity_ToString(order_data->validity)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // order_data->average_price
    if(order_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *order_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->disclosed_quantity
    if(order_data->disclosed_quantity) {
    if(cJSON_AddNumberToObject(item, "disclosed_quantity", *order_data->disclosed_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->exchange_order_id
    if(order_data->exchange_order_id) {
    if(cJSON_AddStringToObject(item, "exchange_order_id", order_data->exchange_order_id) == NULL) {
    goto fail; //String
    }
    }


    // order_data->exchange_timestamp
    if(order_data->exchange_timestamp) {
    if(cJSON_AddStringToObject(item, "exchange_timestamp", order_data->exchange_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // order_data->instrument_token
    if(order_data->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", order_data->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // order_data->is_amo
    if(order_data->is_amo) {
    if(cJSON_AddBoolToObject(item, "is_amo", *order_data->is_amo) == NULL) {
    goto fail; //Bool
    }
    }


    // order_data->status_message
    if(order_data->status_message) {
    if(cJSON_AddStringToObject(item, "status_message", order_data->status_message) == NULL) {
    goto fail; //String
    }
    }


    // order_data->order_id
    if(order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", order_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // order_data->order_request_id
    if(order_data->order_request_id) {
    if(cJSON_AddStringToObject(item, "order_request_id", order_data->order_request_id) == NULL) {
    goto fail; //String
    }
    }


    // order_data->order_type
    if(order_data->order_type != upstox_client_order_data_ORDERTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "order_type", order_data_order_type_ToString(order_data->order_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // order_data->parent_order_id
    if(order_data->parent_order_id) {
    if(cJSON_AddStringToObject(item, "parent_order_id", order_data->parent_order_id) == NULL) {
    goto fail; //String
    }
    }


    // order_data->tradingsymbol
    if(order_data->tradingsymbol) {
    if(cJSON_AddStringToObject(item, "tradingsymbol", order_data->tradingsymbol) == NULL) {
    goto fail; //String
    }
    }


    // order_data->trading_symbol
    if(order_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", order_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // order_data->order_timestamp
    if(order_data->order_timestamp) {
    if(cJSON_AddStringToObject(item, "order_timestamp", order_data->order_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // order_data->filled_quantity
    if(order_data->filled_quantity) {
    if(cJSON_AddNumberToObject(item, "filled_quantity", *order_data->filled_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->transaction_type
    if(order_data->transaction_type != upstox_client_order_data_TRANSACTIONTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "transaction_type", order_data_transaction_type_ToString(order_data->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // order_data->trigger_price
    if(order_data->trigger_price) {
    if(cJSON_AddNumberToObject(item, "trigger_price", *order_data->trigger_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // order_data->placed_by
    if(order_data->placed_by) {
    if(cJSON_AddStringToObject(item, "placed_by", order_data->placed_by) == NULL) {
    goto fail; //String
    }
    }


    // order_data->variety
    if(order_data->variety) {
    if(cJSON_AddStringToObject(item, "variety", order_data->variety) == NULL) {
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

order_data_t *order_data_parseFromJSON(cJSON *order_dataJSON){

    order_data_t *order_data_local_var = NULL;

    // define the local variable for order_data->price
    double *price_local_var = NULL;

    // define the local variable for order_data->quantity
    int *quantity_local_var = NULL;

    char *status_local_str = NULL;

    char *tag_local_str = NULL;

    // define the local variable for order_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for order_data->disclosed_quantity
    int *disclosed_quantity_local_var = NULL;

    char *exchange_order_id_local_str = NULL;

    char *exchange_timestamp_local_str = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for order_data->is_amo
    int *is_amo_local_var = NULL;

    char *status_message_local_str = NULL;

    char *order_id_local_str = NULL;

    char *order_request_id_local_str = NULL;

    char *parent_order_id_local_str = NULL;

    char *tradingsymbol_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    char *order_timestamp_local_str = NULL;

    // define the local variable for order_data->filled_quantity
    int *filled_quantity_local_var = NULL;

    // define the local variable for order_data->trigger_price
    double *trigger_price_local_var = NULL;

    char *placed_by_local_str = NULL;

    char *variety_local_str = NULL;

    // order_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    upstox_client_order_data_EXCHANGE_e exchangeVariable;
    if (exchange) { 
    if(!cJSON_IsString(exchange))
    {
    goto end; //Enum
    }
    exchangeVariable = order_data_exchange_FromString(exchange->valuestring);
    }

    // order_data->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "price");
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

    // order_data->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    upstox_client_order_data_PRODUCT_e productVariable;
    if (product) { 
    if(!cJSON_IsString(product))
    {
    goto end; //Enum
    }
    productVariable = order_data_product_FromString(product->valuestring);
    }

    // order_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "quantity");
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

    // order_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // order_data->tag
    cJSON *tag = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "tag");
    if (cJSON_IsNull(tag)) {
        tag = NULL;
    }
    if (tag) { 
    if(!cJSON_IsString(tag) && !cJSON_IsNull(tag))
    {
    goto end; //String
    }
    }

    // order_data->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    upstox_client_order_data_VALIDITY_e validityVariable;
    if (validity) { 
    if(!cJSON_IsString(validity))
    {
    goto end; //Enum
    }
    validityVariable = order_data_validity_FromString(validity->valuestring);
    }

    // order_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "average_price");
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

    // order_data->disclosed_quantity
    cJSON *disclosed_quantity = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "disclosed_quantity");
    if (cJSON_IsNull(disclosed_quantity)) {
        disclosed_quantity = NULL;
    }
    if (disclosed_quantity) { 
    if(!cJSON_IsNumber(disclosed_quantity))
    {
    goto end; //Numeric
    }
    disclosed_quantity_local_var = malloc(sizeof(int));
    if(!disclosed_quantity_local_var)
    {
        goto end;
    }
    *disclosed_quantity_local_var = disclosed_quantity->valuedouble;
    }

    // order_data->exchange_order_id
    cJSON *exchange_order_id = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "exchange_order_id");
    if (cJSON_IsNull(exchange_order_id)) {
        exchange_order_id = NULL;
    }
    if (exchange_order_id) { 
    if(!cJSON_IsString(exchange_order_id) && !cJSON_IsNull(exchange_order_id))
    {
    goto end; //String
    }
    }

    // order_data->exchange_timestamp
    cJSON *exchange_timestamp = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "exchange_timestamp");
    if (cJSON_IsNull(exchange_timestamp)) {
        exchange_timestamp = NULL;
    }
    if (exchange_timestamp) { 
    if(!cJSON_IsString(exchange_timestamp) && !cJSON_IsNull(exchange_timestamp))
    {
    goto end; //String
    }
    }

    // order_data->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // order_data->is_amo
    cJSON *is_amo = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "is_amo");
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

    // order_data->status_message
    cJSON *status_message = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "status_message");
    if (cJSON_IsNull(status_message)) {
        status_message = NULL;
    }
    if (status_message) { 
    if(!cJSON_IsString(status_message) && !cJSON_IsNull(status_message))
    {
    goto end; //String
    }
    }

    // order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // order_data->order_request_id
    cJSON *order_request_id = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "order_request_id");
    if (cJSON_IsNull(order_request_id)) {
        order_request_id = NULL;
    }
    if (order_request_id) { 
    if(!cJSON_IsString(order_request_id) && !cJSON_IsNull(order_request_id))
    {
    goto end; //String
    }
    }

    // order_data->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    upstox_client_order_data_ORDERTYPE_e order_typeVariable;
    if (order_type) { 
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = order_data_order_type_FromString(order_type->valuestring);
    }

    // order_data->parent_order_id
    cJSON *parent_order_id = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "parent_order_id");
    if (cJSON_IsNull(parent_order_id)) {
        parent_order_id = NULL;
    }
    if (parent_order_id) { 
    if(!cJSON_IsString(parent_order_id) && !cJSON_IsNull(parent_order_id))
    {
    goto end; //String
    }
    }

    // order_data->tradingsymbol
    cJSON *tradingsymbol = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "tradingsymbol");
    if (cJSON_IsNull(tradingsymbol)) {
        tradingsymbol = NULL;
    }
    if (tradingsymbol) { 
    if(!cJSON_IsString(tradingsymbol) && !cJSON_IsNull(tradingsymbol))
    {
    goto end; //String
    }
    }

    // order_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // order_data->order_timestamp
    cJSON *order_timestamp = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "order_timestamp");
    if (cJSON_IsNull(order_timestamp)) {
        order_timestamp = NULL;
    }
    if (order_timestamp) { 
    if(!cJSON_IsString(order_timestamp) && !cJSON_IsNull(order_timestamp))
    {
    goto end; //String
    }
    }

    // order_data->filled_quantity
    cJSON *filled_quantity = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "filled_quantity");
    if (cJSON_IsNull(filled_quantity)) {
        filled_quantity = NULL;
    }
    if (filled_quantity) { 
    if(!cJSON_IsNumber(filled_quantity))
    {
    goto end; //Numeric
    }
    filled_quantity_local_var = malloc(sizeof(int));
    if(!filled_quantity_local_var)
    {
        goto end;
    }
    *filled_quantity_local_var = filled_quantity->valuedouble;
    }

    // order_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    upstox_client_order_data_TRANSACTIONTYPE_e transaction_typeVariable;
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = order_data_transaction_type_FromString(transaction_type->valuestring);
    }

    // order_data->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "trigger_price");
    if (cJSON_IsNull(trigger_price)) {
        trigger_price = NULL;
    }
    if (trigger_price) { 
    if(!cJSON_IsNumber(trigger_price))
    {
    goto end; //Numeric
    }
    trigger_price_local_var = malloc(sizeof(double));
    if(!trigger_price_local_var)
    {
        goto end;
    }
    *trigger_price_local_var = trigger_price->valuedouble;
    }

    // order_data->placed_by
    cJSON *placed_by = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "placed_by");
    if (cJSON_IsNull(placed_by)) {
        placed_by = NULL;
    }
    if (placed_by) { 
    if(!cJSON_IsString(placed_by) && !cJSON_IsNull(placed_by))
    {
    goto end; //String
    }
    }

    // order_data->variety
    cJSON *variety = cJSON_GetObjectItemCaseSensitive(order_dataJSON, "variety");
    if (cJSON_IsNull(variety)) {
        variety = NULL;
    }
    if (variety) { 
    if(!cJSON_IsString(variety) && !cJSON_IsNull(variety))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (tag && !cJSON_IsNull(tag)) tag_local_str = strdup(tag->valuestring);
    if (exchange_order_id && !cJSON_IsNull(exchange_order_id)) exchange_order_id_local_str = strdup(exchange_order_id->valuestring);
    if (exchange_timestamp && !cJSON_IsNull(exchange_timestamp)) exchange_timestamp_local_str = strdup(exchange_timestamp->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (status_message && !cJSON_IsNull(status_message)) status_message_local_str = strdup(status_message->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (order_request_id && !cJSON_IsNull(order_request_id)) order_request_id_local_str = strdup(order_request_id->valuestring);
    if (parent_order_id && !cJSON_IsNull(parent_order_id)) parent_order_id_local_str = strdup(parent_order_id->valuestring);
    if (tradingsymbol && !cJSON_IsNull(tradingsymbol)) tradingsymbol_local_str = strdup(tradingsymbol->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (order_timestamp && !cJSON_IsNull(order_timestamp)) order_timestamp_local_str = strdup(order_timestamp->valuestring);
    if (placed_by && !cJSON_IsNull(placed_by)) placed_by_local_str = strdup(placed_by->valuestring);
    if (variety && !cJSON_IsNull(variety)) variety_local_str = strdup(variety->valuestring);

    order_data_local_var = order_data_create_internal (
        exchange ? exchangeVariable : upstox_client_order_data_EXCHANGE_NULL,
        price_local_var,
        product ? productVariable : upstox_client_order_data_PRODUCT_NULL,
        quantity_local_var,
        status_local_str,
        tag_local_str,
        validity ? validityVariable : upstox_client_order_data_VALIDITY_NULL,
        average_price_local_var,
        disclosed_quantity_local_var,
        exchange_order_id_local_str,
        exchange_timestamp_local_str,
        instrument_token_local_str,
        is_amo_local_var,
        status_message_local_str,
        order_id_local_str,
        order_request_id_local_str,
        order_type ? order_typeVariable : upstox_client_order_data_ORDERTYPE_NULL,
        parent_order_id_local_str,
        tradingsymbol_local_str,
        trading_symbol_local_str,
        order_timestamp_local_str,
        filled_quantity_local_var,
        transaction_type ? transaction_typeVariable : upstox_client_order_data_TRANSACTIONTYPE_NULL,
        trigger_price_local_var,
        placed_by_local_str,
        variety_local_str
        );

    if (!order_data_local_var) {
        goto end;
    }

    return order_data_local_var;
end:
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (tag_local_str) {
        free(tag_local_str);
        tag_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (disclosed_quantity_local_var) {
        free(disclosed_quantity_local_var);
        disclosed_quantity_local_var = NULL;
    }
    if (exchange_order_id_local_str) {
        free(exchange_order_id_local_str);
        exchange_order_id_local_str = NULL;
    }
    if (exchange_timestamp_local_str) {
        free(exchange_timestamp_local_str);
        exchange_timestamp_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (is_amo_local_var) {
        free(is_amo_local_var);
        is_amo_local_var = NULL;
    }
    if (status_message_local_str) {
        free(status_message_local_str);
        status_message_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (order_request_id_local_str) {
        free(order_request_id_local_str);
        order_request_id_local_str = NULL;
    }
    if (parent_order_id_local_str) {
        free(parent_order_id_local_str);
        parent_order_id_local_str = NULL;
    }
    if (tradingsymbol_local_str) {
        free(tradingsymbol_local_str);
        tradingsymbol_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (order_timestamp_local_str) {
        free(order_timestamp_local_str);
        order_timestamp_local_str = NULL;
    }
    if (filled_quantity_local_var) {
        free(filled_quantity_local_var);
        filled_quantity_local_var = NULL;
    }
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (placed_by_local_str) {
        free(placed_by_local_str);
        placed_by_local_str = NULL;
    }
    if (variety_local_str) {
        free(variety_local_str);
        variety_local_str = NULL;
    }
    return NULL;

}
