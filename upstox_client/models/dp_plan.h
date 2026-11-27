/*
 * dp_plan.h
 *
 * 
 */

#ifndef _dp_plan_H_
#define _dp_plan_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct dp_plan_t dp_plan_t;




typedef struct dp_plan_t {
    char *name; // string
    double *min_expense; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} dp_plan_t;

dp_plan_t *dp_plan_create(
    char *name,
    double *min_expense
);

void dp_plan_free(dp_plan_t *dp_plan);

dp_plan_t *dp_plan_parseFromJSON(cJSON *dp_planJSON);

cJSON *dp_plan_convertToJSON(dp_plan_t *dp_plan);

#endif /* _dp_plan_H_ */

