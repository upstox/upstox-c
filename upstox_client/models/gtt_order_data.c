#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_order_data.h"



static gtt_order_data_t *gtt_order_data_create_internal(
    list_t *gtt_order_ids
    ) {
    gtt_order_data_t *gtt_order_data_local_var = malloc(sizeof(gtt_order_data_t));
    if (!gtt_order_data_local_var) {
        return NULL;
    }
    memset(gtt_order_data_local_var, 0, sizeof(gtt_order_data_t));
    gtt_order_data_local_var->_library_owned = 1;
    gtt_order_data_local_var->gtt_order_ids = gtt_order_ids;
    return gtt_order_data_local_var;
}

gtt_order_data_t *gtt_order_data_create(
    list_t *gtt_order_ids
    ) {
    gtt_order_data_t *result = gtt_order_data_create_internal (
        gtt_order_ids
        );
    if (!result) {
    }
    return result;
}

void gtt_order_data_free(gtt_order_data_t *gtt_order_data) {
    if(NULL == gtt_order_data){
        return ;
    }
    if(gtt_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_order_data->gtt_order_ids) {
        list_ForEach(listEntry, gtt_order_data->gtt_order_ids) {
            free(listEntry->data);
        }
        list_freeList(gtt_order_data->gtt_order_ids);
        gtt_order_data->gtt_order_ids = NULL;
    }
    free(gtt_order_data);
}

cJSON *gtt_order_data_convertToJSON(gtt_order_data_t *gtt_order_data) {
    cJSON *item = cJSON_CreateObject();

    // gtt_order_data->gtt_order_ids
    if(gtt_order_data->gtt_order_ids) {
    cJSON *gtt_order_ids = cJSON_AddArrayToObject(item, "gtt_order_ids");
    if(gtt_order_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *gtt_order_idsListEntry;
    list_ForEach(gtt_order_idsListEntry, gtt_order_data->gtt_order_ids) {
    if(cJSON_AddStringToObject(gtt_order_ids, "", gtt_order_idsListEntry->data) == NULL)
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

gtt_order_data_t *gtt_order_data_parseFromJSON(cJSON *gtt_order_dataJSON){

    gtt_order_data_t *gtt_order_data_local_var = NULL;

    // define the local list for gtt_order_data->gtt_order_ids
    list_t *gtt_order_idsList = NULL;

    // gtt_order_data->gtt_order_ids
    cJSON *gtt_order_ids = cJSON_GetObjectItemCaseSensitive(gtt_order_dataJSON, "gtt_order_ids");
    if (cJSON_IsNull(gtt_order_ids)) {
        gtt_order_ids = NULL;
    }
    if (gtt_order_ids) { 
    cJSON *gtt_order_ids_local = NULL;
    if(!cJSON_IsArray(gtt_order_ids)) {
        goto end;//primitive container
    }
    gtt_order_idsList = list_createList();

    cJSON_ArrayForEach(gtt_order_ids_local, gtt_order_ids)
    {
        if(!cJSON_IsString(gtt_order_ids_local))
        {
            goto end;
        }
        list_addElement(gtt_order_idsList , strdup(gtt_order_ids_local->valuestring));
    }
    }



    gtt_order_data_local_var = gtt_order_data_create_internal (
        gtt_order_ids ? gtt_order_idsList : NULL
        );

    if (!gtt_order_data_local_var) {
        goto end;
    }

    return gtt_order_data_local_var;
end:
    if (gtt_order_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, gtt_order_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(gtt_order_idsList);
        gtt_order_idsList = NULL;
    }
    return NULL;

}
