#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_v3_data.h"



static multi_order_v3_data_t *multi_order_v3_data_create_internal(
    list_t *order_ids
    ) {
    multi_order_v3_data_t *multi_order_v3_data_local_var = malloc(sizeof(multi_order_v3_data_t));
    if (!multi_order_v3_data_local_var) {
        return NULL;
    }
    memset(multi_order_v3_data_local_var, 0, sizeof(multi_order_v3_data_t));
    multi_order_v3_data_local_var->_library_owned = 1;
    multi_order_v3_data_local_var->order_ids = order_ids;
    return multi_order_v3_data_local_var;
}

multi_order_v3_data_t *multi_order_v3_data_create(
    list_t *order_ids
    ) {
    multi_order_v3_data_t *result = multi_order_v3_data_create_internal (
        order_ids
        );
    if (!result) {
    }
    return result;
}

void multi_order_v3_data_free(multi_order_v3_data_t *multi_order_v3_data) {
    if(NULL == multi_order_v3_data){
        return ;
    }
    if(multi_order_v3_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_v3_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_v3_data->order_ids) {
        list_ForEach(listEntry, multi_order_v3_data->order_ids) {
            free(listEntry->data);
        }
        list_freeList(multi_order_v3_data->order_ids);
        multi_order_v3_data->order_ids = NULL;
    }
    free(multi_order_v3_data);
}

cJSON *multi_order_v3_data_convertToJSON(multi_order_v3_data_t *multi_order_v3_data) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_v3_data->order_ids
    if(multi_order_v3_data->order_ids) {
    cJSON *order_ids = cJSON_AddArrayToObject(item, "order_ids");
    if(order_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *order_idsListEntry;
    list_ForEach(order_idsListEntry, multi_order_v3_data->order_ids) {
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

multi_order_v3_data_t *multi_order_v3_data_parseFromJSON(cJSON *multi_order_v3_dataJSON){

    multi_order_v3_data_t *multi_order_v3_data_local_var = NULL;

    // define the local list for multi_order_v3_data->order_ids
    list_t *order_idsList = NULL;

    // multi_order_v3_data->order_ids
    cJSON *order_ids = cJSON_GetObjectItemCaseSensitive(multi_order_v3_dataJSON, "order_ids");
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



    multi_order_v3_data_local_var = multi_order_v3_data_create_internal (
        order_ids ? order_idsList : NULL
        );

    if (!multi_order_v3_data_local_var) {
        goto end;
    }

    return multi_order_v3_data_local_var;
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
