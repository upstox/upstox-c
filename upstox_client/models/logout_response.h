/*
 * logout_response.h
 *
 * 
 */

#ifndef _logout_response_H_
#define _logout_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct logout_response_t logout_response_t;


// Enum STATUS for logout_response

typedef enum  { upstox_client_logout_response_STATUS_NULL = 0, upstox_client_logout_response_STATUS_success, upstox_client_logout_response_STATUS_error, upstox_client_logout_response_STATUS_partial_success } upstox_client_logout_response_STATUS_e;

char* logout_response_status_ToString(upstox_client_logout_response_STATUS_e status);

upstox_client_logout_response_STATUS_e logout_response_status_FromString(char* status);



typedef struct logout_response_t {
    upstox_client_logout_response_STATUS_e status; //enum
    int *data; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} logout_response_t;

logout_response_t *logout_response_create(
    upstox_client_logout_response_STATUS_e status,
    int *data
);

void logout_response_free(logout_response_t *logout_response);

logout_response_t *logout_response_parseFromJSON(cJSON *logout_responseJSON);

cJSON *logout_response_convertToJSON(logout_response_t *logout_response);

#endif /* _logout_response_H_ */

