/*
 * convert_position_data.h
 *
 * 
 */

#ifndef _convert_position_data_H_
#define _convert_position_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_position_data_t convert_position_data_t;




typedef struct convert_position_data_t {
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} convert_position_data_t;

convert_position_data_t *convert_position_data_create(
    char *status
);

void convert_position_data_free(convert_position_data_t *convert_position_data);

convert_position_data_t *convert_position_data_parseFromJSON(cJSON *convert_position_dataJSON);

cJSON *convert_position_data_convertToJSON(convert_position_data_t *convert_position_data);

#endif /* _convert_position_data_H_ */

