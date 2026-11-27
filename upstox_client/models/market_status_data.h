/*
 * market_status_data.h
 *
 * 
 */

#ifndef _market_status_data_H_
#define _market_status_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct market_status_data_t market_status_data_t;

#include "cas_eligible_status_data.h"



typedef struct market_status_data_t {
    char *exchange; // string
    char *status; // string
    long *last_updated; //numeric
    struct cas_eligible_status_data_t *cas_eligible_status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} market_status_data_t;

market_status_data_t *market_status_data_create(
    char *exchange,
    char *status,
    long *last_updated,
    cas_eligible_status_data_t *cas_eligible_status
);

void market_status_data_free(market_status_data_t *market_status_data);

market_status_data_t *market_status_data_parseFromJSON(cJSON *market_status_dataJSON);

cJSON *market_status_data_convertToJSON(market_status_data_t *market_status_data);

#endif /* _market_status_data_H_ */

