#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_margin_request.h"



static us_margin_request_t *us_margin_request_create_internal(
    list_t *instruments
    ) {
    us_margin_request_t *us_margin_request_local_var = malloc(sizeof(us_margin_request_t));
    if (!us_margin_request_local_var) {
        return NULL;
    }
    memset(us_margin_request_local_var, 0, sizeof(us_margin_request_t));
    us_margin_request_local_var->_library_owned = 1;
    us_margin_request_local_var->instruments = instruments;
    return us_margin_request_local_var;
}

us_margin_request_t *us_margin_request_create(
    list_t *instruments
    ) {
    us_margin_request_t *result = us_margin_request_create_internal (
        instruments
        );
    if (!result) {
    }
    return result;
}

void us_margin_request_free(us_margin_request_t *us_margin_request) {
    if(NULL == us_margin_request){
        return ;
    }
    if(us_margin_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_margin_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_margin_request->instruments) {
        list_ForEach(listEntry, us_margin_request->instruments) {
            us_order_estimate_request_free(listEntry->data);
        }
        list_freeList(us_margin_request->instruments);
        us_margin_request->instruments = NULL;
    }
    free(us_margin_request);
}

cJSON *us_margin_request_convertToJSON(us_margin_request_t *us_margin_request) {
    cJSON *item = cJSON_CreateObject();

    // us_margin_request->instruments
    if (!us_margin_request->instruments) {
        goto fail;
    }
    cJSON *instruments = cJSON_AddArrayToObject(item, "instruments");
    if(instruments == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *instrumentsListEntry;
    if (us_margin_request->instruments) {
    list_ForEach(instrumentsListEntry, us_margin_request->instruments) {
    cJSON *itemLocal = us_order_estimate_request_convertToJSON(instrumentsListEntry->data);
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

us_margin_request_t *us_margin_request_parseFromJSON(cJSON *us_margin_requestJSON){

    us_margin_request_t *us_margin_request_local_var = NULL;

    // define the local list for us_margin_request->instruments
    list_t *instrumentsList = NULL;

    // us_margin_request->instruments
    cJSON *instruments = cJSON_GetObjectItemCaseSensitive(us_margin_requestJSON, "instruments");
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
        us_order_estimate_request_t *instrumentsItem = us_order_estimate_request_parseFromJSON(instruments_local_nonprimitive);

        list_addElement(instrumentsList, instrumentsItem);
    }



    us_margin_request_local_var = us_margin_request_create_internal (
        instrumentsList
        );

    if (!us_margin_request_local_var) {
        goto end;
    }

    return us_margin_request_local_var;
end:
    if (instrumentsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, instrumentsList) {
            us_order_estimate_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(instrumentsList);
        instrumentsList = NULL;
    }
    return NULL;

}
