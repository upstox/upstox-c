/*
 * trade_wise_meta_data.h
 *
 * 
 */

#ifndef _trade_wise_meta_data_H_
#define _trade_wise_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_wise_meta_data_t trade_wise_meta_data_t;




typedef struct trade_wise_meta_data_t {
    int *trades_count; //numeric
    int *page_size_limit; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} trade_wise_meta_data_t;

trade_wise_meta_data_t *trade_wise_meta_data_create(
    int *trades_count,
    int *page_size_limit
);

void trade_wise_meta_data_free(trade_wise_meta_data_t *trade_wise_meta_data);

trade_wise_meta_data_t *trade_wise_meta_data_parseFromJSON(cJSON *trade_wise_meta_dataJSON);

cJSON *trade_wise_meta_data_convertToJSON(trade_wise_meta_data_t *trade_wise_meta_data);

#endif /* _trade_wise_meta_data_H_ */

