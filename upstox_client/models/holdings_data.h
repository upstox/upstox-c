/*
 * holdings_data.h
 *
 * 
 */

#ifndef _holdings_data_H_
#define _holdings_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct holdings_data_t holdings_data_t;


// Enum EXCHANGE for holdings_data

typedef enum  { upstox_client_holdings_data_EXCHANGE_NULL = 0, upstox_client_holdings_data_EXCHANGE_NSE, upstox_client_holdings_data_EXCHANGE_NFO, upstox_client_holdings_data_EXCHANGE_CDS, upstox_client_holdings_data_EXCHANGE_BSE, upstox_client_holdings_data_EXCHANGE_BFO, upstox_client_holdings_data_EXCHANGE_BCD, upstox_client_holdings_data_EXCHANGE_MCX, upstox_client_holdings_data_EXCHANGE_NSCOM, upstox_client_holdings_data_EXCHANGE_NSE_EG } upstox_client_holdings_data_EXCHANGE_e;

char* holdings_data_exchange_ToString(upstox_client_holdings_data_EXCHANGE_e exchange);

upstox_client_holdings_data_EXCHANGE_e holdings_data_exchange_FromString(char* exchange);



typedef struct holdings_data_t {
    char *isin; // string
    int *cnc_used_quantity; //numeric
    char *collateral_type; // string
    char *company_name; // string
    double *haircut; //numeric
    char *product; // string
    int *quantity; //numeric
    char *tradingsymbol; // string
    double *last_price; //numeric
    double *close_price; //numeric
    double *pnl; //numeric
    double *day_change; //numeric
    double *day_change_percentage; //numeric
    char *instrument_token; // string
    double *average_price; //numeric
    int *collateral_quantity; //numeric
    int *collateral_update_quantity; //numeric
    char *trading_symbol; // string
    int *t1_quantity; //numeric
    upstox_client_holdings_data_EXCHANGE_e exchange; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} holdings_data_t;

holdings_data_t *holdings_data_create(
    char *isin,
    int *cnc_used_quantity,
    char *collateral_type,
    char *company_name,
    double *haircut,
    char *product,
    int *quantity,
    char *tradingsymbol,
    double *last_price,
    double *close_price,
    double *pnl,
    double *day_change,
    double *day_change_percentage,
    char *instrument_token,
    double *average_price,
    int *collateral_quantity,
    int *collateral_update_quantity,
    char *trading_symbol,
    int *t1_quantity,
    upstox_client_holdings_data_EXCHANGE_e exchange
);

void holdings_data_free(holdings_data_t *holdings_data);

holdings_data_t *holdings_data_parseFromJSON(cJSON *holdings_dataJSON);

cJSON *holdings_data_convertToJSON(holdings_data_t *holdings_data);

#endif /* _holdings_data_H_ */

