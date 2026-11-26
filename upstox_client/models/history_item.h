/*
 * history_item.h
 *
 * 
 */

#ifndef _history_item_H_
#define _history_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct history_item_t history_item_t;




typedef struct history_item_t {
    double *value; //numeric
    char *period; // string
    char *change; // string

    int _library_owned; // Is the library responsible for freeing this object?
} history_item_t;

history_item_t *history_item_create(
    double *value,
    char *period,
    char *change
);

void history_item_free(history_item_t *history_item);

history_item_t *history_item_parseFromJSON(cJSON *history_itemJSON);

cJSON *history_item_convertToJSON(history_item_t *history_item);

#endif /* _history_item_H_ */

