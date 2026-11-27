#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_flow_data.h"



static cash_flow_data_t *cash_flow_data_create_internal(
    char *type,
    char *time_period,
    char *units_in,
    list_t *cash_flow,
    list_t *full_statement
    ) {
    cash_flow_data_t *cash_flow_data_local_var = malloc(sizeof(cash_flow_data_t));
    if (!cash_flow_data_local_var) {
        return NULL;
    }
    memset(cash_flow_data_local_var, 0, sizeof(cash_flow_data_t));
    cash_flow_data_local_var->_library_owned = 1;
    cash_flow_data_local_var->type = type;
    cash_flow_data_local_var->time_period = time_period;
    cash_flow_data_local_var->units_in = units_in;
    cash_flow_data_local_var->cash_flow = cash_flow;
    cash_flow_data_local_var->full_statement = full_statement;
    return cash_flow_data_local_var;
}

cash_flow_data_t *cash_flow_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *cash_flow,
    list_t *full_statement
    ) {
    cash_flow_data_t *result = cash_flow_data_create_internal (
        type,
        time_period,
        units_in,
        cash_flow,
        full_statement
        );
    if (!result) {
    }
    return result;
}

void cash_flow_data_free(cash_flow_data_t *cash_flow_data) {
    if(NULL == cash_flow_data){
        return ;
    }
    if(cash_flow_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_flow_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_flow_data->type) {
        free(cash_flow_data->type);
        cash_flow_data->type = NULL;
    }
    if (cash_flow_data->time_period) {
        free(cash_flow_data->time_period);
        cash_flow_data->time_period = NULL;
    }
    if (cash_flow_data->units_in) {
        free(cash_flow_data->units_in);
        cash_flow_data->units_in = NULL;
    }
    if (cash_flow_data->cash_flow) {
        list_ForEach(listEntry, cash_flow_data->cash_flow) {
            cash_flow_entry_free(listEntry->data);
        }
        list_freeList(cash_flow_data->cash_flow);
        cash_flow_data->cash_flow = NULL;
    }
    if (cash_flow_data->full_statement) {
        list_ForEach(listEntry, cash_flow_data->full_statement) {
            financial_statement_entry_free(listEntry->data);
        }
        list_freeList(cash_flow_data->full_statement);
        cash_flow_data->full_statement = NULL;
    }
    free(cash_flow_data);
}

cJSON *cash_flow_data_convertToJSON(cash_flow_data_t *cash_flow_data) {
    cJSON *item = cJSON_CreateObject();

    // cash_flow_data->type
    if(cash_flow_data->type) {
    if(cJSON_AddStringToObject(item, "type", cash_flow_data->type) == NULL) {
    goto fail; //String
    }
    }


    // cash_flow_data->time_period
    if(cash_flow_data->time_period) {
    if(cJSON_AddStringToObject(item, "time_period", cash_flow_data->time_period) == NULL) {
    goto fail; //String
    }
    }


    // cash_flow_data->units_in
    if(cash_flow_data->units_in) {
    if(cJSON_AddStringToObject(item, "units_in", cash_flow_data->units_in) == NULL) {
    goto fail; //String
    }
    }


    // cash_flow_data->cash_flow
    if(cash_flow_data->cash_flow) {
    cJSON *cash_flow = cJSON_AddArrayToObject(item, "cash_flow");
    if(cash_flow == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *cash_flowListEntry;
    if (cash_flow_data->cash_flow) {
    list_ForEach(cash_flowListEntry, cash_flow_data->cash_flow) {
    cJSON *itemLocal = cash_flow_entry_convertToJSON(cash_flowListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(cash_flow, itemLocal);
    }
    }
    }


    // cash_flow_data->full_statement
    if(cash_flow_data->full_statement) {
    cJSON *full_statement = cJSON_AddArrayToObject(item, "full_statement");
    if(full_statement == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *full_statementListEntry;
    if (cash_flow_data->full_statement) {
    list_ForEach(full_statementListEntry, cash_flow_data->full_statement) {
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

cash_flow_data_t *cash_flow_data_parseFromJSON(cJSON *cash_flow_dataJSON){

    cash_flow_data_t *cash_flow_data_local_var = NULL;

    char *type_local_str = NULL;

    char *time_period_local_str = NULL;

    char *units_in_local_str = NULL;

    // define the local list for cash_flow_data->cash_flow
    list_t *cash_flowList = NULL;

    // define the local list for cash_flow_data->full_statement
    list_t *full_statementList = NULL;

    // cash_flow_data->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(cash_flow_dataJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // cash_flow_data->time_period
    cJSON *time_period = cJSON_GetObjectItemCaseSensitive(cash_flow_dataJSON, "time_period");
    if (cJSON_IsNull(time_period)) {
        time_period = NULL;
    }
    if (time_period) { 
    if(!cJSON_IsString(time_period) && !cJSON_IsNull(time_period))
    {
    goto end; //String
    }
    }

    // cash_flow_data->units_in
    cJSON *units_in = cJSON_GetObjectItemCaseSensitive(cash_flow_dataJSON, "units_in");
    if (cJSON_IsNull(units_in)) {
        units_in = NULL;
    }
    if (units_in) { 
    if(!cJSON_IsString(units_in) && !cJSON_IsNull(units_in))
    {
    goto end; //String
    }
    }

    // cash_flow_data->cash_flow
    cJSON *cash_flow = cJSON_GetObjectItemCaseSensitive(cash_flow_dataJSON, "cash_flow");
    if (cJSON_IsNull(cash_flow)) {
        cash_flow = NULL;
    }
    if (cash_flow) { 
    cJSON *cash_flow_local_nonprimitive = NULL;
    if(!cJSON_IsArray(cash_flow)){
        goto end; //nonprimitive container
    }

    cash_flowList = list_createList();

    cJSON_ArrayForEach(cash_flow_local_nonprimitive,cash_flow )
    {
        if(!cJSON_IsObject(cash_flow_local_nonprimitive)){
            goto end;
        }
        cash_flow_entry_t *cash_flowItem = cash_flow_entry_parseFromJSON(cash_flow_local_nonprimitive);

        list_addElement(cash_flowList, cash_flowItem);
    }
    }

    // cash_flow_data->full_statement
    cJSON *full_statement = cJSON_GetObjectItemCaseSensitive(cash_flow_dataJSON, "full_statement");
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

    cash_flow_data_local_var = cash_flow_data_create_internal (
        type_local_str,
        time_period_local_str,
        units_in_local_str,
        cash_flow ? cash_flowList : NULL,
        full_statement ? full_statementList : NULL
        );

    if (!cash_flow_data_local_var) {
        goto end;
    }

    return cash_flow_data_local_var;
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
    if (cash_flowList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, cash_flowList) {
            cash_flow_entry_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(cash_flowList);
        cash_flowList = NULL;
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
