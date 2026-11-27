/*
 * get_mutual_fund_holdings_response.h
 *
 * 
 */

#ifndef _get_mutual_fund_holdings_response_H_
#define _get_mutual_fund_holdings_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_mutual_fund_holdings_response_t get_mutual_fund_holdings_response_t;

#include "mutual_fund_holding_data.h"

// Enum STATUS for get_mutual_fund_holdings_response

typedef enum  { upstox_client_get_mutual_fund_holdings_response_STATUS_NULL = 0, upstox_client_get_mutual_fund_holdings_response_STATUS_success, upstox_client_get_mutual_fund_holdings_response_STATUS_error, upstox_client_get_mutual_fund_holdings_response_STATUS_partial_success } upstox_client_get_mutual_fund_holdings_response_STATUS_e;

char* get_mutual_fund_holdings_response_status_ToString(upstox_client_get_mutual_fund_holdings_response_STATUS_e status);

upstox_client_get_mutual_fund_holdings_response_STATUS_e get_mutual_fund_holdings_response_status_FromString(char* status);



typedef struct get_mutual_fund_holdings_response_t {
    upstox_client_get_mutual_fund_holdings_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_mutual_fund_holdings_response_t;

get_mutual_fund_holdings_response_t *get_mutual_fund_holdings_response_create(
    upstox_client_get_mutual_fund_holdings_response_STATUS_e status,
    list_t *data
);

void get_mutual_fund_holdings_response_free(get_mutual_fund_holdings_response_t *get_mutual_fund_holdings_response);

get_mutual_fund_holdings_response_t *get_mutual_fund_holdings_response_parseFromJSON(cJSON *get_mutual_fund_holdings_responseJSON);

cJSON *get_mutual_fund_holdings_response_convertToJSON(get_mutual_fund_holdings_response_t *get_mutual_fund_holdings_response);

#endif /* _get_mutual_fund_holdings_response_H_ */

