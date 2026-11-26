/*
 * get_position_response.h
 *
 * 
 */

#ifndef _get_position_response_H_
#define _get_position_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_position_response_t get_position_response_t;

#include "order_metadata.h"
#include "position_data.h"

// Enum STATUS for get_position_response

typedef enum  { upstox_client_get_position_response_STATUS_NULL = 0, upstox_client_get_position_response_STATUS_success, upstox_client_get_position_response_STATUS_error, upstox_client_get_position_response_STATUS_partial_success } upstox_client_get_position_response_STATUS_e;

char* get_position_response_status_ToString(upstox_client_get_position_response_STATUS_e status);

upstox_client_get_position_response_STATUS_e get_position_response_status_FromString(char* status);



typedef struct get_position_response_t {
    upstox_client_get_position_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container
    struct order_metadata_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_position_response_t;

get_position_response_t *get_position_response_create(
    upstox_client_get_position_response_STATUS_e status,
    list_t *data,
    order_metadata_t *metadata
);

void get_position_response_free(get_position_response_t *get_position_response);

get_position_response_t *get_position_response_parseFromJSON(cJSON *get_position_responseJSON);

cJSON *get_position_response_convertToJSON(get_position_response_t *get_position_response);

#endif /* _get_position_response_H_ */

