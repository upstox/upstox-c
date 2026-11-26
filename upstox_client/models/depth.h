/*
 * depth.h
 *
 * 
 */

#ifndef _depth_H_
#define _depth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct depth_t depth_t;




typedef struct depth_t {
    int *quantity; //numeric
    double *price; //numeric
    int *orders; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} depth_t;

depth_t *depth_create(
    int *quantity,
    double *price,
    int *orders
);

void depth_free(depth_t *depth);

depth_t *depth_parseFromJSON(cJSON *depthJSON);

cJSON *depth_convertToJSON(depth_t *depth);

#endif /* _depth_H_ */

