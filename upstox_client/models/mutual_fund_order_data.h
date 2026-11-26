/*
 * mutual_fund_order_data.h
 *
 * 
 */

#ifndef _mutual_fund_order_data_H_
#define _mutual_fund_order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mutual_fund_order_data_t mutual_fund_order_data_t;




typedef struct mutual_fund_order_data_t {
    char *status; // string
    char *folio; // string
    char *fund; // string
    double *amount; //numeric
    char *variety; // string
    double *quantity; //numeric
    double *price; //numeric
    char *order_id; // string
    char *exchange_order_id; // string
    char *instrument_key; // string
    char *status_message; // string
    char *order_timestamp; // string
    char *exchange_timestamp; // string
    char *settlement_id; // string
    char *transaction_type; // string
    char *purchase_type; // string
    double *last_price; //numeric
    double *average_price; //numeric
    char *last_price_date; // string

    int _library_owned; // Is the library responsible for freeing this object?
} mutual_fund_order_data_t;

mutual_fund_order_data_t *mutual_fund_order_data_create(
    char *status,
    char *folio,
    char *fund,
    double *amount,
    char *variety,
    double *quantity,
    double *price,
    char *order_id,
    char *exchange_order_id,
    char *instrument_key,
    char *status_message,
    char *order_timestamp,
    char *exchange_timestamp,
    char *settlement_id,
    char *transaction_type,
    char *purchase_type,
    double *last_price,
    double *average_price,
    char *last_price_date
);

void mutual_fund_order_data_free(mutual_fund_order_data_t *mutual_fund_order_data);

mutual_fund_order_data_t *mutual_fund_order_data_parseFromJSON(cJSON *mutual_fund_order_dataJSON);

cJSON *mutual_fund_order_data_convertToJSON(mutual_fund_order_data_t *mutual_fund_order_data);

#endif /* _mutual_fund_order_data_H_ */

