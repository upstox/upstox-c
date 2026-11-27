#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_order_request.h"


char* place_order_request_product_ToString(upstox_client_place_order_request_PRODUCT_e product) {
    char* productArray[] =  { "NULL", "I", "D" };
    return productArray[product];
}

upstox_client_place_order_request_PRODUCT_e place_order_request_product_FromString(char* product){
    int stringToReturn = 0;
    char *productArray[] =  { "NULL", "I", "D" };
    size_t sizeofArray = sizeof(productArray) / sizeof(productArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(product, productArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* place_order_request_validity_ToString(upstox_client_place_order_request_VALIDITY_e validity) {
    char* validityArray[] =  { "NULL", "DAY", "IOC" };
    return validityArray[validity];
}

upstox_client_place_order_request_VALIDITY_e place_order_request_validity_FromString(char* validity){
    int stringToReturn = 0;
    char *validityArray[] =  { "NULL", "DAY", "IOC" };
    size_t sizeofArray = sizeof(validityArray) / sizeof(validityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(validity, validityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* place_order_request_order_type_ToString(upstox_client_place_order_request_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typeArray[order_type];
}

upstox_client_place_order_request_ORDERTYPE_e place_order_request_order_type_FromString(char* order_type){
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
char* place_order_request_transaction_type_ToString(upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_place_order_request_TRANSACTIONTYPE_e place_order_request_transaction_type_FromString(char* transaction_type){
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

static place_order_request_t *place_order_request_create_internal(
    int *quantity,
    upstox_client_place_order_request_PRODUCT_e product,
    upstox_client_place_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    char *instrument_token,
    upstox_client_place_order_request_ORDERTYPE_e order_type,
    upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo
    ) {
    place_order_request_t *place_order_request_local_var = malloc(sizeof(place_order_request_t));
    if (!place_order_request_local_var) {
        return NULL;
    }
    memset(place_order_request_local_var, 0, sizeof(place_order_request_t));
    place_order_request_local_var->_library_owned = 1;
    place_order_request_local_var->quantity = quantity;
    place_order_request_local_var->product = product;
    place_order_request_local_var->validity = validity;
    place_order_request_local_var->price = price;
    place_order_request_local_var->tag = tag;
    place_order_request_local_var->instrument_token = instrument_token;
    place_order_request_local_var->order_type = order_type;
    place_order_request_local_var->transaction_type = transaction_type;
    place_order_request_local_var->disclosed_quantity = disclosed_quantity;
    place_order_request_local_var->trigger_price = trigger_price;
    place_order_request_local_var->is_amo = is_amo;
    return place_order_request_local_var;
}

place_order_request_t *place_order_request_create(
    int *quantity,
    upstox_client_place_order_request_PRODUCT_e product,
    upstox_client_place_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    char *instrument_token,
    upstox_client_place_order_request_ORDERTYPE_e order_type,
    upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *price_copy = NULL;
    if (price) {
        price_copy = malloc(sizeof(double));
        if (price_copy) *price_copy = *price;
    }
    int *disclosed_quantity_copy = NULL;
    if (disclosed_quantity) {
        disclosed_quantity_copy = malloc(sizeof(int));
        if (disclosed_quantity_copy) *disclosed_quantity_copy = *disclosed_quantity;
    }
    double *trigger_price_copy = NULL;
    if (trigger_price) {
        trigger_price_copy = malloc(sizeof(double));
        if (trigger_price_copy) *trigger_price_copy = *trigger_price;
    }
    int *is_amo_copy = NULL;
    if (is_amo) {
        is_amo_copy = malloc(sizeof(int));
        if (is_amo_copy) *is_amo_copy = *is_amo;
    }
    place_order_request_t *result = place_order_request_create_internal (
        quantity_copy,
        product,
        validity,
        price_copy,
        tag,
        instrument_token,
        order_type,
        transaction_type,
        disclosed_quantity_copy,
        trigger_price_copy,
        is_amo_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
        free(disclosed_quantity_copy);
        free(trigger_price_copy);
        free(is_amo_copy);
    }
    return result;
}

void place_order_request_free(place_order_request_t *place_order_request) {
    if(NULL == place_order_request){
        return ;
    }
    if(place_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "place_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (place_order_request->quantity) {
        free(place_order_request->quantity);
        place_order_request->quantity = NULL;
    }
    if (place_order_request->price) {
        free(place_order_request->price);
        place_order_request->price = NULL;
    }
    if (place_order_request->tag) {
        free(place_order_request->tag);
        place_order_request->tag = NULL;
    }
    if (place_order_request->instrument_token) {
        free(place_order_request->instrument_token);
        place_order_request->instrument_token = NULL;
    }
    if (place_order_request->disclosed_quantity) {
        free(place_order_request->disclosed_quantity);
        place_order_request->disclosed_quantity = NULL;
    }
    if (place_order_request->trigger_price) {
        free(place_order_request->trigger_price);
        place_order_request->trigger_price = NULL;
    }
    if (place_order_request->is_amo) {
        free(place_order_request->is_amo);
        place_order_request->is_amo = NULL;
    }
    free(place_order_request);
}

cJSON *place_order_request_convertToJSON(place_order_request_t *place_order_request) {
    cJSON *item = cJSON_CreateObject();

    // place_order_request->quantity
    if (!place_order_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *place_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // place_order_request->product
    if (upstox_client_place_order_request_PRODUCT_NULL == place_order_request->product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product", place_order_request_product_ToString(place_order_request->product)) == NULL)
    {
    goto fail; //Enum
    }


    // place_order_request->validity
    if (upstox_client_place_order_request_VALIDITY_NULL == place_order_request->validity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "validity", place_order_request_validity_ToString(place_order_request->validity)) == NULL)
    {
    goto fail; //Enum
    }


    // place_order_request->price
    if (!place_order_request->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *place_order_request->price) == NULL) {
    goto fail; //Numeric
    }


    // place_order_request->tag
    if(place_order_request->tag) {
    if(cJSON_AddStringToObject(item, "tag", place_order_request->tag) == NULL) {
    goto fail; //String
    }
    }


    // place_order_request->instrument_token
    if (!place_order_request->instrument_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_token", place_order_request->instrument_token) == NULL) {
    goto fail; //String
    }


    // place_order_request->order_type
    if (upstox_client_place_order_request_ORDERTYPE_NULL == place_order_request->order_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_type", place_order_request_order_type_ToString(place_order_request->order_type)) == NULL)
    {
    goto fail; //Enum
    }


    // place_order_request->transaction_type
    if (upstox_client_place_order_request_TRANSACTIONTYPE_NULL == place_order_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", place_order_request_transaction_type_ToString(place_order_request->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // place_order_request->disclosed_quantity
    if (!place_order_request->disclosed_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "disclosed_quantity", *place_order_request->disclosed_quantity) == NULL) {
    goto fail; //Numeric
    }


    // place_order_request->trigger_price
    if (!place_order_request->trigger_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trigger_price", *place_order_request->trigger_price) == NULL) {
    goto fail; //Numeric
    }


    // place_order_request->is_amo
    if (!place_order_request->is_amo) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_amo", *place_order_request->is_amo) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

place_order_request_t *place_order_request_parseFromJSON(cJSON *place_order_requestJSON){

    place_order_request_t *place_order_request_local_var = NULL;

    // define the local variable for place_order_request->quantity
    int *quantity_local_var = NULL;

    // define the local variable for place_order_request->price
    double *price_local_var = NULL;

    char *tag_local_str = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for place_order_request->disclosed_quantity
    int *disclosed_quantity_local_var = NULL;

    // define the local variable for place_order_request->trigger_price
    double *trigger_price_local_var = NULL;

    // define the local variable for place_order_request->is_amo
    int *is_amo_local_var = NULL;

    // place_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "quantity");
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
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;

    // place_order_request->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (!product) {
        goto end;
    }

    upstox_client_place_order_request_PRODUCT_e productVariable;
    
    if(!cJSON_IsString(product))
    {
    goto end; //Enum
    }
    productVariable = place_order_request_product_FromString(product->valuestring);

    // place_order_request->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    if (!validity) {
        goto end;
    }

    upstox_client_place_order_request_VALIDITY_e validityVariable;
    
    if(!cJSON_IsString(validity))
    {
    goto end; //Enum
    }
    validityVariable = place_order_request_validity_FromString(validity->valuestring);

    // place_order_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "price");
    if (cJSON_IsNull(price)) {
        price = NULL;
    }
    if (!price) {
        goto end;
    }

    
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

    // place_order_request->tag
    cJSON *tag = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "tag");
    if (cJSON_IsNull(tag)) {
        tag = NULL;
    }
    if (tag) { 
    if(!cJSON_IsString(tag) && !cJSON_IsNull(tag))
    {
    goto end; //String
    }
    }

    // place_order_request->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (!instrument_token) {
        goto end;
    }

    
    if(!cJSON_IsString(instrument_token))
    {
    goto end; //String
    }

    // place_order_request->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    if (!order_type) {
        goto end;
    }

    upstox_client_place_order_request_ORDERTYPE_e order_typeVariable;
    
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = place_order_request_order_type_FromString(order_type->valuestring);

    // place_order_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = place_order_request_transaction_type_FromString(transaction_type->valuestring);

    // place_order_request->disclosed_quantity
    cJSON *disclosed_quantity = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "disclosed_quantity");
    if (cJSON_IsNull(disclosed_quantity)) {
        disclosed_quantity = NULL;
    }
    if (!disclosed_quantity) {
        goto end;
    }

    
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

    // place_order_request->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "trigger_price");
    if (cJSON_IsNull(trigger_price)) {
        trigger_price = NULL;
    }
    if (!trigger_price) {
        goto end;
    }

    
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

    // place_order_request->is_amo
    cJSON *is_amo = cJSON_GetObjectItemCaseSensitive(place_order_requestJSON, "is_amo");
    if (cJSON_IsNull(is_amo)) {
        is_amo = NULL;
    }
    if (!is_amo) {
        goto end;
    }

    
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


    if (tag && !cJSON_IsNull(tag)) tag_local_str = strdup(tag->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    place_order_request_local_var = place_order_request_create_internal (
        quantity_local_var,
        productVariable,
        validityVariable,
        price_local_var,
        tag_local_str,
        instrument_token_local_str,
        order_typeVariable,
        transaction_typeVariable,
        disclosed_quantity_local_var,
        trigger_price_local_var,
        is_amo_local_var
        );

    if (!place_order_request_local_var) {
        goto end;
    }

    return place_order_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (tag_local_str) {
        free(tag_local_str);
        tag_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (disclosed_quantity_local_var) {
        free(disclosed_quantity_local_var);
        disclosed_quantity_local_var = NULL;
    }
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (is_amo_local_var) {
        free(is_amo_local_var);
        is_amo_local_var = NULL;
    }
    return NULL;

}
