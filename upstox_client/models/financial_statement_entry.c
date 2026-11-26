#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "financial_statement_entry.h"



static financial_statement_entry_t *financial_statement_entry_create_internal(
    char *particular,
    list_t *history
    ) {
    financial_statement_entry_t *financial_statement_entry_local_var = malloc(sizeof(financial_statement_entry_t));
    if (!financial_statement_entry_local_var) {
        return NULL;
    }
    memset(financial_statement_entry_local_var, 0, sizeof(financial_statement_entry_t));
    financial_statement_entry_local_var->_library_owned = 1;
    financial_statement_entry_local_var->particular = particular;
    financial_statement_entry_local_var->history = history;
    return financial_statement_entry_local_var;
}

financial_statement_entry_t *financial_statement_entry_create(
    char *particular,
    list_t *history
    ) {
    financial_statement_entry_t *result = financial_statement_entry_create_internal (
        particular,
        history
        );
    if (!result) {
    }
    return result;
}

void financial_statement_entry_free(financial_statement_entry_t *financial_statement_entry) {
    if(NULL == financial_statement_entry){
        return ;
    }
    if(financial_statement_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "financial_statement_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (financial_statement_entry->particular) {
        free(financial_statement_entry->particular);
        financial_statement_entry->particular = NULL;
    }
    if (financial_statement_entry->history) {
        list_ForEach(listEntry, financial_statement_entry->history) {
            history_item_free(listEntry->data);
        }
        list_freeList(financial_statement_entry->history);
        financial_statement_entry->history = NULL;
    }
    free(financial_statement_entry);
}

cJSON *financial_statement_entry_convertToJSON(financial_statement_entry_t *financial_statement_entry) {
    cJSON *item = cJSON_CreateObject();

    // financial_statement_entry->particular
    if(financial_statement_entry->particular) {
    if(cJSON_AddStringToObject(item, "particular", financial_statement_entry->particular) == NULL) {
    goto fail; //String
    }
    }


    // financial_statement_entry->history
    if(financial_statement_entry->history) {
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (financial_statement_entry->history) {
    list_ForEach(historyListEntry, financial_statement_entry->history) {
    cJSON *itemLocal = history_item_convertToJSON(historyListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(history, itemLocal);
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

financial_statement_entry_t *financial_statement_entry_parseFromJSON(cJSON *financial_statement_entryJSON){

    financial_statement_entry_t *financial_statement_entry_local_var = NULL;

    char *particular_local_str = NULL;

    // define the local list for financial_statement_entry->history
    list_t *historyList = NULL;

    // financial_statement_entry->particular
    cJSON *particular = cJSON_GetObjectItemCaseSensitive(financial_statement_entryJSON, "particular");
    if (cJSON_IsNull(particular)) {
        particular = NULL;
    }
    if (particular) { 
    if(!cJSON_IsString(particular) && !cJSON_IsNull(particular))
    {
    goto end; //String
    }
    }

    // financial_statement_entry->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(financial_statement_entryJSON, "history");
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
        history_item_t *historyItem = history_item_parseFromJSON(history_local_nonprimitive);

        list_addElement(historyList, historyItem);
    }
    }


    if (particular && !cJSON_IsNull(particular)) particular_local_str = strdup(particular->valuestring);

    financial_statement_entry_local_var = financial_statement_entry_create_internal (
        particular_local_str,
        history ? historyList : NULL
        );

    if (!financial_statement_entry_local_var) {
        goto end;
    }

    return financial_statement_entry_local_var;
end:
    if (particular_local_str) {
        free(particular_local_str);
        particular_local_str = NULL;
    }
    if (historyList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, historyList) {
            history_item_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(historyList);
        historyList = NULL;
    }
    return NULL;

}
