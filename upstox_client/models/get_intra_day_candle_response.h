/*
 * get_intra_day_candle_response.h
 *
 * 
 */

#ifndef _get_intra_day_candle_response_H_
#define _get_intra_day_candle_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_intra_day_candle_response_t get_intra_day_candle_response_t;

#include "intra_day_candle_data.h"

// Enum STATUS for get_intra_day_candle_response

typedef enum  { upstox_client_get_intra_day_candle_response_STATUS_NULL = 0, upstox_client_get_intra_day_candle_response_STATUS_success, upstox_client_get_intra_day_candle_response_STATUS_error, upstox_client_get_intra_day_candle_response_STATUS_partial_success } upstox_client_get_intra_day_candle_response_STATUS_e;

char* get_intra_day_candle_response_status_ToString(upstox_client_get_intra_day_candle_response_STATUS_e status);

upstox_client_get_intra_day_candle_response_STATUS_e get_intra_day_candle_response_status_FromString(char* status);



typedef struct get_intra_day_candle_response_t {
    upstox_client_get_intra_day_candle_response_STATUS_e status; //enum
    struct intra_day_candle_data_t *data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} get_intra_day_candle_response_t;

get_intra_day_candle_response_t *get_intra_day_candle_response_create(
    upstox_client_get_intra_day_candle_response_STATUS_e status,
    intra_day_candle_data_t *data
);

void get_intra_day_candle_response_free(get_intra_day_candle_response_t *get_intra_day_candle_response);

get_intra_day_candle_response_t *get_intra_day_candle_response_parseFromJSON(cJSON *get_intra_day_candle_responseJSON);

cJSON *get_intra_day_candle_response_convertToJSON(get_intra_day_candle_response_t *get_intra_day_candle_response);

#endif /* _get_intra_day_candle_response_H_ */

