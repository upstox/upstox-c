#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "balance_sheet_response.h"


char* balance_sheet_response_status_ToString(upstox_client_balance_sheet_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_balance_sheet_response_STATUS_e balance_sheet_response_status_FromString(char* status){
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

static balance_sheet_response_t *balance_sheet_response_create_internal(
    upstox_client_balance_sheet_response_STATUS_e status,
    balance_sheet_data_t *data
    ) {
    balance_sheet_response_t *balance_sheet_response_local_var = malloc(sizeof(balance_sheet_response_t));
    if (!balance_sheet_response_local_var) {
        return NULL;
    }
    memset(balance_sheet_response_local_var, 0, sizeof(balance_sheet_response_t));
    balance_sheet_response_local_var->_library_owned = 1;
    balance_sheet_response_local_var->status = status;
    balance_sheet_response_local_var->data = data;
    return balance_sheet_response_local_var;
}

balance_sheet_response_t *balance_sheet_response_create(
    upstox_client_balance_sheet_response_STATUS_e status,
    balance_sheet_data_t *data
    ) {
    balance_sheet_response_t *result = balance_sheet_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void balance_sheet_response_free(balance_sheet_response_t *balance_sheet_response) {
    if(NULL == balance_sheet_response){
        return ;
    }
    if(balance_sheet_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "balance_sheet_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (balance_sheet_response->data) {
        balance_sheet_data_free(balance_sheet_response->data);
        balance_sheet_response->data = NULL;
    }
    free(balance_sheet_response);
}

cJSON *balance_sheet_response_convertToJSON(balance_sheet_response_t *balance_sheet_response) {
    cJSON *item = cJSON_CreateObject();

    // balance_sheet_response->status
    if(balance_sheet_response->status != upstox_client_balance_sheet_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", balance_sheet_response_status_ToString(balance_sheet_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // balance_sheet_response->data
    if(balance_sheet_response->data) {
    cJSON *data_local_JSON = balance_sheet_data_convertToJSON(balance_sheet_response->data);
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

balance_sheet_response_t *balance_sheet_response_parseFromJSON(cJSON *balance_sheet_responseJSON){

    balance_sheet_response_t *balance_sheet_response_local_var = NULL;

    // define the local variable for balance_sheet_response->data
    balance_sheet_data_t *data_local_nonprim = NULL;

    // balance_sheet_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(balance_sheet_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_balance_sheet_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = balance_sheet_response_status_FromString(status->valuestring);
    }

    // balance_sheet_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(balance_sheet_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = balance_sheet_data_parseFromJSON(data); //nonprimitive
    }



    balance_sheet_response_local_var = balance_sheet_response_create_internal (
        status ? statusVariable : upstox_client_balance_sheet_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!balance_sheet_response_local_var) {
        goto end;
    }

    return balance_sheet_response_local_var;
end:
    if (data_local_nonprim) {
        balance_sheet_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
