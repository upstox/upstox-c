/*
 * user_fund_margin_v3_data.h
 *
 * 
 */

#ifndef _user_fund_margin_v3_data_H_
#define _user_fund_margin_v3_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_fund_margin_v3_data_t user_fund_margin_v3_data_t;

#include "available_to_trade.h"
#include "unavailable_to_trade.h"



typedef struct user_fund_margin_v3_data_t {
    struct available_to_trade_t *available_to_trade; //model
    struct unavailable_to_trade_t *unavailable_to_trade; //model

    int _library_owned; // Is the library responsible for freeing this object?
} user_fund_margin_v3_data_t;

user_fund_margin_v3_data_t *user_fund_margin_v3_data_create(
    available_to_trade_t *available_to_trade,
    unavailable_to_trade_t *unavailable_to_trade
);

void user_fund_margin_v3_data_free(user_fund_margin_v3_data_t *user_fund_margin_v3_data);

user_fund_margin_v3_data_t *user_fund_margin_v3_data_parseFromJSON(cJSON *user_fund_margin_v3_dataJSON);

cJSON *user_fund_margin_v3_data_convertToJSON(user_fund_margin_v3_data_t *user_fund_margin_v3_data);

#endif /* _user_fund_margin_v3_data_H_ */

