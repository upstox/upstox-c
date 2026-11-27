/*
 * us_margin_data.h
 *
 * 
 */

#ifndef _us_margin_data_H_
#define _us_margin_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct us_margin_data_t us_margin_data_t;

#include "us_order_margin.h"



typedef struct us_margin_data_t {
    list_t *margins; //nonprimitive container
    double *shortfall; //numeric
    int *sufficient; //boolean
    double *required_margin; //numeric
    double *available_to_invest; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} us_margin_data_t;

us_margin_data_t *us_margin_data_create(
    list_t *margins,
    double *shortfall,
    int *sufficient,
    double *required_margin,
    double *available_to_invest
);

void us_margin_data_free(us_margin_data_t *us_margin_data);

us_margin_data_t *us_margin_data_parseFromJSON(cJSON *us_margin_dataJSON);

cJSON *us_margin_data_convertToJSON(us_margin_data_t *us_margin_data);

#endif /* _us_margin_data_H_ */

