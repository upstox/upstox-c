/*
 * instrument_data.h
 *
 * 
 */

#ifndef _instrument_data_H_
#define _instrument_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instrument_data_t instrument_data_t;




typedef struct instrument_data_t {
    char *name; // string
    char *segment; // string
    char *exchange; // string
    char *isin; // string
    char *expiry; //date time
    char *country; // string
    char *latency; // string
    char *description; // string
    char *currency; // string
    int *weekly; //boolean
    char *instrument_key; // string
    char *exchange_token; // string
    char *trading_symbol; // string
    char *short_name; // string
    double *tick_size; //numeric
    long *lot_size; //numeric
    char *instrument_type; // string
    double *freeze_quantity; //numeric
    char *underlying_key; // string
    char *underlying_type; // string
    char *underlying_symbol; // string
    char *last_trading_date; //date time
    double *strike_price; //numeric
    char *price_quote_unit; // string
    long *qty_multiplier; //numeric
    long *minimum_lot; //numeric
    char *start_time; // string
    char *end_time; // string
    char *week_days; // string
    double *general_denominator; //numeric
    double *general_numerator; //numeric
    double *price_numerator; //numeric
    double *price_denominator; //numeric
    int *mtf_enabled; //boolean
    double *mtf_bracket; //numeric
    char *security_type; // string
    int *cas_eligible; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instrument_data_t;

instrument_data_t *instrument_data_create(
    char *name,
    char *segment,
    char *exchange,
    char *isin,
    char *expiry,
    char *country,
    char *latency,
    char *description,
    char *currency,
    int *weekly,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    char *short_name,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    char *last_trading_date,
    double *strike_price,
    char *price_quote_unit,
    long *qty_multiplier,
    long *minimum_lot,
    char *start_time,
    char *end_time,
    char *week_days,
    double *general_denominator,
    double *general_numerator,
    double *price_numerator,
    double *price_denominator,
    int *mtf_enabled,
    double *mtf_bracket,
    char *security_type,
    int *cas_eligible
);

void instrument_data_free(instrument_data_t *instrument_data);

instrument_data_t *instrument_data_parseFromJSON(cJSON *instrument_dataJSON);

cJSON *instrument_data_convertToJSON(instrument_data_t *instrument_data);

#endif /* _instrument_data_H_ */

