/*
 * margin_data.h
 *
 * 
 */

#ifndef _margin_data_H_
#define _margin_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct margin_data_t margin_data_t;

#include "margin.h"



typedef struct margin_data_t {
    list_t *margins; //nonprimitive container
    double *required_margin; //numeric
    double *final_margin; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} margin_data_t;

margin_data_t *margin_data_create(
    list_t *margins,
    double *required_margin,
    double *final_margin
);

void margin_data_free(margin_data_t *margin_data);

margin_data_t *margin_data_parseFromJSON(cJSON *margin_dataJSON);

cJSON *margin_data_convertToJSON(margin_data_t *margin_data);

#endif /* _margin_data_H_ */

