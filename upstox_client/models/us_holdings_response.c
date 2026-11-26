#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_holdings_response.h"


char* us_holdings_response_status_ToString(upstox_client_us_holdings_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_us_holdings_response_STATUS_e us_holdings_response_status_FromString(char* status){
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

static us_holdings_response_t *us_holdings_response_create_internal(
    upstox_client_us_holdings_response_STATUS_e status,
    list_t *data
    ) {
    us_holdings_response_t *us_holdings_response_local_var = malloc(sizeof(us_holdings_response_t));
    if (!us_holdings_response_local_var) {
        return NULL;
    }
    memset(us_holdings_response_local_var, 0, sizeof(us_holdings_response_t));
    us_holdings_response_local_var->_library_owned = 1;
    us_holdings_response_local_var->status = status;
    us_holdings_response_local_var->data = data;
    return us_holdings_response_local_var;
}

us_holdings_response_t *us_holdings_response_create(
    upstox_client_us_holdings_response_STATUS_e status,
    list_t *data
    ) {
    us_holdings_response_t *result = us_holdings_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void us_holdings_response_free(us_holdings_response_t *us_holdings_response) {
    if(NULL == us_holdings_response){
        return ;
    }
    if(us_holdings_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_holdings_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_holdings_response->data) {
        list_ForEach(listEntry, us_holdings_response->data) {
            us_holding_data_free(listEntry->data);
        }
        list_freeList(us_holdings_response->data);
        us_holdings_response->data = NULL;
    }
    free(us_holdings_response);
}

cJSON *us_holdings_response_convertToJSON(us_holdings_response_t *us_holdings_response) {
    cJSON *item = cJSON_CreateObject();

    // us_holdings_response->status
    if(us_holdings_response->status != upstox_client_us_holdings_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", us_holdings_response_status_ToString(us_holdings_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // us_holdings_response->data
    if(us_holdings_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (us_holdings_response->data) {
    list_ForEach(dataListEntry, us_holdings_response->data) {
    cJSON *itemLocal = us_holding_data_convertToJSON(dataListEntry->data);
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

us_holdings_response_t *us_holdings_response_parseFromJSON(cJSON *us_holdings_responseJSON){

    us_holdings_response_t *us_holdings_response_local_var = NULL;

    // define the local list for us_holdings_response->data
    list_t *dataList = NULL;

    // us_holdings_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(us_holdings_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_us_holdings_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = us_holdings_response_status_FromString(status->valuestring);
    }

    // us_holdings_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(us_holdings_responseJSON, "data");
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
        us_holding_data_t *dataItem = us_holding_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    us_holdings_response_local_var = us_holdings_response_create_internal (
        status ? statusVariable : upstox_client_us_holdings_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!us_holdings_response_local_var) {
        goto end;
    }

    return us_holdings_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            us_holding_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
