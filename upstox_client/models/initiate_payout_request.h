/*
 * initiate_payout_request.h
 *
 * 
 */

#ifndef _initiate_payout_request_H_
#define _initiate_payout_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct initiate_payout_request_t initiate_payout_request_t;




typedef struct initiate_payout_request_t {
    char *mode; // string
    double *amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} initiate_payout_request_t;

initiate_payout_request_t *initiate_payout_request_create(
    char *mode,
    double *amount
);

void initiate_payout_request_free(initiate_payout_request_t *initiate_payout_request);

initiate_payout_request_t *initiate_payout_request_parseFromJSON(cJSON *initiate_payout_requestJSON);

cJSON *initiate_payout_request_convertToJSON(initiate_payout_request_t *initiate_payout_request);

#endif /* _initiate_payout_request_H_ */

