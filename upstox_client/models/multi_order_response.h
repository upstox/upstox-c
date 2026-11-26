/*
 * multi_order_response.h
 *
 * 
 */

#ifndef _multi_order_response_H_
#define _multi_order_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_response_t multi_order_response_t;

#include "multi_order_data.h"
#include "multi_order_error.h"
#include "multi_order_summary.h"

// Enum STATUS for multi_order_response

typedef enum  { upstox_client_multi_order_response_STATUS_NULL = 0, upstox_client_multi_order_response_STATUS_success, upstox_client_multi_order_response_STATUS_error, upstox_client_multi_order_response_STATUS_partial_success } upstox_client_multi_order_response_STATUS_e;

char* multi_order_response_status_ToString(upstox_client_multi_order_response_STATUS_e status);

upstox_client_multi_order_response_STATUS_e multi_order_response_status_FromString(char* status);



typedef struct multi_order_response_t {
    upstox_client_multi_order_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container
    list_t *errors; //nonprimitive container
    struct multi_order_summary_t *summary; //model

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_response_t;

multi_order_response_t *multi_order_response_create(
    upstox_client_multi_order_response_STATUS_e status,
    list_t *data,
    list_t *errors,
    multi_order_summary_t *summary
);

void multi_order_response_free(multi_order_response_t *multi_order_response);

multi_order_response_t *multi_order_response_parseFromJSON(cJSON *multi_order_responseJSON);

cJSON *multi_order_response_convertToJSON(multi_order_response_t *multi_order_response);

#endif /* _multi_order_response_H_ */

