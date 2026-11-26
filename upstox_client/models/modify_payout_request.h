/*
 * modify_payout_request.h
 *
 * 
 */

#ifndef _modify_payout_request_H_
#define _modify_payout_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct modify_payout_request_t modify_payout_request_t;




typedef struct modify_payout_request_t {
    double *amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} modify_payout_request_t;

modify_payout_request_t *modify_payout_request_create(
    double *amount
);

void modify_payout_request_free(modify_payout_request_t *modify_payout_request);

modify_payout_request_t *modify_payout_request_parseFromJSON(cJSON *modify_payout_requestJSON);

cJSON *modify_payout_request_convertToJSON(modify_payout_request_t *modify_payout_request);

#endif /* _modify_payout_request_H_ */

