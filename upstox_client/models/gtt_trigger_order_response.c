#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_trigger_order_response.h"


char* gtt_trigger_order_response_status_ToString(upstox_client_gtt_trigger_order_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_gtt_trigger_order_response_STATUS_e gtt_trigger_order_response_status_FromString(char* status){
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

static gtt_trigger_order_response_t *gtt_trigger_order_response_create_internal(
    upstox_client_gtt_trigger_order_response_STATUS_e status,
    gtt_order_data_t *data,
    order_metadata_t *metadata
    ) {
    gtt_trigger_order_response_t *gtt_trigger_order_response_local_var = malloc(sizeof(gtt_trigger_order_response_t));
    if (!gtt_trigger_order_response_local_var) {
        return NULL;
    }
    memset(gtt_trigger_order_response_local_var, 0, sizeof(gtt_trigger_order_response_t));
    gtt_trigger_order_response_local_var->_library_owned = 1;
    gtt_trigger_order_response_local_var->status = status;
    gtt_trigger_order_response_local_var->data = data;
    gtt_trigger_order_response_local_var->metadata = metadata;
    return gtt_trigger_order_response_local_var;
}

gtt_trigger_order_response_t *gtt_trigger_order_response_create(
    upstox_client_gtt_trigger_order_response_STATUS_e status,
    gtt_order_data_t *data,
    order_metadata_t *metadata
    ) {
    gtt_trigger_order_response_t *result = gtt_trigger_order_response_create_internal (
        status,
        data,
        metadata
        );
    if (!result) {
    }
    return result;
}

void gtt_trigger_order_response_free(gtt_trigger_order_response_t *gtt_trigger_order_response) {
    if(NULL == gtt_trigger_order_response){
        return ;
    }
    if(gtt_trigger_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_trigger_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_trigger_order_response->data) {
        gtt_order_data_free(gtt_trigger_order_response->data);
        gtt_trigger_order_response->data = NULL;
    }
    if (gtt_trigger_order_response->metadata) {
        order_metadata_free(gtt_trigger_order_response->metadata);
        gtt_trigger_order_response->metadata = NULL;
    }
    free(gtt_trigger_order_response);
}

cJSON *gtt_trigger_order_response_convertToJSON(gtt_trigger_order_response_t *gtt_trigger_order_response) {
    cJSON *item = cJSON_CreateObject();

    // gtt_trigger_order_response->status
    if(gtt_trigger_order_response->status != upstox_client_gtt_trigger_order_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", gtt_trigger_order_response_status_ToString(gtt_trigger_order_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // gtt_trigger_order_response->data
    if(gtt_trigger_order_response->data) {
    cJSON *data_local_JSON = gtt_order_data_convertToJSON(gtt_trigger_order_response->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // gtt_trigger_order_response->metadata
    if(gtt_trigger_order_response->metadata) {
    cJSON *metadata_local_JSON = order_metadata_convertToJSON(gtt_trigger_order_response->metadata);
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

gtt_trigger_order_response_t *gtt_trigger_order_response_parseFromJSON(cJSON *gtt_trigger_order_responseJSON){

    gtt_trigger_order_response_t *gtt_trigger_order_response_local_var = NULL;

    // define the local variable for gtt_trigger_order_response->data
    gtt_order_data_t *data_local_nonprim = NULL;

    // define the local variable for gtt_trigger_order_response->metadata
    order_metadata_t *metadata_local_nonprim = NULL;

    // gtt_trigger_order_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(gtt_trigger_order_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_gtt_trigger_order_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = gtt_trigger_order_response_status_FromString(status->valuestring);
    }

    // gtt_trigger_order_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(gtt_trigger_order_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = gtt_order_data_parseFromJSON(data); //nonprimitive
    }

    // gtt_trigger_order_response->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(gtt_trigger_order_responseJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = order_metadata_parseFromJSON(metadata); //nonprimitive
    }



    gtt_trigger_order_response_local_var = gtt_trigger_order_response_create_internal (
        status ? statusVariable : upstox_client_gtt_trigger_order_response_STATUS_NULL,
        data ? data_local_nonprim : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    if (!gtt_trigger_order_response_local_var) {
        goto end;
    }

    return gtt_trigger_order_response_local_var;
end:
    if (data_local_nonprim) {
        gtt_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        order_metadata_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
