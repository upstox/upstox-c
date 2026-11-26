#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mutual_fund_meta_data.h"



static mutual_fund_meta_data_t *mutual_fund_meta_data_create_internal(
    pagination_t *page
    ) {
    mutual_fund_meta_data_t *mutual_fund_meta_data_local_var = malloc(sizeof(mutual_fund_meta_data_t));
    if (!mutual_fund_meta_data_local_var) {
        return NULL;
    }
    memset(mutual_fund_meta_data_local_var, 0, sizeof(mutual_fund_meta_data_t));
    mutual_fund_meta_data_local_var->_library_owned = 1;
    mutual_fund_meta_data_local_var->page = page;
    return mutual_fund_meta_data_local_var;
}

mutual_fund_meta_data_t *mutual_fund_meta_data_create(
    pagination_t *page
    ) {
    mutual_fund_meta_data_t *result = mutual_fund_meta_data_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void mutual_fund_meta_data_free(mutual_fund_meta_data_t *mutual_fund_meta_data) {
    if(NULL == mutual_fund_meta_data){
        return ;
    }
    if(mutual_fund_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mutual_fund_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mutual_fund_meta_data->page) {
        pagination_free(mutual_fund_meta_data->page);
        mutual_fund_meta_data->page = NULL;
    }
    free(mutual_fund_meta_data);
}

cJSON *mutual_fund_meta_data_convertToJSON(mutual_fund_meta_data_t *mutual_fund_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // mutual_fund_meta_data->page
    if(mutual_fund_meta_data->page) {
    cJSON *page_local_JSON = pagination_convertToJSON(mutual_fund_meta_data->page);
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

mutual_fund_meta_data_t *mutual_fund_meta_data_parseFromJSON(cJSON *mutual_fund_meta_dataJSON){

    mutual_fund_meta_data_t *mutual_fund_meta_data_local_var = NULL;

    // define the local variable for mutual_fund_meta_data->page
    pagination_t *page_local_nonprim = NULL;

    // mutual_fund_meta_data->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(mutual_fund_meta_dataJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = pagination_parseFromJSON(page); //nonprimitive
    }



    mutual_fund_meta_data_local_var = mutual_fund_meta_data_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!mutual_fund_meta_data_local_var) {
        goto end;
    }

    return mutual_fund_meta_data_local_var;
end:
    if (page_local_nonprim) {
        pagination_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
