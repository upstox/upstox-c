/*
 * place_order_request.h
 *
 * 
 */

#ifndef _place_order_request_H_
#define _place_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct place_order_request_t place_order_request_t;


// Enum PRODUCT for place_order_request

typedef enum  { upstox_client_place_order_request_PRODUCT_NULL = 0, upstox_client_place_order_request_PRODUCT_I, upstox_client_place_order_request_PRODUCT_D } upstox_client_place_order_request_PRODUCT_e;

char* place_order_request_product_ToString(upstox_client_place_order_request_PRODUCT_e product);

upstox_client_place_order_request_PRODUCT_e place_order_request_product_FromString(char* product);

// Enum VALIDITY for place_order_request

typedef enum  { upstox_client_place_order_request_VALIDITY_NULL = 0, upstox_client_place_order_request_VALIDITY_DAY, upstox_client_place_order_request_VALIDITY_IOC } upstox_client_place_order_request_VALIDITY_e;

char* place_order_request_validity_ToString(upstox_client_place_order_request_VALIDITY_e validity);

upstox_client_place_order_request_VALIDITY_e place_order_request_validity_FromString(char* validity);

// Enum ORDERTYPE for place_order_request

typedef enum  { upstox_client_place_order_request_ORDERTYPE_NULL = 0, upstox_client_place_order_request_ORDERTYPE_MARKET, upstox_client_place_order_request_ORDERTYPE_LIMIT, upstox_client_place_order_request_ORDERTYPE_SL, upstox_client_place_order_request_ORDERTYPE_SL_M } upstox_client_place_order_request_ORDERTYPE_e;

char* place_order_request_order_type_ToString(upstox_client_place_order_request_ORDERTYPE_e order_type);

upstox_client_place_order_request_ORDERTYPE_e place_order_request_order_type_FromString(char* order_type);

// Enum TRANSACTIONTYPE for place_order_request

typedef enum  { upstox_client_place_order_request_TRANSACTIONTYPE_NULL = 0, upstox_client_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_place_order_request_TRANSACTIONTYPE_SELL } upstox_client_place_order_request_TRANSACTIONTYPE_e;

char* place_order_request_transaction_type_ToString(upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_place_order_request_TRANSACTIONTYPE_e place_order_request_transaction_type_FromString(char* transaction_type);



typedef struct place_order_request_t {
    int *quantity; //numeric
    upstox_client_place_order_request_PRODUCT_e product; //enum
    upstox_client_place_order_request_VALIDITY_e validity; //enum
    double *price; //numeric
    char *tag; // string
    char *instrument_token; // string
    upstox_client_place_order_request_ORDERTYPE_e order_type; //enum
    upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type; //enum
    int *disclosed_quantity; //numeric
    double *trigger_price; //numeric
    int *is_amo; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} place_order_request_t;

place_order_request_t *place_order_request_create(
    int *quantity,
    upstox_client_place_order_request_PRODUCT_e product,
    upstox_client_place_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    char *instrument_token,
    upstox_client_place_order_request_ORDERTYPE_e order_type,
    upstox_client_place_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo
);

void place_order_request_free(place_order_request_t *place_order_request);

place_order_request_t *place_order_request_parseFromJSON(cJSON *place_order_requestJSON);

cJSON *place_order_request_convertToJSON(place_order_request_t *place_order_request);

#endif /* _place_order_request_H_ */

