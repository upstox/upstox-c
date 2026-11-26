#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_position_data.h"



static convert_position_data_t *convert_position_data_create_internal(
    char *status
    ) {
    convert_position_data_t *convert_position_data_local_var = malloc(sizeof(convert_position_data_t));
    if (!convert_position_data_local_var) {
        return NULL;
    }
    memset(convert_position_data_local_var, 0, sizeof(convert_position_data_t));
    convert_position_data_local_var->_library_owned = 1;
    convert_position_data_local_var->status = status;
    return convert_position_data_local_var;
}

convert_position_data_t *convert_position_data_create(
    char *status
    ) {
    convert_position_data_t *result = convert_position_data_create_internal (
        status
        );
    if (!result) {
    }
    return result;
}

void convert_position_data_free(convert_position_data_t *convert_position_data) {
    if(NULL == convert_position_data){
        return ;
    }
    if(convert_position_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_position_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (convert_position_data->status) {
        free(convert_position_data->status);
        convert_position_data->status = NULL;
    }
    free(convert_position_data);
}

cJSON *convert_position_data_convertToJSON(convert_position_data_t *convert_position_data) {
    cJSON *item = cJSON_CreateObject();

    // convert_position_data->status
    if(convert_position_data->status) {
    if(cJSON_AddStringToObject(item, "status", convert_position_data->status) == NULL) {
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

convert_position_data_t *convert_position_data_parseFromJSON(cJSON *convert_position_dataJSON){

    convert_position_data_t *convert_position_data_local_var = NULL;

    char *status_local_str = NULL;

    // convert_position_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(convert_position_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    convert_position_data_local_var = convert_position_data_create_internal (
        status_local_str
        );

    if (!convert_position_data_local_var) {
        goto end;
    }

    return convert_position_data_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    return NULL;

}
