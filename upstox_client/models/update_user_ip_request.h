/*
 * update_user_ip_request.h
 *
 * 
 */

#ifndef _update_user_ip_request_H_
#define _update_user_ip_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_user_ip_request_t update_user_ip_request_t;




typedef struct update_user_ip_request_t {
    char *primary_ip; // string
    char *secondary_ip; // string

    int _library_owned; // Is the library responsible for freeing this object?
} update_user_ip_request_t;

update_user_ip_request_t *update_user_ip_request_create(
    char *primary_ip,
    char *secondary_ip
);

void update_user_ip_request_free(update_user_ip_request_t *update_user_ip_request);

update_user_ip_request_t *update_user_ip_request_parseFromJSON(cJSON *update_user_ip_requestJSON);

cJSON *update_user_ip_request_convertToJSON(update_user_ip_request_t *update_user_ip_request);

#endif /* _update_user_ip_request_H_ */

