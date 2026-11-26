/*
 * balance_sheet_data.h
 *
 * 
 */

#ifndef _balance_sheet_data_H_
#define _balance_sheet_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct balance_sheet_data_t balance_sheet_data_t;

#include "balance_sheet_history_item.h"
#include "financial_statement_entry.h"



typedef struct balance_sheet_data_t {
    char *type; // string
    char *time_period; // string
    char *units_in; // string
    list_t *history; //nonprimitive container
    list_t *full_statement; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} balance_sheet_data_t;

balance_sheet_data_t *balance_sheet_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *history,
    list_t *full_statement
);

void balance_sheet_data_free(balance_sheet_data_t *balance_sheet_data);

balance_sheet_data_t *balance_sheet_data_parseFromJSON(cJSON *balance_sheet_dataJSON);

cJSON *balance_sheet_data_convertToJSON(balance_sheet_data_t *balance_sheet_data);

#endif /* _balance_sheet_data_H_ */

