/*
 * brokerage_data.h
 *
 * 
 */

#ifndef _brokerage_data_H_
#define _brokerage_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct brokerage_data_t brokerage_data_t;

#include "brokerage_taxes.h"
#include "dp_plan.h"
#include "other_taxes.h"



typedef struct brokerage_data_t {
    double *total; //numeric
    double *brokerage; //numeric
    struct brokerage_taxes_t *taxes; //model
    struct other_taxes_t *other_taxes; //model
    struct other_taxes_t *other_charges; //model
    struct dp_plan_t *dp_plan; //model

    int _library_owned; // Is the library responsible for freeing this object?
} brokerage_data_t;

brokerage_data_t *brokerage_data_create(
    double *total,
    double *brokerage,
    brokerage_taxes_t *taxes,
    other_taxes_t *other_taxes,
    other_taxes_t *other_charges,
    dp_plan_t *dp_plan
);

void brokerage_data_free(brokerage_data_t *brokerage_data);

brokerage_data_t *brokerage_data_parseFromJSON(cJSON *brokerage_dataJSON);

cJSON *brokerage_data_convertToJSON(brokerage_data_t *brokerage_data);

#endif /* _brokerage_data_H_ */

