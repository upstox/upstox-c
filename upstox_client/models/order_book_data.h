/*
 * order_book_data.h
 *
 * 
 */

#ifndef _order_book_data_H_
#define _order_book_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_book_data_t order_book_data_t;


// Enum EXCHANGE for order_book_data

typedef enum  { upstox_client_order_book_data_EXCHANGE_NULL = 0, upstox_client_order_book_data_EXCHANGE_NSE, upstox_client_order_book_data_EXCHANGE_NFO, upstox_client_order_book_data_EXCHANGE_CDS, upstox_client_order_book_data_EXCHANGE_BSE, upstox_client_order_book_data_EXCHANGE_BFO, upstox_client_order_book_data_EXCHANGE_BCD, upstox_client_order_book_data_EXCHANGE_MCX, upstox_client_order_book_data_EXCHANGE_NSCOM, upstox_client_order_book_data_EXCHANGE_NSE_EG } upstox_client_order_book_data_EXCHANGE_e;

char* order_book_data_exchange_ToString(upstox_client_order_book_data_EXCHANGE_e exchange);

upstox_client_order_book_data_EXCHANGE_e order_book_data_exchange_FromString(char* exchange);

// Enum PRODUCT for order_book_data

typedef enum  { upstox_client_order_book_data_PRODUCT_NULL = 0, upstox_client_order_book_data_PRODUCT_I, upstox_client_order_book_data_PRODUCT_D, upstox_client_order_book_data_PRODUCT_CO, upstox_client_order_book_data_PRODUCT_OCO, upstox_client_order_book_data_PRODUCT_MTF } upstox_client_order_book_data_PRODUCT_e;

char* order_book_data_product_ToString(upstox_client_order_book_data_PRODUCT_e product);

upstox_client_order_book_data_PRODUCT_e order_book_data_product_FromString(char* product);

// Enum ORDERTYPE for order_book_data

typedef enum  { upstox_client_order_book_data_ORDERTYPE_NULL = 0, upstox_client_order_book_data_ORDERTYPE_MARKET, upstox_client_order_book_data_ORDERTYPE_LIMIT, upstox_client_order_book_data_ORDERTYPE_SL, upstox_client_order_book_data_ORDERTYPE_SL_M } upstox_client_order_book_data_ORDERTYPE_e;

char* order_book_data_order_type_ToString(upstox_client_order_book_data_ORDERTYPE_e order_type);

upstox_client_order_book_data_ORDERTYPE_e order_book_data_order_type_FromString(char* order_type);

// Enum VALIDITY for order_book_data

typedef enum  { upstox_client_order_book_data_VALIDITY_NULL = 0, upstox_client_order_book_data_VALIDITY_DAY, upstox_client_order_book_data_VALIDITY_IOC, upstox_client_order_book_data_VALIDITY_EOS } upstox_client_order_book_data_VALIDITY_e;

char* order_book_data_validity_ToString(upstox_client_order_book_data_VALIDITY_e validity);

upstox_client_order_book_data_VALIDITY_e order_book_data_validity_FromString(char* validity);

// Enum TRANSACTIONTYPE for order_book_data

typedef enum  { upstox_client_order_book_data_TRANSACTIONTYPE_NULL = 0, upstox_client_order_book_data_TRANSACTIONTYPE_BUY, upstox_client_order_book_data_TRANSACTIONTYPE_SELL } upstox_client_order_book_data_TRANSACTIONTYPE_e;

char* order_book_data_transaction_type_ToString(upstox_client_order_book_data_TRANSACTIONTYPE_e transaction_type);

upstox_client_order_book_data_TRANSACTIONTYPE_e order_book_data_transaction_type_FromString(char* transaction_type);



typedef struct order_book_data_t {
    upstox_client_order_book_data_EXCHANGE_e exchange; //enum
    upstox_client_order_book_data_PRODUCT_e product; //enum
    double *price; //numeric
    int *quantity; //numeric
    char *status; // string
    char *guid; // string
    char *tag; // string
    char *instrument_token; // string
    char *placed_by; // string
    char *tradingsymbol; // string
    char *trading_symbol; // string
    upstox_client_order_book_data_ORDERTYPE_e order_type; //enum
    upstox_client_order_book_data_VALIDITY_e validity; //enum
    double *trigger_price; //numeric
    int *disclosed_quantity; //numeric
    upstox_client_order_book_data_TRANSACTIONTYPE_e transaction_type; //enum
    double *average_price; //numeric
    int *filled_quantity; //numeric
    int *pending_quantity; //numeric
    char *status_message; // string
    char *status_message_raw; // string
    char *exchange_order_id; // string
    char *parent_order_id; // string
    char *order_id; // string
    char *variety; // string
    char *order_timestamp; // string
    char *exchange_timestamp; // string
    int *is_amo; //boolean
    char *order_request_id; // string
    char *order_ref_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} order_book_data_t;

order_book_data_t *order_book_data_create(
    upstox_client_order_book_data_EXCHANGE_e exchange,
    upstox_client_order_book_data_PRODUCT_e product,
    double *price,
    int *quantity,
    char *status,
    char *guid,
    char *tag,
    char *instrument_token,
    char *placed_by,
    char *tradingsymbol,
    char *trading_symbol,
    upstox_client_order_book_data_ORDERTYPE_e order_type,
    upstox_client_order_book_data_VALIDITY_e validity,
    double *trigger_price,
    int *disclosed_quantity,
    upstox_client_order_book_data_TRANSACTIONTYPE_e transaction_type,
    double *average_price,
    int *filled_quantity,
    int *pending_quantity,
    char *status_message,
    char *status_message_raw,
    char *exchange_order_id,
    char *parent_order_id,
    char *order_id,
    char *variety,
    char *order_timestamp,
    char *exchange_timestamp,
    int *is_amo,
    char *order_request_id,
    char *order_ref_id
);

void order_book_data_free(order_book_data_t *order_book_data);

order_book_data_t *order_book_data_parseFromJSON(cJSON *order_book_dataJSON);

cJSON *order_book_data_convertToJSON(order_book_data_t *order_book_data);

#endif /* _order_book_data_H_ */

