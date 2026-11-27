/*
 * pledge_unavailable_to_trade.h
 *
 * 
 */

#ifndef _pledge_unavailable_to_trade_H_
#define _pledge_unavailable_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pledge_unavailable_to_trade_t pledge_unavailable_to_trade_t;




typedef struct pledge_unavailable_to_trade_t {
    double *equity; //numeric
    double *mutual_funds; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pledge_unavailable_to_trade_t;

pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_create(
    double *equity,
    double *mutual_funds
);

void pledge_unavailable_to_trade_free(pledge_unavailable_to_trade_t *pledge_unavailable_to_trade);

pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_parseFromJSON(cJSON *pledge_unavailable_to_tradeJSON);

cJSON *pledge_unavailable_to_trade_convertToJSON(pledge_unavailable_to_trade_t *pledge_unavailable_to_trade);

#endif /* _pledge_unavailable_to_trade_H_ */

