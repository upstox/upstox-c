/*
 * exchange_timing_data.h
 *
 * 
 */

#ifndef _exchange_timing_data_H_
#define _exchange_timing_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct exchange_timing_data_t exchange_timing_data_t;




typedef struct exchange_timing_data_t {
    char *exchange; // string
    long *start_time; //numeric
    long *end_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} exchange_timing_data_t;

exchange_timing_data_t *exchange_timing_data_create(
    char *exchange,
    long *start_time,
    long *end_time
);

void exchange_timing_data_free(exchange_timing_data_t *exchange_timing_data);

exchange_timing_data_t *exchange_timing_data_parseFromJSON(cJSON *exchange_timing_dataJSON);

cJSON *exchange_timing_data_convertToJSON(exchange_timing_data_t *exchange_timing_data);

#endif /* _exchange_timing_data_H_ */

