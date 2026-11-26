/*
 * margin_request.h
 *
 * 
 */

#ifndef _margin_request_H_
#define _margin_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct margin_request_t margin_request_t;

#include "instrument.h"



typedef struct margin_request_t {
    list_t *instruments; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} margin_request_t;

margin_request_t *margin_request_create(
    list_t *instruments
);

void margin_request_free(margin_request_t *margin_request);

margin_request_t *margin_request_parseFromJSON(cJSON *margin_requestJSON);

cJSON *margin_request_convertToJSON(margin_request_t *margin_request);

#endif /* _margin_request_H_ */

