#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "corporate_action_event_detail.h"



static corporate_action_event_detail_t *corporate_action_event_detail_create_internal(
    char *name,
    char *value
    ) {
    corporate_action_event_detail_t *corporate_action_event_detail_local_var = malloc(sizeof(corporate_action_event_detail_t));
    if (!corporate_action_event_detail_local_var) {
        return NULL;
    }
    memset(corporate_action_event_detail_local_var, 0, sizeof(corporate_action_event_detail_t));
    corporate_action_event_detail_local_var->_library_owned = 1;
    corporate_action_event_detail_local_var->name = name;
    corporate_action_event_detail_local_var->value = value;
    return corporate_action_event_detail_local_var;
}

corporate_action_event_detail_t *corporate_action_event_detail_create(
    char *name,
    char *value
    ) {
    corporate_action_event_detail_t *result = corporate_action_event_detail_create_internal (
        name,
        value
        );
    if (!result) {
    }
    return result;
}

void corporate_action_event_detail_free(corporate_action_event_detail_t *corporate_action_event_detail) {
    if(NULL == corporate_action_event_detail){
        return ;
    }
    if(corporate_action_event_detail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "corporate_action_event_detail_free");
        return ;
    }
    listEntry_t *listEntry;
    if (corporate_action_event_detail->name) {
        free(corporate_action_event_detail->name);
        corporate_action_event_detail->name = NULL;
    }
    if (corporate_action_event_detail->value) {
        free(corporate_action_event_detail->value);
        corporate_action_event_detail->value = NULL;
    }
    free(corporate_action_event_detail);
}

cJSON *corporate_action_event_detail_convertToJSON(corporate_action_event_detail_t *corporate_action_event_detail) {
    cJSON *item = cJSON_CreateObject();

    // corporate_action_event_detail->name
    if(corporate_action_event_detail->name) {
    if(cJSON_AddStringToObject(item, "name", corporate_action_event_detail->name) == NULL) {
    goto fail; //String
    }
    }


    // corporate_action_event_detail->value
    if(corporate_action_event_detail->value) {
    if(cJSON_AddStringToObject(item, "value", corporate_action_event_detail->value) == NULL) {
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

corporate_action_event_detail_t *corporate_action_event_detail_parseFromJSON(cJSON *corporate_action_event_detailJSON){

    corporate_action_event_detail_t *corporate_action_event_detail_local_var = NULL;

    char *name_local_str = NULL;

    char *value_local_str = NULL;

    // corporate_action_event_detail->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(corporate_action_event_detailJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // corporate_action_event_detail->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(corporate_action_event_detailJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    corporate_action_event_detail_local_var = corporate_action_event_detail_create_internal (
        name_local_str,
        value_local_str
        );

    if (!corporate_action_event_detail_local_var) {
        goto end;
    }

    return corporate_action_event_detail_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
