#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unavailable_to_trade.h"



static unavailable_to_trade_t *unavailable_to_trade_create_internal(
    cash_unavailable_to_trade_t *cash_unavailable_to_trade,
    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade
    ) {
    unavailable_to_trade_t *unavailable_to_trade_local_var = malloc(sizeof(unavailable_to_trade_t));
    if (!unavailable_to_trade_local_var) {
        return NULL;
    }
    memset(unavailable_to_trade_local_var, 0, sizeof(unavailable_to_trade_t));
    unavailable_to_trade_local_var->_library_owned = 1;
    unavailable_to_trade_local_var->cash_unavailable_to_trade = cash_unavailable_to_trade;
    unavailable_to_trade_local_var->pledge_unavailable_to_trade = pledge_unavailable_to_trade;
    return unavailable_to_trade_local_var;
}

unavailable_to_trade_t *unavailable_to_trade_create(
    cash_unavailable_to_trade_t *cash_unavailable_to_trade,
    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade
    ) {
    unavailable_to_trade_t *result = unavailable_to_trade_create_internal (
        cash_unavailable_to_trade,
        pledge_unavailable_to_trade
        );
    if (!result) {
    }
    return result;
}

void unavailable_to_trade_free(unavailable_to_trade_t *unavailable_to_trade) {
    if(NULL == unavailable_to_trade){
        return ;
    }
    if(unavailable_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unavailable_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unavailable_to_trade->cash_unavailable_to_trade) {
        cash_unavailable_to_trade_free(unavailable_to_trade->cash_unavailable_to_trade);
        unavailable_to_trade->cash_unavailable_to_trade = NULL;
    }
    if (unavailable_to_trade->pledge_unavailable_to_trade) {
        pledge_unavailable_to_trade_free(unavailable_to_trade->pledge_unavailable_to_trade);
        unavailable_to_trade->pledge_unavailable_to_trade = NULL;
    }
    free(unavailable_to_trade);
}

cJSON *unavailable_to_trade_convertToJSON(unavailable_to_trade_t *unavailable_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // unavailable_to_trade->cash_unavailable_to_trade
    if(unavailable_to_trade->cash_unavailable_to_trade) {
    cJSON *cash_unavailable_to_trade_local_JSON = cash_unavailable_to_trade_convertToJSON(unavailable_to_trade->cash_unavailable_to_trade);
    if(cash_unavailable_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cash_unavailable_to_trade", cash_unavailable_to_trade_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // unavailable_to_trade->pledge_unavailable_to_trade
    if(unavailable_to_trade->pledge_unavailable_to_trade) {
    cJSON *pledge_unavailable_to_trade_local_JSON = pledge_unavailable_to_trade_convertToJSON(unavailable_to_trade->pledge_unavailable_to_trade);
    if(pledge_unavailable_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pledge_unavailable_to_trade", pledge_unavailable_to_trade_local_JSON);
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

unavailable_to_trade_t *unavailable_to_trade_parseFromJSON(cJSON *unavailable_to_tradeJSON){

    unavailable_to_trade_t *unavailable_to_trade_local_var = NULL;

    // define the local variable for unavailable_to_trade->cash_unavailable_to_trade
    cash_unavailable_to_trade_t *cash_unavailable_to_trade_local_nonprim = NULL;

    // define the local variable for unavailable_to_trade->pledge_unavailable_to_trade
    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_local_nonprim = NULL;

    // unavailable_to_trade->cash_unavailable_to_trade
    cJSON *cash_unavailable_to_trade = cJSON_GetObjectItemCaseSensitive(unavailable_to_tradeJSON, "cash_unavailable_to_trade");
    if (cJSON_IsNull(cash_unavailable_to_trade)) {
        cash_unavailable_to_trade = NULL;
    }
    if (cash_unavailable_to_trade) { 
    cash_unavailable_to_trade_local_nonprim = cash_unavailable_to_trade_parseFromJSON(cash_unavailable_to_trade); //nonprimitive
    }

    // unavailable_to_trade->pledge_unavailable_to_trade
    cJSON *pledge_unavailable_to_trade = cJSON_GetObjectItemCaseSensitive(unavailable_to_tradeJSON, "pledge_unavailable_to_trade");
    if (cJSON_IsNull(pledge_unavailable_to_trade)) {
        pledge_unavailable_to_trade = NULL;
    }
    if (pledge_unavailable_to_trade) { 
    pledge_unavailable_to_trade_local_nonprim = pledge_unavailable_to_trade_parseFromJSON(pledge_unavailable_to_trade); //nonprimitive
    }



    unavailable_to_trade_local_var = unavailable_to_trade_create_internal (
        cash_unavailable_to_trade ? cash_unavailable_to_trade_local_nonprim : NULL,
        pledge_unavailable_to_trade ? pledge_unavailable_to_trade_local_nonprim : NULL
        );

    if (!unavailable_to_trade_local_var) {
        goto end;
    }

    return unavailable_to_trade_local_var;
end:
    if (cash_unavailable_to_trade_local_nonprim) {
        cash_unavailable_to_trade_free(cash_unavailable_to_trade_local_nonprim);
        cash_unavailable_to_trade_local_nonprim = NULL;
    }
    if (pledge_unavailable_to_trade_local_nonprim) {
        pledge_unavailable_to_trade_free(pledge_unavailable_to_trade_local_nonprim);
        pledge_unavailable_to_trade_local_nonprim = NULL;
    }
    return NULL;

}
