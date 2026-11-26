/*
 * market_data.h
 *
 * 
 */

#ifndef _market_data_H_
#define _market_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_data_t market_data_t;




typedef struct market_data_t {
    double *ltp; //numeric
    long *volume; //numeric
    double *oi; //numeric
    double *close_price; //numeric
    double *bid_price; //numeric
    int *bid_qty; //numeric
    double *ask_price; //numeric
    int *ask_qty; //numeric
    double *prev_oi; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} market_data_t;

market_data_t *market_data_create(
    double *ltp,
    long *volume,
    double *oi,
    double *close_price,
    double *bid_price,
    int *bid_qty,
    double *ask_price,
    int *ask_qty,
    double *prev_oi
);

void market_data_free(market_data_t *market_data);

market_data_t *market_data_parseFromJSON(cJSON *market_dataJSON);

cJSON *market_data_convertToJSON(market_data_t *market_data);

#endif /* _market_data_H_ */

