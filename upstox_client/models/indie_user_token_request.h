/*
 * indie_user_token_request.h
 *
 * 
 */

#ifndef _indie_user_token_request_H_
#define _indie_user_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct indie_user_token_request_t indie_user_token_request_t;




typedef struct indie_user_token_request_t {
    char *client_id; // string
    char *client_secret; // string
    int *otp_verification_disabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} indie_user_token_request_t;

indie_user_token_request_t *indie_user_token_request_create(
    char *client_id,
    char *client_secret,
    int *otp_verification_disabled
);

void indie_user_token_request_free(indie_user_token_request_t *indie_user_token_request);

indie_user_token_request_t *indie_user_token_request_parseFromJSON(cJSON *indie_user_token_requestJSON);

cJSON *indie_user_token_request_convertToJSON(indie_user_token_request_t *indie_user_token_request);

#endif /* _indie_user_token_request_H_ */

