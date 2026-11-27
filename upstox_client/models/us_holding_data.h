/*
 * us_holding_data.h
 *
 * 
 */

#ifndef _us_holding_data_H_
#define _us_holding_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_holding_data_t us_holding_data_t;




typedef struct us_holding_data_t {
    char *exchange; // string
    double *quantity; //numeric
    double *pnl; //numeric
    char *instrument_key; // string
    char *trading_symbol; // string
    char *company_name; // string
    double *average_price; //numeric
    double *available_quantity; //numeric
    char *transaction_type; // string
    double *invested_value; //numeric
    double *last_price; //numeric
    double *previous_close; //numeric
    double *current_value; //numeric
    double *day_pnl; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_holding_data_t;

us_holding_data_t *us_holding_data_create(
    char *exchange,
    double *quantity,
    double *pnl,
    char *instrument_key,
    char *trading_symbol,
    char *company_name,
    double *average_price,
    double *available_quantity,
    char *transaction_type,
    double *invested_value,
    double *last_price,
    double *previous_close,
    double *current_value,
    double *day_pnl
);

void us_holding_data_free(us_holding_data_t *us_holding_data);

us_holding_data_t *us_holding_data_parseFromJSON(cJSON *us_holding_dataJSON);

cJSON *us_holding_data_convertToJSON(us_holding_data_t *us_holding_data);

#endif /* _us_holding_data_H_ */

