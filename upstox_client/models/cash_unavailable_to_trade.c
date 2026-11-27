#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_unavailable_to_trade.h"



static cash_unavailable_to_trade_t *cash_unavailable_to_trade_create_internal(
    unsettled_profit_t *unsettled_profit
    ) {
    cash_unavailable_to_trade_t *cash_unavailable_to_trade_local_var = malloc(sizeof(cash_unavailable_to_trade_t));
    if (!cash_unavailable_to_trade_local_var) {
        return NULL;
    }
    memset(cash_unavailable_to_trade_local_var, 0, sizeof(cash_unavailable_to_trade_t));
    cash_unavailable_to_trade_local_var->_library_owned = 1;
    cash_unavailable_to_trade_local_var->unsettled_profit = unsettled_profit;
    return cash_unavailable_to_trade_local_var;
}

cash_unavailable_to_trade_t *cash_unavailable_to_trade_create(
    unsettled_profit_t *unsettled_profit
    ) {
    cash_unavailable_to_trade_t *result = cash_unavailable_to_trade_create_internal (
        unsettled_profit
        );
    if (!result) {
    }
    return result;
}

void cash_unavailable_to_trade_free(cash_unavailable_to_trade_t *cash_unavailable_to_trade) {
    if(NULL == cash_unavailable_to_trade){
        return ;
    }
    if(cash_unavailable_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_unavailable_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_unavailable_to_trade->unsettled_profit) {
        unsettled_profit_free(cash_unavailable_to_trade->unsettled_profit);
        cash_unavailable_to_trade->unsettled_profit = NULL;
    }
    free(cash_unavailable_to_trade);
}

cJSON *cash_unavailable_to_trade_convertToJSON(cash_unavailable_to_trade_t *cash_unavailable_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // cash_unavailable_to_trade->unsettled_profit
    if(cash_unavailable_to_trade->unsettled_profit) {
    cJSON *unsettled_profit_local_JSON = unsettled_profit_convertToJSON(cash_unavailable_to_trade->unsettled_profit);
    if(unsettled_profit_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unsettled_profit", unsettled_profit_local_JSON);
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

cash_unavailable_to_trade_t *cash_unavailable_to_trade_parseFromJSON(cJSON *cash_unavailable_to_tradeJSON){

    cash_unavailable_to_trade_t *cash_unavailable_to_trade_local_var = NULL;

    // define the local variable for cash_unavailable_to_trade->unsettled_profit
    unsettled_profit_t *unsettled_profit_local_nonprim = NULL;

    // cash_unavailable_to_trade->unsettled_profit
    cJSON *unsettled_profit = cJSON_GetObjectItemCaseSensitive(cash_unavailable_to_tradeJSON, "unsettled_profit");
    if (cJSON_IsNull(unsettled_profit)) {
        unsettled_profit = NULL;
    }
    if (unsettled_profit) { 
    unsettled_profit_local_nonprim = unsettled_profit_parseFromJSON(unsettled_profit); //nonprimitive
    }



    cash_unavailable_to_trade_local_var = cash_unavailable_to_trade_create_internal (
        unsettled_profit ? unsettled_profit_local_nonprim : NULL
        );

    if (!cash_unavailable_to_trade_local_var) {
        goto end;
    }

    return cash_unavailable_to_trade_local_var;
end:
    if (unsettled_profit_local_nonprim) {
        unsettled_profit_free(unsettled_profit_local_nonprim);
        unsettled_profit_local_nonprim = NULL;
    }
    return NULL;

}
