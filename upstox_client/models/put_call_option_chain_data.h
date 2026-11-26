/*
 * put_call_option_chain_data.h
 *
 * 
 */

#ifndef _put_call_option_chain_data_H_
#define _put_call_option_chain_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct put_call_option_chain_data_t put_call_option_chain_data_t;

#include "analytics_data.h"
#include "market_data.h"



typedef struct put_call_option_chain_data_t {
    char *instrument_key; // string
    struct market_data_t *market_data; //model
    struct analytics_data_t *option_greeks; //model

    int _library_owned; // Is the library responsible for freeing this object?
} put_call_option_chain_data_t;

put_call_option_chain_data_t *put_call_option_chain_data_create(
    char *instrument_key,
    market_data_t *market_data,
    analytics_data_t *option_greeks
);

void put_call_option_chain_data_free(put_call_option_chain_data_t *put_call_option_chain_data);

put_call_option_chain_data_t *put_call_option_chain_data_parseFromJSON(cJSON *put_call_option_chain_dataJSON);

cJSON *put_call_option_chain_data_convertToJSON(put_call_option_chain_data_t *put_call_option_chain_data);

#endif /* _put_call_option_chain_data_H_ */

