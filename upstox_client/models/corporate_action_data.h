/*
 * corporate_action_data.h
 *
 * 
 */

#ifndef _corporate_action_data_H_
#define _corporate_action_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct corporate_action_data_t corporate_action_data_t;

#include "corporate_action_event_detail.h"



typedef struct corporate_action_data_t {
    char *name; // string
    char *expiry_date; // string
    double *amount; //numeric
    char *ratio; // string
    list_t *event_details; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} corporate_action_data_t;

corporate_action_data_t *corporate_action_data_create(
    char *name,
    char *expiry_date,
    double *amount,
    char *ratio,
    list_t *event_details
);

void corporate_action_data_free(corporate_action_data_t *corporate_action_data);

corporate_action_data_t *corporate_action_data_parseFromJSON(cJSON *corporate_action_dataJSON);

cJSON *corporate_action_data_convertToJSON(corporate_action_data_t *corporate_action_data);

#endif /* _corporate_action_data_H_ */

