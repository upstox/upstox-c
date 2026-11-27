/*
 * brokerage_wrapper_data.h
 *
 * 
 */

#ifndef _brokerage_wrapper_data_H_
#define _brokerage_wrapper_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct brokerage_wrapper_data_t brokerage_wrapper_data_t;

#include "brokerage_data.h"



typedef struct brokerage_wrapper_data_t {
    struct brokerage_data_t *charges; //model

    int _library_owned; // Is the library responsible for freeing this object?
} brokerage_wrapper_data_t;

brokerage_wrapper_data_t *brokerage_wrapper_data_create(
    brokerage_data_t *charges
);

void brokerage_wrapper_data_free(brokerage_wrapper_data_t *brokerage_wrapper_data);

brokerage_wrapper_data_t *brokerage_wrapper_data_parseFromJSON(cJSON *brokerage_wrapper_dataJSON);

cJSON *brokerage_wrapper_data_convertToJSON(brokerage_wrapper_data_t *brokerage_wrapper_data);

#endif /* _brokerage_wrapper_data_H_ */

