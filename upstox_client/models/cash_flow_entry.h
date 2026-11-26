/*
 * cash_flow_entry.h
 *
 * 
 */

#ifndef _cash_flow_entry_H_
#define _cash_flow_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_flow_entry_t cash_flow_entry_t;

#include "history_item.h"



typedef struct cash_flow_entry_t {
    char *category; // string
    list_t *history; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} cash_flow_entry_t;

cash_flow_entry_t *cash_flow_entry_create(
    char *category,
    list_t *history
);

void cash_flow_entry_free(cash_flow_entry_t *cash_flow_entry);

cash_flow_entry_t *cash_flow_entry_parseFromJSON(cJSON *cash_flow_entryJSON);

cJSON *cash_flow_entry_convertToJSON(cash_flow_entry_t *cash_flow_entry);

#endif /* _cash_flow_entry_H_ */

