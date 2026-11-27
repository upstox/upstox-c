#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_meta_data.h"



static profit_and_loss_meta_data_t *profit_and_loss_meta_data_create_internal(
    int *page_number,
    int *page_size
    ) {
    profit_and_loss_meta_data_t *profit_and_loss_meta_data_local_var = malloc(sizeof(profit_and_loss_meta_data_t));
    if (!profit_and_loss_meta_data_local_var) {
        return NULL;
    }
    memset(profit_and_loss_meta_data_local_var, 0, sizeof(profit_and_loss_meta_data_t));
    profit_and_loss_meta_data_local_var->_library_owned = 1;
    profit_and_loss_meta_data_local_var->page_number = page_number;
    profit_and_loss_meta_data_local_var->page_size = page_size;
    return profit_and_loss_meta_data_local_var;
}

profit_and_loss_meta_data_t *profit_and_loss_meta_data_create(
    int *page_number,
    int *page_size
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
    profit_and_loss_meta_data_t *result = profit_and_loss_meta_data_create_internal (
        page_number_copy,
        page_size_copy
        );
    if (!result) {
        free(page_number_copy);
        free(page_size_copy);
    }
    return result;
}

void profit_and_loss_meta_data_free(profit_and_loss_meta_data_t *profit_and_loss_meta_data) {
    if(NULL == profit_and_loss_meta_data){
        return ;
    }
    if(profit_and_loss_meta_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_meta_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_meta_data->page_number) {
        free(profit_and_loss_meta_data->page_number);
        profit_and_loss_meta_data->page_number = NULL;
    }
    if (profit_and_loss_meta_data->page_size) {
        free(profit_and_loss_meta_data->page_size);
        profit_and_loss_meta_data->page_size = NULL;
    }
    free(profit_and_loss_meta_data);
}

cJSON *profit_and_loss_meta_data_convertToJSON(profit_and_loss_meta_data_t *profit_and_loss_meta_data) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_meta_data->page_number
    if(profit_and_loss_meta_data->page_number) {
    if(cJSON_AddNumberToObject(item, "page_number", *profit_and_loss_meta_data->page_number) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_meta_data->page_size
    if(profit_and_loss_meta_data->page_size) {
    if(cJSON_AddNumberToObject(item, "page_size", *profit_and_loss_meta_data->page_size) == NULL) {
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

profit_and_loss_meta_data_t *profit_and_loss_meta_data_parseFromJSON(cJSON *profit_and_loss_meta_dataJSON){

    profit_and_loss_meta_data_t *profit_and_loss_meta_data_local_var = NULL;

    // define the local variable for profit_and_loss_meta_data->page_number
    int *page_number_local_var = NULL;

    // define the local variable for profit_and_loss_meta_data->page_size
    int *page_size_local_var = NULL;

    // profit_and_loss_meta_data->page_number
    cJSON *page_number = cJSON_GetObjectItemCaseSensitive(profit_and_loss_meta_dataJSON, "page_number");
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

    // profit_and_loss_meta_data->page_size
    cJSON *page_size = cJSON_GetObjectItemCaseSensitive(profit_and_loss_meta_dataJSON, "page_size");
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



    profit_and_loss_meta_data_local_var = profit_and_loss_meta_data_create_internal (
        page_number_local_var,
        page_size_local_var
        );

    if (!profit_and_loss_meta_data_local_var) {
        goto end;
    }

    return profit_and_loss_meta_data_local_var;
end:
    if (page_number_local_var) {
        free(page_number_local_var);
        page_number_local_var = NULL;
    }
    if (page_size_local_var) {
        free(page_size_local_var);
        page_size_local_var = NULL;
    }
    return NULL;

}
