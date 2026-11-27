/*
 * multi_order_v3_data.h
 *
 * 
 */

#ifndef _multi_order_v3_data_H_
#define _multi_order_v3_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_v3_data_t multi_order_v3_data_t;




typedef struct multi_order_v3_data_t {
    list_t *order_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_v3_data_t;

multi_order_v3_data_t *multi_order_v3_data_create(
    list_t *order_ids
);

void multi_order_v3_data_free(multi_order_v3_data_t *multi_order_v3_data);

multi_order_v3_data_t *multi_order_v3_data_parseFromJSON(cJSON *multi_order_v3_dataJSON);

cJSON *multi_order_v3_data_convertToJSON(multi_order_v3_data_t *multi_order_v3_data);

#endif /* _multi_order_v3_data_H_ */

