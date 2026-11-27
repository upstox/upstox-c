#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_flow_response.h"


char* cash_flow_response_status_ToString(upstox_client_cash_flow_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_cash_flow_response_STATUS_e cash_flow_response_status_FromString(char* status){
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

static cash_flow_response_t *cash_flow_response_create_internal(
    upstox_client_cash_flow_response_STATUS_e status,
    cash_flow_data_t *data
    ) {
    cash_flow_response_t *cash_flow_response_local_var = malloc(sizeof(cash_flow_response_t));
    if (!cash_flow_response_local_var) {
        return NULL;
    }
    memset(cash_flow_response_local_var, 0, sizeof(cash_flow_response_t));
    cash_flow_response_local_var->_library_owned = 1;
    cash_flow_response_local_var->status = status;
    cash_flow_response_local_var->data = data;
    return cash_flow_response_local_var;
}

cash_flow_response_t *cash_flow_response_create(
    upstox_client_cash_flow_response_STATUS_e status,
    cash_flow_data_t *data
    ) {
    cash_flow_response_t *result = cash_flow_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void cash_flow_response_free(cash_flow_response_t *cash_flow_response) {
    if(NULL == cash_flow_response){
        return ;
    }
    if(cash_flow_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_flow_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_flow_response->data) {
        cash_flow_data_free(cash_flow_response->data);
        cash_flow_response->data = NULL;
    }
    free(cash_flow_response);
}

cJSON *cash_flow_response_convertToJSON(cash_flow_response_t *cash_flow_response) {
    cJSON *item = cJSON_CreateObject();

    // cash_flow_response->status
    if(cash_flow_response->status != upstox_client_cash_flow_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", cash_flow_response_status_ToString(cash_flow_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cash_flow_response->data
    if(cash_flow_response->data) {
    cJSON *data_local_JSON = cash_flow_data_convertToJSON(cash_flow_response->data);
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

cash_flow_response_t *cash_flow_response_parseFromJSON(cJSON *cash_flow_responseJSON){

    cash_flow_response_t *cash_flow_response_local_var = NULL;

    // define the local variable for cash_flow_response->data
    cash_flow_data_t *data_local_nonprim = NULL;

    // cash_flow_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cash_flow_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_cash_flow_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = cash_flow_response_status_FromString(status->valuestring);
    }

    // cash_flow_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(cash_flow_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = cash_flow_data_parseFromJSON(data); //nonprimitive
    }



    cash_flow_response_local_var = cash_flow_response_create_internal (
        status ? statusVariable : upstox_client_cash_flow_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!cash_flow_response_local_var) {
        goto end;
    }

    return cash_flow_response_local_var;
end:
    if (data_local_nonprim) {
        cash_flow_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
