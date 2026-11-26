#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "initiate_payout_request.h"



static initiate_payout_request_t *initiate_payout_request_create_internal(
    char *mode,
    double *amount
    ) {
    initiate_payout_request_t *initiate_payout_request_local_var = malloc(sizeof(initiate_payout_request_t));
    if (!initiate_payout_request_local_var) {
        return NULL;
    }
    memset(initiate_payout_request_local_var, 0, sizeof(initiate_payout_request_t));
    initiate_payout_request_local_var->_library_owned = 1;
    initiate_payout_request_local_var->mode = mode;
    initiate_payout_request_local_var->amount = amount;
    return initiate_payout_request_local_var;
}

initiate_payout_request_t *initiate_payout_request_create(
    char *mode,
    double *amount
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    initiate_payout_request_t *result = initiate_payout_request_create_internal (
        mode,
        amount_copy
        );
    if (!result) {
        free(amount_copy);
    }
    return result;
}

void initiate_payout_request_free(initiate_payout_request_t *initiate_payout_request) {
    if(NULL == initiate_payout_request){
        return ;
    }
    if(initiate_payout_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "initiate_payout_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (initiate_payout_request->mode) {
        free(initiate_payout_request->mode);
        initiate_payout_request->mode = NULL;
    }
    if (initiate_payout_request->amount) {
        free(initiate_payout_request->amount);
        initiate_payout_request->amount = NULL;
    }
    free(initiate_payout_request);
}

cJSON *initiate_payout_request_convertToJSON(initiate_payout_request_t *initiate_payout_request) {
    cJSON *item = cJSON_CreateObject();

    // initiate_payout_request->mode
    if (!initiate_payout_request->mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mode", initiate_payout_request->mode) == NULL) {
    goto fail; //String
    }


    // initiate_payout_request->amount
    if (!initiate_payout_request->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", *initiate_payout_request->amount) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

initiate_payout_request_t *initiate_payout_request_parseFromJSON(cJSON *initiate_payout_requestJSON){

    initiate_payout_request_t *initiate_payout_request_local_var = NULL;

    char *mode_local_str = NULL;

    // define the local variable for initiate_payout_request->amount
    double *amount_local_var = NULL;

    // initiate_payout_request->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(initiate_payout_requestJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (!mode) {
        goto end;
    }

    
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }

    // initiate_payout_request->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(initiate_payout_requestJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (!amount) {
        goto end;
    }

    
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    amount_local_var = malloc(sizeof(double));
    if(!amount_local_var)
    {
        goto end;
    }
    *amount_local_var = amount->valuedouble;


    if (mode && !cJSON_IsNull(mode)) mode_local_str = strdup(mode->valuestring);

    initiate_payout_request_local_var = initiate_payout_request_create_internal (
        mode_local_str,
        amount_local_var
        );

    if (!initiate_payout_request_local_var) {
        goto end;
    }

    return initiate_payout_request_local_var;
end:
    if (mode_local_str) {
        free(mode_local_str);
        mode_local_str = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    return NULL;

}
