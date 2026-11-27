/*
 * cash_flow_data.h
 *
 * 
 */

#ifndef _cash_flow_data_H_
#define _cash_flow_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cash_flow_data_t cash_flow_data_t;

#include "cash_flow_entry.h"
#include "financial_statement_entry.h"



typedef struct cash_flow_data_t {
    char *type; // string
    char *time_period; // string
    char *units_in; // string
    list_t *cash_flow; //nonprimitive container
    list_t *full_statement; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} cash_flow_data_t;

cash_flow_data_t *cash_flow_data_create(
    char *type,
    char *time_period,
    char *units_in,
    list_t *cash_flow,
    list_t *full_statement
);

void cash_flow_data_free(cash_flow_data_t *cash_flow_data);

cash_flow_data_t *cash_flow_data_parseFromJSON(cJSON *cash_flow_dataJSON);

cJSON *cash_flow_data_convertToJSON(cash_flow_data_t *cash_flow_data);

#endif /* _cash_flow_data_H_ */

