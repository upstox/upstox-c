#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_wise_meta_data.h"



static trade_wise_meta_data_t *trade_wise_meta_data_create_internal(
    int *trades_count,
    int *page_size_limit
    ) {
    trade_wise_meta_data_t *trade_wise_meta_data_local_var = malloc(sizeof(trade_wise_meta_data_t));
    if (!trade_wise_meta_data_local_var) {
        return NULL;
    }
    memset(trade_wise_meta_data_local_var, 0, sizeof(trade_wise_meta_data_t));
    trade_wise_meta_data_local_var->_library_owned = 1;
    trade_wise_meta_data_local_var->trades_count = trades_count;
    trade_wise_meta_data_local_var->page_size_limit = page_size_limit;
    return trade_wise_meta_data_local_var;
}

trade_wise_meta_data_t *trade_wise_meta_data_create(
    int *trades_count,
    int *page_size_limit
    ) {
    int *trades_count_copy = NULL;
    if (trades_count) {
        trades_count_copy = malloc(sizeof(int));
        if (trades_count_copy) *trades_count_copy = *trades_count;
    }
    int *page_size_limit_copy = NULL;
    if (page_size_limit) {
        page_size_limit_copy = malloc(sizeof(int));
        if (page_size_limit_copy) *page_size_limit_copy = *page_size_limit;
    }
    trade_wise_meta_data_t *result = trade_wise_meta_data_create_internal (
        trades_count_copy,
        page_size_limit_copy
        );
    if (!result) {
        free(trades_count_copy);
        free(page_size_limit_copy);
    }
    return result;
}

void trade_wise_meta_data_free(trade_wise_meta_data_t *trade_wise_meta_data) {
    if(NULL == trade_wise_meta_data){
        return ;
    }
    if(trade_wise_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_wise_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_wise_meta_data->trades_count) {
        free(trade_wise_meta_data->trades_count);
        trade_wise_meta_data->trades_count = NULL;
    }
    if (trade_wise_meta_data->page_size_limit) {
        free(trade_wise_meta_data->page_size_limit);
        trade_wise_meta_data->page_size_limit = NULL;
    }
    free(trade_wise_meta_data);
}

cJSON *trade_wise_meta_data_convertToJSON(trade_wise_meta_data_t *trade_wise_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_wise_meta_data->trades_count
    if(trade_wise_meta_data->trades_count) {
    if(cJSON_AddNumberToObject(item, "trades_count", *trade_wise_meta_data->trades_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_wise_meta_data->page_size_limit
    if(trade_wise_meta_data->page_size_limit) {
    if(cJSON_AddNumberToObject(item, "page_size_limit", *trade_wise_meta_data->page_size_limit) == NULL) {
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

trade_wise_meta_data_t *trade_wise_meta_data_parseFromJSON(cJSON *trade_wise_meta_dataJSON){

    trade_wise_meta_data_t *trade_wise_meta_data_local_var = NULL;

    // define the local variable for trade_wise_meta_data->trades_count
    int *trades_count_local_var = NULL;

    // define the local variable for trade_wise_meta_data->page_size_limit
    int *page_size_limit_local_var = NULL;

    // trade_wise_meta_data->trades_count
    cJSON *trades_count = cJSON_GetObjectItemCaseSensitive(trade_wise_meta_dataJSON, "trades_count");
    if (cJSON_IsNull(trades_count)) {
        trades_count = NULL;
    }
    if (trades_count) { 
    if(!cJSON_IsNumber(trades_count))
    {
    goto end; //Numeric
    }
    trades_count_local_var = malloc(sizeof(int));
    if(!trades_count_local_var)
    {
        goto end;
    }
    *trades_count_local_var = trades_count->valuedouble;
    }

    // trade_wise_meta_data->page_size_limit
    cJSON *page_size_limit = cJSON_GetObjectItemCaseSensitive(trade_wise_meta_dataJSON, "page_size_limit");
    if (cJSON_IsNull(page_size_limit)) {
        page_size_limit = NULL;
    }
    if (page_size_limit) { 
    if(!cJSON_IsNumber(page_size_limit))
    {
    goto end; //Numeric
    }
    page_size_limit_local_var = malloc(sizeof(int));
    if(!page_size_limit_local_var)
    {
        goto end;
    }
    *page_size_limit_local_var = page_size_limit->valuedouble;
    }



    trade_wise_meta_data_local_var = trade_wise_meta_data_create_internal (
        trades_count_local_var,
        page_size_limit_local_var
        );

    if (!trade_wise_meta_data_local_var) {
        goto end;
    }

    return trade_wise_meta_data_local_var;
end:
    if (trades_count_local_var) {
        free(trades_count_local_var);
        trades_count_local_var = NULL;
    }
    if (page_size_limit_local_var) {
        free(page_size_limit_local_var);
        page_size_limit_local_var = NULL;
    }
    return NULL;

}
