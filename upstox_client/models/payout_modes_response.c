#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payout_modes_response.h"


char* payout_modes_response_status_ToString(upstox_client_payout_modes_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_payout_modes_response_STATUS_e payout_modes_response_status_FromString(char* status){
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

static payout_modes_response_t *payout_modes_response_create_internal(
    upstox_client_payout_modes_response_STATUS_e status,
    object_t *data
    ) {
    payout_modes_response_t *payout_modes_response_local_var = malloc(sizeof(payout_modes_response_t));
    if (!payout_modes_response_local_var) {
        return NULL;
    }
    memset(payout_modes_response_local_var, 0, sizeof(payout_modes_response_t));
    payout_modes_response_local_var->_library_owned = 1;
    payout_modes_response_local_var->status = status;
    payout_modes_response_local_var->data = data;
    return payout_modes_response_local_var;
}

payout_modes_response_t *payout_modes_response_create(
    upstox_client_payout_modes_response_STATUS_e status,
    object_t *data
    ) {
    payout_modes_response_t *result = payout_modes_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void payout_modes_response_free(payout_modes_response_t *payout_modes_response) {
    if(NULL == payout_modes_response){
        return ;
    }
    if(payout_modes_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payout_modes_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payout_modes_response->data) {
        object_free(payout_modes_response->data);
        payout_modes_response->data = NULL;
    }
    free(payout_modes_response);
}

cJSON *payout_modes_response_convertToJSON(payout_modes_response_t *payout_modes_response) {
    cJSON *item = cJSON_CreateObject();

    // payout_modes_response->status
    if(payout_modes_response->status != upstox_client_payout_modes_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", payout_modes_response_status_ToString(payout_modes_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // payout_modes_response->data
    if(payout_modes_response->data) {
    cJSON *data_object = object_convertToJSON(payout_modes_response->data);
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

payout_modes_response_t *payout_modes_response_parseFromJSON(cJSON *payout_modes_responseJSON){

    payout_modes_response_t *payout_modes_response_local_var = NULL;

    // payout_modes_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payout_modes_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_payout_modes_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = payout_modes_response_status_FromString(status->valuestring);
    }

    // payout_modes_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(payout_modes_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }



    payout_modes_response_local_var = payout_modes_response_create_internal (
        status ? statusVariable : upstox_client_payout_modes_response_STATUS_NULL,
        data ? data_local_object : NULL
        );

    if (!payout_modes_response_local_var) {
        goto end;
    }

    return payout_modes_response_local_var;
end:
    return NULL;

}
