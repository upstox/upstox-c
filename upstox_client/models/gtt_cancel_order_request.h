/*
 * gtt_cancel_order_request.h
 *
 * 
 */

#ifndef _gtt_cancel_order_request_H_
#define _gtt_cancel_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_cancel_order_request_t gtt_cancel_order_request_t;




typedef struct gtt_cancel_order_request_t {
    char *gtt_order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_cancel_order_request_t;

gtt_cancel_order_request_t *gtt_cancel_order_request_create(
    char *gtt_order_id
);

void gtt_cancel_order_request_free(gtt_cancel_order_request_t *gtt_cancel_order_request);

gtt_cancel_order_request_t *gtt_cancel_order_request_parseFromJSON(cJSON *gtt_cancel_order_requestJSON);

cJSON *gtt_cancel_order_request_convertToJSON(gtt_cancel_order_request_t *gtt_cancel_order_request);

#endif /* _gtt_cancel_order_request_H_ */

