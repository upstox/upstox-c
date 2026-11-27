#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "history_item.h"



static history_item_t *history_item_create_internal(
    double *value,
    char *period,
    char *change
    ) {
    history_item_t *history_item_local_var = malloc(sizeof(history_item_t));
    if (!history_item_local_var) {
        return NULL;
    }
    memset(history_item_local_var, 0, sizeof(history_item_t));
    history_item_local_var->_library_owned = 1;
    history_item_local_var->value = value;
    history_item_local_var->period = period;
    history_item_local_var->change = change;
    return history_item_local_var;
}

history_item_t *history_item_create(
    double *value,
    char *period,
    char *change
    ) {
    double *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(double));
        if (value_copy) *value_copy = *value;
    }
    history_item_t *result = history_item_create_internal (
        value_copy,
        period,
        change
        );
    if (!result) {
        free(value_copy);
    }
    return result;
}

void history_item_free(history_item_t *history_item) {
    if(NULL == history_item){
        return ;
    }
    if(history_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "history_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (history_item->value) {
        free(history_item->value);
        history_item->value = NULL;
    }
    if (history_item->period) {
        free(history_item->period);
        history_item->period = NULL;
    }
    if (history_item->change) {
        free(history_item->change);
        history_item->change = NULL;
    }
    free(history_item);
}

cJSON *history_item_convertToJSON(history_item_t *history_item) {
    cJSON *item = cJSON_CreateObject();

    // history_item->value
    if(history_item->value) {
    if(cJSON_AddNumberToObject(item, "value", *history_item->value) == NULL) {
    goto fail; //Numeric
    }
    }


    // history_item->period
    if(history_item->period) {
    if(cJSON_AddStringToObject(item, "period", history_item->period) == NULL) {
    goto fail; //String
    }
    }


    // history_item->change
    if(history_item->change) {
    if(cJSON_AddStringToObject(item, "change", history_item->change) == NULL) {
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

history_item_t *history_item_parseFromJSON(cJSON *history_itemJSON){

    history_item_t *history_item_local_var = NULL;

    // define the local variable for history_item->value
    double *value_local_var = NULL;

    char *period_local_str = NULL;

    char *change_local_str = NULL;

    // history_item->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(history_itemJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(double));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;
    }

    // history_item->period
    cJSON *period = cJSON_GetObjectItemCaseSensitive(history_itemJSON, "period");
    if (cJSON_IsNull(period)) {
        period = NULL;
    }
    if (period) { 
    if(!cJSON_IsString(period) && !cJSON_IsNull(period))
    {
    goto end; //String
    }
    }

    // history_item->change
    cJSON *change = cJSON_GetObjectItemCaseSensitive(history_itemJSON, "change");
    if (cJSON_IsNull(change)) {
        change = NULL;
    }
    if (change) { 
    if(!cJSON_IsString(change) && !cJSON_IsNull(change))
    {
    goto end; //String
    }
    }


    if (period && !cJSON_IsNull(period)) period_local_str = strdup(period->valuestring);
    if (change && !cJSON_IsNull(change)) change_local_str = strdup(change->valuestring);

    history_item_local_var = history_item_create_internal (
        value_local_var,
        period_local_str,
        change_local_str
        );

    if (!history_item_local_var) {
        goto end;
    }

    return history_item_local_var;
end:
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    if (period_local_str) {
        free(period_local_str);
        period_local_str = NULL;
    }
    if (change_local_str) {
        free(change_local_str);
        change_local_str = NULL;
    }
    return NULL;

}
