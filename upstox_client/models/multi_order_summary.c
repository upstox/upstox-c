#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_summary.h"



static multi_order_summary_t *multi_order_summary_create_internal(
    int *total,
    int *success,
    int *error,
    int *payload_error
    ) {
    multi_order_summary_t *multi_order_summary_local_var = malloc(sizeof(multi_order_summary_t));
    if (!multi_order_summary_local_var) {
        return NULL;
    }
    memset(multi_order_summary_local_var, 0, sizeof(multi_order_summary_t));
    multi_order_summary_local_var->_library_owned = 1;
    multi_order_summary_local_var->total = total;
    multi_order_summary_local_var->success = success;
    multi_order_summary_local_var->error = error;
    multi_order_summary_local_var->payload_error = payload_error;
    return multi_order_summary_local_var;
}

multi_order_summary_t *multi_order_summary_create(
    int *total,
    int *success,
    int *error,
    int *payload_error
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
    int *payload_error_copy = NULL;
    if (payload_error) {
        payload_error_copy = malloc(sizeof(int));
        if (payload_error_copy) *payload_error_copy = *payload_error;
    }
    multi_order_summary_t *result = multi_order_summary_create_internal (
        total_copy,
        success_copy,
        error_copy,
        payload_error_copy
        );
    if (!result) {
        free(total_copy);
        free(success_copy);
        free(error_copy);
        free(payload_error_copy);
    }
    return result;
}

void multi_order_summary_free(multi_order_summary_t *multi_order_summary) {
    if(NULL == multi_order_summary){
        return ;
    }
    if(multi_order_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_summary->total) {
        free(multi_order_summary->total);
        multi_order_summary->total = NULL;
    }
    if (multi_order_summary->success) {
        free(multi_order_summary->success);
        multi_order_summary->success = NULL;
    }
    if (multi_order_summary->error) {
        free(multi_order_summary->error);
        multi_order_summary->error = NULL;
    }
    if (multi_order_summary->payload_error) {
        free(multi_order_summary->payload_error);
        multi_order_summary->payload_error = NULL;
    }
    free(multi_order_summary);
}

cJSON *multi_order_summary_convertToJSON(multi_order_summary_t *multi_order_summary) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_summary->total
    if(multi_order_summary->total) {
    if(cJSON_AddNumberToObject(item, "total", *multi_order_summary->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // multi_order_summary->success
    if(multi_order_summary->success) {
    if(cJSON_AddNumberToObject(item, "success", *multi_order_summary->success) == NULL) {
    goto fail; //Numeric
    }
    }


    // multi_order_summary->error
    if(multi_order_summary->error) {
    if(cJSON_AddNumberToObject(item, "error", *multi_order_summary->error) == NULL) {
    goto fail; //Numeric
    }
    }


    // multi_order_summary->payload_error
    if(multi_order_summary->payload_error) {
    if(cJSON_AddNumberToObject(item, "payload_error", *multi_order_summary->payload_error) == NULL) {
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

multi_order_summary_t *multi_order_summary_parseFromJSON(cJSON *multi_order_summaryJSON){

    multi_order_summary_t *multi_order_summary_local_var = NULL;

    // define the local variable for multi_order_summary->total
    int *total_local_var = NULL;

    // define the local variable for multi_order_summary->success
    int *success_local_var = NULL;

    // define the local variable for multi_order_summary->error
    int *error_local_var = NULL;

    // define the local variable for multi_order_summary->payload_error
    int *payload_error_local_var = NULL;

    // multi_order_summary->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(multi_order_summaryJSON, "total");
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

    // multi_order_summary->success
    cJSON *success = cJSON_GetObjectItemCaseSensitive(multi_order_summaryJSON, "success");
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

    // multi_order_summary->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(multi_order_summaryJSON, "error");
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

    // multi_order_summary->payload_error
    cJSON *payload_error = cJSON_GetObjectItemCaseSensitive(multi_order_summaryJSON, "payload_error");
    if (cJSON_IsNull(payload_error)) {
        payload_error = NULL;
    }
    if (payload_error) { 
    if(!cJSON_IsNumber(payload_error))
    {
    goto end; //Numeric
    }
    payload_error_local_var = malloc(sizeof(int));
    if(!payload_error_local_var)
    {
        goto end;
    }
    *payload_error_local_var = payload_error->valuedouble;
    }



    multi_order_summary_local_var = multi_order_summary_create_internal (
        total_local_var,
        success_local_var,
        error_local_var,
        payload_error_local_var
        );

    if (!multi_order_summary_local_var) {
        goto end;
    }

    return multi_order_summary_local_var;
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
    if (payload_error_local_var) {
        free(payload_error_local_var);
        payload_error_local_var = NULL;
    }
    return NULL;

}
