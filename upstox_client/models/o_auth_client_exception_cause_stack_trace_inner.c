#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "o_auth_client_exception_cause_stack_trace_inner.h"



static o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_create_internal(
    char *class_loader_name,
    char *module_name,
    char *module_version,
    char *method_name,
    char *file_name,
    int *line_number,
    char *class_name,
    int *native_method
    ) {
    o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_local_var = malloc(sizeof(o_auth_client_exception_cause_stack_trace_inner_t));
    if (!o_auth_client_exception_cause_stack_trace_inner_local_var) {
        return NULL;
    }
    memset(o_auth_client_exception_cause_stack_trace_inner_local_var, 0, sizeof(o_auth_client_exception_cause_stack_trace_inner_t));
    o_auth_client_exception_cause_stack_trace_inner_local_var->_library_owned = 1;
    o_auth_client_exception_cause_stack_trace_inner_local_var->class_loader_name = class_loader_name;
    o_auth_client_exception_cause_stack_trace_inner_local_var->module_name = module_name;
    o_auth_client_exception_cause_stack_trace_inner_local_var->module_version = module_version;
    o_auth_client_exception_cause_stack_trace_inner_local_var->method_name = method_name;
    o_auth_client_exception_cause_stack_trace_inner_local_var->file_name = file_name;
    o_auth_client_exception_cause_stack_trace_inner_local_var->line_number = line_number;
    o_auth_client_exception_cause_stack_trace_inner_local_var->class_name = class_name;
    o_auth_client_exception_cause_stack_trace_inner_local_var->native_method = native_method;
    return o_auth_client_exception_cause_stack_trace_inner_local_var;
}

o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_create(
    char *class_loader_name,
    char *module_name,
    char *module_version,
    char *method_name,
    char *file_name,
    int *line_number,
    char *class_name,
    int *native_method
    ) {
    int *line_number_copy = NULL;
    if (line_number) {
        line_number_copy = malloc(sizeof(int));
        if (line_number_copy) *line_number_copy = *line_number;
    }
    int *native_method_copy = NULL;
    if (native_method) {
        native_method_copy = malloc(sizeof(int));
        if (native_method_copy) *native_method_copy = *native_method;
    }
    o_auth_client_exception_cause_stack_trace_inner_t *result = o_auth_client_exception_cause_stack_trace_inner_create_internal (
        class_loader_name,
        module_name,
        module_version,
        method_name,
        file_name,
        line_number_copy,
        class_name,
        native_method_copy
        );
    if (!result) {
        free(line_number_copy);
        free(native_method_copy);
    }
    return result;
}

void o_auth_client_exception_cause_stack_trace_inner_free(o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner) {
    if(NULL == o_auth_client_exception_cause_stack_trace_inner){
        return ;
    }
    if(o_auth_client_exception_cause_stack_trace_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "o_auth_client_exception_cause_stack_trace_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (o_auth_client_exception_cause_stack_trace_inner->class_loader_name) {
        free(o_auth_client_exception_cause_stack_trace_inner->class_loader_name);
        o_auth_client_exception_cause_stack_trace_inner->class_loader_name = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->module_name) {
        free(o_auth_client_exception_cause_stack_trace_inner->module_name);
        o_auth_client_exception_cause_stack_trace_inner->module_name = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->module_version) {
        free(o_auth_client_exception_cause_stack_trace_inner->module_version);
        o_auth_client_exception_cause_stack_trace_inner->module_version = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->method_name) {
        free(o_auth_client_exception_cause_stack_trace_inner->method_name);
        o_auth_client_exception_cause_stack_trace_inner->method_name = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->file_name) {
        free(o_auth_client_exception_cause_stack_trace_inner->file_name);
        o_auth_client_exception_cause_stack_trace_inner->file_name = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->line_number) {
        free(o_auth_client_exception_cause_stack_trace_inner->line_number);
        o_auth_client_exception_cause_stack_trace_inner->line_number = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->class_name) {
        free(o_auth_client_exception_cause_stack_trace_inner->class_name);
        o_auth_client_exception_cause_stack_trace_inner->class_name = NULL;
    }
    if (o_auth_client_exception_cause_stack_trace_inner->native_method) {
        free(o_auth_client_exception_cause_stack_trace_inner->native_method);
        o_auth_client_exception_cause_stack_trace_inner->native_method = NULL;
    }
    free(o_auth_client_exception_cause_stack_trace_inner);
}

