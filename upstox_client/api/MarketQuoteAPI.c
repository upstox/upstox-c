#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "MarketQuoteAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Market quotes and instruments - Full market quotes
//
// This API provides the functionality to retrieve the full market quotes for one or more instruments.This API returns the complete market data snapshot of up to 500 instruments in one go.
//
get_full_market_quote_response_t*
MarketQuoteAPI_getFullMarketQuote(apiClient_t *apiClient, char *symbol, char *instrument_key)
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
    char *localVarPath = strdup("/v2/market-quote/quotes");





    // query parameters
    char *keyQuery_symbol = NULL;
    char * valueQuery_symbol = NULL;
    keyValuePair_t *keyPairQuery_symbol = 0;
    if (symbol)
    {
        keyQuery_symbol = strdup("symbol");
        valueQuery_symbol = strdup((symbol));
        keyPairQuery_symbol = keyValuePair_create(keyQuery_symbol, valueQuery_symbol);
        list_addElement(localVarQueryParameters,keyPairQuery_symbol);
    }

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
    //    printf("%s\n","UDAPI1009 - symbol is required&lt;br&gt;UDAPI1011 - symbol is of invalid format&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_full_market_quote_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketQuoteAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_full_market_quote_response_parseFromJSON(MarketQuoteAPIlocalVarJSON);
        cJSON_Delete(MarketQuoteAPIlocalVarJSON);
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
    if(keyQuery_symbol){
        free(keyQuery_symbol);
        keyQuery_symbol = NULL;
    }
    if(valueQuery_symbol){
        free(valueQuery_symbol);
        valueQuery_symbol = NULL;
    }
    if(keyPairQuery_symbol){
        keyValuePair_free(keyPairQuery_symbol);
        keyPairQuery_symbol = NULL;
    }
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

// Market quotes and instruments - OHLC quotes
//
// This API provides the functionality to retrieve the OHLC quotes for one or more instruments.This API returns the OHLC snapshots of up to 1000 instruments in one go.
//
get_market_quote_ohlc_response_t*
MarketQuoteAPI_getMarketQuoteOHLC(apiClient_t *apiClient, char *interval, char *symbol, char *instrument_key)
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
    char *localVarPath = strdup("/v2/market-quote/ohlc");





    // query parameters
    char *keyQuery_symbol = NULL;
    char * valueQuery_symbol = NULL;
    keyValuePair_t *keyPairQuery_symbol = 0;
    if (symbol)
    {
        keyQuery_symbol = strdup("symbol");
        valueQuery_symbol = strdup((symbol));
        keyPairQuery_symbol = keyValuePair_create(keyQuery_symbol, valueQuery_symbol);
        list_addElement(localVarQueryParameters,keyPairQuery_symbol);
    }

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
    //    printf("%s\n","UDAPI1009 - symbol is required&lt;br&gt;UDAPI1011 - symbol is of invalid format&lt;br&gt;UDAPI1027 - interval is required&lt;br&gt;UDAPI1028 - Invalid interval&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_market_quote_ohlc_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketQuoteAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_market_quote_ohlc_response_parseFromJSON(MarketQuoteAPIlocalVarJSON);
        cJSON_Delete(MarketQuoteAPIlocalVarJSON);
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
    if(keyQuery_symbol){
        free(keyQuery_symbol);
        keyQuery_symbol = NULL;
    }
    if(valueQuery_symbol){
        free(valueQuery_symbol);
        valueQuery_symbol = NULL;
    }
    if(keyPairQuery_symbol){
        keyValuePair_free(keyPairQuery_symbol);
        keyPairQuery_symbol = NULL;
    }
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

// Market quotes and instruments - LTP quotes.
//
// This API provides the functionality to retrieve the LTP quotes for one or more instruments.This API returns the LTPs of up to 1000 instruments in one go.
//
get_market_quote_last_traded_price_response_t*
MarketQuoteAPI_ltp(apiClient_t *apiClient, char *symbol, char *instrument_key)
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
    char *localVarPath = strdup("/v2/market-quote/ltp");





    // query parameters
    char *keyQuery_symbol = NULL;
    char * valueQuery_symbol = NULL;
    keyValuePair_t *keyPairQuery_symbol = 0;
    if (symbol)
    {
        keyQuery_symbol = strdup("symbol");
        valueQuery_symbol = strdup((symbol));
        keyPairQuery_symbol = keyValuePair_create(keyQuery_symbol, valueQuery_symbol);
        list_addElement(localVarQueryParameters,keyPairQuery_symbol);
    }

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
    //    printf("%s\n","UDAPI1009 - symbol is required&lt;br&gt;UDAPI1011 - symbol is of invalid format&lt;br&gt;UDAPI100011 - Invalid Instrument key");
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
    get_market_quote_last_traded_price_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MarketQuoteAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_market_quote_last_traded_price_response_parseFromJSON(MarketQuoteAPIlocalVarJSON);
        cJSON_Delete(MarketQuoteAPIlocalVarJSON);
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
    if(keyQuery_symbol){
        free(keyQuery_symbol);
        keyQuery_symbol = NULL;
    }
    if(valueQuery_symbol){
        free(valueQuery_symbol);
        valueQuery_symbol = NULL;
    }
    if(keyPairQuery_symbol){
        keyValuePair_free(keyPairQuery_symbol);
        keyPairQuery_symbol = NULL;
    }
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

