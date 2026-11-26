/*
 * cash_available_to_trade.h
 *
 * 
 */

#ifndef _cash_available_to_trade_H_
#define _cash_available_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_available_to_trade_t cash_available_to_trade_t;

#include "cash_breakdown.h"
#include "cash_margin_used.h"



typedef struct cash_available_to_trade_t {
    double *total; //numeric
    struct cash_breakdown_t *cash; //model
    struct cash_margin_used_t *margin_used; //model

    int _library_owned; // Is the library responsible for freeing this object?
} cash_available_to_trade_t;

cash_available_to_trade_t *cash_available_to_trade_create(
    double *total,
    cash_breakdown_t *cash,
    cash_margin_used_t *margin_used
);

void cash_available_to_trade_free(cash_available_to_trade_t *cash_available_to_trade);

cash_available_to_trade_t *cash_available_to_trade_parseFromJSON(cJSON *cash_available_to_tradeJSON);

cJSON *cash_available_to_trade_convertToJSON(cash_available_to_trade_t *cash_available_to_trade);

#endif /* _cash_available_to_trade_H_ */

