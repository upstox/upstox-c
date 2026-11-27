/*
 * unavailable_to_trade.h
 *
 * 
 */

#ifndef _unavailable_to_trade_H_
#define _unavailable_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unavailable_to_trade_t unavailable_to_trade_t;

#include "cash_unavailable_to_trade.h"
#include "pledge_unavailable_to_trade.h"



typedef struct unavailable_to_trade_t {
    struct cash_unavailable_to_trade_t *cash_unavailable_to_trade; //model
    struct pledge_unavailable_to_trade_t *pledge_unavailable_to_trade; //model

    int _library_owned; // Is the library responsible for freeing this object?
} unavailable_to_trade_t;

unavailable_to_trade_t *unavailable_to_trade_create(
    cash_unavailable_to_trade_t *cash_unavailable_to_trade,
    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade
);

void unavailable_to_trade_free(unavailable_to_trade_t *unavailable_to_trade);

unavailable_to_trade_t *unavailable_to_trade_parseFromJSON(cJSON *unavailable_to_tradeJSON);

cJSON *unavailable_to_trade_convertToJSON(unavailable_to_trade_t *unavailable_to_trade);

#endif /* _unavailable_to_trade_H_ */

