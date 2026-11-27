/*
 * get_profit_and_loss_charges_response.h
 *
 * 
 */

#ifndef _get_profit_and_loss_charges_response_H_
#define _get_profit_and_loss_charges_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_profit_and_loss_charges_response_t get_profit_and_loss_charges_response_t;

#include "profit_and_loss_charges_wrapper_data.h"

// Enum STATUS for get_profit_and_loss_charges_response

typedef enum  { upstox_client_get_profit_and_loss_charges_response_STATUS_NULL = 0, upstox_client_get_profit_and_loss_charges_response_STATUS_success, upstox_client_get_profit_and_loss_charges_response_STATUS_error, upstox_client_get_profit_and_loss_charges_response_STATUS_partial_success } upstox_client_get_profit_and_loss_charges_response_STATUS_e;

char* get_profit_and_loss_charges_response_status_ToString(upstox_client_get_profit_and_loss_charges_response_STATUS_e status);

upstox_client_get_profit_and_loss_charges_response_STATUS_e get_profit_and_loss_charges_response_status_FromString(char* status);



typedef struct get_profit_and_loss_charges_response_t {
    upstox_client_get_profit_and_loss_charges_response_STATUS_e status; //enum
    struct profit_and_loss_charges_wrapper_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_profit_and_loss_charges_response_t;

get_profit_and_loss_charges_response_t *get_profit_and_loss_charges_response_create(
    upstox_client_get_profit_and_loss_charges_response_STATUS_e status,
    profit_and_loss_charges_wrapper_data_t *data
);

void get_profit_and_loss_charges_response_free(get_profit_and_loss_charges_response_t *get_profit_and_loss_charges_response);

get_profit_and_loss_charges_response_t *get_profit_and_loss_charges_response_parseFromJSON(cJSON *get_profit_and_loss_charges_responseJSON);

cJSON *get_profit_and_loss_charges_response_convertToJSON(get_profit_and_loss_charges_response_t *get_profit_and_loss_charges_response);

#endif /* _get_profit_and_loss_charges_response_H_ */

