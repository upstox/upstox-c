/*
 * profit_and_loss_meta_data.h
 *
 * 
 */

#ifndef _profit_and_loss_meta_data_H_
#define _profit_and_loss_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profit_and_loss_meta_data_t profit_and_loss_meta_data_t;




typedef struct profit_and_loss_meta_data_t {
    int *page_number; //numeric
    int *page_size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} profit_and_loss_meta_data_t;

profit_and_loss_meta_data_t *profit_and_loss_meta_data_create(
    int *page_number,
    int *page_size
);

void profit_and_loss_meta_data_free(profit_and_loss_meta_data_t *profit_and_loss_meta_data);

profit_and_loss_meta_data_t *profit_and_loss_meta_data_parseFromJSON(cJSON *profit_and_loss_meta_dataJSON);

cJSON *profit_and_loss_meta_data_convertToJSON(profit_and_loss_meta_data_t *profit_and_loss_meta_data);

#endif /* _profit_and_loss_meta_data_H_ */

