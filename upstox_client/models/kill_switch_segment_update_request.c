#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kill_switch_segment_update_request.h"


char* kill_switch_segment_update_request_segment_ToString(upstox_client_kill_switch_segment_update_request_SEGMENT_e segment) {
    char* segmentArray[] =  { "NULL", "BSE_EQ", "NSE_EQ", "NCD_FO", "BCD_FO", "NSE_FO", "BSE_FO", "BSE_MF", "MCX_FO", "NSE_COM" };
    return segmentArray[segment];
}

upstox_client_kill_switch_segment_update_request_SEGMENT_e kill_switch_segment_update_request_segment_FromString(char* segment){
    int stringToReturn = 0;
    char *segmentArray[] =  { "NULL", "BSE_EQ", "NSE_EQ", "NCD_FO", "BCD_FO", "NSE_FO", "BSE_FO", "BSE_MF", "MCX_FO", "NSE_COM" };
    size_t sizeofArray = sizeof(segmentArray) / sizeof(segmentArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(segment, segmentArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* kill_switch_segment_update_request_action_ToString(upstox_client_kill_switch_segment_update_request_ACTION_e action) {
    char* actionArray[] =  { "NULL", "ENABLE", "DISABLE" };
    return actionArray[action];
}

upstox_client_kill_switch_segment_update_request_ACTION_e kill_switch_segment_update_request_action_FromString(char* action){
    int stringToReturn = 0;
    char *actionArray[] =  { "NULL", "ENABLE", "DISABLE" };
    size_t sizeofArray = sizeof(actionArray) / sizeof(actionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(action, actionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static kill_switch_segment_update_request_t *kill_switch_segment_update_request_create_internal(
    upstox_client_kill_switch_segment_update_request_SEGMENT_e segment,
    upstox_client_kill_switch_segment_update_request_ACTION_e action
    ) {
    kill_switch_segment_update_request_t *kill_switch_segment_update_request_local_var = malloc(sizeof(kill_switch_segment_update_request_t));
    if (!kill_switch_segment_update_request_local_var) {
        return NULL;
    }
    memset(kill_switch_segment_update_request_local_var, 0, sizeof(kill_switch_segment_update_request_t));
    kill_switch_segment_update_request_local_var->_library_owned = 1;
    kill_switch_segment_update_request_local_var->segment = segment;
    kill_switch_segment_update_request_local_var->action = action;
    return kill_switch_segment_update_request_local_var;
}

kill_switch_segment_update_request_t *kill_switch_segment_update_request_create(
    upstox_client_kill_switch_segment_update_request_SEGMENT_e segment,
    upstox_client_kill_switch_segment_update_request_ACTION_e action
    ) {
    kill_switch_segment_update_request_t *result = kill_switch_segment_update_request_create_internal (
        segment,
        action
        );
    if (!result) {
    }
    return result;
}

void kill_switch_segment_update_request_free(kill_switch_segment_update_request_t *kill_switch_segment_update_request) {
    if(NULL == kill_switch_segment_update_request){
        return ;
    }
    if(kill_switch_segment_update_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kill_switch_segment_update_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(kill_switch_segment_update_request);
}

cJSON *kill_switch_segment_update_request_convertToJSON(kill_switch_segment_update_request_t *kill_switch_segment_update_request) {
    cJSON *item = cJSON_CreateObject();

    // kill_switch_segment_update_request->segment
    if (upstox_client_kill_switch_segment_update_request_SEGMENT_NULL == kill_switch_segment_update_request->segment) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "segment", kill_switch_segment_update_request_segment_ToString(kill_switch_segment_update_request->segment)) == NULL)
    {
    goto fail; //Enum
    }


    // kill_switch_segment_update_request->action
    if (upstox_client_kill_switch_segment_update_request_ACTION_NULL == kill_switch_segment_update_request->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", kill_switch_segment_update_request_action_ToString(kill_switch_segment_update_request->action)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kill_switch_segment_update_request_t *kill_switch_segment_update_request_parseFromJSON(cJSON *kill_switch_segment_update_requestJSON){

    kill_switch_segment_update_request_t *kill_switch_segment_update_request_local_var = NULL;

    // kill_switch_segment_update_request->segment
    cJSON *segment = cJSON_GetObjectItemCaseSensitive(kill_switch_segment_update_requestJSON, "segment");
    if (cJSON_IsNull(segment)) {
        segment = NULL;
    }
    if (!segment) {
        goto end;
    }

    upstox_client_kill_switch_segment_update_request_SEGMENT_e segmentVariable;
    
    if(!cJSON_IsString(segment))
    {
    goto end; //Enum
    }
    segmentVariable = kill_switch_segment_update_request_segment_FromString(segment->valuestring);

    // kill_switch_segment_update_request->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(kill_switch_segment_update_requestJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    upstox_client_kill_switch_segment_update_request_ACTION_e actionVariable;
    
    if(!cJSON_IsString(action))
    {
    goto end; //Enum
    }
    actionVariable = kill_switch_segment_update_request_action_FromString(action->valuestring);



    kill_switch_segment_update_request_local_var = kill_switch_segment_update_request_create_internal (
        segmentVariable,
        actionVariable
        );

    if (!kill_switch_segment_update_request_local_var) {
        goto end;
    }

    return kill_switch_segment_update_request_local_var;
end:
    return NULL;

}
