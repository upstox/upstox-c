/*
 * get_market_quote_last_traded_price_response.h
 *
 * 
 */

#ifndef _get_market_quote_last_traded_price_response_H_
#define _get_market_quote_last_traded_price_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_market_quote_last_traded_price_response_t get_market_quote_last_traded_price_response_t;

#include "market_quote_symbol_ltp.h"

// Enum STATUS for get_market_quote_last_traded_price_response

typedef enum  { upstox_client_get_market_quote_last_traded_price_response_STATUS_NULL = 0, upstox_client_get_market_quote_last_traded_price_response_STATUS_success, upstox_client_get_market_quote_last_traded_price_response_STATUS_error, upstox_client_get_market_quote_last_traded_price_response_STATUS_partial_success } upstox_client_get_market_quote_last_traded_price_response_STATUS_e;

char* get_market_quote_last_traded_price_response_status_ToString(upstox_client_get_market_quote_last_traded_price_response_STATUS_e status);

upstox_client_get_market_quote_last_traded_price_response_STATUS_e get_market_quote_last_traded_price_response_status_FromString(char* status);



typedef struct get_market_quote_last_traded_price_response_t {
    upstox_client_get_market_quote_last_traded_price_response_STATUS_e status; //enum
    list_t* data; //map

    int _library_owned; // Is the library responsible for freeing this object?
} get_market_quote_last_traded_price_response_t;

get_market_quote_last_traded_price_response_t *get_market_quote_last_traded_price_response_create(
    upstox_client_get_market_quote_last_traded_price_response_STATUS_e status,
    list_t* data
);

void get_market_quote_last_traded_price_response_free(get_market_quote_last_traded_price_response_t *get_market_quote_last_traded_price_response);

get_market_quote_last_traded_price_response_t *get_market_quote_last_traded_price_response_parseFromJSON(cJSON *get_market_quote_last_traded_price_responseJSON);

cJSON *get_market_quote_last_traded_price_response_convertToJSON(get_market_quote_last_traded_price_response_t *get_market_quote_last_traded_price_response);

#endif /* _get_market_quote_last_traded_price_response_H_ */

