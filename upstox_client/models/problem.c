#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "problem.h"



static problem_t *problem_create_internal(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value
    ) {
    problem_t *problem_local_var = malloc(sizeof(problem_t));
    if (!problem_local_var) {
        return NULL;
    }
    memset(problem_local_var, 0, sizeof(problem_t));
    problem_local_var->_library_owned = 1;
    problem_local_var->message = message;
    problem_local_var->error_code = error_code;
    problem_local_var->property_path = property_path;
    problem_local_var->invalid_value = invalid_value;
    return problem_local_var;
}

problem_t *problem_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value
    ) {
    problem_t *result = problem_create_internal (
        message,
        error_code,
        property_path,
        invalid_value
        );
    if (!result) {
    }
    return result;
}

void problem_free(problem_t *problem) {
    if(NULL == problem){
        return ;
    }
    if(problem->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "problem_free");
        return ;
    }
    listEntry_t *listEntry;
    if (problem->message) {
        free(problem->message);
        problem->message = NULL;
    }
    if (problem->error_code) {
        free(problem->error_code);
        problem->error_code = NULL;
    }
    if (problem->property_path) {
        free(problem->property_path);
        problem->property_path = NULL;
    }
    if (problem->invalid_value) {
        object_free(problem->invalid_value);
        problem->invalid_value = NULL;
    }
    free(problem);
}

cJSON *problem_convertToJSON(problem_t *problem) {
    cJSON *item = cJSON_CreateObject();

    // problem->message
    if(problem->message) {
    if(cJSON_AddStringToObject(item, "message", problem->message) == NULL) {
    goto fail; //String
    }
    }


    // problem->error_code
    if(problem->error_code) {
    if(cJSON_AddStringToObject(item, "error_code", problem->error_code) == NULL) {
    goto fail; //String
    }
    }


    // problem->property_path
    if(problem->property_path) {
    if(cJSON_AddStringToObject(item, "property_path", problem->property_path) == NULL) {
    goto fail; //String
    }
    }


    // problem->invalid_value
    if(problem->invalid_value) {
    cJSON *invalid_value_object = object_convertToJSON(problem->invalid_value);
    if(invalid_value_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "invalid_value", invalid_value_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

problem_t *problem_parseFromJSON(cJSON *problemJSON){

    problem_t *problem_local_var = NULL;

    char *message_local_str = NULL;

    char *error_code_local_str = NULL;

    char *property_path_local_str = NULL;

    // problem->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(problemJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // problem->error_code
    cJSON *error_code = cJSON_GetObjectItemCaseSensitive(problemJSON, "error_code");
    if (cJSON_IsNull(error_code)) {
        error_code = NULL;
    }
    if (error_code) { 
    if(!cJSON_IsString(error_code) && !cJSON_IsNull(error_code))
    {
    goto end; //String
    }
    }

    // problem->property_path
    cJSON *property_path = cJSON_GetObjectItemCaseSensitive(problemJSON, "property_path");
    if (cJSON_IsNull(property_path)) {
        property_path = NULL;
    }
    if (property_path) { 
    if(!cJSON_IsString(property_path) && !cJSON_IsNull(property_path))
    {
    goto end; //String
    }
    }

    // problem->invalid_value
    cJSON *invalid_value = cJSON_GetObjectItemCaseSensitive(problemJSON, "invalid_value");
    if (cJSON_IsNull(invalid_value)) {
        invalid_value = NULL;
    }
    object_t *invalid_value_local_object = NULL;
    if (invalid_value) { 
    invalid_value_local_object = object_parseFromJSON(invalid_value); //object
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (error_code && !cJSON_IsNull(error_code)) error_code_local_str = strdup(error_code->valuestring);
    if (property_path && !cJSON_IsNull(property_path)) property_path_local_str = strdup(property_path->valuestring);

    problem_local_var = problem_create_internal (
        message_local_str,
        error_code_local_str,
        property_path_local_str,
        invalid_value ? invalid_value_local_object : NULL
        );

    if (!problem_local_var) {
        goto end;
    }

    return problem_local_var;
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
    return NULL;

}
