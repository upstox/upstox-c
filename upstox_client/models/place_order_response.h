/*
 * place_order_response.h
 *
 * 
 */

#ifndef _place_order_response_H_
#define _place_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_order_response_t place_order_response_t;

#include "place_order_data.h"

// Enum STATUS for place_order_response

typedef enum  { upstox_client_place_order_response_STATUS_NULL = 0, upstox_client_place_order_response_STATUS_success, upstox_client_place_order_response_STATUS_error, upstox_client_place_order_response_STATUS_partial_success } upstox_client_place_order_response_STATUS_e;

char* place_order_response_status_ToString(upstox_client_place_order_response_STATUS_e status);

upstox_client_place_order_response_STATUS_e place_order_response_status_FromString(char* status);



typedef struct place_order_response_t {
    upstox_client_place_order_response_STATUS_e status; //enum
    struct place_order_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} place_order_response_t;

place_order_response_t *place_order_response_create(
    upstox_client_place_order_response_STATUS_e status,
    place_order_data_t *data
);

void place_order_response_free(place_order_response_t *place_order_response);

place_order_response_t *place_order_response_parseFromJSON(cJSON *place_order_responseJSON);

cJSON *place_order_response_convertToJSON(place_order_response_t *place_order_response);

#endif /* _place_order_response_H_ */

