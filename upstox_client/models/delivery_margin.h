/*
 * delivery_margin.h
 *
 * 
 */

#ifndef _delivery_margin_H_
#define _delivery_margin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delivery_margin_t delivery_margin_t;




typedef struct delivery_margin_t {
    double *total; //numeric
    double *equity; //numeric
    double *fo_settlement; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} delivery_margin_t;

delivery_margin_t *delivery_margin_create(
    double *total,
    double *equity,
    double *fo_settlement
);

void delivery_margin_free(delivery_margin_t *delivery_margin);

delivery_margin_t *delivery_margin_parseFromJSON(cJSON *delivery_marginJSON);

cJSON *delivery_margin_convertToJSON(delivery_margin_t *delivery_margin);

#endif /* _delivery_margin_H_ */

