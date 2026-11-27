/*
 * pagination.h
 *
 * 
 */

#ifndef _pagination_H_
#define _pagination_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pagination_t pagination_t;




typedef struct pagination_t {
    int *page_number; //numeric
    int *total_pages; //numeric
    int *records; //numeric
    int *total_records; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pagination_t;

pagination_t *pagination_create(
    int *page_number,
    int *total_pages,
    int *records,
    int *total_records
);

void pagination_free(pagination_t *pagination);

pagination_t *pagination_parseFromJSON(cJSON *paginationJSON);

cJSON *pagination_convertToJSON(pagination_t *pagination);

#endif /* _pagination_H_ */

