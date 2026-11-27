#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modify_order_request.h"


char* modify_order_request_validity_ToString(upstox_client_modify_order_request_VALIDITY_e validity) {
    char* validityArray[] =  { "NULL", "DAY", "IOC" };
    return validityArray[validity];
}

upstox_client_modify_order_request_VALIDITY_e modify_order_request_validity_FromString(char* validity){
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
char* modify_order_request_order_type_ToString(upstox_client_modify_order_request_ORDERTYPE_e order_type) {
    char* order_typeArray[] =  { "NULL", "MARKET", "LIMIT", "SL", "SL-M" };
    return order_typeArray[order_type];
}

upstox_client_modify_order_request_ORDERTYPE_e modify_order_request_order_type_FromString(char* order_type){
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

static modify_order_request_t *modify_order_request_create_internal(
    int *quantity,
    upstox_client_modify_order_request_VALIDITY_e validity,
    double *price,
    char *order_id,
    upstox_client_modify_order_request_ORDERTYPE_e order_type,
    int *disclosed_quantity,
    double *trigger_price,
    double *market_protection
    ) {
    modify_order_request_t *modify_order_request_local_var = malloc(sizeof(modify_order_request_t));
    if (!modify_order_request_local_var) {
        return NULL;
    }
    memset(modify_order_request_local_var, 0, sizeof(modify_order_request_t));
    modify_order_request_local_var->_library_owned = 1;
    modify_order_request_local_var->quantity = quantity;
    modify_order_request_local_var->validity = validity;
    modify_order_request_local_var->price = price;
    modify_order_request_local_var->order_id = order_id;
    modify_order_request_local_var->order_type = order_type;
    modify_order_request_local_var->disclosed_quantity = disclosed_quantity;
    modify_order_request_local_var->trigger_price = trigger_price;
    modify_order_request_local_var->market_protection = market_protection;
    return modify_order_request_local_var;
}

modify_order_request_t *modify_order_request_create(
    int *quantity,
    upstox_client_modify_order_request_VALIDITY_e validity,
    double *price,
    char *order_id,
    upstox_client_modify_order_request_ORDERTYPE_e order_type,
    int *disclosed_quantity,
    double *trigger_price,
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
    double *market_protection_copy = NULL;
    if (market_protection) {
        market_protection_copy = malloc(sizeof(double));
        if (market_protection_copy) *market_protection_copy = *market_protection;
    }
    modify_order_request_t *result = modify_order_request_create_internal (
        quantity_copy,
        validity,
        price_copy,
        order_id,
        order_type,
        disclosed_quantity_copy,
        trigger_price_copy,
        market_protection_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
        free(disclosed_quantity_copy);
        free(trigger_price_copy);
        free(market_protection_copy);
    }
    return result;
}

void modify_order_request_free(modify_order_request_t *modify_order_request) {
    if(NULL == modify_order_request){
        return ;
    }
    if(modify_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "modify_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (modify_order_request->quantity) {
        free(modify_order_request->quantity);
        modify_order_request->quantity = NULL;
    }
    if (modify_order_request->price) {
        free(modify_order_request->price);
        modify_order_request->price = NULL;
    }
    if (modify_order_request->order_id) {
        free(modify_order_request->order_id);
        modify_order_request->order_id = NULL;
    }
    if (modify_order_request->disclosed_quantity) {
        free(modify_order_request->disclosed_quantity);
        modify_order_request->disclosed_quantity = NULL;
    }
    if (modify_order_request->trigger_price) {
        free(modify_order_request->trigger_price);
        modify_order_request->trigger_price = NULL;
    }
    if (modify_order_request->market_protection) {
        free(modify_order_request->market_protection);
        modify_order_request->market_protection = NULL;
    }
    free(modify_order_request);
}

cJSON *modify_order_request_convertToJSON(modify_order_request_t *modify_order_request) {
    cJSON *item = cJSON_CreateObject();

    // modify_order_request->quantity
    if(modify_order_request->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *modify_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // modify_order_request->validity
    if (upstox_client_modify_order_request_VALIDITY_NULL == modify_order_request->validity) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "validity", modify_order_request_validity_ToString(modify_order_request->validity)) == NULL)
    {
    goto fail; //Enum
    }


    // modify_order_request->price
    if (!modify_order_request->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *modify_order_request->price) == NULL) {
    goto fail; //Numeric
    }


    // modify_order_request->order_id
    if (!modify_order_request->order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_id", modify_order_request->order_id) == NULL) {
    goto fail; //String
    }


    // modify_order_request->order_type
    if (upstox_client_modify_order_request_ORDERTYPE_NULL == modify_order_request->order_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "order_type", modify_order_request_order_type_ToString(modify_order_request->order_type)) == NULL)
    {
    goto fail; //Enum
    }


    // modify_order_request->disclosed_quantity
    if(modify_order_request->disclosed_quantity) {
    if(cJSON_AddNumberToObject(item, "disclosed_quantity", *modify_order_request->disclosed_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // modify_order_request->trigger_price
    if (!modify_order_request->trigger_price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trigger_price", *modify_order_request->trigger_price) == NULL) {
    goto fail; //Numeric
    }


    // modify_order_request->market_protection
    if(modify_order_request->market_protection) {
    if(cJSON_AddNumberToObject(item, "market_protection", *modify_order_request->market_protection) == NULL) {
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

modify_order_request_t *modify_order_request_parseFromJSON(cJSON *modify_order_requestJSON){

    modify_order_request_t *modify_order_request_local_var = NULL;

    // define the local variable for modify_order_request->quantity
    int *quantity_local_var = NULL;

    // define the local variable for modify_order_request->price
    double *price_local_var = NULL;

    char *order_id_local_str = NULL;

    // define the local variable for modify_order_request->disclosed_quantity
    int *disclosed_quantity_local_var = NULL;

    // define the local variable for modify_order_request->trigger_price
    double *trigger_price_local_var = NULL;

    // define the local variable for modify_order_request->market_protection
    double *market_protection_local_var = NULL;

    // modify_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "quantity");
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

    // modify_order_request->validity
    cJSON *validity = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "validity");
    if (cJSON_IsNull(validity)) {
        validity = NULL;
    }
    if (!validity) {
        goto end;
    }

    upstox_client_modify_order_request_VALIDITY_e validityVariable;
    
    if(!cJSON_IsString(validity))
    {
    goto end; //Enum
    }
    validityVariable = modify_order_request_validity_FromString(validity->valuestring);

    // modify_order_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "price");
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

    // modify_order_request->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (!order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(order_id))
    {
    goto end; //String
    }

    // modify_order_request->order_type
    cJSON *order_type = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "order_type");
    if (cJSON_IsNull(order_type)) {
        order_type = NULL;
    }
    if (!order_type) {
        goto end;
    }

    upstox_client_modify_order_request_ORDERTYPE_e order_typeVariable;
    
    if(!cJSON_IsString(order_type))
    {
    goto end; //Enum
    }
    order_typeVariable = modify_order_request_order_type_FromString(order_type->valuestring);

    // modify_order_request->disclosed_quantity
    cJSON *disclosed_quantity = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "disclosed_quantity");
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

    // modify_order_request->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "trigger_price");
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

    // modify_order_request->market_protection
    cJSON *market_protection = cJSON_GetObjectItemCaseSensitive(modify_order_requestJSON, "market_protection");
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


    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);

    modify_order_request_local_var = modify_order_request_create_internal (
        quantity_local_var,
        validityVariable,
        price_local_var,
        order_id_local_str,
        order_typeVariable,
        disclosed_quantity_local_var,
        trigger_price_local_var,
        market_protection_local_var
        );

    if (!modify_order_request_local_var) {
        goto end;
    }

    return modify_order_request_local_var;
end:
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
    if (disclosed_quantity_local_var) {
        free(disclosed_quantity_local_var);
        disclosed_quantity_local_var = NULL;
    }
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (market_protection_local_var) {
        free(market_protection_local_var);
        market_protection_local_var = NULL;
    }
    return NULL;

}
