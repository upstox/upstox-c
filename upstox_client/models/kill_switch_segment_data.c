#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kill_switch_segment_data.h"


char* kill_switch_segment_data_segment_status_ToString(upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status) {
    char* segment_statusArray[] =  { "NULL", "ACTIVE", "INACTIVE" };
    return segment_statusArray[segment_status];
}

upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e kill_switch_segment_data_segment_status_FromString(char* segment_status){
    int stringToReturn = 0;
    char *segment_statusArray[] =  { "NULL", "ACTIVE", "INACTIVE" };
    size_t sizeofArray = sizeof(segment_statusArray) / sizeof(segment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(segment_status, segment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static kill_switch_segment_data_t *kill_switch_segment_data_create_internal(
    char *segment,
    upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status,
    int *kill_switch_enabled
    ) {
    kill_switch_segment_data_t *kill_switch_segment_data_local_var = malloc(sizeof(kill_switch_segment_data_t));
    if (!kill_switch_segment_data_local_var) {
        return NULL;
    }
    memset(kill_switch_segment_data_local_var, 0, sizeof(kill_switch_segment_data_t));
    kill_switch_segment_data_local_var->_library_owned = 1;
    kill_switch_segment_data_local_var->segment = segment;
    kill_switch_segment_data_local_var->segment_status = segment_status;
    kill_switch_segment_data_local_var->kill_switch_enabled = kill_switch_enabled;
    return kill_switch_segment_data_local_var;
}

kill_switch_segment_data_t *kill_switch_segment_data_create(
    char *segment,
    upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status,
    int *kill_switch_enabled
    ) {
    int *kill_switch_enabled_copy = NULL;
    if (kill_switch_enabled) {
        kill_switch_enabled_copy = malloc(sizeof(int));
        if (kill_switch_enabled_copy) *kill_switch_enabled_copy = *kill_switch_enabled;
    }
    kill_switch_segment_data_t *result = kill_switch_segment_data_create_internal (
        segment,
        segment_status,
        kill_switch_enabled_copy
        );
    if (!result) {
        free(kill_switch_enabled_copy);
    }
    return result;
}

void kill_switch_segment_data_free(kill_switch_segment_data_t *kill_switch_segment_data) {
    if(NULL == kill_switch_segment_data){
        return ;
    }
    if(kill_switch_segment_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kill_switch_segment_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kill_switch_segment_data->segment) {
        free(kill_switch_segment_data->segment);
        kill_switch_segment_data->segment = NULL;
    }
    if (kill_switch_segment_data->kill_switch_enabled) {
        free(kill_switch_segment_data->kill_switch_enabled);
        kill_switch_segment_data->kill_switch_enabled = NULL;
    }
    free(kill_switch_segment_data);
}

cJSON *kill_switch_segment_data_convertToJSON(kill_switch_segment_data_t *kill_switch_segment_data) {
    cJSON *item = cJSON_CreateObject();

    // kill_switch_segment_data->segment
    if(kill_switch_segment_data->segment) {
    if(cJSON_AddStringToObject(item, "segment", kill_switch_segment_data->segment) == NULL) {
    goto fail; //String
    }
    }


    // kill_switch_segment_data->segment_status
    if(kill_switch_segment_data->segment_status != upstox_client_kill_switch_segment_data_SEGMENTSTATUS_NULL) {
    if(cJSON_AddStringToObject(item, "segment_status", kill_switch_segment_data_segment_status_ToString(kill_switch_segment_data->segment_status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // kill_switch_segment_data->kill_switch_enabled
    if(kill_switch_segment_data->kill_switch_enabled) {
    if(cJSON_AddBoolToObject(item, "kill_switch_enabled", *kill_switch_segment_data->kill_switch_enabled) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kill_switch_segment_data_t *kill_switch_segment_data_parseFromJSON(cJSON *kill_switch_segment_dataJSON){

    kill_switch_segment_data_t *kill_switch_segment_data_local_var = NULL;

    char *segment_local_str = NULL;

    // define the local variable for kill_switch_segment_data->kill_switch_enabled
    int *kill_switch_enabled_local_var = NULL;

    // kill_switch_segment_data->segment
    cJSON *segment = cJSON_GetObjectItemCaseSensitive(kill_switch_segment_dataJSON, "segment");
    if (cJSON_IsNull(segment)) {
        segment = NULL;
    }
    if (segment) { 
    if(!cJSON_IsString(segment) && !cJSON_IsNull(segment))
    {
    goto end; //String
    }
    }

    // kill_switch_segment_data->segment_status
    cJSON *segment_status = cJSON_GetObjectItemCaseSensitive(kill_switch_segment_dataJSON, "segment_status");
    if (cJSON_IsNull(segment_status)) {
        segment_status = NULL;
    }
    upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_statusVariable;
    if (segment_status) { 
    if(!cJSON_IsString(segment_status))
    {
    goto end; //Enum
    }
    segment_statusVariable = kill_switch_segment_data_segment_status_FromString(segment_status->valuestring);
    }

    // kill_switch_segment_data->kill_switch_enabled
    cJSON *kill_switch_enabled = cJSON_GetObjectItemCaseSensitive(kill_switch_segment_dataJSON, "kill_switch_enabled");
    if (cJSON_IsNull(kill_switch_enabled)) {
        kill_switch_enabled = NULL;
    }
    if (kill_switch_enabled) { 
    if(!cJSON_IsBool(kill_switch_enabled))
    {
    goto end; //Bool
    }
    kill_switch_enabled_local_var = malloc(sizeof(int));
    if(!kill_switch_enabled_local_var)
    {
        goto end;
    }
    *kill_switch_enabled_local_var = kill_switch_enabled->valueint;
    }


    if (segment && !cJSON_IsNull(segment)) segment_local_str = strdup(segment->valuestring);

    kill_switch_segment_data_local_var = kill_switch_segment_data_create_internal (
        segment_local_str,
        segment_status ? segment_statusVariable : upstox_client_kill_switch_segment_data_SEGMENTSTATUS_NULL,
        kill_switch_enabled_local_var
        );

    if (!kill_switch_segment_data_local_var) {
        goto end;
    }

    return kill_switch_segment_data_local_var;
end:
    if (segment_local_str) {
        free(segment_local_str);
        segment_local_str = NULL;
    }
    if (kill_switch_enabled_local_var) {
        free(kill_switch_enabled_local_var);
        kill_switch_enabled_local_var = NULL;
    }
    return NULL;

}
