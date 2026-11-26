/*
 * us_order_estimate_data.h
 *
 * 
 */

#ifndef _us_order_estimate_data_H_
#define _us_order_estimate_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_estimate_data_t us_order_estimate_data_t;




typedef struct us_order_estimate_data_t {
    double *brokerage; //numeric
    double *gst; //numeric
    double *trade_value; //numeric
    double *regulatory_fee; //numeric
    double *taf_fee; //numeric
    double *cat_fee; //numeric
    double *total_charges; //numeric
    double *estimated_total; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_estimate_data_t;

us_order_estimate_data_t *us_order_estimate_data_create(
    double *brokerage,
    double *gst,
    double *trade_value,
    double *regulatory_fee,
    double *taf_fee,
    double *cat_fee,
    double *total_charges,
    double *estimated_total
);

void us_order_estimate_data_free(us_order_estimate_data_t *us_order_estimate_data);

us_order_estimate_data_t *us_order_estimate_data_parseFromJSON(cJSON *us_order_estimate_dataJSON);

cJSON *us_order_estimate_data_convertToJSON(us_order_estimate_data_t *us_order_estimate_data);

#endif /* _us_order_estimate_data_H_ */

