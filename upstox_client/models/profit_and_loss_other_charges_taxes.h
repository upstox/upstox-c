/*
 * profit_and_loss_other_charges_taxes.h
 *
 * 
 */

#ifndef _profit_and_loss_other_charges_taxes_H_
#define _profit_and_loss_other_charges_taxes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_other_charges_taxes_t profit_and_loss_other_charges_taxes_t;




typedef struct profit_and_loss_other_charges_taxes_t {
    double *transaction; //numeric
    double *clearing; //numeric
    double *ipft; //numeric
    double *others; //numeric
    double *sebi_turnover; //numeric
    double *demat_transaction; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_other_charges_taxes_t;

profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_create(
    double *transaction,
    double *clearing,
    double *ipft,
    double *others,
    double *sebi_turnover,
    double *demat_transaction
);

void profit_and_loss_other_charges_taxes_free(profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes);

profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_parseFromJSON(cJSON *profit_and_loss_other_charges_taxesJSON);

cJSON *profit_and_loss_other_charges_taxes_convertToJSON(profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes);

#endif /* _profit_and_loss_other_charges_taxes_H_ */

