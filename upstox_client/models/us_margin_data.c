#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_margin_data.h"



static us_margin_data_t *us_margin_data_create_internal(
    list_t *margins,
    double *shortfall,
    int *sufficient,
    double *required_margin,
    double *available_to_invest
    ) {
    us_margin_data_t *us_margin_data_local_var = malloc(sizeof(us_margin_data_t));
    if (!us_margin_data_local_var) {
        return NULL;
    }
    memset(us_margin_data_local_var, 0, sizeof(us_margin_data_t));
    us_margin_data_local_var->_library_owned = 1;
    us_margin_data_local_var->margins = margins;
    us_margin_data_local_var->shortfall = shortfall;
    us_margin_data_local_var->sufficient = sufficient;
    us_margin_data_local_var->required_margin = required_margin;
    us_margin_data_local_var->available_to_invest = available_to_invest;
    return us_margin_data_local_var;
}

us_margin_data_t *us_margin_data_create(
    list_t *margins,
    double *shortfall,
    int *sufficient,
    double *required_margin,
    double *available_to_invest
    ) {
    double *shortfall_copy = NULL;
    if (shortfall) {
        shortfall_copy = malloc(sizeof(double));
        if (shortfall_copy) *shortfall_copy = *shortfall;
    }
    int *sufficient_copy = NULL;
    if (sufficient) {
        sufficient_copy = malloc(sizeof(int));
        if (sufficient_copy) *sufficient_copy = *sufficient;
    }
    double *required_margin_copy = NULL;
    if (required_margin) {
        required_margin_copy = malloc(sizeof(double));
        if (required_margin_copy) *required_margin_copy = *required_margin;
    }
    double *available_to_invest_copy = NULL;
    if (available_to_invest) {
        available_to_invest_copy = malloc(sizeof(double));
        if (available_to_invest_copy) *available_to_invest_copy = *available_to_invest;
    }
    us_margin_data_t *result = us_margin_data_create_internal (
        margins,
        shortfall_copy,
        sufficient_copy,
        required_margin_copy,
        available_to_invest_copy
        );
    if (!result) {
        free(shortfall_copy);
        free(sufficient_copy);
        free(required_margin_copy);
        free(available_to_invest_copy);
    }
    return result;
}

void us_margin_data_free(us_margin_data_t *us_margin_data) {
    if(NULL == us_margin_data){
        return ;
    }
    if(us_margin_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_margin_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_margin_data->margins) {
        list_ForEach(listEntry, us_margin_data->margins) {
            us_order_margin_free(listEntry->data);
        }
        list_freeList(us_margin_data->margins);
        us_margin_data->margins = NULL;
    }
    if (us_margin_data->shortfall) {
        free(us_margin_data->shortfall);
        us_margin_data->shortfall = NULL;
    }
    if (us_margin_data->sufficient) {
        free(us_margin_data->sufficient);
        us_margin_data->sufficient = NULL;
    }
    if (us_margin_data->required_margin) {
        free(us_margin_data->required_margin);
        us_margin_data->required_margin = NULL;
    }
    if (us_margin_data->available_to_invest) {
        free(us_margin_data->available_to_invest);
        us_margin_data->available_to_invest = NULL;
    }
    free(us_margin_data);
}

