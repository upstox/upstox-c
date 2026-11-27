#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "MarketHolidaysAndTimingsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get Change in OI Data
//
// Fetches change in OI data for the given instrument key, expiry, date and interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getChangeOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *interval)
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
    char *localVarPath = strdup("/v2/market/change-oi");





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
    char *keyQuery_date = NULL;
    char * valueQuery_date = NULL;
    keyValuePair_t *keyPairQuery_date = 0;
    if (date)
    {
        keyQuery_date = strdup("date");
        valueQuery_date = strdup((date));
        keyPairQuery_date = keyValuePair_create(keyQuery_date, valueQuery_date);
        list_addElement(localVarQueryParameters,keyPairQuery_date);
    }

    // query parameters
    char *keyQuery_interval = NULL;
    char * valueQuery_interval = NULL;
    keyValuePair_t *keyPairQuery_interval = 0;
    if (interval)
    {
        keyQuery_interval = strdup("interval");
        valueQuery_interval = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_interval, MAX_NUMBER_LENGTH, "%d", *interval);
        keyPairQuery_interval = keyValuePair_create(keyQuery_interval, valueQuery_interval);
        list_addElement(localVarQueryParameters,keyPairQuery_interval);
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
    //    printf("%s\n","UDAPI100011 - Invalid instrument_key.&lt;br&gt;UDAPI1202 - Invalid expiry format.&lt;br&gt;UDAPI1203 - Invalid date format.&lt;br&gt;UDAPI1204 - Invalid interval.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_date){
        free(keyQuery_date);
        keyQuery_date = NULL;
    }
    if(valueQuery_date){
        free(valueQuery_date);
        valueQuery_date = NULL;
    }
    if(keyPairQuery_date){
        keyValuePair_free(keyPairQuery_date);
        keyPairQuery_date = NULL;
    }
    if(keyQuery_interval){
        free(keyQuery_interval);
        keyQuery_interval = NULL;
    }
    if(valueQuery_interval){
        free(valueQuery_interval);
        valueQuery_interval = NULL;
    }
    if(keyPairQuery_interval){
        keyValuePair_free(keyPairQuery_interval);
        keyPairQuery_interval = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get DII Data
//
// Fetches DII activity data for the given interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getDiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from)
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
    char *localVarPath = strdup("/v2/market/dii");





    // query parameters
    char *keyQuery_data_type = NULL;
    char * valueQuery_data_type = NULL;
    keyValuePair_t *keyPairQuery_data_type = 0;
    if (data_type)
    {
        keyQuery_data_type = strdup("data_type");
        valueQuery_data_type = strdup((data_type));
        keyPairQuery_data_type = keyValuePair_create(keyQuery_data_type, valueQuery_data_type);
        list_addElement(localVarQueryParameters,keyPairQuery_data_type);
    }

    // query parameters
    char *keyQuery_interval = NULL;
    char * valueQuery_interval = NULL;
    keyValuePair_t *keyPairQuery_interval = 0;
    if (interval)
    {
        keyQuery_interval = strdup("interval");
        valueQuery_interval = strdup((interval));
        keyPairQuery_interval = keyValuePair_create(keyQuery_interval, valueQuery_interval);
        list_addElement(localVarQueryParameters,keyPairQuery_interval);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char * valueQuery_from = NULL;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = strdup((from));
        keyPairQuery_from = keyValuePair_create(keyQuery_from, valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
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
    //    printf("%s\n","UDAPI1198 - Invalid data_type. Allowed value: NSE_EQ|CASH.&lt;br&gt;UDAPI1199 - Invalid interval.&lt;br&gt;UDAPI1200 - Invalid from date format.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_data_type){
        free(keyQuery_data_type);
        keyQuery_data_type = NULL;
    }
    if(valueQuery_data_type){
        free(valueQuery_data_type);
        valueQuery_data_type = NULL;
    }
    if(keyPairQuery_data_type){
        keyValuePair_free(keyPairQuery_data_type);
        keyPairQuery_data_type = NULL;
    }
    if(keyQuery_interval){
        free(keyQuery_interval);
        keyQuery_interval = NULL;
    }
    if(valueQuery_interval){
        free(valueQuery_interval);
        valueQuery_interval = NULL;
    }
    if(keyPairQuery_interval){
        keyValuePair_free(keyPairQuery_interval);
        keyPairQuery_interval = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(valueQuery_from){
        free(valueQuery_from);
        valueQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Exchange Timings on particular date
//
// This API provides the functionality to retrieve the exchange timings on particular date
//
get_exchange_timing_response_t*
MarketHolidaysAndTimingsAPI_getExchangeTimings(apiClient_t *apiClient, char *date)
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
    char *localVarPath = strdup("/v2/market/timings/{date}");

    if(!date)
        goto end;


    // Path Params
    long sizeOfPathParams_date = strlen(date)+3 + sizeof("{ date }") - 1;
    if(date == NULL) {
        goto end;
    }
    char* localVarToReplace_date = malloc(sizeOfPathParams_date);
    sprintf(localVarToReplace_date, "{%s}", "date");

    localVarPath = strReplace(localVarPath, localVarToReplace_date, date);


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
    get_exchange_timing_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_exchange_timing_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    free(localVarToReplace_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get FII Data
//
// Fetches FII activity data for the given data type and interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getFiiData(apiClient_t *apiClient, char *data_type, char *interval, char *from)
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
    char *localVarPath = strdup("/v2/market/fii");





    // query parameters
    char *keyQuery_data_type = NULL;
    char * valueQuery_data_type = NULL;
    keyValuePair_t *keyPairQuery_data_type = 0;
    if (data_type)
    {
        keyQuery_data_type = strdup("data_type");
        valueQuery_data_type = strdup((data_type));
        keyPairQuery_data_type = keyValuePair_create(keyQuery_data_type, valueQuery_data_type);
        list_addElement(localVarQueryParameters,keyPairQuery_data_type);
    }

    // query parameters
    char *keyQuery_interval = NULL;
    char * valueQuery_interval = NULL;
    keyValuePair_t *keyPairQuery_interval = 0;
    if (interval)
    {
        keyQuery_interval = strdup("interval");
        valueQuery_interval = strdup((interval));
        keyPairQuery_interval = keyValuePair_create(keyQuery_interval, valueQuery_interval);
        list_addElement(localVarQueryParameters,keyPairQuery_interval);
    }

    // query parameters
    char *keyQuery_from = NULL;
    char * valueQuery_from = NULL;
    keyValuePair_t *keyPairQuery_from = 0;
    if (from)
    {
        keyQuery_from = strdup("from");
        valueQuery_from = strdup((from));
        keyPairQuery_from = keyValuePair_create(keyQuery_from, valueQuery_from);
        list_addElement(localVarQueryParameters,keyPairQuery_from);
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
    //    printf("%s\n","UDAPI1198 - Invalid data_type.&lt;br&gt;UDAPI1199 - Invalid interval.&lt;br&gt;UDAPI1200 - Invalid from date format.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_data_type){
        free(keyQuery_data_type);
        keyQuery_data_type = NULL;
    }
    if(valueQuery_data_type){
        free(valueQuery_data_type);
        valueQuery_data_type = NULL;
    }
    if(keyPairQuery_data_type){
        keyValuePair_free(keyPairQuery_data_type);
        keyPairQuery_data_type = NULL;
    }
    if(keyQuery_interval){
        free(keyQuery_interval);
        keyQuery_interval = NULL;
    }
    if(valueQuery_interval){
        free(valueQuery_interval);
        valueQuery_interval = NULL;
    }
    if(keyPairQuery_interval){
        keyValuePair_free(keyPairQuery_interval);
        keyPairQuery_interval = NULL;
    }
    if(keyQuery_from){
        free(keyQuery_from);
        keyQuery_from = NULL;
    }
    if(valueQuery_from){
        free(valueQuery_from);
        valueQuery_from = NULL;
    }
    if(keyPairQuery_from){
        keyValuePair_free(keyPairQuery_from);
        keyPairQuery_from = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Holiday on particular date
//
// This API provides the functionality to retrieve the holiday on particular date
//
get_holiday_response_t*
MarketHolidaysAndTimingsAPI_getHoliday(apiClient_t *apiClient, char *date)
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
    char *localVarPath = strdup("/v2/market/holidays/{date}");

    if(!date)
        goto end;


    // Path Params
    long sizeOfPathParams_date = strlen(date)+3 + sizeof("{ date }") - 1;
    if(date == NULL) {
        goto end;
    }
    char* localVarToReplace_date = malloc(sizeOfPathParams_date);
    sprintf(localVarToReplace_date, "{%s}", "date");

    localVarPath = strReplace(localVarPath, localVarToReplace_date, date);


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
    get_holiday_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_holiday_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    free(localVarToReplace_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Holiday list of current year
//
// This API provides the functionality to retrieve the holiday list of current year
//
get_holiday_response_t*
MarketHolidaysAndTimingsAPI_getHolidays(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v2/market/holidays");




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
    get_holiday_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_holiday_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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

// Get Market status for particular exchange
//
// This API provides the functionality to retrieve the market status for particular exchange
//
get_market_status_response_t*
MarketHolidaysAndTimingsAPI_getMarketStatus(apiClient_t *apiClient, char *exchange)
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
    char *localVarPath = strdup("/v2/market/status/{exchange}");

    if(!exchange)
        goto end;


    // Path Params
    long sizeOfPathParams_exchange = strlen(exchange)+3 + sizeof("{ exchange }") - 1;
    if(exchange == NULL) {
        goto end;
    }
    char* localVarToReplace_exchange = malloc(sizeOfPathParams_exchange);
    sprintf(localVarToReplace_exchange, "{%s}", "exchange");

    localVarPath = strReplace(localVarPath, localVarToReplace_exchange, exchange);


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
    get_market_status_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_market_status_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    free(localVarToReplace_exchange);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Max Pain Data
//
// Fetches Max Pain data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getMaxPainData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval)
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
    char *localVarPath = strdup("/v2/market/max-pain");





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
    char *keyQuery_date = NULL;
    char * valueQuery_date = NULL;
    keyValuePair_t *keyPairQuery_date = 0;
    if (date)
    {
        keyQuery_date = strdup("date");
        valueQuery_date = strdup((date));
        keyPairQuery_date = keyValuePair_create(keyQuery_date, valueQuery_date);
        list_addElement(localVarQueryParameters,keyPairQuery_date);
    }

    // query parameters
    char *keyQuery_bucket_interval = NULL;
    char * valueQuery_bucket_interval = NULL;
    keyValuePair_t *keyPairQuery_bucket_interval = 0;
    if (bucket_interval)
    {
        keyQuery_bucket_interval = strdup("bucket_interval");
        valueQuery_bucket_interval = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_bucket_interval, MAX_NUMBER_LENGTH, "%d", *bucket_interval);
        keyPairQuery_bucket_interval = keyValuePair_create(keyQuery_bucket_interval, valueQuery_bucket_interval);
        list_addElement(localVarQueryParameters,keyPairQuery_bucket_interval);
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
    //    printf("%s\n","UDAPI100011 - Invalid instrument_key.&lt;br&gt;UDAPI1202 - Invalid expiry format.&lt;br&gt;UDAPI1203 - Invalid date format.&lt;br&gt;UDAPI1205 - Invalid bucket_interval.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_date){
        free(keyQuery_date);
        keyQuery_date = NULL;
    }
    if(valueQuery_date){
        free(valueQuery_date);
        valueQuery_date = NULL;
    }
    if(keyPairQuery_date){
        keyValuePair_free(keyPairQuery_date);
        keyPairQuery_date = NULL;
    }
    if(keyQuery_bucket_interval){
        free(keyQuery_bucket_interval);
        keyQuery_bucket_interval = NULL;
    }
    if(valueQuery_bucket_interval){
        free(valueQuery_bucket_interval);
        valueQuery_bucket_interval = NULL;
    }
    if(keyPairQuery_bucket_interval){
        keyValuePair_free(keyPairQuery_bucket_interval);
        keyPairQuery_bucket_interval = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get OI Data
//
// Fetches OI data for the given instrument key, expiry and date.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getOiData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date)
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
    char *localVarPath = strdup("/v2/market/oi");





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
    char *keyQuery_date = NULL;
    char * valueQuery_date = NULL;
    keyValuePair_t *keyPairQuery_date = 0;
    if (date)
    {
        keyQuery_date = strdup("date");
        valueQuery_date = strdup((date));
        keyPairQuery_date = keyValuePair_create(keyQuery_date, valueQuery_date);
        list_addElement(localVarQueryParameters,keyPairQuery_date);
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
    //    printf("%s\n","UDAPI100011 - Invalid instrument_key.&lt;br&gt;UDAPI1202 - Invalid expiry format.&lt;br&gt;UDAPI1203 - Invalid date format.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_date){
        free(keyQuery_date);
        keyQuery_date = NULL;
    }
    if(valueQuery_date){
        free(valueQuery_date);
        valueQuery_date = NULL;
    }
    if(keyPairQuery_date){
        keyValuePair_free(keyPairQuery_date);
        keyPairQuery_date = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get PCR Data
//
// Fetches PCR (Put-Call Ratio) data for the given instrument key, expiry, date and bucket interval.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getPcrData(apiClient_t *apiClient, char *instrument_key, char *expiry, char *date, int *bucket_interval)
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
    char *localVarPath = strdup("/v2/market/pcr");





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
    char *keyQuery_date = NULL;
    char * valueQuery_date = NULL;
    keyValuePair_t *keyPairQuery_date = 0;
    if (date)
    {
        keyQuery_date = strdup("date");
        valueQuery_date = strdup((date));
        keyPairQuery_date = keyValuePair_create(keyQuery_date, valueQuery_date);
        list_addElement(localVarQueryParameters,keyPairQuery_date);
    }

    // query parameters
    char *keyQuery_bucket_interval = NULL;
    char * valueQuery_bucket_interval = NULL;
    keyValuePair_t *keyPairQuery_bucket_interval = 0;
    if (bucket_interval)
    {
        keyQuery_bucket_interval = strdup("bucket_interval");
        valueQuery_bucket_interval = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_bucket_interval, MAX_NUMBER_LENGTH, "%d", *bucket_interval);
        keyPairQuery_bucket_interval = keyValuePair_create(keyQuery_bucket_interval, valueQuery_bucket_interval);
        list_addElement(localVarQueryParameters,keyPairQuery_bucket_interval);
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
    //    printf("%s\n","UDAPI100011 - Invalid instrument_key.&lt;br&gt;UDAPI1202 - Invalid expiry format.&lt;br&gt;UDAPI1203 - Invalid date format.&lt;br&gt;UDAPI1205 - Invalid bucket_interval.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_date){
        free(keyQuery_date);
        keyQuery_date = NULL;
    }
    if(valueQuery_date){
        free(valueQuery_date);
        valueQuery_date = NULL;
    }
    if(keyPairQuery_date){
        keyValuePair_free(keyPairQuery_date);
        keyPairQuery_date = NULL;
    }
    if(keyQuery_bucket_interval){
        free(keyQuery_bucket_interval);
        keyQuery_bucket_interval = NULL;
    }
    if(valueQuery_bucket_interval){
        free(valueQuery_bucket_interval);
        valueQuery_bucket_interval = NULL;
    }
    if(keyPairQuery_bucket_interval){
        keyValuePair_free(keyPairQuery_bucket_interval);
        keyPairQuery_bucket_interval = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Smartlist Futures
//
// Fetches the smartlist of futures for the given asset type and category.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistFutures(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size)
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
    char *localVarPath = strdup("/v2/market/smartlist/futures");





    // query parameters
    char *keyQuery_asset_type = NULL;
    char * valueQuery_asset_type = NULL;
    keyValuePair_t *keyPairQuery_asset_type = 0;
    if (asset_type)
    {
        keyQuery_asset_type = strdup("asset_type");
        valueQuery_asset_type = strdup((asset_type));
        keyPairQuery_asset_type = keyValuePair_create(keyQuery_asset_type, valueQuery_asset_type);
        list_addElement(localVarQueryParameters,keyPairQuery_asset_type);
    }

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
    //    printf("%s\n","UDAPI1212 - Invalid asset_type.&lt;br&gt;UDAPI1213 - Invalid category for the given asset_type.&lt;br&gt;UDAPI1214 - Invalid page_size. Maximum allowed value is 50.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_asset_type){
        free(keyQuery_asset_type);
        keyQuery_asset_type = NULL;
    }
    if(valueQuery_asset_type){
        free(valueQuery_asset_type);
        valueQuery_asset_type = NULL;
    }
    if(keyPairQuery_asset_type){
        keyValuePair_free(keyPairQuery_asset_type);
        keyPairQuery_asset_type = NULL;
    }
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

// Get Smartlist MTF
//
// Fetches the smartlist of MTF (Margin Trade Funding) stocks. Prices are enriched with live LTP data.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistMtf(apiClient_t *apiClient, int *page_number, int *page_size)
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
    char *localVarPath = strdup("/v2/market/smartlist/mtf");





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
    //    printf("%s\n","UDAPI1214 - Invalid page_size. Maximum allowed value is 50.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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

// Get Smartlist Options
//
// Fetches the smartlist of options for the given asset type and category.
//
analytics_response_t*
MarketHolidaysAndTimingsAPI_getSmartlistOptions(apiClient_t *apiClient, char *asset_type, char *category, int *page_number, int *page_size)
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
    char *localVarPath = strdup("/v2/market/smartlist/options");





    // query parameters
    char *keyQuery_asset_type = NULL;
    char * valueQuery_asset_type = NULL;
    keyValuePair_t *keyPairQuery_asset_type = 0;
    if (asset_type)
    {
        keyQuery_asset_type = strdup("asset_type");
        valueQuery_asset_type = strdup((asset_type));
        keyPairQuery_asset_type = keyValuePair_create(keyQuery_asset_type, valueQuery_asset_type);
        list_addElement(localVarQueryParameters,keyPairQuery_asset_type);
    }

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
    //    printf("%s\n","UDAPI1212 - Invalid asset_type.&lt;br&gt;UDAPI1213 - Invalid category for the given asset_type.&lt;br&gt;UDAPI1214 - Invalid page_size. Maximum allowed value is 50.");
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
    analytics_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketHolidaysAndTimingsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = analytics_response_parseFromJSON(MarketHolidaysAndTimingsAPIlocalVarJSON);
        cJSON_Delete(MarketHolidaysAndTimingsAPIlocalVarJSON);
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
    if(keyQuery_asset_type){
        free(keyQuery_asset_type);
        keyQuery_asset_type = NULL;
    }
    if(valueQuery_asset_type){
        free(valueQuery_asset_type);
        valueQuery_asset_type = NULL;
    }
    if(keyPairQuery_asset_type){
        keyValuePair_free(keyPairQuery_asset_type);
        keyPairQuery_asset_type = NULL;
    }
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

