#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "share_holdings_response.h"


char* share_holdings_response_status_ToString(upstox_client_share_holdings_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_share_holdings_response_STATUS_e share_holdings_response_status_FromString(char* status){
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

static share_holdings_response_t *share_holdings_response_create_internal(
    upstox_client_share_holdings_response_STATUS_e status,
    list_t *data
    ) {
    share_holdings_response_t *share_holdings_response_local_var = malloc(sizeof(share_holdings_response_t));
    if (!share_holdings_response_local_var) {
        return NULL;
    }
    memset(share_holdings_response_local_var, 0, sizeof(share_holdings_response_t));
    share_holdings_response_local_var->_library_owned = 1;
    share_holdings_response_local_var->status = status;
    share_holdings_response_local_var->data = data;
    return share_holdings_response_local_var;
}

share_holdings_response_t *share_holdings_response_create(
    upstox_client_share_holdings_response_STATUS_e status,
    list_t *data
    ) {
    share_holdings_response_t *result = share_holdings_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void share_holdings_response_free(share_holdings_response_t *share_holdings_response) {
    if(NULL == share_holdings_response){
        return ;
    }
    if(share_holdings_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "share_holdings_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (share_holdings_response->data) {
        list_ForEach(listEntry, share_holdings_response->data) {
            share_holding_data_free(listEntry->data);
        }
        list_freeList(share_holdings_response->data);
        share_holdings_response->data = NULL;
    }
    free(share_holdings_response);
}

cJSON *share_holdings_response_convertToJSON(share_holdings_response_t *share_holdings_response) {
    cJSON *item = cJSON_CreateObject();

    // share_holdings_response->status
    if(share_holdings_response->status != upstox_client_share_holdings_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", share_holdings_response_status_ToString(share_holdings_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // share_holdings_response->data
    if(share_holdings_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (share_holdings_response->data) {
    list_ForEach(dataListEntry, share_holdings_response->data) {
    cJSON *itemLocal = share_holding_data_convertToJSON(dataListEntry->data);
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

share_holdings_response_t *share_holdings_response_parseFromJSON(cJSON *share_holdings_responseJSON){

    share_holdings_response_t *share_holdings_response_local_var = NULL;

    // define the local list for share_holdings_response->data
    list_t *dataList = NULL;

    // share_holdings_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(share_holdings_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_share_holdings_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = share_holdings_response_status_FromString(status->valuestring);
    }

    // share_holdings_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(share_holdings_responseJSON, "data");
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
        share_holding_data_t *dataItem = share_holding_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    share_holdings_response_local_var = share_holdings_response_create_internal (
        status ? statusVariable : upstox_client_share_holdings_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!share_holdings_response_local_var) {
        goto end;
    }

    return share_holdings_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            share_holding_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
