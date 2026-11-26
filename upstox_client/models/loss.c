#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loss.h"



static loss_t *loss_create_internal(
    double *total,
    double *realised,
    double *unrealised
    ) {
    loss_t *loss_local_var = malloc(sizeof(loss_t));
    if (!loss_local_var) {
        return NULL;
    }
    memset(loss_local_var, 0, sizeof(loss_t));
    loss_local_var->_library_owned = 1;
    loss_local_var->total = total;
    loss_local_var->realised = realised;
    loss_local_var->unrealised = unrealised;
    return loss_local_var;
}

loss_t *loss_create(
    double *total,
    double *realised,
    double *unrealised
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    double *realised_copy = NULL;
    if (realised) {
        realised_copy = malloc(sizeof(double));
        if (realised_copy) *realised_copy = *realised;
    }
    double *unrealised_copy = NULL;
    if (unrealised) {
        unrealised_copy = malloc(sizeof(double));
        if (unrealised_copy) *unrealised_copy = *unrealised;
    }
    loss_t *result = loss_create_internal (
        total_copy,
        realised_copy,
        unrealised_copy
        );
    if (!result) {
        free(total_copy);
        free(realised_copy);
        free(unrealised_copy);
    }
    return result;
}

void loss_free(loss_t *loss) {
    if(NULL == loss){
        return ;
    }
    if(loss->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "loss_free");
        return ;
    }
    listEntry_t *listEntry;
    if (loss->total) {
        free(loss->total);
        loss->total = NULL;
    }
    if (loss->realised) {
        free(loss->realised);
        loss->realised = NULL;
    }
    if (loss->unrealised) {
        free(loss->unrealised);
        loss->unrealised = NULL;
    }
    free(loss);
}

cJSON *loss_convertToJSON(loss_t *loss) {
    cJSON *item = cJSON_CreateObject();

    // loss->total
    if(loss->total) {
    if(cJSON_AddNumberToObject(item, "total", *loss->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // loss->realised
    if(loss->realised) {
    if(cJSON_AddNumberToObject(item, "realised", *loss->realised) == NULL) {
    goto fail; //Numeric
    }
    }


    // loss->unrealised
    if(loss->unrealised) {
    if(cJSON_AddNumberToObject(item, "unrealised", *loss->unrealised) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

loss_t *loss_parseFromJSON(cJSON *lossJSON){

    loss_t *loss_local_var = NULL;

    // define the local variable for loss->total
    double *total_local_var = NULL;

    // define the local variable for loss->realised
    double *realised_local_var = NULL;

    // define the local variable for loss->unrealised
    double *unrealised_local_var = NULL;

    // loss->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(lossJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(double));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;
    }

    // loss->realised
    cJSON *realised = cJSON_GetObjectItemCaseSensitive(lossJSON, "realised");
    if (cJSON_IsNull(realised)) {
        realised = NULL;
    }
    if (realised) { 
    if(!cJSON_IsNumber(realised))
    {
    goto end; //Numeric
    }
    realised_local_var = malloc(sizeof(double));
    if(!realised_local_var)
    {
        goto end;
    }
    *realised_local_var = realised->valuedouble;
    }

    // loss->unrealised
    cJSON *unrealised = cJSON_GetObjectItemCaseSensitive(lossJSON, "unrealised");
    if (cJSON_IsNull(unrealised)) {
        unrealised = NULL;
    }
    if (unrealised) { 
    if(!cJSON_IsNumber(unrealised))
    {
    goto end; //Numeric
    }
    unrealised_local_var = malloc(sizeof(double));
    if(!unrealised_local_var)
    {
        goto end;
    }
    *unrealised_local_var = unrealised->valuedouble;
    }



    loss_local_var = loss_create_internal (
        total_local_var,
        realised_local_var,
        unrealised_local_var
        );

    if (!loss_local_var) {
        goto end;
    }

    return loss_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (realised_local_var) {
        free(realised_local_var);
        realised_local_var = NULL;
    }
    if (unrealised_local_var) {
        free(unrealised_local_var);
        unrealised_local_var = NULL;
    }
    return NULL;

}
