/*
 * ipo_listing_response.h
 *
 * 
 */

#ifndef _ipo_listing_response_H_
#define _ipo_listing_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipo_listing_response_t ipo_listing_response_t;

#include "ipo_listing_data.h"
#include "ipo_meta_data.h"

// Enum STATUS for ipo_listing_response

typedef enum  { upstox_client_ipo_listing_response_STATUS_NULL = 0, upstox_client_ipo_listing_response_STATUS_success, upstox_client_ipo_listing_response_STATUS_error, upstox_client_ipo_listing_response_STATUS_partial_success } upstox_client_ipo_listing_response_STATUS_e;

char* ipo_listing_response_status_ToString(upstox_client_ipo_listing_response_STATUS_e status);

upstox_client_ipo_listing_response_STATUS_e ipo_listing_response_status_FromString(char* status);



typedef struct ipo_listing_response_t {
    upstox_client_ipo_listing_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container
    struct ipo_meta_data_t *meta_data; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ipo_listing_response_t;

ipo_listing_response_t *ipo_listing_response_create(
    upstox_client_ipo_listing_response_STATUS_e status,
    list_t *data,
    ipo_meta_data_t *meta_data
);

void ipo_listing_response_free(ipo_listing_response_t *ipo_listing_response);

ipo_listing_response_t *ipo_listing_response_parseFromJSON(cJSON *ipo_listing_responseJSON);

cJSON *ipo_listing_response_convertToJSON(ipo_listing_response_t *ipo_listing_response);

#endif /* _ipo_listing_response_H_ */

