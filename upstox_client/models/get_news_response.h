/*
 * get_news_response.h
 *
 * 
 */

#ifndef _get_news_response_H_
#define _get_news_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_news_response_t get_news_response_t;

#include "news_item_data.h"
#include "news_response_meta_data.h"

// Enum STATUS for get_news_response

typedef enum  { upstox_client_get_news_response_STATUS_NULL = 0, upstox_client_get_news_response_STATUS_success, upstox_client_get_news_response_STATUS_error, upstox_client_get_news_response_STATUS_partial_success } upstox_client_get_news_response_STATUS_e;

char* get_news_response_status_ToString(upstox_client_get_news_response_STATUS_e status);

upstox_client_get_news_response_STATUS_e get_news_response_status_FromString(char* status);



typedef struct get_news_response_t {
    upstox_client_get_news_response_STATUS_e status; //enum
    list_t* data; //map
    struct news_response_meta_data_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_news_response_t;

get_news_response_t *get_news_response_create(
    upstox_client_get_news_response_STATUS_e status,
    list_t* data,
    news_response_meta_data_t *metadata
);

void get_news_response_free(get_news_response_t *get_news_response);

get_news_response_t *get_news_response_parseFromJSON(cJSON *get_news_responseJSON);

cJSON *get_news_response_convertToJSON(get_news_response_t *get_news_response);

#endif /* _get_news_response_H_ */

