/*
 * mutual_fund_meta_data.h
 *
 * 
 */

#ifndef _mutual_fund_meta_data_H_
#define _mutual_fund_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mutual_fund_meta_data_t mutual_fund_meta_data_t;

#include "pagination.h"



typedef struct mutual_fund_meta_data_t {
    struct pagination_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} mutual_fund_meta_data_t;

mutual_fund_meta_data_t *mutual_fund_meta_data_create(
    pagination_t *page
);

void mutual_fund_meta_data_free(mutual_fund_meta_data_t *mutual_fund_meta_data);

mutual_fund_meta_data_t *mutual_fund_meta_data_parseFromJSON(cJSON *mutual_fund_meta_dataJSON);

cJSON *mutual_fund_meta_data_convertToJSON(mutual_fund_meta_data_t *mutual_fund_meta_data);

#endif /* _mutual_fund_meta_data_H_ */

