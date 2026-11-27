/*
 * batch_execution_summary.h
 *
 * 
 */

#ifndef _batch_execution_summary_H_
#define _batch_execution_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct batch_execution_summary_t batch_execution_summary_t;




typedef struct batch_execution_summary_t {
    int *total; //numeric
    int *success; //numeric
    int *error; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} batch_execution_summary_t;

batch_execution_summary_t *batch_execution_summary_create(
    int *total,
    int *success,
    int *error
);

void batch_execution_summary_free(batch_execution_summary_t *batch_execution_summary);

batch_execution_summary_t *batch_execution_summary_parseFromJSON(cJSON *batch_execution_summaryJSON);

cJSON *batch_execution_summary_convertToJSON(batch_execution_summary_t *batch_execution_summary);

#endif /* _batch_execution_summary_H_ */

