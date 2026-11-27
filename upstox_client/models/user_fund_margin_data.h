/*
 * user_fund_margin_data.h
 *
 * 
 */

#ifndef _user_fund_margin_data_H_
#define _user_fund_margin_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_fund_margin_data_t user_fund_margin_data_t;




typedef struct user_fund_margin_data_t {
    double *used_margin; //numeric
    double *payin_amount; //numeric
    double *span_margin; //numeric
    double *adhoc_margin; //numeric
    double *notional_cash; //numeric
    double *available_margin; //numeric
    double *exposure_margin; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} user_fund_margin_data_t;

user_fund_margin_data_t *user_fund_margin_data_create(
    double *used_margin,
    double *payin_amount,
    double *span_margin,
    double *adhoc_margin,
    double *notional_cash,
    double *available_margin,
    double *exposure_margin
);

void user_fund_margin_data_free(user_fund_margin_data_t *user_fund_margin_data);

user_fund_margin_data_t *user_fund_margin_data_parseFromJSON(cJSON *user_fund_margin_dataJSON);

cJSON *user_fund_margin_data_convertToJSON(user_fund_margin_data_t *user_fund_margin_data);

#endif /* _user_fund_margin_data_H_ */

