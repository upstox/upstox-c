/*
 * market_quote_symbol_ltp.h
 *
 * 
 */

#ifndef _market_quote_symbol_ltp_H_
#define _market_quote_symbol_ltp_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_symbol_ltp_t market_quote_symbol_ltp_t;




typedef struct market_quote_symbol_ltp_t {
    double *last_price; //numeric
    char *instrument_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_symbol_ltp_t;

market_quote_symbol_ltp_t *market_quote_symbol_ltp_create(
    double *last_price,
    char *instrument_token
);

void market_quote_symbol_ltp_free(market_quote_symbol_ltp_t *market_quote_symbol_ltp);

market_quote_symbol_ltp_t *market_quote_symbol_ltp_parseFromJSON(cJSON *market_quote_symbol_ltpJSON);

cJSON *market_quote_symbol_ltp_convertToJSON(market_quote_symbol_ltp_t *market_quote_symbol_ltp);

#endif /* _market_quote_symbol_ltp_H_ */

