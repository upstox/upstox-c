#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "order_metadata.h"



static order_metadata_t *order_metadata_create_internal(
    long *latency
    ) {
    order_metadata_t *order_metadata_local_var = malloc(sizeof(order_metadata_t));
    if (!order_metadata_local_var) {
        return NULL;
    }
    memset(order_metadata_local_var, 0, sizeof(order_metadata_t));
    order_metadata_local_var->_library_owned = 1;
    order_metadata_local_var->latency = latency;
    return order_metadata_local_var;
}

order_metadata_t *order_metadata_create(
    long *latency
    ) {
    long *latency_copy = NULL;
    if (latency) {
        latency_copy = malloc(sizeof(long));
        if (latency_copy) *latency_copy = *latency;
    }
    order_metadata_t *result = order_metadata_create_internal (
        latency_copy
        );
    if (!result) {
        free(latency_copy);
    }
    return result;
}

void order_metadata_free(order_metadata_t *order_metadata) {
    if(NULL == order_metadata){
        return ;
    }
    if(order_metadata->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "order_metadata_free");
        return ;
    }
    listEntry_t *listEntry;
    if (order_metadata->latency) {
        free(order_metadata->latency);
        order_metadata->latency = NULL;
    }
    free(order_metadata);
}

cJSON *order_metadata_convertToJSON(order_metadata_t *order_metadata) {
    cJSON *item = cJSON_CreateObject();

    // order_metadata->latency
    if(order_metadata->latency) {
    if(cJSON_AddNumberToObject(item, "latency", *order_metadata->latency) == NULL) {
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

order_metadata_t *order_metadata_parseFromJSON(cJSON *order_metadataJSON){

    order_metadata_t *order_metadata_local_var = NULL;

    // define the local variable for order_metadata->latency
    long *latency_local_var = NULL;

    // order_metadata->latency
    cJSON *latency = cJSON_GetObjectItemCaseSensitive(order_metadataJSON, "latency");
    if (cJSON_IsNull(latency)) {
        latency = NULL;
    }
    if (latency) { 
    if(!cJSON_IsNumber(latency))
    {
    goto end; //Numeric
    }
    latency_local_var = malloc(sizeof(long));
    if(!latency_local_var)
    {
        goto end;
    }
    *latency_local_var = latency->valuedouble;
    }



    order_metadata_local_var = order_metadata_create_internal (
        latency_local_var
        );

    if (!order_metadata_local_var) {
        goto end;
    }

    return order_metadata_local_var;
end:
    if (latency_local_var) {
        free(latency_local_var);
        latency_local_var = NULL;
    }
    return NULL;

}
