/*
 * search_instrument_response.h
 *
 * 
 */

#ifndef _search_instrument_response_H_
#define _search_instrument_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct search_instrument_response_t search_instrument_response_t;

#include "instrument_data.h"
#include "search_meta_data.h"

// Enum STATUS for search_instrument_response

typedef enum  { upstox_client_search_instrument_response_STATUS_NULL = 0, upstox_client_search_instrument_response_STATUS_success, upstox_client_search_instrument_response_STATUS_error, upstox_client_search_instrument_response_STATUS_partial_success } upstox_client_search_instrument_response_STATUS_e;

char* search_instrument_response_status_ToString(upstox_client_search_instrument_response_STATUS_e status);

upstox_client_search_instrument_response_STATUS_e search_instrument_response_status_FromString(char* status);



typedef struct search_instrument_response_t {
    upstox_client_search_instrument_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container
    struct search_meta_data_t *meta_data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} search_instrument_response_t;

search_instrument_response_t *search_instrument_response_create(
    upstox_client_search_instrument_response_STATUS_e status,
    list_t *data,
    search_meta_data_t *meta_data
);

void search_instrument_response_free(search_instrument_response_t *search_instrument_response);

search_instrument_response_t *search_instrument_response_parseFromJSON(cJSON *search_instrument_responseJSON);

cJSON *search_instrument_response_convertToJSON(search_instrument_response_t *search_instrument_response);

#endif /* _search_instrument_response_H_ */

