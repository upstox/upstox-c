#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "batch_execution_summary.h"



static batch_execution_summary_t *batch_execution_summary_create_internal(
    int *total,
    int *success,
    int *error
    ) {
    batch_execution_summary_t *batch_execution_summary_local_var = malloc(sizeof(batch_execution_summary_t));
    if (!batch_execution_summary_local_var) {
        return NULL;
    }
    memset(batch_execution_summary_local_var, 0, sizeof(batch_execution_summary_t));
    batch_execution_summary_local_var->_library_owned = 1;
    batch_execution_summary_local_var->total = total;
    batch_execution_summary_local_var->success = success;
    batch_execution_summary_local_var->error = error;
    return batch_execution_summary_local_var;
}

batch_execution_summary_t *batch_execution_summary_create(
    int *total,
    int *success,
    int *error
    ) {
    int *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(int));
        if (total_copy) *total_copy = *total;
    }
    int *success_copy = NULL;
    if (success) {
        success_copy = malloc(sizeof(int));
        if (success_copy) *success_copy = *success;
    }
    int *error_copy = NULL;
    if (error) {
        error_copy = malloc(sizeof(int));
        if (error_copy) *error_copy = *error;
    }
    batch_execution_summary_t *result = batch_execution_summary_create_internal (
        total_copy,
        success_copy,
        error_copy
        );
    if (!result) {
        free(total_copy);
        free(success_copy);
        free(error_copy);
    }
    return result;
}

void batch_execution_summary_free(batch_execution_summary_t *batch_execution_summary) {
    if(NULL == batch_execution_summary){
        return ;
    }
    if(batch_execution_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "batch_execution_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (batch_execution_summary->total) {
        free(batch_execution_summary->total);
        batch_execution_summary->total = NULL;
    }
    if (batch_execution_summary->success) {
        free(batch_execution_summary->success);
        batch_execution_summary->success = NULL;
    }
    if (batch_execution_summary->error) {
        free(batch_execution_summary->error);
        batch_execution_summary->error = NULL;
    }
    free(batch_execution_summary);
}

cJSON *batch_execution_summary_convertToJSON(batch_execution_summary_t *batch_execution_summary) {
    cJSON *item = cJSON_CreateObject();

    // batch_execution_summary->total
    if(batch_execution_summary->total) {
    if(cJSON_AddNumberToObject(item, "total", *batch_execution_summary->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // batch_execution_summary->success
    if(batch_execution_summary->success) {
    if(cJSON_AddNumberToObject(item, "success", *batch_execution_summary->success) == NULL) {
    goto fail; //Numeric
    }
    }


    // batch_execution_summary->error
    if(batch_execution_summary->error) {
    if(cJSON_AddNumberToObject(item, "error", *batch_execution_summary->error) == NULL) {
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

batch_execution_summary_t *batch_execution_summary_parseFromJSON(cJSON *batch_execution_summaryJSON){

    batch_execution_summary_t *batch_execution_summary_local_var = NULL;

    // define the local variable for batch_execution_summary->total
    int *total_local_var = NULL;

    // define the local variable for batch_execution_summary->success
    int *success_local_var = NULL;

    // define the local variable for batch_execution_summary->error
    int *error_local_var = NULL;

    // batch_execution_summary->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(batch_execution_summaryJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(int));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;
    }

    // batch_execution_summary->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(batch_execution_summaryJSON, "success");
    if (cJSON_IsNull(success)) {
        success = NULL;
    }
    if (success) { 
    if(!cJSON_IsNumber(success))
    {
    goto end; //Numeric
    }
    success_local_var = malloc(sizeof(int));
    if(!success_local_var)
    {
        goto end;
    }
    *success_local_var = success->valuedouble;
    }

    // batch_execution_summary->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(batch_execution_summaryJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsNumber(error))
    {
    goto end; //Numeric
    }
    error_local_var = malloc(sizeof(int));
    if(!error_local_var)
    {
        goto end;
    }
    *error_local_var = error->valuedouble;
    }



    batch_execution_summary_local_var = batch_execution_summary_create_internal (
        total_local_var,
        success_local_var,
        error_local_var
        );

    if (!batch_execution_summary_local_var) {
        goto end;
    }

    return batch_execution_summary_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (success_local_var) {
        free(success_local_var);
        success_local_var = NULL;
    }
    if (error_local_var) {
        free(error_local_var);
        error_local_var = NULL;
    }
    return NULL;

}
