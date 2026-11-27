#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_history_response_page_data.h"



static trade_history_response_page_data_t *trade_history_response_page_data_create_internal(
    int *page_number,
    int *page_size,
    int *total_records,
    int *total_pages
    ) {
    trade_history_response_page_data_t *trade_history_response_page_data_local_var = malloc(sizeof(trade_history_response_page_data_t));
    if (!trade_history_response_page_data_local_var) {
        return NULL;
    }
    memset(trade_history_response_page_data_local_var, 0, sizeof(trade_history_response_page_data_t));
    trade_history_response_page_data_local_var->_library_owned = 1;
    trade_history_response_page_data_local_var->page_number = page_number;
    trade_history_response_page_data_local_var->page_size = page_size;
    trade_history_response_page_data_local_var->total_records = total_records;
    trade_history_response_page_data_local_var->total_pages = total_pages;
    return trade_history_response_page_data_local_var;
}

trade_history_response_page_data_t *trade_history_response_page_data_create(
    int *page_number,
    int *page_size,
    int *total_records,
    int *total_pages
    ) {
    int *page_number_copy = NULL;
    if (page_number) {
        page_number_copy = malloc(sizeof(int));
        if (page_number_copy) *page_number_copy = *page_number;
    }
    int *page_size_copy = NULL;
    if (page_size) {
        page_size_copy = malloc(sizeof(int));
        if (page_size_copy) *page_size_copy = *page_size;
    }
    int *total_records_copy = NULL;
    if (total_records) {
        total_records_copy = malloc(sizeof(int));
        if (total_records_copy) *total_records_copy = *total_records;
    }
    int *total_pages_copy = NULL;
    if (total_pages) {
        total_pages_copy = malloc(sizeof(int));
        if (total_pages_copy) *total_pages_copy = *total_pages;
    }
    trade_history_response_page_data_t *result = trade_history_response_page_data_create_internal (
        page_number_copy,
        page_size_copy,
        total_records_copy,
        total_pages_copy
        );
    if (!result) {
        free(page_number_copy);
        free(page_size_copy);
        free(total_records_copy);
        free(total_pages_copy);
    }
    return result;
}

void trade_history_response_page_data_free(trade_history_response_page_data_t *trade_history_response_page_data) {
    if(NULL == trade_history_response_page_data){
        return ;
    }
    if(trade_history_response_page_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_history_response_page_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_history_response_page_data->page_number) {
        free(trade_history_response_page_data->page_number);
        trade_history_response_page_data->page_number = NULL;
    }
    if (trade_history_response_page_data->page_size) {
        free(trade_history_response_page_data->page_size);
        trade_history_response_page_data->page_size = NULL;
    }
    if (trade_history_response_page_data->total_records) {
        free(trade_history_response_page_data->total_records);
        trade_history_response_page_data->total_records = NULL;
    }
    if (trade_history_response_page_data->total_pages) {
        free(trade_history_response_page_data->total_pages);
        trade_history_response_page_data->total_pages = NULL;
    }
    free(trade_history_response_page_data);
}

cJSON *trade_history_response_page_data_convertToJSON(trade_history_response_page_data_t *trade_history_response_page_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_history_response_page_data->page_number
    if(trade_history_response_page_data->page_number) {
    if(cJSON_AddNumberToObject(item, "page_number", *trade_history_response_page_data->page_number) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_page_data->page_size
    if(trade_history_response_page_data->page_size) {
    if(cJSON_AddNumberToObject(item, "page_size", *trade_history_response_page_data->page_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_page_data->total_records
    if(trade_history_response_page_data->total_records) {
    if(cJSON_AddNumberToObject(item, "total_records", *trade_history_response_page_data->total_records) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_history_response_page_data->total_pages
    if(trade_history_response_page_data->total_pages) {
    if(cJSON_AddNumberToObject(item, "total_pages", *trade_history_response_page_data->total_pages) == NULL) {
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

trade_history_response_page_data_t *trade_history_response_page_data_parseFromJSON(cJSON *trade_history_response_page_dataJSON){

    trade_history_response_page_data_t *trade_history_response_page_data_local_var = NULL;

    // define the local variable for trade_history_response_page_data->page_number
    int *page_number_local_var = NULL;

    // define the local variable for trade_history_response_page_data->page_size
    int *page_size_local_var = NULL;

    // define the local variable for trade_history_response_page_data->total_records
    int *total_records_local_var = NULL;

    // define the local variable for trade_history_response_page_data->total_pages
    int *total_pages_local_var = NULL;

    // trade_history_response_page_data->page_number
    cJSON *page_number = cJSON_GetObjectItemCaseSensitive(trade_history_response_page_dataJSON, "page_number");
    if (cJSON_IsNull(page_number)) {
        page_number = NULL;
    }
    if (page_number) { 
    if(!cJSON_IsNumber(page_number))
    {
    goto end; //Numeric
    }
    page_number_local_var = malloc(sizeof(int));
    if(!page_number_local_var)
    {
        goto end;
    }
    *page_number_local_var = page_number->valuedouble;
    }

    // trade_history_response_page_data->page_size
    cJSON *page_size = cJSON_GetObjectItemCaseSensitive(trade_history_response_page_dataJSON, "page_size");
    if (cJSON_IsNull(page_size)) {
        page_size = NULL;
    }
    if (page_size) { 
    if(!cJSON_IsNumber(page_size))
    {
    goto end; //Numeric
    }
    page_size_local_var = malloc(sizeof(int));
    if(!page_size_local_var)
    {
        goto end;
    }
    *page_size_local_var = page_size->valuedouble;
    }

    // trade_history_response_page_data->total_records
    cJSON *total_records = cJSON_GetObjectItemCaseSensitive(trade_history_response_page_dataJSON, "total_records");
    if (cJSON_IsNull(total_records)) {
        total_records = NULL;
    }
    if (total_records) { 
    if(!cJSON_IsNumber(total_records))
    {
    goto end; //Numeric
    }
    total_records_local_var = malloc(sizeof(int));
    if(!total_records_local_var)
    {
        goto end;
    }
    *total_records_local_var = total_records->valuedouble;
    }

    // trade_history_response_page_data->total_pages
    cJSON *total_pages = cJSON_GetObjectItemCaseSensitive(trade_history_response_page_dataJSON, "total_pages");
    if (cJSON_IsNull(total_pages)) {
        total_pages = NULL;
    }
    if (total_pages) { 
    if(!cJSON_IsNumber(total_pages))
    {
    goto end; //Numeric
    }
    total_pages_local_var = malloc(sizeof(int));
    if(!total_pages_local_var)
    {
        goto end;
    }
    *total_pages_local_var = total_pages->valuedouble;
    }



    trade_history_response_page_data_local_var = trade_history_response_page_data_create_internal (
        page_number_local_var,
        page_size_local_var,
        total_records_local_var,
        total_pages_local_var
        );

    if (!trade_history_response_page_data_local_var) {
        goto end;
    }

    return trade_history_response_page_data_local_var;
end:
    if (page_number_local_var) {
        free(page_number_local_var);
        page_number_local_var = NULL;
    }
    if (page_size_local_var) {
        free(page_size_local_var);
        page_size_local_var = NULL;
    }
    if (total_records_local_var) {
        free(total_records_local_var);
        total_records_local_var = NULL;
    }
    if (total_pages_local_var) {
        free(total_pages_local_var);
        total_pages_local_var = NULL;
    }
    return NULL;

}
