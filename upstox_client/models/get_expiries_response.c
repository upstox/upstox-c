#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_expiries_response.h"


char* get_expiries_response_status_ToString(upstox_client_get_expiries_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_expiries_response_STATUS_e get_expiries_response_status_FromString(char* status){
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

static get_expiries_response_t *get_expiries_response_create_internal(
    upstox_client_get_expiries_response_STATUS_e status,
    list_t *data
    ) {
    get_expiries_response_t *get_expiries_response_local_var = malloc(sizeof(get_expiries_response_t));
    if (!get_expiries_response_local_var) {
        return NULL;
    }
    memset(get_expiries_response_local_var, 0, sizeof(get_expiries_response_t));
    get_expiries_response_local_var->_library_owned = 1;
    get_expiries_response_local_var->status = status;
    get_expiries_response_local_var->data = data;
    return get_expiries_response_local_var;
}

get_expiries_response_t *get_expiries_response_create(
    upstox_client_get_expiries_response_STATUS_e status,
    list_t *data
    ) {
    get_expiries_response_t *result = get_expiries_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void get_expiries_response_free(get_expiries_response_t *get_expiries_response) {
    if(NULL == get_expiries_response){
        return ;
    }
    if(get_expiries_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_expiries_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_expiries_response->data) {
        list_ForEach(listEntry, get_expiries_response->data) {
            free(listEntry->data);
        }
        list_freeList(get_expiries_response->data);
        get_expiries_response->data = NULL;
    }
    free(get_expiries_response);
}

cJSON *get_expiries_response_convertToJSON(get_expiries_response_t *get_expiries_response) {
    cJSON *item = cJSON_CreateObject();

    // get_expiries_response->status
    if(get_expiries_response->status != upstox_client_get_expiries_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_expiries_response_status_ToString(get_expiries_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_expiries_response->data
    if(get_expiries_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, get_expiries_response->data) {
    if(cJSON_AddStringToObject(data, "", dataListEntry->data) == NULL)
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

get_expiries_response_t *get_expiries_response_parseFromJSON(cJSON *get_expiries_responseJSON){

    get_expiries_response_t *get_expiries_response_local_var = NULL;

    // define the local list for get_expiries_response->data
    list_t *dataList = NULL;

    // get_expiries_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_expiries_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_expiries_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_expiries_response_status_FromString(status->valuestring);
    }

    // get_expiries_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_expiries_responseJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local = NULL;
    if(!cJSON_IsArray(data)) {
        goto end;//primitive container
    }
    dataList = list_createList();

    cJSON_ArrayForEach(data_local, data)
    {
        if(!cJSON_IsString(data_local))
        {
            goto end;
        }
        list_addElement(dataList , strdup(data_local->valuestring));
    }
    }



    get_expiries_response_local_var = get_expiries_response_create_internal (
        status ? statusVariable : upstox_client_get_expiries_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!get_expiries_response_local_var) {
        goto end;
    }

    return get_expiries_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
