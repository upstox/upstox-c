/*
 * get_full_market_quote_response_v3.h
 *
 * 
 */

#ifndef _get_full_market_quote_response_v3_H_
#define _get_full_market_quote_response_v3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_full_market_quote_response_v3_t get_full_market_quote_response_v3_t;

#include "market_quote_symbol_v3.h"

// Enum STATUS for get_full_market_quote_response_v3

typedef enum  { upstox_client_get_full_market_quote_response_v3_STATUS_NULL = 0, upstox_client_get_full_market_quote_response_v3_STATUS_success, upstox_client_get_full_market_quote_response_v3_STATUS_error, upstox_client_get_full_market_quote_response_v3_STATUS_partial_success } upstox_client_get_full_market_quote_response_v3_STATUS_e;

char* get_full_market_quote_response_v3_status_ToString(upstox_client_get_full_market_quote_response_v3_STATUS_e status);

upstox_client_get_full_market_quote_response_v3_STATUS_e get_full_market_quote_response_v3_status_FromString(char* status);



typedef struct get_full_market_quote_response_v3_t {
    upstox_client_get_full_market_quote_response_v3_STATUS_e status; //enum
    list_t* data; //map

    int _library_owned; // Is the library responsible for freeing this object?
} get_full_market_quote_response_v3_t;

get_full_market_quote_response_v3_t *get_full_market_quote_response_v3_create(
    upstox_client_get_full_market_quote_response_v3_STATUS_e status,
    list_t* data
);

void get_full_market_quote_response_v3_free(get_full_market_quote_response_v3_t *get_full_market_quote_response_v3);

get_full_market_quote_response_v3_t *get_full_market_quote_response_v3_parseFromJSON(cJSON *get_full_market_quote_response_v3JSON);

cJSON *get_full_market_quote_response_v3_convertToJSON(get_full_market_quote_response_v3_t *get_full_market_quote_response_v3);

#endif /* _get_full_market_quote_response_v3_H_ */

