#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_details_response.h"


char* ipo_details_response_status_ToString(upstox_client_ipo_details_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_ipo_details_response_STATUS_e ipo_details_response_status_FromString(char* status){
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

static ipo_details_response_t *ipo_details_response_create_internal(
    upstox_client_ipo_details_response_STATUS_e status,
    ipo_details_data_t *data
    ) {
    ipo_details_response_t *ipo_details_response_local_var = malloc(sizeof(ipo_details_response_t));
    if (!ipo_details_response_local_var) {
        return NULL;
    }
    memset(ipo_details_response_local_var, 0, sizeof(ipo_details_response_t));
    ipo_details_response_local_var->_library_owned = 1;
    ipo_details_response_local_var->status = status;
    ipo_details_response_local_var->data = data;
    return ipo_details_response_local_var;
}

ipo_details_response_t *ipo_details_response_create(
    upstox_client_ipo_details_response_STATUS_e status,
    ipo_details_data_t *data
    ) {
    ipo_details_response_t *result = ipo_details_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void ipo_details_response_free(ipo_details_response_t *ipo_details_response) {
    if(NULL == ipo_details_response){
        return ;
    }
    if(ipo_details_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_details_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_details_response->data) {
        ipo_details_data_free(ipo_details_response->data);
        ipo_details_response->data = NULL;
    }
    free(ipo_details_response);
}

cJSON *ipo_details_response_convertToJSON(ipo_details_response_t *ipo_details_response) {
    cJSON *item = cJSON_CreateObject();

    // ipo_details_response->status
    if(ipo_details_response->status != upstox_client_ipo_details_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", ipo_details_response_status_ToString(ipo_details_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_details_response->data
    if(ipo_details_response->data) {
    cJSON *data_local_JSON = ipo_details_data_convertToJSON(ipo_details_response->data);
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

ipo_details_response_t *ipo_details_response_parseFromJSON(cJSON *ipo_details_responseJSON){

    ipo_details_response_t *ipo_details_response_local_var = NULL;

    // define the local variable for ipo_details_response->data
    ipo_details_data_t *data_local_nonprim = NULL;

    // ipo_details_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_details_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_ipo_details_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = ipo_details_response_status_FromString(status->valuestring);
    }

    // ipo_details_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(ipo_details_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = ipo_details_data_parseFromJSON(data); //nonprimitive
    }



    ipo_details_response_local_var = ipo_details_response_create_internal (
        status ? statusVariable : upstox_client_ipo_details_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!ipo_details_response_local_var) {
        goto end;
    }

    return ipo_details_response_local_var;
end:
    if (data_local_nonprim) {
        ipo_details_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
