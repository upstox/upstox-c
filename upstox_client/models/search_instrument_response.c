#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "search_instrument_response.h"


char* search_instrument_response_status_ToString(upstox_client_search_instrument_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_search_instrument_response_STATUS_e search_instrument_response_status_FromString(char* status){
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

static search_instrument_response_t *search_instrument_response_create_internal(
    upstox_client_search_instrument_response_STATUS_e status,
    list_t *data,
    search_meta_data_t *meta_data
    ) {
    search_instrument_response_t *search_instrument_response_local_var = malloc(sizeof(search_instrument_response_t));
    if (!search_instrument_response_local_var) {
        return NULL;
    }
    memset(search_instrument_response_local_var, 0, sizeof(search_instrument_response_t));
    search_instrument_response_local_var->_library_owned = 1;
    search_instrument_response_local_var->status = status;
    search_instrument_response_local_var->data = data;
    search_instrument_response_local_var->meta_data = meta_data;
    return search_instrument_response_local_var;
}

search_instrument_response_t *search_instrument_response_create(
    upstox_client_search_instrument_response_STATUS_e status,
    list_t *data,
    search_meta_data_t *meta_data
    ) {
    search_instrument_response_t *result = search_instrument_response_create_internal (
        status,
        data,
        meta_data
        );
    if (!result) {
    }
    return result;
}

void search_instrument_response_free(search_instrument_response_t *search_instrument_response) {
    if(NULL == search_instrument_response){
        return ;
    }
    if(search_instrument_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "search_instrument_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (search_instrument_response->data) {
        list_ForEach(listEntry, search_instrument_response->data) {
            instrument_data_free(listEntry->data);
        }
        list_freeList(search_instrument_response->data);
        search_instrument_response->data = NULL;
    }
    if (search_instrument_response->meta_data) {
        search_meta_data_free(search_instrument_response->meta_data);
        search_instrument_response->meta_data = NULL;
    }
    free(search_instrument_response);
}

cJSON *search_instrument_response_convertToJSON(search_instrument_response_t *search_instrument_response) {
    cJSON *item = cJSON_CreateObject();

    // search_instrument_response->status
    if(search_instrument_response->status != upstox_client_search_instrument_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", search_instrument_response_status_ToString(search_instrument_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // search_instrument_response->data
    if(search_instrument_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (search_instrument_response->data) {
    list_ForEach(dataListEntry, search_instrument_response->data) {
    cJSON *itemLocal = instrument_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // search_instrument_response->meta_data
    if(search_instrument_response->meta_data) {
    cJSON *meta_data_local_JSON = search_meta_data_convertToJSON(search_instrument_response->meta_data);
    if(meta_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "meta_data", meta_data_local_JSON);
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

search_instrument_response_t *search_instrument_response_parseFromJSON(cJSON *search_instrument_responseJSON){

    search_instrument_response_t *search_instrument_response_local_var = NULL;

    // define the local list for search_instrument_response->data
    list_t *dataList = NULL;

    // define the local variable for search_instrument_response->meta_data
    search_meta_data_t *meta_data_local_nonprim = NULL;

    // search_instrument_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(search_instrument_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_search_instrument_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = search_instrument_response_status_FromString(status->valuestring);
    }

    // search_instrument_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(search_instrument_responseJSON, "data");
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
        instrument_data_t *dataItem = instrument_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // search_instrument_response->meta_data
    cJSON *meta_data = cJSON_GetObjectItemCaseSensitive(search_instrument_responseJSON, "meta_data");
    if (cJSON_IsNull(meta_data)) {
        meta_data = NULL;
    }
    if (meta_data) { 
    meta_data_local_nonprim = search_meta_data_parseFromJSON(meta_data); //nonprimitive
    }



    search_instrument_response_local_var = search_instrument_response_create_internal (
        status ? statusVariable : upstox_client_search_instrument_response_STATUS_NULL,
        data ? dataList : NULL,
        meta_data ? meta_data_local_nonprim : NULL
        );

    if (!search_instrument_response_local_var) {
        goto end;
    }

    return search_instrument_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            instrument_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (meta_data_local_nonprim) {
        search_meta_data_free(meta_data_local_nonprim);
        meta_data_local_nonprim = NULL;
    }
    return NULL;

}
