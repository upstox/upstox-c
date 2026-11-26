/*
 * payout_modes_response.h
 *
 * 
 */

#ifndef _payout_modes_response_H_
#define _payout_modes_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payout_modes_response_t payout_modes_response_t;

#include "object.h"

// Enum STATUS for payout_modes_response

typedef enum  { upstox_client_payout_modes_response_STATUS_NULL = 0, upstox_client_payout_modes_response_STATUS_success, upstox_client_payout_modes_response_STATUS_error, upstox_client_payout_modes_response_STATUS_partial_success } upstox_client_payout_modes_response_STATUS_e;

char* payout_modes_response_status_ToString(upstox_client_payout_modes_response_STATUS_e status);

upstox_client_payout_modes_response_STATUS_e payout_modes_response_status_FromString(char* status);



typedef struct payout_modes_response_t {
    upstox_client_payout_modes_response_STATUS_e status; //enum
    object_t *data; //object

    int _library_owned; // Is the library responsible for freeing this object?
} payout_modes_response_t;

payout_modes_response_t *payout_modes_response_create(
    upstox_client_payout_modes_response_STATUS_e status,
    object_t *data
);

void payout_modes_response_free(payout_modes_response_t *payout_modes_response);

payout_modes_response_t *payout_modes_response_parseFromJSON(cJSON *payout_modes_responseJSON);

cJSON *payout_modes_response_convertToJSON(payout_modes_response_t *payout_modes_response);

#endif /* _payout_modes_response_H_ */

