/*
 * get_expiries_response.h
 *
 * 
 */

#ifndef _get_expiries_response_H_
#define _get_expiries_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_expiries_response_t get_expiries_response_t;


// Enum STATUS for get_expiries_response

typedef enum  { upstox_client_get_expiries_response_STATUS_NULL = 0, upstox_client_get_expiries_response_STATUS_success, upstox_client_get_expiries_response_STATUS_error, upstox_client_get_expiries_response_STATUS_partial_success } upstox_client_get_expiries_response_STATUS_e;

char* get_expiries_response_status_ToString(upstox_client_get_expiries_response_STATUS_e status);

upstox_client_get_expiries_response_STATUS_e get_expiries_response_status_FromString(char* status);



typedef struct get_expiries_response_t {
    upstox_client_get_expiries_response_STATUS_e status; //enum
    list_t *data; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_expiries_response_t;

get_expiries_response_t *get_expiries_response_create(
    upstox_client_get_expiries_response_STATUS_e status,
    list_t *data
);

void get_expiries_response_free(get_expiries_response_t *get_expiries_response);

get_expiries_response_t *get_expiries_response_parseFromJSON(cJSON *get_expiries_responseJSON);

cJSON *get_expiries_response_convertToJSON(get_expiries_response_t *get_expiries_response);

#endif /* _get_expiries_response_H_ */

