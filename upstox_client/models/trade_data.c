#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_data.h"


char* trade_data_exchange_ToString(upstox_client_trade_data_EXCHANGE_e exchange) {
    char* exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangeArray[exchange];
}

upstox_client_trade_data_EXCHANGE_e trade_data_exchange_FromString(char* exchange){
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
char* trade_data_product_ToString(upstox_client_trade_data_PRODUCT_e product) {
    char* productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return productArray[product];
}

upstox_client_trade_data_PRODUCT_e trade_data_product_FromString(char* product){
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
char* trade_data_order_type_ToString(upstox_client_trade_data_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typeArray[order_type];
}

upstox_client_trade_data_ORDERTYPE_e trade_data_order_type_FromString(char* order_type){
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
char* trade_data_transaction_type_ToString(upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_trade_data_TRANSACTIONTYPE_e trade_data_transaction_type_FromString(char* transaction_type){
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

static trade_data_t *trade_data_create_internal(
    upstox_client_trade_data_EXCHANGE_e exchange,
    upstox_client_trade_data_PRODUCT_e product,
    char *tradingsymbol,
    char *trading_symbol,
    char *instrument_token,
    upstox_client_trade_data_ORDERTYPE_e order_type,
    upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type,
    int *quantity,
    char *exchange_order_id,
    char *order_id,
    char *exchange_timestamp,
    double *average_price,
    char *trade_id,
    char *order_ref_id,
    char *order_timestamp
    ) {
    trade_data_t *trade_data_local_var = malloc(sizeof(trade_data_t));
    if (!trade_data_local_var) {
        return NULL;
    }
    memset(trade_data_local_var, 0, sizeof(trade_data_t));
    trade_data_local_var->_library_owned = 1;
    trade_data_local_var->exchange = exchange;
    trade_data_local_var->product = product;
    trade_data_local_var->tradingsymbol = tradingsymbol;
    trade_data_local_var->trading_symbol = trading_symbol;
    trade_data_local_var->instrument_token = instrument_token;
    trade_data_local_var->order_type = order_type;
    trade_data_local_var->transaction_type = transaction_type;
    trade_data_local_var->quantity = quantity;
    trade_data_local_var->exchange_order_id = exchange_order_id;
    trade_data_local_var->order_id = order_id;
    trade_data_local_var->exchange_timestamp = exchange_timestamp;
    trade_data_local_var->average_price = average_price;
    trade_data_local_var->trade_id = trade_id;
    trade_data_local_var->order_ref_id = order_ref_id;
    trade_data_local_var->order_timestamp = order_timestamp;
    return trade_data_local_var;
}

trade_data_t *trade_data_create(
    upstox_client_trade_data_EXCHANGE_e exchange,
    upstox_client_trade_data_PRODUCT_e product,
    char *tradingsymbol,
    char *trading_symbol,
    char *instrument_token,
    upstox_client_trade_data_ORDERTYPE_e order_type,
    upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type,
    int *quantity,
    char *exchange_order_id,
    char *order_id,
    char *exchange_timestamp,
    double *average_price,
    char *trade_id,
    char *order_ref_id,
    char *order_timestamp
    ) {
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
    trade_data_t *result = trade_data_create_internal (
        exchange,
        product,
        tradingsymbol,
        trading_symbol,
        instrument_token,
        order_type,
        transaction_type,
        quantity_copy,
        exchange_order_id,
        order_id,
        exchange_timestamp,
        average_price_copy,
        trade_id,
        order_ref_id,
        order_timestamp
        );
    if (!result) {
        free(quantity_copy);
        free(average_price_copy);
    }
    return result;
}

void trade_data_free(trade_data_t *trade_data) {
    if(NULL == trade_data){
        return ;
    }
    if(trade_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_data->tradingsymbol) {
        free(trade_data->tradingsymbol);
        trade_data->tradingsymbol = NULL;
    }
    if (trade_data->trading_symbol) {
        free(trade_data->trading_symbol);
        trade_data->trading_symbol = NULL;
    }
    if (trade_data->instrument_token) {
        free(trade_data->instrument_token);
        trade_data->instrument_token = NULL;
    }
    if (trade_data->quantity) {
        free(trade_data->quantity);
        trade_data->quantity = NULL;
    }
    if (trade_data->exchange_order_id) {
        free(trade_data->exchange_order_id);
        trade_data->exchange_order_id = NULL;
    }
    if (trade_data->order_id) {
        free(trade_data->order_id);
        trade_data->order_id = NULL;
    }
    if (trade_data->exchange_timestamp) {
        free(trade_data->exchange_timestamp);
        trade_data->exchange_timestamp = NULL;
    }
    if (trade_data->average_price) {
        free(trade_data->average_price);
        trade_data->average_price = NULL;
    }
    if (trade_data->trade_id) {
        free(trade_data->trade_id);
        trade_data->trade_id = NULL;
    }
    if (trade_data->order_ref_id) {
        free(trade_data->order_ref_id);
        trade_data->order_ref_id = NULL;
    }
    if (trade_data->order_timestamp) {
        free(trade_data->order_timestamp);
        trade_data->order_timestamp = NULL;
    }
    free(trade_data);
}

cJSON *trade_data_convertToJSON(trade_data_t *trade_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_data->exchange
    if(trade_data->exchange != upstox_client_trade_data_EXCHANGE_NULL) {
    if(cJSON_AddStringToObject(item, "exchange", trade_data_exchange_ToString(trade_data->exchange)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trade_data->product
    if(trade_data->product != upstox_client_trade_data_PRODUCT_NULL) {
    if(cJSON_AddStringToObject(item, "product", trade_data_product_ToString(trade_data->product)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trade_data->tradingsymbol
    if(trade_data->tradingsymbol) {
    if(cJSON_AddStringToObject(item, "tradingsymbol", trade_data->tradingsymbol) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->trading_symbol
    if(trade_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", trade_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->instrument_token
    if(trade_data->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", trade_data->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->order_type
    if(trade_data->order_type != upstox_client_trade_data_ORDERTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "order_type", trade_data_order_type_ToString(trade_data->order_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trade_data->transaction_type
    if(trade_data->transaction_type != upstox_client_trade_data_TRANSACTIONTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "transaction_type", trade_data_transaction_type_ToString(trade_data->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trade_data->quantity
    if(trade_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *trade_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_data->exchange_order_id
    if(trade_data->exchange_order_id) {
    if(cJSON_AddStringToObject(item, "exchange_order_id", trade_data->exchange_order_id) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->order_id
    if(trade_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", trade_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->exchange_timestamp
    if(trade_data->exchange_timestamp) {
    if(cJSON_AddStringToObject(item, "exchange_timestamp", trade_data->exchange_timestamp) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->average_price
    if(trade_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *trade_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_data->trade_id
    if(trade_data->trade_id) {
    if(cJSON_AddStringToObject(item, "trade_id", trade_data->trade_id) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->order_ref_id
    if(trade_data->order_ref_id) {
    if(cJSON_AddStringToObject(item, "order_ref_id", trade_data->order_ref_id) == NULL) {
    goto fail; //String
    }
    }


    // trade_data->order_timestamp
    if(trade_data->order_timestamp) {
    if(cJSON_AddStringToObject(item, "order_timestamp", trade_data->order_timestamp) == NULL) {
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

trade_data_t *trade_data_parseFromJSON(cJSON *trade_dataJSON){

    trade_data_t *trade_data_local_var = NULL;

    char *tradingsymbol_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for trade_data->quantity
    int *quantity_local_var = NULL;

    char *exchange_order_id_local_str = NULL;

    char *order_id_local_str = NULL;

    char *exchange_timestamp_local_str = NULL;

    // define the local variable for trade_data->average_price
    double *average_price_local_var = NULL;

    char *trade_id_local_str = NULL;

    char *order_ref_id_local_str = NULL;

    char *order_timestamp_local_str = NULL;

    // trade_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    upstox_client_trade_data_EXCHANGE_e exchangeVariable;
    if (exchange) { 
    if(!cJSON_IsString(exchange))
    {
    goto end; //Enum
    }
    exchangeVariable = trade_data_exchange_FromString(exchange->valuestring);
    }

    // trade_data->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    upstox_client_trade_data_PRODUCT_e productVariable;
    if (product) { 
    if(!cJSON_IsString(product))
    {
    goto end; //Enum
    }
    productVariable = trade_data_product_FromString(product->valuestring);
    }

    // trade_data->tradingsymbol
    cJSON *tradingsymbol = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "tradingsymbol");
    if (cJSON_IsNull(tradingsymbol)) {
        tradingsymbol = NULL;
    }
    if (tradingsymbol) { 
    if(!cJSON_IsString(tradingsymbol) && !cJSON_IsNull(tradingsymbol))
    {
    goto end; //String
    }
    }

    // trade_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // trade_data->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // trade_data->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    upstox_client_trade_data_ORDERTYPE_e order_typeVariable;
    if (order_type) { 
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = trade_data_order_type_FromString(order_type->valuestring);
    }

    // trade_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    upstox_client_trade_data_TRANSACTIONTYPE_e transaction_typeVariable;
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = trade_data_transaction_type_FromString(transaction_type->valuestring);
    }

    // trade_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "quantity");
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

    // trade_data->exchange_order_id
    cJSON *exchange_order_id = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "exchange_order_id");
    if (cJSON_IsNull(exchange_order_id)) {
        exchange_order_id = NULL;
    }
    if (exchange_order_id) { 
    if(!cJSON_IsString(exchange_order_id) && !cJSON_IsNull(exchange_order_id))
    {
    goto end; //String
    }
    }

    // trade_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // trade_data->exchange_timestamp
    cJSON *exchange_timestamp = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "exchange_timestamp");
    if (cJSON_IsNull(exchange_timestamp)) {
        exchange_timestamp = NULL;
    }
    if (exchange_timestamp) { 
    if(!cJSON_IsString(exchange_timestamp) && !cJSON_IsNull(exchange_timestamp))
    {
    goto end; //String
    }
    }

    // trade_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "average_price");
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

    // trade_data->trade_id
    cJSON *trade_id = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "trade_id");
    if (cJSON_IsNull(trade_id)) {
        trade_id = NULL;
    }
    if (trade_id) { 
    if(!cJSON_IsString(trade_id) && !cJSON_IsNull(trade_id))
    {
    goto end; //String
    }
    }

    // trade_data->order_ref_id
    cJSON *order_ref_id = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "order_ref_id");
    if (cJSON_IsNull(order_ref_id)) {
        order_ref_id = NULL;
    }
    if (order_ref_id) { 
    if(!cJSON_IsString(order_ref_id) && !cJSON_IsNull(order_ref_id))
    {
    goto end; //String
    }
    }

    // trade_data->order_timestamp
    cJSON *order_timestamp = cJSON_GetObjectItemCaseSensitive(trade_dataJSON, "order_timestamp");
    if (cJSON_IsNull(order_timestamp)) {
        order_timestamp = NULL;
    }
    if (order_timestamp) { 
    if(!cJSON_IsString(order_timestamp) && !cJSON_IsNull(order_timestamp))
    {
    goto end; //String
    }
    }


    if (tradingsymbol && !cJSON_IsNull(tradingsymbol)) tradingsymbol_local_str = strdup(tradingsymbol->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (exchange_order_id && !cJSON_IsNull(exchange_order_id)) exchange_order_id_local_str = strdup(exchange_order_id->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (exchange_timestamp && !cJSON_IsNull(exchange_timestamp)) exchange_timestamp_local_str = strdup(exchange_timestamp->valuestring);
    if (trade_id && !cJSON_IsNull(trade_id)) trade_id_local_str = strdup(trade_id->valuestring);
    if (order_ref_id && !cJSON_IsNull(order_ref_id)) order_ref_id_local_str = strdup(order_ref_id->valuestring);
    if (order_timestamp && !cJSON_IsNull(order_timestamp)) order_timestamp_local_str = strdup(order_timestamp->valuestring);

    trade_data_local_var = trade_data_create_internal (
        exchange ? exchangeVariable : upstox_client_trade_data_EXCHANGE_NULL,
        product ? productVariable : upstox_client_trade_data_PRODUCT_NULL,
        tradingsymbol_local_str,
        trading_symbol_local_str,
        instrument_token_local_str,
        order_type ? order_typeVariable : upstox_client_trade_data_ORDERTYPE_NULL,
        transaction_type ? transaction_typeVariable : upstox_client_trade_data_TRANSACTIONTYPE_NULL,
        quantity_local_var,
        exchange_order_id_local_str,
        order_id_local_str,
        exchange_timestamp_local_str,
        average_price_local_var,
        trade_id_local_str,
        order_ref_id_local_str,
        order_timestamp_local_str
        );

    if (!trade_data_local_var) {
        goto end;
    }

    return trade_data_local_var;
end:
    if (tradingsymbol_local_str) {
        free(tradingsymbol_local_str);
        tradingsymbol_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (exchange_order_id_local_str) {
        free(exchange_order_id_local_str);
        exchange_order_id_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (exchange_timestamp_local_str) {
        free(exchange_timestamp_local_str);
        exchange_timestamp_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (trade_id_local_str) {
        free(trade_id_local_str);
        trade_id_local_str = NULL;
    }
    if (order_ref_id_local_str) {
        free(order_ref_id_local_str);
        order_ref_id_local_str = NULL;
    }
    if (order_timestamp_local_str) {
        free(order_timestamp_local_str);
        order_timestamp_local_str = NULL;
    }
    return NULL;

}
