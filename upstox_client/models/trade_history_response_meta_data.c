#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_history_response_meta_data.h"



static trade_history_response_meta_data_t *trade_history_response_meta_data_create_internal(
    trade_history_response_page_data_t *page
    ) {
    trade_history_response_meta_data_t *trade_history_response_meta_data_local_var = malloc(sizeof(trade_history_response_meta_data_t));
    if (!trade_history_response_meta_data_local_var) {
        return NULL;
    }
    memset(trade_history_response_meta_data_local_var, 0, sizeof(trade_history_response_meta_data_t));
    trade_history_response_meta_data_local_var->_library_owned = 1;
    trade_history_response_meta_data_local_var->page = page;
    return trade_history_response_meta_data_local_var;
}

trade_history_response_meta_data_t *trade_history_response_meta_data_create(
    trade_history_response_page_data_t *page
    ) {
    trade_history_response_meta_data_t *result = trade_history_response_meta_data_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void trade_history_response_meta_data_free(trade_history_response_meta_data_t *trade_history_response_meta_data) {
    if(NULL == trade_history_response_meta_data){
        return ;
    }
    if(trade_history_response_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_history_response_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_history_response_meta_data->page) {
        trade_history_response_page_data_free(trade_history_response_meta_data->page);
        trade_history_response_meta_data->page = NULL;
    }
    free(trade_history_response_meta_data);
}

cJSON *trade_history_response_meta_data_convertToJSON(trade_history_response_meta_data_t *trade_history_response_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_history_response_meta_data->page
    if(trade_history_response_meta_data->page) {
    cJSON *page_local_JSON = trade_history_response_page_data_convertToJSON(trade_history_response_meta_data->page);
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

trade_history_response_meta_data_t *trade_history_response_meta_data_parseFromJSON(cJSON *trade_history_response_meta_dataJSON){

    trade_history_response_meta_data_t *trade_history_response_meta_data_local_var = NULL;

    // define the local variable for trade_history_response_meta_data->page
    trade_history_response_page_data_t *page_local_nonprim = NULL;

    // trade_history_response_meta_data->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(trade_history_response_meta_dataJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = trade_history_response_page_data_parseFromJSON(page); //nonprimitive
    }



    trade_history_response_meta_data_local_var = trade_history_response_meta_data_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!trade_history_response_meta_data_local_var) {
        goto end;
    }

    return trade_history_response_meta_data_local_var;
end:
    if (page_local_nonprim) {
        trade_history_response_page_data_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
