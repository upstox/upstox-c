#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_charges_wrapper_data.h"



static profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_create_internal(
    profit_and_loss_charges_data_t *charges_breakdown
    ) {
    profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_local_var = malloc(sizeof(profit_and_loss_charges_wrapper_data_t));
    if (!profit_and_loss_charges_wrapper_data_local_var) {
        return NULL;
    }
    memset(profit_and_loss_charges_wrapper_data_local_var, 0, sizeof(profit_and_loss_charges_wrapper_data_t));
    profit_and_loss_charges_wrapper_data_local_var->_library_owned = 1;
    profit_and_loss_charges_wrapper_data_local_var->charges_breakdown = charges_breakdown;
    return profit_and_loss_charges_wrapper_data_local_var;
}

profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_create(
    profit_and_loss_charges_data_t *charges_breakdown
    ) {
    profit_and_loss_charges_wrapper_data_t *result = profit_and_loss_charges_wrapper_data_create_internal (
        charges_breakdown
        );
    if (!result) {
    }
    return result;
}

void profit_and_loss_charges_wrapper_data_free(profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data) {
    if(NULL == profit_and_loss_charges_wrapper_data){
        return ;
    }
    if(profit_and_loss_charges_wrapper_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_charges_wrapper_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_charges_wrapper_data->charges_breakdown) {
        profit_and_loss_charges_data_free(profit_and_loss_charges_wrapper_data->charges_breakdown);
        profit_and_loss_charges_wrapper_data->charges_breakdown = NULL;
    }
    free(profit_and_loss_charges_wrapper_data);
}

cJSON *profit_and_loss_charges_wrapper_data_convertToJSON(profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_charges_wrapper_data->charges_breakdown
    if(profit_and_loss_charges_wrapper_data->charges_breakdown) {
    cJSON *charges_breakdown_local_JSON = profit_and_loss_charges_data_convertToJSON(profit_and_loss_charges_wrapper_data->charges_breakdown);
    if(charges_breakdown_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "charges_breakdown", charges_breakdown_local_JSON);
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

profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_parseFromJSON(cJSON *profit_and_loss_charges_wrapper_dataJSON){

    profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_local_var = NULL;

    // define the local variable for profit_and_loss_charges_wrapper_data->charges_breakdown
    profit_and_loss_charges_data_t *charges_breakdown_local_nonprim = NULL;

    // profit_and_loss_charges_wrapper_data->charges_breakdown
    cJSON *charges_breakdown = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_wrapper_dataJSON, "charges_breakdown");
    if (cJSON_IsNull(charges_breakdown)) {
        charges_breakdown = NULL;
    }
    if (charges_breakdown) { 
    charges_breakdown_local_nonprim = profit_and_loss_charges_data_parseFromJSON(charges_breakdown); //nonprimitive
    }



    profit_and_loss_charges_wrapper_data_local_var = profit_and_loss_charges_wrapper_data_create_internal (
        charges_breakdown ? charges_breakdown_local_nonprim : NULL
        );

    if (!profit_and_loss_charges_wrapper_data_local_var) {
        goto end;
    }

    return profit_and_loss_charges_wrapper_data_local_var;
end:
    if (charges_breakdown_local_nonprim) {
        profit_and_loss_charges_data_free(charges_breakdown_local_nonprim);
        charges_breakdown_local_nonprim = NULL;
    }
    return NULL;

}
