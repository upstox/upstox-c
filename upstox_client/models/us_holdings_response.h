/*
 * us_holdings_response.h
 *
 * 
 */

#ifndef _us_holdings_response_H_
#define _us_holdings_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_holdings_response_t us_holdings_response_t;

#include "us_holding_data.h"

// Enum STATUS for us_holdings_response

typedef enum  { upstox_client_us_holdings_response_STATUS_NULL = 0, upstox_client_us_holdings_response_STATUS_success, upstox_client_us_holdings_response_STATUS_error, upstox_client_us_holdings_response_STATUS_partial_success } upstox_client_us_holdings_response_STATUS_e;

char* us_holdings_response_status_ToString(upstox_client_us_holdings_response_STATUS_e status);

upstox_client_us_holdings_response_STATUS_e us_holdings_response_status_FromString(char* status);



typedef struct us_holdings_response_t {
    upstox_client_us_holdings_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} us_holdings_response_t;

us_holdings_response_t *us_holdings_response_create(
    upstox_client_us_holdings_response_STATUS_e status,
    list_t *data
);

void us_holdings_response_free(us_holdings_response_t *us_holdings_response);

us_holdings_response_t *us_holdings_response_parseFromJSON(cJSON *us_holdings_responseJSON);

cJSON *us_holdings_response_convertToJSON(us_holdings_response_t *us_holdings_response);

#endif /* _us_holdings_response_H_ */

