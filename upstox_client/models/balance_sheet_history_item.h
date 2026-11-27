/*
 * balance_sheet_history_item.h
 *
 * 
 */

#ifndef _balance_sheet_history_item_H_
#define _balance_sheet_history_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct balance_sheet_history_item_t balance_sheet_history_item_t;




typedef struct balance_sheet_history_item_t {
    double *total_asset; //numeric
    double *total_liability; //numeric
    char *period; // string

    int _library_owned; // Is the library responsible for freeing this object?
} balance_sheet_history_item_t;

balance_sheet_history_item_t *balance_sheet_history_item_create(
    double *total_asset,
    double *total_liability,
    char *period
);

void balance_sheet_history_item_free(balance_sheet_history_item_t *balance_sheet_history_item);

balance_sheet_history_item_t *balance_sheet_history_item_parseFromJSON(cJSON *balance_sheet_history_itemJSON);

cJSON *balance_sheet_history_item_convertToJSON(balance_sheet_history_item_t *balance_sheet_history_item);

#endif /* _balance_sheet_history_item_H_ */

