/*
 * user_ip_response_data.h
 *
 * 
 */

#ifndef _user_ip_response_data_H_
#define _user_ip_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_ip_response_data_t user_ip_response_data_t;

#include "family_member_data.h"



typedef struct user_ip_response_data_t {
    char *primary_ip; // string
    char *secondary_ip; // string
    char *primary_ip_updated_at; // string
    char *secondary_ip_updated_at; // string
    list_t *primary_ip_family_members; //nonprimitive container
    list_t *secondary_ip_family_members; //nonprimitive container
    int *access_tokens_invalidated; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} user_ip_response_data_t;

user_ip_response_data_t *user_ip_response_data_create(
    char *primary_ip,
    char *secondary_ip,
    char *primary_ip_updated_at,
    char *secondary_ip_updated_at,
    list_t *primary_ip_family_members,
    list_t *secondary_ip_family_members,
    int *access_tokens_invalidated
);

void user_ip_response_data_free(user_ip_response_data_t *user_ip_response_data);

user_ip_response_data_t *user_ip_response_data_parseFromJSON(cJSON *user_ip_response_dataJSON);

cJSON *user_ip_response_data_convertToJSON(user_ip_response_data_t *user_ip_response_data);

#endif /* _user_ip_response_data_H_ */

