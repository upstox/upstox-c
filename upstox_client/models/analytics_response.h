/*
 * analytics_response.h
 *
 * 
 */

#ifndef _analytics_response_H_
#define _analytics_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct analytics_response_t analytics_response_t;

#include "object.h"

// Enum STATUS for analytics_response

typedef enum  { upstox_client_analytics_response_STATUS_NULL = 0, upstox_client_analytics_response_STATUS_success, upstox_client_analytics_response_STATUS_error, upstox_client_analytics_response_STATUS_partial_success } upstox_client_analytics_response_STATUS_e;

char* analytics_response_status_ToString(upstox_client_analytics_response_STATUS_e status);

upstox_client_analytics_response_STATUS_e analytics_response_status_FromString(char* status);



typedef struct analytics_response_t {
    upstox_client_analytics_response_STATUS_e status; //enum
    object_t *data; //object

    int _library_owned; // Is the library responsible for freeing this object?
} analytics_response_t;

analytics_response_t *analytics_response_create(
    upstox_client_analytics_response_STATUS_e status,
    object_t *data
);

void analytics_response_free(analytics_response_t *analytics_response);

analytics_response_t *analytics_response_parseFromJSON(cJSON *analytics_responseJSON);

cJSON *analytics_response_convertToJSON(analytics_response_t *analytics_response);

#endif /* _analytics_response_H_ */

