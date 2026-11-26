#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "available_to_trade.h"



static available_to_trade_t *available_to_trade_create_internal(
    double *total,
    cash_available_to_trade_t *cash_available_to_trade,
    pledge_available_to_trade_t *pledge_available_to_trade
    ) {
    available_to_trade_t *available_to_trade_local_var = malloc(sizeof(available_to_trade_t));
    if (!available_to_trade_local_var) {
        return NULL;
    }
    memset(available_to_trade_local_var, 0, sizeof(available_to_trade_t));
    available_to_trade_local_var->_library_owned = 1;
    available_to_trade_local_var->total = total;
    available_to_trade_local_var->cash_available_to_trade = cash_available_to_trade;
    available_to_trade_local_var->pledge_available_to_trade = pledge_available_to_trade;
    return available_to_trade_local_var;
}

available_to_trade_t *available_to_trade_create(
    double *total,
    cash_available_to_trade_t *cash_available_to_trade,
    pledge_available_to_trade_t *pledge_available_to_trade
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    available_to_trade_t *result = available_to_trade_create_internal (
        total_copy,
        cash_available_to_trade,
        pledge_available_to_trade
        );
    if (!result) {
        free(total_copy);
    }
    return result;
}

void available_to_trade_free(available_to_trade_t *available_to_trade) {
    if(NULL == available_to_trade){
        return ;
    }
    if(available_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "available_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (available_to_trade->total) {
        free(available_to_trade->total);
        available_to_trade->total = NULL;
    }
    if (available_to_trade->cash_available_to_trade) {
        cash_available_to_trade_free(available_to_trade->cash_available_to_trade);
        available_to_trade->cash_available_to_trade = NULL;
    }
    if (available_to_trade->pledge_available_to_trade) {
        pledge_available_to_trade_free(available_to_trade->pledge_available_to_trade);
        available_to_trade->pledge_available_to_trade = NULL;
    }
    free(available_to_trade);
}

cJSON *available_to_trade_convertToJSON(available_to_trade_t *available_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // available_to_trade->total
    if(available_to_trade->total) {
    if(cJSON_AddNumberToObject(item, "total", *available_to_trade->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // available_to_trade->cash_available_to_trade
    if(available_to_trade->cash_available_to_trade) {
    cJSON *cash_available_to_trade_local_JSON = cash_available_to_trade_convertToJSON(available_to_trade->cash_available_to_trade);
    if(cash_available_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cash_available_to_trade", cash_available_to_trade_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // available_to_trade->pledge_available_to_trade
    if(available_to_trade->pledge_available_to_trade) {
    cJSON *pledge_available_to_trade_local_JSON = pledge_available_to_trade_convertToJSON(available_to_trade->pledge_available_to_trade);
    if(pledge_available_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pledge_available_to_trade", pledge_available_to_trade_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

available_to_trade_t *available_to_trade_parseFromJSON(cJSON *available_to_tradeJSON){

    available_to_trade_t *available_to_trade_local_var = NULL;

    // define the local variable for available_to_trade->total
    double *total_local_var = NULL;

    // define the local variable for available_to_trade->cash_available_to_trade
    cash_available_to_trade_t *cash_available_to_trade_local_nonprim = NULL;

    // define the local variable for available_to_trade->pledge_available_to_trade
    pledge_available_to_trade_t *pledge_available_to_trade_local_nonprim = NULL;

    // available_to_trade->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(available_to_tradeJSON, "total");
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

    // available_to_trade->cash_available_to_trade
    cJSON *cash_available_to_trade = cJSON_GetObjectItemCaseSensitive(available_to_tradeJSON, "cash_available_to_trade");
    if (cJSON_IsNull(cash_available_to_trade)) {
        cash_available_to_trade = NULL;
    }
    if (cash_available_to_trade) { 
    cash_available_to_trade_local_nonprim = cash_available_to_trade_parseFromJSON(cash_available_to_trade); //nonprimitive
    }

    // available_to_trade->pledge_available_to_trade
    cJSON *pledge_available_to_trade = cJSON_GetObjectItemCaseSensitive(available_to_tradeJSON, "pledge_available_to_trade");
    if (cJSON_IsNull(pledge_available_to_trade)) {
        pledge_available_to_trade = NULL;
    }
    if (pledge_available_to_trade) { 
    pledge_available_to_trade_local_nonprim = pledge_available_to_trade_parseFromJSON(pledge_available_to_trade); //nonprimitive
    }



    available_to_trade_local_var = available_to_trade_create_internal (
        total_local_var,
        cash_available_to_trade ? cash_available_to_trade_local_nonprim : NULL,
        pledge_available_to_trade ? pledge_available_to_trade_local_nonprim : NULL
        );

    if (!available_to_trade_local_var) {
        goto end;
    }

    return available_to_trade_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (cash_available_to_trade_local_nonprim) {
        cash_available_to_trade_free(cash_available_to_trade_local_nonprim);
        cash_available_to_trade_local_nonprim = NULL;
    }
    if (pledge_available_to_trade_local_nonprim) {
        pledge_available_to_trade_free(pledge_available_to_trade_local_nonprim);
        pledge_available_to_trade_local_nonprim = NULL;
    }
    return NULL;

}
