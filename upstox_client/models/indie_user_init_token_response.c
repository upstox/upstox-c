#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indie_user_init_token_response.h"



static indie_user_init_token_response_t *indie_user_init_token_response_create_internal(
    char *status,
    indie_user_init_token_data_t *data
    ) {
    indie_user_init_token_response_t *indie_user_init_token_response_local_var = malloc(sizeof(indie_user_init_token_response_t));
    if (!indie_user_init_token_response_local_var) {
        return NULL;
    }
    memset(indie_user_init_token_response_local_var, 0, sizeof(indie_user_init_token_response_t));
    indie_user_init_token_response_local_var->_library_owned = 1;
    indie_user_init_token_response_local_var->status = status;
    indie_user_init_token_response_local_var->data = data;
    return indie_user_init_token_response_local_var;
}

indie_user_init_token_response_t *indie_user_init_token_response_create(
    char *status,
    indie_user_init_token_data_t *data
    ) {
    indie_user_init_token_response_t *result = indie_user_init_token_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void indie_user_init_token_response_free(indie_user_init_token_response_t *indie_user_init_token_response) {
    if(NULL == indie_user_init_token_response){
        return ;
    }
    if(indie_user_init_token_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "indie_user_init_token_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (indie_user_init_token_response->status) {
        free(indie_user_init_token_response->status);
        indie_user_init_token_response->status = NULL;
    }
    if (indie_user_init_token_response->data) {
        indie_user_init_token_data_free(indie_user_init_token_response->data);
        indie_user_init_token_response->data = NULL;
    }
    free(indie_user_init_token_response);
}

cJSON *indie_user_init_token_response_convertToJSON(indie_user_init_token_response_t *indie_user_init_token_response) {
    cJSON *item = cJSON_CreateObject();

    // indie_user_init_token_response->status
    if(indie_user_init_token_response->status) {
    if(cJSON_AddStringToObject(item, "status", indie_user_init_token_response->status) == NULL) {
    goto fail; //String
    }
    }


    // indie_user_init_token_response->data
    if(indie_user_init_token_response->data) {
    cJSON *data_local_JSON = indie_user_init_token_data_convertToJSON(indie_user_init_token_response->data);
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

indie_user_init_token_response_t *indie_user_init_token_response_parseFromJSON(cJSON *indie_user_init_token_responseJSON){

    indie_user_init_token_response_t *indie_user_init_token_response_local_var = NULL;

    char *status_local_str = NULL;

    // define the local variable for indie_user_init_token_response->data
    indie_user_init_token_data_t *data_local_nonprim = NULL;

    // indie_user_init_token_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(indie_user_init_token_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // indie_user_init_token_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(indie_user_init_token_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    data_local_nonprim = indie_user_init_token_data_parseFromJSON(data); //nonprimitive
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    indie_user_init_token_response_local_var = indie_user_init_token_response_create_internal (
        status_local_str,
        data ? data_local_nonprim : NULL
        );

    if (!indie_user_init_token_response_local_var) {
        goto end;
    }

    return indie_user_init_token_response_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (data_local_nonprim) {
        indie_user_init_token_data_free(data_local_nonprim);
        data_local_nonprim = NULL;
    }
    return NULL;

}
