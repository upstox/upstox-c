/*
 * market_quote_symbol.h
 *
 * 
 */

#ifndef _market_quote_symbol_H_
#define _market_quote_symbol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_symbol_t market_quote_symbol_t;

#include "depth_map.h"
#include "ohlc.h"



typedef struct market_quote_symbol_t {
    struct ohlc_t *ohlc; //model
    struct depth_map_t *depth; //model
    char *timestamp; // string
    char *instrument_token; // string
    char *symbol; // string
    double *last_price; //numeric
    long *volume; //numeric
    double *average_price; //numeric
    double *oi; //numeric
    double *net_change; //numeric
    double *total_buy_quantity; //numeric
    double *total_sell_quantity; //numeric
    double *lower_circuit_limit; //numeric
    double *upper_circuit_limit; //numeric
    char *last_trade_time; // string
    double *oi_day_high; //numeric
    double *oi_day_low; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_symbol_t;

market_quote_symbol_t *market_quote_symbol_create(
    ohlc_t *ohlc,
    depth_map_t *depth,
    char *timestamp,
    char *instrument_token,
    char *symbol,
    double *last_price,
    long *volume,
    double *average_price,
    double *oi,
    double *net_change,
    double *total_buy_quantity,
    double *total_sell_quantity,
    double *lower_circuit_limit,
    double *upper_circuit_limit,
    char *last_trade_time,
    double *oi_day_high,
    double *oi_day_low
);

void market_quote_symbol_free(market_quote_symbol_t *market_quote_symbol);

market_quote_symbol_t *market_quote_symbol_parseFromJSON(cJSON *market_quote_symbolJSON);

cJSON *market_quote_symbol_convertToJSON(market_quote_symbol_t *market_quote_symbol);

#endif /* _market_quote_symbol_H_ */

