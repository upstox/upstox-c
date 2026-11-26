/*
 * cash_unavailable_to_trade.h
 *
 * 
 */

#ifndef _cash_unavailable_to_trade_H_
#define _cash_unavailable_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_unavailable_to_trade_t cash_unavailable_to_trade_t;

#include "unsettled_profit.h"



typedef struct cash_unavailable_to_trade_t {
    struct unsettled_profit_t *unsettled_profit; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cash_unavailable_to_trade_t;

cash_unavailable_to_trade_t *cash_unavailable_to_trade_create(
    unsettled_profit_t *unsettled_profit
);

void cash_unavailable_to_trade_free(cash_unavailable_to_trade_t *cash_unavailable_to_trade);

cash_unavailable_to_trade_t *cash_unavailable_to_trade_parseFromJSON(cJSON *cash_unavailable_to_tradeJSON);

cJSON *cash_unavailable_to_trade_convertToJSON(cash_unavailable_to_trade_t *cash_unavailable_to_trade);

#endif /* _cash_unavailable_to_trade_H_ */

