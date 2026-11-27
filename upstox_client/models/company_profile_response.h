/*
 * company_profile_response.h
 *
 * 
 */

#ifndef _company_profile_response_H_
#define _company_profile_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct company_profile_response_t company_profile_response_t;

#include "company_profile_data.h"

// Enum STATUS for company_profile_response

typedef enum  { upstox_client_company_profile_response_STATUS_NULL = 0, upstox_client_company_profile_response_STATUS_success, upstox_client_company_profile_response_STATUS_error, upstox_client_company_profile_response_STATUS_partial_success } upstox_client_company_profile_response_STATUS_e;

char* company_profile_response_status_ToString(upstox_client_company_profile_response_STATUS_e status);

upstox_client_company_profile_response_STATUS_e company_profile_response_status_FromString(char* status);



typedef struct company_profile_response_t {
    upstox_client_company_profile_response_STATUS_e status; //enum
    struct company_profile_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} company_profile_response_t;

company_profile_response_t *company_profile_response_create(
    upstox_client_company_profile_response_STATUS_e status,
    company_profile_data_t *data
);

void company_profile_response_free(company_profile_response_t *company_profile_response);

company_profile_response_t *company_profile_response_parseFromJSON(cJSON *company_profile_responseJSON);

cJSON *company_profile_response_convertToJSON(company_profile_response_t *company_profile_response);

#endif /* _company_profile_response_H_ */

