#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "logout_response.h"


char* logout_response_status_ToString(upstox_client_logout_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_logout_response_STATUS_e logout_response_status_FromString(char* status){
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

static logout_response_t *logout_response_create_internal(
    upstox_client_logout_response_STATUS_e status,
    int *data
    ) {
    logout_response_t *logout_response_local_var = malloc(sizeof(logout_response_t));
    if (!logout_response_local_var) {
        return NULL;
    }
    memset(logout_response_local_var, 0, sizeof(logout_response_t));
    logout_response_local_var->_library_owned = 1;
    logout_response_local_var->status = status;
    logout_response_local_var->data = data;
    return logout_response_local_var;
}

logout_response_t *logout_response_create(
    upstox_client_logout_response_STATUS_e status,
    int *data
    ) {
    int *data_copy = NULL;
    if (data) {
        data_copy = malloc(sizeof(int));
        if (data_copy) *data_copy = *data;
    }
    logout_response_t *result = logout_response_create_internal (
        status,
        data_copy
        );
    if (!result) {
        free(data_copy);
    }
    return result;
}

void logout_response_free(logout_response_t *logout_response) {
    if(NULL == logout_response){
        return ;
    }
    if(logout_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "logout_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (logout_response->data) {
        free(logout_response->data);
        logout_response->data = NULL;
    }
    free(logout_response);
}

cJSON *logout_response_convertToJSON(logout_response_t *logout_response) {
    cJSON *item = cJSON_CreateObject();

    // logout_response->status
    if(logout_response->status != upstox_client_logout_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", logout_response_status_ToString(logout_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // logout_response->data
    if(logout_response->data) {
    if(cJSON_AddBoolToObject(item, "data", *logout_response->data) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

logout_response_t *logout_response_parseFromJSON(cJSON *logout_responseJSON){

    logout_response_t *logout_response_local_var = NULL;

    // define the local variable for logout_response->data
    int *data_local_var = NULL;

    // logout_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(logout_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_logout_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = logout_response_status_FromString(status->valuestring);
    }

    // logout_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(logout_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    if(!cJSON_IsBool(data))
    {
    goto end; //Bool
    }
    data_local_var = malloc(sizeof(int));
    if(!data_local_var)
    {
        goto end;
    }
    *data_local_var = data->valueint;
    }



    logout_response_local_var = logout_response_create_internal (
        status ? statusVariable : upstox_client_logout_response_STATUS_NULL,
        data_local_var
        );

    if (!logout_response_local_var) {
        goto end;
    }

    return logout_response_local_var;
end:
    if (data_local_var) {
        free(data_local_var);
        data_local_var = NULL;
    }
    return NULL;

}
