/*
 * gtt_order_data.h
 *
 * 
 */

#ifndef _gtt_order_data_H_
#define _gtt_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_order_data_t gtt_order_data_t;




typedef struct gtt_order_data_t {
    list_t *gtt_order_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_order_data_t;

gtt_order_data_t *gtt_order_data_create(
    list_t *gtt_order_ids
);

void gtt_order_data_free(gtt_order_data_t *gtt_order_data);

gtt_order_data_t *gtt_order_data_parseFromJSON(cJSON *gtt_order_dataJSON);

cJSON *gtt_order_data_convertToJSON(gtt_order_data_t *gtt_order_data);

#endif /* _gtt_order_data_H_ */

