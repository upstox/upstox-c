#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_margin_response.h"


char* post_margin_response_status_ToString(upstox_client_post_margin_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_post_margin_response_STATUS_e post_margin_response_status_FromString(char* status){
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

static post_margin_response_t *post_margin_response_create_internal(
    upstox_client_post_margin_response_STATUS_e status,
    margin_data_t *data
    ) {
    post_margin_response_t *post_margin_response_local_var = malloc(sizeof(post_margin_response_t));
    if (!post_margin_response_local_var) {
        return NULL;
    }
    memset(post_margin_response_local_var, 0, sizeof(post_margin_response_t));
    post_margin_response_local_var->_library_owned = 1;
    post_margin_response_local_var->status = status;
    post_margin_response_local_var->data = data;
    return post_margin_response_local_var;
}

post_margin_response_t *post_margin_response_create(
    upstox_client_post_margin_response_STATUS_e status,
    margin_data_t *data
    ) {
    post_margin_response_t *result = post_margin_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void post_margin_response_free(post_margin_response_t *post_margin_response) {
    if(NULL == post_margin_response){
        return ;
    }
    if(post_margin_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_margin_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_margin_response->data) {
        margin_data_free(post_margin_response->data);
        post_margin_response->data = NULL;
    }
    free(post_margin_response);
}

cJSON *post_margin_response_convertToJSON(post_margin_response_t *post_margin_response) {
    cJSON *item = cJSON_CreateObject();

    // post_margin_response->status
    if(post_margin_response->status != upstox_client_post_margin_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", post_margin_response_status_ToString(post_margin_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // post_margin_response->data
    if(post_margin_response->data) {
    cJSON *data_local_JSON = margin_data_convertToJSON(post_margin_response->data);
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

post_margin_response_t *post_margin_response_parseFromJSON(cJSON *post_margin_responseJSON){

    post_margin_response_t *post_margin_response_local_var = NULL;

    // define the local variable for post_margin_response->data
    margin_data_t *data_local_nonprim = NULL;

    // post_margin_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(post_margin_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_post_margin_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = post_margin_response_status_FromString(status->valuestring);
    }

    // post_margin_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(post_margin_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = margin_data_parseFromJSON(data); //nonprimitive
    }



    post_margin_response_local_var = post_margin_response_create_internal (
        status ? statusVariable : upstox_client_post_margin_response_STATUS_NULL,
        data ? data_local_nonprim : NULL
        );

    if (!post_margin_response_local_var) {
        goto end;
    }

    return post_margin_response_local_var;
end:
    if (data_local_nonprim) {
        margin_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
