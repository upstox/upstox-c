#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "margin_request.h"



static margin_request_t *margin_request_create_internal(
    list_t *instruments
    ) {
    margin_request_t *margin_request_local_var = malloc(sizeof(margin_request_t));
    if (!margin_request_local_var) {
        return NULL;
    }
    memset(margin_request_local_var, 0, sizeof(margin_request_t));
    margin_request_local_var->_library_owned = 1;
    margin_request_local_var->instruments = instruments;
    return margin_request_local_var;
}

margin_request_t *margin_request_create(
    list_t *instruments
    ) {
    margin_request_t *result = margin_request_create_internal (
        instruments
        );
    if (!result) {
    }
    return result;
}

void margin_request_free(margin_request_t *margin_request) {
    if(NULL == margin_request){
        return ;
    }
    if(margin_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "margin_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (margin_request->instruments) {
        list_ForEach(listEntry, margin_request->instruments) {
            instrument_free(listEntry->data);
        }
        list_freeList(margin_request->instruments);
        margin_request->instruments = NULL;
    }
    free(margin_request);
}

cJSON *margin_request_convertToJSON(margin_request_t *margin_request) {
    cJSON *item = cJSON_CreateObject();

    // margin_request->instruments
    if (!margin_request->instruments) {
        goto fail;
    }
    cJSON *instruments = cJSON_AddArrayToObject(item, "instruments");
    if(instruments == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *instrumentsListEntry;
    if (margin_request->instruments) {
    list_ForEach(instrumentsListEntry, margin_request->instruments) {
    cJSON *itemLocal = instrument_convertToJSON(instrumentsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(instruments, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

margin_request_t *margin_request_parseFromJSON(cJSON *margin_requestJSON){

    margin_request_t *margin_request_local_var = NULL;

    // define the local list for margin_request->instruments
    list_t *instrumentsList = NULL;

    // margin_request->instruments
    cJSON *instruments = cJSON_GetObjectItemCaseSensitive(margin_requestJSON, "instruments");
    if (cJSON_IsNull(instruments)) {
        instruments = NULL;
    }
    if (!instruments) {
        goto end;
    }

    
    cJSON *instruments_local_nonprimitive = NULL;
    if(!cJSON_IsArray(instruments)){
        goto end; //nonprimitive container
    }

    instrumentsList = list_createList();

    cJSON_ArrayForEach(instruments_local_nonprimitive,instruments )
    {
        if(!cJSON_IsObject(instruments_local_nonprimitive)){
            goto end;
        }
        instrument_t *instrumentsItem = instrument_parseFromJSON(instruments_local_nonprimitive);

        list_addElement(instrumentsList, instrumentsItem);
    }



    margin_request_local_var = margin_request_create_internal (
        instrumentsList
        );

    if (!margin_request_local_var) {
        goto end;
    }

    return margin_request_local_var;
end:
    if (instrumentsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instrumentsList) {
            instrument_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instrumentsList);
        instrumentsList = NULL;
    }
    return NULL;

}
