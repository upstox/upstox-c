#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cas_eligible_status_data.h"


char* cas_eligible_status_data_status_ToString(upstox_client_cas_eligible_status_data_STATUS_e status) {
    char* statusArray[] =  { "NULL", "NORMAL_OPEN", "NORMAL_CLOSE", "PRE_OPEN_START", "PRE_OPEN_END", "CLOSING_START", "CLOSING_END", "CTS_CLOSE", "CAS_LM_START", "CAS_M_STOP", "CAS_STOP" };
    return statusArray[status];
}

upstox_client_cas_eligible_status_data_STATUS_e cas_eligible_status_data_status_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "NULL", "NORMAL_OPEN", "NORMAL_CLOSE", "PRE_OPEN_START", "PRE_OPEN_END", "CLOSING_START", "CLOSING_END", "CTS_CLOSE", "CAS_LM_START", "CAS_M_STOP", "CAS_STOP" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static cas_eligible_status_data_t *cas_eligible_status_data_create_internal(
    upstox_client_cas_eligible_status_data_STATUS_e status,
    long *last_updated
    ) {
    cas_eligible_status_data_t *cas_eligible_status_data_local_var = malloc(sizeof(cas_eligible_status_data_t));
    if (!cas_eligible_status_data_local_var) {
        return NULL;
    }
    memset(cas_eligible_status_data_local_var, 0, sizeof(cas_eligible_status_data_t));
    cas_eligible_status_data_local_var->_library_owned = 1;
    cas_eligible_status_data_local_var->status = status;
    cas_eligible_status_data_local_var->last_updated = last_updated;
    return cas_eligible_status_data_local_var;
}

cas_eligible_status_data_t *cas_eligible_status_data_create(
    upstox_client_cas_eligible_status_data_STATUS_e status,
    long *last_updated
    ) {
    long *last_updated_copy = NULL;
    if (last_updated) {
        last_updated_copy = malloc(sizeof(long));
        if (last_updated_copy) *last_updated_copy = *last_updated;
    }
    cas_eligible_status_data_t *result = cas_eligible_status_data_create_internal (
        status,
        last_updated_copy
        );
    if (!result) {
        free(last_updated_copy);
    }
    return result;
}

void cas_eligible_status_data_free(cas_eligible_status_data_t *cas_eligible_status_data) {
    if(NULL == cas_eligible_status_data){
        return ;
    }
    if(cas_eligible_status_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cas_eligible_status_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cas_eligible_status_data->last_updated) {
        free(cas_eligible_status_data->last_updated);
        cas_eligible_status_data->last_updated = NULL;
    }
    free(cas_eligible_status_data);
}

cJSON *cas_eligible_status_data_convertToJSON(cas_eligible_status_data_t *cas_eligible_status_data) {
    cJSON *item = cJSON_CreateObject();

    // cas_eligible_status_data->status
    if(cas_eligible_status_data->status != upstox_client_cas_eligible_status_data_STATUS_NULL) {
    if(cJSON_AddStringToObject(item, "status", cas_eligible_status_data_status_ToString(cas_eligible_status_data->status)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // cas_eligible_status_data->last_updated
    if(cas_eligible_status_data->last_updated) {
    if(cJSON_AddNumberToObject(item, "last_updated", *cas_eligible_status_data->last_updated) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cas_eligible_status_data_t *cas_eligible_status_data_parseFromJSON(cJSON *cas_eligible_status_dataJSON){

    cas_eligible_status_data_t *cas_eligible_status_data_local_var = NULL;

    // define the local variable for cas_eligible_status_data->last_updated
    long *last_updated_local_var = NULL;

    // cas_eligible_status_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(cas_eligible_status_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    upstox_client_cas_eligible_status_data_STATUS_e statusVariable;
    if (status) { 
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = cas_eligible_status_data_status_FromString(status->valuestring);
    }

    // cas_eligible_status_data->last_updated
    cJSON *last_updated = cJSON_GetObjectItemCaseSensitive(cas_eligible_status_dataJSON, "last_updated");
    if (cJSON_IsNull(last_updated)) {
        last_updated = NULL;
    }
    if (last_updated) { 
    if(!cJSON_IsNumber(last_updated))
    {
    goto end; //Numeric
    }
    last_updated_local_var = malloc(sizeof(long));
    if(!last_updated_local_var)
    {
        goto end;
    }
    *last_updated_local_var = last_updated->valuedouble;
    }



    cas_eligible_status_data_local_var = cas_eligible_status_data_create_internal (
        status ? statusVariable : upstox_client_cas_eligible_status_data_STATUS_NULL,
        last_updated_local_var
        );

    if (!cas_eligible_status_data_local_var) {
        goto end;
    }

    return cas_eligible_status_data_local_var;
end:
    if (last_updated_local_var) {
        free(last_updated_local_var);
        last_updated_local_var = NULL;
    }
    return NULL;

}
