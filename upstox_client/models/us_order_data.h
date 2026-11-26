/*
 * us_order_data.h
 *
 * 
 */

#ifndef _us_order_data_H_
#define _us_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_data_t us_order_data_t;




typedef struct us_order_data_t {
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_data_t;

us_order_data_t *us_order_data_create(
    char *order_id
);

void us_order_data_free(us_order_data_t *us_order_data);

us_order_data_t *us_order_data_parseFromJSON(cJSON *us_order_dataJSON);

cJSON *us_order_data_convertToJSON(us_order_data_t *us_order_data);

#endif /* _us_order_data_H_ */

