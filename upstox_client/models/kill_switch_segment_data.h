/*
 * kill_switch_segment_data.h
 *
 * 
 */

#ifndef _kill_switch_segment_data_H_
#define _kill_switch_segment_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kill_switch_segment_data_t kill_switch_segment_data_t;


// Enum SEGMENTSTATUS for kill_switch_segment_data

typedef enum  { upstox_client_kill_switch_segment_data_SEGMENTSTATUS_NULL = 0, upstox_client_kill_switch_segment_data_SEGMENTSTATUS_ACTIVE, upstox_client_kill_switch_segment_data_SEGMENTSTATUS_INACTIVE } upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e;

char* kill_switch_segment_data_segment_status_ToString(upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status);

upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e kill_switch_segment_data_segment_status_FromString(char* segment_status);



typedef struct kill_switch_segment_data_t {
    char *segment; // string
    upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status; //enum
    int *kill_switch_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} kill_switch_segment_data_t;

kill_switch_segment_data_t *kill_switch_segment_data_create(
    char *segment,
    upstox_client_kill_switch_segment_data_SEGMENTSTATUS_e segment_status,
    int *kill_switch_enabled
);

void kill_switch_segment_data_free(kill_switch_segment_data_t *kill_switch_segment_data);

kill_switch_segment_data_t *kill_switch_segment_data_parseFromJSON(cJSON *kill_switch_segment_dataJSON);

cJSON *kill_switch_segment_data_convertToJSON(kill_switch_segment_data_t *kill_switch_segment_data);

#endif /* _kill_switch_segment_data_H_ */

