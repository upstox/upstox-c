/*
 * us_place_order_request.h
 *
 * 
 */

#ifndef _us_place_order_request_H_
#define _us_place_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_place_order_request_t us_place_order_request_t;


// Enum VALIDITY for us_place_order_request

typedef enum  { upstox_client_us_place_order_request_VALIDITY_NULL = 0, upstox_client_us_place_order_request_VALIDITY_DAY } upstox_client_us_place_order_request_VALIDITY_e;

char* us_place_order_request_validity_ToString(upstox_client_us_place_order_request_VALIDITY_e validity);

upstox_client_us_place_order_request_VALIDITY_e us_place_order_request_validity_FromString(char* validity);

// Enum TRANSACTIONTYPE for us_place_order_request

typedef enum  { upstox_client_us_place_order_request_TRANSACTIONTYPE_NULL = 0, upstox_client_us_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_us_place_order_request_TRANSACTIONTYPE_SELL } upstox_client_us_place_order_request_TRANSACTIONTYPE_e;

char* us_place_order_request_transaction_type_ToString(upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_us_place_order_request_TRANSACTIONTYPE_e us_place_order_request_transaction_type_FromString(char* transaction_type);

// Enum ORDERTYPE for us_place_order_request

typedef enum  { upstox_client_us_place_order_request_ORDERTYPE_NULL = 0, upstox_client_us_place_order_request_ORDERTYPE_MARKET, upstox_client_us_place_order_request_ORDERTYPE_LIMIT } upstox_client_us_place_order_request_ORDERTYPE_e;

char* us_place_order_request_order_type_ToString(upstox_client_us_place_order_request_ORDERTYPE_e order_type);

upstox_client_us_place_order_request_ORDERTYPE_e us_place_order_request_order_type_FromString(char* order_type);



typedef struct us_place_order_request_t {
    double *quantity; //numeric
    double *amount; //numeric
    double *price; //numeric
    upstox_client_us_place_order_request_VALIDITY_e validity; //enum
    char *tag; // string
    char *instrument_key; // string
    upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type; //enum
    upstox_client_us_place_order_request_ORDERTYPE_e order_type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} us_place_order_request_t;

us_place_order_request_t *us_place_order_request_create(
    double *quantity,
    double *amount,
    double *price,
    upstox_client_us_place_order_request_VALIDITY_e validity,
    char *tag,
    char *instrument_key,
    upstox_client_us_place_order_request_TRANSACTIONTYPE_e transaction_type,
    upstox_client_us_place_order_request_ORDERTYPE_e order_type
);

void us_place_order_request_free(us_place_order_request_t *us_place_order_request);

us_place_order_request_t *us_place_order_request_parseFromJSON(cJSON *us_place_order_requestJSON);

cJSON *us_place_order_request_convertToJSON(us_place_order_request_t *us_place_order_request);

#endif /* _us_place_order_request_H_ */

