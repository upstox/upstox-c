#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "share_holding_data.h"



static share_holding_data_t *share_holding_data_create_internal(
    char *category,
    list_t *history
    ) {
    share_holding_data_t *share_holding_data_local_var = malloc(sizeof(share_holding_data_t));
    if (!share_holding_data_local_var) {
        return NULL;
    }
    memset(share_holding_data_local_var, 0, sizeof(share_holding_data_t));
    share_holding_data_local_var->_library_owned = 1;
    share_holding_data_local_var->category = category;
    share_holding_data_local_var->history = history;
    return share_holding_data_local_var;
}

share_holding_data_t *share_holding_data_create(
    char *category,
    list_t *history
    ) {
    share_holding_data_t *result = share_holding_data_create_internal (
        category,
        history
        );
    if (!result) {
    }
    return result;
}

void share_holding_data_free(share_holding_data_t *share_holding_data) {
    if(NULL == share_holding_data){
        return ;
    }
    if(share_holding_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "share_holding_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (share_holding_data->category) {
        free(share_holding_data->category);
        share_holding_data->category = NULL;
    }
    if (share_holding_data->history) {
        list_ForEach(listEntry, share_holding_data->history) {
            history_item_free(listEntry->data);
        }
        list_freeList(share_holding_data->history);
        share_holding_data->history = NULL;
    }
    free(share_holding_data);
}

cJSON *share_holding_data_convertToJSON(share_holding_data_t *share_holding_data) {
    cJSON *item = cJSON_CreateObject();

    // share_holding_data->category
    if(share_holding_data->category) {
    if(cJSON_AddStringToObject(item, "category", share_holding_data->category) == NULL) {
    goto fail; //String
    }
    }


    // share_holding_data->history
    if(share_holding_data->history) {
    cJSON *history = cJSON_AddArrayToObject(item, "history");
    if(history == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *historyListEntry;
    if (share_holding_data->history) {
    list_ForEach(historyListEntry, share_holding_data->history) {
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

share_holding_data_t *share_holding_data_parseFromJSON(cJSON *share_holding_dataJSON){

    share_holding_data_t *share_holding_data_local_var = NULL;

    char *category_local_str = NULL;

    // define the local list for share_holding_data->history
    list_t *historyList = NULL;

    // share_holding_data->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(share_holding_dataJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (category) { 
    if(!cJSON_IsString(category) && !cJSON_IsNull(category))
    {
    goto end; //String
    }
    }

    // share_holding_data->history
    cJSON *history = cJSON_GetObjectItemCaseSensitive(share_holding_dataJSON, "history");
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

    share_holding_data_local_var = share_holding_data_create_internal (
        category_local_str,
        history ? historyList : NULL
        );

    if (!share_holding_data_local_var) {
        goto end;
    }

    return share_holding_data_local_var;
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
