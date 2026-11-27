/*
 * company_profile_data.h
 *
 * 
 */

#ifndef _company_profile_data_H_
#define _company_profile_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct company_profile_data_t company_profile_data_t;

#include "sector_market_cap_amount.h"



typedef struct company_profile_data_t {
    char *company_profile; // string
    char *sector; // string
    struct sector_market_cap_amount_t *sector_market_cap_inr; //model
    struct sector_market_cap_amount_t *sector_market_cap_usd; //model

    int _library_owned; // Is the library responsible for freeing this object?
} company_profile_data_t;

company_profile_data_t *company_profile_data_create(
    char *company_profile,
    char *sector,
    sector_market_cap_amount_t *sector_market_cap_inr,
    sector_market_cap_amount_t *sector_market_cap_usd
);

void company_profile_data_free(company_profile_data_t *company_profile_data);

company_profile_data_t *company_profile_data_parseFromJSON(cJSON *company_profile_dataJSON);

cJSON *company_profile_data_convertToJSON(company_profile_data_t *company_profile_data);

#endif /* _company_profile_data_H_ */

