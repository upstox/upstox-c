#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "LoginAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Authorize API
//
// This provides details on the login endpoint.
//
void
LoginAPI_authorize(apiClient_t *apiClient, char *client_id, char *redirect_uri, char *state, char *scope)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/login/authorization/dialog");





    // query parameters
    char *keyQuery_client_id = NULL;
    char * valueQuery_client_id = NULL;
    keyValuePair_t *keyPairQuery_client_id = 0;
    if (client_id)
    {
        keyQuery_client_id = strdup("client_id");
        valueQuery_client_id = strdup((client_id));
        keyPairQuery_client_id = keyValuePair_create(keyQuery_client_id, valueQuery_client_id);
        list_addElement(localVarQueryParameters,keyPairQuery_client_id);
    }

    // query parameters
    char *keyQuery_redirect_uri = NULL;
    char * valueQuery_redirect_uri = NULL;
    keyValuePair_t *keyPairQuery_redirect_uri = 0;
    if (redirect_uri)
    {
        keyQuery_redirect_uri = strdup("redirect_uri");
        valueQuery_redirect_uri = strdup((redirect_uri));
        keyPairQuery_redirect_uri = keyValuePair_create(keyQuery_redirect_uri, valueQuery_redirect_uri);
        list_addElement(localVarQueryParameters,keyPairQuery_redirect_uri);
    }

    // query parameters
    char *keyQuery_state = NULL;
    char * valueQuery_state = NULL;
    keyValuePair_t *keyPairQuery_state = 0;
    if (state)
    {
        keyQuery_state = strdup("state");
        valueQuery_state = strdup((state));
        keyPairQuery_state = keyValuePair_create(keyQuery_state, valueQuery_state);
        list_addElement(localVarQueryParameters,keyPairQuery_state);
    }

    // query parameters
    char *keyQuery_scope = NULL;
    char * valueQuery_scope = NULL;
    keyValuePair_t *keyPairQuery_scope = 0;
    if (scope)
    {
        keyQuery_scope = strdup("scope");
        valueQuery_scope = strdup((scope));
        keyPairQuery_scope = keyValuePair_create(keyQuery_scope, valueQuery_scope);
        list_addElement(localVarQueryParameters,keyPairQuery_scope);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 302) {
    //    printf("%s\n","Successful Operation");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1018 - Redirect URI is required");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method Not Allowed");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 423) {
    //    printf("%s\n","Locked");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","Too Many Requests");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_client_id){
        free(keyQuery_client_id);
        keyQuery_client_id = NULL;
    }
    if(valueQuery_client_id){
        free(valueQuery_client_id);
        valueQuery_client_id = NULL;
    }
    if(keyPairQuery_client_id){
        keyValuePair_free(keyPairQuery_client_id);
        keyPairQuery_client_id = NULL;
    }
    if(keyQuery_client_id){
        free(keyQuery_client_id);
        keyQuery_client_id = NULL;
    }
    if(valueQuery_client_id){
        free(valueQuery_client_id);
        valueQuery_client_id = NULL;
    }
    if(keyPairQuery_client_id){
        keyValuePair_free(keyPairQuery_client_id);
        keyPairQuery_client_id = NULL;
    }
    if(keyQuery_redirect_uri){
        free(keyQuery_redirect_uri);
        keyQuery_redirect_uri = NULL;
    }
    if(valueQuery_redirect_uri){
        free(valueQuery_redirect_uri);
        valueQuery_redirect_uri = NULL;
    }
    if(keyPairQuery_redirect_uri){
        keyValuePair_free(keyPairQuery_redirect_uri);
        keyPairQuery_redirect_uri = NULL;
    }
    if(keyQuery_redirect_uri){
        free(keyQuery_redirect_uri);
        keyQuery_redirect_uri = NULL;
    }
    if(valueQuery_redirect_uri){
        free(valueQuery_redirect_uri);
        valueQuery_redirect_uri = NULL;
    }
    if(keyPairQuery_redirect_uri){
        keyValuePair_free(keyPairQuery_redirect_uri);
        keyPairQuery_redirect_uri = NULL;
    }
    if(keyQuery_state){
        free(keyQuery_state);
        keyQuery_state = NULL;
    }
    if(valueQuery_state){
        free(valueQuery_state);
        valueQuery_state = NULL;
    }
    if(keyPairQuery_state){
        keyValuePair_free(keyPairQuery_state);
        keyPairQuery_state = NULL;
    }
    if(keyQuery_state){
        free(keyQuery_state);
        keyQuery_state = NULL;
    }
    if(valueQuery_state){
        free(valueQuery_state);
        valueQuery_state = NULL;
    }
    if(keyPairQuery_state){
        keyValuePair_free(keyPairQuery_state);
        keyPairQuery_state = NULL;
    }
    if(keyQuery_scope){
        free(keyQuery_scope);
        keyQuery_scope = NULL;
    }
    if(valueQuery_scope){
        free(valueQuery_scope);
        valueQuery_scope = NULL;
    }
    if(keyPairQuery_scope){
        keyValuePair_free(keyPairQuery_scope);
        keyPairQuery_scope = NULL;
    }
    if(keyQuery_scope){
        free(keyQuery_scope);
        keyQuery_scope = NULL;
    }
    if(valueQuery_scope){
        free(valueQuery_scope);
        valueQuery_scope = NULL;
    }
    if(keyPairQuery_scope){
        keyValuePair_free(keyPairQuery_scope);
        keyPairQuery_scope = NULL;
    }

}

