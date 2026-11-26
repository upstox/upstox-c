/*
 * market_quote_symbol_v3.h
 *
 * 
 */

#ifndef _market_quote_symbol_v3_H_
#define _market_quote_symbol_v3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_quote_symbol_v3_t market_quote_symbol_v3_t;

#include "depth_map.h"
#include "ohlc_v3.h"



typedef struct market_quote_symbol_v3_t {
    struct ohlc_v3_t *ohlc; //model
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
    double *prev_close_price; //numeric
    double *year_high; //numeric
    double *year_low; //numeric
    double *previous_oi; //numeric
    double *indicative_equilibrium_price; //numeric
    double *reference_price; //numeric
    long *indicative_equilibrium_quantity; //numeric
    long *indicative_imbalance_quantity_total; //numeric
    long *indicative_imbalance_quantity_market; //numeric
    int *cas_eligible; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} market_quote_symbol_v3_t;

market_quote_symbol_v3_t *market_quote_symbol_v3_create(
    ohlc_v3_t *ohlc,
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
    double *oi_day_low,
    double *prev_close_price,
    double *year_high,
    double *year_low,
    double *previous_oi,
    double *indicative_equilibrium_price,
    double *reference_price,
    long *indicative_equilibrium_quantity,
    long *indicative_imbalance_quantity_total,
    long *indicative_imbalance_quantity_market,
    int *cas_eligible
);

void market_quote_symbol_v3_free(market_quote_symbol_v3_t *market_quote_symbol_v3);

market_quote_symbol_v3_t *market_quote_symbol_v3_parseFromJSON(cJSON *market_quote_symbol_v3JSON);

cJSON *market_quote_symbol_v3_convertToJSON(market_quote_symbol_v3_t *market_quote_symbol_v3);

#endif /* _market_quote_symbol_v3_H_ */

