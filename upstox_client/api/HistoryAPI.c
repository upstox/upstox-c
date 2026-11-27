#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "HistoryAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Historical candle data
//
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
HistoryAPI_getHistoricalCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date)
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
    char *localVarPath = strdup("/v2/historical-candle/{instrumentKey}/{interval}/{to_date}");

    if(!instrumentKey)
        goto end;
    if(!interval)
        goto end;
    if(!to_date)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + sizeof("{ interval }") - 1;
    if(interval == NULL) {
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    sprintf(localVarToReplace_interval, "{%s}", "interval");

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, interval);

    // Path Params
    long sizeOfPathParams_to_date = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + sizeof("{ to_date }") - 1;
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
        cJSON *HistoryAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_historical_candle_response_parseFromJSON(HistoryAPIlocalVarJSON);
        cJSON_Delete(HistoryAPIlocalVarJSON);
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
    free(localVarToReplace_interval);
    free(localVarToReplace_to_date);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Historical candle data
//
// Get OHLC values for all instruments across various timeframes. Historical data can be fetched for the following durations. 1minute: last 1 month candles till endDate 30minute: last 1 year candles till endDate day: last 1 year candles till endDate week: last 10 year candles till endDate month: last 10 year candles till endDate
//
get_historical_candle_response_t*
HistoryAPI_getHistoricalCandleData1(apiClient_t *apiClient, char *instrumentKey, char *interval, char *to_date, char *from_date)
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
    char *localVarPath = strdup("/v2/historical-candle/{instrumentKey}/{interval}/{to_date}/{from_date}");

    if(!instrumentKey)
        goto end;
    if(!interval)
        goto end;
    if(!to_date)
        goto end;
    if(!from_date)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ interval }") - 1;
    if(interval == NULL) {
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    sprintf(localVarToReplace_interval, "{%s}", "interval");

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, interval);

    // Path Params
    long sizeOfPathParams_to_date = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ to_date }") - 1;
    if(to_date == NULL) {
        goto end;
    }
    char* localVarToReplace_to_date = malloc(sizeOfPathParams_to_date);
    sprintf(localVarToReplace_to_date, "{%s}", "to_date");

    localVarPath = strReplace(localVarPath, localVarToReplace_to_date, to_date);

    // Path Params
    long sizeOfPathParams_from_date = strlen(instrumentKey)+3 + strlen(interval)+3 + strlen(to_date)+3 + strlen(from_date)+3 + sizeof("{ from_date }") - 1;
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
        cJSON *HistoryAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_historical_candle_response_parseFromJSON(HistoryAPIlocalVarJSON);
        cJSON_Delete(HistoryAPIlocalVarJSON);
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
    free(localVarToReplace_interval);
    free(localVarToReplace_to_date);
    free(localVarToReplace_from_date);
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
HistoryAPI_getIntraDayCandleData(apiClient_t *apiClient, char *instrumentKey, char *interval)
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
    char *localVarPath = strdup("/v2/historical-candle/intraday/{instrumentKey}/{interval}");

    if(!instrumentKey)
        goto end;
    if(!interval)
        goto end;


    // Path Params
    long sizeOfPathParams_instrumentKey = strlen(instrumentKey)+3 + strlen(interval)+3 + sizeof("{ instrumentKey }") - 1;
    if(instrumentKey == NULL) {
        goto end;
    }
    char* localVarToReplace_instrumentKey = malloc(sizeOfPathParams_instrumentKey);
    sprintf(localVarToReplace_instrumentKey, "{%s}", "instrumentKey");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrumentKey, instrumentKey);

    // Path Params
    long sizeOfPathParams_interval = strlen(instrumentKey)+3 + strlen(interval)+3 + sizeof("{ interval }") - 1;
    if(interval == NULL) {
        goto end;
    }
    char* localVarToReplace_interval = malloc(sizeOfPathParams_interval);
    sprintf(localVarToReplace_interval, "{%s}", "interval");

    localVarPath = strReplace(localVarPath, localVarToReplace_interval, interval);


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
    //    printf("%s\n","UDAPI1076 - Interval accepts one of (1minute,30minute)&lt;br&gt;UDAPI1021 - Instrument key is of invalid format&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
        cJSON *HistoryAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_intra_day_candle_response_parseFromJSON(HistoryAPIlocalVarJSON);
        cJSON_Delete(HistoryAPIlocalVarJSON);
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
    free(localVarToReplace_interval);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

