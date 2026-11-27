/*
 * ipo_apply_request.h
 *
 * 
 */

#ifndef _ipo_apply_request_H_
#define _ipo_apply_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_apply_request_t ipo_apply_request_t;

#include "ipo_bid_request.h"

// Enum CATEGORY for ipo_apply_request

typedef enum  { upstox_client_ipo_apply_request_CATEGORY_NULL = 0, upstox_client_ipo_apply_request_CATEGORY_IND, upstox_client_ipo_apply_request_CATEGORY_HNI } upstox_client_ipo_apply_request_CATEGORY_e;

char* ipo_apply_request_category_ToString(upstox_client_ipo_apply_request_CATEGORY_e category);

upstox_client_ipo_apply_request_CATEGORY_e ipo_apply_request_category_FromString(char* category);



typedef struct ipo_apply_request_t {
    char *id; // string
    char *upi; // string
    upstox_client_ipo_apply_request_CATEGORY_e category; //enum
    list_t *bids; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_apply_request_t;

ipo_apply_request_t *ipo_apply_request_create(
    char *id,
    char *upi,
    upstox_client_ipo_apply_request_CATEGORY_e category,
    list_t *bids
);

void ipo_apply_request_free(ipo_apply_request_t *ipo_apply_request);

ipo_apply_request_t *ipo_apply_request_parseFromJSON(cJSON *ipo_apply_requestJSON);

cJSON *ipo_apply_request_convertToJSON(ipo_apply_request_t *ipo_apply_request);

#endif /* _ipo_apply_request_H_ */

