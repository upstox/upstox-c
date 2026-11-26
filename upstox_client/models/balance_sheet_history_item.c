#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "balance_sheet_history_item.h"



static balance_sheet_history_item_t *balance_sheet_history_item_create_internal(
    double *total_asset,
    double *total_liability,
    char *period
    ) {
    balance_sheet_history_item_t *balance_sheet_history_item_local_var = malloc(sizeof(balance_sheet_history_item_t));
    if (!balance_sheet_history_item_local_var) {
        return NULL;
    }
    memset(balance_sheet_history_item_local_var, 0, sizeof(balance_sheet_history_item_t));
    balance_sheet_history_item_local_var->_library_owned = 1;
    balance_sheet_history_item_local_var->total_asset = total_asset;
    balance_sheet_history_item_local_var->total_liability = total_liability;
    balance_sheet_history_item_local_var->period = period;
    return balance_sheet_history_item_local_var;
}

balance_sheet_history_item_t *balance_sheet_history_item_create(
    double *total_asset,
    double *total_liability,
    char *period
    ) {
    double *total_asset_copy = NULL;
    if (total_asset) {
        total_asset_copy = malloc(sizeof(double));
        if (total_asset_copy) *total_asset_copy = *total_asset;
    }
    double *total_liability_copy = NULL;
    if (total_liability) {
        total_liability_copy = malloc(sizeof(double));
        if (total_liability_copy) *total_liability_copy = *total_liability;
    }
    balance_sheet_history_item_t *result = balance_sheet_history_item_create_internal (
        total_asset_copy,
        total_liability_copy,
        period
        );
    if (!result) {
        free(total_asset_copy);
        free(total_liability_copy);
    }
    return result;
}

void balance_sheet_history_item_free(balance_sheet_history_item_t *balance_sheet_history_item) {
    if(NULL == balance_sheet_history_item){
        return ;
    }
    if(balance_sheet_history_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "balance_sheet_history_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (balance_sheet_history_item->total_asset) {
        free(balance_sheet_history_item->total_asset);
        balance_sheet_history_item->total_asset = NULL;
    }
    if (balance_sheet_history_item->total_liability) {
        free(balance_sheet_history_item->total_liability);
        balance_sheet_history_item->total_liability = NULL;
    }
    if (balance_sheet_history_item->period) {
        free(balance_sheet_history_item->period);
        balance_sheet_history_item->period = NULL;
    }
    free(balance_sheet_history_item);
}

cJSON *balance_sheet_history_item_convertToJSON(balance_sheet_history_item_t *balance_sheet_history_item) {
    cJSON *item = cJSON_CreateObject();

    // balance_sheet_history_item->total_asset
    if(balance_sheet_history_item->total_asset) {
    if(cJSON_AddNumberToObject(item, "total_asset", *balance_sheet_history_item->total_asset) == NULL) {
    goto fail; //Numeric
    }
    }


    // balance_sheet_history_item->total_liability
    if(balance_sheet_history_item->total_liability) {
    if(cJSON_AddNumberToObject(item, "total_liability", *balance_sheet_history_item->total_liability) == NULL) {
    goto fail; //Numeric
    }
    }


    // balance_sheet_history_item->period
    if(balance_sheet_history_item->period) {
    if(cJSON_AddStringToObject(item, "period", balance_sheet_history_item->period) == NULL) {
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

balance_sheet_history_item_t *balance_sheet_history_item_parseFromJSON(cJSON *balance_sheet_history_itemJSON){

    balance_sheet_history_item_t *balance_sheet_history_item_local_var = NULL;

    // define the local variable for balance_sheet_history_item->total_asset
    double *total_asset_local_var = NULL;

    // define the local variable for balance_sheet_history_item->total_liability
    double *total_liability_local_var = NULL;

    char *period_local_str = NULL;

    // balance_sheet_history_item->total_asset
    cJSON *total_asset = cJSON_GetObjectItemCaseSensitive(balance_sheet_history_itemJSON, "total_asset");
    if (cJSON_IsNull(total_asset)) {
        total_asset = NULL;
    }
    if (total_asset) { 
    if(!cJSON_IsNumber(total_asset))
    {
    goto end; //Numeric
    }
    total_asset_local_var = malloc(sizeof(double));
    if(!total_asset_local_var)
    {
        goto end;
    }
    *total_asset_local_var = total_asset->valuedouble;
    }

    // balance_sheet_history_item->total_liability
    cJSON *total_liability = cJSON_GetObjectItemCaseSensitive(balance_sheet_history_itemJSON, "total_liability");
    if (cJSON_IsNull(total_liability)) {
        total_liability = NULL;
    }
    if (total_liability) { 
    if(!cJSON_IsNumber(total_liability))
    {
    goto end; //Numeric
    }
    total_liability_local_var = malloc(sizeof(double));
    if(!total_liability_local_var)
    {
        goto end;
    }
    *total_liability_local_var = total_liability->valuedouble;
    }

    // balance_sheet_history_item->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(balance_sheet_history_itemJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (period) { 
    if(!cJSON_IsString(period) && !cJSON_IsNull(period))
    {
    goto end; //String
    }
    }


    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);

    balance_sheet_history_item_local_var = balance_sheet_history_item_create_internal (
        total_asset_local_var,
        total_liability_local_var,
        period_local_str
        );

    if (!balance_sheet_history_item_local_var) {
        goto end;
    }

    return balance_sheet_history_item_local_var;
end:
    if (total_asset_local_var) {
        free(total_asset_local_var);
        total_asset_local_var = NULL;
    }
    if (total_liability_local_var) {
        free(total_liability_local_var);
        total_liability_local_var = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    return NULL;

}
