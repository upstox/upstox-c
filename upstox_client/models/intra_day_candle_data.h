/*
 * intra_day_candle_data.h
 *
 * 
 */

#ifndef _intra_day_candle_data_H_
#define _intra_day_candle_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct intra_day_candle_data_t intra_day_candle_data_t;

#include "any_type.h"



typedef struct intra_day_candle_data_t {
    list_t *candles; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} intra_day_candle_data_t;

intra_day_candle_data_t *intra_day_candle_data_create(
    list_t *candles
);

void intra_day_candle_data_free(intra_day_candle_data_t *intra_day_candle_data);

intra_day_candle_data_t *intra_day_candle_data_parseFromJSON(cJSON *intra_day_candle_dataJSON);

cJSON *intra_day_candle_data_convertToJSON(intra_day_candle_data_t *intra_day_candle_data);

#endif /* _intra_day_candle_data_H_ */

