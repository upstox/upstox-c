/*
 * gtt_trigger_order_response.h
 *
 * 
 */

#ifndef _gtt_trigger_order_response_H_
#define _gtt_trigger_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_trigger_order_response_t gtt_trigger_order_response_t;

#include "gtt_order_data.h"
#include "order_metadata.h"

// Enum STATUS for gtt_trigger_order_response

typedef enum  { upstox_client_gtt_trigger_order_response_STATUS_NULL = 0, upstox_client_gtt_trigger_order_response_STATUS_success, upstox_client_gtt_trigger_order_response_STATUS_error, upstox_client_gtt_trigger_order_response_STATUS_partial_success } upstox_client_gtt_trigger_order_response_STATUS_e;

char* gtt_trigger_order_response_status_ToString(upstox_client_gtt_trigger_order_response_STATUS_e status);

upstox_client_gtt_trigger_order_response_STATUS_e gtt_trigger_order_response_status_FromString(char* status);



typedef struct gtt_trigger_order_response_t {
    upstox_client_gtt_trigger_order_response_STATUS_e status; //enum
    struct gtt_order_data_t *data; //model
    struct order_metadata_t *metadata; //model

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_trigger_order_response_t;

gtt_trigger_order_response_t *gtt_trigger_order_response_create(
    upstox_client_gtt_trigger_order_response_STATUS_e status,
    gtt_order_data_t *data,
    order_metadata_t *metadata
);

void gtt_trigger_order_response_free(gtt_trigger_order_response_t *gtt_trigger_order_response);

gtt_trigger_order_response_t *gtt_trigger_order_response_parseFromJSON(cJSON *gtt_trigger_order_responseJSON);

cJSON *gtt_trigger_order_response_convertToJSON(gtt_trigger_order_response_t *gtt_trigger_order_response);

#endif /* _gtt_trigger_order_response_H_ */

