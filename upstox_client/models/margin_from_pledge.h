/*
 * margin_from_pledge.h
 *
 * 
 */

#ifndef _margin_from_pledge_H_
#define _margin_from_pledge_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct margin_from_pledge_t margin_from_pledge_t;




typedef struct margin_from_pledge_t {
    double *total; //numeric
    double *equity; //numeric
    double *mutual_funds; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} margin_from_pledge_t;

margin_from_pledge_t *margin_from_pledge_create(
    double *total,
    double *equity,
    double *mutual_funds
);

void margin_from_pledge_free(margin_from_pledge_t *margin_from_pledge);

margin_from_pledge_t *margin_from_pledge_parseFromJSON(cJSON *margin_from_pledgeJSON);

cJSON *margin_from_pledge_convertToJSON(margin_from_pledge_t *margin_from_pledge);

#endif /* _margin_from_pledge_H_ */

