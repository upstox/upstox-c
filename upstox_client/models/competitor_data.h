/*
 * competitor_data.h
 *
 * 
 */

#ifndef _competitor_data_H_
#define _competitor_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct competitor_data_t competitor_data_t;

#include "sector_market_cap_amount.h"



typedef struct competitor_data_t {
    char *company_profile; // string
    char *sector; // string
    struct sector_market_cap_amount_t *sector_market_cap_inr; //model
    struct sector_market_cap_amount_t *sector_market_cap_usd; //model
    char *instrument_key; // string

    int _library_owned; // Is the library responsible for freeing this object?
} competitor_data_t;

competitor_data_t *competitor_data_create(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd,
    char *instrument_key
);

void competitor_data_free(competitor_data_t *competitor_data);

competitor_data_t *competitor_data_parseFromJSON(cJSON *competitor_dataJSON);

cJSON *competitor_data_convertToJSON(competitor_data_t *competitor_data);

#endif /* _competitor_data_H_ */

