#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pagination.h"



static pagination_t *pagination_create_internal(
    int *page_number,
    int *total_pages,
    int *records,
    int *total_records
    ) {
    pagination_t *pagination_local_var = malloc(sizeof(pagination_t));
    if (!pagination_local_var) {
        return NULL;
    }
    memset(pagination_local_var, 0, sizeof(pagination_t));
    pagination_local_var->_library_owned = 1;
    pagination_local_var->page_number = page_number;
    pagination_local_var->total_pages = total_pages;
    pagination_local_var->records = records;
    pagination_local_var->total_records = total_records;
    return pagination_local_var;
}

pagination_t *pagination_create(
    int *page_number,
    int *total_pages,
    int *records,
    int *total_records
    ) {
    int *page_number_copy = NULL;
    if (page_number) {
        page_number_copy = malloc(sizeof(int));
        if (page_number_copy) *page_number_copy = *page_number;
    }
    int *total_pages_copy = NULL;
    if (total_pages) {
        total_pages_copy = malloc(sizeof(int));
        if (total_pages_copy) *total_pages_copy = *total_pages;
    }
    int *records_copy = NULL;
    if (records) {
        records_copy = malloc(sizeof(int));
        if (records_copy) *records_copy = *records;
    }
    int *total_records_copy = NULL;
    if (total_records) {
        total_records_copy = malloc(sizeof(int));
        if (total_records_copy) *total_records_copy = *total_records;
    }
    pagination_t *result = pagination_create_internal (
        page_number_copy,
        total_pages_copy,
        records_copy,
        total_records_copy
        );
    if (!result) {
        free(page_number_copy);
        free(total_pages_copy);
        free(records_copy);
        free(total_records_copy);
    }
    return result;
}

void pagination_free(pagination_t *pagination) {
    if(NULL == pagination){
        return ;
    }
    if(pagination->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pagination_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pagination->page_number) {
        free(pagination->page_number);
        pagination->page_number = NULL;
    }
    if (pagination->total_pages) {
        free(pagination->total_pages);
        pagination->total_pages = NULL;
    }
    if (pagination->records) {
        free(pagination->records);
        pagination->records = NULL;
    }
    if (pagination->total_records) {
        free(pagination->total_records);
        pagination->total_records = NULL;
    }
    free(pagination);
}

cJSON *pagination_convertToJSON(pagination_t *pagination) {
    cJSON *item = cJSON_CreateObject();

    // pagination->page_number
    if(pagination->page_number) {
    if(cJSON_AddNumberToObject(item, "page_number", *pagination->page_number) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->total_pages
    if(pagination->total_pages) {
    if(cJSON_AddNumberToObject(item, "total_pages", *pagination->total_pages) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->records
    if(pagination->records) {
    if(cJSON_AddNumberToObject(item, "records", *pagination->records) == NULL) {
    goto fail; //Numeric
    }
    }


    // pagination->total_records
    if(pagination->total_records) {
    if(cJSON_AddNumberToObject(item, "total_records", *pagination->total_records) == NULL) {
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

pagination_t *pagination_parseFromJSON(cJSON *paginationJSON){

    pagination_t *pagination_local_var = NULL;

    // define the local variable for pagination->page_number
    int *page_number_local_var = NULL;

    // define the local variable for pagination->total_pages
    int *total_pages_local_var = NULL;

    // define the local variable for pagination->records
    int *records_local_var = NULL;

    // define the local variable for pagination->total_records
    int *total_records_local_var = NULL;

    // pagination->page_number
    cJSON *page_number = cJSON_GetObjectItemCaseSensitive(paginationJSON, "page_number");
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

    // pagination->total_pages
    cJSON *total_pages = cJSON_GetObjectItemCaseSensitive(paginationJSON, "total_pages");
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

    // pagination->records
    cJSON *records = cJSON_GetObjectItemCaseSensitive(paginationJSON, "records");
    if (cJSON_IsNull(records)) {
        records = NULL;
    }
    if (records) { 
    if(!cJSON_IsNumber(records))
    {
    goto end; //Numeric
    }
    records_local_var = malloc(sizeof(int));
    if(!records_local_var)
    {
        goto end;
    }
    *records_local_var = records->valuedouble;
    }

    // pagination->total_records
    cJSON *total_records = cJSON_GetObjectItemCaseSensitive(paginationJSON, "total_records");
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



    pagination_local_var = pagination_create_internal (
        page_number_local_var,
        total_pages_local_var,
        records_local_var,
        total_records_local_var
        );

    if (!pagination_local_var) {
        goto end;
    }

    return pagination_local_var;
end:
    if (page_number_local_var) {
        free(page_number_local_var);
        page_number_local_var = NULL;
    }
    if (total_pages_local_var) {
        free(total_pages_local_var);
        total_pages_local_var = NULL;
    }
    if (records_local_var) {
        free(records_local_var);
        records_local_var = NULL;
    }
    if (total_records_local_var) {
        free(total_records_local_var);
        total_records_local_var = NULL;
    }
    return NULL;

}
