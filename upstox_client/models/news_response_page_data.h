/*
 * news_response_page_data.h
 *
 * 
 */

#ifndef _news_response_page_data_H_
#define _news_response_page_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct news_response_page_data_t news_response_page_data_t;




typedef struct news_response_page_data_t {
    int *page_number; //numeric
    int *page_size; //numeric
    int *total_records; //numeric
    int *total_pages; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} news_response_page_data_t;

news_response_page_data_t *news_response_page_data_create(
    int *page_number,
    int *page_size,
    int *total_records,
    int *total_pages
);

void news_response_page_data_free(news_response_page_data_t *news_response_page_data);

news_response_page_data_t *news_response_page_data_parseFromJSON(cJSON *news_response_page_dataJSON);

cJSON *news_response_page_data_convertToJSON(news_response_page_data_t *news_response_page_data);

#endif /* _news_response_page_data_H_ */

