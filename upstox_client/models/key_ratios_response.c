#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "key_ratios_response.h"


char* key_ratios_response_status_ToString(upstox_client_key_ratios_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_key_ratios_response_STATUS_e key_ratios_response_status_FromString(char* status){
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

static key_ratios_response_t *key_ratios_response_create_internal(
    upstox_client_key_ratios_response_STATUS_e status,
    list_t *data
    ) {
    key_ratios_response_t *key_ratios_response_local_var = malloc(sizeof(key_ratios_response_t));
    if (!key_ratios_response_local_var) {
        return NULL;
    }
    memset(key_ratios_response_local_var, 0, sizeof(key_ratios_response_t));
    key_ratios_response_local_var->_library_owned = 1;
    key_ratios_response_local_var->status = status;
    key_ratios_response_local_var->data = data;
    return key_ratios_response_local_var;
}

key_ratios_response_t *key_ratios_response_create(
    upstox_client_key_ratios_response_STATUS_e status,
    list_t *data
    ) {
    key_ratios_response_t *result = key_ratios_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void key_ratios_response_free(key_ratios_response_t *key_ratios_response) {
    if(NULL == key_ratios_response){
        return ;
    }
    if(key_ratios_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "key_ratios_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (key_ratios_response->data) {
        list_ForEach(listEntry, key_ratios_response->data) {
            key_ratio_data_free(listEntry->data);
        }
        list_freeList(key_ratios_response->data);
        key_ratios_response->data = NULL;
    }
    free(key_ratios_response);
}

cJSON *key_ratios_response_convertToJSON(key_ratios_response_t *key_ratios_response) {
    cJSON *item = cJSON_CreateObject();

    // key_ratios_response->status
    if(key_ratios_response->status != upstox_client_key_ratios_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", key_ratios_response_status_ToString(key_ratios_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // key_ratios_response->data
    if(key_ratios_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (key_ratios_response->data) {
    list_ForEach(dataListEntry, key_ratios_response->data) {
    cJSON *itemLocal = key_ratio_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
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

key_ratios_response_t *key_ratios_response_parseFromJSON(cJSON *key_ratios_responseJSON){

    key_ratios_response_t *key_ratios_response_local_var = NULL;

    // define the local list for key_ratios_response->data
    list_t *dataList = NULL;

    // key_ratios_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(key_ratios_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_key_ratios_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = key_ratios_response_status_FromString(status->valuestring);
    }

    // key_ratios_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(key_ratios_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local_nonprimitive = NULL;
    if(!cJSON_IsArray(data)){
        goto end; //nonprimitive container
    }

    dataList = list_createList();

    cJSON_ArrayForEach(data_local_nonprimitive,data )
    {
        if(!cJSON_IsObject(data_local_nonprimitive)){
            goto end;
        }
        key_ratio_data_t *dataItem = key_ratio_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    key_ratios_response_local_var = key_ratios_response_create_internal (
        status ? statusVariable : upstox_client_key_ratios_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!key_ratios_response_local_var) {
        goto end;
    }

    return key_ratios_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            key_ratio_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
