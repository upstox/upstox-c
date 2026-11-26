/*
 * cas_eligible_status_data.h
 *
 * 
 */

#ifndef _cas_eligible_status_data_H_
#define _cas_eligible_status_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cas_eligible_status_data_t cas_eligible_status_data_t;


// Enum STATUS for cas_eligible_status_data

typedef enum  { upstox_client_cas_eligible_status_data_STATUS_NULL = 0, upstox_client_cas_eligible_status_data_STATUS_NORMAL_OPEN, upstox_client_cas_eligible_status_data_STATUS_NORMAL_CLOSE, upstox_client_cas_eligible_status_data_STATUS_PRE_OPEN_START, upstox_client_cas_eligible_status_data_STATUS_PRE_OPEN_END, upstox_client_cas_eligible_status_data_STATUS_CLOSING_START, upstox_client_cas_eligible_status_data_STATUS_CLOSING_END, upstox_client_cas_eligible_status_data_STATUS_CTS_CLOSE, upstox_client_cas_eligible_status_data_STATUS_CAS_LM_START, upstox_client_cas_eligible_status_data_STATUS_CAS_M_STOP, upstox_client_cas_eligible_status_data_STATUS_CAS_STOP } upstox_client_cas_eligible_status_data_STATUS_e;

char* cas_eligible_status_data_status_ToString(upstox_client_cas_eligible_status_data_STATUS_e status);

upstox_client_cas_eligible_status_data_STATUS_e cas_eligible_status_data_status_FromString(char* status);



typedef struct cas_eligible_status_data_t {
    upstox_client_cas_eligible_status_data_STATUS_e status; //enum
    long *last_updated; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cas_eligible_status_data_t;

cas_eligible_status_data_t *cas_eligible_status_data_create(
    upstox_client_cas_eligible_status_data_STATUS_e status,
    long *last_updated
);

void cas_eligible_status_data_free(cas_eligible_status_data_t *cas_eligible_status_data);

cas_eligible_status_data_t *cas_eligible_status_data_parseFromJSON(cJSON *cas_eligible_status_dataJSON);

cJSON *cas_eligible_status_data_convertToJSON(cas_eligible_status_data_t *cas_eligible_status_data);

#endif /* _cas_eligible_status_data_H_ */

