/*
 * sector_market_cap_amount.h
 *
 * 
 */

#ifndef _sector_market_cap_amount_H_
#define _sector_market_cap_amount_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sector_market_cap_amount_t sector_market_cap_amount_t;




typedef struct sector_market_cap_amount_t {
    double *value; //numeric
    char *unit; // string
    char *formatted; // string

    int _library_owned; // Is the library responsible for freeing this object?
} sector_market_cap_amount_t;

sector_market_cap_amount_t *sector_market_cap_amount_create(
    double *value,
    char *unit,
    char *formatted
);

void sector_market_cap_amount_free(sector_market_cap_amount_t *sector_market_cap_amount);

sector_market_cap_amount_t *sector_market_cap_amount_parseFromJSON(cJSON *sector_market_cap_amountJSON);

cJSON *sector_market_cap_amount_convertToJSON(sector_market_cap_amount_t *sector_market_cap_amount);

#endif /* _sector_market_cap_amount_H_ */

