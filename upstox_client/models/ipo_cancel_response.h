/*
 * ipo_cancel_response.h
 *
 * 
 */

#ifndef _ipo_cancel_response_H_
#define _ipo_cancel_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_cancel_response_t ipo_cancel_response_t;

#include "ipo_cancel_data.h"

// Enum STATUS for ipo_cancel_response

typedef enum  { upstox_client_ipo_cancel_response_STATUS_NULL = 0, upstox_client_ipo_cancel_response_STATUS_success, upstox_client_ipo_cancel_response_STATUS_error, upstox_client_ipo_cancel_response_STATUS_partial_success } upstox_client_ipo_cancel_response_STATUS_e;

char* ipo_cancel_response_status_ToString(upstox_client_ipo_cancel_response_STATUS_e status);

upstox_client_ipo_cancel_response_STATUS_e ipo_cancel_response_status_FromString(char* status);



typedef struct ipo_cancel_response_t {
    upstox_client_ipo_cancel_response_STATUS_e status; //enum
    struct ipo_cancel_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_cancel_response_t;

ipo_cancel_response_t *ipo_cancel_response_create(
    upstox_client_ipo_cancel_response_STATUS_e status,
    ipo_cancel_data_t *data
);

void ipo_cancel_response_free(ipo_cancel_response_t *ipo_cancel_response);

ipo_cancel_response_t *ipo_cancel_response_parseFromJSON(cJSON *ipo_cancel_responseJSON);

cJSON *ipo_cancel_response_convertToJSON(ipo_cancel_response_t *ipo_cancel_response);

#endif /* _ipo_cancel_response_H_ */

