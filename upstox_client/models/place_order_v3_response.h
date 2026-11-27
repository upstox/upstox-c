/*
 * place_order_v3_response.h
 *
 * 
 */

#ifndef _place_order_v3_response_H_
#define _place_order_v3_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_order_v3_response_t place_order_v3_response_t;

#include "multi_order_v3_data.h"
#include "order_metadata.h"

// Enum STATUS for place_order_v3_response

typedef enum  { upstox_client_place_order_v3_response_STATUS_NULL = 0, upstox_client_place_order_v3_response_STATUS_success, upstox_client_place_order_v3_response_STATUS_error, upstox_client_place_order_v3_response_STATUS_partial_success } upstox_client_place_order_v3_response_STATUS_e;

char* place_order_v3_response_status_ToString(upstox_client_place_order_v3_response_STATUS_e status);

upstox_client_place_order_v3_response_STATUS_e place_order_v3_response_status_FromString(char* status);



typedef struct place_order_v3_response_t {
    upstox_client_place_order_v3_response_STATUS_e status; //enum
    struct multi_order_v3_data_t *data; //model
    struct order_metadata_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} place_order_v3_response_t;

place_order_v3_response_t *place_order_v3_response_create(
    upstox_client_place_order_v3_response_STATUS_e status,
    multi_order_v3_data_t *data,
    order_metadata_t *metadata
);

void place_order_v3_response_free(place_order_v3_response_t *place_order_v3_response);

place_order_v3_response_t *place_order_v3_response_parseFromJSON(cJSON *place_order_v3_responseJSON);

cJSON *place_order_v3_response_convertToJSON(place_order_v3_response_t *place_order_v3_response);

#endif /* _place_order_v3_response_H_ */

