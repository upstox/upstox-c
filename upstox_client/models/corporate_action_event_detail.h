/*
 * corporate_action_event_detail.h
 *
 * 
 */

#ifndef _corporate_action_event_detail_H_
#define _corporate_action_event_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct corporate_action_event_detail_t corporate_action_event_detail_t;




typedef struct corporate_action_event_detail_t {
    char *name; // string
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} corporate_action_event_detail_t;

corporate_action_event_detail_t *corporate_action_event_detail_create(
    char *name,
    char *value
);

void corporate_action_event_detail_free(corporate_action_event_detail_t *corporate_action_event_detail);

corporate_action_event_detail_t *corporate_action_event_detail_parseFromJSON(cJSON *corporate_action_event_detailJSON);

cJSON *corporate_action_event_detail_convertToJSON(corporate_action_event_detail_t *corporate_action_event_detail);

#endif /* _corporate_action_event_detail_H_ */

