/*
 * ipo_cancel_data.h
 *
 * 
 */

#ifndef _ipo_cancel_data_H_
#define _ipo_cancel_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_cancel_data_t ipo_cancel_data_t;




typedef struct ipo_cancel_data_t {
    char *order_id; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_cancel_data_t;

ipo_cancel_data_t *ipo_cancel_data_create(
    char *order_id,
    char *status
);

void ipo_cancel_data_free(ipo_cancel_data_t *ipo_cancel_data);

ipo_cancel_data_t *ipo_cancel_data_parseFromJSON(cJSON *ipo_cancel_dataJSON);

cJSON *ipo_cancel_data_convertToJSON(ipo_cancel_data_t *ipo_cancel_data);

#endif /* _ipo_cancel_data_H_ */

