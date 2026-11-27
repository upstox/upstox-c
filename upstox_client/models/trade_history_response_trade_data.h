/*
 * trade_history_response_trade_data.h
 *
 * 
 */

#ifndef _trade_history_response_trade_data_H_
#define _trade_history_response_trade_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_history_response_trade_data_t trade_history_response_trade_data_t;




typedef struct trade_history_response_trade_data_t {
    char *exchange; // string
    char *segment; // string
    char *option_type; // string
    int *quantity; //numeric
    double *amount; //numeric
    char *trade_id; // string
    char *trade_date; // string
    char *transaction_type; // string
    char *scrip_name; // string
    char *strike_price; // string
    char *expiry; // string
    double *price; //numeric
    char *isin; // string
    char *symbol; // string
    char *instrument_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} trade_history_response_trade_data_t;

trade_history_response_trade_data_t *trade_history_response_trade_data_create(
    char *exchange,
    char *segment,
    char *option_type,
    int *quantity,
    double *amount,
    char *trade_id,
    char *trade_date,
    char *transaction_type,
    char *scrip_name,
    char *strike_price,
    char *expiry,
    double *price,
    char *isin,
    char *symbol,
    char *instrument_token
);

void trade_history_response_trade_data_free(trade_history_response_trade_data_t *trade_history_response_trade_data);

trade_history_response_trade_data_t *trade_history_response_trade_data_parseFromJSON(cJSON *trade_history_response_trade_dataJSON);

cJSON *trade_history_response_trade_data_convertToJSON(trade_history_response_trade_data_t *trade_history_response_trade_data);

#endif /* _trade_history_response_trade_data_H_ */

