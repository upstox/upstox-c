#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instrument.h"



static instrument_t *instrument_create_internal(
    char *instrument_key,
    int *quantity,
    char *product,
    char *transaction_type,
    double *price
    ) {
    instrument_t *instrument_local_var = malloc(sizeof(instrument_t));
    if (!instrument_local_var) {
        return NULL;
    }
    memset(instrument_local_var, 0, sizeof(instrument_t));
    instrument_local_var->_library_owned = 1;
    instrument_local_var->instrument_key = instrument_key;
    instrument_local_var->quantity = quantity;
    instrument_local_var->product = product;
    instrument_local_var->transaction_type = transaction_type;
    instrument_local_var->price = price;
    return instrument_local_var;
}

instrument_t *instrument_create(
    char *instrument_key,
    int *quantity,
    char *product,
    char *transaction_type,
    double *price
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
    instrument_t *result = instrument_create_internal (
        instrument_key,
        quantity_copy,
        product,
        transaction_type,
        price_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
    }
    return result;
}

void instrument_free(instrument_t *instrument) {
    if(NULL == instrument){
        return ;
    }
    if(instrument->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instrument_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instrument->instrument_key) {
        free(instrument->instrument_key);
        instrument->instrument_key = NULL;
    }
    if (instrument->quantity) {
        free(instrument->quantity);
        instrument->quantity = NULL;
    }
    if (instrument->product) {
        free(instrument->product);
        instrument->product = NULL;
    }
    if (instrument->transaction_type) {
        free(instrument->transaction_type);
        instrument->transaction_type = NULL;
    }
    if (instrument->price) {
        free(instrument->price);
        instrument->price = NULL;
    }
    free(instrument);
}

cJSON *instrument_convertToJSON(instrument_t *instrument) {
    cJSON *item = cJSON_CreateObject();

    // instrument->instrument_key
    if (!instrument->instrument_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "instrument_key", instrument->instrument_key) == NULL) {
    goto fail; //String
    }


    // instrument->quantity
    if (!instrument->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *instrument->quantity) == NULL) {
    goto fail; //Numeric
    }


    // instrument->product
    if (!instrument->product) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "product", instrument->product) == NULL) {
    goto fail; //String
    }


    // instrument->transaction_type
    if (!instrument->transaction_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "transaction_type", instrument->transaction_type) == NULL) {
    goto fail; //String
    }


    // instrument->price
    if(instrument->price) {
    if(cJSON_AddNumberToObject(item, "price", *instrument->price) == NULL) {
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

instrument_t *instrument_parseFromJSON(cJSON *instrumentJSON){

    instrument_t *instrument_local_var = NULL;

    char *instrument_key_local_str = NULL;

    // define the local variable for instrument->quantity
    int *quantity_local_var = NULL;

    char *product_local_str = NULL;

    char *transaction_type_local_str = NULL;

    // define the local variable for instrument->price
    double *price_local_var = NULL;

    // instrument->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(instrumentJSON, "instrument_key");
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

    // instrument->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(instrumentJSON, "quantity");
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

    // instrument->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(instrumentJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (!product) {
        goto end;
    }

    
    if(!cJSON_IsString(product))
    {
    goto end; //String
    }

    // instrument->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(instrumentJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (!transaction_type) {
        goto end;
    }

    
    if(!cJSON_IsString(transaction_type))
    {
    goto end; //String
    }

    // instrument->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(instrumentJSON, "price");
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


    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (product && !cJSON_IsNull(product)) product_local_str = strdup(product->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);

    instrument_local_var = instrument_create_internal (
        instrument_key_local_str,
        quantity_local_var,
        product_local_str,
        transaction_type_local_str,
        price_local_var
        );

    if (!instrument_local_var) {
        goto end;
    }

    return instrument_local_var;
end:
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (product_local_str) {
        free(product_local_str);
        product_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    return NULL;

}
