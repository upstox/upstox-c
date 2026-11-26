#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "key_ratio_data.h"



static key_ratio_data_t *key_ratio_data_create_internal(
    char *name,
    char *company_value,
    char *sector_value
    ) {
    key_ratio_data_t *key_ratio_data_local_var = malloc(sizeof(key_ratio_data_t));
    if (!key_ratio_data_local_var) {
        return NULL;
    }
    memset(key_ratio_data_local_var, 0, sizeof(key_ratio_data_t));
    key_ratio_data_local_var->_library_owned = 1;
    key_ratio_data_local_var->name = name;
    key_ratio_data_local_var->company_value = company_value;
    key_ratio_data_local_var->sector_value = sector_value;
    return key_ratio_data_local_var;
}

key_ratio_data_t *key_ratio_data_create(
    char *name,
    char *company_value,
    char *sector_value
    ) {
    key_ratio_data_t *result = key_ratio_data_create_internal (
        name,
        company_value,
        sector_value
        );
    if (!result) {
    }
    return result;
}

void key_ratio_data_free(key_ratio_data_t *key_ratio_data) {
    if(NULL == key_ratio_data){
        return ;
    }
    if(key_ratio_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "key_ratio_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (key_ratio_data->name) {
        free(key_ratio_data->name);
        key_ratio_data->name = NULL;
    }
    if (key_ratio_data->company_value) {
        free(key_ratio_data->company_value);
        key_ratio_data->company_value = NULL;
    }
    if (key_ratio_data->sector_value) {
        free(key_ratio_data->sector_value);
        key_ratio_data->sector_value = NULL;
    }
    free(key_ratio_data);
}

cJSON *key_ratio_data_convertToJSON(key_ratio_data_t *key_ratio_data) {
    cJSON *item = cJSON_CreateObject();

    // key_ratio_data->name
    if(key_ratio_data->name) {
    if(cJSON_AddStringToObject(item, "name", key_ratio_data->name) == NULL) {
    goto fail; //String
    }
    }


    // key_ratio_data->company_value
    if(key_ratio_data->company_value) {
    if(cJSON_AddStringToObject(item, "company_value", key_ratio_data->company_value) == NULL) {
    goto fail; //String
    }
    }


    // key_ratio_data->sector_value
    if(key_ratio_data->sector_value) {
    if(cJSON_AddStringToObject(item, "sector_value", key_ratio_data->sector_value) == NULL) {
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

key_ratio_data_t *key_ratio_data_parseFromJSON(cJSON *key_ratio_dataJSON){

    key_ratio_data_t *key_ratio_data_local_var = NULL;

    char *name_local_str = NULL;

    char *company_value_local_str = NULL;

    char *sector_value_local_str = NULL;

    // key_ratio_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(key_ratio_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // key_ratio_data->company_value
    cJSON *company_value = cJSON_GetObjectItemCaseSensitive(key_ratio_dataJSON, "company_value");
    if (cJSON_IsNull(company_value)) {
        company_value = NULL;
    }
    if (company_value) { 
    if(!cJSON_IsString(company_value) && !cJSON_IsNull(company_value))
    {
    goto end; //String
    }
    }

    // key_ratio_data->sector_value
    cJSON *sector_value = cJSON_GetObjectItemCaseSensitive(key_ratio_dataJSON, "sector_value");
    if (cJSON_IsNull(sector_value)) {
        sector_value = NULL;
    }
    if (sector_value) { 
    if(!cJSON_IsString(sector_value) && !cJSON_IsNull(sector_value))
    {
    goto end; //String
    }
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (company_value && !cJSON_IsNull(company_value)) company_value_local_str = strdup(company_value->valuestring);
    if (sector_value && !cJSON_IsNull(sector_value)) sector_value_local_str = strdup(sector_value->valuestring);

    key_ratio_data_local_var = key_ratio_data_create_internal (
        name_local_str,
        company_value_local_str,
        sector_value_local_str
        );

    if (!key_ratio_data_local_var) {
        goto end;
    }

    return key_ratio_data_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (company_value_local_str) {
        free(company_value_local_str);
        company_value_local_str = NULL;
    }
    if (sector_value_local_str) {
        free(sector_value_local_str);
        sector_value_local_str = NULL;
    }
    return NULL;

}
