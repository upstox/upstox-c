#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "place_order_data.h"



static place_order_data_t *place_order_data_create_internal(
    char *order_id
    ) {
    place_order_data_t *place_order_data_local_var = malloc(sizeof(place_order_data_t));
    if (!place_order_data_local_var) {
        return NULL;
    }
    memset(place_order_data_local_var, 0, sizeof(place_order_data_t));
    place_order_data_local_var->_library_owned = 1;
    place_order_data_local_var->order_id = order_id;
    return place_order_data_local_var;
}

place_order_data_t *place_order_data_create(
    char *order_id
    ) {
    place_order_data_t *result = place_order_data_create_internal (
        order_id
        );
    if (!result) {
    }
    return result;
}

void place_order_data_free(place_order_data_t *place_order_data) {
    if(NULL == place_order_data){
        return ;
    }
    if(place_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "place_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (place_order_data->order_id) {
        free(place_order_data->order_id);
        place_order_data->order_id = NULL;
    }
    free(place_order_data);
}

cJSON *place_order_data_convertToJSON(place_order_data_t *place_order_data) {
    cJSON *item = cJSON_CreateObject();

    // place_order_data->order_id
    if(place_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", place_order_data->order_id) == NULL) {
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

place_order_data_t *place_order_data_parseFromJSON(cJSON *place_order_dataJSON){

    place_order_data_t *place_order_data_local_var = NULL;

    char *order_id_local_str = NULL;

    // place_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(place_order_dataJSON, "order_id");
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

    place_order_data_local_var = place_order_data_create_internal (
        order_id_local_str
        );

    if (!place_order_data_local_var) {
        goto end;
    }

    return place_order_data_local_var;
end:
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
