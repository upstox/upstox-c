/*
 * o_auth_client_exception_cause.h
 *
 * 
 */

#ifndef _o_auth_client_exception_cause_H_
#define _o_auth_client_exception_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct o_auth_client_exception_cause_t o_auth_client_exception_cause_t;

#include "o_auth_client_exception_cause_stack_trace_inner.h"



typedef struct o_auth_client_exception_cause_t {
    list_t *stack_trace; //nonprimitive container
    char *message; // string
    char *localized_message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} o_auth_client_exception_cause_t;

o_auth_client_exception_cause_t *o_auth_client_exception_cause_create(
    list_t *stack_trace,
    char *message,
    char *localized_message
);

void o_auth_client_exception_cause_free(o_auth_client_exception_cause_t *o_auth_client_exception_cause);

o_auth_client_exception_cause_t *o_auth_client_exception_cause_parseFromJSON(cJSON *o_auth_client_exception_causeJSON);

cJSON *o_auth_client_exception_cause_convertToJSON(o_auth_client_exception_cause_t *o_auth_client_exception_cause);

#endif /* _o_auth_client_exception_cause_H_ */

