#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "FundamentalsAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get Balance Sheet
//
// Fetches balance sheet data for the given ISIN.
//
balance_sheet_response_t*
FundamentalsAPI_getBalanceSheet(apiClient_t *apiClient, char *isin, char *type, int *fs)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/balance-sheet");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);



    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_fs = NULL;
    char * valueQuery_fs = NULL;
    keyValuePair_t *keyPairQuery_fs = 0;
    if (fs)
    {
        keyQuery_fs = strdup("fs");
        valueQuery_fs = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_fs, MAX_NUMBER_LENGTH, "%d", *fs);
        keyPairQuery_fs = keyValuePair_create(keyQuery_fs, valueQuery_fs);
        list_addElement(localVarQueryParameters,keyPairQuery_fs);
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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.&lt;br&gt;UDAPI1207 - Invalid type. Allowed values: consolidated, standalone.");
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
    balance_sheet_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = balance_sheet_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_fs){
        free(keyQuery_fs);
        keyQuery_fs = NULL;
    }
    if(valueQuery_fs){
        free(valueQuery_fs);
        valueQuery_fs = NULL;
    }
    if(keyPairQuery_fs){
        keyValuePair_free(keyPairQuery_fs);
        keyPairQuery_fs = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Cash Flow
//
// Fetches cash flow data for the given ISIN.
//
cash_flow_response_t*
FundamentalsAPI_getCashFlow(apiClient_t *apiClient, char *isin, char *type, int *fs)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/cash-flow");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);



    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_fs = NULL;
    char * valueQuery_fs = NULL;
    keyValuePair_t *keyPairQuery_fs = 0;
    if (fs)
    {
        keyQuery_fs = strdup("fs");
        valueQuery_fs = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_fs, MAX_NUMBER_LENGTH, "%d", *fs);
        keyPairQuery_fs = keyValuePair_create(keyQuery_fs, valueQuery_fs);
        list_addElement(localVarQueryParameters,keyPairQuery_fs);
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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.&lt;br&gt;UDAPI1207 - Invalid type. Allowed values: consolidated, standalone.");
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
    cash_flow_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cash_flow_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_fs){
        free(keyQuery_fs);
        keyQuery_fs = NULL;
    }
    if(valueQuery_fs){
        free(valueQuery_fs);
        valueQuery_fs = NULL;
    }
    if(keyPairQuery_fs){
        keyValuePair_free(keyPairQuery_fs);
        keyPairQuery_fs = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Company Profile
//
// Fetches company profile information for the given ISIN.
//
company_profile_response_t*
FundamentalsAPI_getCompanyProfile(apiClient_t *apiClient, char *isin)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/profile");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);


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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.");
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
    company_profile_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = company_profile_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Competitors
//
// Fetches the list of competitors for the given instrument_key.
//
competitors_response_t*
FundamentalsAPI_getCompetitors(apiClient_t *apiClient, char *instrument_key)
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
    char *localVarPath = strdup("/v2/fundamentals/{instrument_key}/competitors");

    if(!instrument_key)
        goto end;


    // Path Params
    long sizeOfPathParams_instrument_key = strlen(instrument_key)+3 + sizeof("{ instrument_key }") - 1;
    if(instrument_key == NULL) {
        goto end;
    }
    char* localVarToReplace_instrument_key = malloc(sizeOfPathParams_instrument_key);
    sprintf(localVarToReplace_instrument_key, "{%s}", "instrument_key");

    localVarPath = strReplace(localVarPath, localVarToReplace_instrument_key, instrument_key);


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
    //    printf("%s\n","UDAPI100011 - Invalid Instrument key.");
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
    competitors_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = competitors_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_instrument_key);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Corporate Actions
//
// Fetches corporate actions for the given ISIN.
//
corporate_actions_response_t*
FundamentalsAPI_getCorporateActions(apiClient_t *apiClient, char *isin)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/corporate-actions");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);


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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.");
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
    corporate_actions_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = corporate_actions_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Income Statement
