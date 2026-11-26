/*
 * corporate_actions_response.h
 *
 * 
 */

#ifndef _corporate_actions_response_H_
#define _corporate_actions_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct corporate_actions_response_t corporate_actions_response_t;

#include "corporate_action_data.h"

// Enum STATUS for corporate_actions_response

typedef enum  { upstox_client_corporate_actions_response_STATUS_NULL = 0, upstox_client_corporate_actions_response_STATUS_success, upstox_client_corporate_actions_response_STATUS_error, upstox_client_corporate_actions_response_STATUS_partial_success } upstox_client_corporate_actions_response_STATUS_e;

char* corporate_actions_response_status_ToString(upstox_client_corporate_actions_response_STATUS_e status);

upstox_client_corporate_actions_response_STATUS_e corporate_actions_response_status_FromString(char* status);



typedef struct corporate_actions_response_t {
    upstox_client_corporate_actions_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} corporate_actions_response_t;

corporate_actions_response_t *corporate_actions_response_create(
    upstox_client_corporate_actions_response_STATUS_e status,
    list_t *data
);

void corporate_actions_response_free(corporate_actions_response_t *corporate_actions_response);

corporate_actions_response_t *corporate_actions_response_parseFromJSON(cJSON *corporate_actions_responseJSON);

cJSON *corporate_actions_response_convertToJSON(corporate_actions_response_t *corporate_actions_response);

#endif /* _corporate_actions_response_H_ */

