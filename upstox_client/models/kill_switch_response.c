#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kill_switch_response.h"


char* kill_switch_response_status_ToString(upstox_client_kill_switch_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_kill_switch_response_STATUS_e kill_switch_response_status_FromString(char* status){
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

static kill_switch_response_t *kill_switch_response_create_internal(
    upstox_client_kill_switch_response_STATUS_e status,
    list_t *data
    ) {
    kill_switch_response_t *kill_switch_response_local_var = malloc(sizeof(kill_switch_response_t));
    if (!kill_switch_response_local_var) {
        return NULL;
    }
    memset(kill_switch_response_local_var, 0, sizeof(kill_switch_response_t));
    kill_switch_response_local_var->_library_owned = 1;
    kill_switch_response_local_var->status = status;
    kill_switch_response_local_var->data = data;
    return kill_switch_response_local_var;
}

kill_switch_response_t *kill_switch_response_create(
    upstox_client_kill_switch_response_STATUS_e status,
    list_t *data
    ) {
    kill_switch_response_t *result = kill_switch_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void kill_switch_response_free(kill_switch_response_t *kill_switch_response) {
    if(NULL == kill_switch_response){
        return ;
    }
    if(kill_switch_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kill_switch_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kill_switch_response->data) {
        list_ForEach(listEntry, kill_switch_response->data) {
            kill_switch_segment_data_free(listEntry->data);
        }
        list_freeList(kill_switch_response->data);
        kill_switch_response->data = NULL;
    }
    free(kill_switch_response);
}

cJSON *kill_switch_response_convertToJSON(kill_switch_response_t *kill_switch_response) {
    cJSON *item = cJSON_CreateObject();

    // kill_switch_response->status
    if(kill_switch_response->status != upstox_client_kill_switch_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", kill_switch_response_status_ToString(kill_switch_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // kill_switch_response->data
    if(kill_switch_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (kill_switch_response->data) {
    list_ForEach(dataListEntry, kill_switch_response->data) {
    cJSON *itemLocal = kill_switch_segment_data_convertToJSON(dataListEntry->data);
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

kill_switch_response_t *kill_switch_response_parseFromJSON(cJSON *kill_switch_responseJSON){

    kill_switch_response_t *kill_switch_response_local_var = NULL;

    // define the local list for kill_switch_response->data
    list_t *dataList = NULL;

    // kill_switch_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(kill_switch_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_kill_switch_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = kill_switch_response_status_FromString(status->valuestring);
    }

    // kill_switch_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(kill_switch_responseJSON, "data");
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
        kill_switch_segment_data_t *dataItem = kill_switch_segment_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    kill_switch_response_local_var = kill_switch_response_create_internal (
        status ? statusVariable : upstox_client_kill_switch_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!kill_switch_response_local_var) {
        goto end;
    }

    return kill_switch_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            kill_switch_segment_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
