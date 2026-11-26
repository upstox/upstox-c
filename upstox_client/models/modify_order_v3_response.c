#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modify_order_v3_response.h"


char* modify_order_v3_response_status_ToString(upstox_client_modify_order_v3_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_modify_order_v3_response_STATUS_e modify_order_v3_response_status_FromString(char* status){
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

static modify_order_v3_response_t *modify_order_v3_response_create_internal(
    upstox_client_modify_order_v3_response_STATUS_e status,
    modify_order_data_t *data,
    order_metadata_t *metadata
    ) {
    modify_order_v3_response_t *modify_order_v3_response_local_var = malloc(sizeof(modify_order_v3_response_t));
    if (!modify_order_v3_response_local_var) {
        return NULL;
    }
    memset(modify_order_v3_response_local_var, 0, sizeof(modify_order_v3_response_t));
    modify_order_v3_response_local_var->_library_owned = 1;
    modify_order_v3_response_local_var->status = status;
    modify_order_v3_response_local_var->data = data;
    modify_order_v3_response_local_var->metadata = metadata;
    return modify_order_v3_response_local_var;
}

modify_order_v3_response_t *modify_order_v3_response_create(
    upstox_client_modify_order_v3_response_STATUS_e status,
    modify_order_data_t *data,
    order_metadata_t *metadata
    ) {
    modify_order_v3_response_t *result = modify_order_v3_response_create_internal (
        status,
        data,
        metadata
        );
    if (!result) {
    }
    return result;
}

void modify_order_v3_response_free(modify_order_v3_response_t *modify_order_v3_response) {
    if(NULL == modify_order_v3_response){
        return ;
    }
    if(modify_order_v3_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "modify_order_v3_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (modify_order_v3_response->data) {
        modify_order_data_free(modify_order_v3_response->data);
        modify_order_v3_response->data = NULL;
    }
    if (modify_order_v3_response->metadata) {
        order_metadata_free(modify_order_v3_response->metadata);
        modify_order_v3_response->metadata = NULL;
    }
    free(modify_order_v3_response);
}

cJSON *modify_order_v3_response_convertToJSON(modify_order_v3_response_t *modify_order_v3_response) {
    cJSON *item = cJSON_CreateObject();

    // modify_order_v3_response->status
    if(modify_order_v3_response->status != upstox_client_modify_order_v3_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", modify_order_v3_response_status_ToString(modify_order_v3_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // modify_order_v3_response->data
    if(modify_order_v3_response->data) {
    cJSON *data_local_JSON = modify_order_data_convertToJSON(modify_order_v3_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // modify_order_v3_response->metadata
    if(modify_order_v3_response->metadata) {
    cJSON *metadata_local_JSON = order_metadata_convertToJSON(modify_order_v3_response->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

modify_order_v3_response_t *modify_order_v3_response_parseFromJSON(cJSON *modify_order_v3_responseJSON){

    modify_order_v3_response_t *modify_order_v3_response_local_var = NULL;

    // define the local variable for modify_order_v3_response->data
    modify_order_data_t *data_local_nonprim = NULL;

    // define the local variable for modify_order_v3_response->metadata
    order_metadata_t *metadata_local_nonprim = NULL;

    // modify_order_v3_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(modify_order_v3_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_modify_order_v3_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = modify_order_v3_response_status_FromString(status->valuestring);
    }

    // modify_order_v3_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(modify_order_v3_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = modify_order_data_parseFromJSON(data); //nonprimitive
    }

    // modify_order_v3_response->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(modify_order_v3_responseJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = order_metadata_parseFromJSON(metadata); //nonprimitive
    }



    modify_order_v3_response_local_var = modify_order_v3_response_create_internal (
        status ? statusVariable : upstox_client_modify_order_v3_response_STATUS_NULL,
        data ? data_local_nonprim : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    if (!modify_order_v3_response_local_var) {
        goto end;
    }

    return modify_order_v3_response_local_var;
end:
    if (data_local_nonprim) {
        modify_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        order_metadata_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
