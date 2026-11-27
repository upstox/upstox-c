/*
 * loss.h
 *
 * 
 */

#ifndef _loss_H_
#define _loss_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct loss_t loss_t;




typedef struct loss_t {
    double *total; //numeric
    double *realised; //numeric
    double *unrealised; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} loss_t;

loss_t *loss_create(
    double *total,
    double *realised,
    double *unrealised
);

void loss_free(loss_t *loss);

loss_t *loss_parseFromJSON(cJSON *lossJSON);

cJSON *loss_convertToJSON(loss_t *loss);

#endif /* _loss_H_ */

