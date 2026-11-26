/*
 * get_option_chain_response.h
 *
 * 
 */

#ifndef _get_option_chain_response_H_
#define _get_option_chain_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_option_chain_response_t get_option_chain_response_t;

#include "option_strike_data.h"

// Enum STATUS for get_option_chain_response

typedef enum  { upstox_client_get_option_chain_response_STATUS_NULL = 0, upstox_client_get_option_chain_response_STATUS_success, upstox_client_get_option_chain_response_STATUS_error, upstox_client_get_option_chain_response_STATUS_partial_success } upstox_client_get_option_chain_response_STATUS_e;

char* get_option_chain_response_status_ToString(upstox_client_get_option_chain_response_STATUS_e status);

upstox_client_get_option_chain_response_STATUS_e get_option_chain_response_status_FromString(char* status);



typedef struct get_option_chain_response_t {
    upstox_client_get_option_chain_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_option_chain_response_t;

get_option_chain_response_t *get_option_chain_response_create(
    upstox_client_get_option_chain_response_STATUS_e status,
    list_t *data
);

void get_option_chain_response_free(get_option_chain_response_t *get_option_chain_response);

get_option_chain_response_t *get_option_chain_response_parseFromJSON(cJSON *get_option_chain_responseJSON);

cJSON *get_option_chain_response_convertToJSON(get_option_chain_response_t *get_option_chain_response);

#endif /* _get_option_chain_response_H_ */

