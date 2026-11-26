#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "income_statement_data.h"



static income_statement_data_t *income_statement_data_create_internal(
    char *type,
    char *time_period,
    char *units_in,
    list_t *income_statement,
    list_t *full_statement
    ) {
    income_statement_data_t *income_statement_data_local_var = malloc(sizeof(income_statement_data_t));
    if (!income_statement_data_local_var) {
        return NULL;
    }
    memset(income_statement_data_local_var, 0, sizeof(income_statement_data_t));
    income_statement_data_local_var->_library_owned = 1;
    income_statement_data_local_var->type = type;
    income_statement_data_local_var->time_period = time_period;
    income_statement_data_local_var->units_in = units_in;
    income_statement_data_local_var->income_statement = income_statement;
    income_statement_data_local_var->full_statement = full_statement;
    return income_statement_data_local_var;
}

income_statement_data_t *income_statement_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *income_statement,
    list_t *full_statement
    ) {
    income_statement_data_t *result = income_statement_data_create_internal (
        type,
        time_period,
        units_in,
        income_statement,
        full_statement
        );
    if (!result) {
    }
    return result;
}

void income_statement_data_free(income_statement_data_t *income_statement_data) {
    if(NULL == income_statement_data){
        return ;
    }
    if(income_statement_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "income_statement_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (income_statement_data->type) {
        free(income_statement_data->type);
        income_statement_data->type = NULL;
    }
    if (income_statement_data->time_period) {
        free(income_statement_data->time_period);
        income_statement_data->time_period = NULL;
    }
    if (income_statement_data->units_in) {
        free(income_statement_data->units_in);
        income_statement_data->units_in = NULL;
    }
    if (income_statement_data->income_statement) {
        list_ForEach(listEntry, income_statement_data->income_statement) {
            income_statement_entry_free(listEntry->data);
        }
        list_freeList(income_statement_data->income_statement);
        income_statement_data->income_statement = NULL;
    }
    if (income_statement_data->full_statement) {
        list_ForEach(listEntry, income_statement_data->full_statement) {
            financial_statement_entry_free(listEntry->data);
        }
        list_freeList(income_statement_data->full_statement);
        income_statement_data->full_statement = NULL;
    }
    free(income_statement_data);
}

