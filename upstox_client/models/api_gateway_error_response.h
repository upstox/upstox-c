/*
 * api_gateway_error_response.h
 *
 * 
 */

#ifndef _api_gateway_error_response_H_
#define _api_gateway_error_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_gateway_error_response_t api_gateway_error_response_t;

#include "problem.h"

// Enum STATUS for api_gateway_error_response

typedef enum  { upstox_client_api_gateway_error_response_STATUS_NULL = 0, upstox_client_api_gateway_error_response_STATUS_success, upstox_client_api_gateway_error_response_STATUS_error, upstox_client_api_gateway_error_response_STATUS_partial_success } upstox_client_api_gateway_error_response_STATUS_e;

char* api_gateway_error_response_status_ToString(upstox_client_api_gateway_error_response_STATUS_e status);

upstox_client_api_gateway_error_response_STATUS_e api_gateway_error_response_status_FromString(char* status);



typedef struct api_gateway_error_response_t {
    upstox_client_api_gateway_error_response_STATUS_e status; //enum
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} api_gateway_error_response_t;

api_gateway_error_response_t *api_gateway_error_response_create(
    upstox_client_api_gateway_error_response_STATUS_e status,
    list_t *errors
);

void api_gateway_error_response_free(api_gateway_error_response_t *api_gateway_error_response);

api_gateway_error_response_t *api_gateway_error_response_parseFromJSON(cJSON *api_gateway_error_responseJSON);

cJSON *api_gateway_error_response_convertToJSON(api_gateway_error_response_t *api_gateway_error_response);

#endif /* _api_gateway_error_response_H_ */

