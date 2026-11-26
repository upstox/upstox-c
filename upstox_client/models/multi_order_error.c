#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_order_error.h"



static multi_order_error_t *multi_order_error_create_internal(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *correlation_id
    ) {
    multi_order_error_t *multi_order_error_local_var = malloc(sizeof(multi_order_error_t));
    if (!multi_order_error_local_var) {
        return NULL;
    }
    memset(multi_order_error_local_var, 0, sizeof(multi_order_error_t));
    multi_order_error_local_var->_library_owned = 1;
    multi_order_error_local_var->message = message;
    multi_order_error_local_var->error_code = error_code;
    multi_order_error_local_var->property_path = property_path;
    multi_order_error_local_var->invalid_value = invalid_value;
    multi_order_error_local_var->correlation_id = correlation_id;
    return multi_order_error_local_var;
}

multi_order_error_t *multi_order_error_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *correlation_id
    ) {
    multi_order_error_t *result = multi_order_error_create_internal (
        message,
        error_code,
        property_path,
        invalid_value,
        correlation_id
        );
    if (!result) {
    }
    return result;
}

void multi_order_error_free(multi_order_error_t *multi_order_error) {
    if(NULL == multi_order_error){
        return ;
    }
    if(multi_order_error->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "multi_order_error_free");
        return ;
    }
    listEntry_t *listEntry;
    if (multi_order_error->message) {
        free(multi_order_error->message);
        multi_order_error->message = NULL;
    }
    if (multi_order_error->error_code) {
        free(multi_order_error->error_code);
        multi_order_error->error_code = NULL;
    }
    if (multi_order_error->property_path) {
        free(multi_order_error->property_path);
        multi_order_error->property_path = NULL;
    }
    if (multi_order_error->invalid_value) {
        object_free(multi_order_error->invalid_value);
        multi_order_error->invalid_value = NULL;
    }
    if (multi_order_error->correlation_id) {
        free(multi_order_error->correlation_id);
        multi_order_error->correlation_id = NULL;
    }
    free(multi_order_error);
}

cJSON *multi_order_error_convertToJSON(multi_order_error_t *multi_order_error) {
    cJSON *item = cJSON_CreateObject();

    // multi_order_error->message
    if(multi_order_error->message) {
    if(cJSON_AddStringToObject(item, "message", multi_order_error->message) == NULL) {
    goto fail; //String
    }
    }


    // multi_order_error->error_code
    if(multi_order_error->error_code) {
    if(cJSON_AddStringToObject(item, "error_code", multi_order_error->error_code) == NULL) {
    goto fail; //String
    }
    }


    // multi_order_error->property_path
    if(multi_order_error->property_path) {
    if(cJSON_AddStringToObject(item, "property_path", multi_order_error->property_path) == NULL) {
    goto fail; //String
    }
    }


    // multi_order_error->invalid_value
    if(multi_order_error->invalid_value) {
    cJSON *invalid_value_object = object_convertToJSON(multi_order_error->invalid_value);
    if(invalid_value_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invalid_value", invalid_value_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // multi_order_error->correlation_id
    if(multi_order_error->correlation_id) {
    if(cJSON_AddStringToObject(item, "correlation_id", multi_order_error->correlation_id) == NULL) {
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

multi_order_error_t *multi_order_error_parseFromJSON(cJSON *multi_order_errorJSON){

    multi_order_error_t *multi_order_error_local_var = NULL;

    char *message_local_str = NULL;

    char *error_code_local_str = NULL;

    char *property_path_local_str = NULL;

    char *correlation_id_local_str = NULL;

    // multi_order_error->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(multi_order_errorJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // multi_order_error->error_code
    cJSON *error_code = cJSON_GetObjectItemCaseSensitive(multi_order_errorJSON, "error_code");
    if (cJSON_IsNull(error_code)) {
        error_code = NULL;
    }
    if (error_code) { 
    if(!cJSON_IsString(error_code) && !cJSON_IsNull(error_code))
    {
    goto end; //String
    }
    }

    // multi_order_error->property_path
    cJSON *property_path = cJSON_GetObjectItemCaseSensitive(multi_order_errorJSON, "property_path");
    if (cJSON_IsNull(property_path)) {
        property_path = NULL;
    }
    if (property_path) { 
    if(!cJSON_IsString(property_path) && !cJSON_IsNull(property_path))
    {
    goto end; //String
    }
    }

    // multi_order_error->invalid_value
    cJSON *invalid_value = cJSON_GetObjectItemCaseSensitive(multi_order_errorJSON, "invalid_value");
    if (cJSON_IsNull(invalid_value)) {
        invalid_value = NULL;
    }
    object_t *invalid_value_local_object = NULL;
    if (invalid_value) { 
    invalid_value_local_object = object_parseFromJSON(invalid_value); //object
    }

    // multi_order_error->correlation_id
    cJSON *correlation_id = cJSON_GetObjectItemCaseSensitive(multi_order_errorJSON, "correlation_id");
    if (cJSON_IsNull(correlation_id)) {
        correlation_id = NULL;
    }
    if (correlation_id) { 
    if(!cJSON_IsString(correlation_id) && !cJSON_IsNull(correlation_id))
    {
    goto end; //String
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (error_code && !cJSON_IsNull(error_code)) error_code_local_str = strdup(error_code->valuestring);
    if (property_path && !cJSON_IsNull(property_path)) property_path_local_str = strdup(property_path->valuestring);
    if (correlation_id && !cJSON_IsNull(correlation_id)) correlation_id_local_str = strdup(correlation_id->valuestring);

    multi_order_error_local_var = multi_order_error_create_internal (
        message_local_str,
        error_code_local_str,
        property_path_local_str,
        invalid_value ? invalid_value_local_object : NULL,
        correlation_id_local_str
        );

    if (!multi_order_error_local_var) {
        goto end;
    }

    return multi_order_error_local_var;
end:
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (error_code_local_str) {
        free(error_code_local_str);
        error_code_local_str = NULL;
    }
    if (property_path_local_str) {
        free(property_path_local_str);
        property_path_local_str = NULL;
    }
    if (correlation_id_local_str) {
        free(correlation_id_local_str);
        correlation_id_local_str = NULL;
    }
    return NULL;

}
