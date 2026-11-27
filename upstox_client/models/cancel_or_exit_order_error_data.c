#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_or_exit_order_error_data.h"



static cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_create_internal(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *instrument_key,
    char *order_id
    ) {
    cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_local_var = malloc(sizeof(cancel_or_exit_order_error_data_t));
    if (!cancel_or_exit_order_error_data_local_var) {
        return NULL;
    }
    memset(cancel_or_exit_order_error_data_local_var, 0, sizeof(cancel_or_exit_order_error_data_t));
    cancel_or_exit_order_error_data_local_var->_library_owned = 1;
    cancel_or_exit_order_error_data_local_var->message = message;
    cancel_or_exit_order_error_data_local_var->error_code = error_code;
    cancel_or_exit_order_error_data_local_var->property_path = property_path;
    cancel_or_exit_order_error_data_local_var->invalid_value = invalid_value;
    cancel_or_exit_order_error_data_local_var->instrument_key = instrument_key;
    cancel_or_exit_order_error_data_local_var->order_id = order_id;
    return cancel_or_exit_order_error_data_local_var;
}

cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *instrument_key,
    char *order_id
    ) {
    cancel_or_exit_order_error_data_t *result = cancel_or_exit_order_error_data_create_internal (
        message,
        error_code,
        property_path,
        invalid_value,
        instrument_key,
        order_id
        );
    if (!result) {
    }
    return result;
}

void cancel_or_exit_order_error_data_free(cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data) {
    if(NULL == cancel_or_exit_order_error_data){
        return ;
    }
    if(cancel_or_exit_order_error_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cancel_or_exit_order_error_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cancel_or_exit_order_error_data->message) {
        free(cancel_or_exit_order_error_data->message);
        cancel_or_exit_order_error_data->message = NULL;
    }
    if (cancel_or_exit_order_error_data->error_code) {
        free(cancel_or_exit_order_error_data->error_code);
        cancel_or_exit_order_error_data->error_code = NULL;
    }
    if (cancel_or_exit_order_error_data->property_path) {
        free(cancel_or_exit_order_error_data->property_path);
        cancel_or_exit_order_error_data->property_path = NULL;
    }
    if (cancel_or_exit_order_error_data->invalid_value) {
        object_free(cancel_or_exit_order_error_data->invalid_value);
        cancel_or_exit_order_error_data->invalid_value = NULL;
    }
    if (cancel_or_exit_order_error_data->instrument_key) {
        free(cancel_or_exit_order_error_data->instrument_key);
        cancel_or_exit_order_error_data->instrument_key = NULL;
    }
    if (cancel_or_exit_order_error_data->order_id) {
        free(cancel_or_exit_order_error_data->order_id);
        cancel_or_exit_order_error_data->order_id = NULL;
    }
    free(cancel_or_exit_order_error_data);
}

cJSON *cancel_or_exit_order_error_data_convertToJSON(cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data) {
    cJSON *item = cJSON_CreateObject();

    // cancel_or_exit_order_error_data->message
    if(cancel_or_exit_order_error_data->message) {
    if(cJSON_AddStringToObject(item, "message", cancel_or_exit_order_error_data->message) == NULL) {
    goto fail; //String
    }
    }


    // cancel_or_exit_order_error_data->error_code
    if(cancel_or_exit_order_error_data->error_code) {
    if(cJSON_AddStringToObject(item, "error_code", cancel_or_exit_order_error_data->error_code) == NULL) {
    goto fail; //String
    }
    }


    // cancel_or_exit_order_error_data->property_path
    if(cancel_or_exit_order_error_data->property_path) {
    if(cJSON_AddStringToObject(item, "property_path", cancel_or_exit_order_error_data->property_path) == NULL) {
    goto fail; //String
    }
    }


    // cancel_or_exit_order_error_data->invalid_value
    if(cancel_or_exit_order_error_data->invalid_value) {
    cJSON *invalid_value_object = object_convertToJSON(cancel_or_exit_order_error_data->invalid_value);
    if(invalid_value_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invalid_value", invalid_value_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cancel_or_exit_order_error_data->instrument_key
    if(cancel_or_exit_order_error_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", cancel_or_exit_order_error_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // cancel_or_exit_order_error_data->order_id
    if(cancel_or_exit_order_error_data->order_id) {
    if(cJSON_AddStringToObject(item, "order_id", cancel_or_exit_order_error_data->order_id) == NULL) {
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

cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_parseFromJSON(cJSON *cancel_or_exit_order_error_dataJSON){

    cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_local_var = NULL;

    char *message_local_str = NULL;

    char *error_code_local_str = NULL;

    char *property_path_local_str = NULL;

    char *instrument_key_local_str = NULL;

    char *order_id_local_str = NULL;

    // cancel_or_exit_order_error_data->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // cancel_or_exit_order_error_data->error_code
    cJSON *error_code = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "error_code");
    if (cJSON_IsNull(error_code)) {
        error_code = NULL;
    }
    if (error_code) { 
    if(!cJSON_IsString(error_code) && !cJSON_IsNull(error_code))
    {
    goto end; //String
    }
    }

    // cancel_or_exit_order_error_data->property_path
    cJSON *property_path = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "property_path");
    if (cJSON_IsNull(property_path)) {
        property_path = NULL;
    }
    if (property_path) { 
    if(!cJSON_IsString(property_path) && !cJSON_IsNull(property_path))
    {
    goto end; //String
    }
    }

    // cancel_or_exit_order_error_data->invalid_value
    cJSON *invalid_value = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "invalid_value");
    if (cJSON_IsNull(invalid_value)) {
        invalid_value = NULL;
    }
    object_t *invalid_value_local_object = NULL;
    if (invalid_value) { 
    invalid_value_local_object = object_parseFromJSON(invalid_value); //object
    }

    // cancel_or_exit_order_error_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // cancel_or_exit_order_error_data->order_id
    cJSON *order_id = cJSON_GetObjectItemCaseSensitive(cancel_or_exit_order_error_dataJSON, "order_id");
    if (cJSON_IsNull(order_id)) {
        order_id = NULL;
    }
    if (order_id) { 
    if(!cJSON_IsString(order_id) && !cJSON_IsNull(order_id))
    {
    goto end; //String
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (error_code && !cJSON_IsNull(error_code)) error_code_local_str = strdup(error_code->valuestring);
    if (property_path && !cJSON_IsNull(property_path)) property_path_local_str = strdup(property_path->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (order_id && !cJSON_IsNull(order_id)) order_id_local_str = strdup(order_id->valuestring);

    cancel_or_exit_order_error_data_local_var = cancel_or_exit_order_error_data_create_internal (
        message_local_str,
        error_code_local_str,
        property_path_local_str,
        invalid_value ? invalid_value_local_object : NULL,
        instrument_key_local_str,
        order_id_local_str
        );

    if (!cancel_or_exit_order_error_data_local_var) {
        goto end;
    }

    return cancel_or_exit_order_error_data_local_var;
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
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (order_id_local_str) {
        free(order_id_local_str);
        order_id_local_str = NULL;
    }
    return NULL;

}
