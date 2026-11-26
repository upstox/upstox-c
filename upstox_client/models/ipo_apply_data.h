/*
 * ipo_apply_data.h
 *
 * 
 */

#ifndef _ipo_apply_data_H_
#define _ipo_apply_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_apply_data_t ipo_apply_data_t;




typedef struct ipo_apply_data_t {
    char *order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_apply_data_t;

ipo_apply_data_t *ipo_apply_data_create(
    char *order_id
);

void ipo_apply_data_free(ipo_apply_data_t *ipo_apply_data);

ipo_apply_data_t *ipo_apply_data_parseFromJSON(cJSON *ipo_apply_dataJSON);

cJSON *ipo_apply_data_convertToJSON(ipo_apply_data_t *ipo_apply_data);

#endif /* _ipo_apply_data_H_ */

