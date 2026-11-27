#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_meta_data_wrapper.h"



static profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_create_internal(
    profit_and_loss_meta_data_t *page
    ) {
    profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_local_var = malloc(sizeof(profit_and_loss_meta_data_wrapper_t));
    if (!profit_and_loss_meta_data_wrapper_local_var) {
        return NULL;
    }
    memset(profit_and_loss_meta_data_wrapper_local_var, 0, sizeof(profit_and_loss_meta_data_wrapper_t));
    profit_and_loss_meta_data_wrapper_local_var->_library_owned = 1;
    profit_and_loss_meta_data_wrapper_local_var->page = page;
    return profit_and_loss_meta_data_wrapper_local_var;
}

profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_create(
    profit_and_loss_meta_data_t *page
    ) {
    profit_and_loss_meta_data_wrapper_t *result = profit_and_loss_meta_data_wrapper_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void profit_and_loss_meta_data_wrapper_free(profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper) {
    if(NULL == profit_and_loss_meta_data_wrapper){
        return ;
    }
    if(profit_and_loss_meta_data_wrapper->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_meta_data_wrapper_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_meta_data_wrapper->page) {
        profit_and_loss_meta_data_free(profit_and_loss_meta_data_wrapper->page);
        profit_and_loss_meta_data_wrapper->page = NULL;
    }
    free(profit_and_loss_meta_data_wrapper);
}

cJSON *profit_and_loss_meta_data_wrapper_convertToJSON(profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_meta_data_wrapper->page
    if(profit_and_loss_meta_data_wrapper->page) {
    cJSON *page_local_JSON = profit_and_loss_meta_data_convertToJSON(profit_and_loss_meta_data_wrapper->page);
    if(page_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "page", page_local_JSON);
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

profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_parseFromJSON(cJSON *profit_and_loss_meta_data_wrapperJSON){

    profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_local_var = NULL;

    // define the local variable for profit_and_loss_meta_data_wrapper->page
    profit_and_loss_meta_data_t *page_local_nonprim = NULL;

    // profit_and_loss_meta_data_wrapper->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(profit_and_loss_meta_data_wrapperJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = profit_and_loss_meta_data_parseFromJSON(page); //nonprimitive
    }



    profit_and_loss_meta_data_wrapper_local_var = profit_and_loss_meta_data_wrapper_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!profit_and_loss_meta_data_wrapper_local_var) {
        goto end;
    }

    return profit_and_loss_meta_data_wrapper_local_var;
end:
    if (page_local_nonprim) {
        profit_and_loss_meta_data_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
