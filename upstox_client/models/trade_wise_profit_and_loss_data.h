/*
 * trade_wise_profit_and_loss_data.h
 *
 * 
 */

#ifndef _trade_wise_profit_and_loss_data_H_
#define _trade_wise_profit_and_loss_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trade_wise_profit_and_loss_data_t trade_wise_profit_and_loss_data_t;




typedef struct trade_wise_profit_and_loss_data_t {
    double *quantity; //numeric
    char *isin; // string
    char *scrip_name; // string
    char *trade_type; // string
    char *buy_date; // string
    double *buy_average; //numeric
    char *sell_date; // string
    double *sell_average; //numeric
    double *buy_amount; //numeric
    double *sell_amount; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} trade_wise_profit_and_loss_data_t;

trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_create(
    double *quantity,
    char *isin,
    char *scrip_name,
    char *trade_type,
    char *buy_date,
    double *buy_average,
    char *sell_date,
    double *sell_average,
    double *buy_amount,
    double *sell_amount
);

void trade_wise_profit_and_loss_data_free(trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data);

trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_parseFromJSON(cJSON *trade_wise_profit_and_loss_dataJSON);

cJSON *trade_wise_profit_and_loss_data_convertToJSON(trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data);

#endif /* _trade_wise_profit_and_loss_data_H_ */

