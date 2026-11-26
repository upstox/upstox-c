/*
 * news_item_data.h
 *
 * 
 */

#ifndef _news_item_data_H_
#define _news_item_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct news_item_data_t news_item_data_t;




typedef struct news_item_data_t {
    char *heading; // string
    char *summary; // string
    char *thumbnail; // string
    char *article_link; // string
    long *published_time; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} news_item_data_t;

news_item_data_t *news_item_data_create(
    char *heading,
    char *summary,
    char *thumbnail,
    char *article_link,
    long *published_time
);

void news_item_data_free(news_item_data_t *news_item_data);

news_item_data_t *news_item_data_parseFromJSON(cJSON *news_item_dataJSON);

cJSON *news_item_data_convertToJSON(news_item_data_t *news_item_data);

#endif /* _news_item_data_H_ */

