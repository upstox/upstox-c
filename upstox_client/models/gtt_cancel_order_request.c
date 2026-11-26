#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gtt_cancel_order_request.h"



static gtt_cancel_order_request_t *gtt_cancel_order_request_create_internal(
    char *gtt_order_id
    ) {
    gtt_cancel_order_request_t *gtt_cancel_order_request_local_var = malloc(sizeof(gtt_cancel_order_request_t));
    if (!gtt_cancel_order_request_local_var) {
        return NULL;
    }
    memset(gtt_cancel_order_request_local_var, 0, sizeof(gtt_cancel_order_request_t));
    gtt_cancel_order_request_local_var->_library_owned = 1;
    gtt_cancel_order_request_local_var->gtt_order_id = gtt_order_id;
    return gtt_cancel_order_request_local_var;
}

gtt_cancel_order_request_t *gtt_cancel_order_request_create(
    char *gtt_order_id
    ) {
    gtt_cancel_order_request_t *result = gtt_cancel_order_request_create_internal (
        gtt_order_id
        );
    if (!result) {
    }
    return result;
}

void gtt_cancel_order_request_free(gtt_cancel_order_request_t *gtt_cancel_order_request) {
    if(NULL == gtt_cancel_order_request){
        return ;
    }
    if(gtt_cancel_order_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gtt_cancel_order_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gtt_cancel_order_request->gtt_order_id) {
        free(gtt_cancel_order_request->gtt_order_id);
        gtt_cancel_order_request->gtt_order_id = NULL;
    }
    free(gtt_cancel_order_request);
}

cJSON *gtt_cancel_order_request_convertToJSON(gtt_cancel_order_request_t *gtt_cancel_order_request) {
    cJSON *item = cJSON_CreateObject();

    // gtt_cancel_order_request->gtt_order_id
    if (!gtt_cancel_order_request->gtt_order_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "gtt_order_id", gtt_cancel_order_request->gtt_order_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gtt_cancel_order_request_t *gtt_cancel_order_request_parseFromJSON(cJSON *gtt_cancel_order_requestJSON){

    gtt_cancel_order_request_t *gtt_cancel_order_request_local_var = NULL;

    char *gtt_order_id_local_str = NULL;

    // gtt_cancel_order_request->gtt_order_id
    cJSON *gtt_order_id = cJSON_GetObjectItemCaseSensitive(gtt_cancel_order_requestJSON, "gtt_order_id");
    if (cJSON_IsNull(gtt_order_id)) {
        gtt_order_id = NULL;
    }
    if (!gtt_order_id) {
        goto end;
    }

    
    if(!cJSON_IsString(gtt_order_id))
    {
    goto end; //String
    }


    if (gtt_order_id && !cJSON_IsNull(gtt_order_id)) gtt_order_id_local_str = strdup(gtt_order_id->valuestring);

    gtt_cancel_order_request_local_var = gtt_cancel_order_request_create_internal (
        gtt_order_id_local_str
        );

    if (!gtt_cancel_order_request_local_var) {
        goto end;
    }

    return gtt_cancel_order_request_local_var;
end:
    if (gtt_order_id_local_str) {
        free(gtt_order_id_local_str);
        gtt_order_id_local_str = NULL;
    }
    return NULL;

}
