#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pledge_available_to_trade.h"



static pledge_available_to_trade_t *pledge_available_to_trade_create_internal(
    margin_from_pledge_t *margin_from_pledge,
    pledge_margin_used_t *margin_used
    ) {
    pledge_available_to_trade_t *pledge_available_to_trade_local_var = malloc(sizeof(pledge_available_to_trade_t));
    if (!pledge_available_to_trade_local_var) {
        return NULL;
    }
    memset(pledge_available_to_trade_local_var, 0, sizeof(pledge_available_to_trade_t));
    pledge_available_to_trade_local_var->_library_owned = 1;
    pledge_available_to_trade_local_var->margin_from_pledge = margin_from_pledge;
    pledge_available_to_trade_local_var->margin_used = margin_used;
    return pledge_available_to_trade_local_var;
}

pledge_available_to_trade_t *pledge_available_to_trade_create(
    margin_from_pledge_t *margin_from_pledge,
    pledge_margin_used_t *margin_used
    ) {
    pledge_available_to_trade_t *result = pledge_available_to_trade_create_internal (
        margin_from_pledge,
        margin_used
        );
    if (!result) {
    }
    return result;
}

void pledge_available_to_trade_free(pledge_available_to_trade_t *pledge_available_to_trade) {
    if(NULL == pledge_available_to_trade){
        return ;
    }
    if(pledge_available_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pledge_available_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pledge_available_to_trade->margin_from_pledge) {
        margin_from_pledge_free(pledge_available_to_trade->margin_from_pledge);
        pledge_available_to_trade->margin_from_pledge = NULL;
    }
    if (pledge_available_to_trade->margin_used) {
        pledge_margin_used_free(pledge_available_to_trade->margin_used);
        pledge_available_to_trade->margin_used = NULL;
    }
    free(pledge_available_to_trade);
}

cJSON *pledge_available_to_trade_convertToJSON(pledge_available_to_trade_t *pledge_available_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // pledge_available_to_trade->margin_from_pledge
    if(pledge_available_to_trade->margin_from_pledge) {
    cJSON *margin_from_pledge_local_JSON = margin_from_pledge_convertToJSON(pledge_available_to_trade->margin_from_pledge);
    if(margin_from_pledge_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "margin_from_pledge", margin_from_pledge_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // pledge_available_to_trade->margin_used
    if(pledge_available_to_trade->margin_used) {
    cJSON *margin_used_local_JSON = pledge_margin_used_convertToJSON(pledge_available_to_trade->margin_used);
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

pledge_available_to_trade_t *pledge_available_to_trade_parseFromJSON(cJSON *pledge_available_to_tradeJSON){

    pledge_available_to_trade_t *pledge_available_to_trade_local_var = NULL;

    // define the local variable for pledge_available_to_trade->margin_from_pledge
    margin_from_pledge_t *margin_from_pledge_local_nonprim = NULL;

    // define the local variable for pledge_available_to_trade->margin_used
    pledge_margin_used_t *margin_used_local_nonprim = NULL;

    // pledge_available_to_trade->margin_from_pledge
    cJSON *margin_from_pledge = cJSON_GetObjectItemCaseSensitive(pledge_available_to_tradeJSON, "margin_from_pledge");
    if (cJSON_IsNull(margin_from_pledge)) {
        margin_from_pledge = NULL;
    }
    if (margin_from_pledge) { 
    margin_from_pledge_local_nonprim = margin_from_pledge_parseFromJSON(margin_from_pledge); //nonprimitive
    }

    // pledge_available_to_trade->margin_used
    cJSON *margin_used = cJSON_GetObjectItemCaseSensitive(pledge_available_to_tradeJSON, "margin_used");
    if (cJSON_IsNull(margin_used)) {
        margin_used = NULL;
    }
    if (margin_used) { 
    margin_used_local_nonprim = pledge_margin_used_parseFromJSON(margin_used); //nonprimitive
    }



    pledge_available_to_trade_local_var = pledge_available_to_trade_create_internal (
        margin_from_pledge ? margin_from_pledge_local_nonprim : NULL,
        margin_used ? margin_used_local_nonprim : NULL
        );

    if (!pledge_available_to_trade_local_var) {
        goto end;
    }

    return pledge_available_to_trade_local_var;
end:
    if (margin_from_pledge_local_nonprim) {
        margin_from_pledge_free(margin_from_pledge_local_nonprim);
        margin_from_pledge_local_nonprim = NULL;
    }
    if (margin_used_local_nonprim) {
        pledge_margin_used_free(margin_used_local_nonprim);
        margin_used_local_nonprim = NULL;
    }
    return NULL;

}
