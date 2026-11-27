/*
 * cancel_order_data.h
 *
 * 
 */

#ifndef _cancel_order_data_H_
#define _cancel_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_order_data_t cancel_order_data_t;




typedef struct cancel_order_data_t {
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_order_data_t;

cancel_order_data_t *cancel_order_data_create(
    char *order_id
);

void cancel_order_data_free(cancel_order_data_t *cancel_order_data);

cancel_order_data_t *cancel_order_data_parseFromJSON(cJSON *cancel_order_dataJSON);

cJSON *cancel_order_data_convertToJSON(cancel_order_data_t *cancel_order_data);

#endif /* _cancel_order_data_H_ */

