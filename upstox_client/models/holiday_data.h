/*
 * holiday_data.h
 *
 * 
 */

#ifndef _holiday_data_H_
#define _holiday_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct holiday_data_t holiday_data_t;

#include "exchange_timing_data.h"

// Enum HOLIDAYTYPE for holiday_data

typedef enum  { upstox_client_holiday_data_HOLIDAYTYPE_NULL = 0, upstox_client_holiday_data_HOLIDAYTYPE_ALL, upstox_client_holiday_data_HOLIDAYTYPE_SETTLEMENT_HOLIDAY, upstox_client_holiday_data_HOLIDAYTYPE_TRADING_HOLIDAY, upstox_client_holiday_data_HOLIDAYTYPE_SPECIAL_TIMING } upstox_client_holiday_data_HOLIDAYTYPE_e;

char* holiday_data_holiday_type_ToString(upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type);

upstox_client_holiday_data_HOLIDAYTYPE_e holiday_data_holiday_type_FromString(char* holiday_type);



typedef struct holiday_data_t {
    char *date; //date time
    char *description; // string
    upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type; //enum
    list_t *closed_exchanges; //primitive container
    list_t *open_exchanges; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} holiday_data_t;

holiday_data_t *holiday_data_create(
    char *date,
    char *description,
    upstox_client_holiday_data_HOLIDAYTYPE_e holiday_type,
    list_t *closed_exchanges,
    list_t *open_exchanges
);

void holiday_data_free(holiday_data_t *holiday_data);

holiday_data_t *holiday_data_parseFromJSON(cJSON *holiday_dataJSON);

cJSON *holiday_data_convertToJSON(holiday_data_t *holiday_data);

#endif /* _holiday_data_H_ */

