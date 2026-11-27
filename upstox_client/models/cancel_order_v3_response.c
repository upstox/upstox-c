#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_order_v3_response.h"


char* cancel_order_v3_response_status_ToString(upstox_client_cancel_order_v3_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_cancel_order_v3_response_STATUS_e cancel_order_v3_response_status_FromString(char* status){
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

static cancel_order_v3_response_t *cancel_order_v3_response_create_internal(
    upstox_client_cancel_order_v3_response_STATUS_e status,
    cancel_order_data_t *data,
    order_metadata_t *metadata
    ) {
    cancel_order_v3_response_t *cancel_order_v3_response_local_var = malloc(sizeof(cancel_order_v3_response_t));
    if (!cancel_order_v3_response_local_var) {
        return NULL;
    }
    memset(cancel_order_v3_response_local_var, 0, sizeof(cancel_order_v3_response_t));
    cancel_order_v3_response_local_var->_library_owned = 1;
    cancel_order_v3_response_local_var->status = status;
    cancel_order_v3_response_local_var->data = data;
    cancel_order_v3_response_local_var->metadata = metadata;
    return cancel_order_v3_response_local_var;
}

cancel_order_v3_response_t *cancel_order_v3_response_create(
    upstox_client_cancel_order_v3_response_STATUS_e status,
    cancel_order_data_t *data,
    order_metadata_t *metadata
    ) {
    cancel_order_v3_response_t *result = cancel_order_v3_response_create_internal (
        status,
        data,
        metadata
        );
    if (!result) {
    }
    return result;
}

void cancel_order_v3_response_free(cancel_order_v3_response_t *cancel_order_v3_response) {
    if(NULL == cancel_order_v3_response){
        return ;
    }
    if(cancel_order_v3_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_order_v3_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_order_v3_response->data) {
        cancel_order_data_free(cancel_order_v3_response->data);
        cancel_order_v3_response->data = NULL;
    }
    if (cancel_order_v3_response->metadata) {
        order_metadata_free(cancel_order_v3_response->metadata);
        cancel_order_v3_response->metadata = NULL;
    }
    free(cancel_order_v3_response);
}

cJSON *cancel_order_v3_response_convertToJSON(cancel_order_v3_response_t *cancel_order_v3_response) {
    cJSON *item = cJSON_CreateObject();

    // cancel_order_v3_response->status
    if(cancel_order_v3_response->status != upstox_client_cancel_order_v3_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", cancel_order_v3_response_status_ToString(cancel_order_v3_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cancel_order_v3_response->data
    if(cancel_order_v3_response->data) {
    cJSON *data_local_JSON = cancel_order_data_convertToJSON(cancel_order_v3_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cancel_order_v3_response->metadata
    if(cancel_order_v3_response->metadata) {
    cJSON *metadata_local_JSON = order_metadata_convertToJSON(cancel_order_v3_response->metadata);
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

cancel_order_v3_response_t *cancel_order_v3_response_parseFromJSON(cJSON *cancel_order_v3_responseJSON){

    cancel_order_v3_response_t *cancel_order_v3_response_local_var = NULL;

    // define the local variable for cancel_order_v3_response->data
    cancel_order_data_t *data_local_nonprim = NULL;

    // define the local variable for cancel_order_v3_response->metadata
    order_metadata_t *metadata_local_nonprim = NULL;

    // cancel_order_v3_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cancel_order_v3_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_cancel_order_v3_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = cancel_order_v3_response_status_FromString(status->valuestring);
    }

    // cancel_order_v3_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(cancel_order_v3_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = cancel_order_data_parseFromJSON(data); //nonprimitive
    }

    // cancel_order_v3_response->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(cancel_order_v3_responseJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = order_metadata_parseFromJSON(metadata); //nonprimitive
    }



    cancel_order_v3_response_local_var = cancel_order_v3_response_create_internal (
        status ? statusVariable : upstox_client_cancel_order_v3_response_STATUS_NULL,
        data ? data_local_nonprim : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    if (!cancel_order_v3_response_local_var) {
        goto end;
    }

    return cancel_order_v3_response_local_var;
end:
    if (data_local_nonprim) {
        cancel_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        order_metadata_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
