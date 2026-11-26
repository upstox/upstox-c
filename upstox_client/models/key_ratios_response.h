/*
 * key_ratios_response.h
 *
 * 
 */

#ifndef _key_ratios_response_H_
#define _key_ratios_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct key_ratios_response_t key_ratios_response_t;

#include "key_ratio_data.h"

// Enum STATUS for key_ratios_response

typedef enum  { upstox_client_key_ratios_response_STATUS_NULL = 0, upstox_client_key_ratios_response_STATUS_success, upstox_client_key_ratios_response_STATUS_error, upstox_client_key_ratios_response_STATUS_partial_success } upstox_client_key_ratios_response_STATUS_e;

char* key_ratios_response_status_ToString(upstox_client_key_ratios_response_STATUS_e status);

upstox_client_key_ratios_response_STATUS_e key_ratios_response_status_FromString(char* status);



typedef struct key_ratios_response_t {
    upstox_client_key_ratios_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} key_ratios_response_t;

key_ratios_response_t *key_ratios_response_create(
    upstox_client_key_ratios_response_STATUS_e status,
    list_t *data
);

void key_ratios_response_free(key_ratios_response_t *key_ratios_response);

key_ratios_response_t *key_ratios_response_parseFromJSON(cJSON *key_ratios_responseJSON);

cJSON *key_ratios_response_convertToJSON(key_ratios_response_t *key_ratios_response);

#endif /* _key_ratios_response_H_ */

