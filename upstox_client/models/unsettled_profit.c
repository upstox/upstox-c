#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unsettled_profit.h"



static unsettled_profit_t *unsettled_profit_create_internal(
    double *todays_profit,
    double *previous_days
    ) {
    unsettled_profit_t *unsettled_profit_local_var = malloc(sizeof(unsettled_profit_t));
    if (!unsettled_profit_local_var) {
        return NULL;
    }
    memset(unsettled_profit_local_var, 0, sizeof(unsettled_profit_t));
    unsettled_profit_local_var->_library_owned = 1;
    unsettled_profit_local_var->todays_profit = todays_profit;
    unsettled_profit_local_var->previous_days = previous_days;
    return unsettled_profit_local_var;
}

unsettled_profit_t *unsettled_profit_create(
    double *todays_profit,
    double *previous_days
    ) {
    double *todays_profit_copy = NULL;
    if (todays_profit) {
        todays_profit_copy = malloc(sizeof(double));
        if (todays_profit_copy) *todays_profit_copy = *todays_profit;
    }
    double *previous_days_copy = NULL;
    if (previous_days) {
        previous_days_copy = malloc(sizeof(double));
        if (previous_days_copy) *previous_days_copy = *previous_days;
    }
    unsettled_profit_t *result = unsettled_profit_create_internal (
        todays_profit_copy,
        previous_days_copy
        );
    if (!result) {
        free(todays_profit_copy);
        free(previous_days_copy);
    }
    return result;
}

void unsettled_profit_free(unsettled_profit_t *unsettled_profit) {
    if(NULL == unsettled_profit){
        return ;
    }
    if(unsettled_profit->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unsettled_profit_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unsettled_profit->todays_profit) {
        free(unsettled_profit->todays_profit);
        unsettled_profit->todays_profit = NULL;
    }
    if (unsettled_profit->previous_days) {
        free(unsettled_profit->previous_days);
        unsettled_profit->previous_days = NULL;
    }
    free(unsettled_profit);
}

cJSON *unsettled_profit_convertToJSON(unsettled_profit_t *unsettled_profit) {
    cJSON *item = cJSON_CreateObject();

    // unsettled_profit->todays_profit
    if(unsettled_profit->todays_profit) {
    if(cJSON_AddNumberToObject(item, "todays_profit", *unsettled_profit->todays_profit) == NULL) {
    goto fail; //Numeric
    }
    }


    // unsettled_profit->previous_days
    if(unsettled_profit->previous_days) {
    if(cJSON_AddNumberToObject(item, "previous_days", *unsettled_profit->previous_days) == NULL) {
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

unsettled_profit_t *unsettled_profit_parseFromJSON(cJSON *unsettled_profitJSON){

    unsettled_profit_t *unsettled_profit_local_var = NULL;

    // define the local variable for unsettled_profit->todays_profit
    double *todays_profit_local_var = NULL;

    // define the local variable for unsettled_profit->previous_days
    double *previous_days_local_var = NULL;

    // unsettled_profit->todays_profit
    cJSON *todays_profit = cJSON_GetObjectItemCaseSensitive(unsettled_profitJSON, "todays_profit");
    if (cJSON_IsNull(todays_profit)) {
        todays_profit = NULL;
    }
    if (todays_profit) { 
    if(!cJSON_IsNumber(todays_profit))
    {
    goto end; //Numeric
    }
    todays_profit_local_var = malloc(sizeof(double));
    if(!todays_profit_local_var)
    {
        goto end;
    }
    *todays_profit_local_var = todays_profit->valuedouble;
    }

    // unsettled_profit->previous_days
    cJSON *previous_days = cJSON_GetObjectItemCaseSensitive(unsettled_profitJSON, "previous_days");
    if (cJSON_IsNull(previous_days)) {
        previous_days = NULL;
    }
    if (previous_days) { 
    if(!cJSON_IsNumber(previous_days))
    {
    goto end; //Numeric
    }
    previous_days_local_var = malloc(sizeof(double));
    if(!previous_days_local_var)
    {
        goto end;
    }
    *previous_days_local_var = previous_days->valuedouble;
    }



    unsettled_profit_local_var = unsettled_profit_create_internal (
        todays_profit_local_var,
        previous_days_local_var
        );

    if (!unsettled_profit_local_var) {
        goto end;
    }

    return unsettled_profit_local_var;
end:
    if (todays_profit_local_var) {
        free(todays_profit_local_var);
        todays_profit_local_var = NULL;
    }
    if (previous_days_local_var) {
        free(previous_days_local_var);
        previous_days_local_var = NULL;
    }
    return NULL;

}
