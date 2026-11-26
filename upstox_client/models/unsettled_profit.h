/*
 * unsettled_profit.h
 *
 * 
 */

#ifndef _unsettled_profit_H_
#define _unsettled_profit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unsettled_profit_t unsettled_profit_t;




typedef struct unsettled_profit_t {
    double *todays_profit; //numeric
    double *previous_days; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} unsettled_profit_t;

unsettled_profit_t *unsettled_profit_create(
    double *todays_profit,
    double *previous_days
);

void unsettled_profit_free(unsettled_profit_t *unsettled_profit);

unsettled_profit_t *unsettled_profit_parseFromJSON(cJSON *unsettled_profitJSON);

cJSON *unsettled_profit_convertToJSON(unsettled_profit_t *unsettled_profit);

#endif /* _unsettled_profit_H_ */

