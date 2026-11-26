/*
 * competitors_response.h
 *
 * 
 */

#ifndef _competitors_response_H_
#define _competitors_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct competitors_response_t competitors_response_t;

#include "competitor_data.h"

// Enum STATUS for competitors_response

typedef enum  { upstox_client_competitors_response_STATUS_NULL = 0, upstox_client_competitors_response_STATUS_success, upstox_client_competitors_response_STATUS_error, upstox_client_competitors_response_STATUS_partial_success } upstox_client_competitors_response_STATUS_e;

char* competitors_response_status_ToString(upstox_client_competitors_response_STATUS_e status);

upstox_client_competitors_response_STATUS_e competitors_response_status_FromString(char* status);



typedef struct competitors_response_t {
    upstox_client_competitors_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} competitors_response_t;

competitors_response_t *competitors_response_create(
    upstox_client_competitors_response_STATUS_e status,
    list_t *data
);

void competitors_response_free(competitors_response_t *competitors_response);

competitors_response_t *competitors_response_parseFromJSON(cJSON *competitors_responseJSON);

cJSON *competitors_response_convertToJSON(competitors_response_t *competitors_response);

#endif /* _competitors_response_H_ */

