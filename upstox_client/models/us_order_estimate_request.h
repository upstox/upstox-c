/*
 * us_order_estimate_request.h
 *
 * 
 */

#ifndef _us_order_estimate_request_H_
#define _us_order_estimate_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_estimate_request_t us_order_estimate_request_t;


// Enum TRANSACTIONTYPE for us_order_estimate_request

typedef enum  { upstox_client_us_order_estimate_request_TRANSACTIONTYPE_NULL = 0, upstox_client_us_order_estimate_request_TRANSACTIONTYPE_BUY, upstox_client_us_order_estimate_request_TRANSACTIONTYPE_SELL } upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e;

char* us_order_estimate_request_transaction_type_ToString(upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e us_order_estimate_request_transaction_type_FromString(char* transaction_type);

// Enum ORDERTYPE for us_order_estimate_request

typedef enum  { upstox_client_us_order_estimate_request_ORDERTYPE_NULL = 0, upstox_client_us_order_estimate_request_ORDERTYPE_MARKET, upstox_client_us_order_estimate_request_ORDERTYPE_LIMIT } upstox_client_us_order_estimate_request_ORDERTYPE_e;

char* us_order_estimate_request_order_type_ToString(upstox_client_us_order_estimate_request_ORDERTYPE_e order_type);

upstox_client_us_order_estimate_request_ORDERTYPE_e us_order_estimate_request_order_type_FromString(char* order_type);



typedef struct us_order_estimate_request_t {
    double *quantity; //numeric
    double *price; //numeric
    char *instrument_key; // string
    upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type; //enum
    upstox_client_us_order_estimate_request_ORDERTYPE_e order_type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_estimate_request_t;

us_order_estimate_request_t *us_order_estimate_request_create(
    double *quantity,
    double *price,
    char *instrument_key,
    upstox_client_us_order_estimate_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_order_estimate_request_ORDERTYPE_e order_type
);

void us_order_estimate_request_free(us_order_estimate_request_t *us_order_estimate_request);

us_order_estimate_request_t *us_order_estimate_request_parseFromJSON(cJSON *us_order_estimate_requestJSON);

cJSON *us_order_estimate_request_convertToJSON(us_order_estimate_request_t *us_order_estimate_request);

#endif /* _us_order_estimate_request_H_ */

