/*
 * profit_and_loss_charges_wrapper_data.h
 *
 * 
 */

#ifndef _profit_and_loss_charges_wrapper_data_H_
#define _profit_and_loss_charges_wrapper_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_charges_wrapper_data_t profit_and_loss_charges_wrapper_data_t;

#include "profit_and_loss_charges_data.h"



typedef struct profit_and_loss_charges_wrapper_data_t {
    struct profit_and_loss_charges_data_t *charges_breakdown; //model

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_charges_wrapper_data_t;

profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_create(
    profit_and_loss_charges_data_t *charges_breakdown
);

void profit_and_loss_charges_wrapper_data_free(profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data);

profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data_parseFromJSON(cJSON *profit_and_loss_charges_wrapper_dataJSON);

cJSON *profit_and_loss_charges_wrapper_data_convertToJSON(profit_and_loss_charges_wrapper_data_t *profit_and_loss_charges_wrapper_data);

#endif /* _profit_and_loss_charges_wrapper_data_H_ */

