#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_order_detail_response.h"


char* ipo_order_detail_response_status_ToString(upstox_client_ipo_order_detail_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_ipo_order_detail_response_STATUS_e ipo_order_detail_response_status_FromString(char* status){
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

static ipo_order_detail_response_t *ipo_order_detail_response_create_internal(
    upstox_client_ipo_order_detail_response_STATUS_e status,
    ipo_order_data_t *data
    ) {
    ipo_order_detail_response_t *ipo_order_detail_response_local_var = malloc(sizeof(ipo_order_detail_response_t));
    if (!ipo_order_detail_response_local_var) {
        return NULL;
    }
    memset(ipo_order_detail_response_local_var, 0, sizeof(ipo_order_detail_response_t));
    ipo_order_detail_response_local_var->_library_owned = 1;
    ipo_order_detail_response_local_var->status = status;
    ipo_order_detail_response_local_var->data = data;
    return ipo_order_detail_response_local_var;
}

ipo_order_detail_response_t *ipo_order_detail_response_create(
    upstox_client_ipo_order_detail_response_STATUS_e status,
    ipo_order_data_t *data
    ) {
    ipo_order_detail_response_t *result = ipo_order_detail_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void ipo_order_detail_response_free(ipo_order_detail_response_t *ipo_order_detail_response) {
    if(NULL == ipo_order_detail_response){
        return ;
    }
    if(ipo_order_detail_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_order_detail_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_order_detail_response->data) {
        ipo_order_data_free(ipo_order_detail_response->data);
        ipo_order_detail_response->data = NULL;
    }
    free(ipo_order_detail_response);
}

cJSON *ipo_order_detail_response_convertToJSON(ipo_order_detail_response_t *ipo_order_detail_response) {
    cJSON *item = cJSON_CreateObject();

    // ipo_order_detail_response->status
    if(ipo_order_detail_response->status != upstox_client_ipo_order_detail_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", ipo_order_detail_response_status_ToString(ipo_order_detail_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // ipo_order_detail_response->data
    if(ipo_order_detail_response->data) {
    cJSON *data_local_JSON = ipo_order_data_convertToJSON(ipo_order_detail_response->data);
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

ipo_order_detail_response_t *ipo_order_detail_response_parseFromJSON(cJSON *ipo_order_detail_responseJSON){

    ipo_order_detail_response_t *ipo_order_detail_response_local_var = NULL;

    // define the local variable for ipo_order_detail_response->data
    ipo_order_data_t *data_local_nonprim = NULL;

    // ipo_order_detail_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_order_detail_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_ipo_order_detail_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = ipo_order_detail_response_status_FromString(status->valuestring);
    }

    // ipo_order_detail_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(ipo_order_detail_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = ipo_order_data_parseFromJSON(data); //nonprimitive
    }



    ipo_order_detail_response_local_var = ipo_order_detail_response_create_internal (
        status ? statusVariable : upstox_client_ipo_order_detail_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!ipo_order_detail_response_local_var) {
        goto end;
    }

    return ipo_order_detail_response_local_var;
end:
    if (data_local_nonprim) {
        ipo_order_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
