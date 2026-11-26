#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_flow_entry.h"



static cash_flow_entry_t *cash_flow_entry_create_internal(
    char *category,
    list_t *history
    ) {
    cash_flow_entry_t *cash_flow_entry_local_var = malloc(sizeof(cash_flow_entry_t));
    if (!cash_flow_entry_local_var) {
        return NULL;
    }
    memset(cash_flow_entry_local_var, 0, sizeof(cash_flow_entry_t));
    cash_flow_entry_local_var->_library_owned = 1;
    cash_flow_entry_local_var->category = category;
    cash_flow_entry_local_var->history = history;
    return cash_flow_entry_local_var;
}

cash_flow_entry_t *cash_flow_entry_create(
    char *category,
    list_t *history
    ) {
    cash_flow_entry_t *result = cash_flow_entry_create_internal (
        category,
        history
        );
    if (!result) {
    }
    return result;
}

void cash_flow_entry_free(cash_flow_entry_t *cash_flow_entry) {
    if(NULL == cash_flow_entry){
        return ;
    }
    if(cash_flow_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_flow_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_flow_entry->category) {
        free(cash_flow_entry->category);
        cash_flow_entry->category = NULL;
    }
    if (cash_flow_entry->history) {
        list_ForEach(listEntry, cash_flow_entry->history) {
            history_item_free(listEntry->data);
        }
        list_freeList(cash_flow_entry->history);
        cash_flow_entry->history = NULL;
    }
    free(cash_flow_entry);
}

cJSON *cash_flow_entry_convertToJSON(cash_flow_entry_t *cash_flow_entry) {
    cJSON *item = cJSON_CreateObject();

    // cash_flow_entry->category
    if(cash_flow_entry->category) {
    if(cJSON_AddStringToObject(item, "category", cash_flow_entry->category) == NULL) {
    goto fail; //String
    }
    }


    // cash_flow_entry->history
    if(cash_flow_entry->history) {
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (cash_flow_entry->history) {
    list_ForEach(historyListEntry, cash_flow_entry->history) {
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

cash_flow_entry_t *cash_flow_entry_parseFromJSON(cJSON *cash_flow_entryJSON){

    cash_flow_entry_t *cash_flow_entry_local_var = NULL;

    char *category_local_str = NULL;

    // define the local list for cash_flow_entry->history
    list_t *historyList = NULL;

    // cash_flow_entry->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(cash_flow_entryJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // cash_flow_entry->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(cash_flow_entryJSON, "history");
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


    if (category && !cJSON_IsNull(category)) category_local_str = strdup(category->valuestring);

    cash_flow_entry_local_var = cash_flow_entry_create_internal (
        category_local_str,
        history ? historyList : NULL
        );

    if (!cash_flow_entry_local_var) {
        goto end;
    }

    return cash_flow_entry_local_var;
end:
    if (category_local_str) {
        free(category_local_str);
        category_local_str = NULL;
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
