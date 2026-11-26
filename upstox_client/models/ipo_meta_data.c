#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_meta_data.h"



static ipo_meta_data_t *ipo_meta_data_create_internal(
    pagination_t *page
    ) {
    ipo_meta_data_t *ipo_meta_data_local_var = malloc(sizeof(ipo_meta_data_t));
    if (!ipo_meta_data_local_var) {
        return NULL;
    }
    memset(ipo_meta_data_local_var, 0, sizeof(ipo_meta_data_t));
    ipo_meta_data_local_var->_library_owned = 1;
    ipo_meta_data_local_var->page = page;
    return ipo_meta_data_local_var;
}

ipo_meta_data_t *ipo_meta_data_create(
    pagination_t *page
    ) {
    ipo_meta_data_t *result = ipo_meta_data_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void ipo_meta_data_free(ipo_meta_data_t *ipo_meta_data) {
    if(NULL == ipo_meta_data){
        return ;
    }
    if(ipo_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_meta_data->page) {
        pagination_free(ipo_meta_data->page);
        ipo_meta_data->page = NULL;
    }
    free(ipo_meta_data);
}

cJSON *ipo_meta_data_convertToJSON(ipo_meta_data_t *ipo_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_meta_data->page
    if(ipo_meta_data->page) {
    cJSON *page_local_JSON = pagination_convertToJSON(ipo_meta_data->page);
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

ipo_meta_data_t *ipo_meta_data_parseFromJSON(cJSON *ipo_meta_dataJSON){

    ipo_meta_data_t *ipo_meta_data_local_var = NULL;

    // define the local variable for ipo_meta_data->page
    pagination_t *page_local_nonprim = NULL;

    // ipo_meta_data->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(ipo_meta_dataJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = pagination_parseFromJSON(page); //nonprimitive
    }



    ipo_meta_data_local_var = ipo_meta_data_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!ipo_meta_data_local_var) {
        goto end;
    }

    return ipo_meta_data_local_var;
end:
    if (page_local_nonprim) {
        pagination_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
