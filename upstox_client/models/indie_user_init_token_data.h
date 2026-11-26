/*
 * indie_user_init_token_data.h
 *
 * 
 */

#ifndef _indie_user_init_token_data_H_
#define _indie_user_init_token_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct indie_user_init_token_data_t indie_user_init_token_data_t;




typedef struct indie_user_init_token_data_t {
    char *authorization_expiry; // string
    char *notifier_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} indie_user_init_token_data_t;

indie_user_init_token_data_t *indie_user_init_token_data_create(
    char *authorization_expiry,
    char *notifier_url
);

void indie_user_init_token_data_free(indie_user_init_token_data_t *indie_user_init_token_data);

indie_user_init_token_data_t *indie_user_init_token_data_parseFromJSON(cJSON *indie_user_init_token_dataJSON);

cJSON *indie_user_init_token_data_convertToJSON(indie_user_init_token_data_t *indie_user_init_token_data);

#endif /* _indie_user_init_token_data_H_ */