cJSON *income_statement_data_convertToJSON(income_statement_data_t *income_statement_data) {
    cJSON *item = cJSON_CreateObject();

    // income_statement_data->type
    if(income_statement_data->type) {
    if(cJSON_AddStringToObject(item, "type", income_statement_data->type) == NULL) {
    goto fail; //String
    }
    }


    // income_statement_data->time_period
    if(income_statement_data->time_period) {
    if(cJSON_AddStringToObject(item, "time_period", income_statement_data->time_period) == NULL) {
    goto fail; //String
    }
    }


    // income_statement_data->units_in
    if(income_statement_data->units_in) {
    if(cJSON_AddStringToObject(item, "units_in", income_statement_data->units_in) == NULL) {
    goto fail; //String
    }
    }


    // income_statement_data->income_statement
    if(income_statement_data->income_statement) {
    cJSON *income_statement = cJSON_AddArrayToObject(item, "income_statement");
    if(income_statement == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *income_statementListEntry;
    if (income_statement_data->income_statement) {
    list_ForEach(income_statementListEntry, income_statement_data->income_statement) {
    cJSON *itemLocal = income_statement_entry_convertToJSON(income_statementListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(income_statement, itemLocal);
    }
    }
    }


    // income_statement_data->full_statement
    if(income_statement_data->full_statement) {
    cJSON *full_statement = cJSON_AddArrayToObject(item, "full_statement");
    if(full_statement == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *full_statementListEntry;
    if (income_statement_data->full_statement) {
    list_ForEach(full_statementListEntry, income_statement_data->full_statement) {
    cJSON *itemLocal = financial_statement_entry_convertToJSON(full_statementListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(full_statement, itemLocal);
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

income_statement_data_t *income_statement_data_parseFromJSON(cJSON *income_statement_dataJSON){

    income_statement_data_t *income_statement_data_local_var = NULL;

    char *type_local_str = NULL;

    char *time_period_local_str = NULL;

    char *units_in_local_str = NULL;

    // define the local list for income_statement_data->income_statement
    list_t *income_statementList = NULL;

    // define the local list for income_statement_data->full_statement
    list_t *full_statementList = NULL;

    // income_statement_data->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(income_statement_dataJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // income_statement_data->time_period
    cJSON *time_period = cJSON_GetObjectItemCaseSensitive(income_statement_dataJSON, "time_period");
    if (cJSON_IsNull(time_period)) {
        time_period = NULL;
    }
    if (time_period) { 
    if(!cJSON_IsString(time_period) && !cJSON_IsNull(time_period))
    {
    goto end; //String
    }
    }

    // income_statement_data->units_in
    cJSON *units_in = cJSON_GetObjectItemCaseSensitive(income_statement_dataJSON, "units_in");
    if (cJSON_IsNull(units_in)) {
        units_in = NULL;
    }
    if (units_in) { 
    if(!cJSON_IsString(units_in) && !cJSON_IsNull(units_in))
    {
    goto end; //String
    }
    }

    // income_statement_data->income_statement
    cJSON *income_statement = cJSON_GetObjectItemCaseSensitive(income_statement_dataJSON, "income_statement");
    if (cJSON_IsNull(income_statement)) {
        income_statement = NULL;
    }
    if (income_statement) { 
    cJSON *income_statement_local_nonprimitive = NULL;
    if(!cJSON_IsArray(income_statement)){
        goto end; //nonprimitive container
    }

    income_statementList = list_createList();

    cJSON_ArrayForEach(income_statement_local_nonprimitive,income_statement )
    {
        if(!cJSON_IsObject(income_statement_local_nonprimitive)){
            goto end;
        }
        income_statement_entry_t *income_statementItem = income_statement_entry_parseFromJSON(income_statement_local_nonprimitive);

        list_addElement(income_statementList, income_statementItem);
    }
    }

    // income_statement_data->full_statement
    cJSON *full_statement = cJSON_GetObjectItemCaseSensitive(income_statement_dataJSON, "full_statement");
    if (cJSON_IsNull(full_statement)) {
        full_statement = NULL;
    }
    if (full_statement) { 
    cJSON *full_statement_local_nonprimitive = NULL;
    if(!cJSON_IsArray(full_statement)){
        goto end; //nonprimitive container
    }

    full_statementList = list_createList();

    cJSON_ArrayForEach(full_statement_local_nonprimitive,full_statement )
    {
        if(!cJSON_IsObject(full_statement_local_nonprimitive)){
            goto end;
        }
        financial_statement_entry_t *full_statementItem = financial_statement_entry_parseFromJSON(full_statement_local_nonprimitive);

        list_addElement(full_statementList, full_statementItem);
    }
    }


    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);
    if (time_period && !cJSON_IsNull(time_period)) time_period_local_str = strdup(time_period->valuestring);
    if (units_in && !cJSON_IsNull(units_in)) units_in_local_str = strdup(units_in->valuestring);

    income_statement_data_local_var = income_statement_data_create_internal (
        type_local_str,
        time_period_local_str,
        units_in_local_str,
        income_statement ? income_statementList : NULL,
        full_statement ? full_statementList : NULL
        );

    if (!income_statement_data_local_var) {
        goto end;
    }

    return income_statement_data_local_var;
end:
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    if (time_period_local_str) {
        free(time_period_local_str);
        time_period_local_str = NULL;
    }
    if (units_in_local_str) {
        free(units_in_local_str);
        units_in_local_str = NULL;
    }
    if (income_statementList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, income_statementList) {
            income_statement_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(income_statementList);
        income_statementList = NULL;
    }
    if (full_statementList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, full_statementList) {
            financial_statement_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(full_statementList);
        full_statementList = NULL;
    }
    return NULL;

}
