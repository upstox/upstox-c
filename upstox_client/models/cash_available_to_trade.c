#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_available_to_trade.h"



static cash_available_to_trade_t *cash_available_to_trade_create_internal(
    double *total,
    cash_breakdown_t *cash,
    cash_margin_used_t *margin_used
    ) {
    cash_available_to_trade_t *cash_available_to_trade_local_var = malloc(sizeof(cash_available_to_trade_t));
    if (!cash_available_to_trade_local_var) {
        return NULL;
    }
    memset(cash_available_to_trade_local_var, 0, sizeof(cash_available_to_trade_t));
    cash_available_to_trade_local_var->_library_owned = 1;
    cash_available_to_trade_local_var->total = total;
    cash_available_to_trade_local_var->cash = cash;
    cash_available_to_trade_local_var->margin_used = margin_used;
    return cash_available_to_trade_local_var;
}

cash_available_to_trade_t *cash_available_to_trade_create(
    double *total,
    cash_breakdown_t *cash,
    cash_margin_used_t *margin_used
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    cash_available_to_trade_t *result = cash_available_to_trade_create_internal (
        total_copy,
        cash,
        margin_used
        );
    if (!result) {
        free(total_copy);
    }
    return result;
}

void cash_available_to_trade_free(cash_available_to_trade_t *cash_available_to_trade) {
    if(NULL == cash_available_to_trade){
        return ;
    }
    if(cash_available_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_available_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_available_to_trade->total) {
        free(cash_available_to_trade->total);
        cash_available_to_trade->total = NULL;
    }
    if (cash_available_to_trade->cash) {
        cash_breakdown_free(cash_available_to_trade->cash);
        cash_available_to_trade->cash = NULL;
    }
    if (cash_available_to_trade->margin_used) {
        cash_margin_used_free(cash_available_to_trade->margin_used);
        cash_available_to_trade->margin_used = NULL;
    }
    free(cash_available_to_trade);
}

cJSON *cash_available_to_trade_convertToJSON(cash_available_to_trade_t *cash_available_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // cash_available_to_trade->total
    if(cash_available_to_trade->total) {
    if(cJSON_AddNumberToObject(item, "total", *cash_available_to_trade->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_available_to_trade->cash
    if(cash_available_to_trade->cash) {
    cJSON *cash_local_JSON = cash_breakdown_convertToJSON(cash_available_to_trade->cash);
    if(cash_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cash", cash_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cash_available_to_trade->margin_used
    if(cash_available_to_trade->margin_used) {
    cJSON *margin_used_local_JSON = cash_margin_used_convertToJSON(cash_available_to_trade->margin_used);
    if(margin_used_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "margin_used", margin_used_local_JSON);
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

cash_available_to_trade_t *cash_available_to_trade_parseFromJSON(cJSON *cash_available_to_tradeJSON){

    cash_available_to_trade_t *cash_available_to_trade_local_var = NULL;

    // define the local variable for cash_available_to_trade->total
    double *total_local_var = NULL;

    // define the local variable for cash_available_to_trade->cash
    cash_breakdown_t *cash_local_nonprim = NULL;

    // define the local variable for cash_available_to_trade->margin_used
    cash_margin_used_t *margin_used_local_nonprim = NULL;

    // cash_available_to_trade->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cash_available_to_tradeJSON, "total");
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

    // cash_available_to_trade->cash
    cJSON *cash = cJSON_GetObjectItemCaseSensitive(cash_available_to_tradeJSON, "cash");
    if (cJSON_IsNull(cash)) {
        cash = NULL;
    }
    if (cash) { 
    cash_local_nonprim = cash_breakdown_parseFromJSON(cash); //nonprimitive
    }

    // cash_available_to_trade->margin_used
    cJSON *margin_used = cJSON_GetObjectItemCaseSensitive(cash_available_to_tradeJSON, "margin_used");
    if (cJSON_IsNull(margin_used)) {
        margin_used = NULL;
    }
    if (margin_used) { 
    margin_used_local_nonprim = cash_margin_used_parseFromJSON(margin_used); //nonprimitive
    }



    cash_available_to_trade_local_var = cash_available_to_trade_create_internal (
        total_local_var,
        cash ? cash_local_nonprim : NULL,
        margin_used ? margin_used_local_nonprim : NULL
        );

    if (!cash_available_to_trade_local_var) {
        goto end;
    }

    return cash_available_to_trade_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (cash_local_nonprim) {
        cash_breakdown_free(cash_local_nonprim);
        cash_local_nonprim = NULL;
    }
    if (margin_used_local_nonprim) {
        cash_margin_used_free(margin_used_local_nonprim);
        margin_used_local_nonprim = NULL;
    }
    return NULL;

}
