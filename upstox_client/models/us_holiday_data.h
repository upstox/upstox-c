/*
 * us_holiday_data.h
 *
 * 
 */

#ifndef _us_holiday_data_H_
#define _us_holiday_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_holiday_data_t us_holiday_data_t;


// Enum HOLIDAYTYPE for us_holiday_data

typedef enum  { upstox_client_us_holiday_data_HOLIDAYTYPE_NULL = 0, upstox_client_us_holiday_data_HOLIDAYTYPE_ALL, upstox_client_us_holiday_data_HOLIDAYTYPE_SETTLEMENT_HOLIDAY, upstox_client_us_holiday_data_HOLIDAYTYPE_TRADING_HOLIDAY, upstox_client_us_holiday_data_HOLIDAYTYPE_SPECIAL_TIMING } upstox_client_us_holiday_data_HOLIDAYTYPE_e;

char* us_holiday_data_holiday_type_ToString(upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type);

upstox_client_us_holiday_data_HOLIDAYTYPE_e us_holiday_data_holiday_type_FromString(char* holiday_type);



typedef struct us_holiday_data_t {
    char *date; // string
    upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} us_holiday_data_t;

us_holiday_data_t *us_holiday_data_create(
    char *date,
    upstox_client_us_holiday_data_HOLIDAYTYPE_e holiday_type
);

void us_holiday_data_free(us_holiday_data_t *us_holiday_data);

us_holiday_data_t *us_holiday_data_parseFromJSON(cJSON *us_holiday_dataJSON);

cJSON *us_holiday_data_convertToJSON(us_holiday_data_t *us_holiday_data);

#endif /* _us_holiday_data_H_ */

