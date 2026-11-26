#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_ip_response.h"


char* user_ip_response_status_ToString(upstox_client_user_ip_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_user_ip_response_STATUS_e user_ip_response_status_FromString(char* status){
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

static user_ip_response_t *user_ip_response_create_internal(
    upstox_client_user_ip_response_STATUS_e status,
    user_ip_response_data_t *data
    ) {
    user_ip_response_t *user_ip_response_local_var = malloc(sizeof(user_ip_response_t));
    if (!user_ip_response_local_var) {
        return NULL;
    }
    memset(user_ip_response_local_var, 0, sizeof(user_ip_response_t));
    user_ip_response_local_var->_library_owned = 1;
    user_ip_response_local_var->status = status;
    user_ip_response_local_var->data = data;
    return user_ip_response_local_var;
}

user_ip_response_t *user_ip_response_create(
    upstox_client_user_ip_response_STATUS_e status,
    user_ip_response_data_t *data
    ) {
    user_ip_response_t *result = user_ip_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void user_ip_response_free(user_ip_response_t *user_ip_response) {
    if(NULL == user_ip_response){
        return ;
    }
    if(user_ip_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_ip_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_ip_response->data) {
        user_ip_response_data_free(user_ip_response->data);
        user_ip_response->data = NULL;
    }
    free(user_ip_response);
}

cJSON *user_ip_response_convertToJSON(user_ip_response_t *user_ip_response) {
    cJSON *item = cJSON_CreateObject();

    // user_ip_response->status
    if(user_ip_response->status != upstox_client_user_ip_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", user_ip_response_status_ToString(user_ip_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // user_ip_response->data
    if(user_ip_response->data) {
    cJSON *data_local_JSON = user_ip_response_data_convertToJSON(user_ip_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
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

user_ip_response_t *user_ip_response_parseFromJSON(cJSON *user_ip_responseJSON){

    user_ip_response_t *user_ip_response_local_var = NULL;

    // define the local variable for user_ip_response->data
    user_ip_response_data_t *data_local_nonprim = NULL;

    // user_ip_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(user_ip_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_user_ip_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = user_ip_response_status_FromString(status->valuestring);
    }

    // user_ip_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(user_ip_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = user_ip_response_data_parseFromJSON(data); //nonprimitive
    }



    user_ip_response_local_var = user_ip_response_create_internal (
        status ? statusVariable : upstox_client_user_ip_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!user_ip_response_local_var) {
        goto end;
    }

    return user_ip_response_local_var;
end:
    if (data_local_nonprim) {
        user_ip_response_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
