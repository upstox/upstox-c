#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "balance_sheet_data.h"



static balance_sheet_data_t *balance_sheet_data_create_internal(
    char *type,
    char *time_period,
    char *units_in,
    list_t *history,
    list_t *full_statement
    ) {
    balance_sheet_data_t *balance_sheet_data_local_var = malloc(sizeof(balance_sheet_data_t));
    if (!balance_sheet_data_local_var) {
        return NULL;
    }
    memset(balance_sheet_data_local_var, 0, sizeof(balance_sheet_data_t));
    balance_sheet_data_local_var->_library_owned = 1;
    balance_sheet_data_local_var->type = type;
    balance_sheet_data_local_var->time_period = time_period;
    balance_sheet_data_local_var->units_in = units_in;
    balance_sheet_data_local_var->history = history;
    balance_sheet_data_local_var->full_statement = full_statement;
    return balance_sheet_data_local_var;
}

balance_sheet_data_t *balance_sheet_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *history,
    list_t *full_statement
    ) {
    balance_sheet_data_t *result = balance_sheet_data_create_internal (
        type,
        time_period,
        units_in,
        history,
        full_statement
        );
    if (!result) {
    }
    return result;
}

void balance_sheet_data_free(balance_sheet_data_t *balance_sheet_data) {
    if(NULL == balance_sheet_data){
        return ;
    }
    if(balance_sheet_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "balance_sheet_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (balance_sheet_data->type) {
        free(balance_sheet_data->type);
        balance_sheet_data->type = NULL;
    }
    if (balance_sheet_data->time_period) {
        free(balance_sheet_data->time_period);
        balance_sheet_data->time_period = NULL;
    }
    if (balance_sheet_data->units_in) {
        free(balance_sheet_data->units_in);
        balance_sheet_data->units_in = NULL;
    }
    if (balance_sheet_data->history) {
        list_ForEach(listEntry, balance_sheet_data->history) {
            balance_sheet_history_item_free(listEntry->data);
        }
        list_freeList(balance_sheet_data->history);
        balance_sheet_data->history = NULL;
    }
    if (balance_sheet_data->full_statement) {
        list_ForEach(listEntry, balance_sheet_data->full_statement) {
            financial_statement_entry_free(listEntry->data);
        }
        list_freeList(balance_sheet_data->full_statement);
        balance_sheet_data->full_statement = NULL;
    }
    free(balance_sheet_data);
}

cJSON *balance_sheet_data_convertToJSON(balance_sheet_data_t *balance_sheet_data) {
    cJSON *item = cJSON_CreateObject();

    // balance_sheet_data->type
    if(balance_sheet_data->type) {
    if(cJSON_AddStringToObject(item, "type", balance_sheet_data->type) == NULL) {
    goto fail; //String
    }
    }


    // balance_sheet_data->time_period
    if(balance_sheet_data->time_period) {
    if(cJSON_AddStringToObject(item, "time_period", balance_sheet_data->time_period) == NULL) {
    goto fail; //String
    }
    }


    // balance_sheet_data->units_in
    if(balance_sheet_data->units_in) {
    if(cJSON_AddStringToObject(item, "units_in", balance_sheet_data->units_in) == NULL) {
    goto fail; //String
    }
    }


    // balance_sheet_data->history
    if(balance_sheet_data->history) {
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (balance_sheet_data->history) {
    list_ForEach(historyListEntry, balance_sheet_data->history) {
    cJSON *itemLocal = balance_sheet_history_item_convertToJSON(historyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(history, itemLocal);
    }
    }
    }


    // balance_sheet_data->full_statement
    if(balance_sheet_data->full_statement) {
    cJSON *full_statement = cJSON_AddArrayToObject(item, "full_statement");
    if(full_statement == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *full_statementListEntry;
    if (balance_sheet_data->full_statement) {
    list_ForEach(full_statementListEntry, balance_sheet_data->full_statement) {
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

balance_sheet_data_t *balance_sheet_data_parseFromJSON(cJSON *balance_sheet_dataJSON){

    balance_sheet_data_t *balance_sheet_data_local_var = NULL;

    char *type_local_str = NULL;

    char *time_period_local_str = NULL;

    char *units_in_local_str = NULL;

    // define the local list for balance_sheet_data->history
    list_t *historyList = NULL;

    // define the local list for balance_sheet_data->full_statement
    list_t *full_statementList = NULL;

    // balance_sheet_data->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(balance_sheet_dataJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // balance_sheet_data->time_period
    cJSON *time_period = cJSON_GetObjectItemCaseSensitive(balance_sheet_dataJSON, "time_period");
    if (cJSON_IsNull(time_period)) {
        time_period = NULL;
    }
    if (time_period) { 
    if(!cJSON_IsString(time_period) && !cJSON_IsNull(time_period))
    {
    goto end; //String
    }
    }

    // balance_sheet_data->units_in
    cJSON *units_in = cJSON_GetObjectItemCaseSensitive(balance_sheet_dataJSON, "units_in");
    if (cJSON_IsNull(units_in)) {
        units_in = NULL;
    }
    if (units_in) { 
    if(!cJSON_IsString(units_in) && !cJSON_IsNull(units_in))
    {
    goto end; //String
    }
    }

    // balance_sheet_data->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(balance_sheet_dataJSON, "history");
    if (cJSON_IsNull(history)) {
        history = NULL;
    }
    if (history) { 
    cJSON *history_local_nonprimitive = NULL;
    if(!cJSON_IsArray(history)){
        goto end; //nonprimitive container
    }

    historyList = list_createList();

    cJSON_ArrayForEach(history_local_nonprimitive,history )
    {
        if(!cJSON_IsObject(history_local_nonprimitive)){
            goto end;
        }
        balance_sheet_history_item_t *historyItem = balance_sheet_history_item_parseFromJSON(history_local_nonprimitive);

        list_addElement(historyList, historyItem);
    }
    }

    // balance_sheet_data->full_statement
    cJSON *full_statement = cJSON_GetObjectItemCaseSensitive(balance_sheet_dataJSON, "full_statement");
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

    balance_sheet_data_local_var = balance_sheet_data_create_internal (
        type_local_str,
        time_period_local_str,
        units_in_local_str,
        history ? historyList : NULL,
        full_statement ? full_statementList : NULL
        );

    if (!balance_sheet_data_local_var) {
        goto end;
    }

    return balance_sheet_data_local_var;
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
    if (historyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, historyList) {
            balance_sheet_history_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(historyList);
        historyList = NULL;
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
