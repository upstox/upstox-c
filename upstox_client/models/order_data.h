/*
 * order_data.h
 *
 * 
 */

#ifndef _order_data_H_
#define _order_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_data_t order_data_t;


// Enum EXCHANGE for order_data

typedef enum  { upstox_client_order_data_EXCHANGE_NULL = 0, upstox_client_order_data_EXCHANGE_NSE, upstox_client_order_data_EXCHANGE_NFO, upstox_client_order_data_EXCHANGE_CDS, upstox_client_order_data_EXCHANGE_BSE, upstox_client_order_data_EXCHANGE_BFO, upstox_client_order_data_EXCHANGE_BCD, upstox_client_order_data_EXCHANGE_MCX, upstox_client_order_data_EXCHANGE_NSCOM, upstox_client_order_data_EXCHANGE_NSE_EG } upstox_client_order_data_EXCHANGE_e;

char* order_data_exchange_ToString(upstox_client_order_data_EXCHANGE_e exchange);

upstox_client_order_data_EXCHANGE_e order_data_exchange_FromString(char* exchange);

// Enum PRODUCT for order_data

typedef enum  { upstox_client_order_data_PRODUCT_NULL = 0, upstox_client_order_data_PRODUCT_I, upstox_client_order_data_PRODUCT_D, upstox_client_order_data_PRODUCT_CO, upstox_client_order_data_PRODUCT_OCO, upstox_client_order_data_PRODUCT_MTF } upstox_client_order_data_PRODUCT_e;

char* order_data_product_ToString(upstox_client_order_data_PRODUCT_e product);

upstox_client_order_data_PRODUCT_e order_data_product_FromString(char* product);

// Enum VALIDITY for order_data

typedef enum  { upstox_client_order_data_VALIDITY_NULL = 0, upstox_client_order_data_VALIDITY_DAY, upstox_client_order_data_VALIDITY_IOC, upstox_client_order_data_VALIDITY_EOS } upstox_client_order_data_VALIDITY_e;

char* order_data_validity_ToString(upstox_client_order_data_VALIDITY_e validity);

upstox_client_order_data_VALIDITY_e order_data_validity_FromString(char* validity);

// Enum ORDERTYPE for order_data

typedef enum  { upstox_client_order_data_ORDERTYPE_NULL = 0, upstox_client_order_data_ORDERTYPE_MARKET, upstox_client_order_data_ORDERTYPE_LIMIT, upstox_client_order_data_ORDERTYPE_SL, upstox_client_order_data_ORDERTYPE_SL_M } upstox_client_order_data_ORDERTYPE_e;

char* order_data_order_type_ToString(upstox_client_order_data_ORDERTYPE_e order_type);

upstox_client_order_data_ORDERTYPE_e order_data_order_type_FromString(char* order_type);

// Enum TRANSACTIONTYPE for order_data

typedef enum  { upstox_client_order_data_TRANSACTIONTYPE_NULL = 0, upstox_client_order_data_TRANSACTIONTYPE_BUY, upstox_client_order_data_TRANSACTIONTYPE_SELL } upstox_client_order_data_TRANSACTIONTYPE_e;

char* order_data_transaction_type_ToString(upstox_client_order_data_TRANSACTIONTYPE_e transaction_type);

upstox_client_order_data_TRANSACTIONTYPE_e order_data_transaction_type_FromString(char* transaction_type);



typedef struct order_data_t {
    upstox_client_order_data_EXCHANGE_e exchange; //enum
    double *price; //numeric
    upstox_client_order_data_PRODUCT_e product; //enum
    int *quantity; //numeric
    char *status; // string
    char *tag; // string
    upstox_client_order_data_VALIDITY_e validity; //enum
    double *average_price; //numeric
    int *disclosed_quantity; //numeric
    char *exchange_order_id; // string
    char *exchange_timestamp; // string
    char *instrument_token; // string
    int *is_amo; //boolean
    char *status_message; // string
    char *order_id; // string
    char *order_request_id; // string
    upstox_client_order_data_ORDERTYPE_e order_type; //enum
    char *parent_order_id; // string
    char *tradingsymbol; // string
    char *trading_symbol; // string
    char *order_timestamp; // string
    int *filled_quantity; //numeric
    upstox_client_order_data_TRANSACTIONTYPE_e transaction_type; //enum
    double *trigger_price; //numeric
    char *placed_by; // string
    char *variety; // string

    int _library_owned; // Is the library responsible for freeing this object?
} order_data_t;

order_data_t *order_data_create(
    upstox_client_order_data_EXCHANGE_e exchange,
    double *price,
    upstox_client_order_data_PRODUCT_e product,
    int *quantity,
    char *status,
    char *tag,
    upstox_client_order_data_VALIDITY_e validity,
    double *average_price,
    int *disclosed_quantity,
    char *exchange_order_id,
    char *exchange_timestamp,
    char *instrument_token,
    int *is_amo,
    char *status_message,
    char *order_id,
    char *order_request_id,
    upstox_client_order_data_ORDERTYPE_e order_type,
    char *parent_order_id,
    char *tradingsymbol,
    char *trading_symbol,
    char *order_timestamp,
    int *filled_quantity,
    upstox_client_order_data_TRANSACTIONTYPE_e transaction_type,
    double *trigger_price,
    char *placed_by,
    char *variety
);

void order_data_free(order_data_t *order_data);

order_data_t *order_data_parseFromJSON(cJSON *order_dataJSON);

cJSON *order_data_convertToJSON(order_data_t *order_data);

#endif /* _order_data_H_ */

