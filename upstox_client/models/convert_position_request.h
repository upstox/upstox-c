/*
 * convert_position_request.h
 *
 * 
 */

#ifndef _convert_position_request_H_
#define _convert_position_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_position_request_t convert_position_request_t;


// Enum NEWPRODUCT for convert_position_request

typedef enum  { upstox_client_convert_position_request_NEWPRODUCT_NULL = 0, upstox_client_convert_position_request_NEWPRODUCT_I, upstox_client_convert_position_request_NEWPRODUCT_D, upstox_client_convert_position_request_NEWPRODUCT_CO, upstox_client_convert_position_request_NEWPRODUCT_OCO, upstox_client_convert_position_request_NEWPRODUCT_MTF } upstox_client_convert_position_request_NEWPRODUCT_e;

char* convert_position_request_new_product_ToString(upstox_client_convert_position_request_NEWPRODUCT_e new_product);

upstox_client_convert_position_request_NEWPRODUCT_e convert_position_request_new_product_FromString(char* new_product);

// Enum OLDPRODUCT for convert_position_request

typedef enum  { upstox_client_convert_position_request_OLDPRODUCT_NULL = 0, upstox_client_convert_position_request_OLDPRODUCT_I, upstox_client_convert_position_request_OLDPRODUCT_D, upstox_client_convert_position_request_OLDPRODUCT_CO, upstox_client_convert_position_request_OLDPRODUCT_OCO, upstox_client_convert_position_request_OLDPRODUCT_MTF } upstox_client_convert_position_request_OLDPRODUCT_e;

char* convert_position_request_old_product_ToString(upstox_client_convert_position_request_OLDPRODUCT_e old_product);

upstox_client_convert_position_request_OLDPRODUCT_e convert_position_request_old_product_FromString(char* old_product);

// Enum TRANSACTIONTYPE for convert_position_request

typedef enum  { upstox_client_convert_position_request_TRANSACTIONTYPE_NULL = 0, upstox_client_convert_position_request_TRANSACTIONTYPE_BUY, upstox_client_convert_position_request_TRANSACTIONTYPE_SELL } upstox_client_convert_position_request_TRANSACTIONTYPE_e;

char* convert_position_request_transaction_type_ToString(upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type);

upstox_client_convert_position_request_TRANSACTIONTYPE_e convert_position_request_transaction_type_FromString(char* transaction_type);



typedef struct convert_position_request_t {
    char *instrument_token; // string
    upstox_client_convert_position_request_NEWPRODUCT_e new_product; //enum
    upstox_client_convert_position_request_OLDPRODUCT_e old_product; //enum
    upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type; //enum
    int *quantity; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} convert_position_request_t;

convert_position_request_t *convert_position_request_create(
    char *instrument_token,
    upstox_client_convert_position_request_NEWPRODUCT_e new_product,
    upstox_client_convert_position_request_OLDPRODUCT_e old_product,
    upstox_client_convert_position_request_TRANSACTIONTYPE_e transaction_type,
    int *quantity
);

void convert_position_request_free(convert_position_request_t *convert_position_request);

convert_position_request_t *convert_position_request_parseFromJSON(cJSON *convert_position_requestJSON);

cJSON *convert_position_request_convertToJSON(convert_position_request_t *convert_position_request);

#endif /* _convert_position_request_H_ */

