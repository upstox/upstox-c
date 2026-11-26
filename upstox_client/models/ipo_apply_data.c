#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipo_apply_data.h"



static ipo_apply_data_t *ipo_apply_data_create_internal(
    char *order_id
    ) {
    ipo_apply_data_t *ipo_apply_data_local_var = malloc(sizeof(ipo_apply_data_t));
    if (!ipo_apply_data_local_var) {
        return NULL;
    }
    memset(ipo_apply_data_local_var, 0, sizeof(ipo_apply_data_t));
    ipo_apply_data_local_var->_library_owned = 1;
    ipo_apply_data_local_var->order_id = order_id;
    return ipo_apply_data_local_var;
}

ipo_apply_data_t *ipo_apply_data_create(
    char *order_id
    ) {
    ipo_apply_data_t *result = ipo_apply_data_create_internal (
        order_id
        );
    if (!result) {
    }
    return result;
}

void ipo_apply_data_free(ipo_apply_data_t *ipo_apply_data) {
    if(NULL == ipo_apply_data){
        return ;
    }
    if(ipo_apply_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipo_apply_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipo_apply_data->order_id) {
        free(ipo_apply_data->order_id);
        ipo_apply_data->order_id = NULL;
    }
    free(ipo_apply_data);
}

cJSON *ipo_apply_data_convertToJSON(ipo_apply_data_t *ipo_apply_data) {
    cJSON *item = cJSON_CreateObject();

    // ipo_apply_data->order_id
    if(ipo_apply_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", ipo_apply_data->order_id) == NULL) {
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

ipo_apply_data_t *ipo_apply_data_parseFromJSON(cJSON *ipo_apply_dataJSON){

    ipo_apply_data_t *ipo_apply_data_local_var = NULL;

    char *order_id_local_str = NULL;

    // ipo_apply_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(ipo_apply_dataJSON, "order_id");
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

    ipo_apply_data_local_var = ipo_apply_data_create_internal (
        order_id_local_str
        );

    if (!ipo_apply_data_local_var) {
        goto end;
    }

    return ipo_apply_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
