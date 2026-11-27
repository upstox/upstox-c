/*
 * historical_candle_data.h
 *
 * 
 */

#ifndef _historical_candle_data_H_
#define _historical_candle_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct historical_candle_data_t historical_candle_data_t;

#include "any_type.h"



typedef struct historical_candle_data_t {
    list_t *candles; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} historical_candle_data_t;

historical_candle_data_t *historical_candle_data_create(
    list_t *candles
);

void historical_candle_data_free(historical_candle_data_t *historical_candle_data);

historical_candle_data_t *historical_candle_data_parseFromJSON(cJSON *historical_candle_dataJSON);

cJSON *historical_candle_data_convertToJSON(historical_candle_data_t *historical_candle_data);

#endif /* _historical_candle_data_H_ */

