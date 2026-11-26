#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indie_user_init_token_data.h"



static indie_user_init_token_data_t *indie_user_init_token_data_create_internal(
    char *authorization_expiry,
    char *notifier_url
    ) {
    indie_user_init_token_data_t *indie_user_init_token_data_local_var = malloc(sizeof(indie_user_init_token_data_t));
    if (!indie_user_init_token_data_local_var) {
        return NULL;
    }
    memset(indie_user_init_token_data_local_var, 0, sizeof(indie_user_init_token_data_t));
    indie_user_init_token_data_local_var->_library_owned = 1;
    indie_user_init_token_data_local_var->authorization_expiry = authorization_expiry;
    indie_user_init_token_data_local_var->notifier_url = notifier_url;
    return indie_user_init_token_data_local_var;
}

indie_user_init_token_data_t *indie_user_init_token_data_create(
    char *authorization_expiry,
    char *notifier_url
    ) {
    indie_user_init_token_data_t *result = indie_user_init_token_data_create_internal (
        authorization_expiry,
        notifier_url
        );
    if (!result) {
    }
    return result;
}

void indie_user_init_token_data_free(indie_user_init_token_data_t *indie_user_init_token_data) {
    if(NULL == indie_user_init_token_data){
        return ;
    }
    if(indie_user_init_token_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "indie_user_init_token_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (indie_user_init_token_data->authorization_expiry) {
        free(indie_user_init_token_data->authorization_expiry);
        indie_user_init_token_data->authorization_expiry = NULL;
    }
    if (indie_user_init_token_data->notifier_url) {
        free(indie_user_init_token_data->notifier_url);
        indie_user_init_token_data->notifier_url = NULL;
    }
    free(indie_user_init_token_data);
}

cJSON *indie_user_init_token_data_convertToJSON(indie_user_init_token_data_t *indie_user_init_token_data) {
    cJSON *item = cJSON_CreateObject();

    // indie_user_init_token_data->authorization_expiry
    if(indie_user_init_token_data->authorization_expiry) {
    if(cJSON_AddStringToObject(item, "authorization_expiry", indie_user_init_token_data->authorization_expiry) == NULL) {
    goto fail; //String
    }
    }


    // indie_user_init_token_data->notifier_url
    if(indie_user_init_token_data->notifier_url) {
    if(cJSON_AddStringToObject(item, "notifier_url", indie_user_init_token_data->notifier_url) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

indie_user_init_token_data_t *indie_user_init_token_data_parseFromJSON(cJSON *indie_user_init_token_dataJSON){

    indie_user_init_token_data_t *indie_user_init_token_data_local_var = NULL;

    char *authorization_expiry_local_str = NULL;

    char *notifier_url_local_str = NULL;

    // indie_user_init_token_data->authorization_expiry
    cJSON *authorization_expiry = cJSON_GetObjectItemCaseSensitive(indie_user_init_token_dataJSON, "authorization_expiry");
    if (cJSON_IsNull(authorization_expiry)) {
        authorization_expiry = NULL;
    }
    if (authorization_expiry) { 
    if(!cJSON_IsString(authorization_expiry) && !cJSON_IsNull(authorization_expiry))
    {
    goto end; //String
    }
    }

    // indie_user_init_token_data->notifier_url
    cJSON *notifier_url = cJSON_GetObjectItemCaseSensitive(indie_user_init_token_dataJSON, "notifier_url");
    if (cJSON_IsNull(notifier_url)) {
        notifier_url = NULL;
    }
    if (notifier_url) { 
    if(!cJSON_IsString(notifier_url) && !cJSON_IsNull(notifier_url))
    {
    goto end; //String
    }
    }


    if (authorization_expiry && !cJSON_IsNull(authorization_expiry)) authorization_expiry_local_str = strdup(authorization_expiry->valuestring);
    if (notifier_url && !cJSON_IsNull(notifier_url)) notifier_url_local_str = strdup(notifier_url->valuestring);

    indie_user_init_token_data_local_var = indie_user_init_token_data_create_internal (
        authorization_expiry_local_str,
        notifier_url_local_str
        );

    if (!indie_user_init_token_data_local_var) {
        goto end;
    }

    return indie_user_init_token_data_local_var;
end:
    if (authorization_expiry_local_str) {
        free(authorization_expiry_local_str);
        authorization_expiry_local_str = NULL;
    }
    if (notifier_url_local_str) {
        free(notifier_url_local_str);
        notifier_url_local_str = NULL;
    }
    return NULL;

}
