/*
 * kill_switch_response.h
 *
 * 
 */

#ifndef _kill_switch_response_H_
#define _kill_switch_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kill_switch_response_t kill_switch_response_t;

#include "kill_switch_segment_data.h"

// Enum STATUS for kill_switch_response

typedef enum  { upstox_client_kill_switch_response_STATUS_NULL = 0, upstox_client_kill_switch_response_STATUS_success, upstox_client_kill_switch_response_STATUS_error, upstox_client_kill_switch_response_STATUS_partial_success } upstox_client_kill_switch_response_STATUS_e;

char* kill_switch_response_status_ToString(upstox_client_kill_switch_response_STATUS_e status);

upstox_client_kill_switch_response_STATUS_e kill_switch_response_status_FromString(char* status);



typedef struct kill_switch_response_t {
    upstox_client_kill_switch_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} kill_switch_response_t;

kill_switch_response_t *kill_switch_response_create(
    upstox_client_kill_switch_response_STATUS_e status,
    list_t *data
);

void kill_switch_response_free(kill_switch_response_t *kill_switch_response);

kill_switch_response_t *kill_switch_response_parseFromJSON(cJSON *kill_switch_responseJSON);

cJSON *kill_switch_response_convertToJSON(kill_switch_response_t *kill_switch_response);

#endif /* _kill_switch_response_H_ */

