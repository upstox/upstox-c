/*
 * us_funds_data.h
 *
 * 
 */

#ifndef _us_funds_data_H_
#define _us_funds_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_funds_data_t us_funds_data_t;




typedef struct us_funds_data_t {
    double *cash; //numeric
    double *available_to_trade; //numeric
    double *available_to_withdraw; //numeric
    double *unsettled_cash; //numeric
    double *exchange_rate; //numeric
    double *available_to_trade_inr; //numeric
    double *available_to_withdraw_inr; //numeric
    double *cash_inr; //numeric
    double *unsettled_cash_inr; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_funds_data_t;

us_funds_data_t *us_funds_data_create(
    double *cash,
    double *available_to_trade,
    double *available_to_withdraw,
    double *unsettled_cash,
    double *exchange_rate,
    double *available_to_trade_inr,
    double *available_to_withdraw_inr,
    double *cash_inr,
    double *unsettled_cash_inr
);

void us_funds_data_free(us_funds_data_t *us_funds_data);

us_funds_data_t *us_funds_data_parseFromJSON(cJSON *us_funds_dataJSON);

cJSON *us_funds_data_convertToJSON(us_funds_data_t *us_funds_data);

#endif /* _us_funds_data_H_ */

