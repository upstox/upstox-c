/*
 * ipo_apply_response.h
 *
 * 
 */

#ifndef _ipo_apply_response_H_
#define _ipo_apply_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_apply_response_t ipo_apply_response_t;

#include "ipo_apply_data.h"

// Enum STATUS for ipo_apply_response

typedef enum  { upstox_client_ipo_apply_response_STATUS_NULL = 0, upstox_client_ipo_apply_response_STATUS_success, upstox_client_ipo_apply_response_STATUS_error, upstox_client_ipo_apply_response_STATUS_partial_success } upstox_client_ipo_apply_response_STATUS_e;

char* ipo_apply_response_status_ToString(upstox_client_ipo_apply_response_STATUS_e status);

upstox_client_ipo_apply_response_STATUS_e ipo_apply_response_status_FromString(char* status);



typedef struct ipo_apply_response_t {
    upstox_client_ipo_apply_response_STATUS_e status; //enum
    struct ipo_apply_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_apply_response_t;

ipo_apply_response_t *ipo_apply_response_create(
    upstox_client_ipo_apply_response_STATUS_e status,
    ipo_apply_data_t *data
);

void ipo_apply_response_free(ipo_apply_response_t *ipo_apply_response);

ipo_apply_response_t *ipo_apply_response_parseFromJSON(cJSON *ipo_apply_responseJSON);

cJSON *ipo_apply_response_convertToJSON(ipo_apply_response_t *ipo_apply_response);

#endif /* _ipo_apply_response_H_ */

