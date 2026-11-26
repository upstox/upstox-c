#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_bid_request.h"



static ipo_bid_request_t *ipo_bid_request_create_internal(
    int *quantity,
    double *price
    ) {
    ipo_bid_request_t *ipo_bid_request_local_var = malloc(sizeof(ipo_bid_request_t));
    if (!ipo_bid_request_local_var) {
        return NULL;
    }
    memset(ipo_bid_request_local_var, 0, sizeof(ipo_bid_request_t));
    ipo_bid_request_local_var->_library_owned = 1;
    ipo_bid_request_local_var->quantity = quantity;
    ipo_bid_request_local_var->price = price;
    return ipo_bid_request_local_var;
}

ipo_bid_request_t *ipo_bid_request_create(
    int *quantity,
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
    ipo_bid_request_t *result = ipo_bid_request_create_internal (
        quantity_copy,
        price_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
    }
    return result;
}

void ipo_bid_request_free(ipo_bid_request_t *ipo_bid_request) {
    if(NULL == ipo_bid_request){
        return ;
    }
    if(ipo_bid_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_bid_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_bid_request->quantity) {
        free(ipo_bid_request->quantity);
        ipo_bid_request->quantity = NULL;
    }
    if (ipo_bid_request->price) {
        free(ipo_bid_request->price);
        ipo_bid_request->price = NULL;
    }
    free(ipo_bid_request);
}

cJSON *ipo_bid_request_convertToJSON(ipo_bid_request_t *ipo_bid_request) {
    cJSON *item = cJSON_CreateObject();

    // ipo_bid_request->quantity
    if (!ipo_bid_request->quantity) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "quantity", *ipo_bid_request->quantity) == NULL) {
    goto fail; //Numeric
    }


    // ipo_bid_request->price
    if (!ipo_bid_request->price) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "price", *ipo_bid_request->price) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_bid_request_t *ipo_bid_request_parseFromJSON(cJSON *ipo_bid_requestJSON){

    ipo_bid_request_t *ipo_bid_request_local_var = NULL;

    // define the local variable for ipo_bid_request->quantity
    int *quantity_local_var = NULL;

    // define the local variable for ipo_bid_request->price
    double *price_local_var = NULL;

    // ipo_bid_request->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(ipo_bid_requestJSON, "quantity");
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

    // ipo_bid_request->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(ipo_bid_requestJSON, "price");
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



    ipo_bid_request_local_var = ipo_bid_request_create_internal (
        quantity_local_var,
        price_local_var
        );

    if (!ipo_bid_request_local_var) {
        goto end;
    }

    return ipo_bid_request_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    return NULL;

}
