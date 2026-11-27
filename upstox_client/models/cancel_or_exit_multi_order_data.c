#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_or_exit_multi_order_data.h"



static cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_create_internal(
    list_t *order_ids
    ) {
    cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_local_var = malloc(sizeof(cancel_or_exit_multi_order_data_t));
    if (!cancel_or_exit_multi_order_data_local_var) {
        return NULL;
    }
    memset(cancel_or_exit_multi_order_data_local_var, 0, sizeof(cancel_or_exit_multi_order_data_t));
    cancel_or_exit_multi_order_data_local_var->_library_owned = 1;
    cancel_or_exit_multi_order_data_local_var->order_ids = order_ids;
    return cancel_or_exit_multi_order_data_local_var;
}

cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_create(
    list_t *order_ids
    ) {
    cancel_or_exit_multi_order_data_t *result = cancel_or_exit_multi_order_data_create_internal (
        order_ids
        );
    if (!result) {
    }
    return result;
}

void cancel_or_exit_multi_order_data_free(cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data) {
    if(NULL == cancel_or_exit_multi_order_data){
        return ;
    }
    if(cancel_or_exit_multi_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_or_exit_multi_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_or_exit_multi_order_data->order_ids) {
        list_ForEach(listEntry, cancel_or_exit_multi_order_data->order_ids) {
            free(listEntry->data);
        }
        list_freeList(cancel_or_exit_multi_order_data->order_ids);
        cancel_or_exit_multi_order_data->order_ids = NULL;
    }
    free(cancel_or_exit_multi_order_data);
}

cJSON *cancel_or_exit_multi_order_data_convertToJSON(cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data) {
    cJSON *item = cJSON_CreateObject();

    // cancel_or_exit_multi_order_data->order_ids
    if(cancel_or_exit_multi_order_data->order_ids) {
    cJSON *order_ids = cJSON_AddArrayToObject(item, "order_ids");
    if(order_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *order_idsListEntry;
    list_ForEach(order_idsListEntry, cancel_or_exit_multi_order_data->order_ids) {
    if(cJSON_AddStringToObject(order_ids, "", order_idsListEntry->data) == NULL)
    {
        goto fail;
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

cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_parseFromJSON(cJSON *cancel_or_exit_multi_order_dataJSON){

    cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_local_var = NULL;

    // define the local list for cancel_or_exit_multi_order_data->order_ids
    list_t *order_idsList = NULL;

    // cancel_or_exit_multi_order_data->order_ids
    cJSON *order_ids = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_multi_order_dataJSON, "order_ids");
    if (cJSON_IsNull(order_ids)) {
        order_ids = NULL;
    }
    if (order_ids) { 
    cJSON *order_ids_local = NULL;
    if(!cJSON_IsArray(order_ids)) {
        goto end;//primitive container
    }
    order_idsList = list_createList();

    cJSON_ArrayForEach(order_ids_local, order_ids)
    {
        if(!cJSON_IsString(order_ids_local))
        {
            goto end;
        }
        list_addElement(order_idsList , strdup(order_ids_local->valuestring));
    }
    }



    cancel_or_exit_multi_order_data_local_var = cancel_or_exit_multi_order_data_create_internal (
        order_ids ? order_idsList : NULL
        );

    if (!cancel_or_exit_multi_order_data_local_var) {
        goto end;
    }

    return cancel_or_exit_multi_order_data_local_var;
end:
    if (order_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, order_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(order_idsList);
        order_idsList = NULL;
    }
    return NULL;

}
