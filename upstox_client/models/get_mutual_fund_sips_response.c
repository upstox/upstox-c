#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_mutual_fund_sips_response.h"


char* get_mutual_fund_sips_response_status_ToString(upstox_client_get_mutual_fund_sips_response_STATUS_e status) {
    char* statusArray[] =  { "NULL", "success", "error", "partial_success" };
    return statusArray[status];
}

upstox_client_get_mutual_fund_sips_response_STATUS_e get_mutual_fund_sips_response_status_FromString(char* status){
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

static get_mutual_fund_sips_response_t *get_mutual_fund_sips_response_create_internal(
    upstox_client_get_mutual_fund_sips_response_STATUS_e status,
    list_t *data,
    mutual_fund_meta_data_t *meta_data
    ) {
    get_mutual_fund_sips_response_t *get_mutual_fund_sips_response_local_var = malloc(sizeof(get_mutual_fund_sips_response_t));
    if (!get_mutual_fund_sips_response_local_var) {
        return NULL;
    }
    memset(get_mutual_fund_sips_response_local_var, 0, sizeof(get_mutual_fund_sips_response_t));
    get_mutual_fund_sips_response_local_var->_library_owned = 1;
    get_mutual_fund_sips_response_local_var->status = status;
    get_mutual_fund_sips_response_local_var->data = data;
    get_mutual_fund_sips_response_local_var->meta_data = meta_data;
    return get_mutual_fund_sips_response_local_var;
}

get_mutual_fund_sips_response_t *get_mutual_fund_sips_response_create(
    upstox_client_get_mutual_fund_sips_response_STATUS_e status,
    list_t *data,
    mutual_fund_meta_data_t *meta_data
    ) {
    get_mutual_fund_sips_response_t *result = get_mutual_fund_sips_response_create_internal (
        status,
        data,
        meta_data
        );
    if (!result) {
    }
    return result;
}

void get_mutual_fund_sips_response_free(get_mutual_fund_sips_response_t *get_mutual_fund_sips_response) {
    if(NULL == get_mutual_fund_sips_response){
        return ;
    }
    if(get_mutual_fund_sips_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_mutual_fund_sips_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_mutual_fund_sips_response->data) {
        list_ForEach(listEntry, get_mutual_fund_sips_response->data) {
            mutual_fund_sip_data_free(listEntry->data);
        }
        list_freeList(get_mutual_fund_sips_response->data);
        get_mutual_fund_sips_response->data = NULL;
    }
    if (get_mutual_fund_sips_response->meta_data) {
        mutual_fund_meta_data_free(get_mutual_fund_sips_response->meta_data);
        get_mutual_fund_sips_response->meta_data = NULL;
    }
    free(get_mutual_fund_sips_response);
}

cJSON *get_mutual_fund_sips_response_convertToJSON(get_mutual_fund_sips_response_t *get_mutual_fund_sips_response) {
    cJSON *item = cJSON_CreateObject();

    // get_mutual_fund_sips_response->status
    if(get_mutual_fund_sips_response->status != upstox_client_get_mutual_fund_sips_response_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", get_mutual_fund_sips_response_status_ToString(get_mutual_fund_sips_response->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // get_mutual_fund_sips_response->data
    if(get_mutual_fund_sips_response->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *dataListEntry;
    if (get_mutual_fund_sips_response->data) {
    list_ForEach(dataListEntry, get_mutual_fund_sips_response->data) {
    cJSON *itemLocal = mutual_fund_sip_data_convertToJSON(dataListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(data, itemLocal);
    }
    }
    }


    // get_mutual_fund_sips_response->meta_data
    if(get_mutual_fund_sips_response->meta_data) {
    cJSON *meta_data_local_JSON = mutual_fund_meta_data_convertToJSON(get_mutual_fund_sips_response->meta_data);
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

get_mutual_fund_sips_response_t *get_mutual_fund_sips_response_parseFromJSON(cJSON *get_mutual_fund_sips_responseJSON){

    get_mutual_fund_sips_response_t *get_mutual_fund_sips_response_local_var = NULL;

    // define the local list for get_mutual_fund_sips_response->data
    list_t *dataList = NULL;

    // define the local variable for get_mutual_fund_sips_response->meta_data
    mutual_fund_meta_data_t *meta_data_local_nonprim = NULL;

    // get_mutual_fund_sips_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(get_mutual_fund_sips_responseJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_get_mutual_fund_sips_response_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = get_mutual_fund_sips_response_status_FromString(status->valuestring);
    }

    // get_mutual_fund_sips_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(get_mutual_fund_sips_responseJSON, "data");
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
        mutual_fund_sip_data_t *dataItem = mutual_fund_sip_data_parseFromJSON(data_local_nonprimitive);

        list_addElement(dataList, dataItem);
    }
    }

    // get_mutual_fund_sips_response->meta_data
    cJSON *meta_data = cJSON_GetObjectItemCaseSensitive(get_mutual_fund_sips_responseJSON, "meta_data");
    if (cJSON_IsNull(meta_data)) {
        meta_data = NULL;
    }
    if (meta_data) { 
    meta_data_local_nonprim = mutual_fund_meta_data_parseFromJSON(meta_data); //nonprimitive
    }



    get_mutual_fund_sips_response_local_var = get_mutual_fund_sips_response_create_internal (
        status ? statusVariable : upstox_client_get_mutual_fund_sips_response_STATUS_NULL,
        data ? dataList : NULL,
        meta_data ? meta_data_local_nonprim : NULL
        );

    if (!get_mutual_fund_sips_response_local_var) {
        goto end;
    }

    return get_mutual_fund_sips_response_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            mutual_fund_sip_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (meta_data_local_nonprim) {
        mutual_fund_meta_data_free(meta_data_local_nonprim);
        meta_data_local_nonprim = NULL;
    }
    return NULL;

}
