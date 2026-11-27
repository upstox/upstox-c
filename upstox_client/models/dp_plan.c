#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dp_plan.h"



static dp_plan_t *dp_plan_create_internal(
    char *name,
    double *min_expense
    ) {
    dp_plan_t *dp_plan_local_var = malloc(sizeof(dp_plan_t));
    if (!dp_plan_local_var) {
        return NULL;
    }
    memset(dp_plan_local_var, 0, sizeof(dp_plan_t));
    dp_plan_local_var->_library_owned = 1;
    dp_plan_local_var->name = name;
    dp_plan_local_var->min_expense = min_expense;
    return dp_plan_local_var;
}

dp_plan_t *dp_plan_create(
    char *name,
    double *min_expense
    ) {
    double *min_expense_copy = NULL;
    if (min_expense) {
        min_expense_copy = malloc(sizeof(double));
        if (min_expense_copy) *min_expense_copy = *min_expense;
    }
    dp_plan_t *result = dp_plan_create_internal (
        name,
        min_expense_copy
        );
    if (!result) {
        free(min_expense_copy);
    }
    return result;
}

void dp_plan_free(dp_plan_t *dp_plan) {
    if(NULL == dp_plan){
        return ;
    }
    if(dp_plan->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "dp_plan_free");
        return ;
    }
    listEntry_t *listEntry;
    if (dp_plan->name) {
        free(dp_plan->name);
        dp_plan->name = NULL;
    }
    if (dp_plan->min_expense) {
        free(dp_plan->min_expense);
        dp_plan->min_expense = NULL;
    }
    free(dp_plan);
}

cJSON *dp_plan_convertToJSON(dp_plan_t *dp_plan) {
    cJSON *item = cJSON_CreateObject();

    // dp_plan->name
    if(dp_plan->name) {
    if(cJSON_AddStringToObject(item, "name", dp_plan->name) == NULL) {
    goto fail; //String
    }
    }


    // dp_plan->min_expense
    if(dp_plan->min_expense) {
    if(cJSON_AddNumberToObject(item, "min_expense", *dp_plan->min_expense) == NULL) {
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

dp_plan_t *dp_plan_parseFromJSON(cJSON *dp_planJSON){

    dp_plan_t *dp_plan_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for dp_plan->min_expense
    double *min_expense_local_var = NULL;

    // dp_plan->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(dp_planJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // dp_plan->min_expense
    cJSON *min_expense = cJSON_GetObjectItemCaseSensitive(dp_planJSON, "min_expense");
    if (cJSON_IsNull(min_expense)) {
        min_expense = NULL;
    }
    if (min_expense) { 
    if(!cJSON_IsNumber(min_expense))
    {
    goto end; //Numeric
    }
    min_expense_local_var = malloc(sizeof(double));
    if(!min_expense_local_var)
    {
        goto end;
    }
    *min_expense_local_var = min_expense->valuedouble;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    dp_plan_local_var = dp_plan_create_internal (
        name_local_str,
        min_expense_local_var
        );

    if (!dp_plan_local_var) {
        goto end;
    }

    return dp_plan_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (min_expense_local_var) {
        free(min_expense_local_var);
        min_expense_local_var = NULL;
    }
    return NULL;

}
