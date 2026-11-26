/*
 * user_ip_response.h
 *
 * 
 */

#ifndef _user_ip_response_H_
#define _user_ip_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_ip_response_t user_ip_response_t;

#include "user_ip_response_data.h"

// Enum STATUS for user_ip_response

typedef enum  { upstox_client_user_ip_response_STATUS_NULL = 0, upstox_client_user_ip_response_STATUS_success, upstox_client_user_ip_response_STATUS_error, upstox_client_user_ip_response_STATUS_partial_success } upstox_client_user_ip_response_STATUS_e;

char* user_ip_response_status_ToString(upstox_client_user_ip_response_STATUS_e status);

upstox_client_user_ip_response_STATUS_e user_ip_response_status_FromString(char* status);



typedef struct user_ip_response_t {
    upstox_client_user_ip_response_STATUS_e status; //enum
    struct user_ip_response_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} user_ip_response_t;

user_ip_response_t *user_ip_response_create(
    upstox_client_user_ip_response_STATUS_e status,
    user_ip_response_data_t *data
);

void user_ip_response_free(user_ip_response_t *user_ip_response);

user_ip_response_t *user_ip_response_parseFromJSON(cJSON *user_ip_responseJSON);

cJSON *user_ip_response_convertToJSON(user_ip_response_t *user_ip_response);

#endif /* _user_ip_response_H_ */

