#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "family_member_data.h"



static family_member_data_t *family_member_data_create_internal(
    char *user_id,
    char *name
    ) {
    family_member_data_t *family_member_data_local_var = malloc(sizeof(family_member_data_t));
    if (!family_member_data_local_var) {
        return NULL;
    }
    memset(family_member_data_local_var, 0, sizeof(family_member_data_t));
    family_member_data_local_var->_library_owned = 1;
    family_member_data_local_var->user_id = user_id;
    family_member_data_local_var->name = name;
    return family_member_data_local_var;
}

family_member_data_t *family_member_data_create(
    char *user_id,
    char *name
    ) {
    family_member_data_t *result = family_member_data_create_internal (
        user_id,
        name
        );
    if (!result) {
    }
    return result;
}

void family_member_data_free(family_member_data_t *family_member_data) {
    if(NULL == family_member_data){
        return ;
    }
    if(family_member_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "family_member_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (family_member_data->user_id) {
        free(family_member_data->user_id);
        family_member_data->user_id = NULL;
    }
    if (family_member_data->name) {
        free(family_member_data->name);
        family_member_data->name = NULL;
    }
    free(family_member_data);
}

cJSON *family_member_data_convertToJSON(family_member_data_t *family_member_data) {
    cJSON *item = cJSON_CreateObject();

    // family_member_data->user_id
    if(family_member_data->user_id) {
    if(cJSON_AddStringToObject(item, "user_id", family_member_data->user_id) == NULL) {
    goto fail; //String
    }
    }


    // family_member_data->name
    if(family_member_data->name) {
    if(cJSON_AddStringToObject(item, "name", family_member_data->name) == NULL) {
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

family_member_data_t *family_member_data_parseFromJSON(cJSON *family_member_dataJSON){

    family_member_data_t *family_member_data_local_var = NULL;

    char *user_id_local_str = NULL;

    char *name_local_str = NULL;

    // family_member_data->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(family_member_dataJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // family_member_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(family_member_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    if (user_id && !cJSON_IsNull(user_id)) user_id_local_str = strdup(user_id->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    family_member_data_local_var = family_member_data_create_internal (
        user_id_local_str,
        name_local_str
        );

    if (!family_member_data_local_var) {
        goto end;
    }

    return family_member_data_local_var;
end:
    if (user_id_local_str) {
        free(user_id_local_str);
        user_id_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