cJSON *o_auth_client_exception_cause_stack_trace_inner_convertToJSON(o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner) {
    cJSON *item = cJSON_CreateObject();

    // o_auth_client_exception_cause_stack_trace_inner->class_loader_name
    if(o_auth_client_exception_cause_stack_trace_inner->class_loader_name) {
    if(cJSON_AddStringToObject(item, "classLoaderName", o_auth_client_exception_cause_stack_trace_inner->class_loader_name) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->module_name
    if(o_auth_client_exception_cause_stack_trace_inner->module_name) {
    if(cJSON_AddStringToObject(item, "moduleName", o_auth_client_exception_cause_stack_trace_inner->module_name) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->module_version
    if(o_auth_client_exception_cause_stack_trace_inner->module_version) {
    if(cJSON_AddStringToObject(item, "moduleVersion", o_auth_client_exception_cause_stack_trace_inner->module_version) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->method_name
    if(o_auth_client_exception_cause_stack_trace_inner->method_name) {
    if(cJSON_AddStringToObject(item, "methodName", o_auth_client_exception_cause_stack_trace_inner->method_name) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->file_name
    if(o_auth_client_exception_cause_stack_trace_inner->file_name) {
    if(cJSON_AddStringToObject(item, "fileName", o_auth_client_exception_cause_stack_trace_inner->file_name) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->line_number
    if(o_auth_client_exception_cause_stack_trace_inner->line_number) {
    if(cJSON_AddNumberToObject(item, "lineNumber", *o_auth_client_exception_cause_stack_trace_inner->line_number) == NULL) {
    goto fail; //Numeric
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->class_name
    if(o_auth_client_exception_cause_stack_trace_inner->class_name) {
    if(cJSON_AddStringToObject(item, "className", o_auth_client_exception_cause_stack_trace_inner->class_name) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception_cause_stack_trace_inner->native_method
    if(o_auth_client_exception_cause_stack_trace_inner->native_method) {
    if(cJSON_AddBoolToObject(item, "nativeMethod", *o_auth_client_exception_cause_stack_trace_inner->native_method) == NULL) {
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

o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_parseFromJSON(cJSON *o_auth_client_exception_cause_stack_trace_innerJSON){

    o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_local_var = NULL;

    char *class_loader_name_local_str = NULL;

    char *module_name_local_str = NULL;

    char *module_version_local_str = NULL;

    char *method_name_local_str = NULL;

    char *file_name_local_str = NULL;

    // define the local variable for o_auth_client_exception_cause_stack_trace_inner->line_number
    int *line_number_local_var = NULL;

    char *class_name_local_str = NULL;

    // define the local variable for o_auth_client_exception_cause_stack_trace_inner->native_method
    int *native_method_local_var = NULL;

    // o_auth_client_exception_cause_stack_trace_inner->class_loader_name
    cJSON *class_loader_name = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "classLoaderName");
    if (cJSON_IsNull(class_loader_name)) {
        class_loader_name = NULL;
    }
    if (class_loader_name) { 
    if(!cJSON_IsString(class_loader_name) && !cJSON_IsNull(class_loader_name))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->module_name
    cJSON *module_name = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "moduleName");
    if (cJSON_IsNull(module_name)) {
        module_name = NULL;
    }
    if (module_name) { 
    if(!cJSON_IsString(module_name) && !cJSON_IsNull(module_name))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->module_version
    cJSON *module_version = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "moduleVersion");
    if (cJSON_IsNull(module_version)) {
        module_version = NULL;
    }
    if (module_version) { 
    if(!cJSON_IsString(module_version) && !cJSON_IsNull(module_version))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->method_name
    cJSON *method_name = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "methodName");
    if (cJSON_IsNull(method_name)) {
        method_name = NULL;
    }
    if (method_name) { 
    if(!cJSON_IsString(method_name) && !cJSON_IsNull(method_name))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->file_name
    cJSON *file_name = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "fileName");
    if (cJSON_IsNull(file_name)) {
        file_name = NULL;
    }
    if (file_name) { 
    if(!cJSON_IsString(file_name) && !cJSON_IsNull(file_name))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->line_number
    cJSON *line_number = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "lineNumber");
    if (cJSON_IsNull(line_number)) {
        line_number = NULL;
    }
    if (line_number) { 
    if(!cJSON_IsNumber(line_number))
    {
    goto end; //Numeric
    }
    line_number_local_var = malloc(sizeof(int));
    if(!line_number_local_var)
    {
        goto end;
    }
    *line_number_local_var = line_number->valuedouble;
    }

    // o_auth_client_exception_cause_stack_trace_inner->class_name
    cJSON *class_name = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "className");
    if (cJSON_IsNull(class_name)) {
        class_name = NULL;
    }
    if (class_name) { 
    if(!cJSON_IsString(class_name) && !cJSON_IsNull(class_name))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception_cause_stack_trace_inner->native_method
    cJSON *native_method = cJSON_GetObjectItemCaseSensitive(o_auth_client_exception_cause_stack_trace_innerJSON, "nativeMethod");
    if (cJSON_IsNull(native_method)) {
        native_method = NULL;
    }
    if (native_method) { 
    if(!cJSON_IsBool(native_method))
    {
    goto end; //Bool
    }
    native_method_local_var = malloc(sizeof(int));
    if(!native_method_local_var)
    {
        goto end;
    }
    *native_method_local_var = native_method->valueint;
    }


    if (class_loader_name && !cJSON_IsNull(class_loader_name)) class_loader_name_local_str = strdup(class_loader_name->valuestring);
    if (module_name && !cJSON_IsNull(module_name)) module_name_local_str = strdup(module_name->valuestring);
    if (module_version && !cJSON_IsNull(module_version)) module_version_local_str = strdup(module_version->valuestring);
    if (method_name && !cJSON_IsNull(method_name)) method_name_local_str = strdup(method_name->valuestring);
    if (file_name && !cJSON_IsNull(file_name)) file_name_local_str = strdup(file_name->valuestring);
    if (class_name && !cJSON_IsNull(class_name)) class_name_local_str = strdup(class_name->valuestring);

    o_auth_client_exception_cause_stack_trace_inner_local_var = o_auth_client_exception_cause_stack_trace_inner_create_internal (
        class_loader_name_local_str,
        module_name_local_str,
        module_version_local_str,
        method_name_local_str,
        file_name_local_str,
        line_number_local_var,
        class_name_local_str,
        native_method_local_var
        );

    if (!o_auth_client_exception_cause_stack_trace_inner_local_var) {
        goto end;
    }

    return o_auth_client_exception_cause_stack_trace_inner_local_var;
end:
    if (class_loader_name_local_str) {
        free(class_loader_name_local_str);
        class_loader_name_local_str = NULL;
    }
    if (module_name_local_str) {
        free(module_name_local_str);
        module_name_local_str = NULL;
    }
    if (module_version_local_str) {
        free(module_version_local_str);
        module_version_local_str = NULL;
    }
    if (method_name_local_str) {
        free(method_name_local_str);
        method_name_local_str = NULL;
    }
    if (file_name_local_str) {
        free(file_name_local_str);
        file_name_local_str = NULL;
    }
    if (line_number_local_var) {
        free(line_number_local_var);
        line_number_local_var = NULL;
    }
    if (class_name_local_str) {
        free(class_name_local_str);
        class_name_local_str = NULL;
    }
    if (native_method_local_var) {
        free(native_method_local_var);
        native_method_local_var = NULL;
    }
    return NULL;

}
