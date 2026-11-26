#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_response.h"


char* analytics_response_status_ToString(upstox_client_analytics_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_analytics_response_STATUS_e analytics_response_status_FromString(char* status){
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

static analytics_response_t *analytics_response_create_internal(
    upstox_client_analytics_response_STATUS_e status,
    object_t *data
    ) {
    analytics_response_t *analytics_response_local_var = malloc(sizeof(analytics_response_t));
    if (!analytics_response_local_var) {
        return NULL;
    }
    memset(analytics_response_local_var, 0, sizeof(analytics_response_t));
    analytics_response_local_var->_library_owned = 1;
    analytics_response_local_var->status = status;
    analytics_response_local_var->data = data;
    return analytics_response_local_var;
}

analytics_response_t *analytics_response_create(
    upstox_client_analytics_response_STATUS_e status,
    object_t *data
    ) {
    analytics_response_t *result = analytics_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void analytics_response_free(analytics_response_t *analytics_response) {
    if(NULL == analytics_response){
        return ;
    }
    if(analytics_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "analytics_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (analytics_response->data) {
        object_free(analytics_response->data);
        analytics_response->data = NULL;
    }
    free(analytics_response);
}

cJSON *analytics_response_convertToJSON(analytics_response_t *analytics_response) {
    cJSON *item = cJSON_CreateObject();

    // analytics_response->status
    if(analytics_response->status != upstox_client_analytics_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", analytics_response_status_ToString(analytics_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // analytics_response->data
    if(analytics_response->data) {
    cJSON *data_object = object_convertToJSON(analytics_response->data);
    if(data_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_object);
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

analytics_response_t *analytics_response_parseFromJSON(cJSON *analytics_responseJSON){

    analytics_response_t *analytics_response_local_var = NULL;

    // analytics_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(analytics_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_analytics_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = analytics_response_status_FromString(status->valuestring);
    }

    // analytics_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(analytics_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }



    analytics_response_local_var = analytics_response_create_internal (
        status ? statusVariable : upstox_client_analytics_response_STATUS_NULL,
        data ? data_local_object : NULL
        );

    if (!analytics_response_local_var) {
        goto end;
    }

    return analytics_response_local_var;
end:
    return NULL;

}
