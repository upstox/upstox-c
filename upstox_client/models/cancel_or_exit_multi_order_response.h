/*
 * cancel_or_exit_multi_order_response.h
 *
 * 
 */

#ifndef _cancel_or_exit_multi_order_response_H_
#define _cancel_or_exit_multi_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_or_exit_multi_order_response_t cancel_or_exit_multi_order_response_t;

#include "batch_execution_summary.h"
#include "cancel_or_exit_multi_order_data.h"
#include "cancel_or_exit_order_error_data.h"

// Enum STATUS for cancel_or_exit_multi_order_response

typedef enum  { upstox_client_cancel_or_exit_multi_order_response_STATUS_NULL = 0, upstox_client_cancel_or_exit_multi_order_response_STATUS_success, upstox_client_cancel_or_exit_multi_order_response_STATUS_error, upstox_client_cancel_or_exit_multi_order_response_STATUS_partial_success } upstox_client_cancel_or_exit_multi_order_response_STATUS_e;

char* cancel_or_exit_multi_order_response_status_ToString(upstox_client_cancel_or_exit_multi_order_response_STATUS_e status);

upstox_client_cancel_or_exit_multi_order_response_STATUS_e cancel_or_exit_multi_order_response_status_FromString(char* status);



typedef struct cancel_or_exit_multi_order_response_t {
    upstox_client_cancel_or_exit_multi_order_response_STATUS_e status; //enum
    struct cancel_or_exit_multi_order_data_t *data; //model
    list_t *errors; //nonprimitive container
    struct batch_execution_summary_t *summary; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_or_exit_multi_order_response_t;

cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_create(
    upstox_client_cancel_or_exit_multi_order_response_STATUS_e status,
    cancel_or_exit_multi_order_data_t *data,
    list_t *errors,
    batch_execution_summary_t *summary
);

void cancel_or_exit_multi_order_response_free(cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response);

cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response_parseFromJSON(cJSON *cancel_or_exit_multi_order_responseJSON);

cJSON *cancel_or_exit_multi_order_response_convertToJSON(cancel_or_exit_multi_order_response_t *cancel_or_exit_multi_order_response);

#endif /* _cancel_or_exit_multi_order_response_H_ */

