/*
 * cash_breakdown.h
 *
 * 
 */

#ifndef _cash_breakdown_H_
#define _cash_breakdown_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_breakdown_t cash_breakdown_t;




typedef struct cash_breakdown_t {
    double *opening_balance; //numeric
    double *added_today; //numeric
    double *withdrawn_today; //numeric
    double *amount_from_stock_sale; //numeric
    double *unpaid_charges; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cash_breakdown_t;

cash_breakdown_t *cash_breakdown_create(
    double *opening_balance,
    double *added_today,
    double *withdrawn_today,
    double *amount_from_stock_sale,
    double *unpaid_charges
);

void cash_breakdown_free(cash_breakdown_t *cash_breakdown);

cash_breakdown_t *cash_breakdown_parseFromJSON(cJSON *cash_breakdownJSON);

cJSON *cash_breakdown_convertToJSON(cash_breakdown_t *cash_breakdown);

#endif /* _cash_breakdown_H_ */

