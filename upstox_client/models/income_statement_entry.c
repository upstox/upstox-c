#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "income_statement_entry.h"



static income_statement_entry_t *income_statement_entry_create_internal(
    char *category,
    list_t *history
    ) {
    income_statement_entry_t *income_statement_entry_local_var = malloc(sizeof(income_statement_entry_t));
    if (!income_statement_entry_local_var) {
        return NULL;
    }
    memset(income_statement_entry_local_var, 0, sizeof(income_statement_entry_t));
    income_statement_entry_local_var->_library_owned = 1;
    income_statement_entry_local_var->category = category;
    income_statement_entry_local_var->history = history;
    return income_statement_entry_local_var;
}

income_statement_entry_t *income_statement_entry_create(
    char *category,
    list_t *history
    ) {
    income_statement_entry_t *result = income_statement_entry_create_internal (
        category,
        history
        );
    if (!result) {
    }
    return result;
}

void income_statement_entry_free(income_statement_entry_t *income_statement_entry) {
    if(NULL == income_statement_entry){
        return ;
    }
    if(income_statement_entry->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "income_statement_entry_free");
        return ;
    }
    listEntry_t *listEntry;
    if (income_statement_entry->category) {
        free(income_statement_entry->category);
        income_statement_entry->category = NULL;
    }
    if (income_statement_entry->history) {
        list_ForEach(listEntry, income_statement_entry->history) {
            history_item_free(listEntry->data);
        }
        list_freeList(income_statement_entry->history);
        income_statement_entry->history = NULL;
    }
    free(income_statement_entry);
}

cJSON *income_statement_entry_convertToJSON(income_statement_entry_t *income_statement_entry) {
    cJSON *item = cJSON_CreateObject();

    // income_statement_entry->category
    if(income_statement_entry->category) {
    if(cJSON_AddStringToObject(item, "category", income_statement_entry->category) == NULL) {
    goto fail; //String
    }
    }


    // income_statement_entry->history
    if(income_statement_entry->history) {
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (income_statement_entry->history) {
    list_ForEach(historyListEntry, income_statement_entry->history) {
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

income_statement_entry_t *income_statement_entry_parseFromJSON(cJSON *income_statement_entryJSON){

    income_statement_entry_t *income_statement_entry_local_var = NULL;

    char *category_local_str = NULL;

    // define the local list for income_statement_entry->history
    list_t *historyList = NULL;

    // income_statement_entry->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(income_statement_entryJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // income_statement_entry->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(income_statement_entryJSON, "history");
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

    income_statement_entry_local_var = income_statement_entry_create_internal (
        category_local_str,
        history ? historyList : NULL
        );

    if (!income_statement_entry_local_var) {
        goto end;
    }

    return income_statement_entry_local_var;
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
