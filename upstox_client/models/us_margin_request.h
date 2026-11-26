/*
 * us_margin_request.h
 *
 * 
 */

#ifndef _us_margin_request_H_
#define _us_margin_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_margin_request_t us_margin_request_t;

#include "us_order_estimate_request.h"



typedef struct us_margin_request_t {
    list_t *instruments; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} us_margin_request_t;

us_margin_request_t *us_margin_request_create(
    list_t *instruments
);

void us_margin_request_free(us_margin_request_t *us_margin_request);

us_margin_request_t *us_margin_request_parseFromJSON(cJSON *us_margin_requestJSON);

cJSON *us_margin_request_convertToJSON(us_margin_request_t *us_margin_request);

#endif /* _us_margin_request_H_ */

