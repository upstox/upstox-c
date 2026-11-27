#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payout_details_response.h"


char* payout_details_response_status_ToString(upstox_client_payout_details_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_payout_details_response_STATUS_e payout_details_response_status_FromString(char* status){
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

static payout_details_response_t *payout_details_response_create_internal(
    upstox_client_payout_details_response_STATUS_e status,
    payout_details_t *data
    ) {
    payout_details_response_t *payout_details_response_local_var = malloc(sizeof(payout_details_response_t));
    if (!payout_details_response_local_var) {
        return NULL;
    }
    memset(payout_details_response_local_var, 0, sizeof(payout_details_response_t));
    payout_details_response_local_var->_library_owned = 1;
    payout_details_response_local_var->status = status;
    payout_details_response_local_var->data = data;
    return payout_details_response_local_var;
}

payout_details_response_t *payout_details_response_create(
    upstox_client_payout_details_response_STATUS_e status,
    payout_details_t *data
    ) {
    payout_details_response_t *result = payout_details_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void payout_details_response_free(payout_details_response_t *payout_details_response) {
    if(NULL == payout_details_response){
        return ;
    }
    if(payout_details_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payout_details_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payout_details_response->data) {
        payout_details_free(payout_details_response->data);
        payout_details_response->data = NULL;
    }
    free(payout_details_response);
}

cJSON *payout_details_response_convertToJSON(payout_details_response_t *payout_details_response) {
    cJSON *item = cJSON_CreateObject();

    // payout_details_response->status
    if(payout_details_response->status != upstox_client_payout_details_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", payout_details_response_status_ToString(payout_details_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // payout_details_response->data
    if(payout_details_response->data) {
    cJSON *data_local_JSON = payout_details_convertToJSON(payout_details_response->data);
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

payout_details_response_t *payout_details_response_parseFromJSON(cJSON *payout_details_responseJSON){

    payout_details_response_t *payout_details_response_local_var = NULL;

    // define the local variable for payout_details_response->data
    payout_details_t *data_local_nonprim = NULL;

    // payout_details_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payout_details_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_payout_details_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = payout_details_response_status_FromString(status->valuestring);
    }

    // payout_details_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(payout_details_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = payout_details_parseFromJSON(data); //nonprimitive
    }



    payout_details_response_local_var = payout_details_response_create_internal (
        status ? statusVariable : upstox_client_payout_details_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!payout_details_response_local_var) {
        goto end;
    }

    return payout_details_response_local_var;
end:
    if (data_local_nonprim) {
        payout_details_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
