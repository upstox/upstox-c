/*
 * profit_and_loss_charges_taxes.h
 *
 * 
 */

#ifndef _profit_and_loss_charges_taxes_H_
#define _profit_and_loss_charges_taxes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_charges_taxes_t profit_and_loss_charges_taxes_t;




typedef struct profit_and_loss_charges_taxes_t {
    double *gst; //numeric
    double *stt; //numeric
    double *stamp_duty; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_charges_taxes_t;

profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_create(
    double *gst,
    double *stt,
    double *stamp_duty
);

void profit_and_loss_charges_taxes_free(profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes);

profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes_parseFromJSON(cJSON *profit_and_loss_charges_taxesJSON);

cJSON *profit_and_loss_charges_taxes_convertToJSON(profit_and_loss_charges_taxes_t *profit_and_loss_charges_taxes);

#endif /* _profit_and_loss_charges_taxes_H_ */

