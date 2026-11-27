/*
 * order_metadata.h
 *
 * 
 */

#ifndef _order_metadata_H_
#define _order_metadata_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct order_metadata_t order_metadata_t;




typedef struct order_metadata_t {
    long *latency; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} order_metadata_t;

order_metadata_t *order_metadata_create(
    long *latency
);

void order_metadata_free(order_metadata_t *order_metadata);

order_metadata_t *order_metadata_parseFromJSON(cJSON *order_metadataJSON);

cJSON *order_metadata_convertToJSON(order_metadata_t *order_metadata);

#endif /* _order_metadata_H_ */

