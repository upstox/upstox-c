#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "depth.h"



static depth_t *depth_create_internal(
    int *quantity,
    double *price,
    int *orders
    ) {
    depth_t *depth_local_var = malloc(sizeof(depth_t));
    if (!depth_local_var) {
        return NULL;
    }
    memset(depth_local_var, 0, sizeof(depth_t));
    depth_local_var->_library_owned = 1;
    depth_local_var->quantity = quantity;
    depth_local_var->price = price;
    depth_local_var->orders = orders;
    return depth_local_var;
}

depth_t *depth_create(
    int *quantity,
    double *price,
    int *orders
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
    int *orders_copy = NULL;
    if (orders) {
        orders_copy = malloc(sizeof(int));
        if (orders_copy) *orders_copy = *orders;
    }
    depth_t *result = depth_create_internal (
        quantity_copy,
        price_copy,
        orders_copy
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
        free(orders_copy);
    }
    return result;
}

void depth_free(depth_t *depth) {
    if(NULL == depth){
        return ;
    }
    if(depth->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "depth_free");
        return ;
    }
    listEntry_t *listEntry;
    if (depth->quantity) {
        free(depth->quantity);
        depth->quantity = NULL;
    }
    if (depth->price) {
        free(depth->price);
        depth->price = NULL;
    }
    if (depth->orders) {
        free(depth->orders);
        depth->orders = NULL;
    }
    free(depth);
}

cJSON *depth_convertToJSON(depth_t *depth) {
    cJSON *item = cJSON_CreateObject();

    // depth->quantity
    if(depth->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *depth->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // depth->price
    if(depth->price) {
    if(cJSON_AddNumberToObject(item, "price", *depth->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // depth->orders
    if(depth->orders) {
    if(cJSON_AddNumberToObject(item, "orders", *depth->orders) == NULL) {
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

depth_t *depth_parseFromJSON(cJSON *depthJSON){

    depth_t *depth_local_var = NULL;

    // define the local variable for depth->quantity
    int *quantity_local_var = NULL;

    // define the local variable for depth->price
    double *price_local_var = NULL;

    // define the local variable for depth->orders
    int *orders_local_var = NULL;

    // depth->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(depthJSON, "quantity");
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

    // depth->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(depthJSON, "price");
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

    // depth->orders
    cJSON *orders = cJSON_GetObjectItemCaseSensitive(depthJSON, "orders");
    if (cJSON_IsNull(orders)) {
        orders = NULL;
    }
    if (orders) { 
    if(!cJSON_IsNumber(orders))
    {
    goto end; //Numeric
    }
    orders_local_var = malloc(sizeof(int));
    if(!orders_local_var)
    {
        goto end;
    }
    *orders_local_var = orders->valuedouble;
    }



    depth_local_var = depth_create_internal (
        quantity_local_var,
        price_local_var,
        orders_local_var
        );

    if (!depth_local_var) {
        goto end;
    }

    return depth_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (orders_local_var) {
        free(orders_local_var);
        orders_local_var = NULL;
    }
    return NULL;

}
