/*
 * us_order_book_data.h
 *
 * 
 */

#ifndef _us_order_book_data_H_
#define _us_order_book_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_order_book_data_t us_order_book_data_t;


// Enum STATUS for us_order_book_data

typedef enum  { upstox_client_us_order_book_data_STATUS_NULL = 0, upstox_client_us_order_book_data_STATUS_complete, upstox_client_us_order_book_data_STATUS_open, upstox_client_us_order_book_data_STATUS_queued, upstox_client_us_order_book_data_STATUS_cancelled, upstox_client_us_order_book_data_STATUS_cancelled_partially, upstox_client_us_order_book_data_STATUS_failed, upstox_client_us_order_book_data_STATUS_failed_partially, upstox_client_us_order_book_data_STATUS_expired, upstox_client_us_order_book_data_STATUS_partially_complete, upstox_client_us_order_book_data_STATUS_scheduled } upstox_client_us_order_book_data_STATUS_e;

char* us_order_book_data_status_ToString(upstox_client_us_order_book_data_STATUS_e status);

upstox_client_us_order_book_data_STATUS_e us_order_book_data_status_FromString(char* status);

// Enum ORDERTYPE for us_order_book_data

typedef enum  { upstox_client_us_order_book_data_ORDERTYPE_NULL = 0, upstox_client_us_order_book_data_ORDERTYPE_MARKET, upstox_client_us_order_book_data_ORDERTYPE_LIMIT } upstox_client_us_order_book_data_ORDERTYPE_e;

char* us_order_book_data_order_type_ToString(upstox_client_us_order_book_data_ORDERTYPE_e order_type);

upstox_client_us_order_book_data_ORDERTYPE_e us_order_book_data_order_type_FromString(char* order_type);



typedef struct us_order_book_data_t {
    char *name; // string
    char *exchange; // string
    char *validity; // string
    double *price; //numeric
    double *quantity; //numeric
    double *amount; //numeric
    upstox_client_us_order_book_data_STATUS_e status; //enum
    int *fractionable; //boolean
    char *variety; // string
    char *tag; // string
    char *order_id; // string
    char *instrument_key; // string
    char *trading_symbol; // string
    upstox_client_us_order_book_data_ORDERTYPE_e order_type; //enum
    char *transaction_type; // string
    double *average_price; //numeric
    double *filled_quantity; //numeric
    double *pending_quantity; //numeric
    char *status_message; // string
    char *status_message_raw; // string
    char *order_timestamp; // string
    char *exchange_timestamp; // string
    int *is_amo; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} us_order_book_data_t;

us_order_book_data_t *us_order_book_data_create(
    char *name,
    char *exchange,
    char *validity,
    double *price,
    double *quantity,
    double *amount,
    upstox_client_us_order_book_data_STATUS_e status,
    int *fractionable,
    char *variety,
    char *tag,
    char *order_id,
    char *instrument_key,
    char *trading_symbol,
    upstox_client_us_order_book_data_ORDERTYPE_e order_type,
    char *transaction_type,
    double *average_price,
    double *filled_quantity,
    double *pending_quantity,
    char *status_message,
    char *status_message_raw,
    char *order_timestamp,
    char *exchange_timestamp,
    int *is_amo
);

void us_order_book_data_free(us_order_book_data_t *us_order_book_data);

us_order_book_data_t *us_order_book_data_parseFromJSON(cJSON *us_order_book_dataJSON);

cJSON *us_order_book_data_convertToJSON(us_order_book_data_t *us_order_book_data);

#endif /* _us_order_book_data_H_ */

