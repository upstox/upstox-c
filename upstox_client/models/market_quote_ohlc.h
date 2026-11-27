/*
 * market_quote_ohlc.h
 *
 * 
 */

#ifndef _market_quote_ohlc_H_
#define _market_quote_ohlc_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_ohlc_t market_quote_ohlc_t;

#include "ohlc.h"



typedef struct market_quote_ohlc_t {
    struct ohlc_t *ohlc; //model
    double *last_price; //numeric
    char *instrument_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_ohlc_t;

market_quote_ohlc_t *market_quote_ohlc_create(
    ohlc_t *ohlc,
    double *last_price,
    char *instrument_token
);

void market_quote_ohlc_free(market_quote_ohlc_t *market_quote_ohlc);

market_quote_ohlc_t *market_quote_ohlc_parseFromJSON(cJSON *market_quote_ohlcJSON);

cJSON *market_quote_ohlc_convertToJSON(market_quote_ohlc_t *market_quote_ohlc);

#endif /* _market_quote_ohlc_H_ */

