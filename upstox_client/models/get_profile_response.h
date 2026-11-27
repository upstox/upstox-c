/*
 * get_profile_response.h
 *
 * 
 */

#ifndef _get_profile_response_H_
#define _get_profile_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_profile_response_t get_profile_response_t;

#include "profile_data.h"

// Enum STATUS for get_profile_response

typedef enum  { upstox_client_get_profile_response_STATUS_NULL = 0, upstox_client_get_profile_response_STATUS_success, upstox_client_get_profile_response_STATUS_error, upstox_client_get_profile_response_STATUS_partial_success } upstox_client_get_profile_response_STATUS_e;

char* get_profile_response_status_ToString(upstox_client_get_profile_response_STATUS_e status);

upstox_client_get_profile_response_STATUS_e get_profile_response_status_FromString(char* status);



typedef struct get_profile_response_t {
    upstox_client_get_profile_response_STATUS_e status; //enum
    struct profile_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_profile_response_t;

get_profile_response_t *get_profile_response_create(
    upstox_client_get_profile_response_STATUS_e status,
    profile_data_t *data
);

void get_profile_response_free(get_profile_response_t *get_profile_response);

get_profile_response_t *get_profile_response_parseFromJSON(cJSON *get_profile_responseJSON);

cJSON *get_profile_response_convertToJSON(get_profile_response_t *get_profile_response);

#endif /* _get_profile_response_H_ */

