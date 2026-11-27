#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_or_exit_multi_order_response.h"


char* cancel_or_exit_multi_order_response_status_ToString(upstox_client_cancel_or_exit_multi_order_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_cancel_or_exit_multi_order_response_STATUS_e cancel_or_exit_multi_order_response_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "success", "error", "partial_success" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_create_internal(
    upstox_client_cancel_or_exit_multi_order_response_STATUS_e status,
    cancel_or_exit_multi_order_data_t *data,
    list_t *errors,
    batch_execution_summary_t *summary
    ) {
    cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_local_var = malloc(sizeof(cancel_or_exit_multi_order_response_t));
    if (!cancel_or_exit_multi_order_response_local_var) {
        return NULL;
    }
    memset(cancel_or_exit_multi_order_response_local_var, 0, sizeof(cancel_or_exit_multi_order_response_t));
    cancel_or_exit_multi_order_response_local_var->_library_owned = 1;
    cancel_or_exit_multi_order_response_local_var->status = status;
    cancel_or_exit_multi_order_response_local_var->data = data;
    cancel_or_exit_multi_order_response_local_var->errors = errors;
    cancel_or_exit_multi_order_response_local_var->summary = summary;
    return cancel_or_exit_multi_order_response_local_var;
}

cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_create(
    upstox_client_cancel_or_exit_multi_order_response_STATUS_e status,
    cancel_or_exit_multi_order_data_t *data,
    list_t *errors,
    batch_execution_summary_t *summary
    ) {
    cancel_or_exit_multi_order_response_t *result = cancel_or_exit_multi_order_response_create_internal (
        status,
        data,
        errors,
        summary
        );
    if (!result) {
    }
    return result;
}

void cancel_or_exit_multi_order_response_free(cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response) {
    if(NULL == cancel_or_exit_multi_order_response){
        return ;
    }
    if(cancel_or_exit_multi_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_or_exit_multi_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_or_exit_multi_order_response->data) {
        cancel_or_exit_multi_order_data_free(cancel_or_exit_multi_order_response->data);
        cancel_or_exit_multi_order_response->data = NULL;
    }
    if (cancel_or_exit_multi_order_response->errors) {
        list_ForEach(listEntry, cancel_or_exit_multi_order_response->errors) {
            cancel_or_exit_order_error_data_free(listEntry->data);
        }
        list_freeList(cancel_or_exit_multi_order_response->errors);
        cancel_or_exit_multi_order_response->errors = NULL;
    }
    if (cancel_or_exit_multi_order_response->summary) {
        batch_execution_summary_free(cancel_or_exit_multi_order_response->summary);
        cancel_or_exit_multi_order_response->summary = NULL;
    }
    free(cancel_or_exit_multi_order_response);
}

cJSON *cancel_or_exit_multi_order_response_convertToJSON(cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response) {
    cJSON *item = cJSON_CreateObject();

    // cancel_or_exit_multi_order_response->status
    if(cancel_or_exit_multi_order_response->status != upstox_client_cancel_or_exit_multi_order_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", cancel_or_exit_multi_order_response_status_ToString(cancel_or_exit_multi_order_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cancel_or_exit_multi_order_response->data
    if(cancel_or_exit_multi_order_response->data) {
    cJSON *data_local_JSON = cancel_or_exit_multi_order_data_convertToJSON(cancel_or_exit_multi_order_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cancel_or_exit_multi_order_response->errors
    if(cancel_or_exit_multi_order_response->errors) {
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (cancel_or_exit_multi_order_response->errors) {
    list_ForEach(errorsListEntry, cancel_or_exit_multi_order_response->errors) {
    cJSON *itemLocal = cancel_or_exit_order_error_data_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }
    }


    // cancel_or_exit_multi_order_response->summary
    if(cancel_or_exit_multi_order_response->summary) {
    cJSON *summary_local_JSON = batch_execution_summary_convertToJSON(cancel_or_exit_multi_order_response->summary);
    if(summary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "summary", summary_local_JSON);
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

cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_parseFromJSON(cJSON *cancel_or_exit_multi_order_responseJSON){

    cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_local_var = NULL;

    // define the local variable for cancel_or_exit_multi_order_response->data
    cancel_or_exit_multi_order_data_t *data_local_nonprim = NULL;

    // define the local list for cancel_or_exit_multi_order_response->errors
    list_t *errorsList = NULL;

    // define the local variable for cancel_or_exit_multi_order_response->summary
    batch_execution_summary_t *summary_local_nonprim = NULL;

    // cancel_or_exit_multi_order_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_multi_order_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_cancel_or_exit_multi_order_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = cancel_or_exit_multi_order_response_status_FromString(status->valuestring);
    }

    // cancel_or_exit_multi_order_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_multi_order_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = cancel_or_exit_multi_order_data_parseFromJSON(data); //nonprimitive
    }

    // cancel_or_exit_multi_order_response->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_multi_order_responseJSON, "errors");
    if (cJSON_IsNull(errors)) {
        errors = NULL;
    }
    if (errors) { 
    cJSON *errors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(errors)){
        goto end; //nonprimitive container
    }

    errorsList = list_createList();

    cJSON_ArrayForEach(errors_local_nonprimitive,errors )
    {
        if(!cJSON_IsObject(errors_local_nonprimitive)){
            goto end;
        }
        cancel_or_exit_order_error_data_t *errorsItem = cancel_or_exit_order_error_data_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }
    }

    // cancel_or_exit_multi_order_response->summary
    cJSON *summary = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_multi_order_responseJSON, "summary");
    if (cJSON_IsNull(summary)) {
        summary = NULL;
    }
    if (summary) { 
    summary_local_nonprim = batch_execution_summary_parseFromJSON(summary); //nonprimitive
    }



    cancel_or_exit_multi_order_response_local_var = cancel_or_exit_multi_order_response_create_internal (
        status ? statusVariable : upstox_client_cancel_or_exit_multi_order_response_STATUS_NULL,
        data ? data_local_nonprim : NULL,
        errors ? errorsList : NULL,
        summary ? summary_local_nonprim : NULL
        );

    if (!cancel_or_exit_multi_order_response_local_var) {
        goto end;
    }

    return cancel_or_exit_multi_order_response_local_var;
end:
    if (data_local_nonprim) {
        cancel_or_exit_multi_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            cancel_or_exit_order_error_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    if (summary_local_nonprim) {
        batch_execution_summary_free(summary_local_nonprim);
        summary_local_nonprim = NULL;
    }
    return NULL;

}
