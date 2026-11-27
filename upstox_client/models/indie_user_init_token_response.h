/*
 * indie_user_init_token_response.h
 *
 * 
 */

#ifndef _indie_user_init_token_response_H_
#define _indie_user_init_token_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct indie_user_init_token_response_t indie_user_init_token_response_t;

#include "indie_user_init_token_data.h"



typedef struct indie_user_init_token_response_t {
    char *status; // string
    struct indie_user_init_token_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} indie_user_init_token_response_t;

indie_user_init_token_response_t *indie_user_init_token_response_create(
    char *status,
    indie_user_init_token_data_t *data
);

void indie_user_init_token_response_free(indie_user_init_token_response_t *indie_user_init_token_response);

indie_user_init_token_response_t *indie_user_init_token_response_parseFromJSON(cJSON *indie_user_init_token_responseJSON);

cJSON *indie_user_init_token_response_convertToJSON(indie_user_init_token_response_t *indie_user_init_token_response);

#endif /* _indie_user_init_token_response_H_ */

