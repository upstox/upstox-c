/*
 * option_strike_data.h
 *
 * 
 */

#ifndef _option_strike_data_H_
#define _option_strike_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct option_strike_data_t option_strike_data_t;

#include "put_call_option_chain_data.h"



typedef struct option_strike_data_t {
    char *expiry; //date time
    double *pcr; //numeric
    double *strike_price; //numeric
    char *underlying_key; // string
    double *underlying_spot_price; //numeric
    struct put_call_option_chain_data_t *call_options; //model
    struct put_call_option_chain_data_t *put_options; //model

    int _library_owned; // Is the library responsible for freeing this object?
} option_strike_data_t;

option_strike_data_t *option_strike_data_create(
    char *expiry,
    double *pcr,
    double *strike_price,
    char *underlying_key,
    double *underlying_spot_price,
    put_call_option_chain_data_t *call_options,
    put_call_option_chain_data_t *put_options
);

void option_strike_data_free(option_strike_data_t *option_strike_data);

option_strike_data_t *option_strike_data_parseFromJSON(cJSON *option_strike_dataJSON);

cJSON *option_strike_data_convertToJSON(option_strike_data_t *option_strike_data);

#endif /* _option_strike_data_H_ */

