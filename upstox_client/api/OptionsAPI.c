#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "OptionsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get option contracts
//
// This API provides the functionality to retrieve the option contracts
//
get_option_contract_response_t*
OptionsAPI_getOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date)
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
    char *localVarPath = strdup("/v2/option/contract");





    // query parameters
    char *keyQuery_instrument_key = NULL;
    char * valueQuery_instrument_key = NULL;
    keyValuePair_t *keyPairQuery_instrument_key = 0;
    if (instrument_key)
    {
        keyQuery_instrument_key = strdup("instrument_key");
        valueQuery_instrument_key = strdup((instrument_key));
        keyPairQuery_instrument_key = keyValuePair_create(keyQuery_instrument_key, valueQuery_instrument_key);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_key);
    }

    // query parameters
    char *keyQuery_expiry_date = NULL;
    char * valueQuery_expiry_date = NULL;
    keyValuePair_t *keyPairQuery_expiry_date = 0;
    if (expiry_date)
    {
        keyQuery_expiry_date = strdup("expiry_date");
        valueQuery_expiry_date = strdup((expiry_date));
        keyPairQuery_expiry_date = keyValuePair_create(keyQuery_expiry_date, valueQuery_expiry_date);
        list_addElement(localVarQueryParameters,keyPairQuery_expiry_date);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","");
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
    get_option_contract_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OptionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_option_contract_response_parseFromJSON(OptionsAPIlocalVarJSON);
        cJSON_Delete(OptionsAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_instrument_key){
        free(keyQuery_instrument_key);
        keyQuery_instrument_key = NULL;
    }
    if(valueQuery_instrument_key){
        free(valueQuery_instrument_key);
        valueQuery_instrument_key = NULL;
    }
    if(keyPairQuery_instrument_key){
        keyValuePair_free(keyPairQuery_instrument_key);
        keyPairQuery_instrument_key = NULL;
    }
    if(keyQuery_expiry_date){
        free(keyQuery_expiry_date);
        keyQuery_expiry_date = NULL;
    }
    if(valueQuery_expiry_date){
        free(valueQuery_expiry_date);
        valueQuery_expiry_date = NULL;
    }
    if(keyPairQuery_expiry_date){
        keyValuePair_free(keyPairQuery_expiry_date);
        keyPairQuery_expiry_date = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get option chain
//
// This API provides the functionality to retrieve the option chain
//
get_option_chain_response_t*
OptionsAPI_getPutCallOptionChain(apiClient_t *apiClient, char *instrument_key, char *expiry_date)
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
    char *localVarPath = strdup("/v2/option/chain");





    // query parameters
    char *keyQuery_instrument_key = NULL;
    char * valueQuery_instrument_key = NULL;
    keyValuePair_t *keyPairQuery_instrument_key = 0;
    if (instrument_key)
    {
        keyQuery_instrument_key = strdup("instrument_key");
        valueQuery_instrument_key = strdup((instrument_key));
        keyPairQuery_instrument_key = keyValuePair_create(keyQuery_instrument_key, valueQuery_instrument_key);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_key);
    }

    // query parameters
    char *keyQuery_expiry_date = NULL;
    char * valueQuery_expiry_date = NULL;
    keyValuePair_t *keyPairQuery_expiry_date = 0;
    if (expiry_date)
    {
        keyQuery_expiry_date = strdup("expiry_date");
        valueQuery_expiry_date = strdup((expiry_date));
        keyPairQuery_expiry_date = keyValuePair_create(keyQuery_expiry_date, valueQuery_expiry_date);
        list_addElement(localVarQueryParameters,keyPairQuery_expiry_date);
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
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","");
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
    get_option_chain_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OptionsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_option_chain_response_parseFromJSON(OptionsAPIlocalVarJSON);
        cJSON_Delete(OptionsAPIlocalVarJSON);
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
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_instrument_key){
        free(keyQuery_instrument_key);
        keyQuery_instrument_key = NULL;
    }
    if(valueQuery_instrument_key){
        free(valueQuery_instrument_key);
        valueQuery_instrument_key = NULL;
    }
    if(keyPairQuery_instrument_key){
        keyValuePair_free(keyPairQuery_instrument_key);
        keyPairQuery_instrument_key = NULL;
    }
    if(keyQuery_expiry_date){
        free(keyQuery_expiry_date);
        keyQuery_expiry_date = NULL;
    }
    if(valueQuery_expiry_date){
        free(valueQuery_expiry_date);
        valueQuery_expiry_date = NULL;
    }
    if(keyPairQuery_expiry_date){
        keyValuePair_free(keyPairQuery_expiry_date);
        keyPairQuery_expiry_date = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

