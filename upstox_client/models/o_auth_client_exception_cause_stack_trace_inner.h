/*
 * o_auth_client_exception_cause_stack_trace_inner.h
 *
 * 
 */

#ifndef _o_auth_client_exception_cause_stack_trace_inner_H_
#define _o_auth_client_exception_cause_stack_trace_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_client_exception_cause_stack_trace_inner_t o_auth_client_exception_cause_stack_trace_inner_t;




typedef struct o_auth_client_exception_cause_stack_trace_inner_t {
    char *class_loader_name; // string
    char *module_name; // string
    char *module_version; // string
    char *method_name; // string
    char *file_name; // string
    int *line_number; //numeric
    char *class_name; // string
    int *native_method; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_client_exception_cause_stack_trace_inner_t;

o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_create(
    char *class_loader_name,
    char *module_name,
    char *module_version,
    char *method_name,
    char *file_name,
    int *line_number,
    char *class_name,
    int *native_method
);

void o_auth_client_exception_cause_stack_trace_inner_free(o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner);

o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner_parseFromJSON(cJSON *o_auth_client_exception_cause_stack_trace_innerJSON);

cJSON *o_auth_client_exception_cause_stack_trace_inner_convertToJSON(o_auth_client_exception_cause_stack_trace_inner_t *o_auth_client_exception_cause_stack_trace_inner);

#endif /* _o_auth_client_exception_cause_stack_trace_inner_H_ */

