#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_history_response.h"


char* payment_history_response_status_ToString(upstox_client_payment_history_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_payment_history_response_STATUS_e payment_history_response_status_FromString(char* status){
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

static payment_history_response_t *payment_history_response_create_internal(
    upstox_client_payment_history_response_STATUS_e status,
    list_t *data
    ) {
    payment_history_response_t *payment_history_response_local_var = malloc(sizeof(payment_history_response_t));
    if (!payment_history_response_local_var) {
        return NULL;
    }
    memset(payment_history_response_local_var, 0, sizeof(payment_history_response_t));
    payment_history_response_local_var->_library_owned = 1;
    payment_history_response_local_var->status = status;
    payment_history_response_local_var->data = data;
    return payment_history_response_local_var;
}

payment_history_response_t *payment_history_response_create(
    upstox_client_payment_history_response_STATUS_e status,
    list_t *data
    ) {
    payment_history_response_t *result = payment_history_response_create_internal (
        status,
        data
        );
    if (!result) {
    }
    return result;
}

void payment_history_response_free(payment_history_response_t *payment_history_response) {
    if(NULL == payment_history_response){
        return ;
    }
    if(payment_history_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_history_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_history_response->data) {
        list_ForEach(listEntry, payment_history_response->data) {
            payment_history_data_free(listEntry->data);
        }
        list_freeList(payment_history_response->data);
        payment_history_response->data = NULL;
    }
    free(payment_history_response);
}

cJSON *payment_history_response_convertToJSON(payment_history_response_t *payment_history_response) {
    cJSON *item = cJSON_CreateObject();

    // payment_history_response->status
    if(payment_history_response->status != upstox_client_payment_history_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", payment_history_response_status_ToString(payment_history_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // payment_history_response->data
    if(payment_history_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (payment_history_response->data) {
    list_ForEach(dataListEntry, payment_history_response->data) {
    cJSON *itemLocal = payment_history_data_convertToJSON(dataListEntry->data);
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

payment_history_response_t *payment_history_response_parseFromJSON(cJSON *payment_history_responseJSON){

    payment_history_response_t *payment_history_response_local_var = NULL;

    // define the local list for payment_history_response->data
    list_t *dataList = NULL;

    // payment_history_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payment_history_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_payment_history_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = payment_history_response_status_FromString(status->valuestring);
    }

    // payment_history_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(payment_history_responseJSON, "data");
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
        payment_history_data_t *dataItem = payment_history_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }



    payment_history_response_local_var = payment_history_response_create_internal (
        status ? statusVariable : upstox_client_payment_history_response_STATUS_NULL,
        data ? dataList : NULL
        );

    if (!payment_history_response_local_var) {
        goto end;
    }

    return payment_history_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            payment_history_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    return NULL;

}
