#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modify_order_data.h"



static modify_order_data_t *modify_order_data_create_internal(
    char *order_id
    ) {
    modify_order_data_t *modify_order_data_local_var = malloc(sizeof(modify_order_data_t));
    if (!modify_order_data_local_var) {
        return NULL;
    }
    memset(modify_order_data_local_var, 0, sizeof(modify_order_data_t));
    modify_order_data_local_var->_library_owned = 1;
    modify_order_data_local_var->order_id = order_id;
    return modify_order_data_local_var;
}

modify_order_data_t *modify_order_data_create(
    char *order_id
    ) {
    modify_order_data_t *result = modify_order_data_create_internal (
        order_id
        );
    if (!result) {
    }
    return result;
}

void modify_order_data_free(modify_order_data_t *modify_order_data) {
    if(NULL == modify_order_data){
        return ;
    }
    if(modify_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "modify_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (modify_order_data->order_id) {
        free(modify_order_data->order_id);
        modify_order_data->order_id = NULL;
    }
    free(modify_order_data);
}

cJSON *modify_order_data_convertToJSON(modify_order_data_t *modify_order_data) {
    cJSON *item = cJSON_CreateObject();

    // modify_order_data->order_id
    if(modify_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", modify_order_data->order_id) == NULL) {
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

modify_order_data_t *modify_order_data_parseFromJSON(cJSON *modify_order_dataJSON){

    modify_order_data_t *modify_order_data_local_var = NULL;

    char *order_id_local_str = NULL;

    // modify_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(modify_order_dataJSON, "order_id");
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

    modify_order_data_local_var = modify_order_data_create_internal (
        order_id_local_str
        );

    if (!modify_order_data_local_var) {
        goto end;
    }

    return modify_order_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
