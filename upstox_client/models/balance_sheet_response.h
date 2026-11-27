/*
 * balance_sheet_response.h
 *
 * 
 */

#ifndef _balance_sheet_response_H_
#define _balance_sheet_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct balance_sheet_response_t balance_sheet_response_t;

#include "balance_sheet_data.h"

// Enum STATUS for balance_sheet_response

typedef enum  { upstox_client_balance_sheet_response_STATUS_NULL = 0, upstox_client_balance_sheet_response_STATUS_success, upstox_client_balance_sheet_response_STATUS_error, upstox_client_balance_sheet_response_STATUS_partial_success } upstox_client_balance_sheet_response_STATUS_e;

char* balance_sheet_response_status_ToString(upstox_client_balance_sheet_response_STATUS_e status);

upstox_client_balance_sheet_response_STATUS_e balance_sheet_response_status_FromString(char* status);



typedef struct balance_sheet_response_t {
    upstox_client_balance_sheet_response_STATUS_e status; //enum
    struct balance_sheet_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} balance_sheet_response_t;

balance_sheet_response_t *balance_sheet_response_create(
    upstox_client_balance_sheet_response_STATUS_e status,
    balance_sheet_data_t *data
);

void balance_sheet_response_free(balance_sheet_response_t *balance_sheet_response);

balance_sheet_response_t *balance_sheet_response_parseFromJSON(cJSON *balance_sheet_responseJSON);

cJSON *balance_sheet_response_convertToJSON(balance_sheet_response_t *balance_sheet_response);

#endif /* _balance_sheet_response_H_ */

