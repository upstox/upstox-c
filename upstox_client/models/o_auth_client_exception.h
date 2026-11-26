/*
 * o_auth_client_exception.h
 *
 * 
 */

#ifndef _o_auth_client_exception_H_
#define _o_auth_client_exception_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_client_exception_t o_auth_client_exception_t;

#include "o_auth_client_exception_cause.h"
#include "o_auth_client_exception_cause_stack_trace_inner.h"



typedef struct o_auth_client_exception_t {
    struct o_auth_client_exception_cause_t *cause; //model
    list_t *stack_trace; //nonprimitive container
    char *message; // string
    list_t *suppressed; //nonprimitive container
    char *localized_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_client_exception_t;

o_auth_client_exception_t *o_auth_client_exception_create(
    o_auth_client_exception_cause_t *cause,
    list_t *stack_trace,
    char *message,
    list_t *suppressed,
    char *localized_message
);

void o_auth_client_exception_free(o_auth_client_exception_t *o_auth_client_exception);

o_auth_client_exception_t *o_auth_client_exception_parseFromJSON(cJSON *o_auth_client_exceptionJSON);

cJSON *o_auth_client_exception_convertToJSON(o_auth_client_exception_t *o_auth_client_exception);

#endif /* _o_auth_client_exception_H_ */

