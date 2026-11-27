/*
 * margin.h
 *
 * 
 */

#ifndef _margin_H_
#define _margin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct margin_t margin_t;




typedef struct margin_t {
    double *span_margin; //numeric
    double *exposure_margin; //numeric
    double *equity_margin; //numeric
    double *net_buy_premium; //numeric
    double *additional_margin; //numeric
    double *total_margin; //numeric
    double *tender_margin; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} margin_t;

margin_t *margin_create(
    double *span_margin,
    double *exposure_margin,
    double *equity_margin,
    double *net_buy_premium,
    double *additional_margin,
    double *total_margin,
    double *tender_margin
);

void margin_free(margin_t *margin);

margin_t *margin_parseFromJSON(cJSON *marginJSON);

cJSON *margin_convertToJSON(margin_t *margin);

#endif /* _margin_H_ */

