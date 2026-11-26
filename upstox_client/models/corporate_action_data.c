#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "corporate_action_data.h"



static corporate_action_data_t *corporate_action_data_create_internal(
    char *name,
    char *expiry_date,
    double *amount,
    char *ratio,
    list_t *event_details
    ) {
    corporate_action_data_t *corporate_action_data_local_var = malloc(sizeof(corporate_action_data_t));
    if (!corporate_action_data_local_var) {
        return NULL;
    }
    memset(corporate_action_data_local_var, 0, sizeof(corporate_action_data_t));
    corporate_action_data_local_var->_library_owned = 1;
    corporate_action_data_local_var->name = name;
    corporate_action_data_local_var->expiry_date = expiry_date;
    corporate_action_data_local_var->amount = amount;
    corporate_action_data_local_var->ratio = ratio;
    corporate_action_data_local_var->event_details = event_details;
    return corporate_action_data_local_var;
}

corporate_action_data_t *corporate_action_data_create(
    char *name,
    char *expiry_date,
    double *amount,
    char *ratio,
    list_t *event_details
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    corporate_action_data_t *result = corporate_action_data_create_internal (
        name,
        expiry_date,
        amount_copy,
        ratio,
        event_details
        );
    if (!result) {
        free(amount_copy);
    }
    return result;
}

void corporate_action_data_free(corporate_action_data_t *corporate_action_data) {
    if(NULL == corporate_action_data){
        return ;
    }
    if(corporate_action_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "corporate_action_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (corporate_action_data->name) {
        free(corporate_action_data->name);
        corporate_action_data->name = NULL;
    }
    if (corporate_action_data->expiry_date) {
        free(corporate_action_data->expiry_date);
        corporate_action_data->expiry_date = NULL;
    }
    if (corporate_action_data->amount) {
        free(corporate_action_data->amount);
        corporate_action_data->amount = NULL;
    }
    if (corporate_action_data->ratio) {
        free(corporate_action_data->ratio);
        corporate_action_data->ratio = NULL;
    }
    if (corporate_action_data->event_details) {
        list_ForEach(listEntry, corporate_action_data->event_details) {
            corporate_action_event_detail_free(listEntry->data);
        }
        list_freeList(corporate_action_data->event_details);
        corporate_action_data->event_details = NULL;
    }
    free(corporate_action_data);
}

cJSON *corporate_action_data_convertToJSON(corporate_action_data_t *corporate_action_data) {
    cJSON *item = cJSON_CreateObject();

    // corporate_action_data->name
    if(corporate_action_data->name) {
    if(cJSON_AddStringToObject(item, "name", corporate_action_data->name) == NULL) {
    goto fail; //String
    }
    }


    // corporate_action_data->expiry_date
    if(corporate_action_data->expiry_date) {
    if(cJSON_AddStringToObject(item, "expiry_date", corporate_action_data->expiry_date) == NULL) {
    goto fail; //String
    }
    }


    // corporate_action_data->amount
    if(corporate_action_data->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *corporate_action_data->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // corporate_action_data->ratio
    if(corporate_action_data->ratio) {
    if(cJSON_AddStringToObject(item, "ratio", corporate_action_data->ratio) == NULL) {
    goto fail; //String
    }
    }


    // corporate_action_data->event_details
    if(corporate_action_data->event_details) {
    cJSON *event_details = cJSON_AddArrayToObject(item, "event_details");
    if(event_details == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *event_detailsListEntry;
    if (corporate_action_data->event_details) {
    list_ForEach(event_detailsListEntry, corporate_action_data->event_details) {
    cJSON *itemLocal = corporate_action_event_detail_convertToJSON(event_detailsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(event_details, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

corporate_action_data_t *corporate_action_data_parseFromJSON(cJSON *corporate_action_dataJSON){

    corporate_action_data_t *corporate_action_data_local_var = NULL;

    char *name_local_str = NULL;

    char *expiry_date_local_str = NULL;

    // define the local variable for corporate_action_data->amount
    double *amount_local_var = NULL;

    char *ratio_local_str = NULL;

    // define the local list for corporate_action_data->event_details
    list_t *event_detailsList = NULL;

    // corporate_action_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(corporate_action_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // corporate_action_data->expiry_date
    cJSON *expiry_date = cJSON_GetObjectItemCaseSensitive(corporate_action_dataJSON, "expiry_date");
    if (cJSON_IsNull(expiry_date)) {
        expiry_date = NULL;
    }
    if (expiry_date) { 
    if(!cJSON_IsString(expiry_date) && !cJSON_IsNull(expiry_date))
    {
    goto end; //String
    }
    }

    // corporate_action_data->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(corporate_action_dataJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (amount) { 
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    amount_local_var = malloc(sizeof(double));
    if(!amount_local_var)
    {
        goto end;
    }
    *amount_local_var = amount->valuedouble;
    }

    // corporate_action_data->ratio
    cJSON *ratio = cJSON_GetObjectItemCaseSensitive(corporate_action_dataJSON, "ratio");
    if (cJSON_IsNull(ratio)) {
        ratio = NULL;
    }
    if (ratio) { 
    if(!cJSON_IsString(ratio) && !cJSON_IsNull(ratio))
    {
    goto end; //String
    }
    }

    // corporate_action_data->event_details
    cJSON *event_details = cJSON_GetObjectItemCaseSensitive(corporate_action_dataJSON, "event_details");
    if (cJSON_IsNull(event_details)) {
        event_details = NULL;
    }
    if (event_details) { 
    cJSON *event_details_local_nonprimitive = NULL;
    if(!cJSON_IsArray(event_details)){
        goto end; //nonprimitive container
    }

    event_detailsList = list_createList();

    cJSON_ArrayForEach(event_details_local_nonprimitive,event_details )
    {
        if(!cJSON_IsObject(event_details_local_nonprimitive)){
            goto end;
        }
        corporate_action_event_detail_t *event_detailsItem = corporate_action_event_detail_parseFromJSON(event_details_local_nonprimitive);

        list_addElement(event_detailsList, event_detailsItem);
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (expiry_date && !cJSON_IsNull(expiry_date)) expiry_date_local_str = strdup(expiry_date->valuestring);
    if (ratio && !cJSON_IsNull(ratio)) ratio_local_str = strdup(ratio->valuestring);

    corporate_action_data_local_var = corporate_action_data_create_internal (
        name_local_str,
        expiry_date_local_str,
        amount_local_var,
        ratio_local_str,
        event_details ? event_detailsList : NULL
        );

    if (!corporate_action_data_local_var) {
        goto end;
    }

    return corporate_action_data_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (expiry_date_local_str) {
        free(expiry_date_local_str);
        expiry_date_local_str = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (ratio_local_str) {
        free(ratio_local_str);
        ratio_local_str = NULL;
    }
    if (event_detailsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, event_detailsList) {
            corporate_action_event_detail_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(event_detailsList);
        event_detailsList = NULL;
    }
    return NULL;

}
