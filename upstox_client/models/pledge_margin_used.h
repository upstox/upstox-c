/*
 * pledge_margin_used.h
 *
 * 
 */

#ifndef _pledge_margin_used_H_
#define _pledge_margin_used_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pledge_margin_used_t pledge_margin_used_t;

#include "delivery_margin.h"



typedef struct pledge_margin_used_t {
    double *total; //numeric
    double *mtf; //numeric
    double *span_exposure; //numeric
    double *cash_margin_var_elm; //numeric
    double *premium_present; //numeric
    struct delivery_margin_t *delivery_margin; //model

    int _library_owned; // Is the library responsible for freeing this object?
} pledge_margin_used_t;

pledge_margin_used_t *pledge_margin_used_create(
    double *total,
    double *mtf,
    double *span_exposure,
    double *cash_margin_var_elm,
    double *premium_present,
    delivery_margin_t *delivery_margin
);

void pledge_margin_used_free(pledge_margin_used_t *pledge_margin_used);

pledge_margin_used_t *pledge_margin_used_parseFromJSON(cJSON *pledge_margin_usedJSON);

cJSON *pledge_margin_used_convertToJSON(pledge_margin_used_t *pledge_margin_used);

#endif /* _pledge_margin_used_H_ */

