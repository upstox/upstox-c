/*
 * news_response_meta_data.h
 *
 * 
 */

#ifndef _news_response_meta_data_H_
#define _news_response_meta_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct news_response_meta_data_t news_response_meta_data_t;

#include "news_response_page_data.h"



typedef struct news_response_meta_data_t {
    struct news_response_page_data_t *page; //model

    int _library_owned; // Is the library responsible for freeing this object?
} news_response_meta_data_t;

news_response_meta_data_t *news_response_meta_data_create(
    news_response_page_data_t *page
);

void news_response_meta_data_free(news_response_meta_data_t *news_response_meta_data);

news_response_meta_data_t *news_response_meta_data_parseFromJSON(cJSON *news_response_meta_dataJSON);

cJSON *news_response_meta_data_convertToJSON(news_response_meta_data_t *news_response_meta_data);

#endif /* _news_response_meta_data_H_ */

