/*
 * brokerage_taxes.h
 *
 * 
 */

#ifndef _brokerage_taxes_H_
#define _brokerage_taxes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct brokerage_taxes_t brokerage_taxes_t;




typedef struct brokerage_taxes_t {
    double *gst; //numeric
    double *stt; //numeric
    double *stamp_duty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} brokerage_taxes_t;

brokerage_taxes_t *brokerage_taxes_create(
    double *gst,
    double *stt,
    double *stamp_duty
);

void brokerage_taxes_free(brokerage_taxes_t *brokerage_taxes);

brokerage_taxes_t *brokerage_taxes_parseFromJSON(cJSON *brokerage_taxesJSON);

cJSON *brokerage_taxes_convertToJSON(brokerage_taxes_t *brokerage_taxes);

#endif /* _brokerage_taxes_H_ */

