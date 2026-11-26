/*
 * trade_data.h
 *
 * 
 */

#ifndef _trade_data_H_
#define _trade_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_data_t trade_data_t;


// Enum EXCHANGE for trade_data

typedef enum  { upstox_client_trade_data_EXCHANGE_NULL = 0, upstox_client_trade_data_EXCHANGE_NSE, upstox_client_trade_data_EXCHANGE_NFO, upstox_client_trade_data_EXCHANGE_CDS, upstox_client_trade_data_EXCHANGE_BSE, upstox_client_trade_data_EXCHANGE_BFO, upstox_client_trade_data_EXCHANGE_BCD, upstox_client_trade_data_EXCHANGE_MCX, upstox_client_trade_data_EXCHANGE_NSCOM, upstox_client_trade_data_EXCHANGE_NSE_EG } upstox_client_trade_data_EXCHANGE_e;

char* trade_data_exchange_ToString(upstox_client_trade_data_EXCHANGE_e exchange);

upstox_client_trade_data_EXCHANGE_e trade_data_exchange_FromString(char* exchange);

// Enum PRODUCT for trade_data

typedef enum  { upstox_client_trade_data_PRODUCT_NULL = 0, upstox_client_trade_data_PRODUCT_I, upstox_client_trade_data_PRODUCT_D, upstox_client_trade_data_PRODUCT_CO, upstox_client_trade_data_PRODUCT_OCO, upstox_client_trade_data_PRODUCT_MTF } upstox_client_trade_data_PRODUCT_e;

char* trade_data_product_ToString(upstox_client_trade_data_PRODUCT_e product);

upstox_client_trade_data_PRODUCT_e trade_data_product_FromString(char* product);

// Enum ORDERTYPE for trade_data

typedef enum  { upstox_client_trade_data_ORDERTYPE_NULL = 0, upstox_client_trade_data_ORDERTYPE_MARKET, upstox_client_trade_data_ORDERTYPE_LIMIT, upstox_client_trade_data_ORDERTYPE_SL, upstox_client_trade_data_ORDERTYPE_SL_M } upstox_client_trade_data_ORDERTYPE_e;

char* trade_data_order_type_ToString(upstox_client_trade_data_ORDERTYPE_e order_type);

upstox_client_trade_data_ORDERTYPE_e trade_data_order_type_FromString(char* order_type);

// Enum TRANSACTIONTYPE for trade_data

typedef enum  { upstox_client_trade_data_TRANSACTIONTYPE_NULL = 0, upstox_client_trade_data_TRANSACTIONTYPE_BUY, upstox_client_trade_data_TRANSACTIONTYPE_SELL } upstox_client_trade_data_TRANSACTIONTYPE_e;

char* trade_data_transaction_type_ToString(upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type);

upstox_client_trade_data_TRANSACTIONTYPE_e trade_data_transaction_type_FromString(char* transaction_type);



typedef struct trade_data_t {
    upstox_client_trade_data_EXCHANGE_e exchange; //enum
    upstox_client_trade_data_PRODUCT_e product; //enum
    char *tradingsymbol; // string
    char *trading_symbol; // string
    char *instrument_token; // string
    upstox_client_trade_data_ORDERTYPE_e order_type; //enum
    upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type; //enum
    int *quantity; //numeric
    char *exchange_order_id; // string
    char *order_id; // string
    char *exchange_timestamp; // string
    double *average_price; //numeric
    char *trade_id; // string
    char *order_ref_id; // string
    char *order_timestamp; // string

    int _library_owned; // Is the library responsible for freeing this object?
} trade_data_t;

trade_data_t *trade_data_create(
    upstox_client_trade_data_EXCHANGE_e exchange,
    upstox_client_trade_data_PRODUCT_e product,
    char *tradingsymbol,
    char *trading_symbol,
    char *instrument_token,
    upstox_client_trade_data_ORDERTYPE_e order_type,
    upstox_client_trade_data_TRANSACTIONTYPE_e transaction_type,
    int *quantity,
    char *exchange_order_id,
    char *order_id,
    char *exchange_timestamp,
    double *average_price,
    char *trade_id,
    char *order_ref_id,
    char *order_timestamp
);

void trade_data_free(trade_data_t *trade_data);

trade_data_t *trade_data_parseFromJSON(cJSON *trade_dataJSON);

cJSON *trade_data_convertToJSON(trade_data_t *trade_data);

#endif /* _trade_data_H_ */

