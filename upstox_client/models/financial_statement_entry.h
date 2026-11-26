/*
 * financial_statement_entry.h
 *
 * 
 */

#ifndef _financial_statement_entry_H_
#define _financial_statement_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct financial_statement_entry_t financial_statement_entry_t;

#include "history_item.h"



typedef struct financial_statement_entry_t {
    char *particular; // string
    list_t *history; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} financial_statement_entry_t;

financial_statement_entry_t *financial_statement_entry_create(
    char *particular,
    list_t *history
);

void financial_statement_entry_free(financial_statement_entry_t *financial_statement_entry);

financial_statement_entry_t *financial_statement_entry_parseFromJSON(cJSON *financial_statement_entryJSON);

cJSON *financial_statement_entry_convertToJSON(financial_statement_entry_t *financial_statement_entry);

#endif /* _financial_statement_entry_H_ */

