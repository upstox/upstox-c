#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "update_user_ip_request.h"



static update_user_ip_request_t *update_user_ip_request_create_internal(
    char *primary_ip,
    char *secondary_ip
    ) {
    update_user_ip_request_t *update_user_ip_request_local_var = malloc(sizeof(update_user_ip_request_t));
    if (!update_user_ip_request_local_var) {
        return NULL;
    }
    memset(update_user_ip_request_local_var, 0, sizeof(update_user_ip_request_t));
    update_user_ip_request_local_var->_library_owned = 1;
    update_user_ip_request_local_var->primary_ip = primary_ip;
    update_user_ip_request_local_var->secondary_ip = secondary_ip;
    return update_user_ip_request_local_var;
}

update_user_ip_request_t *update_user_ip_request_create(
    char *primary_ip,
    char *secondary_ip
    ) {
    update_user_ip_request_t *result = update_user_ip_request_create_internal (
        primary_ip,
        secondary_ip
        );
    if (!result) {
    }
    return result;
}

void update_user_ip_request_free(update_user_ip_request_t *update_user_ip_request) {
    if(NULL == update_user_ip_request){
        return ;
    }
    if(update_user_ip_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "update_user_ip_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (update_user_ip_request->primary_ip) {
        free(update_user_ip_request->primary_ip);
        update_user_ip_request->primary_ip = NULL;
    }
    if (update_user_ip_request->secondary_ip) {
        free(update_user_ip_request->secondary_ip);
        update_user_ip_request->secondary_ip = NULL;
    }
    free(update_user_ip_request);
}

cJSON *update_user_ip_request_convertToJSON(update_user_ip_request_t *update_user_ip_request) {
    cJSON *item = cJSON_CreateObject();

    // update_user_ip_request->primary_ip
    if(update_user_ip_request->primary_ip) {
    if(cJSON_AddStringToObject(item, "primary_ip", update_user_ip_request->primary_ip) == NULL) {
    goto fail; //String
    }
    }


    // update_user_ip_request->secondary_ip
    if(update_user_ip_request->secondary_ip) {
    if(cJSON_AddStringToObject(item, "secondary_ip", update_user_ip_request->secondary_ip) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

update_user_ip_request_t *update_user_ip_request_parseFromJSON(cJSON *update_user_ip_requestJSON){

    update_user_ip_request_t *update_user_ip_request_local_var = NULL;

    char *primary_ip_local_str = NULL;

    char *secondary_ip_local_str = NULL;

    // update_user_ip_request->primary_ip
    cJSON *primary_ip = cJSON_GetObjectItemCaseSensitive(update_user_ip_requestJSON, "primary_ip");
    if (cJSON_IsNull(primary_ip)) {
        primary_ip = NULL;
    }
    if (primary_ip) { 
    if(!cJSON_IsString(primary_ip) && !cJSON_IsNull(primary_ip))
    {
    goto end; //String
    }
    }

    // update_user_ip_request->secondary_ip
    cJSON *secondary_ip = cJSON_GetObjectItemCaseSensitive(update_user_ip_requestJSON, "secondary_ip");
    if (cJSON_IsNull(secondary_ip)) {
        secondary_ip = NULL;
    }
    if (secondary_ip) { 
    if(!cJSON_IsString(secondary_ip) && !cJSON_IsNull(secondary_ip))
    {
    goto end; //String
    }
    }


    if (primary_ip && !cJSON_IsNull(primary_ip)) primary_ip_local_str = strdup(primary_ip->valuestring);
    if (secondary_ip && !cJSON_IsNull(secondary_ip)) secondary_ip_local_str = strdup(secondary_ip->valuestring);

    update_user_ip_request_local_var = update_user_ip_request_create_internal (
        primary_ip_local_str,
        secondary_ip_local_str
        );

    if (!update_user_ip_request_local_var) {
        goto end;
    }

    return update_user_ip_request_local_var;
end:
    if (primary_ip_local_str) {
        free(primary_ip_local_str);
        primary_ip_local_str = NULL;
    }
    if (secondary_ip_local_str) {
        free(secondary_ip_local_str);
        secondary_ip_local_str = NULL;
    }
    return NULL;

}
