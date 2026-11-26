/*
 * position_data.h
 *
 * 
 */

#ifndef _position_data_H_
#define _position_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct position_data_t position_data_t;


// Enum EXCHANGE for position_data

typedef enum  { upstox_client_position_data_EXCHANGE_NULL = 0, upstox_client_position_data_EXCHANGE_NSE, upstox_client_position_data_EXCHANGE_NFO, upstox_client_position_data_EXCHANGE_CDS, upstox_client_position_data_EXCHANGE_BSE, upstox_client_position_data_EXCHANGE_BFO, upstox_client_position_data_EXCHANGE_BCD, upstox_client_position_data_EXCHANGE_MCX, upstox_client_position_data_EXCHANGE_NSCOM, upstox_client_position_data_EXCHANGE_NSE_EG } upstox_client_position_data_EXCHANGE_e;

char* position_data_exchange_ToString(upstox_client_position_data_EXCHANGE_e exchange);

upstox_client_position_data_EXCHANGE_e position_data_exchange_FromString(char* exchange);



typedef struct position_data_t {
    upstox_client_position_data_EXCHANGE_e exchange; //enum
    double *multiplier; //numeric
    double *value; //numeric
    double *pnl; //numeric
    char *product; // string
    char *instrument_token; // string
    double *average_price; //numeric
    double *buy_value; //numeric
    int *overnight_quantity; //numeric
    double *day_buy_value; //numeric
    double *day_buy_price; //numeric
    double *overnight_buy_amount; //numeric
    int *overnight_buy_quantity; //numeric
    int *day_buy_quantity; //numeric
    double *day_sell_value; //numeric
    double *day_sell_price; //numeric
    double *overnight_sell_amount; //numeric
    int *overnight_sell_quantity; //numeric
    int *day_sell_quantity; //numeric
    int *quantity; //numeric
    double *last_price; //numeric
    double *unrealised; //numeric
    double *realised; //numeric
    double *sell_value; //numeric
    char *tradingsymbol; // string
    char *trading_symbol; // string
    double *close_price; //numeric
    double *buy_price; //numeric
    double *sell_price; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} position_data_t;

position_data_t *position_data_create(
    upstox_client_position_data_EXCHANGE_e exchange,
    double *multiplier,
    double *value,
    double *pnl,
    char *product,
    char *instrument_token,
    double *average_price,
    double *buy_value,
    int *overnight_quantity,
    double *day_buy_value,
    double *day_buy_price,
    double *overnight_buy_amount,
    int *overnight_buy_quantity,
    int *day_buy_quantity,
    double *day_sell_value,
    double *day_sell_price,
    double *overnight_sell_amount,
    int *overnight_sell_quantity,
    int *day_sell_quantity,
    int *quantity,
    double *last_price,
    double *unrealised,
    double *realised,
    double *sell_value,
    char *tradingsymbol,
    char *trading_symbol,
    double *close_price,
    double *buy_price,
    double *sell_price
);

void position_data_free(position_data_t *position_data);

position_data_t *position_data_parseFromJSON(cJSON *position_dataJSON);

cJSON *position_data_convertToJSON(position_data_t *position_data);

#endif /* _position_data_H_ */

