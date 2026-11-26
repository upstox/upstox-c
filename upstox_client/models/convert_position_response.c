#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_position_response.h"


char* convert_position_response_status_ToString(upstox_client_convert_position_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_convert_position_response_STATUS_e convert_position_response_status_FromString(char* status){
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

static convert_position_response_t *convert_position_response_create_internal(
    upstox_client_convert_position_response_STATUS_e status,
    convert_position_data_t *data,
    list_t *errors
    ) {
    convert_position_response_t *convert_position_response_local_var = malloc(sizeof(convert_position_response_t));
    if (!convert_position_response_local_var) {
        return NULL;
    }
    memset(convert_position_response_local_var, 0, sizeof(convert_position_response_t));
    convert_position_response_local_var->_library_owned = 1;
    convert_position_response_local_var->status = status;
    convert_position_response_local_var->data = data;
    convert_position_response_local_var->errors = errors;
    return convert_position_response_local_var;
}

convert_position_response_t *convert_position_response_create(
    upstox_client_convert_position_response_STATUS_e status,
    convert_position_data_t *data,
    list_t *errors
    ) {
    convert_position_response_t *result = convert_position_response_create_internal (
        status,
        data,
        errors
        );
    if (!result) {
    }
    return result;
}

void convert_position_response_free(convert_position_response_t *convert_position_response) {
    if(NULL == convert_position_response){
        return ;
    }
    if(convert_position_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_position_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (convert_position_response->data) {
        convert_position_data_free(convert_position_response->data);
        convert_position_response->data = NULL;
    }
    if (convert_position_response->errors) {
        list_ForEach(listEntry, convert_position_response->errors) {
            problem_free(listEntry->data);
        }
        list_freeList(convert_position_response->errors);
        convert_position_response->errors = NULL;
    }
    free(convert_position_response);
}

cJSON *convert_position_response_convertToJSON(convert_position_response_t *convert_position_response) {
    cJSON *item = cJSON_CreateObject();

    // convert_position_response->status
    if(convert_position_response->status != upstox_client_convert_position_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", convert_position_response_status_ToString(convert_position_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // convert_position_response->data
    if(convert_position_response->data) {
    cJSON *data_local_JSON = convert_position_data_convertToJSON(convert_position_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // convert_position_response->errors
    if(convert_position_response->errors) {
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (convert_position_response->errors) {
    list_ForEach(errorsListEntry, convert_position_response->errors) {
    cJSON *itemLocal = problem_convertToJSON(errorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(errors, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

convert_position_response_t *convert_position_response_parseFromJSON(cJSON *convert_position_responseJSON){

    convert_position_response_t *convert_position_response_local_var = NULL;

    // define the local variable for convert_position_response->data
    convert_position_data_t *data_local_nonprim = NULL;

    // define the local list for convert_position_response->errors
    list_t *errorsList = NULL;

    // convert_position_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(convert_position_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_convert_position_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = convert_position_response_status_FromString(status->valuestring);
    }

    // convert_position_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(convert_position_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = convert_position_data_parseFromJSON(data); //nonprimitive
    }

    // convert_position_response->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(convert_position_responseJSON, "errors");
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
        problem_t *errorsItem = problem_parseFromJSON(errors_local_nonprimitive);

        list_addElement(errorsList, errorsItem);
    }
    }



    convert_position_response_local_var = convert_position_response_create_internal (
        status ? statusVariable : upstox_client_convert_position_response_STATUS_NULL,
        data ? data_local_nonprim : NULL,
        errors ? errorsList : NULL
        );

    if (!convert_position_response_local_var) {
        goto end;
    }

    return convert_position_response_local_var;
end:
    if (data_local_nonprim) {
        convert_position_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (errorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, errorsList) {
            problem_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(errorsList);
        errorsList = NULL;
    }
    return NULL;

}