// Generate token using TOTP and PIN
//
// This API generates an access token for an automation client using the app's API key together with the user's 6-digit PIN and 6-digit TOTP
//
token_response_t*
LoginAPI_generateTokenViaTotpAndPin(apiClient_t *apiClient, char *x_api_key, totp_pin_token_request_t *totp_pin_token_request, char *x_user_id)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/totp-login/authorization/token");





    // header parameters
    char *keyHeader_x_api_key = NULL;
    char * valueHeader_x_api_key = 0;
    keyValuePair_t *keyPairHeader_x_api_key = 0;
    if (x_api_key) {
        keyHeader_x_api_key = strdup("x-api-key");
        valueHeader_x_api_key = strdup((x_api_key));
        keyPairHeader_x_api_key = keyValuePair_create(keyHeader_x_api_key, valueHeader_x_api_key);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_api_key);
    }


    // header parameters
    char *keyHeader_x_user_id = NULL;
    char * valueHeader_x_user_id = 0;
    keyValuePair_t *keyPairHeader_x_user_id = 0;
    if (x_user_id) {
        keyHeader_x_user_id = strdup("x-user-id");
        valueHeader_x_user_id = strdup((x_user_id));
        keyPairHeader_x_user_id = keyValuePair_create(keyHeader_x_user_id, valueHeader_x_user_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_x_user_id);
    }


    // Body Param
    cJSON *localVarSingleItemJSON_totp_pin_token_request = NULL;
    if (totp_pin_token_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_totp_pin_token_request = totp_pin_token_request_convertToJSON(totp_pin_token_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_totp_pin_token_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1241 - The &#39;pin&#39; must be exactly 6 digits &lt;br/&gt;UDAPI1242 - The &#39;totp&#39; must be exactly 6 digits &lt;br/&gt;UDAPI1248 - x-user-id header is required for multi-client apps &lt;br/&gt;UDAPI1249 - The x-user-id header must be exactly 6 alphanumeric characters &lt;br/&gt;UDAPI100098 - TOTP is not enabled for this user &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","UDAPI100096 - The API key is not registered with Upstox &lt;br/&gt;UDAPI100097 - Invalid Credentials &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","UDAPI100102 - User has not granted consent to this app &lt;br/&gt;UDAPI100103 - The x-user-id header does not match the user registered for this app &lt;br/&gt;UDAPI100104 - This app is not permitted to use multi-client TOTP login &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method Not Allowed");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 423) {
    //    printf("%s\n","Locked");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","UDAPI100099 - Too Many Request Sent &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","UDAPI100100 - Something went wrong... please contact us &lt;br/&gt;");
    //}
    //nonprimitive not container
    token_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LoginAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = token_response_parseFromJSON(LoginAPIlocalVarJSON);
        cJSON_Delete(LoginAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyHeader_x_api_key) {
        free(keyHeader_x_api_key);
        keyHeader_x_api_key = NULL;
    }
    if (valueHeader_x_api_key) {
        free(valueHeader_x_api_key);
        valueHeader_x_api_key = NULL;
    }
    free(keyPairHeader_x_api_key);
    if (keyHeader_x_user_id) {
        free(keyHeader_x_user_id);
        keyHeader_x_user_id = NULL;
    }
    if (valueHeader_x_user_id) {
        free(valueHeader_x_user_id);
        valueHeader_x_user_id = NULL;
    }
    free(keyPairHeader_x_user_id);
    if (localVarSingleItemJSON_totp_pin_token_request) {
        cJSON_Delete(localVarSingleItemJSON_totp_pin_token_request);
        localVarSingleItemJSON_totp_pin_token_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Init token API
//
// This API provides the initialize the generate token and it's expiry for an indie user
//
indie_user_init_token_response_t*
LoginAPI_initTokenRequestForIndieUser(apiClient_t *apiClient, char *client_id, indie_user_token_request_t *indie_user_token_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v3/login/auth/token/request/{client_id}");

    if(!client_id)
        goto end;


    // Path Params
    long sizeOfPathParams_client_id = strlen(client_id)+3 + sizeof("{ client_id }") - 1;
    if(client_id == NULL) {
        goto end;
    }
    char* localVarToReplace_client_id = malloc(sizeOfPathParams_client_id);
    sprintf(localVarToReplace_client_id, "{%s}", "client_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_client_id, client_id);



    // Body Param
    cJSON *localVarSingleItemJSON_indie_user_token_request = NULL;
    if (indie_user_token_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_indie_user_token_request = indie_user_token_request_convertToJSON(indie_user_token_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_indie_user_token_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1017 - API Key is required &lt;br/&gt;UDAPI1024 - App Secret is required &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method Not Allowed");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 423) {
    //    printf("%s\n","Locked");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","Too Many Requests");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    indie_user_init_token_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LoginAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = indie_user_init_token_response_parseFromJSON(LoginAPIlocalVarJSON);
        cJSON_Delete(LoginAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_client_id);
    if (localVarSingleItemJSON_indie_user_token_request) {
        cJSON_Delete(localVarSingleItemJSON_indie_user_token_request);
        localVarSingleItemJSON_indie_user_token_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Logout
//
// Logout
//
logout_response_t*
LoginAPI_logout(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/logout");




    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authorization Failure");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method Not Allowed");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 423) {
    //    printf("%s\n","Locked");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","Too Many Requests");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    logout_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LoginAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = logout_response_parseFromJSON(LoginAPIlocalVarJSON);
        cJSON_Delete(LoginAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get token API
//
// This API provides the functionality to obtain opaque token from authorization_code exchange and also provides the user’s profile in the same response.
//
token_response_t*
LoginAPI_token(apiClient_t *apiClient, char *code, char *client_id, char *client_secret, char *redirect_uri, char *grant_type, int *refresh_extended_token)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_createList();
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/login/authorization/token");





    // form parameters
    char *keyForm_code = NULL;
    char * valueForm_code = 0;
    keyValuePair_t *keyPairForm_code = 0;
    if (code != NULL)
    {
        keyForm_code = strdup("code");
        valueForm_code = strdup((code));
        keyPairForm_code = keyValuePair_create(keyForm_code,valueForm_code);
        list_addElement(localVarFormParameters,keyPairForm_code);
    }

    // form parameters
    char *keyForm_client_id = NULL;
    char * valueForm_client_id = 0;
    keyValuePair_t *keyPairForm_client_id = 0;
    if (client_id != NULL)
    {
        keyForm_client_id = strdup("client_id");
        valueForm_client_id = strdup((client_id));
        keyPairForm_client_id = keyValuePair_create(keyForm_client_id,valueForm_client_id);
        list_addElement(localVarFormParameters,keyPairForm_client_id);
    }

    // form parameters
    char *keyForm_client_secret = NULL;
    char * valueForm_client_secret = 0;
    keyValuePair_t *keyPairForm_client_secret = 0;
    if (client_secret != NULL)
    {
        keyForm_client_secret = strdup("client_secret");
        valueForm_client_secret = strdup((client_secret));
        keyPairForm_client_secret = keyValuePair_create(keyForm_client_secret,valueForm_client_secret);
        list_addElement(localVarFormParameters,keyPairForm_client_secret);
    }

    // form parameters
    char *keyForm_redirect_uri = NULL;
    char * valueForm_redirect_uri = 0;
    keyValuePair_t *keyPairForm_redirect_uri = 0;
    if (redirect_uri != NULL)
    {
        keyForm_redirect_uri = strdup("redirect_uri");
        valueForm_redirect_uri = strdup((redirect_uri));
        keyPairForm_redirect_uri = keyValuePair_create(keyForm_redirect_uri,valueForm_redirect_uri);
        list_addElement(localVarFormParameters,keyPairForm_redirect_uri);
    }

    // form parameters
    char *keyForm_grant_type = NULL;
    char * valueForm_grant_type = 0;
    keyValuePair_t *keyPairForm_grant_type = 0;
    if (grant_type != NULL)
    {
        keyForm_grant_type = strdup("grant_type");
        valueForm_grant_type = strdup((grant_type));
        keyPairForm_grant_type = keyValuePair_create(keyForm_grant_type,valueForm_grant_type);
        list_addElement(localVarFormParameters,keyPairForm_grant_type);
    }

    // form parameters
    char *keyForm_refresh_extended_token = NULL;
    char * valueForm_refresh_extended_token = 0;
    keyValuePair_t *keyPairForm_refresh_extended_token = 0;
    if (refresh_extended_token != NULL)
    {
        keyForm_refresh_extended_token = strdup("refresh_extended_token");
        valueForm_refresh_extended_token = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueForm_refresh_extended_token, MAX_NUMBER_LENGTH, "%d", *refresh_extended_token);
        keyPairForm_refresh_extended_token = keyValuePair_create(keyForm_refresh_extended_token,valueForm_refresh_extended_token);
        list_addElement(localVarFormParameters,keyPairForm_refresh_extended_token);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1017 - API Key is required &lt;br/&gt;UDAPI1018 - Redirect URI is required &lt;br/&gt;UDAPI1022 - Code is required &lt;br/&gt;UDAPI1023 - Grant type is required &lt;br/&gt;UDAPI1024 - App Secret is required &lt;br/&gt;");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 405) {
    //    printf("%s\n","Method Not Allowed");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 422) {
    //    printf("%s\n","Unprocessable Entity");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 423) {
    //    printf("%s\n","Locked");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 429) {
    //    printf("%s\n","Too Many Requests");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 500) {
    //    printf("%s\n","Internal Server Error");
    //}
    //nonprimitive not container
    token_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *LoginAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = token_response_parseFromJSON(LoginAPIlocalVarJSON);
        cJSON_Delete(LoginAPIlocalVarJSON);
        if(elementToReturn == NULL) {
            // return 0;
        }
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    list_freeList(localVarFormParameters);
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyForm_code) {
        free(keyForm_code);
        keyForm_code = NULL;
    }
    if (valueForm_code) {
        free(valueForm_code);
        valueForm_code = NULL;
    }
    free(keyPairForm_code);
    if (keyForm_client_id) {
        free(keyForm_client_id);
        keyForm_client_id = NULL;
    }
    if (valueForm_client_id) {
        free(valueForm_client_id);
        valueForm_client_id = NULL;
    }
    free(keyPairForm_client_id);
    if (keyForm_client_secret) {
        free(keyForm_client_secret);
        keyForm_client_secret = NULL;
    }
    if (valueForm_client_secret) {
        free(valueForm_client_secret);
        valueForm_client_secret = NULL;
    }
    free(keyPairForm_client_secret);
    if (keyForm_redirect_uri) {
        free(keyForm_redirect_uri);
        keyForm_redirect_uri = NULL;
    }
    if (valueForm_redirect_uri) {
        free(valueForm_redirect_uri);
        valueForm_redirect_uri = NULL;
    }
    free(keyPairForm_redirect_uri);
    if (keyForm_grant_type) {
        free(keyForm_grant_type);
        keyForm_grant_type = NULL;
    }
    if (valueForm_grant_type) {
        free(valueForm_grant_type);
        valueForm_grant_type = NULL;
    }
    free(keyPairForm_grant_type);
    if (keyForm_refresh_extended_token) {
        free(keyForm_refresh_extended_token);
        keyForm_refresh_extended_token = NULL;
    }
    free(keyPairForm_refresh_extended_token);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

