/*
 * market_quote_symbol_ltp_v3.h
 *
 * 
 */

#ifndef _market_quote_symbol_ltp_v3_H_
#define _market_quote_symbol_ltp_v3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_symbol_ltp_v3_t market_quote_symbol_ltp_v3_t;




typedef struct market_quote_symbol_ltp_v3_t {
    double *last_price; //numeric
    char *instrument_token; // string
    long *ltq; //numeric
    long *volume; //numeric
    double *cp; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_symbol_ltp_v3_t;

market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_create(
    double *last_price,
    char *instrument_token,
    long *ltq,
    long *volume,
    double *cp
);

void market_quote_symbol_ltp_v3_free(market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3);

market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_parseFromJSON(cJSON *market_quote_symbol_ltp_v3JSON);

cJSON *market_quote_symbol_ltp_v3_convertToJSON(market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3);

#endif /* _market_quote_symbol_ltp_v3_H_ */

