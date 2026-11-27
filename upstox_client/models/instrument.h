/*
 * instrument.h
 *
 * 
 */

#ifndef _instrument_H_
#define _instrument_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instrument_t instrument_t;




typedef struct instrument_t {
    char *instrument_key; // string
    int *quantity; //numeric
    char *product; // string
    char *transaction_type; // string
    double *price; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} instrument_t;

instrument_t *instrument_create(
    char *instrument_key,
    int *quantity,
    char *product,
    char *transaction_type,
    double *price
);

void instrument_free(instrument_t *instrument);

instrument_t *instrument_parseFromJSON(cJSON *instrumentJSON);

cJSON *instrument_convertToJSON(instrument_t *instrument);

#endif /* _instrument_H_ */

