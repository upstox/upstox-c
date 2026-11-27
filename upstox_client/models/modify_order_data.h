/*
 * modify_order_data.h
 *
 * 
 */

#ifndef _modify_order_data_H_
#define _modify_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct modify_order_data_t modify_order_data_t;




typedef struct modify_order_data_t {
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} modify_order_data_t;

modify_order_data_t *modify_order_data_create(
    char *order_id
);

void modify_order_data_free(modify_order_data_t *modify_order_data);

modify_order_data_t *modify_order_data_parseFromJSON(cJSON *modify_order_dataJSON);

cJSON *modify_order_data_convertToJSON(modify_order_data_t *modify_order_data);

#endif /* _modify_order_data_H_ */

