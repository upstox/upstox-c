/*
 * ipo_meta_data.h
 *
 * 
 */

#ifndef _ipo_meta_data_H_
#define _ipo_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_meta_data_t ipo_meta_data_t;

#include "pagination.h"



typedef struct ipo_meta_data_t {
    struct pagination_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_meta_data_t;

ipo_meta_data_t *ipo_meta_data_create(
    pagination_t *page
);

void ipo_meta_data_free(ipo_meta_data_t *ipo_meta_data);

ipo_meta_data_t *ipo_meta_data_parseFromJSON(cJSON *ipo_meta_dataJSON);

cJSON *ipo_meta_data_convertToJSON(ipo_meta_data_t *ipo_meta_data);

#endif /* _ipo_meta_data_H_ */

