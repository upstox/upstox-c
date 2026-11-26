#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_data.h"



static us_order_data_t *us_order_data_create_internal(
    char *order_id
    ) {
    us_order_data_t *us_order_data_local_var = malloc(sizeof(us_order_data_t));
    if (!us_order_data_local_var) {
        return NULL;
    }
    memset(us_order_data_local_var, 0, sizeof(us_order_data_t));
    us_order_data_local_var->_library_owned = 1;
    us_order_data_local_var->order_id = order_id;
    return us_order_data_local_var;
}

us_order_data_t *us_order_data_create(
    char *order_id
    ) {
    us_order_data_t *result = us_order_data_create_internal (
        order_id
        );
    if (!result) {
    }
    return result;
}

void us_order_data_free(us_order_data_t *us_order_data) {
    if(NULL == us_order_data){
        return ;
    }
    if(us_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_data->order_id) {
        free(us_order_data->order_id);
        us_order_data->order_id = NULL;
    }
    free(us_order_data);
}

cJSON *us_order_data_convertToJSON(us_order_data_t *us_order_data) {
    cJSON *item = cJSON_CreateObject();

    // us_order_data->order_id
    if(us_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", us_order_data->order_id) == NULL) {
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

us_order_data_t *us_order_data_parseFromJSON(cJSON *us_order_dataJSON){

    us_order_data_t *us_order_data_local_var = NULL;

    char *order_id_local_str = NULL;

    // us_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(us_order_dataJSON, "order_id");
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

    us_order_data_local_var = us_order_data_create_internal (
        order_id_local_str
        );

    if (!us_order_data_local_var) {
        goto end;
    }

    return us_order_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
