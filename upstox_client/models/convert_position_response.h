/*
 * convert_position_response.h
 *
 * 
 */

#ifndef _convert_position_response_H_
#define _convert_position_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_position_response_t convert_position_response_t;

#include "convert_position_data.h"
#include "problem.h"

// Enum STATUS for convert_position_response

typedef enum  { upstox_client_convert_position_response_STATUS_NULL = 0, upstox_client_convert_position_response_STATUS_success, upstox_client_convert_position_response_STATUS_error, upstox_client_convert_position_response_STATUS_partial_success } upstox_client_convert_position_response_STATUS_e;

char* convert_position_response_status_ToString(upstox_client_convert_position_response_STATUS_e status);

upstox_client_convert_position_response_STATUS_e convert_position_response_status_FromString(char* status);



typedef struct convert_position_response_t {
    upstox_client_convert_position_response_STATUS_e status; //enum
    struct convert_position_data_t *data; //model
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} convert_position_response_t;

convert_position_response_t *convert_position_response_create(
    upstox_client_convert_position_response_STATUS_e status,
    convert_position_data_t *data,
    list_t *errors
);

void convert_position_response_free(convert_position_response_t *convert_position_response);

convert_position_response_t *convert_position_response_parseFromJSON(cJSON *convert_position_responseJSON);

cJSON *convert_position_response_convertToJSON(convert_position_response_t *convert_position_response);

#endif /* _convert_position_response_H_ */

