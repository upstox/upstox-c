/*
 * key_ratio_data.h
 *
 * 
 */

#ifndef _key_ratio_data_H_
#define _key_ratio_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct key_ratio_data_t key_ratio_data_t;




typedef struct key_ratio_data_t {
    char *name; // string
    char *company_value; // string
    char *sector_value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} key_ratio_data_t;

key_ratio_data_t *key_ratio_data_create(
    char *name,
    char *company_value,
    char *sector_value
);

void key_ratio_data_free(key_ratio_data_t *key_ratio_data);

key_ratio_data_t *key_ratio_data_parseFromJSON(cJSON *key_ratio_dataJSON);

cJSON *key_ratio_data_convertToJSON(key_ratio_data_t *key_ratio_data);

#endif /* _key_ratio_data_H_ */

