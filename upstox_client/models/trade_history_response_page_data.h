/*
 * trade_history_response_page_data.h
 *
 * 
 */

#ifndef _trade_history_response_page_data_H_
#define _trade_history_response_page_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_history_response_page_data_t trade_history_response_page_data_t;




typedef struct trade_history_response_page_data_t {
    int *page_number; //numeric
    int *page_size; //numeric
    int *total_records; //numeric
    int *total_pages; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} trade_history_response_page_data_t;

trade_history_response_page_data_t *trade_history_response_page_data_create(
    int *page_number,
    int *page_size,
    int *total_records,
    int *total_pages
);

void trade_history_response_page_data_free(trade_history_response_page_data_t *trade_history_response_page_data);

trade_history_response_page_data_t *trade_history_response_page_data_parseFromJSON(cJSON *trade_history_response_page_dataJSON);

cJSON *trade_history_response_page_data_convertToJSON(trade_history_response_page_data_t *trade_history_response_page_data);

#endif /* _trade_history_response_page_data_H_ */

