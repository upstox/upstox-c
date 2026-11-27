/*
 * ipo_bid_request.h
 *
 * 
 */

#ifndef _ipo_bid_request_H_
#define _ipo_bid_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_bid_request_t ipo_bid_request_t;




typedef struct ipo_bid_request_t {
    int *quantity; //numeric
    double *price; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_bid_request_t;

ipo_bid_request_t *ipo_bid_request_create(
    int *quantity,
    double *price
);

void ipo_bid_request_free(ipo_bid_request_t *ipo_bid_request);

ipo_bid_request_t *ipo_bid_request_parseFromJSON(cJSON *ipo_bid_requestJSON);

cJSON *ipo_bid_request_convertToJSON(ipo_bid_request_t *ipo_bid_request);

#endif /* _ipo_bid_request_H_ */

