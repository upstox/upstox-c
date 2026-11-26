#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "margin_data.h"



static margin_data_t *margin_data_create_internal(
    list_t *margins,
    double *required_margin,
    double *final_margin
    ) {
    margin_data_t *margin_data_local_var = malloc(sizeof(margin_data_t));
    if (!margin_data_local_var) {
        return NULL;
    }
    memset(margin_data_local_var, 0, sizeof(margin_data_t));
    margin_data_local_var->_library_owned = 1;
    margin_data_local_var->margins = margins;
    margin_data_local_var->required_margin = required_margin;
    margin_data_local_var->final_margin = final_margin;
    return margin_data_local_var;
}

margin_data_t *margin_data_create(
    list_t *margins,
    double *required_margin,
    double *final_margin
    ) {
    double *required_margin_copy = NULL;
    if (required_margin) {
        required_margin_copy = malloc(sizeof(double));
        if (required_margin_copy) *required_margin_copy = *required_margin;
    }
    double *final_margin_copy = NULL;
    if (final_margin) {
        final_margin_copy = malloc(sizeof(double));
        if (final_margin_copy) *final_margin_copy = *final_margin;
    }
    margin_data_t *result = margin_data_create_internal (
        margins,
        required_margin_copy,
        final_margin_copy
        );
    if (!result) {
        free(required_margin_copy);
        free(final_margin_copy);
    }
    return result;
}

void margin_data_free(margin_data_t *margin_data) {
    if(NULL == margin_data){
        return ;
    }
    if(margin_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "margin_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (margin_data->margins) {
        list_ForEach(listEntry, margin_data->margins) {
            margin_free(listEntry->data);
        }
        list_freeList(margin_data->margins);
        margin_data->margins = NULL;
    }
    if (margin_data->required_margin) {
        free(margin_data->required_margin);
        margin_data->required_margin = NULL;
    }
    if (margin_data->final_margin) {
        free(margin_data->final_margin);
        margin_data->final_margin = NULL;
    }
    free(margin_data);
}

cJSON *margin_data_convertToJSON(margin_data_t *margin_data) {
    cJSON *item = cJSON_CreateObject();

    // margin_data->margins
    if(margin_data->margins) {
    cJSON *margins = cJSON_AddArrayToObject(item, "margins");
    if(margins == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *marginsListEntry;
    if (margin_data->margins) {
    list_ForEach(marginsListEntry, margin_data->margins) {
    cJSON *itemLocal = margin_convertToJSON(marginsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(margins, itemLocal);
    }
    }
    }


    // margin_data->required_margin
    if(margin_data->required_margin) {
    if(cJSON_AddNumberToObject(item, "required_margin", *margin_data->required_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin_data->final_margin
    if(margin_data->final_margin) {
    if(cJSON_AddNumberToObject(item, "final_margin", *margin_data->final_margin) == NULL) {
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

margin_data_t *margin_data_parseFromJSON(cJSON *margin_dataJSON){

    margin_data_t *margin_data_local_var = NULL;

    // define the local list for margin_data->margins
    list_t *marginsList = NULL;

    // define the local variable for margin_data->required_margin
    double *required_margin_local_var = NULL;

    // define the local variable for margin_data->final_margin
    double *final_margin_local_var = NULL;

    // margin_data->margins
    cJSON *margins = cJSON_GetObjectItemCaseSensitive(margin_dataJSON, "margins");
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
        margin_t *marginsItem = margin_parseFromJSON(margins_local_nonprimitive);

        list_addElement(marginsList, marginsItem);
    }
    }

    // margin_data->required_margin
    cJSON *required_margin = cJSON_GetObjectItemCaseSensitive(margin_dataJSON, "required_margin");
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

    // margin_data->final_margin
    cJSON *final_margin = cJSON_GetObjectItemCaseSensitive(margin_dataJSON, "final_margin");
    if (cJSON_IsNull(final_margin)) {
        final_margin = NULL;
    }
    if (final_margin) { 
    if(!cJSON_IsNumber(final_margin))
    {
    goto end; //Numeric
    }
    final_margin_local_var = malloc(sizeof(double));
    if(!final_margin_local_var)
    {
        goto end;
    }
    *final_margin_local_var = final_margin->valuedouble;
    }



    margin_data_local_var = margin_data_create_internal (
        margins ? marginsList : NULL,
        required_margin_local_var,
        final_margin_local_var
        );

    if (!margin_data_local_var) {
        goto end;
    }

    return margin_data_local_var;
end:
    if (marginsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, marginsList) {
            margin_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(marginsList);
        marginsList = NULL;
    }
    if (required_margin_local_var) {
        free(required_margin_local_var);
        required_margin_local_var = NULL;
    }
    if (final_margin_local_var) {
        free(final_margin_local_var);
        final_margin_local_var = NULL;
    }
    return NULL;

}