//
// Fetches income statement data for the given ISIN.
//
income_statement_response_t*
FundamentalsAPI_getIncomeStatement(apiClient_t *apiClient, char *isin, char *type, char *time_period, int *fs)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/income-statement");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);



    // query parameters
    char *keyQuery_type = NULL;
    char * valueQuery_type = NULL;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = strdup((type));
        keyPairQuery_type = keyValuePair_create(keyQuery_type, valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_time_period = NULL;
    char * valueQuery_time_period = NULL;
    keyValuePair_t *keyPairQuery_time_period = 0;
    if (time_period)
    {
        keyQuery_time_period = strdup("time_period");
        valueQuery_time_period = strdup((time_period));
        keyPairQuery_time_period = keyValuePair_create(keyQuery_time_period, valueQuery_time_period);
        list_addElement(localVarQueryParameters,keyPairQuery_time_period);
    }

    // query parameters
    char *keyQuery_fs = NULL;
    char * valueQuery_fs = NULL;
    keyValuePair_t *keyPairQuery_fs = 0;
    if (fs)
    {
        keyQuery_fs = strdup("fs");
        valueQuery_fs = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_fs, MAX_NUMBER_LENGTH, "%d", *fs);
        keyPairQuery_fs = keyValuePair_create(keyQuery_fs, valueQuery_fs);
        list_addElement(localVarQueryParameters,keyPairQuery_fs);
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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.&lt;br&gt;UDAPI1207 - Invalid type. Allowed values: consolidated, standalone.&lt;br&gt;UDAPI1208 - Invalid time period. Allowed values: yearly, quarterly.");
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
    income_statement_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = income_statement_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    if(keyQuery_type){
        free(keyQuery_type);
        keyQuery_type = NULL;
    }
    if(valueQuery_type){
        free(valueQuery_type);
        valueQuery_type = NULL;
    }
    if(keyPairQuery_type){
        keyValuePair_free(keyPairQuery_type);
        keyPairQuery_type = NULL;
    }
    if(keyQuery_time_period){
        free(keyQuery_time_period);
        keyQuery_time_period = NULL;
    }
    if(valueQuery_time_period){
        free(valueQuery_time_period);
        valueQuery_time_period = NULL;
    }
    if(keyPairQuery_time_period){
        keyValuePair_free(keyPairQuery_time_period);
        keyPairQuery_time_period = NULL;
    }
    if(keyQuery_fs){
        free(keyQuery_fs);
        keyQuery_fs = NULL;
    }
    if(valueQuery_fs){
        free(valueQuery_fs);
        valueQuery_fs = NULL;
    }
    if(keyPairQuery_fs){
        keyValuePair_free(keyPairQuery_fs);
        keyPairQuery_fs = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Key Ratios
//
// Fetches key financial ratios for the given ISIN.
//
key_ratios_response_t*
FundamentalsAPI_getKeyRatios(apiClient_t *apiClient, char *isin)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/key-ratios");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);


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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.");
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
    key_ratios_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = key_ratios_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Share Holdings
//
// Fetches shareholding pattern for the given ISIN.
//
share_holdings_response_t*
FundamentalsAPI_getShareHoldings(apiClient_t *apiClient, char *isin)
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
    char *localVarPath = strdup("/v2/fundamentals/{isin}/share-holdings");

    if(!isin)
        goto end;


    // Path Params
    long sizeOfPathParams_isin = strlen(isin)+3 + sizeof("{ isin }") - 1;
    if(isin == NULL) {
        goto end;
    }
    char* localVarToReplace_isin = malloc(sizeOfPathParams_isin);
    sprintf(localVarToReplace_isin, "{%s}", "isin");

    localVarPath = strReplace(localVarPath, localVarToReplace_isin, isin);


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
    //    printf("%s\n","UDAPI1206 - Invalid ISIN.");
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
    share_holdings_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *FundamentalsAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = share_holdings_response_parseFromJSON(FundamentalsAPIlocalVarJSON);
        cJSON_Delete(FundamentalsAPIlocalVarJSON);
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
    free(localVarToReplace_isin);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

