#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_estimate_request.h"


char* us_order_estimate_request_transaction_type_ToString(upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e us_order_estimate_request_transaction_type_FromString(char* transaction_type){
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
char* us_order_estimate_request_order_type_ToString(upstox_client_us_order_estimate_request_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT" };
    return order_typeArray[order_type];
}

upstox_client_us_order_estimate_request_ORDERTYPE_e us_order_estimate_request_order_type_FromString(char* order_type){
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

static us_order_estimate_request_t *us_order_estimate_request_create_internal(
    double *quantity,
    double *price,
    char *instrument_key,
    upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_order_estimate_request_ORDERTYPE_e order_type
    ) {
    us_order_estimate_request_t *us_order_estimate_request_local_var = malloc(sizeof(us_order_estimate_request_t));
    if (!us_order_estimate_request_local_var) {
        return NULL;
    }
    memset(us_order_estimate_request_local_var, 0, sizeof(us_order_estimate_request_t));
    us_order_estimate_request_local_var->_library_owned = 1;
    us_order_estimate_request_local_var->quantity = quantity;
    us_order_estimate_request_local_var->price = price;
    us_order_estimate_request_local_var->instrument_key = instrument_key;
    us_order_estimate_request_local_var->transaction_type = transaction_type;
    us_order_estimate_request_local_var->order_type = order_type;
    return us_order_estimate_request_local_var;
}

us_order_estimate_request_t *us_order_estimate_request_create(
    double *quantity,
    double *price,
    char *instrument_key,
    upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_order_estimate_request_ORDERTYPE_e order_type
    ) {
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
    us_order_estimate_request_t *result = us_order_estimate_request_create_internal (
        quantity_copy,
        price_copy,
        instrument_key,
        transaction_type,
        order_type
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
    }
    return result;
}

void us_order_estimate_request_free(us_order_estimate_request_t *us_order_estimate_request) {
    if(NULL == us_order_estimate_request){
        return ;
    }
    if(us_order_estimate_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_estimate_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_estimate_request->quantity) {
        free(us_order_estimate_request->quantity);
        us_order_estimate_request->quantity = NULL;
    }
    if (us_order_estimate_request->price) {
        free(us_order_estimate_request->price);
        us_order_estimate_request->price = NULL;
    }
    if (us_order_estimate_request->instrument_key) {
        free(us_order_estimate_request->instrument_key);
        us_order_estimate_request->instrument_key = NULL;
    }
    free(us_order_estimate_request);
}

cJSON *us_order_estimate_request_convertToJSON(us_order_estimate_request_t *us_order_estimate_request) {
    cJSON *item = cJSON_CreateObject();

    // us_order_estimate_request->quantity
    if (!us_order_estimate_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *us_order_estimate_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // us_order_estimate_request->price
    if(us_order_estimate_request->price) {
    if(cJSON_AddNumberToObject(item, "price", *us_order_estimate_request->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_request->instrument_key
    if (!us_order_estimate_request->instrument_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_key", us_order_estimate_request->instrument_key) == NULL) {
    goto fail; //String
    }


    // us_order_estimate_request->transaction_type
    if (upstox_client_us_order_estimate_request_TRANSACTIONTYPE_NULL == us_order_estimate_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", us_order_estimate_request_transaction_type_ToString(us_order_estimate_request->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // us_order_estimate_request->order_type
    if (upstox_client_us_order_estimate_request_ORDERTYPE_NULL == us_order_estimate_request->order_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_type", us_order_estimate_request_order_type_ToString(us_order_estimate_request->order_type)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

us_order_estimate_request_t *us_order_estimate_request_parseFromJSON(cJSON *us_order_estimate_requestJSON){

    us_order_estimate_request_t *us_order_estimate_request_local_var = NULL;

    // define the local variable for us_order_estimate_request->quantity
    double *quantity_local_var = NULL;

    // define the local variable for us_order_estimate_request->price
    double *price_local_var = NULL;

    char *instrument_key_local_str = NULL;

    // us_order_estimate_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(us_order_estimate_requestJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (!quantity) {
        goto end;
    }

    
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

    // us_order_estimate_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(us_order_estimate_requestJSON, "price");
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

    // us_order_estimate_request->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(us_order_estimate_requestJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (!instrument_key) {
        goto end;
    }

    
    if(!cJSON_IsString(instrument_key))
    {
    goto end; //String
    }

    // us_order_estimate_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(us_order_estimate_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = us_order_estimate_request_transaction_type_FromString(transaction_type->valuestring);

    // us_order_estimate_request->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(us_order_estimate_requestJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    if (!order_type) {
        goto end;
    }

    upstox_client_us_order_estimate_request_ORDERTYPE_e order_typeVariable;
    
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = us_order_estimate_request_order_type_FromString(order_type->valuestring);


    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);

    us_order_estimate_request_local_var = us_order_estimate_request_create_internal (
        quantity_local_var,
        price_local_var,
        instrument_key_local_str,
        transaction_typeVariable,
        order_typeVariable
        );

    if (!us_order_estimate_request_local_var) {
        goto end;
    }

    return us_order_estimate_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    return NULL;

}
