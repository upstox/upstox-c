/*
 * expired_future_data.h
 *
 * 
 */

#ifndef _expired_future_data_H_
#define _expired_future_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct expired_future_data_t expired_future_data_t;




typedef struct expired_future_data_t {
    char *name; // string
    char *segment; // string
    char *exchange; // string
    char *expiry; // string
    char *instrument_key; // string
    char *exchange_token; // string
    char *trading_symbol; // string
    double *tick_size; //numeric
    long *lot_size; //numeric
    char *instrument_type; // string
    double *freeze_quantity; //numeric
    char *underlying_key; // string
    char *underlying_type; // string
    char *underlying_symbol; // string
    long *minimum_lot; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} expired_future_data_t;

expired_future_data_t *expired_future_data_create(
    char *name,
    char *segment,
    char *exchange,
    char *expiry,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    long *minimum_lot
);

void expired_future_data_free(expired_future_data_t *expired_future_data);

expired_future_data_t *expired_future_data_parseFromJSON(cJSON *expired_future_dataJSON);

cJSON *expired_future_data_convertToJSON(expired_future_data_t *expired_future_data);

#endif /* _expired_future_data_H_ */

