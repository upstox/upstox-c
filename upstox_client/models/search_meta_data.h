/*
 * search_meta_data.h
 *
 * 
 */

#ifndef _search_meta_data_H_
#define _search_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_meta_data_t search_meta_data_t;

#include "pagination.h"



typedef struct search_meta_data_t {
    struct pagination_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} search_meta_data_t;

search_meta_data_t *search_meta_data_create(
    pagination_t *page
);

void search_meta_data_free(search_meta_data_t *search_meta_data);

search_meta_data_t *search_meta_data_parseFromJSON(cJSON *search_meta_dataJSON);

cJSON *search_meta_data_convertToJSON(search_meta_data_t *search_meta_data);

#endif /* _search_meta_data_H_ */

