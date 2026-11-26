/*
 * available_to_trade.h
 *
 * 
 */

#ifndef _available_to_trade_H_
#define _available_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct available_to_trade_t available_to_trade_t;

#include "cash_available_to_trade.h"
#include "pledge_available_to_trade.h"



typedef struct available_to_trade_t {
    double *total; //numeric
    struct cash_available_to_trade_t *cash_available_to_trade; //model
    struct pledge_available_to_trade_t *pledge_available_to_trade; //model

    int _library_owned; // Is the library responsible for freeing this object?
} available_to_trade_t;

available_to_trade_t *available_to_trade_create(
    double *total,
    cash_available_to_trade_t *cash_available_to_trade,
    pledge_available_to_trade_t *pledge_available_to_trade
);

void available_to_trade_free(available_to_trade_t *available_to_trade);

available_to_trade_t *available_to_trade_parseFromJSON(cJSON *available_to_tradeJSON);

cJSON *available_to_trade_convertToJSON(available_to_trade_t *available_to_trade);

#endif /* _available_to_trade_H_ */

