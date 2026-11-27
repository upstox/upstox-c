#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "competitors_response.h"


char* competitors_response_status_ToString(upstox_client_competitors_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_competitors_response_STATUS_e competitors_response_status_FromString(char* status){
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

static competitors_response_t *competitors_response_create_internal(
    upstox_client_competitors_response_STATUS_e status,
    list_t *data
    ) {
    competitors_response_t *competitors_response_local_var = malloc(sizeof(competitors_response_t));
    if (!competitors_response_local_var) {
        return NULL;
    }
    memset(competitors_response_local_var, 0, sizeof(competitors_response_t));
    competitors_response_local_var->_library_owned = 1;
    competitors_response_local_var->status = status;
    competitors_response_local_var->data = data;
    return competitors_response_local_var;
}

competitors_response_t *competitors_response_create(
    upstox_client_competitors_response_STATUS_e status,
    list_t *data
    ) {
    competitors_response_t *result = competitors_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void competitors_response_free(competitors_response_t *competitors_response) {
    if(NULL == competitors_response){
        return ;
    }
    if(competitors_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "competitors_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (competitors_response->data) {
        list_ForEach(listEntry, competitors_response->data) {
            competitor_data_free(listEntry->data);
        }
        list_freeList(competitors_response->data);
        competitors_response->data = NULL;
    }
    free(competitors_response);
}

cJSON *competitors_response_convertToJSON(competitors_response_t *competitors_response) {
    cJSON *item = cJSON_CreateObject();

    // competitors_response->status
    if(competitors_response->status != upstox_client_competitors_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", competitors_response_status_ToString(competitors_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // competitors_response->data
    if(competitors_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (competitors_response->data) {
    list_ForEach(dataListEntry, competitors_response->data) {
    cJSON *itemLocal = competitor_data_convertToJSON(dataListEntry->data);
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

competitors_response_t *competitors_response_parseFromJSON(cJSON *competitors_responseJSON){

    competitors_response_t *competitors_response_local_var = NULL;

    // define the local list for competitors_response->data
    list_t *dataList = NULL;

    // competitors_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(competitors_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_competitors_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = competitors_response_status_FromString(status->valuestring);
    }

    // competitors_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(competitors_responseJSON, "data");
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
        competitor_data_t *dataItem = competitor_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    competitors_response_local_var = competitors_response_create_internal (
        status ? statusVariable : upstox_client_competitors_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!competitors_response_local_var) {
        goto end;
    }

    return competitors_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            competitor_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
