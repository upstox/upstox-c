#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "InstrumentsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Search instruments
//
// This API provides the functionality to retrieve the instrument details for searched query
//
search_instrument_response_t*
InstrumentsAPI_searchInstrument(apiClient_t *apiClient, char *query, char *exchanges, char *segments, char *instrument_types, char *expiry, int *atm_offset, int *page_number, int *records)
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
    char *localVarPath = strdup("/v2/instruments/search");





    // query parameters
    char *keyQuery_query = NULL;
    char * valueQuery_query = NULL;
    keyValuePair_t *keyPairQuery_query = 0;
    if (query)
    {
        keyQuery_query = strdup("query");
        valueQuery_query = strdup((query));
        keyPairQuery_query = keyValuePair_create(keyQuery_query, valueQuery_query);
        list_addElement(localVarQueryParameters,keyPairQuery_query);
    }

    // query parameters
    char *keyQuery_exchanges = NULL;
    char * valueQuery_exchanges = NULL;
    keyValuePair_t *keyPairQuery_exchanges = 0;
    if (exchanges)
    {
        keyQuery_exchanges = strdup("exchanges");
        valueQuery_exchanges = strdup((exchanges));
        keyPairQuery_exchanges = keyValuePair_create(keyQuery_exchanges, valueQuery_exchanges);
        list_addElement(localVarQueryParameters,keyPairQuery_exchanges);
    }

    // query parameters
    char *keyQuery_segments = NULL;
    char * valueQuery_segments = NULL;
    keyValuePair_t *keyPairQuery_segments = 0;
    if (segments)
    {
        keyQuery_segments = strdup("segments");
        valueQuery_segments = strdup((segments));
        keyPairQuery_segments = keyValuePair_create(keyQuery_segments, valueQuery_segments);
        list_addElement(localVarQueryParameters,keyPairQuery_segments);
    }

    // query parameters
    char *keyQuery_instrument_types = NULL;
    char * valueQuery_instrument_types = NULL;
    keyValuePair_t *keyPairQuery_instrument_types = 0;
    if (instrument_types)
    {
        keyQuery_instrument_types = strdup("instrument_types");
        valueQuery_instrument_types = strdup((instrument_types));
        keyPairQuery_instrument_types = keyValuePair_create(keyQuery_instrument_types, valueQuery_instrument_types);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_types);
    }

    // query parameters
    char *keyQuery_expiry = NULL;
    char * valueQuery_expiry = NULL;
    keyValuePair_t *keyPairQuery_expiry = 0;
    if (expiry)
    {
        keyQuery_expiry = strdup("expiry");
        valueQuery_expiry = strdup((expiry));
        keyPairQuery_expiry = keyValuePair_create(keyQuery_expiry, valueQuery_expiry);
        list_addElement(localVarQueryParameters,keyPairQuery_expiry);
    }

    // query parameters
    char *keyQuery_atm_offset = NULL;
    char * valueQuery_atm_offset = NULL;
    keyValuePair_t *keyPairQuery_atm_offset = 0;
    if (atm_offset)
    {
        keyQuery_atm_offset = strdup("atm_offset");
        valueQuery_atm_offset = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_atm_offset, MAX_NUMBER_LENGTH, "%d", *atm_offset);
        keyPairQuery_atm_offset = keyValuePair_create(keyQuery_atm_offset, valueQuery_atm_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_atm_offset);
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
    char *keyQuery_records = NULL;
    char * valueQuery_records = NULL;
    keyValuePair_t *keyPairQuery_records = 0;
    if (records)
    {
        keyQuery_records = strdup("records");
        valueQuery_records = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_records, MAX_NUMBER_LENGTH, "%d", *records);
        keyPairQuery_records = keyValuePair_create(keyQuery_records, valueQuery_records);
        list_addElement(localVarQueryParameters,keyPairQuery_records);
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
    search_instrument_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *InstrumentsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = search_instrument_response_parseFromJSON(InstrumentsAPIlocalVarJSON);
        cJSON_Delete(InstrumentsAPIlocalVarJSON);
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
    if(keyQuery_query){
        free(keyQuery_query);
        keyQuery_query = NULL;
    }
    if(valueQuery_query){
        free(valueQuery_query);
        valueQuery_query = NULL;
    }
    if(keyPairQuery_query){
        keyValuePair_free(keyPairQuery_query);
        keyPairQuery_query = NULL;
    }
    if(keyQuery_exchanges){
        free(keyQuery_exchanges);
        keyQuery_exchanges = NULL;
    }
    if(valueQuery_exchanges){
        free(valueQuery_exchanges);
        valueQuery_exchanges = NULL;
    }
    if(keyPairQuery_exchanges){
        keyValuePair_free(keyPairQuery_exchanges);
        keyPairQuery_exchanges = NULL;
    }
    if(keyQuery_segments){
        free(keyQuery_segments);
        keyQuery_segments = NULL;
    }
    if(valueQuery_segments){
        free(valueQuery_segments);
        valueQuery_segments = NULL;
    }
    if(keyPairQuery_segments){
        keyValuePair_free(keyPairQuery_segments);
        keyPairQuery_segments = NULL;
    }
    if(keyQuery_instrument_types){
        free(keyQuery_instrument_types);
        keyQuery_instrument_types = NULL;
    }
    if(valueQuery_instrument_types){
        free(valueQuery_instrument_types);
        valueQuery_instrument_types = NULL;
    }
    if(keyPairQuery_instrument_types){
        keyValuePair_free(keyPairQuery_instrument_types);
        keyPairQuery_instrument_types = NULL;
    }
    if(keyQuery_expiry){
        free(keyQuery_expiry);
        keyQuery_expiry = NULL;
    }
    if(valueQuery_expiry){
        free(valueQuery_expiry);
        valueQuery_expiry = NULL;
    }
    if(keyPairQuery_expiry){
        keyValuePair_free(keyPairQuery_expiry);
        keyPairQuery_expiry = NULL;
    }
    if(keyQuery_atm_offset){
        free(keyQuery_atm_offset);
        keyQuery_atm_offset = NULL;
    }
    if(valueQuery_atm_offset){
        free(valueQuery_atm_offset);
        valueQuery_atm_offset = NULL;
    }
    if(keyPairQuery_atm_offset){
        keyValuePair_free(keyPairQuery_atm_offset);
        keyPairQuery_atm_offset = NULL;
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
    if(keyQuery_records){
        free(keyQuery_records);
        keyQuery_records = NULL;
    }
    if(valueQuery_records){
        free(valueQuery_records);
        valueQuery_records = NULL;
    }
    if(keyPairQuery_records){
        keyValuePair_free(keyPairQuery_records);
        keyPairQuery_records = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

