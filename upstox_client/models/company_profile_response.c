#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "company_profile_response.h"


char* company_profile_response_status_ToString(upstox_client_company_profile_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_company_profile_response_STATUS_e company_profile_response_status_FromString(char* status){
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

static company_profile_response_t *company_profile_response_create_internal(
    upstox_client_company_profile_response_STATUS_e status,
    company_profile_data_t *data
    ) {
    company_profile_response_t *company_profile_response_local_var = malloc(sizeof(company_profile_response_t));
    if (!company_profile_response_local_var) {
        return NULL;
    }
    memset(company_profile_response_local_var, 0, sizeof(company_profile_response_t));
    company_profile_response_local_var->_library_owned = 1;
    company_profile_response_local_var->status = status;
    company_profile_response_local_var->data = data;
    return company_profile_response_local_var;
}

company_profile_response_t *company_profile_response_create(
    upstox_client_company_profile_response_STATUS_e status,
    company_profile_data_t *data
    ) {
    company_profile_response_t *result = company_profile_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void company_profile_response_free(company_profile_response_t *company_profile_response) {
    if(NULL == company_profile_response){
        return ;
    }
    if(company_profile_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "company_profile_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (company_profile_response->data) {
        company_profile_data_free(company_profile_response->data);
        company_profile_response->data = NULL;
    }
    free(company_profile_response);
}

cJSON *company_profile_response_convertToJSON(company_profile_response_t *company_profile_response) {
    cJSON *item = cJSON_CreateObject();

    // company_profile_response->status
    if(company_profile_response->status != upstox_client_company_profile_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", company_profile_response_status_ToString(company_profile_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // company_profile_response->data
    if(company_profile_response->data) {
    cJSON *data_local_JSON = company_profile_data_convertToJSON(company_profile_response->data);
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

company_profile_response_t *company_profile_response_parseFromJSON(cJSON *company_profile_responseJSON){

    company_profile_response_t *company_profile_response_local_var = NULL;

    // define the local variable for company_profile_response->data
    company_profile_data_t *data_local_nonprim = NULL;

    // company_profile_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(company_profile_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_company_profile_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = company_profile_response_status_FromString(status->valuestring);
    }

    // company_profile_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(company_profile_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = company_profile_data_parseFromJSON(data); //nonprimitive
    }



    company_profile_response_local_var = company_profile_response_create_internal (
        status ? statusVariable : upstox_client_company_profile_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!company_profile_response_local_var) {
        goto end;
    }

    return company_profile_response_local_var;
end:
    if (data_local_nonprim) {
        company_profile_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
