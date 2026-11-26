/*
 * websocket_auth_redirect_response_data.h
 *
 * 
 */

#ifndef _websocket_auth_redirect_response_data_H_
#define _websocket_auth_redirect_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct websocket_auth_redirect_response_data_t websocket_auth_redirect_response_data_t;




typedef struct websocket_auth_redirect_response_data_t {
    char *authorized_redirect_uri; // string

    int _library_owned; // Is the library responsible for freeing this object?
} websocket_auth_redirect_response_data_t;

websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_create(
    char *authorized_redirect_uri
);

void websocket_auth_redirect_response_data_free(websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data);

websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_parseFromJSON(cJSON *websocket_auth_redirect_response_dataJSON);

cJSON *websocket_auth_redirect_response_data_convertToJSON(websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data);

#endif /* _websocket_auth_redirect_response_data_H_ */

