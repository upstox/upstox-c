/*
 * trade_history_response_meta_data.h
 *
 * 
 */

#ifndef _trade_history_response_meta_data_H_
#define _trade_history_response_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_history_response_meta_data_t trade_history_response_meta_data_t;

#include "trade_history_response_page_data.h"



typedef struct trade_history_response_meta_data_t {
    struct trade_history_response_page_data_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} trade_history_response_meta_data_t;

trade_history_response_meta_data_t *trade_history_response_meta_data_create(
    trade_history_response_page_data_t *page
);

void trade_history_response_meta_data_free(trade_history_response_meta_data_t *trade_history_response_meta_data);

trade_history_response_meta_data_t *trade_history_response_meta_data_parseFromJSON(cJSON *trade_history_response_meta_dataJSON);

cJSON *trade_history_response_meta_data_convertToJSON(trade_history_response_meta_data_t *trade_history_response_meta_data);

#endif /* _trade_history_response_meta_data_H_ */

