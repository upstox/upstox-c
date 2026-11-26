#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_request.h"


char* multi_order_request_product_ToString(upstox_client_multi_order_request_PRODUCT_e product) {
    char* productArray[] =  { "NULL", "I", "D" };
    return productArray[product];
}

upstox_client_multi_order_request_PRODUCT_e multi_order_request_product_FromString(char* product){
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
char* multi_order_request_validity_ToString(upstox_client_multi_order_request_VALIDITY_e validity) {
    char* validityArray[] =  { "NULL", "DAY", "IOC" };
    return validityArray[validity];
}

upstox_client_multi_order_request_VALIDITY_e multi_order_request_validity_FromString(char* validity){
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
char* multi_order_request_order_type_ToString(upstox_client_multi_order_request_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typeArray[order_type];
}

upstox_client_multi_order_request_ORDERTYPE_e multi_order_request_order_type_FromString(char* order_type){
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
char* multi_order_request_transaction_type_ToString(upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_multi_order_request_TRANSACTIONTYPE_e multi_order_request_transaction_type_FromString(char* transaction_type){
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

static multi_order_request_t *multi_order_request_create_internal(
    int *quantity,
    upstox_client_multi_order_request_PRODUCT_e product,
    upstox_client_multi_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    int *slice,
    char *instrument_token,
    upstox_client_multi_order_request_ORDERTYPE_e order_type,
    upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo,
    char *correlation_id,
    double *market_protection
    ) {
    multi_order_request_t *multi_order_request_local_var = malloc(sizeof(multi_order_request_t));
    if (!multi_order_request_local_var) {
        return NULL;
    }
    memset(multi_order_request_local_var, 0, sizeof(multi_order_request_t));
    multi_order_request_local_var->_library_owned = 1;
    multi_order_request_local_var->quantity = quantity;
    multi_order_request_local_var->product = product;
    multi_order_request_local_var->validity = validity;
    multi_order_request_local_var->price = price;
    multi_order_request_local_var->tag = tag;
    multi_order_request_local_var->slice = slice;
    multi_order_request_local_var->instrument_token = instrument_token;
    multi_order_request_local_var->order_type = order_type;
    multi_order_request_local_var->transaction_type = transaction_type;
    multi_order_request_local_var->disclosed_quantity = disclosed_quantity;
    multi_order_request_local_var->trigger_price = trigger_price;
    multi_order_request_local_var->is_amo = is_amo;
    multi_order_request_local_var->correlation_id = correlation_id;
    multi_order_request_local_var->market_protection = market_protection;
    return multi_order_request_local_var;
}

multi_order_request_t *multi_order_request_create(
    int *quantity,
    upstox_client_multi_order_request_PRODUCT_e product,
    upstox_client_multi_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    int *slice,
    char *instrument_token,
    upstox_client_multi_order_request_ORDERTYPE_e order_type,
    upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo,
    char *correlation_id,
    double *market_protection
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
    int *slice_copy = NULL;
    if (slice) {
        slice_copy = malloc(sizeof(int));
        if (slice_copy) *slice_copy = *slice;
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
    double *market_protection_copy = NULL;
    if (market_protection) {
        market_protection_copy = malloc(sizeof(double));
        if (market_protection_copy) *market_protection_copy = *market_protection;
    }
    multi_order_request_t *result = multi_order_request_create_internal (
        quantity_copy,
        product,
        validity,
        price_copy,
        tag,
        slice_copy,
        instrument_token,
        order_type,
        transaction_type,
        disclosed_quantity_copy,
        trigger_price_copy,
        is_amo_copy,
        correlation_id,
        market_protection_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
        free(slice_copy);
        free(disclosed_quantity_copy);
        free(trigger_price_copy);
        free(is_amo_copy);
        free(market_protection_copy);
    }
    return result;
}

void multi_order_request_free(multi_order_request_t *multi_order_request) {
    if(NULL == multi_order_request){
        return ;
    }
    if(multi_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_request->quantity) {
        free(multi_order_request->quantity);
        multi_order_request->quantity = NULL;
    }
    if (multi_order_request->price) {
        free(multi_order_request->price);
        multi_order_request->price = NULL;
    }
    if (multi_order_request->tag) {
        free(multi_order_request->tag);
        multi_order_request->tag = NULL;
    }
    if (multi_order_request->slice) {
        free(multi_order_request->slice);
        multi_order_request->slice = NULL;
    }
    if (multi_order_request->instrument_token) {
        free(multi_order_request->instrument_token);
        multi_order_request->instrument_token = NULL;
    }
    if (multi_order_request->disclosed_quantity) {
        free(multi_order_request->disclosed_quantity);
        multi_order_request->disclosed_quantity = NULL;
    }
    if (multi_order_request->trigger_price) {
        free(multi_order_request->trigger_price);
        multi_order_request->trigger_price = NULL;
    }
    if (multi_order_request->is_amo) {
        free(multi_order_request->is_amo);
        multi_order_request->is_amo = NULL;
    }
    if (multi_order_request->correlation_id) {
        free(multi_order_request->correlation_id);
        multi_order_request->correlation_id = NULL;
    }
    if (multi_order_request->market_protection) {
        free(multi_order_request->market_protection);
        multi_order_request->market_protection = NULL;
    }
    free(multi_order_request);
}

cJSON *multi_order_request_convertToJSON(multi_order_request_t *multi_order_request) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_request->quantity
    if (!multi_order_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *multi_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // multi_order_request->product
    if (upstox_client_multi_order_request_PRODUCT_NULL == multi_order_request->product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product", multi_order_request_product_ToString(multi_order_request->product)) == NULL)
    {
    goto fail; //Enum
    }


    // multi_order_request->validity
    if (upstox_client_multi_order_request_VALIDITY_NULL == multi_order_request->validity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "validity", multi_order_request_validity_ToString(multi_order_request->validity)) == NULL)
    {
    goto fail; //Enum
    }


    // multi_order_request->price
    if (!multi_order_request->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *multi_order_request->price) == NULL) {
    goto fail; //Numeric
    }


    // multi_order_request->tag
    if(multi_order_request->tag) {
    if(cJSON_AddStringToObject(item, "tag", multi_order_request->tag) == NULL) {
    goto fail; //String
    }
    }


    // multi_order_request->slice
    if (!multi_order_request->slice) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "slice", *multi_order_request->slice) == NULL) {
    goto fail; //Bool
    }


    // multi_order_request->instrument_token
    if (!multi_order_request->instrument_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_token", multi_order_request->instrument_token) == NULL) {
    goto fail; //String
    }


    // multi_order_request->order_type
    if (upstox_client_multi_order_request_ORDERTYPE_NULL == multi_order_request->order_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_type", multi_order_request_order_type_ToString(multi_order_request->order_type)) == NULL)
    {
    goto fail; //Enum
    }


    // multi_order_request->transaction_type
    if (upstox_client_multi_order_request_TRANSACTIONTYPE_NULL == multi_order_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", multi_order_request_transaction_type_ToString(multi_order_request->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // multi_order_request->disclosed_quantity
    if (!multi_order_request->disclosed_quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "disclosed_quantity", *multi_order_request->disclosed_quantity) == NULL) {
    goto fail; //Numeric
    }


    // multi_order_request->trigger_price
    if (!multi_order_request->trigger_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trigger_price", *multi_order_request->trigger_price) == NULL) {
    goto fail; //Numeric
    }


    // multi_order_request->is_amo
    if (!multi_order_request->is_amo) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "is_amo", *multi_order_request->is_amo) == NULL) {
    goto fail; //Bool
    }


    // multi_order_request->correlation_id
    if (!multi_order_request->correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "correlation_id", multi_order_request->correlation_id) == NULL) {
    goto fail; //String
    }


    // multi_order_request->market_protection
    if(multi_order_request->market_protection) {
    if(cJSON_AddNumberToObject(item, "market_protection", *multi_order_request->market_protection) == NULL) {
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

multi_order_request_t *multi_order_request_parseFromJSON(cJSON *multi_order_requestJSON){

    multi_order_request_t *multi_order_request_local_var = NULL;

    // define the local variable for multi_order_request->quantity
    int *quantity_local_var = NULL;

    // define the local variable for multi_order_request->price
    double *price_local_var = NULL;

    char *tag_local_str = NULL;

    // define the local variable for multi_order_request->slice
    int *slice_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for multi_order_request->disclosed_quantity
    int *disclosed_quantity_local_var = NULL;

    // define the local variable for multi_order_request->trigger_price
    double *trigger_price_local_var = NULL;

    // define the local variable for multi_order_request->is_amo
    int *is_amo_local_var = NULL;

    char *correlation_id_local_str = NULL;

    // define the local variable for multi_order_request->market_protection
    double *market_protection_local_var = NULL;

    // multi_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "quantity");
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

    // multi_order_request->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (!product) {
        goto end;
    }

    upstox_client_multi_order_request_PRODUCT_e productVariable;
    
    if(!cJSON_IsString(product))
    {
    goto end; //Enum
    }
    productVariable = multi_order_request_product_FromString(product->valuestring);

    // multi_order_request->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    if (!validity) {
        goto end;
    }

    upstox_client_multi_order_request_VALIDITY_e validityVariable;
    
    if(!cJSON_IsString(validity))
    {
    goto end; //Enum
    }
    validityVariable = multi_order_request_validity_FromString(validity->valuestring);

    // multi_order_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "price");
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

    // multi_order_request->tag
    cJSON *tag = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "tag");
    if (cJSON_IsNull(tag)) {
        tag = NULL;
    }
    if (tag) { 
    if(!cJSON_IsString(tag) && !cJSON_IsNull(tag))
    {
    goto end; //String
    }
    }

    // multi_order_request->slice
    cJSON *slice = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "slice");
    if (cJSON_IsNull(slice)) {
        slice = NULL;
    }
    if (!slice) {
        goto end;
    }

    
    if(!cJSON_IsBool(slice))
    {
    goto end; //Bool
    }
    slice_local_var = malloc(sizeof(int));
    if(!slice_local_var)
    {
        goto end;
    }
    *slice_local_var = slice->valueint;

    // multi_order_request->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "instrument_token");
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

    // multi_order_request->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    if (!order_type) {
        goto end;
    }

    upstox_client_multi_order_request_ORDERTYPE_e order_typeVariable;
    
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = multi_order_request_order_type_FromString(order_type->valuestring);

    // multi_order_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = multi_order_request_transaction_type_FromString(transaction_type->valuestring);

    // multi_order_request->disclosed_quantity
    cJSON *disclosed_quantity = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "disclosed_quantity");
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

    // multi_order_request->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "trigger_price");
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

    // multi_order_request->is_amo
    cJSON *is_amo = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "is_amo");
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

    // multi_order_request->correlation_id
    cJSON *correlation_id = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "correlation_id");
    if (cJSON_IsNull(correlation_id)) {
        correlation_id = NULL;
    }
    if (!correlation_id) {
        goto end;
    }

    
    if(!cJSON_IsString(correlation_id))
    {
    goto end; //String
    }

    // multi_order_request->market_protection
    cJSON *market_protection = cJSON_GetObjectItemCaseSensitive(multi_order_requestJSON, "market_protection");
    if (cJSON_IsNull(market_protection)) {
        market_protection = NULL;
    }
    if (market_protection) { 
    if(!cJSON_IsNumber(market_protection))
    {
    goto end; //Numeric
    }
    market_protection_local_var = malloc(sizeof(double));
    if(!market_protection_local_var)
    {
        goto end;
    }
    *market_protection_local_var = market_protection->valuedouble;
    }


    if (tag && !cJSON_IsNull(tag)) tag_local_str = strdup(tag->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (correlation_id && !cJSON_IsNull(correlation_id)) correlation_id_local_str = strdup(correlation_id->valuestring);

    multi_order_request_local_var = multi_order_request_create_internal (
        quantity_local_var,
        productVariable,
        validityVariable,
        price_local_var,
        tag_local_str,
        slice_local_var,
        instrument_token_local_str,
        order_typeVariable,
        transaction_typeVariable,
        disclosed_quantity_local_var,
        trigger_price_local_var,
        is_amo_local_var,
        correlation_id_local_str,
        market_protection_local_var
        );

    if (!multi_order_request_local_var) {
        goto end;
    }

    return multi_order_request_local_var;
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
    if (slice_local_var) {
        free(slice_local_var);
        slice_local_var = NULL;
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
    if (correlation_id_local_str) {
        free(correlation_id_local_str);
        correlation_id_local_str = NULL;
    }
    if (market_protection_local_var) {
        free(market_protection_local_var);
        market_protection_local_var = NULL;
    }
    return NULL;

}
