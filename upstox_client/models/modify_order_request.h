/*
 * modify_order_request.h
 *
 * 
 */

#ifndef _modify_order_request_H_
#define _modify_order_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct modify_order_request_t modify_order_request_t;


// Enum VALIDITY for modify_order_request

typedef enum  { upstox_client_modify_order_request_VALIDITY_NULL = 0, upstox_client_modify_order_request_VALIDITY_DAY, upstox_client_modify_order_request_VALIDITY_IOC } upstox_client_modify_order_request_VALIDITY_e;

char* modify_order_request_validity_ToString(upstox_client_modify_order_request_VALIDITY_e validity);

upstox_client_modify_order_request_VALIDITY_e modify_order_request_validity_FromString(char* validity);

// Enum ORDERTYPE for modify_order_request

typedef enum  { upstox_client_modify_order_request_ORDERTYPE_NULL = 0, upstox_client_modify_order_request_ORDERTYPE_MARKET, upstox_client_modify_order_request_ORDERTYPE_LIMIT, upstox_client_modify_order_request_ORDERTYPE_SL, upstox_client_modify_order_request_ORDERTYPE_SL_M } upstox_client_modify_order_request_ORDERTYPE_e;

char* modify_order_request_order_type_ToString(upstox_client_modify_order_request_ORDERTYPE_e order_type);

upstox_client_modify_order_request_ORDERTYPE_e modify_order_request_order_type_FromString(char* order_type);



typedef struct modify_order_request_t {
    int *quantity; //numeric
    upstox_client_modify_order_request_VALIDITY_e validity; //enum
    double *price; //numeric
    char *order_id; // string
    upstox_client_modify_order_request_ORDERTYPE_e order_type; //enum
    int *disclosed_quantity; //numeric
    double *trigger_price; //numeric
    double *market_protection; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} modify_order_request_t;

modify_order_request_t *modify_order_request_create(
    int *quantity,
    upstox_client_modify_order_request_VALIDITY_e validity,
    double *price,
    char *order_id,
    upstox_client_modify_order_request_ORDERTYPE_e order_type,
    int *disclosed_quantity,
    double *trigger_price,
    double *market_protection
);

void modify_order_request_free(modify_order_request_t *modify_order_request);

modify_order_request_t *modify_order_request_parseFromJSON(cJSON *modify_order_requestJSON);

cJSON *modify_order_request_convertToJSON(modify_order_request_t *modify_order_request);

#endif /* _modify_order_request_H_ */

