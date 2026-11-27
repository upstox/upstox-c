#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modify_payout_request.h"



static modify_payout_request_t *modify_payout_request_create_internal(
    double *amount
    ) {
    modify_payout_request_t *modify_payout_request_local_var = malloc(sizeof(modify_payout_request_t));
    if (!modify_payout_request_local_var) {
        return NULL;
    }
    memset(modify_payout_request_local_var, 0, sizeof(modify_payout_request_t));
    modify_payout_request_local_var->_library_owned = 1;
    modify_payout_request_local_var->amount = amount;
    return modify_payout_request_local_var;
}

modify_payout_request_t *modify_payout_request_create(
    double *amount
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    modify_payout_request_t *result = modify_payout_request_create_internal (
        amount_copy
        );
    if (!result) {
        free(amount_copy);
    }
    return result;
}

void modify_payout_request_free(modify_payout_request_t *modify_payout_request) {
    if(NULL == modify_payout_request){
        return ;
    }
    if(modify_payout_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "modify_payout_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (modify_payout_request->amount) {
        free(modify_payout_request->amount);
        modify_payout_request->amount = NULL;
    }
    free(modify_payout_request);
}

cJSON *modify_payout_request_convertToJSON(modify_payout_request_t *modify_payout_request) {
    cJSON *item = cJSON_CreateObject();

    // modify_payout_request->amount
    if (!modify_payout_request->amount) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "amount", *modify_payout_request->amount) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

modify_payout_request_t *modify_payout_request_parseFromJSON(cJSON *modify_payout_requestJSON){

    modify_payout_request_t *modify_payout_request_local_var = NULL;

    // define the local variable for modify_payout_request->amount
    double *amount_local_var = NULL;

    // modify_payout_request->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(modify_payout_requestJSON, "amount");
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



    modify_payout_request_local_var = modify_payout_request_create_internal (
        amount_local_var
        );

    if (!modify_payout_request_local_var) {
        goto end;
    }

    return modify_payout_request_local_var;
end:
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    return NULL;

}
