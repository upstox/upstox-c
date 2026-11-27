/*
 * analytics_data.h
 *
 * 
 */

#ifndef _analytics_data_H_
#define _analytics_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct analytics_data_t analytics_data_t;




typedef struct analytics_data_t {
    double *vega; //numeric
    double *theta; //numeric
    double *gamma; //numeric
    double *delta; //numeric
    double *iv; //numeric
    double *pop; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} analytics_data_t;

analytics_data_t *analytics_data_create(
    double *vega,
    double *theta,
    double *gamma,
    double *delta,
    double *iv,
    double *pop
);

void analytics_data_free(analytics_data_t *analytics_data);

analytics_data_t *analytics_data_parseFromJSON(cJSON *analytics_dataJSON);

cJSON *analytics_data_convertToJSON(analytics_data_t *analytics_data);

#endif /* _analytics_data_H_ */

