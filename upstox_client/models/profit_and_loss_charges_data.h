/*
 * profit_and_loss_charges_data.h
 *
 * 
 */

#ifndef _profit_and_loss_charges_data_H_
#define _profit_and_loss_charges_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_charges_data_t profit_and_loss_charges_data_t;

#include "profit_and_loss_charges_taxes.h"
#include "profit_and_loss_other_charges_taxes.h"



typedef struct profit_and_loss_charges_data_t {
    double *total; //numeric
    double *brokerage; //numeric
    struct profit_and_loss_charges_taxes_t *taxes; //model
    struct profit_and_loss_other_charges_taxes_t *charges; //model

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_charges_data_t;

profit_and_loss_charges_data_t *profit_and_loss_charges_data_create(
    double *total,
    double *brokerage,
    profit_and_loss_charges_taxes_t *taxes,
    profit_and_loss_other_charges_taxes_t *charges
);

void profit_and_loss_charges_data_free(profit_and_loss_charges_data_t *profit_and_loss_charges_data);

profit_and_loss_charges_data_t *profit_and_loss_charges_data_parseFromJSON(cJSON *profit_and_loss_charges_dataJSON);

cJSON *profit_and_loss_charges_data_convertToJSON(profit_and_loss_charges_data_t *profit_and_loss_charges_data);

#endif /* _profit_and_loss_charges_data_H_ */

