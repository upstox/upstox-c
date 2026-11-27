#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_fund_margin_v3_data.h"



static user_fund_margin_v3_data_t *user_fund_margin_v3_data_create_internal(
    available_to_trade_t *available_to_trade,
    unavailable_to_trade_t *unavailable_to_trade
    ) {
    user_fund_margin_v3_data_t *user_fund_margin_v3_data_local_var = malloc(sizeof(user_fund_margin_v3_data_t));
    if (!user_fund_margin_v3_data_local_var) {
        return NULL;
    }
    memset(user_fund_margin_v3_data_local_var, 0, sizeof(user_fund_margin_v3_data_t));
    user_fund_margin_v3_data_local_var->_library_owned = 1;
    user_fund_margin_v3_data_local_var->available_to_trade = available_to_trade;
    user_fund_margin_v3_data_local_var->unavailable_to_trade = unavailable_to_trade;
    return user_fund_margin_v3_data_local_var;
}

user_fund_margin_v3_data_t *user_fund_margin_v3_data_create(
    available_to_trade_t *available_to_trade,
    unavailable_to_trade_t *unavailable_to_trade
    ) {
    user_fund_margin_v3_data_t *result = user_fund_margin_v3_data_create_internal (
        available_to_trade,
        unavailable_to_trade
        );
    if (!result) {
    }
    return result;
}

void user_fund_margin_v3_data_free(user_fund_margin_v3_data_t *user_fund_margin_v3_data) {
    if(NULL == user_fund_margin_v3_data){
        return ;
    }
    if(user_fund_margin_v3_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_fund_margin_v3_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_fund_margin_v3_data->available_to_trade) {
        available_to_trade_free(user_fund_margin_v3_data->available_to_trade);
        user_fund_margin_v3_data->available_to_trade = NULL;
    }
    if (user_fund_margin_v3_data->unavailable_to_trade) {
        unavailable_to_trade_free(user_fund_margin_v3_data->unavailable_to_trade);
        user_fund_margin_v3_data->unavailable_to_trade = NULL;
    }
    free(user_fund_margin_v3_data);
}

cJSON *user_fund_margin_v3_data_convertToJSON(user_fund_margin_v3_data_t *user_fund_margin_v3_data) {
    cJSON *item = cJSON_CreateObject();

    // user_fund_margin_v3_data->available_to_trade
    if(user_fund_margin_v3_data->available_to_trade) {
    cJSON *available_to_trade_local_JSON = available_to_trade_convertToJSON(user_fund_margin_v3_data->available_to_trade);
    if(available_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "available_to_trade", available_to_trade_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // user_fund_margin_v3_data->unavailable_to_trade
    if(user_fund_margin_v3_data->unavailable_to_trade) {
    cJSON *unavailable_to_trade_local_JSON = unavailable_to_trade_convertToJSON(user_fund_margin_v3_data->unavailable_to_trade);
    if(unavailable_to_trade_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unavailable_to_trade", unavailable_to_trade_local_JSON);
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

user_fund_margin_v3_data_t *user_fund_margin_v3_data_parseFromJSON(cJSON *user_fund_margin_v3_dataJSON){

    user_fund_margin_v3_data_t *user_fund_margin_v3_data_local_var = NULL;

    // define the local variable for user_fund_margin_v3_data->available_to_trade
    available_to_trade_t *available_to_trade_local_nonprim = NULL;

    // define the local variable for user_fund_margin_v3_data->unavailable_to_trade
    unavailable_to_trade_t *unavailable_to_trade_local_nonprim = NULL;

    // user_fund_margin_v3_data->available_to_trade
    cJSON *available_to_trade = cJSON_GetObjectItemCaseSensitive(user_fund_margin_v3_dataJSON, "available_to_trade");
    if (cJSON_IsNull(available_to_trade)) {
        available_to_trade = NULL;
    }
    if (available_to_trade) { 
    available_to_trade_local_nonprim = available_to_trade_parseFromJSON(available_to_trade); //nonprimitive
    }

    // user_fund_margin_v3_data->unavailable_to_trade
    cJSON *unavailable_to_trade = cJSON_GetObjectItemCaseSensitive(user_fund_margin_v3_dataJSON, "unavailable_to_trade");
    if (cJSON_IsNull(unavailable_to_trade)) {
        unavailable_to_trade = NULL;
    }
    if (unavailable_to_trade) { 
    unavailable_to_trade_local_nonprim = unavailable_to_trade_parseFromJSON(unavailable_to_trade); //nonprimitive
    }



    user_fund_margin_v3_data_local_var = user_fund_margin_v3_data_create_internal (
        available_to_trade ? available_to_trade_local_nonprim : NULL,
        unavailable_to_trade ? unavailable_to_trade_local_nonprim : NULL
        );

    if (!user_fund_margin_v3_data_local_var) {
        goto end;
    }

    return user_fund_margin_v3_data_local_var;
end:
    if (available_to_trade_local_nonprim) {
        available_to_trade_free(available_to_trade_local_nonprim);
        available_to_trade_local_nonprim = NULL;
    }
    if (unavailable_to_trade_local_nonprim) {
        unavailable_to_trade_free(unavailable_to_trade_local_nonprim);
        unavailable_to_trade_local_nonprim = NULL;
    }
    return NULL;

}
