#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_response.h"


char* multi_order_response_status_ToString(upstox_client_multi_order_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_multi_order_response_STATUS_e multi_order_response_status_FromString(char* status){
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

static multi_order_response_t *multi_order_response_create_internal(
    upstox_client_multi_order_response_STATUS_e status,
    list_t *data,
    list_t *errors,
    multi_order_summary_t *summary
    ) {
    multi_order_response_t *multi_order_response_local_var = malloc(sizeof(multi_order_response_t));
    if (!multi_order_response_local_var) {
        return NULL;
    }
    memset(multi_order_response_local_var, 0, sizeof(multi_order_response_t));
    multi_order_response_local_var->_library_owned = 1;
    multi_order_response_local_var->status = status;
    multi_order_response_local_var->data = data;
    multi_order_response_local_var->errors = errors;
    multi_order_response_local_var->summary = summary;
    return multi_order_response_local_var;
}

multi_order_response_t *multi_order_response_create(
    upstox_client_multi_order_response_STATUS_e status,
    list_t *data,
    list_t *errors,
    multi_order_summary_t *summary
    ) {
    multi_order_response_t *result = multi_order_response_create_internal (
        status,
        data,
        errors,
        summary
        );
    if (!result) {
    }
    return result;
}

void multi_order_response_free(multi_order_response_t *multi_order_response) {
    if(NULL == multi_order_response){
        return ;
    }
    if(multi_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_response->data) {
        list_ForEach(listEntry, multi_order_response->data) {
            multi_order_data_free(listEntry->data);
        }
        list_freeList(multi_order_response->data);
        multi_order_response->data = NULL;
    }
    if (multi_order_response->errors) {
        list_ForEach(listEntry, multi_order_response->errors) {
            multi_order_error_free(listEntry->data);
        }
        list_freeList(multi_order_response->errors);
        multi_order_response->errors = NULL;
    }
    if (multi_order_response->summary) {
        multi_order_summary_free(multi_order_response->summary);
        multi_order_response->summary = NULL;
    }
    free(multi_order_response);
}

cJSON *multi_order_response_convertToJSON(multi_order_response_t *multi_order_response) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_response->status
    if(multi_order_response->status != upstox_client_multi_order_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", multi_order_response_status_ToString(multi_order_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // multi_order_response->data
    if(multi_order_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (multi_order_response->data) {
    list_ForEach(dataListEntry, multi_order_response->data) {
    cJSON *itemLocal = multi_order_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // multi_order_response->errors
    if(multi_order_response->errors) {
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (multi_order_response->errors) {
    list_ForEach(errorsListEntry, multi_order_response->errors) {
    cJSON *itemLocal = multi_order_error_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }
    }


    // multi_order_response->summary
    if(multi_order_response->summary) {
    cJSON *summary_local_JSON = multi_order_summary_convertToJSON(multi_order_response->summary);
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

multi_order_response_t *multi_order_response_parseFromJSON(cJSON *multi_order_responseJSON){

    multi_order_response_t *multi_order_response_local_var = NULL;

    // define the local list for multi_order_response->data
    list_t *dataList = NULL;

    // define the local list for multi_order_response->errors
    list_t *errorsList = NULL;

    // define the local variable for multi_order_response->summary
    multi_order_summary_t *summary_local_nonprim = NULL;

    // multi_order_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(multi_order_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_multi_order_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = multi_order_response_status_FromString(status->valuestring);
    }

    // multi_order_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(multi_order_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_createList();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        multi_order_data_t *dataItem = multi_order_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // multi_order_response->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(multi_order_responseJSON, "errors");
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
        multi_order_error_t *errorsItem = multi_order_error_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }
    }

    // multi_order_response->summary
    cJSON *summary = cJSON_GetObjectItemCaseSensitive(multi_order_responseJSON, "summary");
    if (cJSON_IsNull(summary)) {
        summary = NULL;
    }
    if (summary) { 
    summary_local_nonprim = multi_order_summary_parseFromJSON(summary); //nonprimitive
    }



    multi_order_response_local_var = multi_order_response_create_internal (
        status ? statusVariable : upstox_client_multi_order_response_STATUS_NULL,
        data ? dataList : NULL,
        errors ? errorsList : NULL,
        summary ? summary_local_nonprim : NULL
        );

    if (!multi_order_response_local_var) {
        goto end;
    }

    return multi_order_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            multi_order_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            multi_order_error_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    if (summary_local_nonprim) {
        multi_order_summary_free(summary_local_nonprim);
        summary_local_nonprim = NULL;
    }
    return NULL;

}
