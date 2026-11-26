#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_profile_response.h"


char* get_profile_response_status_ToString(upstox_client_get_profile_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_profile_response_STATUS_e get_profile_response_status_FromString(char* status){
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

static get_profile_response_t *get_profile_response_create_internal(
    upstox_client_get_profile_response_STATUS_e status,
    profile_data_t *data
    ) {
    get_profile_response_t *get_profile_response_local_var = malloc(sizeof(get_profile_response_t));
    if (!get_profile_response_local_var) {
        return NULL;
    }
    memset(get_profile_response_local_var, 0, sizeof(get_profile_response_t));
    get_profile_response_local_var->_library_owned = 1;
    get_profile_response_local_var->status = status;
    get_profile_response_local_var->data = data;
    return get_profile_response_local_var;
}

get_profile_response_t *get_profile_response_create(
    upstox_client_get_profile_response_STATUS_e status,
    profile_data_t *data
    ) {
    get_profile_response_t *result = get_profile_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void get_profile_response_free(get_profile_response_t *get_profile_response) {
    if(NULL == get_profile_response){
        return ;
    }
    if(get_profile_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_profile_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_profile_response->data) {
        profile_data_free(get_profile_response->data);
        get_profile_response->data = NULL;
    }
    free(get_profile_response);
}

cJSON *get_profile_response_convertToJSON(get_profile_response_t *get_profile_response) {
    cJSON *item = cJSON_CreateObject();

    // get_profile_response->status
    if(get_profile_response->status != upstox_client_get_profile_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_profile_response_status_ToString(get_profile_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_profile_response->data
    if(get_profile_response->data) {
    cJSON *data_local_JSON = profile_data_convertToJSON(get_profile_response->data);
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

get_profile_response_t *get_profile_response_parseFromJSON(cJSON *get_profile_responseJSON){

    get_profile_response_t *get_profile_response_local_var = NULL;

    // define the local variable for get_profile_response->data
    profile_data_t *data_local_nonprim = NULL;

    // get_profile_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_profile_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_profile_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_profile_response_status_FromString(status->valuestring);
    }

    // get_profile_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_profile_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = profile_data_parseFromJSON(data); //nonprimitive
    }



    get_profile_response_local_var = get_profile_response_create_internal (
        status ? statusVariable : upstox_client_get_profile_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!get_profile_response_local_var) {
        goto end;
    }

    return get_profile_response_local_var;
end:
    if (data_local_nonprim) {
        profile_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
