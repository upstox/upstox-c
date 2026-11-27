#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_history_response.h"


char* trade_history_response_status_ToString(upstox_client_trade_history_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_trade_history_response_STATUS_e trade_history_response_status_FromString(char* status){
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

static trade_history_response_t *trade_history_response_create_internal(
    upstox_client_trade_history_response_STATUS_e status,
    list_t *data,
    trade_history_response_meta_data_t *meta_data
    ) {
    trade_history_response_t *trade_history_response_local_var = malloc(sizeof(trade_history_response_t));
    if (!trade_history_response_local_var) {
        return NULL;
    }
    memset(trade_history_response_local_var, 0, sizeof(trade_history_response_t));
    trade_history_response_local_var->_library_owned = 1;
    trade_history_response_local_var->status = status;
    trade_history_response_local_var->data = data;
    trade_history_response_local_var->meta_data = meta_data;
    return trade_history_response_local_var;
}

trade_history_response_t *trade_history_response_create(
    upstox_client_trade_history_response_STATUS_e status,
    list_t *data,
    trade_history_response_meta_data_t *meta_data
    ) {
    trade_history_response_t *result = trade_history_response_create_internal (
        status,
        data,
        meta_data
        );
    if (!result) {
    }
    return result;
}

void trade_history_response_free(trade_history_response_t *trade_history_response) {
    if(NULL == trade_history_response){
        return ;
    }
    if(trade_history_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_history_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_history_response->data) {
        list_ForEach(listEntry, trade_history_response->data) {
            trade_history_response_trade_data_free(listEntry->data);
        }
        list_freeList(trade_history_response->data);
        trade_history_response->data = NULL;
    }
    if (trade_history_response->meta_data) {
        trade_history_response_meta_data_free(trade_history_response->meta_data);
        trade_history_response->meta_data = NULL;
    }
    free(trade_history_response);
}

cJSON *trade_history_response_convertToJSON(trade_history_response_t *trade_history_response) {
    cJSON *item = cJSON_CreateObject();

    // trade_history_response->status
    if(trade_history_response->status != upstox_client_trade_history_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", trade_history_response_status_ToString(trade_history_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trade_history_response->data
    if(trade_history_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (trade_history_response->data) {
    list_ForEach(dataListEntry, trade_history_response->data) {
    cJSON *itemLocal = trade_history_response_trade_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // trade_history_response->meta_data
    if(trade_history_response->meta_data) {
    cJSON *meta_data_local_JSON = trade_history_response_meta_data_convertToJSON(trade_history_response->meta_data);
    if(meta_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metaData", meta_data_local_JSON);
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

trade_history_response_t *trade_history_response_parseFromJSON(cJSON *trade_history_responseJSON){

    trade_history_response_t *trade_history_response_local_var = NULL;

    // define the local list for trade_history_response->data
    list_t *dataList = NULL;

    // define the local variable for trade_history_response->meta_data
    trade_history_response_meta_data_t *meta_data_local_nonprim = NULL;

    // trade_history_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(trade_history_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_trade_history_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = trade_history_response_status_FromString(status->valuestring);
    }

    // trade_history_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(trade_history_responseJSON, "data");
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
        trade_history_response_trade_data_t *dataItem = trade_history_response_trade_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // trade_history_response->meta_data
    cJSON *meta_data = cJSON_GetObjectItemCaseSensitive(trade_history_responseJSON, "metaData");
    if (cJSON_IsNull(meta_data)) {
        meta_data = NULL;
    }
    if (meta_data) { 
    meta_data_local_nonprim = trade_history_response_meta_data_parseFromJSON(meta_data); //nonprimitive
    }



    trade_history_response_local_var = trade_history_response_create_internal (
        status ? statusVariable : upstox_client_trade_history_response_STATUS_NULL,
        data ? dataList : NULL,
        meta_data ? meta_data_local_nonprim : NULL
        );

    if (!trade_history_response_local_var) {
        goto end;
    }

    return trade_history_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            trade_history_response_trade_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (meta_data_local_nonprim) {
        trade_history_response_meta_data_free(meta_data_local_nonprim);
        meta_data_local_nonprim = NULL;
    }
    return NULL;

}