cJSON *us_margin_data_convertToJSON(us_margin_data_t *us_margin_data) {
    cJSON *item = cJSON_CreateObject();

    // us_margin_data->margins
    if(us_margin_data->margins) {
    cJSON *margins = cJSON_AddArrayToObject(item, "margins");
    if(margins == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *marginsListEntry;
    if (us_margin_data->margins) {
    list_ForEach(marginsListEntry, us_margin_data->margins) {
    cJSON *itemLocal = us_order_margin_convertToJSON(marginsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(margins, itemLocal);
    }
    }
    }


    // us_margin_data->shortfall
    if(us_margin_data->shortfall) {
    if(cJSON_AddNumberToObject(item, "shortfall", *us_margin_data->shortfall) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_margin_data->sufficient
    if(us_margin_data->sufficient) {
    if(cJSON_AddBoolToObject(item, "sufficient", *us_margin_data->sufficient) == NULL) {
    goto fail; //Bool
    }
    }


    // us_margin_data->required_margin
    if(us_margin_data->required_margin) {
    if(cJSON_AddNumberToObject(item, "required_margin", *us_margin_data->required_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_margin_data->available_to_invest
    if(us_margin_data->available_to_invest) {
    if(cJSON_AddNumberToObject(item, "available_to_invest", *us_margin_data->available_to_invest) == NULL) {
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

us_margin_data_t *us_margin_data_parseFromJSON(cJSON *us_margin_dataJSON){

    us_margin_data_t *us_margin_data_local_var = NULL;

    // define the local list for us_margin_data->margins
    list_t *marginsList = NULL;

    // define the local variable for us_margin_data->shortfall
    double *shortfall_local_var = NULL;

    // define the local variable for us_margin_data->sufficient
    int *sufficient_local_var = NULL;

    // define the local variable for us_margin_data->required_margin
    double *required_margin_local_var = NULL;

    // define the local variable for us_margin_data->available_to_invest
    double *available_to_invest_local_var = NULL;

    // us_margin_data->margins
    cJSON *margins = cJSON_GetObjectItemCaseSensitive(us_margin_dataJSON, "margins");
    if (cJSON_IsNull(margins)) {
        margins = NULL;
    }
    if (margins) { 
    cJSON *margins_local_nonprimitive = NULL;
    if(!cJSON_IsArray(margins)){
        goto end; //nonprimitive container
    }

    marginsList = list_createList();

    cJSON_ArrayForEach(margins_local_nonprimitive,margins )
    {
        if(!cJSON_IsObject(margins_local_nonprimitive)){
            goto end;
        }
        us_order_margin_t *marginsItem = us_order_margin_parseFromJSON(margins_local_nonprimitive);

        list_addElement(marginsList, marginsItem);
    }
    }

    // us_margin_data->shortfall
    cJSON *shortfall = cJSON_GetObjectItemCaseSensitive(us_margin_dataJSON, "shortfall");
    if (cJSON_IsNull(shortfall)) {
        shortfall = NULL;
    }
    if (shortfall) { 
    if(!cJSON_IsNumber(shortfall))
    {
    goto end; //Numeric
    }
    shortfall_local_var = malloc(sizeof(double));
    if(!shortfall_local_var)
    {
        goto end;
    }
    *shortfall_local_var = shortfall->valuedouble;
    }

    // us_margin_data->sufficient
    cJSON *sufficient = cJSON_GetObjectItemCaseSensitive(us_margin_dataJSON, "sufficient");
    if (cJSON_IsNull(sufficient)) {
        sufficient = NULL;
    }
    if (sufficient) { 
    if(!cJSON_IsBool(sufficient))
    {
    goto end; //Bool
    }
    sufficient_local_var = malloc(sizeof(int));
    if(!sufficient_local_var)
    {
        goto end;
    }
    *sufficient_local_var = sufficient->valueint;
    }

    // us_margin_data->required_margin
    cJSON *required_margin = cJSON_GetObjectItemCaseSensitive(us_margin_dataJSON, "required_margin");
    if (cJSON_IsNull(required_margin)) {
        required_margin = NULL;
    }
    if (required_margin) { 
    if(!cJSON_IsNumber(required_margin))
    {
    goto end; //Numeric
    }
    required_margin_local_var = malloc(sizeof(double));
    if(!required_margin_local_var)
    {
        goto end;
    }
    *required_margin_local_var = required_margin->valuedouble;
    }

    // us_margin_data->available_to_invest
    cJSON *available_to_invest = cJSON_GetObjectItemCaseSensitive(us_margin_dataJSON, "available_to_invest");
    if (cJSON_IsNull(available_to_invest)) {
        available_to_invest = NULL;
    }
    if (available_to_invest) { 
    if(!cJSON_IsNumber(available_to_invest))
    {
    goto end; //Numeric
    }
    available_to_invest_local_var = malloc(sizeof(double));
    if(!available_to_invest_local_var)
    {
        goto end;
    }
    *available_to_invest_local_var = available_to_invest->valuedouble;
    }



    us_margin_data_local_var = us_margin_data_create_internal (
        margins ? marginsList : NULL,
        shortfall_local_var,
        sufficient_local_var,
        required_margin_local_var,
        available_to_invest_local_var
        );

    if (!us_margin_data_local_var) {
        goto end;
    }

    return us_margin_data_local_var;
end:
    if (marginsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, marginsList) {
            us_order_margin_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(marginsList);
        marginsList = NULL;
    }
    if (shortfall_local_var) {
        free(shortfall_local_var);
        shortfall_local_var = NULL;
    }
    if (sufficient_local_var) {
        free(sufficient_local_var);
        sufficient_local_var = NULL;
    }
    if (required_margin_local_var) {
        free(required_margin_local_var);
        required_margin_local_var = NULL;
    }
    if (available_to_invest_local_var) {
        free(available_to_invest_local_var);
        available_to_invest_local_var = NULL;
    }
    return NULL;

}
