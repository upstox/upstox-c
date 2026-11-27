/*
 * cash_margin_used.h
 *
 * 
 */

#ifndef _cash_margin_used_H_
#define _cash_margin_used_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_margin_used_t cash_margin_used_t;

#include "delivery_margin.h"
#include "loss.h"



typedef struct cash_margin_used_t {
    double *total; //numeric
    double *mtf; //numeric
    struct loss_t *loss; //model
    double *span_exposure; //numeric
    double *cash_margin_var_elm; //numeric
    double *premium_present; //numeric
    struct delivery_margin_t *delivery_margin; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cash_margin_used_t;

cash_margin_used_t *cash_margin_used_create(
    double *total,
    double *mtf,
    loss_t *loss,
    double *span_exposure,
    double *cash_margin_var_elm,
    double *premium_present,
    delivery_margin_t *delivery_margin
);

void cash_margin_used_free(cash_margin_used_t *cash_margin_used);

cash_margin_used_t *cash_margin_used_parseFromJSON(cJSON *cash_margin_usedJSON);

cJSON *cash_margin_used_convertToJSON(cash_margin_used_t *cash_margin_used);

#endif /* _cash_margin_used_H_ */

