/*
 * share_holding_data.h
 *
 * 
 */

#ifndef _share_holding_data_H_
#define _share_holding_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct share_holding_data_t share_holding_data_t;

#include "history_item.h"



typedef struct share_holding_data_t {
    char *category; // string
    list_t *history; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} share_holding_data_t;

share_holding_data_t *share_holding_data_create(
    char *category,
    list_t *history
);

void share_holding_data_free(share_holding_data_t *share_holding_data);

share_holding_data_t *share_holding_data_parseFromJSON(cJSON *share_holding_dataJSON);

cJSON *share_holding_data_convertToJSON(share_holding_data_t *share_holding_data);

#endif /* _share_holding_data_H_ */

