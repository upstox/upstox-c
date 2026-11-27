#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_order_data.h"



static cancel_order_data_t *cancel_order_data_create_internal(
    char *order_id
    ) {
    cancel_order_data_t *cancel_order_data_local_var = malloc(sizeof(cancel_order_data_t));
    if (!cancel_order_data_local_var) {
        return NULL;
    }
    memset(cancel_order_data_local_var, 0, sizeof(cancel_order_data_t));
    cancel_order_data_local_var->_library_owned = 1;
    cancel_order_data_local_var->order_id = order_id;
    return cancel_order_data_local_var;
}

cancel_order_data_t *cancel_order_data_create(
    char *order_id
    ) {
    cancel_order_data_t *result = cancel_order_data_create_internal (
        order_id
        );
    if (!result) {
    }
    return result;
}

void cancel_order_data_free(cancel_order_data_t *cancel_order_data) {
    if(NULL == cancel_order_data){
        return ;
    }
    if(cancel_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_order_data->order_id) {
        free(cancel_order_data->order_id);
        cancel_order_data->order_id = NULL;
    }
    free(cancel_order_data);
}

cJSON *cancel_order_data_convertToJSON(cancel_order_data_t *cancel_order_data) {
    cJSON *item = cJSON_CreateObject();

    // cancel_order_data->order_id
    if(cancel_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", cancel_order_data->order_id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cancel_order_data_t *cancel_order_data_parseFromJSON(cJSON *cancel_order_dataJSON){

    cancel_order_data_t *cancel_order_data_local_var = NULL;

    char *order_id_local_str = NULL;

    // cancel_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(cancel_order_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }


    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);

    cancel_order_data_local_var = cancel_order_data_create_internal (
        order_id_local_str
        );

    if (!cancel_order_data_local_var) {
        goto end;
    }

    return cancel_order_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
