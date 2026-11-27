#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_user_fund_margin_v3_response.h"


char* get_user_fund_margin_v3_response_status_ToString(upstox_client_get_user_fund_margin_v3_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_user_fund_margin_v3_response_STATUS_e get_user_fund_margin_v3_response_status_FromString(char* status){
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

static get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_create_internal(
    upstox_client_get_user_fund_margin_v3_response_STATUS_e status,
    user_fund_margin_v3_data_t *data
    ) {
    get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_local_var = malloc(sizeof(get_user_fund_margin_v3_response_t));
    if (!get_user_fund_margin_v3_response_local_var) {
        return NULL;
    }
    memset(get_user_fund_margin_v3_response_local_var, 0, sizeof(get_user_fund_margin_v3_response_t));
    get_user_fund_margin_v3_response_local_var->_library_owned = 1;
    get_user_fund_margin_v3_response_local_var->status = status;
    get_user_fund_margin_v3_response_local_var->data = data;
    return get_user_fund_margin_v3_response_local_var;
}

get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_create(
    upstox_client_get_user_fund_margin_v3_response_STATUS_e status,
    user_fund_margin_v3_data_t *data
    ) {
    get_user_fund_margin_v3_response_t *result = get_user_fund_margin_v3_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void get_user_fund_margin_v3_response_free(get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response) {
    if(NULL == get_user_fund_margin_v3_response){
        return ;
    }
    if(get_user_fund_margin_v3_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_user_fund_margin_v3_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_user_fund_margin_v3_response->data) {
        user_fund_margin_v3_data_free(get_user_fund_margin_v3_response->data);
        get_user_fund_margin_v3_response->data = NULL;
    }
    free(get_user_fund_margin_v3_response);
}

cJSON *get_user_fund_margin_v3_response_convertToJSON(get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response) {
    cJSON *item = cJSON_CreateObject();

    // get_user_fund_margin_v3_response->status
    if(get_user_fund_margin_v3_response->status != upstox_client_get_user_fund_margin_v3_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_user_fund_margin_v3_response_status_ToString(get_user_fund_margin_v3_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_user_fund_margin_v3_response->data
    if(get_user_fund_margin_v3_response->data) {
    cJSON *data_local_JSON = user_fund_margin_v3_data_convertToJSON(get_user_fund_margin_v3_response->data);
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

get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_parseFromJSON(cJSON *get_user_fund_margin_v3_responseJSON){

    get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_local_var = NULL;

    // define the local variable for get_user_fund_margin_v3_response->data
    user_fund_margin_v3_data_t *data_local_nonprim = NULL;

    // get_user_fund_margin_v3_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_user_fund_margin_v3_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_user_fund_margin_v3_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_user_fund_margin_v3_response_status_FromString(status->valuestring);
    }

    // get_user_fund_margin_v3_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_user_fund_margin_v3_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = user_fund_margin_v3_data_parseFromJSON(data); //nonprimitive
    }



    get_user_fund_margin_v3_response_local_var = get_user_fund_margin_v3_response_create_internal (
        status ? statusVariable : upstox_client_get_user_fund_margin_v3_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!get_user_fund_margin_v3_response_local_var) {
        goto end;
    }

    return get_user_fund_margin_v3_response_local_var;
end:
    if (data_local_nonprim) {
        user_fund_margin_v3_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
