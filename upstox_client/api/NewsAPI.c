#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "NewsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get News
//
// Fetches news articles for the given instrument keys, or the user's current positions or holdings.
//
get_news_response_t*
NewsAPI_getNews(apiClient_t *apiClient, char *category, char *instrument_keys, int *page_number, int *page_size)
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
    char *localVarPath = strdup("/v2/news");





    // query parameters
    char *keyQuery_category = NULL;
    char * valueQuery_category = NULL;
    keyValuePair_t *keyPairQuery_category = 0;
    if (category)
    {
        keyQuery_category = strdup("category");
        valueQuery_category = strdup((category));
        keyPairQuery_category = keyValuePair_create(keyQuery_category, valueQuery_category);
        list_addElement(localVarQueryParameters,keyPairQuery_category);
    }

    // query parameters
    char *keyQuery_instrument_keys = NULL;
    char * valueQuery_instrument_keys = NULL;
    keyValuePair_t *keyPairQuery_instrument_keys = 0;
    if (instrument_keys)
    {
        keyQuery_instrument_keys = strdup("instrument_keys");
        valueQuery_instrument_keys = strdup((instrument_keys));
        keyPairQuery_instrument_keys = keyValuePair_create(keyQuery_instrument_keys, valueQuery_instrument_keys);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_keys);
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
    //    printf("%s\n","UDAPI1189 - Invalid category. Allowed values: instrument_keys, positions, holdings.&lt;br&gt;UDAPI1190 - instrument_keys is required when category is instrument_keys.&lt;br&gt;UDAPI1193 - News can be fetched for a maximum of 30 instrument keys per request.");
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
    get_news_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *NewsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_news_response_parseFromJSON(NewsAPIlocalVarJSON);
        cJSON_Delete(NewsAPIlocalVarJSON);
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
    if(keyQuery_category){
        free(keyQuery_category);
        keyQuery_category = NULL;
    }
    if(valueQuery_category){
        free(valueQuery_category);
        valueQuery_category = NULL;
    }
    if(keyPairQuery_category){
        keyValuePair_free(keyPairQuery_category);
        keyPairQuery_category = NULL;
    }
    if(keyQuery_instrument_keys){
        free(keyQuery_instrument_keys);
        keyQuery_instrument_keys = NULL;
    }
    if(valueQuery_instrument_keys){
        free(valueQuery_instrument_keys);
        valueQuery_instrument_keys = NULL;
    }
    if(keyPairQuery_instrument_keys){
        keyValuePair_free(keyPairQuery_instrument_keys);
        keyPairQuery_instrument_keys = NULL;
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

