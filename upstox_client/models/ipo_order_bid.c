#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_order_bid.h"



static ipo_order_bid_t *ipo_order_bid_create_internal(
    int *quantity,
    double *price,
    double *amount,
    char *message
    ) {
    ipo_order_bid_t *ipo_order_bid_local_var = malloc(sizeof(ipo_order_bid_t));
    if (!ipo_order_bid_local_var) {
        return NULL;
    }
    memset(ipo_order_bid_local_var, 0, sizeof(ipo_order_bid_t));
    ipo_order_bid_local_var->_library_owned = 1;
    ipo_order_bid_local_var->quantity = quantity;
    ipo_order_bid_local_var->price = price;
    ipo_order_bid_local_var->amount = amount;
    ipo_order_bid_local_var->message = message;
    return ipo_order_bid_local_var;
}

ipo_order_bid_t *ipo_order_bid_create(
    int *quantity,
    double *price,
    double *amount,
    char *message
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
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    ipo_order_bid_t *result = ipo_order_bid_create_internal (
        quantity_copy,
        price_copy,
        amount_copy,
        message
        );
    if (!result) {
        free(quantity_copy);
        free(price_copy);
        free(amount_copy);
    }
    return result;
}

void ipo_order_bid_free(ipo_order_bid_t *ipo_order_bid) {
    if(NULL == ipo_order_bid){
        return ;
    }
    if(ipo_order_bid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_order_bid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_order_bid->quantity) {
        free(ipo_order_bid->quantity);
        ipo_order_bid->quantity = NULL;
    }
    if (ipo_order_bid->price) {
        free(ipo_order_bid->price);
        ipo_order_bid->price = NULL;
    }
    if (ipo_order_bid->amount) {
        free(ipo_order_bid->amount);
        ipo_order_bid->amount = NULL;
    }
    if (ipo_order_bid->message) {
        free(ipo_order_bid->message);
        ipo_order_bid->message = NULL;
    }
    free(ipo_order_bid);
}

cJSON *ipo_order_bid_convertToJSON(ipo_order_bid_t *ipo_order_bid) {
    cJSON *item = cJSON_CreateObject();

    // ipo_order_bid->quantity
    if(ipo_order_bid->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *ipo_order_bid->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_order_bid->price
    if(ipo_order_bid->price) {
    if(cJSON_AddNumberToObject(item, "price", *ipo_order_bid->price) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_order_bid->amount
    if(ipo_order_bid->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *ipo_order_bid->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // ipo_order_bid->message
    if(ipo_order_bid->message) {
    if(cJSON_AddStringToObject(item, "message", ipo_order_bid->message) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_order_bid_t *ipo_order_bid_parseFromJSON(cJSON *ipo_order_bidJSON){

    ipo_order_bid_t *ipo_order_bid_local_var = NULL;

    // define the local variable for ipo_order_bid->quantity
    int *quantity_local_var = NULL;

    // define the local variable for ipo_order_bid->price
    double *price_local_var = NULL;

    // define the local variable for ipo_order_bid->amount
    double *amount_local_var = NULL;

    char *message_local_str = NULL;

    // ipo_order_bid->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(ipo_order_bidJSON, "quantity");
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

    // ipo_order_bid->price
    cJSON *price = cJSON_GetObjectItemCaseSensitive(ipo_order_bidJSON, "price");
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

    // ipo_order_bid->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(ipo_order_bidJSON, "amount");
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

    // ipo_order_bid->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(ipo_order_bidJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);

    ipo_order_bid_local_var = ipo_order_bid_create_internal (
        quantity_local_var,
        price_local_var,
        amount_local_var,
        message_local_str
        );

    if (!ipo_order_bid_local_var) {
        goto end;
    }

    return ipo_order_bid_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (price_local_var) {
        free(price_local_var);
        price_local_var = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    return NULL;

}
