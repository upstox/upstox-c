#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_position_request.h"


char* convert_position_request_new_product_ToString(upstox_client_convert_position_request_NEWPRODUCT_e new_product) {
    char* new_productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return new_productArray[new_product];
}

upstox_client_convert_position_request_NEWPRODUCT_e convert_position_request_new_product_FromString(char* new_product){
    int stringToReturn = 0;
    char *new_productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    size_t sizeofArray = sizeof(new_productArray) / sizeof(new_productArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(new_product, new_productArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* convert_position_request_old_product_ToString(upstox_client_convert_position_request_OLDPRODUCT_e old_product) {
    char* old_productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    return old_productArray[old_product];
}

upstox_client_convert_position_request_OLDPRODUCT_e convert_position_request_old_product_FromString(char* old_product){
    int stringToReturn = 0;
    char *old_productArray[] =  { "NULL", "I", "D", "CO", "OCO", "MTF" };
    size_t sizeofArray = sizeof(old_productArray) / sizeof(old_productArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(old_product, old_productArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* convert_position_request_transaction_type_ToString(upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type) {
    char* transaction_typeArray[] =  { "NULL", "BUY", "SELL" };
    return transaction_typeArray[transaction_type];
}

upstox_client_convert_position_request_TRANSACTIONTYPE_e convert_position_request_transaction_type_FromString(char* transaction_type){
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

static convert_position_request_t *convert_position_request_create_internal(
    char *instrument_token,
    upstox_client_convert_position_request_NEWPRODUCT_e new_product,
    upstox_client_convert_position_request_OLDPRODUCT_e old_product,
    upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type,
    int *quantity
    ) {
    convert_position_request_t *convert_position_request_local_var = malloc(sizeof(convert_position_request_t));
    if (!convert_position_request_local_var) {
        return NULL;
    }
    memset(convert_position_request_local_var, 0, sizeof(convert_position_request_t));
    convert_position_request_local_var->_library_owned = 1;
    convert_position_request_local_var->instrument_token = instrument_token;
    convert_position_request_local_var->new_product = new_product;
    convert_position_request_local_var->old_product = old_product;
    convert_position_request_local_var->transaction_type = transaction_type;
    convert_position_request_local_var->quantity = quantity;
    return convert_position_request_local_var;
}

convert_position_request_t *convert_position_request_create(
    char *instrument_token,
    upstox_client_convert_position_request_NEWPRODUCT_e new_product,
    upstox_client_convert_position_request_OLDPRODUCT_e old_product,
    upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type,
    int *quantity
    ) {
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    convert_position_request_t *result = convert_position_request_create_internal (
        instrument_token,
        new_product,
        old_product,
        transaction_type,
        quantity_copy
        );
    if (!result) {
        free(quantity_copy);
    }
    return result;
}

void convert_position_request_free(convert_position_request_t *convert_position_request) {
    if(NULL == convert_position_request){
        return ;
    }
    if(convert_position_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_position_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (convert_position_request->instrument_token) {
        free(convert_position_request->instrument_token);
        convert_position_request->instrument_token = NULL;
    }
    if (convert_position_request->quantity) {
        free(convert_position_request->quantity);
        convert_position_request->quantity = NULL;
    }
    free(convert_position_request);
}

cJSON *convert_position_request_convertToJSON(convert_position_request_t *convert_position_request) {
    cJSON *item = cJSON_CreateObject();

    // convert_position_request->instrument_token
    if (!convert_position_request->instrument_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_token", convert_position_request->instrument_token) == NULL) {
    goto fail; //String
    }


    // convert_position_request->new_product
    if (upstox_client_convert_position_request_NEWPRODUCT_NULL == convert_position_request->new_product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "new_product", convert_position_request_new_product_ToString(convert_position_request->new_product)) == NULL)
    {
    goto fail; //Enum
    }


    // convert_position_request->old_product
    if (upstox_client_convert_position_request_OLDPRODUCT_NULL == convert_position_request->old_product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "old_product", convert_position_request_old_product_ToString(convert_position_request->old_product)) == NULL)
    {
    goto fail; //Enum
    }


    // convert_position_request->transaction_type
    if (upstox_client_convert_position_request_TRANSACTIONTYPE_NULL == convert_position_request->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", convert_position_request_transaction_type_ToString(convert_position_request->transaction_type)) == NULL)
    {
    goto fail; //Enum
    }


    // convert_position_request->quantity
    if (!convert_position_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *convert_position_request->quantity) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

convert_position_request_t *convert_position_request_parseFromJSON(cJSON *convert_position_requestJSON){

    convert_position_request_t *convert_position_request_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for convert_position_request->quantity
    int *quantity_local_var = NULL;

    // convert_position_request->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(convert_position_requestJSON, "instrument_token");
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

    // convert_position_request->new_product
    cJSON *new_product = cJSON_GetObjectItemCaseSensitive(convert_position_requestJSON, "new_product");
    if (cJSON_IsNull(new_product)) {
        new_product = NULL;
    }
    if (!new_product) {
        goto end;
    }

    upstox_client_convert_position_request_NEWPRODUCT_e new_productVariable;
    
    if(!cJSON_IsString(new_product))
    {
    goto end; //Enum
    }
    new_productVariable = convert_position_request_new_product_FromString(new_product->valuestring);

    // convert_position_request->old_product
    cJSON *old_product = cJSON_GetObjectItemCaseSensitive(convert_position_requestJSON, "old_product");
    if (cJSON_IsNull(old_product)) {
        old_product = NULL;
    }
    if (!old_product) {
        goto end;
    }

    upstox_client_convert_position_request_OLDPRODUCT_e old_productVariable;
    
    if(!cJSON_IsString(old_product))
    {
    goto end; //Enum
    }
    old_productVariable = convert_position_request_old_product_FromString(old_product->valuestring);

    // convert_position_request->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(convert_position_requestJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_typeVariable;
    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //Enum
    }
    transaction_typeVariable = convert_position_request_transaction_type_FromString(transaction_type->valuestring);

    // convert_position_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(convert_position_requestJSON, "quantity");
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


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    convert_position_request_local_var = convert_position_request_create_internal (
        instrument_token_local_str,
        new_productVariable,
        old_productVariable,
        transaction_typeVariable,
        quantity_local_var
        );

    if (!convert_position_request_local_var) {
        goto end;
    }

    return convert_position_request_local_var;
end:
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    return NULL;

}
