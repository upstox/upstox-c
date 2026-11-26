/*
 * profile_data.h
 *
 * 
 */

#ifndef _profile_data_H_
#define _profile_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct profile_data_t profile_data_t;


// Enum EXCHANGES for profile_data

typedef enum  { upstox_client_profile_data_EXCHANGES_NULL = 0, upstox_client_profile_data_EXCHANGES_NSE, upstox_client_profile_data_EXCHANGES_NFO, upstox_client_profile_data_EXCHANGES_CDS, upstox_client_profile_data_EXCHANGES_BSE, upstox_client_profile_data_EXCHANGES_BFO, upstox_client_profile_data_EXCHANGES_BCD, upstox_client_profile_data_EXCHANGES_MCX, upstox_client_profile_data_EXCHANGES_NSCOM, upstox_client_profile_data_EXCHANGES_NSE_EG } upstox_client_profile_data_EXCHANGES_e;

char* profile_data_exchanges_ToString(upstox_client_profile_data_EXCHANGES_e exchanges);

upstox_client_profile_data_EXCHANGES_e profile_data_exchanges_FromString(char* exchanges);

// Enum PRODUCTS for profile_data

typedef enum  { upstox_client_profile_data_PRODUCTS_NULL = 0, upstox_client_profile_data_PRODUCTS_I, upstox_client_profile_data_PRODUCTS_D, upstox_client_profile_data_PRODUCTS_CO, upstox_client_profile_data_PRODUCTS_OCO, upstox_client_profile_data_PRODUCTS_MTF } upstox_client_profile_data_PRODUCTS_e;

char* profile_data_products_ToString(upstox_client_profile_data_PRODUCTS_e products);

upstox_client_profile_data_PRODUCTS_e profile_data_products_FromString(char* products);

// Enum ORDERTYPES for profile_data

typedef enum  { upstox_client_profile_data_ORDERTYPES_NULL = 0, upstox_client_profile_data_ORDERTYPES_MARKET, upstox_client_profile_data_ORDERTYPES_LIMIT, upstox_client_profile_data_ORDERTYPES_SL, upstox_client_profile_data_ORDERTYPES_SL_M } upstox_client_profile_data_ORDERTYPES_e;

char* profile_data_order_types_ToString(upstox_client_profile_data_ORDERTYPES_e order_types);

upstox_client_profile_data_ORDERTYPES_e profile_data_order_types_FromString(char* order_types);



typedef struct profile_data_t {
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

    int _library_owned; // Is the library responsible for freeing this object?
} profile_data_t;

profile_data_t *profile_data_create(
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
    int *is_active
);

void profile_data_free(profile_data_t *profile_data);

profile_data_t *profile_data_parseFromJSON(cJSON *profile_dataJSON);

cJSON *profile_data_convertToJSON(profile_data_t *profile_data);

#endif /* _profile_data_H_ */

