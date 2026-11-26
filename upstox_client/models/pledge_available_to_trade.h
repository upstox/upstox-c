/*
 * pledge_available_to_trade.h
 *
 * 
 */

#ifndef _pledge_available_to_trade_H_
#define _pledge_available_to_trade_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pledge_available_to_trade_t pledge_available_to_trade_t;

#include "margin_from_pledge.h"
#include "pledge_margin_used.h"



typedef struct pledge_available_to_trade_t {
    struct margin_from_pledge_t *margin_from_pledge; //model
    struct pledge_margin_used_t *margin_used; //model

    int _library_owned; // Is the library responsible for freeing this object?
} pledge_available_to_trade_t;

pledge_available_to_trade_t *pledge_available_to_trade_create(
    margin_from_pledge_t *margin_from_pledge,
    pledge_margin_used_t *margin_used
);

void pledge_available_to_trade_free(pledge_available_to_trade_t *pledge_available_to_trade);

pledge_available_to_trade_t *pledge_available_to_trade_parseFromJSON(cJSON *pledge_available_to_tradeJSON);

cJSON *pledge_available_to_trade_convertToJSON(pledge_available_to_trade_t *pledge_available_to_trade);

#endif /* _pledge_available_to_trade_H_ */

