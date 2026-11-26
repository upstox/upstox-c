#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "totp_pin_token_request.h"



static totp_pin_token_request_t *totp_pin_token_request_create_internal(
    char *pin,
    char *totp
    ) {
    totp_pin_token_request_t *totp_pin_token_request_local_var = malloc(sizeof(totp_pin_token_request_t));
    if (!totp_pin_token_request_local_var) {
        return NULL;
    }
    memset(totp_pin_token_request_local_var, 0, sizeof(totp_pin_token_request_t));
    totp_pin_token_request_local_var->_library_owned = 1;
    totp_pin_token_request_local_var->pin = pin;
    totp_pin_token_request_local_var->totp = totp;
    return totp_pin_token_request_local_var;
}

totp_pin_token_request_t *totp_pin_token_request_create(
    char *pin,
    char *totp
    ) {
    totp_pin_token_request_t *result = totp_pin_token_request_create_internal (
        pin,
        totp
        );
    if (!result) {
    }
    return result;
}

void totp_pin_token_request_free(totp_pin_token_request_t *totp_pin_token_request) {
    if(NULL == totp_pin_token_request){
        return ;
    }
    if(totp_pin_token_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "totp_pin_token_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (totp_pin_token_request->pin) {
        free(totp_pin_token_request->pin);
        totp_pin_token_request->pin = NULL;
    }
    if (totp_pin_token_request->totp) {
        free(totp_pin_token_request->totp);
        totp_pin_token_request->totp = NULL;
    }
    free(totp_pin_token_request);
}

cJSON *totp_pin_token_request_convertToJSON(totp_pin_token_request_t *totp_pin_token_request) {
    cJSON *item = cJSON_CreateObject();

    // totp_pin_token_request->pin
    if (!totp_pin_token_request->pin) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pin", totp_pin_token_request->pin) == NULL) {
    goto fail; //String
    }


    // totp_pin_token_request->totp
    if (!totp_pin_token_request->totp) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "totp", totp_pin_token_request->totp) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

totp_pin_token_request_t *totp_pin_token_request_parseFromJSON(cJSON *totp_pin_token_requestJSON){

    totp_pin_token_request_t *totp_pin_token_request_local_var = NULL;

    char *pin_local_str = NULL;

    char *totp_local_str = NULL;

    // totp_pin_token_request->pin
    cJSON *pin = cJSON_GetObjectItemCaseSensitive(totp_pin_token_requestJSON, "pin");
    if (cJSON_IsNull(pin)) {
        pin = NULL;
    }
    if (!pin) {
        goto end;
    }

    
    if(!cJSON_IsString(pin))
    {
    goto end; //String
    }

    // totp_pin_token_request->totp
    cJSON *totp = cJSON_GetObjectItemCaseSensitive(totp_pin_token_requestJSON, "totp");
    if (cJSON_IsNull(totp)) {
        totp = NULL;
    }
    if (!totp) {
        goto end;
    }

    
    if(!cJSON_IsString(totp))
    {
    goto end; //String
    }


    if (pin && !cJSON_IsNull(pin)) pin_local_str = strdup(pin->valuestring);
    if (totp && !cJSON_IsNull(totp)) totp_local_str = strdup(totp->valuestring);

    totp_pin_token_request_local_var = totp_pin_token_request_create_internal (
        pin_local_str,
        totp_local_str
        );

    if (!totp_pin_token_request_local_var) {
        goto end;
    }

    return totp_pin_token_request_local_var;
end:
    if (pin_local_str) {
        free(pin_local_str);
        pin_local_str = NULL;
    }
    if (totp_local_str) {
        free(totp_local_str);
        totp_local_str = NULL;
    }
    return NULL;

}
