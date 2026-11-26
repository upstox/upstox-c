#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_market_quote_ohlc_response_v3.h"
#include "market_quote_ohlcv3.h"


char* get_market_quote_ohlc_response_v3_status_ToString(upstox_client_get_market_quote_ohlc_response_v3_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_market_quote_ohlc_response_v3_STATUS_e get_market_quote_ohlc_response_v3_status_FromString(char* status){
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

static get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3_create_internal(
    upstox_client_get_market_quote_ohlc_response_v3_STATUS_e status,
    list_t* data
    ) {
    get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3_local_var = malloc(sizeof(get_market_quote_ohlc_response_v3_t));
    if (!get_market_quote_ohlc_response_v3_local_var) {
        return NULL;
    }
    memset(get_market_quote_ohlc_response_v3_local_var, 0, sizeof(get_market_quote_ohlc_response_v3_t));
    get_market_quote_ohlc_response_v3_local_var->_library_owned = 1;
    get_market_quote_ohlc_response_v3_local_var->status = status;
    get_market_quote_ohlc_response_v3_local_var->data = data;
    return get_market_quote_ohlc_response_v3_local_var;
}

get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3_create(
    upstox_client_get_market_quote_ohlc_response_v3_STATUS_e status,
    list_t* data
    ) {
    get_market_quote_ohlc_response_v3_t *result = get_market_quote_ohlc_response_v3_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

// Frees one map value: a market_quote_ohlcv3_t.
static void get_market_quote_ohlc_response_v3_map_value_free(void *value) {
    market_quote_ohlcv3_free(value);
}

void get_market_quote_ohlc_response_v3_free(get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3) {
    if(NULL == get_market_quote_ohlc_response_v3){
        return ;
    }
    if(get_market_quote_ohlc_response_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_market_quote_ohlc_response_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_market_quote_ohlc_response_v3->data) {
        list_ForEach(listEntry, get_market_quote_ohlc_response_v3->data) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            get_market_quote_ohlc_response_v3_map_value_free(localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(get_market_quote_ohlc_response_v3->data);
        get_market_quote_ohlc_response_v3->data = NULL;
    }
    free(get_market_quote_ohlc_response_v3);
}

cJSON *get_market_quote_ohlc_response_v3_convertToJSON(get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3) {
    cJSON *item = cJSON_CreateObject();

    // get_market_quote_ohlc_response_v3->status
    if(get_market_quote_ohlc_response_v3->status != upstox_client_get_market_quote_ohlc_response_v3_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_market_quote_ohlc_response_v3_status_ToString(get_market_quote_ohlc_response_v3->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_market_quote_ohlc_response_v3->data
    if(get_market_quote_ohlc_response_v3->data) {
    cJSON *data = cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (get_market_quote_ohlc_response_v3->data) {
    list_ForEach(dataListEntry, get_market_quote_ohlc_response_v3->data) {
        keyValuePair_t *localKeyValue = dataListEntry->data;
        cJSON *mapJSON = market_quote_ohlcv3_convertToJSON(localKeyValue->value);
        if (mapJSON == NULL) { goto fail; }
        cJSON_AddItemToObject(localMapObject, localKeyValue->key, mapJSON);
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

get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3_parseFromJSON(cJSON *get_market_quote_ohlc_response_v3JSON){

    get_market_quote_ohlc_response_v3_t *get_market_quote_ohlc_response_v3_local_var = NULL;

    // define the local map for get_market_quote_ohlc_response_v3->data
    list_t *dataList = NULL;

    // get_market_quote_ohlc_response_v3->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_market_quote_ohlc_response_v3JSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_market_quote_ohlc_response_v3_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_market_quote_ohlc_response_v3_status_FromString(status->valuestring);
    }

    // get_market_quote_ohlc_response_v3->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_market_quote_ohlc_response_v3JSON, "data");
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
            market_quote_ohlcv3_t *mapValue = market_quote_ohlcv3_parseFromJSON(data_local_map);
            if (mapValue == NULL) { goto end; }
            list_addElement(dataList, keyValuePair_create(strdup(data_local_map->string), mapValue));
        }
    }
    }



    get_market_quote_ohlc_response_v3_local_var = get_market_quote_ohlc_response_v3_create_internal (
        status ? statusVariable : upstox_client_get_market_quote_ohlc_response_v3_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!get_market_quote_ohlc_response_v3_local_var) {
        goto end;
    }

    return get_market_quote_ohlc_response_v3_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            get_market_quote_ohlc_response_v3_map_value_free(localKeyValue->value);
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
