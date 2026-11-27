#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_meta_data.h"



static search_meta_data_t *search_meta_data_create_internal(
    pagination_t *page
    ) {
    search_meta_data_t *search_meta_data_local_var = malloc(sizeof(search_meta_data_t));
    if (!search_meta_data_local_var) {
        return NULL;
    }
    memset(search_meta_data_local_var, 0, sizeof(search_meta_data_t));
    search_meta_data_local_var->_library_owned = 1;
    search_meta_data_local_var->page = page;
    return search_meta_data_local_var;
}

search_meta_data_t *search_meta_data_create(
    pagination_t *page
    ) {
    search_meta_data_t *result = search_meta_data_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void search_meta_data_free(search_meta_data_t *search_meta_data) {
    if(NULL == search_meta_data){
        return ;
    }
    if(search_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "search_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (search_meta_data->page) {
        pagination_free(search_meta_data->page);
        search_meta_data->page = NULL;
    }
    free(search_meta_data);
}

cJSON *search_meta_data_convertToJSON(search_meta_data_t *search_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // search_meta_data->page
    if(search_meta_data->page) {
    cJSON *page_local_JSON = pagination_convertToJSON(search_meta_data->page);
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

search_meta_data_t *search_meta_data_parseFromJSON(cJSON *search_meta_dataJSON){

    search_meta_data_t *search_meta_data_local_var = NULL;

    // define the local variable for search_meta_data->page
    pagination_t *page_local_nonprim = NULL;

    // search_meta_data->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(search_meta_dataJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = pagination_parseFromJSON(page); //nonprimitive
    }



    search_meta_data_local_var = search_meta_data_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!search_meta_data_local_var) {
        goto end;
    }

    return search_meta_data_local_var;
end:
    if (page_local_nonprim) {
        pagination_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
