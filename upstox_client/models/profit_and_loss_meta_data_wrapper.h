/*
 * profit_and_loss_meta_data_wrapper.h
 *
 * 
 */

#ifndef _profit_and_loss_meta_data_wrapper_H_
#define _profit_and_loss_meta_data_wrapper_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_meta_data_wrapper_t profit_and_loss_meta_data_wrapper_t;

#include "profit_and_loss_meta_data.h"



typedef struct profit_and_loss_meta_data_wrapper_t {
    struct profit_and_loss_meta_data_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_meta_data_wrapper_t;

profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_create(
    profit_and_loss_meta_data_t *page
);

void profit_and_loss_meta_data_wrapper_free(profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper);

profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper_parseFromJSON(cJSON *profit_and_loss_meta_data_wrapperJSON);

cJSON *profit_and_loss_meta_data_wrapper_convertToJSON(profit_and_loss_meta_data_wrapper_t *profit_and_loss_meta_data_wrapper);

#endif /* _profit_and_loss_meta_data_wrapper_H_ */

