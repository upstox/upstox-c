#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_data.h"



static multi_order_data_t *multi_order_data_create_internal(
    char *correlation_id,
    char *order_id
    ) {
    multi_order_data_t *multi_order_data_local_var = malloc(sizeof(multi_order_data_t));
    if (!multi_order_data_local_var) {
        return NULL;
    }
    memset(multi_order_data_local_var, 0, sizeof(multi_order_data_t));
    multi_order_data_local_var->_library_owned = 1;
    multi_order_data_local_var->correlation_id = correlation_id;
    multi_order_data_local_var->order_id = order_id;
    return multi_order_data_local_var;
}

multi_order_data_t *multi_order_data_create(
    char *correlation_id,
    char *order_id
    ) {
    multi_order_data_t *result = multi_order_data_create_internal (
        correlation_id,
        order_id
        );
    if (!result) {
    }
    return result;
}

void multi_order_data_free(multi_order_data_t *multi_order_data) {
    if(NULL == multi_order_data){
        return ;
    }
    if(multi_order_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_data->correlation_id) {
        free(multi_order_data->correlation_id);
        multi_order_data->correlation_id = NULL;
    }
    if (multi_order_data->order_id) {
        free(multi_order_data->order_id);
        multi_order_data->order_id = NULL;
    }
    free(multi_order_data);
}

cJSON *multi_order_data_convertToJSON(multi_order_data_t *multi_order_data) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_data->correlation_id
    if(multi_order_data->correlation_id) {
    if(cJSON_AddStringToObject(item, "correlation_id", multi_order_data->correlation_id) == NULL) {
    goto fail; //String
    }
    }


    // multi_order_data->order_id
    if(multi_order_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", multi_order_data->order_id) == NULL) {
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

multi_order_data_t *multi_order_data_parseFromJSON(cJSON *multi_order_dataJSON){

    multi_order_data_t *multi_order_data_local_var = NULL;

    char *correlation_id_local_str = NULL;

    char *order_id_local_str = NULL;

    // multi_order_data->correlation_id
    cJSON *correlation_id = cJSON_GetObjectItemCaseSensitive(multi_order_dataJSON, "correlation_id");
    if (cJSON_IsNull(correlation_id)) {
        correlation_id = NULL;
    }
    if (correlation_id) { 
    if(!cJSON_IsString(correlation_id) && !cJSON_IsNull(correlation_id))
    {
    goto end; //String
    }
    }

    // multi_order_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(multi_order_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }


    if (correlation_id && !cJSON_IsNull(correlation_id)) correlation_id_local_str = strdup(correlation_id->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);

    multi_order_data_local_var = multi_order_data_create_internal (
        correlation_id_local_str,
        order_id_local_str
        );

    if (!multi_order_data_local_var) {
        goto end;
    }

    return multi_order_data_local_var;
end:
    if (correlation_id_local_str) {
        free(correlation_id_local_str);
        correlation_id_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
