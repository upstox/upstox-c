/*
 * other_taxes.h
 *
 * 
 */

#ifndef _other_taxes_H_
#define _other_taxes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct other_taxes_t other_taxes_t;




typedef struct other_taxes_t {
    double *transaction; //numeric
    double *clearing; //numeric
    double *ipft; //numeric
    double *sebi_turnover; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} other_taxes_t;

other_taxes_t *other_taxes_create(
    double *transaction,
    double *clearing,
    double *ipft,
    double *sebi_turnover
);

void other_taxes_free(other_taxes_t *other_taxes);

other_taxes_t *other_taxes_parseFromJSON(cJSON *other_taxesJSON);

cJSON *other_taxes_convertToJSON(other_taxes_t *other_taxes);

#endif /* _other_taxes_H_ */

