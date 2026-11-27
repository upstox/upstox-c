/*
 * multi_order_error.h
 *
 * 
 */

#ifndef _multi_order_error_H_
#define _multi_order_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_error_t multi_order_error_t;

#include "object.h"



typedef struct multi_order_error_t {
    char *message; // string
    char *error_code; // string
    char *property_path; // string
    object_t *invalid_value; //object
    char *correlation_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_error_t;

multi_order_error_t *multi_order_error_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *correlation_id
);

void multi_order_error_free(multi_order_error_t *multi_order_error);

multi_order_error_t *multi_order_error_parseFromJSON(cJSON *multi_order_errorJSON);

cJSON *multi_order_error_convertToJSON(multi_order_error_t *multi_order_error);

#endif /* _multi_order_error_H_ */

