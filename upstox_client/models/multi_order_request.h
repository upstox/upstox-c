/*
 * multi_order_request.h
 *
 * 
 */

#ifndef _multi_order_request_H_
#define _multi_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_request_t multi_order_request_t;


// Enum PRODUCT for multi_order_request

typedef enum  { upstox_client_multi_order_request_PRODUCT_NULL = 0, upstox_client_multi_order_request_PRODUCT_I, upstox_client_multi_order_request_PRODUCT_D } upstox_client_multi_order_request_PRODUCT_e;

char* multi_order_request_product_ToString(upstox_client_multi_order_request_PRODUCT_e product);

upstox_client_multi_order_request_PRODUCT_e multi_order_request_product_FromString(char* product);

// Enum VALIDITY for multi_order_request

typedef enum  { upstox_client_multi_order_request_VALIDITY_NULL = 0, upstox_client_multi_order_request_VALIDITY_DAY, upstox_client_multi_order_request_VALIDITY_IOC } upstox_client_multi_order_request_VALIDITY_e;

char* multi_order_request_validity_ToString(upstox_client_multi_order_request_VALIDITY_e validity);

upstox_client_multi_order_request_VALIDITY_e multi_order_request_validity_FromString(char* validity);

// Enum ORDERTYPE for multi_order_request

typedef enum  { upstox_client_multi_order_request_ORDERTYPE_NULL = 0, upstox_client_multi_order_request_ORDERTYPE_MARKET, upstox_client_multi_order_request_ORDERTYPE_LIMIT, upstox_client_multi_order_request_ORDERTYPE_SL, upstox_client_multi_order_request_ORDERTYPE_SL_M } upstox_client_multi_order_request_ORDERTYPE_e;

char* multi_order_request_order_type_ToString(upstox_client_multi_order_request_ORDERTYPE_e order_type);

upstox_client_multi_order_request_ORDERTYPE_e multi_order_request_order_type_FromString(char* order_type);

// Enum TRANSACTIONTYPE for multi_order_request

typedef enum  { upstox_client_multi_order_request_TRANSACTIONTYPE_NULL = 0, upstox_client_multi_order_request_TRANSACTIONTYPE_BUY, upstox_client_multi_order_request_TRANSACTIONTYPE_SELL } upstox_client_multi_order_request_TRANSACTIONTYPE_e;

char* multi_order_request_transaction_type_ToString(upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_multi_order_request_TRANSACTIONTYPE_e multi_order_request_transaction_type_FromString(char* transaction_type);



typedef struct multi_order_request_t {
    int *quantity; //numeric
    upstox_client_multi_order_request_PRODUCT_e product; //enum
    upstox_client_multi_order_request_VALIDITY_e validity; //enum
    double *price; //numeric
    char *tag; // string
    int *slice; //boolean
    char *instrument_token; // string
    upstox_client_multi_order_request_ORDERTYPE_e order_type; //enum
    upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type; //enum
    int *disclosed_quantity; //numeric
    double *trigger_price; //numeric
    int *is_amo; //boolean
    char *correlation_id; // string
    double *market_protection; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_request_t;

multi_order_request_t *multi_order_request_create(
    int *quantity,
    upstox_client_multi_order_request_PRODUCT_e product,
    upstox_client_multi_order_request_VALIDITY_e validity,
    double *price,
    char *tag,
    int *slice,
    char *instrument_token,
    upstox_client_multi_order_request_ORDERTYPE_e order_type,
    upstox_client_multi_order_request_TRANSACTIONTYPE_e transaction_type,
    int *disclosed_quantity,
    double *trigger_price,
    int *is_amo,
    char *correlation_id,
    double *market_protection
);

void multi_order_request_free(multi_order_request_t *multi_order_request);

multi_order_request_t *multi_order_request_parseFromJSON(cJSON *multi_order_requestJSON);

cJSON *multi_order_request_convertToJSON(multi_order_request_t *multi_order_request);

#endif /* _multi_order_request_H_ */

