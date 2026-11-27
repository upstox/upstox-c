#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_gateway_error_response.h"


char* api_gateway_error_response_status_ToString(upstox_client_api_gateway_error_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_api_gateway_error_response_STATUS_e api_gateway_error_response_status_FromString(char* status){
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

static api_gateway_error_response_t *api_gateway_error_response_create_internal(
    upstox_client_api_gateway_error_response_STATUS_e status,
    list_t *errors
    ) {
    api_gateway_error_response_t *api_gateway_error_response_local_var = malloc(sizeof(api_gateway_error_response_t));
    if (!api_gateway_error_response_local_var) {
        return NULL;
    }
    memset(api_gateway_error_response_local_var, 0, sizeof(api_gateway_error_response_t));
    api_gateway_error_response_local_var->_library_owned = 1;
    api_gateway_error_response_local_var->status = status;
    api_gateway_error_response_local_var->errors = errors;
    return api_gateway_error_response_local_var;
}

api_gateway_error_response_t *api_gateway_error_response_create(
    upstox_client_api_gateway_error_response_STATUS_e status,
    list_t *errors
    ) {
    api_gateway_error_response_t *result = api_gateway_error_response_create_internal (
        status,
        errors
        );
    if (!result) {
    }
    return result;
}

void api_gateway_error_response_free(api_gateway_error_response_t *api_gateway_error_response) {
    if(NULL == api_gateway_error_response){
        return ;
    }
    if(api_gateway_error_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_gateway_error_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_gateway_error_response->errors) {
        list_ForEach(listEntry, api_gateway_error_response->errors) {
            problem_free(listEntry->data);
        }
        list_freeList(api_gateway_error_response->errors);
        api_gateway_error_response->errors = NULL;
    }
    free(api_gateway_error_response);
}

cJSON *api_gateway_error_response_convertToJSON(api_gateway_error_response_t *api_gateway_error_response) {
    cJSON *item = cJSON_CreateObject();

    // api_gateway_error_response->status
    if(api_gateway_error_response->status != upstox_client_api_gateway_error_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", api_gateway_error_response_status_ToString(api_gateway_error_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // api_gateway_error_response->errors
    if(api_gateway_error_response->errors) {
    cJSON *errors = cJSON_AddArrayToObject(item, "errors");
    if(errors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *errorsListEntry;
    if (api_gateway_error_response->errors) {
    list_ForEach(errorsListEntry, api_gateway_error_response->errors) {
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

api_gateway_error_response_t *api_gateway_error_response_parseFromJSON(cJSON *api_gateway_error_responseJSON){

    api_gateway_error_response_t *api_gateway_error_response_local_var = NULL;

    // define the local list for api_gateway_error_response->errors
    list_t *errorsList = NULL;

    // api_gateway_error_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(api_gateway_error_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_api_gateway_error_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = api_gateway_error_response_status_FromString(status->valuestring);
    }

    // api_gateway_error_response->errors
    cJSON *errors = cJSON_GetObjectItemCaseSensitive(api_gateway_error_responseJSON, "errors");
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



    api_gateway_error_response_local_var = api_gateway_error_response_create_internal (
        status ? statusVariable : upstox_client_api_gateway_error_response_STATUS_NULL,
        errors ? errorsList : NULL
        );

    if (!api_gateway_error_response_local_var) {
        goto end;
    }

    return api_gateway_error_response_local_var;
end:
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
