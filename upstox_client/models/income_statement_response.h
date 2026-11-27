/*
 * income_statement_response.h
 *
 * 
 */

#ifndef _income_statement_response_H_
#define _income_statement_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct income_statement_response_t income_statement_response_t;

#include "income_statement_data.h"

// Enum STATUS for income_statement_response

typedef enum  { upstox_client_income_statement_response_STATUS_NULL = 0, upstox_client_income_statement_response_STATUS_success, upstox_client_income_statement_response_STATUS_error, upstox_client_income_statement_response_STATUS_partial_success } upstox_client_income_statement_response_STATUS_e;

char* income_statement_response_status_ToString(upstox_client_income_statement_response_STATUS_e status);

upstox_client_income_statement_response_STATUS_e income_statement_response_status_FromString(char* status);



typedef struct income_statement_response_t {
    upstox_client_income_statement_response_STATUS_e status; //enum
    struct income_statement_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} income_statement_response_t;

income_statement_response_t *income_statement_response_create(
    upstox_client_income_statement_response_STATUS_e status,
    income_statement_data_t *data
);

void income_statement_response_free(income_statement_response_t *income_statement_response);

income_statement_response_t *income_statement_response_parseFromJSON(cJSON *income_statement_responseJSON);

cJSON *income_statement_response_convertToJSON(income_statement_response_t *income_statement_response);

#endif /* _income_statement_response_H_ */

