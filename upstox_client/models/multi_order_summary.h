/*
 * multi_order_summary.h
 *
 * 
 */

#ifndef _multi_order_summary_H_
#define _multi_order_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct multi_order_summary_t multi_order_summary_t;




typedef struct multi_order_summary_t {
    int *total; //numeric
    int *success; //numeric
    int *error; //numeric
    int *payload_error; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} multi_order_summary_t;

multi_order_summary_t *multi_order_summary_create(
    int *total,
    int *success,
    int *error,
    int *payload_error
);

void multi_order_summary_free(multi_order_summary_t *multi_order_summary);

multi_order_summary_t *multi_order_summary_parseFromJSON(cJSON *multi_order_summaryJSON);

cJSON *multi_order_summary_convertToJSON(multi_order_summary_t *multi_order_summary);

#endif /* _multi_order_summary_H_ */

