/*
 * gtt_place_order_request.h
 *
 * 
 */

#ifndef _gtt_place_order_request_H_
#define _gtt_place_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gtt_place_order_request_t gtt_place_order_request_t;

#include "gtt_rule.h"

// Enum TYPE for gtt_place_order_request

typedef enum  { upstox_client_gtt_place_order_request_TYPE_NULL = 0, upstox_client_gtt_place_order_request_TYPE_SINGLE, upstox_client_gtt_place_order_request_TYPE_MULTIPLE } upstox_client_gtt_place_order_request_TYPE_e;

char* gtt_place_order_request_type_ToString(upstox_client_gtt_place_order_request_TYPE_e type);

upstox_client_gtt_place_order_request_TYPE_e gtt_place_order_request_type_FromString(char* type);

// Enum PRODUCT for gtt_place_order_request

typedef enum  { upstox_client_gtt_place_order_request_PRODUCT_NULL = 0, upstox_client_gtt_place_order_request_PRODUCT_I, upstox_client_gtt_place_order_request_PRODUCT_D, upstox_client_gtt_place_order_request_PRODUCT_MTF } upstox_client_gtt_place_order_request_PRODUCT_e;

char* gtt_place_order_request_product_ToString(upstox_client_gtt_place_order_request_PRODUCT_e product);

upstox_client_gtt_place_order_request_PRODUCT_e gtt_place_order_request_product_FromString(char* product);

// Enum TRANSACTIONTYPE for gtt_place_order_request

typedef enum  { upstox_client_gtt_place_order_request_TRANSACTIONTYPE_NULL = 0, upstox_client_gtt_place_order_request_TRANSACTIONTYPE_BUY, upstox_client_gtt_place_order_request_TRANSACTIONTYPE_SELL } upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e;

char* gtt_place_order_request_transaction_type_ToString(upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e gtt_place_order_request_transaction_type_FromString(char* transaction_type);



typedef struct gtt_place_order_request_t {
    upstox_client_gtt_place_order_request_TYPE_e type; //enum
    int *quantity; //numeric
    upstox_client_gtt_place_order_request_PRODUCT_e product; //enum
    list_t *rules; //nonprimitive container
    char *instrument_token; // string
    upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} gtt_place_order_request_t;

gtt_place_order_request_t *gtt_place_order_request_create(
    upstox_client_gtt_place_order_request_TYPE_e type,
    int *quantity,
    upstox_client_gtt_place_order_request_PRODUCT_e product,
    list_t *rules,
    char *instrument_token,
    upstox_client_gtt_place_order_request_TRANSACTIONTYPE_e transaction_type
);

void gtt_place_order_request_free(gtt_place_order_request_t *gtt_place_order_request);

gtt_place_order_request_t *gtt_place_order_request_parseFromJSON(cJSON *gtt_place_order_requestJSON);

cJSON *gtt_place_order_request_convertToJSON(gtt_place_order_request_t *gtt_place_order_request);

#endif /* _gtt_place_order_request_H_ */

