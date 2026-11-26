/*
 * websocket_auth_redirect_response.h
 *
 * 
 */

#ifndef _websocket_auth_redirect_response_H_
#define _websocket_auth_redirect_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct websocket_auth_redirect_response_t websocket_auth_redirect_response_t;

#include "websocket_auth_redirect_response_data.h"

// Enum STATUS for websocket_auth_redirect_response

typedef enum  { upstox_client_websocket_auth_redirect_response_STATUS_NULL = 0, upstox_client_websocket_auth_redirect_response_STATUS_success, upstox_client_websocket_auth_redirect_response_STATUS_error, upstox_client_websocket_auth_redirect_response_STATUS_partial_success } upstox_client_websocket_auth_redirect_response_STATUS_e;

char* websocket_auth_redirect_response_status_ToString(upstox_client_websocket_auth_redirect_response_STATUS_e status);

upstox_client_websocket_auth_redirect_response_STATUS_e websocket_auth_redirect_response_status_FromString(char* status);



typedef struct websocket_auth_redirect_response_t {
    upstox_client_websocket_auth_redirect_response_STATUS_e status; //enum
    struct websocket_auth_redirect_response_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} websocket_auth_redirect_response_t;

websocket_auth_redirect_response_t *websocket_auth_redirect_response_create(
    upstox_client_websocket_auth_redirect_response_STATUS_e status,
    websocket_auth_redirect_response_data_t *data
);

void websocket_auth_redirect_response_free(websocket_auth_redirect_response_t *websocket_auth_redirect_response);

websocket_auth_redirect_response_t *websocket_auth_redirect_response_parseFromJSON(cJSON *websocket_auth_redirect_responseJSON);

cJSON *websocket_auth_redirect_response_convertToJSON(websocket_auth_redirect_response_t *websocket_auth_redirect_response);

#endif /* _websocket_auth_redirect_response_H_ */

