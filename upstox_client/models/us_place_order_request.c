#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_place_order_request.h"


char* us_place_order_request_validity_ToString(upstox_client_us_place_order_request_VALIDITY_e validity) {
    char* validityArray[] =  { "NULL", "DAY" };
    return validityArray[validity];
}

upstox_client_us_place_order_request_VALIDITY_e us_place_order_request_validity_FromString(char* validity){
    int stringToReturn = 0;
    char *validityArray[] =  { "NULL", "DAY" };
    size_t sizeofArray = sizeof(validityArray) / sizeof(validityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(validity, validityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* us_place_order_request_transaction_type_ToString(upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_us_place_order_request_TRANSACTIONTYPE_e us_place_order_request_transaction_type_FromString(char* transaction_type){
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
char* us_place_order_request_order_type_ToString(upstox_client_us_place_order_request_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT" };
    return order_typeArray[order_type];
}

upstox_client_us_place_order_request_ORDERTYPE_e us_place_order_request_order_type_FromString(char* order_type){
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

static us_place_order_request_t *us_place_order_request_create_internal(
    double *quantity,
    double *amount,
    double *price,
    upstox_client_us_place_order_request_VALIDITY_e validity,
    char *tag,
    char *instrument_key,
    upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_place_order_request_ORDERTYPE_e order_type
    ) {
    us_place_order_request_t *us_place_order_request_local_var = malloc(sizeof(us_place_order_request_t));
    if (!us_place_order_request_local_var) {
        return NULL;
    }
    memset(us_place_order_request_local_var, 0, sizeof(us_place_order_request_t));
    us_place_order_request_local_var->_library_owned = 1;
    us_place_order_request_local_var->quantity = quantity;
    us_place_order_request_local_var->amount = amount;
    us_place_order_request_local_var->price = price;
    us_place_order_request_local_var->validity = validity;
    us_place_order_request_local_var->tag = tag;
    us_place_order_request_local_var->instrument_key = instrument_key;
    us_place_order_request_local_var->transaction_type = transaction_type;
    us_place_order_request_local_var->order_type = order_type;
    return us_place_order_request_local_var;
}

us_place_order_request_t *us_place_order_request_create(
    double *quantity,
    double *amount,
    double *price,
    upstox_client_us_place_order_request_VALIDITY_e validity,
    char *tag,
    char *instrument_key,
    upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_place_order_request_ORDERTYPE_e order_type
    ) {
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
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    us_place_order_request_t *result = us_place_order_request_create_internal (
        quantity_copy,
        amount_copy,
        price_copy,
        validity,
        tag,
        instrument_key,
        transaction_type,
        order_type
        );
    if (!result) {
        free(quantity_copy);
        free(amount_copy);
        free(price_copy);
    }
    return result;
}

void us_place_order_request_free(us_place_order_request_t *us_place_order_request) {
    if(NULL == us_place_order_request){
        return ;
    }
    if(us_place_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_place_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_place_order_request->quantity) {
        free(us_place_order_request->quantity);
        us_place_order_request->quantity = NULL;
    }
    if (us_place_order_request->amount) {
        free(us_place_order_request->amount);
        us_place_order_request->amount = NULL;
    }
    if (us_place_order_request->price) {
        free(us_place_order_request->price);
        us_place_order_request->price = NULL;
    }
    if (us_place_order_request->tag) {
        free(us_place_order_request->tag);
        us_place_order_request->tag = NULL;
    }
    if (us_place_order_request->instrument_key) {
        free(us_place_order_request->instrument_key);
        us_place_order_request->instrument_key = NULL;
    }
    free(us_place_order_request);
}

cJSON *us_place_order_request_convertToJSON(us_place_order_request_t *us_place_order_request) {
    cJSON *item = cJSON_CreateObject();

    // us_place_order_request->quantity
    if(us_place_order_request->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *us_place_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_place_order_request->amount
    if(us_place_order_request->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *us_place_order_request->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_place_order_request->price
    if(us_place_order_request->price) {
    if(cJSON_AddNumberToObject(item, "price", *us_place_order_request->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_place_order_request->validity
    if (upstox_client_us_place_order_request_VALIDITY_NULL == us_place_order_request->validity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "validity", us_place_order_request_validity_ToString(us_place_order_request->validity)) == NULL)
    {
    goto fail; //Enum
    }


    // us_place_order_request->tag
    if(us_place_order_request->tag) {
    if(cJSON_AddStringToObject(item, "tag", us_place_order_request->tag) == NULL) {
    goto fail; //String
    }
    }


    // us_place_order_request->instrument_key
    if (!us_place_order_request->instrument_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_key", us_place_order_request->instrument_key) == NULL) {
    goto fail; //String
    }


    // us_place_order_request->transaction_type
    if (upstox_client_us_place_order_request_TRANSACTIONTYPE_NULL == us_place_order_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", us_place_order_request_transaction_type_ToString(us_place_order_request->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // us_place_order_request->order_type
    if (upstox_client_us_place_order_request_ORDERTYPE_NULL == us_place_order_request->order_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_type", us_place_order_request_order_type_ToString(us_place_order_request->order_type)) == NULL)
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

us_place_order_request_t *us_place_order_request_parseFromJSON(cJSON *us_place_order_requestJSON){

    us_place_order_request_t *us_place_order_request_local_var = NULL;

    // define the local variable for us_place_order_request->quantity
    double *quantity_local_var = NULL;

    // define the local variable for us_place_order_request->amount
    double *amount_local_var = NULL;

    // define the local variable for us_place_order_request->price
    double *price_local_var = NULL;

    char *tag_local_str = NULL;

    char *instrument_key_local_str = NULL;

    // us_place_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "quantity");
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

    // us_place_order_request->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "amount");
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

    // us_place_order_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "price");
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

    // us_place_order_request->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    if (!validity) {
        goto end;
    }

    upstox_client_us_place_order_request_VALIDITY_e validityVariable;
    
    if(!cJSON_IsString(validity))
    {
    goto end; //Enum
    }
    validityVariable = us_place_order_request_validity_FromString(validity->valuestring);

    // us_place_order_request->tag
    cJSON *tag = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "tag");
    if (cJSON_IsNull(tag)) {
        tag = NULL;
    }
    if (tag) { 
    if(!cJSON_IsString(tag) && !cJSON_IsNull(tag))
    {
    goto end; //String
    }
    }

    // us_place_order_request->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "instrument_key");
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

    // us_place_order_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = us_place_order_request_transaction_type_FromString(transaction_type->valuestring);

    // us_place_order_request->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(us_place_order_requestJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    if (!order_type) {
        goto end;
    }

    upstox_client_us_place_order_request_ORDERTYPE_e order_typeVariable;
    
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = us_place_order_request_order_type_FromString(order_type->valuestring);


    if (tag && !cJSON_IsNull(tag)) tag_local_str = strdup(tag->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);

    us_place_order_request_local_var = us_place_order_request_create_internal (
        quantity_local_var,
        amount_local_var,
        price_local_var,
        validityVariable,
        tag_local_str,
        instrument_key_local_str,
        transaction_typeVariable,
        order_typeVariable
        );

    if (!us_place_order_request_local_var) {
        goto end;
    }

    return us_place_order_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (tag_local_str) {
        free(tag_local_str);
        tag_local_str = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    return NULL;

}
