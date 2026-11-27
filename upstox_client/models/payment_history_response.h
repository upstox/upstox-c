/*
 * payment_history_response.h
 *
 * 
 */

#ifndef _payment_history_response_H_
#define _payment_history_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct payment_history_response_t payment_history_response_t;

#include "payment_history_data.h"

// Enum STATUS for payment_history_response

typedef enum  { upstox_client_payment_history_response_STATUS_NULL = 0, upstox_client_payment_history_response_STATUS_success, upstox_client_payment_history_response_STATUS_error, upstox_client_payment_history_response_STATUS_partial_success } upstox_client_payment_history_response_STATUS_e;

char* payment_history_response_status_ToString(upstox_client_payment_history_response_STATUS_e status);

upstox_client_payment_history_response_STATUS_e payment_history_response_status_FromString(char* status);



typedef struct payment_history_response_t {
    upstox_client_payment_history_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} payment_history_response_t;

payment_history_response_t *payment_history_response_create(
    upstox_client_payment_history_response_STATUS_e status,
    list_t *data
);

void payment_history_response_free(payment_history_response_t *payment_history_response);

payment_history_response_t *payment_history_response_parseFromJSON(cJSON *payment_history_responseJSON);

cJSON *payment_history_response_convertToJSON(payment_history_response_t *payment_history_response);

#endif /* _payment_history_response_H_ */

