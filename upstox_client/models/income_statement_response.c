#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "income_statement_response.h"


char* income_statement_response_status_ToString(upstox_client_income_statement_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_income_statement_response_STATUS_e income_statement_response_status_FromString(char* status){
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

static income_statement_response_t *income_statement_response_create_internal(
    upstox_client_income_statement_response_STATUS_e status,
    income_statement_data_t *data
    ) {
    income_statement_response_t *income_statement_response_local_var = malloc(sizeof(income_statement_response_t));
    if (!income_statement_response_local_var) {
        return NULL;
    }
    memset(income_statement_response_local_var, 0, sizeof(income_statement_response_t));
    income_statement_response_local_var->_library_owned = 1;
    income_statement_response_local_var->status = status;
    income_statement_response_local_var->data = data;
    return income_statement_response_local_var;
}

income_statement_response_t *income_statement_response_create(
    upstox_client_income_statement_response_STATUS_e status,
    income_statement_data_t *data
    ) {
    income_statement_response_t *result = income_statement_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void income_statement_response_free(income_statement_response_t *income_statement_response) {
    if(NULL == income_statement_response){
        return ;
    }
    if(income_statement_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "income_statement_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (income_statement_response->data) {
        income_statement_data_free(income_statement_response->data);
        income_statement_response->data = NULL;
    }
    free(income_statement_response);
}

cJSON *income_statement_response_convertToJSON(income_statement_response_t *income_statement_response) {
    cJSON *item = cJSON_CreateObject();

    // income_statement_response->status
    if(income_statement_response->status != upstox_client_income_statement_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", income_statement_response_status_ToString(income_statement_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // income_statement_response->data
    if(income_statement_response->data) {
    cJSON *data_local_JSON = income_statement_data_convertToJSON(income_statement_response->data);
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

income_statement_response_t *income_statement_response_parseFromJSON(cJSON *income_statement_responseJSON){

    income_statement_response_t *income_statement_response_local_var = NULL;

    // define the local variable for income_statement_response->data
    income_statement_data_t *data_local_nonprim = NULL;

    // income_statement_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(income_statement_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_income_statement_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = income_statement_response_status_FromString(status->valuestring);
    }

    // income_statement_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(income_statement_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = income_statement_data_parseFromJSON(data); //nonprimitive
    }



    income_statement_response_local_var = income_statement_response_create_internal (
        status ? statusVariable : upstox_client_income_statement_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!income_statement_response_local_var) {
        goto end;
    }

    return income_statement_response_local_var;
end:
    if (data_local_nonprim) {
        income_statement_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
