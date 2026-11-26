/*
 * totp_pin_token_request.h
 *
 * 
 */

#ifndef _totp_pin_token_request_H_
#define _totp_pin_token_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_pin_token_request_t totp_pin_token_request_t;




typedef struct totp_pin_token_request_t {
    char *pin; // string
    char *totp; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_pin_token_request_t;

totp_pin_token_request_t *totp_pin_token_request_create(
    char *pin,
    char *totp
);

void totp_pin_token_request_free(totp_pin_token_request_t *totp_pin_token_request);

totp_pin_token_request_t *totp_pin_token_request_parseFromJSON(cJSON *totp_pin_token_requestJSON);

cJSON *totp_pin_token_request_convertToJSON(totp_pin_token_request_t *totp_pin_token_request);

#endif /* _totp_pin_token_request_H_ */

