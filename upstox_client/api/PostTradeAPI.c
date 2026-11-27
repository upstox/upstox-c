#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "PostTradeAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get historical trades
//
// This API retrieves the trade history for a specified time interval.
//
trade_history_response_t*
PostTradeAPI_getTradesByDateRange(apiClient_t *apiClient, char *start_date, char *end_date, int *page_number, int *page_size, char *segment)
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
    char *localVarPath = strdup("/v2/charges/historical-trades");





    // query parameters
    char *keyQuery_segment = NULL;
    char * valueQuery_segment = NULL;
    keyValuePair_t *keyPairQuery_segment = 0;
    if (segment)
    {
        keyQuery_segment = strdup("segment");
        valueQuery_segment = strdup((segment));
        keyPairQuery_segment = keyValuePair_create(keyQuery_segment, valueQuery_segment);
        list_addElement(localVarQueryParameters,keyPairQuery_segment);
    }

    // query parameters
    char *keyQuery_start_date = NULL;
    char * valueQuery_start_date = NULL;
    keyValuePair_t *keyPairQuery_start_date = 0;
    if (start_date)
    {
        keyQuery_start_date = strdup("start_date");
        valueQuery_start_date = strdup((start_date));
        keyPairQuery_start_date = keyValuePair_create(keyQuery_start_date, valueQuery_start_date);
        list_addElement(localVarQueryParameters,keyPairQuery_start_date);
    }

    // query parameters
    char *keyQuery_end_date = NULL;
    char * valueQuery_end_date = NULL;
    keyValuePair_t *keyPairQuery_end_date = 0;
    if (end_date)
    {
        keyQuery_end_date = strdup("end_date");
        valueQuery_end_date = strdup((end_date));
        keyPairQuery_end_date = keyValuePair_create(keyQuery_end_date, valueQuery_end_date);
        list_addElement(localVarQueryParameters,keyPairQuery_end_date);
    }

    // query parameters
    char *keyQuery_page_number = NULL;
    char * valueQuery_page_number = NULL;
    keyValuePair_t *keyPairQuery_page_number = 0;
    if (page_number)
    {
        keyQuery_page_number = strdup("page_number");
        valueQuery_page_number = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page_number, MAX_NUMBER_LENGTH, "%d", *page_number);
        keyPairQuery_page_number = keyValuePair_create(keyQuery_page_number, valueQuery_page_number);
        list_addElement(localVarQueryParameters,keyPairQuery_page_number);
    }

    // query parameters
    char *keyQuery_page_size = NULL;
    char * valueQuery_page_size = NULL;
    keyValuePair_t *keyPairQuery_page_size = 0;
    if (page_size)
    {
        keyQuery_page_size = strdup("page_size");
        valueQuery_page_size = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_page_size, MAX_NUMBER_LENGTH, "%d", *page_size);
        keyPairQuery_page_size = keyValuePair_create(keyQuery_page_size, valueQuery_page_size);
        list_addElement(localVarQueryParameters,keyPairQuery_page_size);
    }
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
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
    trade_history_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *PostTradeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = trade_history_response_parseFromJSON(PostTradeAPIlocalVarJSON);
        cJSON_Delete(PostTradeAPIlocalVarJSON);
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
    if(keyQuery_segment){
        free(keyQuery_segment);
        keyQuery_segment = NULL;
    }
    if(valueQuery_segment){
        free(valueQuery_segment);
        valueQuery_segment = NULL;
    }
    if(keyPairQuery_segment){
        keyValuePair_free(keyPairQuery_segment);
        keyPairQuery_segment = NULL;
    }
    if(keyQuery_start_date){
        free(keyQuery_start_date);
        keyQuery_start_date = NULL;
    }
    if(valueQuery_start_date){
        free(valueQuery_start_date);
        valueQuery_start_date = NULL;
    }
    if(keyPairQuery_start_date){
        keyValuePair_free(keyPairQuery_start_date);
        keyPairQuery_start_date = NULL;
    }
    if(keyQuery_end_date){
        free(keyQuery_end_date);
        keyQuery_end_date = NULL;
    }
    if(valueQuery_end_date){
        free(valueQuery_end_date);
        valueQuery_end_date = NULL;
    }
    if(keyPairQuery_end_date){
        keyValuePair_free(keyPairQuery_end_date);
        keyPairQuery_end_date = NULL;
    }
    if(keyQuery_page_number){
        free(keyQuery_page_number);
        keyQuery_page_number = NULL;
    }
    if(valueQuery_page_number){
        free(valueQuery_page_number);
        valueQuery_page_number = NULL;
    }
    if(keyPairQuery_page_number){
        keyValuePair_free(keyPairQuery_page_number);
        keyPairQuery_page_number = NULL;
    }
    if(keyQuery_page_size){
        free(keyQuery_page_size);
        keyQuery_page_size = NULL;
    }
    if(valueQuery_page_size){
        free(valueQuery_page_size);
        valueQuery_page_size = NULL;
    }
    if(keyPairQuery_page_size){
        keyValuePair_free(keyPairQuery_page_size);
        keyPairQuery_page_size = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

