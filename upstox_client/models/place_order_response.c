#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_order_response.h"


char* place_order_response_status_ToString(upstox_client_place_order_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_place_order_response_STATUS_e place_order_response_status_FromString(char* status){
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

static place_order_response_t *place_order_response_create_internal(
    upstox_client_place_order_response_STATUS_e status,
    place_order_data_t *data
    ) {
    place_order_response_t *place_order_response_local_var = malloc(sizeof(place_order_response_t));
    if (!place_order_response_local_var) {
        return NULL;
    }
    memset(place_order_response_local_var, 0, sizeof(place_order_response_t));
    place_order_response_local_var->_library_owned = 1;
    place_order_response_local_var->status = status;
    place_order_response_local_var->data = data;
    return place_order_response_local_var;
}

place_order_response_t *place_order_response_create(
    upstox_client_place_order_response_STATUS_e status,
    place_order_data_t *data
    ) {
    place_order_response_t *result = place_order_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void place_order_response_free(place_order_response_t *place_order_response) {
    if(NULL == place_order_response){
        return ;
    }
    if(place_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "place_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (place_order_response->data) {
        place_order_data_free(place_order_response->data);
        place_order_response->data = NULL;
    }
    free(place_order_response);
}

cJSON *place_order_response_convertToJSON(place_order_response_t *place_order_response) {
    cJSON *item = cJSON_CreateObject();

    // place_order_response->status
    if(place_order_response->status != upstox_client_place_order_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", place_order_response_status_ToString(place_order_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // place_order_response->data
    if(place_order_response->data) {
    cJSON *data_local_JSON = place_order_data_convertToJSON(place_order_response->data);
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

place_order_response_t *place_order_response_parseFromJSON(cJSON *place_order_responseJSON){

    place_order_response_t *place_order_response_local_var = NULL;

    // define the local variable for place_order_response->data
    place_order_data_t *data_local_nonprim = NULL;

    // place_order_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(place_order_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_place_order_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = place_order_response_status_FromString(status->valuestring);
    }

    // place_order_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(place_order_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = place_order_data_parseFromJSON(data); //nonprimitive
    }



    place_order_response_local_var = place_order_response_create_internal (
        status ? statusVariable : upstox_client_place_order_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!place_order_response_local_var) {
        goto end;
    }

    return place_order_response_local_var;
end:
    if (data_local_nonprim) {
        place_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
