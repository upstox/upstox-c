/*
 * get_user_fund_margin_v3_response.h
 *
 * 
 */

#ifndef _get_user_fund_margin_v3_response_H_
#define _get_user_fund_margin_v3_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_user_fund_margin_v3_response_t get_user_fund_margin_v3_response_t;

#include "user_fund_margin_v3_data.h"

// Enum STATUS for get_user_fund_margin_v3_response

typedef enum  { upstox_client_get_user_fund_margin_v3_response_STATUS_NULL = 0, upstox_client_get_user_fund_margin_v3_response_STATUS_success, upstox_client_get_user_fund_margin_v3_response_STATUS_error, upstox_client_get_user_fund_margin_v3_response_STATUS_partial_success } upstox_client_get_user_fund_margin_v3_response_STATUS_e;

char* get_user_fund_margin_v3_response_status_ToString(upstox_client_get_user_fund_margin_v3_response_STATUS_e status);

upstox_client_get_user_fund_margin_v3_response_STATUS_e get_user_fund_margin_v3_response_status_FromString(char* status);



typedef struct get_user_fund_margin_v3_response_t {
    upstox_client_get_user_fund_margin_v3_response_STATUS_e status; //enum
    struct user_fund_margin_v3_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_user_fund_margin_v3_response_t;

get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_create(
    upstox_client_get_user_fund_margin_v3_response_STATUS_e status,
    user_fund_margin_v3_data_t *data
);

void get_user_fund_margin_v3_response_free(get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response);

get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response_parseFromJSON(cJSON *get_user_fund_margin_v3_responseJSON);

cJSON *get_user_fund_margin_v3_response_convertToJSON(get_user_fund_margin_v3_response_t *get_user_fund_margin_v3_response);

#endif /* _get_user_fund_margin_v3_response_H_ */

