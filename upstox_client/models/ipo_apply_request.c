#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_apply_request.h"


char* ipo_apply_request_category_ToString(upstox_client_ipo_apply_request_CATEGORY_e category) {
    char* categoryArray[] =  { "NULL", "IND", "HNI" };
    return categoryArray[category];
}

upstox_client_ipo_apply_request_CATEGORY_e ipo_apply_request_category_FromString(char* category){
    int stringToReturn = 0;
    char *categoryArray[] =  { "NULL", "IND", "HNI" };
    size_t sizeofArray = sizeof(categoryArray) / sizeof(categoryArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(category, categoryArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static ipo_apply_request_t *ipo_apply_request_create_internal(
    char *id,
    char *upi,
    upstox_client_ipo_apply_request_CATEGORY_e category,
    list_t *bids
    ) {
    ipo_apply_request_t *ipo_apply_request_local_var = malloc(sizeof(ipo_apply_request_t));
    if (!ipo_apply_request_local_var) {
        return NULL;
    }
    memset(ipo_apply_request_local_var, 0, sizeof(ipo_apply_request_t));
    ipo_apply_request_local_var->_library_owned = 1;
    ipo_apply_request_local_var->id = id;
    ipo_apply_request_local_var->upi = upi;
    ipo_apply_request_local_var->category = category;
    ipo_apply_request_local_var->bids = bids;
    return ipo_apply_request_local_var;
}

ipo_apply_request_t *ipo_apply_request_create(
    char *id,
    char *upi,
    upstox_client_ipo_apply_request_CATEGORY_e category,
    list_t *bids
    ) {
    ipo_apply_request_t *result = ipo_apply_request_create_internal (
        id,
        upi,
        category,
        bids
        );
    if (!result) {
    }
    return result;
}

void ipo_apply_request_free(ipo_apply_request_t *ipo_apply_request) {
    if(NULL == ipo_apply_request){
        return ;
    }
    if(ipo_apply_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_apply_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_apply_request->id) {
        free(ipo_apply_request->id);
        ipo_apply_request->id = NULL;
    }
    if (ipo_apply_request->upi) {
        free(ipo_apply_request->upi);
        ipo_apply_request->upi = NULL;
    }
    if (ipo_apply_request->bids) {
        list_ForEach(listEntry, ipo_apply_request->bids) {
            ipo_bid_request_free(listEntry->data);
        }
        list_freeList(ipo_apply_request->bids);
        ipo_apply_request->bids = NULL;
    }
    free(ipo_apply_request);
}

cJSON *ipo_apply_request_convertToJSON(ipo_apply_request_t *ipo_apply_request) {
    cJSON *item = cJSON_CreateObject();

    // ipo_apply_request->id
    if (!ipo_apply_request->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", ipo_apply_request->id) == NULL) {
    goto fail; //String
    }


    // ipo_apply_request->upi
    if (!ipo_apply_request->upi) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "upi", ipo_apply_request->upi) == NULL) {
    goto fail; //String
    }


    // ipo_apply_request->category
    if (upstox_client_ipo_apply_request_CATEGORY_NULL == ipo_apply_request->category) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "category", ipo_apply_request_category_ToString(ipo_apply_request->category)) == NULL)
    {
    goto fail; //Enum
    }


    // ipo_apply_request->bids
    if (!ipo_apply_request->bids) {
        goto fail;
    }
    cJSON *bids = cJSON_AddArrayToObject(item, "bids");
    if(bids == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *bidsListEntry;
    if (ipo_apply_request->bids) {
    list_ForEach(bidsListEntry, ipo_apply_request->bids) {
    cJSON *itemLocal = ipo_bid_request_convertToJSON(bidsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(bids, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipo_apply_request_t *ipo_apply_request_parseFromJSON(cJSON *ipo_apply_requestJSON){

    ipo_apply_request_t *ipo_apply_request_local_var = NULL;

    char *id_local_str = NULL;

    char *upi_local_str = NULL;

    // define the local list for ipo_apply_request->bids
    list_t *bidsList = NULL;

    // ipo_apply_request->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(ipo_apply_requestJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // ipo_apply_request->upi
    cJSON *upi = cJSON_GetObjectItemCaseSensitive(ipo_apply_requestJSON, "upi");
    if (cJSON_IsNull(upi)) {
        upi = NULL;
    }
    if (!upi) {
        goto end;
    }

    
    if(!cJSON_IsString(upi))
    {
    goto end; //String
    }

    // ipo_apply_request->category
    cJSON *category = cJSON_GetObjectItemCaseSensitive(ipo_apply_requestJSON, "category");
    if (cJSON_IsNull(category)) {
        category = NULL;
    }
    if (!category) {
        goto end;
    }

    upstox_client_ipo_apply_request_CATEGORY_e categoryVariable;
    
    if(!cJSON_IsString(category))
    {
    goto end; //Enum
    }
    categoryVariable = ipo_apply_request_category_FromString(category->valuestring);

    // ipo_apply_request->bids
    cJSON *bids = cJSON_GetObjectItemCaseSensitive(ipo_apply_requestJSON, "bids");
    if (cJSON_IsNull(bids)) {
        bids = NULL;
    }
    if (!bids) {
        goto end;
    }

    
    cJSON *bids_local_nonprimitive = NULL;
    if(!cJSON_IsArray(bids)){
        goto end; //nonprimitive container
    }

    bidsList = list_createList();

    cJSON_ArrayForEach(bids_local_nonprimitive,bids )
    {
        if(!cJSON_IsObject(bids_local_nonprimitive)){
            goto end;
        }
        ipo_bid_request_t *bidsItem = ipo_bid_request_parseFromJSON(bids_local_nonprimitive);

        list_addElement(bidsList, bidsItem);
    }


    if (id && !cJSON_IsNull(id)) id_local_str = strdup(id->valuestring);
    if (upi && !cJSON_IsNull(upi)) upi_local_str = strdup(upi->valuestring);

    ipo_apply_request_local_var = ipo_apply_request_create_internal (
        id_local_str,
        upi_local_str,
        categoryVariable,
        bidsList
        );

    if (!ipo_apply_request_local_var) {
        goto end;
    }

    return ipo_apply_request_local_var;
end:
    if (id_local_str) {
        free(id_local_str);
        id_local_str = NULL;
    }
    if (upi_local_str) {
        free(upi_local_str);
        upi_local_str = NULL;
    }
    if (bidsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, bidsList) {
            ipo_bid_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(bidsList);
        bidsList = NULL;
    }
    return NULL;

}
