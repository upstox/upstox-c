#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_order_response.h"


char* get_order_response_status_ToString(upstox_client_get_order_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_order_response_STATUS_e get_order_response_status_FromString(char* status){
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

static get_order_response_t *get_order_response_create_internal(
    upstox_client_get_order_response_STATUS_e status,
    list_t *data
    ) {
    get_order_response_t *get_order_response_local_var = malloc(sizeof(get_order_response_t));
    if (!get_order_response_local_var) {
        return NULL;
    }
    memset(get_order_response_local_var, 0, sizeof(get_order_response_t));
    get_order_response_local_var->_library_owned = 1;
    get_order_response_local_var->status = status;
    get_order_response_local_var->data = data;
    return get_order_response_local_var;
}

get_order_response_t *get_order_response_create(
    upstox_client_get_order_response_STATUS_e status,
    list_t *data
    ) {
    get_order_response_t *result = get_order_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void get_order_response_free(get_order_response_t *get_order_response) {
    if(NULL == get_order_response){
        return ;
    }
    if(get_order_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_order_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_order_response->data) {
        list_ForEach(listEntry, get_order_response->data) {
            order_data_free(listEntry->data);
        }
        list_freeList(get_order_response->data);
        get_order_response->data = NULL;
    }
    free(get_order_response);
}

cJSON *get_order_response_convertToJSON(get_order_response_t *get_order_response) {
    cJSON *item = cJSON_CreateObject();

    // get_order_response->status
    if(get_order_response->status != upstox_client_get_order_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_order_response_status_ToString(get_order_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_order_response->data
    if(get_order_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (get_order_response->data) {
    list_ForEach(dataListEntry, get_order_response->data) {
    cJSON *itemLocal = order_data_convertToJSON(dataListEntry->data);
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

get_order_response_t *get_order_response_parseFromJSON(cJSON *get_order_responseJSON){

    get_order_response_t *get_order_response_local_var = NULL;

    // define the local list for get_order_response->data
    list_t *dataList = NULL;

    // get_order_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_order_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_order_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_order_response_status_FromString(status->valuestring);
    }

    // get_order_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_order_responseJSON, "data");
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
        order_data_t *dataItem = order_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    get_order_response_local_var = get_order_response_create_internal (
        status ? statusVariable : upstox_client_get_order_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!get_order_response_local_var) {
        goto end;
    }

    return get_order_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            order_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
