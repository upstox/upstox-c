#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "HistoryV3API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options
//
get_historical_candle_response_t*
HistoryV3API_getHistoricalCandleData1(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date, char *from_date)
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
    char *localVarPath = strdup("/v3/historical-candle/{instrumentKey}/{unit}/{interval}/{to_date}/{from_date}");

    if(!instrumentKey)
        goto end;
    if(!unit)
        goto end;
    if(!to_date)
        goto end;
    if(!from_date)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_unit = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ unit }") - 1;
    if(unit == NULL) {
        goto end;
    }
    char* localVarToReplace_unit = malloc(sizeOfPathParams_unit);
    sprintf(localVarToReplace_unit, "{%s}", "unit");

    localVarPath = strReplace(localVarPath, localVarToReplace_unit, unit);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ interval }") - 1;
    if(interval == 0){
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    snprintf(localVarToReplace_interval, sizeOfPathParams_interval, "{%s}", "interval");

    char localVarBuff_interval[256];
    snprintf(localVarBuff_interval, sizeof localVarBuff_interval, "%ld", (long)*interval);

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, localVarBuff_interval);


    // Path Params
    long sizeOfPathParams_to_date = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ to_date }") - 1;
    if(to_date == NULL) {
        goto end;
    }
    char* localVarToReplace_to_date = malloc(sizeOfPathParams_to_date);
    sprintf(localVarToReplace_to_date, "{%s}", "to_date");

    localVarPath = strReplace(localVarPath, localVarToReplace_to_date, to_date);

    // Path Params
    long sizeOfPathParams_from_date = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ from_date }") - 1;
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
    //    printf("%s\n","UDAPI1015 - to_date must be greater than or equal to from_date and Date should be in valid format: yyyy-mm-dd&lt;br&gt;UDAPI1021 - Instrument key is of invalid format&lt;br&gt;UDAPI1022 - to_date is required&lt;br&gt;UDAPI1146 - Invalid unit&lt;br&gt;UDAPI1147 - Invalid interval&lt;br&gt;UDAPI1148 - Invalid date range&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
        cJSON *HistoryV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_historical_candle_response_parseFromJSON(HistoryV3APIlocalVarJSON);
        cJSON_Delete(HistoryV3APIlocalVarJSON);
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
    free(localVarToReplace_instrumentKey);
    free(localVarToReplace_unit);
    free(localVarToReplace_interval);
    free(localVarToReplace_to_date);
    free(localVarToReplace_from_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Historical candle data
//
// Get OHLC values for all instruments for the present trading day with expanded interval options.
//
get_historical_candle_response_t*
HistoryV3API_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval, char *to_date)
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
    char *localVarPath = strdup("/v3/historical-candle/{instrumentKey}/{unit}/{interval}/{to_date}");

    if(!instrumentKey)
        goto end;
    if(!unit)
        goto end;
    if(!to_date)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_unit = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + sizeof("{ unit }") - 1;
    if(unit == NULL) {
        goto end;
    }
    char* localVarToReplace_unit = malloc(sizeOfPathParams_unit);
    sprintf(localVarToReplace_unit, "{%s}", "unit");

    localVarPath = strReplace(localVarPath, localVarToReplace_unit, unit);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + sizeof("{ interval }") - 1;
    if(interval == 0){
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    snprintf(localVarToReplace_interval, sizeOfPathParams_interval, "{%s}", "interval");

    char localVarBuff_interval[256];
    snprintf(localVarBuff_interval, sizeof localVarBuff_interval, "%ld", (long)*interval);

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, localVarBuff_interval);


    // Path Params
    long sizeOfPathParams_to_date = strlen(instrumentKey)+3 + strlen(unit)+3 +  + strlen(to_date)+3 + sizeof("{ to_date }") - 1;
    if(to_date == NULL) {
        goto end;
    }
    char* localVarToReplace_to_date = malloc(sizeOfPathParams_to_date);
    sprintf(localVarToReplace_to_date, "{%s}", "to_date");

    localVarPath = strReplace(localVarPath, localVarToReplace_to_date, to_date);


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
    //    printf("%s\n","UDAPI1015 - to_date must be greater than or equal to from_date and Date should be in valid format: yyyy-mm-dd&lt;br&gt;UDAPI1021 - Instrument key is of invalid format&lt;br&gt;UDAPI1022 - to_date is required&lt;br&gt;UDAPI1146 - Invalid unit&lt;br&gt;UDAPI1147 - Invalid interval&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
        cJSON *HistoryV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_historical_candle_response_parseFromJSON(HistoryV3APIlocalVarJSON);
        cJSON_Delete(HistoryV3APIlocalVarJSON);
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
    free(localVarToReplace_instrumentKey);
    free(localVarToReplace_unit);
    free(localVarToReplace_interval);
    free(localVarToReplace_to_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Intra day candle data
//
// Get OHLC values for all instruments for the present trading day
//
get_intra_day_candle_response_t*
HistoryV3API_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *unit, int *interval)
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
    char *localVarPath = strdup("/v3/historical-candle/intraday/{instrumentKey}/{unit}/{interval}");

    if(!instrumentKey)
        goto end;
    if(!unit)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(unit)+3 +  + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_unit = strlen(instrumentKey)+3 + strlen(unit)+3 +  + sizeof("{ unit }") - 1;
    if(unit == NULL) {
        goto end;
    }
    char* localVarToReplace_unit = malloc(sizeOfPathParams_unit);
    sprintf(localVarToReplace_unit, "{%s}", "unit");

    localVarPath = strReplace(localVarPath, localVarToReplace_unit, unit);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(unit)+3 +  + sizeof("{ interval }") - 1;
    if(interval == 0){
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    snprintf(localVarToReplace_interval, sizeOfPathParams_interval, "{%s}", "interval");

    char localVarBuff_interval[256];
    snprintf(localVarBuff_interval, sizeof localVarBuff_interval, "%ld", (long)*interval);

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, localVarBuff_interval);



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
    //    printf("%s\n","UDAPI1021 - Instrument key is of invalid format&lt;br&gt;UDAPI1146 - Invalid unit&lt;br&gt;UDAPI1147 - Invalid interval&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_intra_day_candle_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *HistoryV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_intra_day_candle_response_parseFromJSON(HistoryV3APIlocalVarJSON);
        cJSON_Delete(HistoryV3APIlocalVarJSON);
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
    free(localVarToReplace_instrumentKey);
    free(localVarToReplace_unit);
    free(localVarToReplace_interval);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

