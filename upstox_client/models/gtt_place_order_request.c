#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_place_order_request.h"


char* gtt_place_order_request_type_ToString(upstox_client_gtt_place_order_request_TYPE_e type) {
    char* typeArray[] =  { "NULL", "SINGLE", "MULTIPLE" };
    return typeArray[type];
}

upstox_client_gtt_place_order_request_TYPE_e gtt_place_order_request_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "SINGLE", "MULTIPLE" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* gtt_place_order_request_product_ToString(upstox_client_gtt_place_order_request_PRODUCT_e product) {
    char* productArray[] =  { "NULL", "I", "D", "MTF" };
    return productArray[product];
}

upstox_client_gtt_place_order_request_PRODUCT_e gtt_place_order_request_product_FromString(char* product){
    int stringToReturn = 0;
    char *productArray[] =  { "NULL", "I", "D", "MTF" };
    size_t sizeofArray = sizeof(productArray) / sizeof(productArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(product, productArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* gtt_place_order_request_transaction_type_ToString(upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e gtt_place_order_request_transaction_type_FromString(char* transaction_type){
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

static gtt_place_order_request_t *gtt_place_order_request_create_internal(
    upstox_client_gtt_place_order_request_TYPE_e type,
    int *quantity,
    upstox_client_gtt_place_order_request_PRODUCT_e product,
    list_t *rules,
    char *instrument_token,
    upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type
    ) {
    gtt_place_order_request_t *gtt_place_order_request_local_var = malloc(sizeof(gtt_place_order_request_t));
    if (!gtt_place_order_request_local_var) {
        return NULL;
    }
    memset(gtt_place_order_request_local_var, 0, sizeof(gtt_place_order_request_t));
    gtt_place_order_request_local_var->_library_owned = 1;
    gtt_place_order_request_local_var->type = type;
    gtt_place_order_request_local_var->quantity = quantity;
    gtt_place_order_request_local_var->product = product;
    gtt_place_order_request_local_var->rules = rules;
    gtt_place_order_request_local_var->instrument_token = instrument_token;
    gtt_place_order_request_local_var->transaction_type = transaction_type;
    return gtt_place_order_request_local_var;
}

gtt_place_order_request_t *gtt_place_order_request_create(
    upstox_client_gtt_place_order_request_TYPE_e type,
    int *quantity,
    upstox_client_gtt_place_order_request_PRODUCT_e product,
    list_t *rules,
    char *instrument_token,
    upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    gtt_place_order_request_t *result = gtt_place_order_request_create_internal (
        type,
        quantity_copy,
        product,
        rules,
        instrument_token,
        transaction_type
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void gtt_place_order_request_free(gtt_place_order_request_t *gtt_place_order_request) {
    if(NULL == gtt_place_order_request){
        return ;
    }
    if(gtt_place_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_place_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_place_order_request->quantity) {
        free(gtt_place_order_request->quantity);
        gtt_place_order_request->quantity = NULL;
    }
    if (gtt_place_order_request->rules) {
        list_ForEach(listEntry, gtt_place_order_request->rules) {
            gtt_rule_free(listEntry->data);
        }
        list_freeList(gtt_place_order_request->rules);
        gtt_place_order_request->rules = NULL;
    }
    if (gtt_place_order_request->instrument_token) {
        free(gtt_place_order_request->instrument_token);
        gtt_place_order_request->instrument_token = NULL;
    }
    free(gtt_place_order_request);
}

cJSON *gtt_place_order_request_convertToJSON(gtt_place_order_request_t *gtt_place_order_request) {
    cJSON *item = cJSON_CreateObject();

    // gtt_place_order_request->type
    if (upstox_client_gtt_place_order_request_TYPE_NULL == gtt_place_order_request->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", gtt_place_order_request_type_ToString(gtt_place_order_request->type)) == NULL)
    {
    goto fail; //Enum
    }


    // gtt_place_order_request->quantity
    if (!gtt_place_order_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *gtt_place_order_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // gtt_place_order_request->product
    if (upstox_client_gtt_place_order_request_PRODUCT_NULL == gtt_place_order_request->product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product", gtt_place_order_request_product_ToString(gtt_place_order_request->product)) == NULL)
    {
    goto fail; //Enum
    }


    // gtt_place_order_request->rules
    if (!gtt_place_order_request->rules) {
        goto fail;
    }
    cJSON *rules = cJSON_AddArrayToObject(item, "rules");
    if(rules == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *rulesListEntry;
    if (gtt_place_order_request->rules) {
    list_ForEach(rulesListEntry, gtt_place_order_request->rules) {
    cJSON *itemLocal = gtt_rule_convertToJSON(rulesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(rules, itemLocal);
    }
    }


    // gtt_place_order_request->instrument_token
    if (!gtt_place_order_request->instrument_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_token", gtt_place_order_request->instrument_token) == NULL) {
    goto fail; //String
    }


    // gtt_place_order_request->transaction_type
    if (upstox_client_gtt_place_order_request_TRANSACTIONTYPE_NULL == gtt_place_order_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", gtt_place_order_request_transaction_type_ToString(gtt_place_order_request->transaction_type)) == NULL)
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

gtt_place_order_request_t *gtt_place_order_request_parseFromJSON(cJSON *gtt_place_order_requestJSON){

    gtt_place_order_request_t *gtt_place_order_request_local_var = NULL;

    // define the local variable for gtt_place_order_request->quantity
    int *quantity_local_var = NULL;

    // define the local list for gtt_place_order_request->rules
    list_t *rulesList = NULL;

    char *instrument_token_local_str = NULL;

    // gtt_place_order_request->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    upstox_client_gtt_place_order_request_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = gtt_place_order_request_type_FromString(type->valuestring);

    // gtt_place_order_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "quantity");
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

    // gtt_place_order_request->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (!product) {
        goto end;
    }

    upstox_client_gtt_place_order_request_PRODUCT_e productVariable;
    
    if(!cJSON_IsString(product))
    {
    goto end; //Enum
    }
    productVariable = gtt_place_order_request_product_FromString(product->valuestring);

    // gtt_place_order_request->rules
    cJSON *rules = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "rules");
    if (cJSON_IsNull(rules)) {
        rules = NULL;
    }
    if (!rules) {
        goto end;
    }

    
    cJSON *rules_local_nonprimitive = NULL;
    if(!cJSON_IsArray(rules)){
        goto end; //nonprimitive container
    }

    rulesList = list_createList();

    cJSON_ArrayForEach(rules_local_nonprimitive,rules )
    {
        if(!cJSON_IsObject(rules_local_nonprimitive)){
            goto end;
        }
        gtt_rule_t *rulesItem = gtt_rule_parseFromJSON(rules_local_nonprimitive);

        list_addElement(rulesList, rulesItem);
    }

    // gtt_place_order_request->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "instrument_token");
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

    // gtt_place_order_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(gtt_place_order_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = gtt_place_order_request_transaction_type_FromString(transaction_type->valuestring);


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    gtt_place_order_request_local_var = gtt_place_order_request_create_internal (
        typeVariable,
        quantity_local_var,
        productVariable,
        rulesList,
        instrument_token_local_str,
        transaction_typeVariable
        );

    if (!gtt_place_order_request_local_var) {
        goto end;
    }

    return gtt_place_order_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (rulesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, rulesList) {
            gtt_rule_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(rulesList);
        rulesList = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    return NULL;

}
