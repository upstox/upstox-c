/*
 * income_statement_entry.h
 *
 * 
 */

#ifndef _income_statement_entry_H_
#define _income_statement_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct income_statement_entry_t income_statement_entry_t;

#include "history_item.h"



typedef struct income_statement_entry_t {
    char *category; // string
    list_t *history; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} income_statement_entry_t;

income_statement_entry_t *income_statement_entry_create(
    char *category,
    list_t *history
);

void income_statement_entry_free(income_statement_entry_t *income_statement_entry);

income_statement_entry_t *income_statement_entry_parseFromJSON(cJSON *income_statement_entryJSON);

cJSON *income_statement_entry_convertToJSON(income_statement_entry_t *income_statement_entry);

#endif /* _income_statement_entry_H_ */

