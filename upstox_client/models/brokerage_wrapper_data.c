#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "brokerage_wrapper_data.h"



static brokerage_wrapper_data_t *brokerage_wrapper_data_create_internal(
    brokerage_data_t *charges
    ) {
    brokerage_wrapper_data_t *brokerage_wrapper_data_local_var = malloc(sizeof(brokerage_wrapper_data_t));
    if (!brokerage_wrapper_data_local_var) {
        return NULL;
    }
    memset(brokerage_wrapper_data_local_var, 0, sizeof(brokerage_wrapper_data_t));
    brokerage_wrapper_data_local_var->_library_owned = 1;
    brokerage_wrapper_data_local_var->charges = charges;
    return brokerage_wrapper_data_local_var;
}

brokerage_wrapper_data_t *brokerage_wrapper_data_create(
    brokerage_data_t *charges
    ) {
    brokerage_wrapper_data_t *result = brokerage_wrapper_data_create_internal (
        charges
        );
    if (!result) {
    }
    return result;
}

void brokerage_wrapper_data_free(brokerage_wrapper_data_t *brokerage_wrapper_data) {
    if(NULL == brokerage_wrapper_data){
        return ;
    }
    if(brokerage_wrapper_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "brokerage_wrapper_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (brokerage_wrapper_data->charges) {
        brokerage_data_free(brokerage_wrapper_data->charges);
        brokerage_wrapper_data->charges = NULL;
    }
    free(brokerage_wrapper_data);
}

cJSON *brokerage_wrapper_data_convertToJSON(brokerage_wrapper_data_t *brokerage_wrapper_data) {
    cJSON *item = cJSON_CreateObject();

    // brokerage_wrapper_data->charges
    if(brokerage_wrapper_data->charges) {
    cJSON *charges_local_JSON = brokerage_data_convertToJSON(brokerage_wrapper_data->charges);
    if(charges_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "charges", charges_local_JSON);
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

brokerage_wrapper_data_t *brokerage_wrapper_data_parseFromJSON(cJSON *brokerage_wrapper_dataJSON){

    brokerage_wrapper_data_t *brokerage_wrapper_data_local_var = NULL;

    // define the local variable for brokerage_wrapper_data->charges
    brokerage_data_t *charges_local_nonprim = NULL;

    // brokerage_wrapper_data->charges
    cJSON *charges = cJSON_GetObjectItemCaseSensitive(brokerage_wrapper_dataJSON, "charges");
    if (cJSON_IsNull(charges)) {
        charges = NULL;
    }
    if (charges) { 
    charges_local_nonprim = brokerage_data_parseFromJSON(charges); //nonprimitive
    }



    brokerage_wrapper_data_local_var = brokerage_wrapper_data_create_internal (
        charges ? charges_local_nonprim : NULL
        );

    if (!brokerage_wrapper_data_local_var) {
        goto end;
    }

    return brokerage_wrapper_data_local_var;
end:
    if (charges_local_nonprim) {
        brokerage_data_free(charges_local_nonprim);
        charges_local_nonprim = NULL;
    }
    return NULL;

}
