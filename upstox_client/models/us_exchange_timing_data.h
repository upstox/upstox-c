/*
 * us_exchange_timing_data.h
 *
 * 
 */

#ifndef _us_exchange_timing_data_H_
#define _us_exchange_timing_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_exchange_timing_data_t us_exchange_timing_data_t;




typedef struct us_exchange_timing_data_t {
    char *exchange; // string
    long *start_time; //numeric
    long *end_time; //numeric
    long *overnight_start_time; //numeric
    long *overnight_end_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_exchange_timing_data_t;

us_exchange_timing_data_t *us_exchange_timing_data_create(
    char *exchange,
    long *start_time,
    long *end_time,
    long *overnight_start_time,
    long *overnight_end_time
);

void us_exchange_timing_data_free(us_exchange_timing_data_t *us_exchange_timing_data);

us_exchange_timing_data_t *us_exchange_timing_data_parseFromJSON(cJSON *us_exchange_timing_dataJSON);

cJSON *us_exchange_timing_data_convertToJSON(us_exchange_timing_data_t *us_exchange_timing_data);

#endif /* _us_exchange_timing_data_H_ */

