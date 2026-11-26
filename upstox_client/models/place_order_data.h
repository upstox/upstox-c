/*
 * place_order_data.h
 *
 * 
 */

#ifndef _place_order_data_H_
#define _place_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_order_data_t place_order_data_t;




typedef struct place_order_data_t {
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} place_order_data_t;

place_order_data_t *place_order_data_create(
    char *order_id
);

void place_order_data_free(place_order_data_t *place_order_data);

place_order_data_t *place_order_data_parseFromJSON(cJSON *place_order_dataJSON);

cJSON *place_order_data_convertToJSON(place_order_data_t *place_order_data);

#endif /* _place_order_data_H_ */

