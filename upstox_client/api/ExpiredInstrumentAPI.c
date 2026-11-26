#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ExpiredInstrumentAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Expired instruments - Get future contracts
//
// This API provides the functionality to retrieve expired future contracts for a given instrument key and expiry date.
//
get_expired_futures_contract_response_t*
ExpiredInstrumentAPI_getExpiredFutureContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date)
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
    char *localVarPath = strdup("/v2/expired-instruments/future/contract");





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
    //    printf("%s\n","UDAPI1009 - instrument_key is required&lt;br&gt;UDAPI1011 - instrument_key is of invalid format&lt;br&gt;UDAPI100011 - Invalid Instrument key&lt;br&gt;");
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
    get_expired_futures_contract_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExpiredInstrumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_expired_futures_contract_response_parseFromJSON(ExpiredInstrumentAPIlocalVarJSON);
        cJSON_Delete(ExpiredInstrumentAPIlocalVarJSON);
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

// Expired Historical candle data
//
// Get Expired OHLC values for all instruments across various timeframes. Expired Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
ExpiredInstrumentAPI_getExpiredHistoricalCandleData(apiClient_t *apiClient, char *expired_instrument_key, char *interval, char *to_date, char *from_date)
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
    char *localVarPath = strdup("/v2/expired-instruments/historical-candle/{expired_instrument_key}/{interval}/{to_date}/{from_date}");

    if(!expired_instrument_key)
        goto end;
    if(!interval)
        goto end;
    if(!to_date)
        goto end;
    if(!from_date)
        goto end;


    // Path Params
    long sizeOfPathParams_expired_instrument_key = strlen(expired_instrument_key)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ expired_instrument_key }") - 1;
    if(expired_instrument_key == NULL) {
        goto end;
    }
    char* localVarToReplace_expired_instrument_key = malloc(sizeOfPathParams_expired_instrument_key);
    sprintf(localVarToReplace_expired_instrument_key, "{%s}", "expired_instrument_key");

    localVarPath = strReplace(localVarPath, localVarToReplace_expired_instrument_key, expired_instrument_key);

    // Path Params
    long sizeOfPathParams_interval = strlen(expired_instrument_key)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ interval }") - 1;
    if(interval == NULL) {
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    sprintf(localVarToReplace_interval, "{%s}", "interval");

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, interval);

    // Path Params
    long sizeOfPathParams_to_date = strlen(expired_instrument_key)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ to_date }") - 1;
    if(to_date == NULL) {
        goto end;
    }
    char* localVarToReplace_to_date = malloc(sizeOfPathParams_to_date);
    sprintf(localVarToReplace_to_date, "{%s}", "to_date");

    localVarPath = strReplace(localVarPath, localVarToReplace_to_date, to_date);

    // Path Params
    long sizeOfPathParams_from_date = strlen(expired_instrument_key)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ from_date }") - 1;
    if(from_date == NULL) {
        goto end;
    }
    char* localVarToReplace_from_date = malloc(sizeOfPathParams_from_date);
    sprintf(localVarToReplace_from_date, "{%s}", "from_date");

    localVarPath = strReplace(localVarPath, localVarToReplace_from_date, from_date);


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
    //    printf("%s\n","UDAPI1015 - to_date must be greater than or equal to from_date and Date should be in valid format: yyyy-mm-dd&lt;br&gt;UDAPI1020 - Interval accepts one of (1minute,30minute,day,week,month)&lt;br&gt;UDAPI1021 - Instrument key is of invalid format&lt;br&gt;UDAPI1022 - to_date is required&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_historical_candle_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExpiredInstrumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_historical_candle_response_parseFromJSON(ExpiredInstrumentAPIlocalVarJSON);
        cJSON_Delete(ExpiredInstrumentAPIlocalVarJSON);
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
    free(localVarToReplace_expired_instrument_key);
    free(localVarToReplace_interval);
    free(localVarToReplace_to_date);
    free(localVarToReplace_from_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get expired option contracts
//
// This API provides the functionality to retrieve the expired option contracts
//
get_option_contract_response_t*
ExpiredInstrumentAPI_getExpiredOptionContracts(apiClient_t *apiClient, char *instrument_key, char *expiry_date)
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
    char *localVarPath = strdup("/v2/expired-instruments/option/contract");





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
        cJSON *ExpiredInstrumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_option_contract_response_parseFromJSON(ExpiredInstrumentAPIlocalVarJSON);
        cJSON_Delete(ExpiredInstrumentAPIlocalVarJSON);
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

// Expired instruments - Get expiries
//
// This API provides the functionality to retrieve expiry dates for a given instrument key.
//
get_expiries_response_t*
ExpiredInstrumentAPI_getExpiriesResponse(apiClient_t *apiClient, char *instrument_key)
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
    char *localVarPath = strdup("/v2/expired-instruments/expiries");





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
    //    printf("%s\n","UDAPI1009 - instrument_key is required&lt;br&gt;UDAPI1011 - instrument_key is of invalid format&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_expiries_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ExpiredInstrumentAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_expiries_response_parseFromJSON(ExpiredInstrumentAPIlocalVarJSON);
        cJSON_Delete(ExpiredInstrumentAPIlocalVarJSON);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

