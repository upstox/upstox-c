/*
 * trade_history_response.h
 *
 * 
 */

#ifndef _trade_history_response_H_
#define _trade_history_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_history_response_t trade_history_response_t;

#include "trade_history_response_meta_data.h"
#include "trade_history_response_trade_data.h"

// Enum STATUS for trade_history_response

typedef enum  { upstox_client_trade_history_response_STATUS_NULL = 0, upstox_client_trade_history_response_STATUS_success, upstox_client_trade_history_response_STATUS_error, upstox_client_trade_history_response_STATUS_partial_success } upstox_client_trade_history_response_STATUS_e;

char* trade_history_response_status_ToString(upstox_client_trade_history_response_STATUS_e status);

upstox_client_trade_history_response_STATUS_e trade_history_response_status_FromString(char* status);



typedef struct trade_history_response_t {
    upstox_client_trade_history_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container
    struct trade_history_response_meta_data_t *meta_data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} trade_history_response_t;

trade_history_response_t *trade_history_response_create(
    upstox_client_trade_history_response_STATUS_e status,
    list_t *data,
    trade_history_response_meta_data_t *meta_data
);

void trade_history_response_free(trade_history_response_t *trade_history_response);

trade_history_response_t *trade_history_response_parseFromJSON(cJSON *trade_history_responseJSON);

cJSON *trade_history_response_convertToJSON(trade_history_response_t *trade_history_response);

#endif /* _trade_history_response_H_ */

