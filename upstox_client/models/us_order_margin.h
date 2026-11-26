/*
 * us_order_margin.h
 *
 * 
 */

#ifndef _us_order_margin_H_
#define _us_order_margin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_margin_t us_order_margin_t;




typedef struct us_order_margin_t {
    double *brokerage; //numeric
    double *gst; //numeric
    char *instrument_key; // string
    char *transaction_type; // string
    double *trade_value; //numeric
    double *required_margin; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_margin_t;

us_order_margin_t *us_order_margin_create(
    double *brokerage,
    double *gst,
    char *instrument_key,
    char *transaction_type,
    double *trade_value,
    double *required_margin
);

void us_order_margin_free(us_order_margin_t *us_order_margin);

us_order_margin_t *us_order_margin_parseFromJSON(cJSON *us_order_marginJSON);

cJSON *us_order_margin_convertToJSON(us_order_margin_t *us_order_margin);

#endif /* _us_order_margin_H_ */

