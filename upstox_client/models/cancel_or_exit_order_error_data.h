/*
 * cancel_or_exit_order_error_data.h
 *
 * 
 */

#ifndef _cancel_or_exit_order_error_data_H_
#define _cancel_or_exit_order_error_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_or_exit_order_error_data_t cancel_or_exit_order_error_data_t;

#include "object.h"



typedef struct cancel_or_exit_order_error_data_t {
    char *message; // string
    char *error_code; // string
    char *property_path; // string
    object_t *invalid_value; //object
    char *instrument_key; // string
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_or_exit_order_error_data_t;

cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_create(
    char *message,
    char *error_code,
    char *property_path,
    object_t *invalid_value,
    char *instrument_key,
    char *order_id
);

void cancel_or_exit_order_error_data_free(cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data);

cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data_parseFromJSON(cJSON *cancel_or_exit_order_error_dataJSON);

cJSON *cancel_or_exit_order_error_data_convertToJSON(cancel_or_exit_order_error_data_t *cancel_or_exit_order_error_data);

#endif /* _cancel_or_exit_order_error_data_H_ */

