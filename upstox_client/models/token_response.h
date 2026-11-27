/*
 * token_response.h
 *
 * 
 */

#ifndef _token_response_H_
#define _token_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct token_response_t token_response_t;


// Enum EXCHANGES for token_response

typedef enum  { upstox_client_token_response_EXCHANGES_NULL = 0, upstox_client_token_response_EXCHANGES_NSE, upstox_client_token_response_EXCHANGES_NFO, upstox_client_token_response_EXCHANGES_CDS, upstox_client_token_response_EXCHANGES_BSE, upstox_client_token_response_EXCHANGES_BFO, upstox_client_token_response_EXCHANGES_BCD, upstox_client_token_response_EXCHANGES_MCX, upstox_client_token_response_EXCHANGES_NSCOM, upstox_client_token_response_EXCHANGES_NSE_EG } upstox_client_token_response_EXCHANGES_e;

char* token_response_exchanges_ToString(upstox_client_token_response_EXCHANGES_e exchanges);

upstox_client_token_response_EXCHANGES_e token_response_exchanges_FromString(char* exchanges);

// Enum PRODUCTS for token_response

typedef enum  { upstox_client_token_response_PRODUCTS_NULL = 0, upstox_client_token_response_PRODUCTS_I, upstox_client_token_response_PRODUCTS_D, upstox_client_token_response_PRODUCTS_CO, upstox_client_token_response_PRODUCTS_OCO, upstox_client_token_response_PRODUCTS_MTF } upstox_client_token_response_PRODUCTS_e;

char* token_response_products_ToString(upstox_client_token_response_PRODUCTS_e products);

upstox_client_token_response_PRODUCTS_e token_response_products_FromString(char* products);

// Enum ORDERTYPES for token_response

typedef enum  { upstox_client_token_response_ORDERTYPES_NULL = 0, upstox_client_token_response_ORDERTYPES_MARKET, upstox_client_token_response_ORDERTYPES_LIMIT, upstox_client_token_response_ORDERTYPES_SL, upstox_client_token_response_ORDERTYPES_SL_M } upstox_client_token_response_ORDERTYPES_e;

char* token_response_order_types_ToString(upstox_client_token_response_ORDERTYPES_e order_types);

upstox_client_token_response_ORDERTYPES_e token_response_order_types_FromString(char* order_types);



typedef struct token_response_t {
    char *email; // string
    list_t *exchanges; //primitive container
    list_t *products; //primitive container
    char *broker; // string
    char *user_id; // string
    char *user_name; // string
    list_t *order_types; //primitive container
    char *user_type; // string
    int *poa; //boolean
    int *ddpi; //boolean
    int *is_active; //boolean
    char *access_token; // string
    char *extended_token; // string
    int *expires_in; //numeric
    char *token_type; // string
    char *refresh_token; // string
    int *refresh_token_expires_in; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} token_response_t;

token_response_t *token_response_create(
    char *email,
    list_t *exchanges,
    list_t *products,
    char *broker,
    char *user_id,
    char *user_name,
    list_t *order_types,
    char *user_type,
    int *poa,
    int *ddpi,
    int *is_active,
    char *access_token,
    char *extended_token,
    int *expires_in,
    char *token_type,
    char *refresh_token,
    int *refresh_token_expires_in
);

void token_response_free(token_response_t *token_response);

token_response_t *token_response_parseFromJSON(cJSON *token_responseJSON);

cJSON *token_response_convertToJSON(token_response_t *token_response);

#endif /* _token_response_H_ */

