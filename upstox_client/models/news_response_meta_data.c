#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "news_response_meta_data.h"



static news_response_meta_data_t *news_response_meta_data_create_internal(
    news_response_page_data_t *page
    ) {
    news_response_meta_data_t *news_response_meta_data_local_var = malloc(sizeof(news_response_meta_data_t));
    if (!news_response_meta_data_local_var) {
        return NULL;
    }
    memset(news_response_meta_data_local_var, 0, sizeof(news_response_meta_data_t));
    news_response_meta_data_local_var->_library_owned = 1;
    news_response_meta_data_local_var->page = page;
    return news_response_meta_data_local_var;
}

news_response_meta_data_t *news_response_meta_data_create(
    news_response_page_data_t *page
    ) {
    news_response_meta_data_t *result = news_response_meta_data_create_internal (
        page
        );
    if (!result) {
    }
    return result;
}

void news_response_meta_data_free(news_response_meta_data_t *news_response_meta_data) {
    if(NULL == news_response_meta_data){
        return ;
    }
    if(news_response_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "news_response_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (news_response_meta_data->page) {
        news_response_page_data_free(news_response_meta_data->page);
        news_response_meta_data->page = NULL;
    }
    free(news_response_meta_data);
}

cJSON *news_response_meta_data_convertToJSON(news_response_meta_data_t *news_response_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // news_response_meta_data->page
    if(news_response_meta_data->page) {
    cJSON *page_local_JSON = news_response_page_data_convertToJSON(news_response_meta_data->page);
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

news_response_meta_data_t *news_response_meta_data_parseFromJSON(cJSON *news_response_meta_dataJSON){

    news_response_meta_data_t *news_response_meta_data_local_var = NULL;

    // define the local variable for news_response_meta_data->page
    news_response_page_data_t *page_local_nonprim = NULL;

    // news_response_meta_data->page
    cJSON *page = cJSON_GetObjectItemCaseSensitive(news_response_meta_dataJSON, "page");
    if (cJSON_IsNull(page)) {
        page = NULL;
    }
    if (page) { 
    page_local_nonprim = news_response_page_data_parseFromJSON(page); //nonprimitive
    }



    news_response_meta_data_local_var = news_response_meta_data_create_internal (
        page ? page_local_nonprim : NULL
        );

    if (!news_response_meta_data_local_var) {
        goto end;
    }

    return news_response_meta_data_local_var;
end:
    if (page_local_nonprim) {
        news_response_page_data_free(page_local_nonprim);
        page_local_nonprim = NULL;
    }
    return NULL;

}
