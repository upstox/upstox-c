/*
 * cancel_order_v3_response.h
 *
 * 
 */

#ifndef _cancel_order_v3_response_H_
#define _cancel_order_v3_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_order_v3_response_t cancel_order_v3_response_t;

#include "cancel_order_data.h"
#include "order_metadata.h"

// Enum STATUS for cancel_order_v3_response

typedef enum  { upstox_client_cancel_order_v3_response_STATUS_NULL = 0, upstox_client_cancel_order_v3_response_STATUS_success, upstox_client_cancel_order_v3_response_STATUS_error, upstox_client_cancel_order_v3_response_STATUS_partial_success } upstox_client_cancel_order_v3_response_STATUS_e;

char* cancel_order_v3_response_status_ToString(upstox_client_cancel_order_v3_response_STATUS_e status);

upstox_client_cancel_order_v3_response_STATUS_e cancel_order_v3_response_status_FromString(char* status);



typedef struct cancel_order_v3_response_t {
    upstox_client_cancel_order_v3_response_STATUS_e status; //enum
    struct cancel_order_data_t *data; //model
    struct order_metadata_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_order_v3_response_t;

cancel_order_v3_response_t *cancel_order_v3_response_create(
    upstox_client_cancel_order_v3_response_STATUS_e status,
    cancel_order_data_t *data,
    order_metadata_t *metadata
);

void cancel_order_v3_response_free(cancel_order_v3_response_t *cancel_order_v3_response);

cancel_order_v3_response_t *cancel_order_v3_response_parseFromJSON(cJSON *cancel_order_v3_responseJSON);

cJSON *cancel_order_v3_response_convertToJSON(cancel_order_v3_response_t *cancel_order_v3_response);

#endif /* _cancel_order_v3_response_H_ */

