/*
 * income_statement_data.h
 *
 * 
 */

#ifndef _income_statement_data_H_
#define _income_statement_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct income_statement_data_t income_statement_data_t;

#include "financial_statement_entry.h"
#include "income_statement_entry.h"



typedef struct income_statement_data_t {
    char *type; // string
    char *time_period; // string
    char *units_in; // string
    list_t *income_statement; //nonprimitive container
    list_t *full_statement; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} income_statement_data_t;

income_statement_data_t *income_statement_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *income_statement,
    list_t *full_statement
);

void income_statement_data_free(income_statement_data_t *income_statement_data);

income_statement_data_t *income_statement_data_parseFromJSON(cJSON *income_statement_dataJSON);

cJSON *income_statement_data_convertToJSON(income_statement_data_t *income_statement_data);

#endif /* _income_statement_data_H_ */

