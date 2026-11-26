/*
 * mutual_fund_holding_data.h
 *
 * 
 */

#ifndef _mutual_fund_holding_data_H_
#define _mutual_fund_holding_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mutual_fund_holding_data_t mutual_fund_holding_data_t;




typedef struct mutual_fund_holding_data_t {
    char *folio; // string
    char *fund; // string
    double *pnl; //numeric
    double *quantity; //numeric
    char *instrument_key; // string
    double *average_price; //numeric
    double *last_price; //numeric
    char *last_price_date; // string
    double *pledged_quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} mutual_fund_holding_data_t;

mutual_fund_holding_data_t *mutual_fund_holding_data_create(
    char *folio,
    char *fund,
    double *pnl,
    double *quantity,
    char *instrument_key,
    double *average_price,
    double *last_price,
    char *last_price_date,
    double *pledged_quantity
);

void mutual_fund_holding_data_free(mutual_fund_holding_data_t *mutual_fund_holding_data);

mutual_fund_holding_data_t *mutual_fund_holding_data_parseFromJSON(cJSON *mutual_fund_holding_dataJSON);

cJSON *mutual_fund_holding_data_convertToJSON(mutual_fund_holding_data_t *mutual_fund_holding_data);

#endif /* _mutual_fund_holding_data_H_ */

