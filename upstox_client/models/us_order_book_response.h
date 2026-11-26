/*
 * us_order_book_response.h
 *
 * 
 */

#ifndef _us_order_book_response_H_
#define _us_order_book_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_book_response_t us_order_book_response_t;

#include "us_order_book_data.h"

// Enum STATUS for us_order_book_response

typedef enum  { upstox_client_us_order_book_response_STATUS_NULL = 0, upstox_client_us_order_book_response_STATUS_success, upstox_client_us_order_book_response_STATUS_error, upstox_client_us_order_book_response_STATUS_partial_success } upstox_client_us_order_book_response_STATUS_e;

char* us_order_book_response_status_ToString(upstox_client_us_order_book_response_STATUS_e status);

upstox_client_us_order_book_response_STATUS_e us_order_book_response_status_FromString(char* status);



typedef struct us_order_book_response_t {
    upstox_client_us_order_book_response_STATUS_e status; //enum
    list_t *data; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_book_response_t;

us_order_book_response_t *us_order_book_response_create(
    upstox_client_us_order_book_response_STATUS_e status,
    list_t *data
);

void us_order_book_response_free(us_order_book_response_t *us_order_book_response);

us_order_book_response_t *us_order_book_response_parseFromJSON(cJSON *us_order_book_responseJSON);

cJSON *us_order_book_response_convertToJSON(us_order_book_response_t *us_order_book_response);

#endif /* _us_order_book_response_H_ */

