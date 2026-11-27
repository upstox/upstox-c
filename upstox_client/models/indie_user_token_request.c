#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indie_user_token_request.h"



static indie_user_token_request_t *indie_user_token_request_create_internal(
    char *client_id,
    char *client_secret,
    int *otp_verification_disabled
    ) {
    indie_user_token_request_t *indie_user_token_request_local_var = malloc(sizeof(indie_user_token_request_t));
    if (!indie_user_token_request_local_var) {
        return NULL;
    }
    memset(indie_user_token_request_local_var, 0, sizeof(indie_user_token_request_t));
    indie_user_token_request_local_var->_library_owned = 1;
    indie_user_token_request_local_var->client_id = client_id;
    indie_user_token_request_local_var->client_secret = client_secret;
    indie_user_token_request_local_var->otp_verification_disabled = otp_verification_disabled;
    return indie_user_token_request_local_var;
}

indie_user_token_request_t *indie_user_token_request_create(
    char *client_id,
    char *client_secret,
    int *otp_verification_disabled
    ) {
    int *otp_verification_disabled_copy = NULL;
    if (otp_verification_disabled) {
        otp_verification_disabled_copy = malloc(sizeof(int));
        if (otp_verification_disabled_copy) *otp_verification_disabled_copy = *otp_verification_disabled;
    }
    indie_user_token_request_t *result = indie_user_token_request_create_internal (
        client_id,
        client_secret,
        otp_verification_disabled_copy
        );
    if (!result) {
        free(otp_verification_disabled_copy);
    }
    return result;
}

void indie_user_token_request_free(indie_user_token_request_t *indie_user_token_request) {
    if(NULL == indie_user_token_request){
        return ;
    }
    if(indie_user_token_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "indie_user_token_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (indie_user_token_request->client_id) {
        free(indie_user_token_request->client_id);
        indie_user_token_request->client_id = NULL;
    }
    if (indie_user_token_request->client_secret) {
        free(indie_user_token_request->client_secret);
        indie_user_token_request->client_secret = NULL;
    }
    if (indie_user_token_request->otp_verification_disabled) {
        free(indie_user_token_request->otp_verification_disabled);
        indie_user_token_request->otp_verification_disabled = NULL;
    }
    free(indie_user_token_request);
}

cJSON *indie_user_token_request_convertToJSON(indie_user_token_request_t *indie_user_token_request) {
    cJSON *item = cJSON_CreateObject();

    // indie_user_token_request->client_id
    if(indie_user_token_request->client_id) {
    if(cJSON_AddStringToObject(item, "client_id", indie_user_token_request->client_id) == NULL) {
    goto fail; //String
    }
    }


    // indie_user_token_request->client_secret
    if(indie_user_token_request->client_secret) {
    if(cJSON_AddStringToObject(item, "client_secret", indie_user_token_request->client_secret) == NULL) {
    goto fail; //String
    }
    }


    // indie_user_token_request->otp_verification_disabled
    if(indie_user_token_request->otp_verification_disabled) {
    if(cJSON_AddBoolToObject(item, "otp_verification_disabled", *indie_user_token_request->otp_verification_disabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

indie_user_token_request_t *indie_user_token_request_parseFromJSON(cJSON *indie_user_token_requestJSON){

    indie_user_token_request_t *indie_user_token_request_local_var = NULL;

    char *client_id_local_str = NULL;

    char *client_secret_local_str = NULL;

    // define the local variable for indie_user_token_request->otp_verification_disabled
    int *otp_verification_disabled_local_var = NULL;

    // indie_user_token_request->client_id
    cJSON *client_id = cJSON_GetObjectItemCaseSensitive(indie_user_token_requestJSON, "client_id");
    if (cJSON_IsNull(client_id)) {
        client_id = NULL;
    }
    if (client_id) { 
    if(!cJSON_IsString(client_id) && !cJSON_IsNull(client_id))
    {
    goto end; //String
    }
    }

    // indie_user_token_request->client_secret
    cJSON *client_secret = cJSON_GetObjectItemCaseSensitive(indie_user_token_requestJSON, "client_secret");
    if (cJSON_IsNull(client_secret)) {
        client_secret = NULL;
    }
    if (client_secret) { 
    if(!cJSON_IsString(client_secret) && !cJSON_IsNull(client_secret))
    {
    goto end; //String
    }
    }

    // indie_user_token_request->otp_verification_disabled
    cJSON *otp_verification_disabled = cJSON_GetObjectItemCaseSensitive(indie_user_token_requestJSON, "otp_verification_disabled");
    if (cJSON_IsNull(otp_verification_disabled)) {
        otp_verification_disabled = NULL;
    }
    if (otp_verification_disabled) { 
    if(!cJSON_IsBool(otp_verification_disabled))
    {
    goto end; //Bool
    }
    otp_verification_disabled_local_var = malloc(sizeof(int));
    if(!otp_verification_disabled_local_var)
    {
        goto end;
    }
    *otp_verification_disabled_local_var = otp_verification_disabled->valueint;
    }


    if (client_id && !cJSON_IsNull(client_id)) client_id_local_str = strdup(client_id->valuestring);
    if (client_secret && !cJSON_IsNull(client_secret)) client_secret_local_str = strdup(client_secret->valuestring);

    indie_user_token_request_local_var = indie_user_token_request_create_internal (
        client_id_local_str,
        client_secret_local_str,
        otp_verification_disabled_local_var
        );

    if (!indie_user_token_request_local_var) {
        goto end;
    }

    return indie_user_token_request_local_var;
end:
    if (client_id_local_str) {
        free(client_id_local_str);
        client_id_local_str = NULL;
    }
    if (client_secret_local_str) {
        free(client_secret_local_str);
        client_secret_local_str = NULL;
    }
    if (otp_verification_disabled_local_var) {
        free(otp_verification_disabled_local_var);
        otp_verification_disabled_local_var = NULL;
    }
    return NULL;

}
