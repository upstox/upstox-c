#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_margin.h"



static delivery_margin_t *delivery_margin_create_internal(
    double *total,
    double *equity,
    double *fo_settlement
    ) {
    delivery_margin_t *delivery_margin_local_var = malloc(sizeof(delivery_margin_t));
    if (!delivery_margin_local_var) {
        return NULL;
    }
    memset(delivery_margin_local_var, 0, sizeof(delivery_margin_t));
    delivery_margin_local_var->_library_owned = 1;
    delivery_margin_local_var->total = total;
    delivery_margin_local_var->equity = equity;
    delivery_margin_local_var->fo_settlement = fo_settlement;
    return delivery_margin_local_var;
}

delivery_margin_t *delivery_margin_create(
    double *total,
    double *equity,
    double *fo_settlement
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    double *equity_copy = NULL;
    if (equity) {
        equity_copy = malloc(sizeof(double));
        if (equity_copy) *equity_copy = *equity;
    }
    double *fo_settlement_copy = NULL;
    if (fo_settlement) {
        fo_settlement_copy = malloc(sizeof(double));
        if (fo_settlement_copy) *fo_settlement_copy = *fo_settlement;
    }
    delivery_margin_t *result = delivery_margin_create_internal (
        total_copy,
        equity_copy,
        fo_settlement_copy
        );
    if (!result) {
        free(total_copy);
        free(equity_copy);
        free(fo_settlement_copy);
    }
    return result;
}

void delivery_margin_free(delivery_margin_t *delivery_margin) {
    if(NULL == delivery_margin){
        return ;
    }
    if(delivery_margin->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delivery_margin_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_margin->total) {
        free(delivery_margin->total);
        delivery_margin->total = NULL;
    }
    if (delivery_margin->equity) {
        free(delivery_margin->equity);
        delivery_margin->equity = NULL;
    }
    if (delivery_margin->fo_settlement) {
        free(delivery_margin->fo_settlement);
        delivery_margin->fo_settlement = NULL;
    }
    free(delivery_margin);
}

cJSON *delivery_margin_convertToJSON(delivery_margin_t *delivery_margin) {
    cJSON *item = cJSON_CreateObject();

    // delivery_margin->total
    if(delivery_margin->total) {
    if(cJSON_AddNumberToObject(item, "total", *delivery_margin->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // delivery_margin->equity
    if(delivery_margin->equity) {
    if(cJSON_AddNumberToObject(item, "equity", *delivery_margin->equity) == NULL) {
    goto fail; //Numeric
    }
    }


    // delivery_margin->fo_settlement
    if(delivery_margin->fo_settlement) {
    if(cJSON_AddNumberToObject(item, "fo_settlement", *delivery_margin->fo_settlement) == NULL) {
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

delivery_margin_t *delivery_margin_parseFromJSON(cJSON *delivery_marginJSON){

    delivery_margin_t *delivery_margin_local_var = NULL;

    // define the local variable for delivery_margin->total
    double *total_local_var = NULL;

    // define the local variable for delivery_margin->equity
    double *equity_local_var = NULL;

    // define the local variable for delivery_margin->fo_settlement
    double *fo_settlement_local_var = NULL;

    // delivery_margin->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(delivery_marginJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(double));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;
    }

    // delivery_margin->equity
    cJSON *equity = cJSON_GetObjectItemCaseSensitive(delivery_marginJSON, "equity");
    if (cJSON_IsNull(equity)) {
        equity = NULL;
    }
    if (equity) { 
    if(!cJSON_IsNumber(equity))
    {
    goto end; //Numeric
    }
    equity_local_var = malloc(sizeof(double));
    if(!equity_local_var)
    {
        goto end;
    }
    *equity_local_var = equity->valuedouble;
    }

    // delivery_margin->fo_settlement
    cJSON *fo_settlement = cJSON_GetObjectItemCaseSensitive(delivery_marginJSON, "fo_settlement");
    if (cJSON_IsNull(fo_settlement)) {
        fo_settlement = NULL;
    }
    if (fo_settlement) { 
    if(!cJSON_IsNumber(fo_settlement))
    {
    goto end; //Numeric
    }
    fo_settlement_local_var = malloc(sizeof(double));
    if(!fo_settlement_local_var)
    {
        goto end;
    }
    *fo_settlement_local_var = fo_settlement->valuedouble;
    }



    delivery_margin_local_var = delivery_margin_create_internal (
        total_local_var,
        equity_local_var,
        fo_settlement_local_var
        );

    if (!delivery_margin_local_var) {
        goto end;
    }

    return delivery_margin_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (equity_local_var) {
        free(equity_local_var);
        equity_local_var = NULL;
    }
    if (fo_settlement_local_var) {
        free(fo_settlement_local_var);
        fo_settlement_local_var = NULL;
    }
    return NULL;

}
