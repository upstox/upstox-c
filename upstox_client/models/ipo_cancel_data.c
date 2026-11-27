#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_cancel_data.h"



static ipo_cancel_data_t *ipo_cancel_data_create_internal(
    char *order_id,
    char *status
    ) {
    ipo_cancel_data_t *ipo_cancel_data_local_var = malloc(sizeof(ipo_cancel_data_t));
    if (!ipo_cancel_data_local_var) {
        return NULL;
    }
    memset(ipo_cancel_data_local_var, 0, sizeof(ipo_cancel_data_t));
    ipo_cancel_data_local_var->_library_owned = 1;
    ipo_cancel_data_local_var->order_id = order_id;
    ipo_cancel_data_local_var->status = status;
    return ipo_cancel_data_local_var;
}

ipo_cancel_data_t *ipo_cancel_data_create(
    char *order_id,
    char *status
    ) {
    ipo_cancel_data_t *result = ipo_cancel_data_create_internal (
        order_id,
        status
        );
    if (!result) {
    }
    return result;
}

void ipo_cancel_data_free(ipo_cancel_data_t *ipo_cancel_data) {
    if(NULL == ipo_cancel_data){
        return ;
    }
    if(ipo_cancel_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_cancel_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_cancel_data->order_id) {
        free(ipo_cancel_data->order_id);
        ipo_cancel_data->order_id = NULL;
    }
    if (ipo_cancel_data->status) {
        free(ipo_cancel_data->status);
        ipo_cancel_data->status = NULL;
    }
    free(ipo_cancel_data);
}

cJSON *ipo_cancel_data_convertToJSON(ipo_cancel_data_t *ipo_cancel_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_cancel_data->order_id
    if(ipo_cancel_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", ipo_cancel_data->order_id) == NULL) {
    goto fail; //String
    }
    }


    // ipo_cancel_data->status
    if(ipo_cancel_data->status) {
    if(cJSON_AddStringToObject(item, "status", ipo_cancel_data->status) == NULL) {
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

ipo_cancel_data_t *ipo_cancel_data_parseFromJSON(cJSON *ipo_cancel_dataJSON){

    ipo_cancel_data_t *ipo_cancel_data_local_var = NULL;

    char *order_id_local_str = NULL;

    char *status_local_str = NULL;

    // ipo_cancel_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(ipo_cancel_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }

    // ipo_cancel_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(ipo_cancel_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }


    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    ipo_cancel_data_local_var = ipo_cancel_data_create_internal (
        order_id_local_str,
        status_local_str
        );

    if (!ipo_cancel_data_local_var) {
        goto end;
    }

    return ipo_cancel_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
