/*
 * gtt_modify_order_request.h
 *
 * 
 */

#ifndef _gtt_modify_order_request_H_
#define _gtt_modify_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_modify_order_request_t gtt_modify_order_request_t;

#include "gtt_rule.h"

// Enum TYPE for gtt_modify_order_request

typedef enum  { upstox_client_gtt_modify_order_request_TYPE_NULL = 0, upstox_client_gtt_modify_order_request_TYPE_SINGLE, upstox_client_gtt_modify_order_request_TYPE_MULTIPLE } upstox_client_gtt_modify_order_request_TYPE_e;

char* gtt_modify_order_request_type_ToString(upstox_client_gtt_modify_order_request_TYPE_e type);

upstox_client_gtt_modify_order_request_TYPE_e gtt_modify_order_request_type_FromString(char* type);



typedef struct gtt_modify_order_request_t {
    upstox_client_gtt_modify_order_request_TYPE_e type; //enum
    int *quantity; //numeric
    list_t *rules; //nonprimitive container
    char *gtt_order_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_modify_order_request_t;

gtt_modify_order_request_t *gtt_modify_order_request_create(
    upstox_client_gtt_modify_order_request_TYPE_e type,
    int *quantity,
    list_t *rules,
    char *gtt_order_id
);

void gtt_modify_order_request_free(gtt_modify_order_request_t *gtt_modify_order_request);

gtt_modify_order_request_t *gtt_modify_order_request_parseFromJSON(cJSON *gtt_modify_order_requestJSON);

cJSON *gtt_modify_order_request_convertToJSON(gtt_modify_order_request_t *gtt_modify_order_request);

#endif /* _gtt_modify_order_request_H_ */

