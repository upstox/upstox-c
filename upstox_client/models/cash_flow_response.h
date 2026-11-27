/*
 * cash_flow_response.h
 *
 * 
 */

#ifndef _cash_flow_response_H_
#define _cash_flow_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_flow_response_t cash_flow_response_t;

#include "cash_flow_data.h"

// Enum STATUS for cash_flow_response

typedef enum  { upstox_client_cash_flow_response_STATUS_NULL = 0, upstox_client_cash_flow_response_STATUS_success, upstox_client_cash_flow_response_STATUS_error, upstox_client_cash_flow_response_STATUS_partial_success } upstox_client_cash_flow_response_STATUS_e;

char* cash_flow_response_status_ToString(upstox_client_cash_flow_response_STATUS_e status);

upstox_client_cash_flow_response_STATUS_e cash_flow_response_status_FromString(char* status);



typedef struct cash_flow_response_t {
    upstox_client_cash_flow_response_STATUS_e status; //enum
    struct cash_flow_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cash_flow_response_t;

cash_flow_response_t *cash_flow_response_create(
    upstox_client_cash_flow_response_STATUS_e status,
    cash_flow_data_t *data
);

void cash_flow_response_free(cash_flow_response_t *cash_flow_response);

cash_flow_response_t *cash_flow_response_parseFromJSON(cJSON *cash_flow_responseJSON);

cJSON *cash_flow_response_convertToJSON(cash_flow_response_t *cash_flow_response);

#endif /* _cash_flow_response_H_ */

