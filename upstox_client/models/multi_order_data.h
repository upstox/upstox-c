/*
 * multi_order_data.h
 *
 * 
 */

#ifndef _multi_order_data_H_
#define _multi_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_data_t multi_order_data_t;




typedef struct multi_order_data_t {
    char *correlation_id; // string
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_data_t;

multi_order_data_t *multi_order_data_create(
    char *correlation_id,
    char *order_id
);

void multi_order_data_free(multi_order_data_t *multi_order_data);

multi_order_data_t *multi_order_data_parseFromJSON(cJSON *multi_order_dataJSON);

cJSON *multi_order_data_convertToJSON(multi_order_data_t *multi_order_data);

#endif /* _multi_order_data_H_ */

