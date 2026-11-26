/*
 * post_margin_response.h
 *
 * 
 */

#ifndef _post_margin_response_H_
#define _post_margin_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_margin_response_t post_margin_response_t;

#include "margin_data.h"

// Enum STATUS for post_margin_response

typedef enum  { upstox_client_post_margin_response_STATUS_NULL = 0, upstox_client_post_margin_response_STATUS_success, upstox_client_post_margin_response_STATUS_error, upstox_client_post_margin_response_STATUS_partial_success } upstox_client_post_margin_response_STATUS_e;

char* post_margin_response_status_ToString(upstox_client_post_margin_response_STATUS_e status);

upstox_client_post_margin_response_STATUS_e post_margin_response_status_FromString(char* status);



typedef struct post_margin_response_t {
    upstox_client_post_margin_response_STATUS_e status; //enum
    struct margin_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} post_margin_response_t;

post_margin_response_t *post_margin_response_create(
    upstox_client_post_margin_response_STATUS_e status,
    margin_data_t *data
);

void post_margin_response_free(post_margin_response_t *post_margin_response);

post_margin_response_t *post_margin_response_parseFromJSON(cJSON *post_margin_responseJSON);

cJSON *post_margin_response_convertToJSON(post_margin_response_t *post_margin_response);

#endif /* _post_margin_response_H_ */

