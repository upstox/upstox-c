/*
 * cancel_or_exit_multi_order_data.h
 *
 * 
 */

#ifndef _cancel_or_exit_multi_order_data_H_
#define _cancel_or_exit_multi_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_or_exit_multi_order_data_t cancel_or_exit_multi_order_data_t;




typedef struct cancel_or_exit_multi_order_data_t {
    list_t *order_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_or_exit_multi_order_data_t;

cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_create(
    list_t *order_ids
);

void cancel_or_exit_multi_order_data_free(cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data);

cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data_parseFromJSON(cJSON *cancel_or_exit_multi_order_dataJSON);

cJSON *cancel_or_exit_multi_order_data_convertToJSON(cancel_or_exit_multi_order_data_t *cancel_or_exit_multi_order_data);

#endif /* _cancel_or_exit_multi_order_data_H_ */

