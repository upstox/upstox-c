#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "websocket_auth_redirect_response_data.h"



static websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_create_internal(
    char *authorized_redirect_uri
    ) {
    websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_local_var = malloc(sizeof(websocket_auth_redirect_response_data_t));
    if (!websocket_auth_redirect_response_data_local_var) {
        return NULL;
    }
    memset(websocket_auth_redirect_response_data_local_var, 0, sizeof(websocket_auth_redirect_response_data_t));
    websocket_auth_redirect_response_data_local_var->_library_owned = 1;
    websocket_auth_redirect_response_data_local_var->authorized_redirect_uri = authorized_redirect_uri;
    return websocket_auth_redirect_response_data_local_var;
}

websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_create(
    char *authorized_redirect_uri
    ) {
    websocket_auth_redirect_response_data_t *result = websocket_auth_redirect_response_data_create_internal (
        authorized_redirect_uri
        );
    if (!result) {
    }
    return result;
}

void websocket_auth_redirect_response_data_free(websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data) {
    if(NULL == websocket_auth_redirect_response_data){
        return ;
    }
    if(websocket_auth_redirect_response_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "websocket_auth_redirect_response_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (websocket_auth_redirect_response_data->authorized_redirect_uri) {
        free(websocket_auth_redirect_response_data->authorized_redirect_uri);
        websocket_auth_redirect_response_data->authorized_redirect_uri = NULL;
    }
    free(websocket_auth_redirect_response_data);
}

cJSON *websocket_auth_redirect_response_data_convertToJSON(websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data) {
    cJSON *item = cJSON_CreateObject();

    // websocket_auth_redirect_response_data->authorized_redirect_uri
    if(websocket_auth_redirect_response_data->authorized_redirect_uri) {
    if(cJSON_AddStringToObject(item, "authorized_redirect_uri", websocket_auth_redirect_response_data->authorized_redirect_uri) == NULL) {
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

websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_parseFromJSON(cJSON *websocket_auth_redirect_response_dataJSON){

    websocket_auth_redirect_response_data_t *websocket_auth_redirect_response_data_local_var = NULL;

    char *authorized_redirect_uri_local_str = NULL;

    // websocket_auth_redirect_response_data->authorized_redirect_uri
    cJSON *authorized_redirect_uri = cJSON_GetObjectItemCaseSensitive(websocket_auth_redirect_response_dataJSON, "authorized_redirect_uri");
    if (cJSON_IsNull(authorized_redirect_uri)) {
        authorized_redirect_uri = NULL;
    }
    if (authorized_redirect_uri) { 
    if(!cJSON_IsString(authorized_redirect_uri) && !cJSON_IsNull(authorized_redirect_uri))
    {
    goto end; //String
    }
    }


    if (authorized_redirect_uri && !cJSON_IsNull(authorized_redirect_uri)) authorized_redirect_uri_local_str = strdup(authorized_redirect_uri->valuestring);

    websocket_auth_redirect_response_data_local_var = websocket_auth_redirect_response_data_create_internal (
        authorized_redirect_uri_local_str
        );

    if (!websocket_auth_redirect_response_data_local_var) {
        goto end;
    }

    return websocket_auth_redirect_response_data_local_var;
end:
    if (authorized_redirect_uri_local_str) {
        free(authorized_redirect_uri_local_str);
        authorized_redirect_uri_local_str = NULL;
    }
    return NULL;

}
