/*
 * ohlc.h
 *
 * 
 */

#ifndef _ohlc_H_
#define _ohlc_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ohlc_t ohlc_t;




typedef struct ohlc_t {
    double *open; //numeric
    double *high; //numeric
    double *low; //numeric
    double *close; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ohlc_t;

ohlc_t *ohlc_create(
    double *open,
    double *high,
    double *low,
    double *close
);

void ohlc_free(ohlc_t *ohlc);

ohlc_t *ohlc_parseFromJSON(cJSON *ohlcJSON);

cJSON *ohlc_convertToJSON(ohlc_t *ohlc);

#endif /* _ohlc_H_ */

