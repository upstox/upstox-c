/*
 * get_order_response.h
 *
 * 
 */

#ifndef _get_order_response_H_
#define _get_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_order_response_t get_order_response_t;

#include "order_data.h"

// Enum STATUS for get_order_response

typedef enum  { upstox_client_get_order_response_STATUS_NULL = 0, upstox_client_get_order_response_STATUS_success, upstox_client_get_order_response_STATUS_error, upstox_client_get_order_response_STATUS_partial_success } upstox_client_get_order_response_STATUS_e;

char* get_order_response_status_ToString(upstox_client_get_order_response_STATUS_e status);

upstox_client_get_order_response_STATUS_e get_order_response_status_FromString(char* status);



typedef struct get_order_response_t {
    upstox_client_get_order_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} get_order_response_t;

get_order_response_t *get_order_response_create(
    upstox_client_get_order_response_STATUS_e status,
    list_t *data
);

void get_order_response_free(get_order_response_t *get_order_response);

get_order_response_t *get_order_response_parseFromJSON(cJSON *get_order_responseJSON);

cJSON *get_order_response_convertToJSON(get_order_response_t *get_order_response);

#endif /* _get_order_response_H_ */

