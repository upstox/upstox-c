/*
 * modify_order_v3_response.h
 *
 * 
 */

#ifndef _modify_order_v3_response_H_
#define _modify_order_v3_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct modify_order_v3_response_t modify_order_v3_response_t;

#include "modify_order_data.h"
#include "order_metadata.h"

// Enum STATUS for modify_order_v3_response

typedef enum  { upstox_client_modify_order_v3_response_STATUS_NULL = 0, upstox_client_modify_order_v3_response_STATUS_success, upstox_client_modify_order_v3_response_STATUS_error, upstox_client_modify_order_v3_response_STATUS_partial_success } upstox_client_modify_order_v3_response_STATUS_e;

char* modify_order_v3_response_status_ToString(upstox_client_modify_order_v3_response_STATUS_e status);

upstox_client_modify_order_v3_response_STATUS_e modify_order_v3_response_status_FromString(char* status);



typedef struct modify_order_v3_response_t {
    upstox_client_modify_order_v3_response_STATUS_e status; //enum
    struct modify_order_data_t *data; //model
    struct order_metadata_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} modify_order_v3_response_t;

modify_order_v3_response_t *modify_order_v3_response_create(
    upstox_client_modify_order_v3_response_STATUS_e status,
    modify_order_data_t *data,
    order_metadata_t *metadata
);

void modify_order_v3_response_free(modify_order_v3_response_t *modify_order_v3_response);

modify_order_v3_response_t *modify_order_v3_response_parseFromJSON(cJSON *modify_order_v3_responseJSON);

cJSON *modify_order_v3_response_convertToJSON(modify_order_v3_response_t *modify_order_v3_response);

#endif /* _modify_order_v3_response_H_ */

