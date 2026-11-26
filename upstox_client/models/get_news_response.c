#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_news_response.h"
#include "news_item_data.h"


char* get_news_response_status_ToString(upstox_client_get_news_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_news_response_STATUS_e get_news_response_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "success", "error", "partial_success" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static get_news_response_t *get_news_response_create_internal(
    upstox_client_get_news_response_STATUS_e status,
    list_t* data,
    news_response_meta_data_t *metadata
    ) {
    get_news_response_t *get_news_response_local_var = malloc(sizeof(get_news_response_t));
    if (!get_news_response_local_var) {
        return NULL;
    }
    memset(get_news_response_local_var, 0, sizeof(get_news_response_t));
    get_news_response_local_var->_library_owned = 1;
    get_news_response_local_var->status = status;
    get_news_response_local_var->data = data;
    get_news_response_local_var->metadata = metadata;
    return get_news_response_local_var;
}

get_news_response_t *get_news_response_create(
    upstox_client_get_news_response_STATUS_e status,
    list_t* data,
    news_response_meta_data_t *metadata
    ) {
    get_news_response_t *result = get_news_response_create_internal (
        status,
        data,
        metadata
        );
    if (!result) {
    }
    return result;
}

// Frees one map value: a list of news_item_data_t.
static void get_news_response_map_value_free(void *value) {
    listEntry_t *entry = NULL;
    list_ForEach(entry, (list_t *) value) {
        news_item_data_free(entry->data);
    }
    list_freeList(value);
}

void get_news_response_free(get_news_response_t *get_news_response) {
    if(NULL == get_news_response){
        return ;
    }
    if(get_news_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_news_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_news_response->data) {
        list_ForEach(listEntry, get_news_response->data) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            get_news_response_map_value_free(localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(get_news_response->data);
        get_news_response->data = NULL;
    }
    if (get_news_response->metadata) {
        news_response_meta_data_free(get_news_response->metadata);
        get_news_response->metadata = NULL;
    }
    free(get_news_response);
}

cJSON *get_news_response_convertToJSON(get_news_response_t *get_news_response) {
    cJSON *item = cJSON_CreateObject();

    // get_news_response->status
    if(get_news_response->status != upstox_client_get_news_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_news_response_status_ToString(get_news_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_news_response->data
    if(get_news_response->data) {
    cJSON *data = cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (get_news_response->data) {
    list_ForEach(dataListEntry, get_news_response->data) {
        keyValuePair_t *localKeyValue = dataListEntry->data;
        cJSON *mapJSON = cJSON_CreateArray();
        listEntry_t *mapEntry = NULL;
        list_ForEach(mapEntry, (list_t *) localKeyValue->value) {
            cJSON *itemJSON = news_item_data_convertToJSON(mapEntry->data);
            if (itemJSON == NULL) { cJSON_Delete(mapJSON); goto fail; }
            cJSON_AddItemToArray(mapJSON, itemJSON);
        }
        cJSON_AddItemToObject(localMapObject, localKeyValue->key, mapJSON);
    }
    }
    }


    // get_news_response->metadata
    if(get_news_response->metadata) {
    cJSON *metadata_local_JSON = news_response_meta_data_convertToJSON(get_news_response->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_news_response_t *get_news_response_parseFromJSON(cJSON *get_news_responseJSON){

    get_news_response_t *get_news_response_local_var = NULL;

    // define the local map for get_news_response->data
    list_t *dataList = NULL;

    // define the local variable for get_news_response->metadata
    news_response_meta_data_t *metadata_local_nonprim = NULL;

    // get_news_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_news_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_news_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_news_response_status_FromString(status->valuestring);
    }

    // get_news_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_news_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local_map = NULL;
    if(!cJSON_IsObject(data) && !cJSON_IsNull(data))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(data))
    {
        dataList = list_createList();
        cJSON_ArrayForEach(data_local_map, data)
        {
            list_t *mapValue = list_createList();
            cJSON *mapItem = NULL;
            cJSON_ArrayForEach(mapItem, data_local_map) {
                news_item_data_t *parsed = news_item_data_parseFromJSON(mapItem);
                if (parsed == NULL) { get_news_response_map_value_free(mapValue); goto end; }
                list_addElement(mapValue, parsed);
            }
            list_addElement(dataList, keyValuePair_create(strdup(data_local_map->string), mapValue));
        }
    }
    }

    // get_news_response->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(get_news_responseJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = news_response_meta_data_parseFromJSON(metadata); //nonprimitive
    }



    get_news_response_local_var = get_news_response_create_internal (
        status ? statusVariable : upstox_client_get_news_response_STATUS_NULL,
        data ? dataList : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    if (!get_news_response_local_var) {
        goto end;
    }

    return get_news_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            get_news_response_map_value_free(localKeyValue->value);
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (metadata_local_nonprim) {
        news_response_meta_data_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
