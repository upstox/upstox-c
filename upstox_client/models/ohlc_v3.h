/*
 * ohlc_v3.h
 *
 * 
 */

#ifndef _ohlc_v3_H_
#define _ohlc_v3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ohlc_v3_t ohlc_v3_t;




typedef struct ohlc_v3_t {
    double *open; //numeric
    double *high; //numeric
    double *low; //numeric
    double *close; //numeric
    long *volume; //numeric
    long *ts; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ohlc_v3_t;

ohlc_v3_t *ohlc_v3_create(
    double *open,
    double *high,
    double *low,
    double *close,
    long *volume,
    long *ts
);

void ohlc_v3_free(ohlc_v3_t *ohlc_v3);

ohlc_v3_t *ohlc_v3_parseFromJSON(cJSON *ohlc_v3JSON);

cJSON *ohlc_v3_convertToJSON(ohlc_v3_t *ohlc_v3);

#endif /* _ohlc_v3_H_ */

