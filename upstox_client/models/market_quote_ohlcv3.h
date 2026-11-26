/*
 * market_quote_ohlcv3.h
 *
 * 
 */

#ifndef _market_quote_ohlcv3_H_
#define _market_quote_ohlcv3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_ohlcv3_t market_quote_ohlcv3_t;

#include "ohlc_v3.h"



typedef struct market_quote_ohlcv3_t {
    double *last_price; //numeric
    char *instrument_token; // string
    struct ohlc_v3_t *prev_ohlc; //model
    struct ohlc_v3_t *live_ohlc; //model

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_ohlcv3_t;

market_quote_ohlcv3_t *market_quote_ohlcv3_create(
    double *last_price,
    char *instrument_token,
    ohlc_v3_t *prev_ohlc,
    ohlc_v3_t *live_ohlc
);

void market_quote_ohlcv3_free(market_quote_ohlcv3_t *market_quote_ohlcv3);

market_quote_ohlcv3_t *market_quote_ohlcv3_parseFromJSON(cJSON *market_quote_ohlcv3JSON);

cJSON *market_quote_ohlcv3_convertToJSON(market_quote_ohlcv3_t *market_quote_ohlcv3);

#endif /* _market_quote_ohlcv3_H_ */

