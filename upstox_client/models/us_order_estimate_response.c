#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_estimate_response.h"


char* us_order_estimate_response_status_ToString(upstox_client_us_order_estimate_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_us_order_estimate_response_STATUS_e us_order_estimate_response_status_FromString(char* status){
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

static us_order_estimate_response_t *us_order_estimate_response_create_internal(
    upstox_client_us_order_estimate_response_STATUS_e status,
    us_order_estimate_data_t *data
    ) {
    us_order_estimate_response_t *us_order_estimate_response_local_var = malloc(sizeof(us_order_estimate_response_t));
    if (!us_order_estimate_response_local_var) {
        return NULL;
    }
    memset(us_order_estimate_response_local_var, 0, sizeof(us_order_estimate_response_t));
    us_order_estimate_response_local_var->_library_owned = 1;
    us_order_estimate_response_local_var->status = status;
    us_order_estimate_response_local_var->data = data;
    return us_order_estimate_response_local_var;
}

us_order_estimate_response_t *us_order_estimate_response_create(
    upstox_client_us_order_estimate_response_STATUS_e status,
    us_order_estimate_data_t *data
    ) {
    us_order_estimate_response_t *result = us_order_estimate_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void us_order_estimate_response_free(us_order_estimate_response_t *us_order_estimate_response) {
    if(NULL == us_order_estimate_response){
        return ;
    }
    if(us_order_estimate_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_estimate_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_estimate_response->data) {
        us_order_estimate_data_free(us_order_estimate_response->data);
        us_order_estimate_response->data = NULL;
    }
    free(us_order_estimate_response);
}

cJSON *us_order_estimate_response_convertToJSON(us_order_estimate_response_t *us_order_estimate_response) {
    cJSON *item = cJSON_CreateObject();

    // us_order_estimate_response->status
    if(us_order_estimate_response->status != upstox_client_us_order_estimate_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", us_order_estimate_response_status_ToString(us_order_estimate_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // us_order_estimate_response->data
    if(us_order_estimate_response->data) {
    cJSON *data_local_JSON = us_order_estimate_data_convertToJSON(us_order_estimate_response->data);
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

us_order_estimate_response_t *us_order_estimate_response_parseFromJSON(cJSON *us_order_estimate_responseJSON){

    us_order_estimate_response_t *us_order_estimate_response_local_var = NULL;

    // define the local variable for us_order_estimate_response->data
    us_order_estimate_data_t *data_local_nonprim = NULL;

    // us_order_estimate_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(us_order_estimate_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_us_order_estimate_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = us_order_estimate_response_status_FromString(status->valuestring);
    }

    // us_order_estimate_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(us_order_estimate_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = us_order_estimate_data_parseFromJSON(data); //nonprimitive
    }



    us_order_estimate_response_local_var = us_order_estimate_response_create_internal (
        status ? statusVariable : upstox_client_us_order_estimate_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!us_order_estimate_response_local_var) {
        goto end;
    }

    return us_order_estimate_response_local_var;
end:
    if (data_local_nonprim) {
        us_order_estimate_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
