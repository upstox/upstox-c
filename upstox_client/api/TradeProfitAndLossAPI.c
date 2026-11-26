#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "TradeProfitAndLossAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get profit and loss on trades
//
// This API gives the charges incurred by users for their trades
//
get_profit_and_loss_charges_response_t*
TradeProfitAndLossAPI_getProfitAndLossCharges(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date)
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
    char *localVarPath = strdup("/v2/trade/profit-loss/charges");





    // query parameters
    char *keyQuery_from_date = NULL;
    char * valueQuery_from_date = NULL;
    keyValuePair_t *keyPairQuery_from_date = 0;
    if (from_date)
    {
        keyQuery_from_date = strdup("from_date");
        valueQuery_from_date = strdup((from_date));
        keyPairQuery_from_date = keyValuePair_create(keyQuery_from_date, valueQuery_from_date);
        list_addElement(localVarQueryParameters,keyPairQuery_from_date);
    }

    // query parameters
    char *keyQuery_to_date = NULL;
    char * valueQuery_to_date = NULL;
    keyValuePair_t *keyPairQuery_to_date = 0;
    if (to_date)
    {
        keyQuery_to_date = strdup("to_date");
        valueQuery_to_date = strdup((to_date));
        keyPairQuery_to_date = keyValuePair_create(keyQuery_to_date, valueQuery_to_date);
        list_addElement(localVarQueryParameters,keyPairQuery_to_date);
    }

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
    char *keyQuery_financial_year = NULL;
    char * valueQuery_financial_year = NULL;
    keyValuePair_t *keyPairQuery_financial_year = 0;
    if (financial_year)
    {
        keyQuery_financial_year = strdup("financial_year");
        valueQuery_financial_year = strdup((financial_year));
        keyPairQuery_financial_year = keyValuePair_create(keyQuery_financial_year, valueQuery_financial_year);
        list_addElement(localVarQueryParameters,keyPairQuery_financial_year);
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
    //    printf("%s\n","UDAPI1067 - The &#39;&#39;segment&#39;&#39; is required&lt;br&gt;UDAPI1066 - The &#39;&#39;segment&#39;&#39; is invalid&lt;br&gt;UDAPI1068 - The start_date is required&lt;br&gt;UDAPI1069 - The end_date is required&lt;br&gt;UDAPI1105 - The provided dates do not fall within the specified financial year");
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
    get_profit_and_loss_charges_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TradeProfitAndLossAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_profit_and_loss_charges_response_parseFromJSON(TradeProfitAndLossAPIlocalVarJSON);
        cJSON_Delete(TradeProfitAndLossAPIlocalVarJSON);
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
    if(keyQuery_from_date){
        free(keyQuery_from_date);
        keyQuery_from_date = NULL;
    }
    if(valueQuery_from_date){
        free(valueQuery_from_date);
        valueQuery_from_date = NULL;
    }
    if(keyPairQuery_from_date){
        keyValuePair_free(keyPairQuery_from_date);
        keyPairQuery_from_date = NULL;
    }
    if(keyQuery_to_date){
        free(keyQuery_to_date);
        keyQuery_to_date = NULL;
    }
    if(valueQuery_to_date){
        free(valueQuery_to_date);
        valueQuery_to_date = NULL;
    }
    if(keyPairQuery_to_date){
        keyValuePair_free(keyPairQuery_to_date);
        keyPairQuery_to_date = NULL;
    }
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
    if(keyQuery_financial_year){
        free(keyQuery_financial_year);
        keyQuery_financial_year = NULL;
    }
    if(valueQuery_financial_year){
        free(valueQuery_financial_year);
        valueQuery_financial_year = NULL;
    }
    if(keyPairQuery_financial_year){
        keyValuePair_free(keyPairQuery_financial_year);
        keyPairQuery_financial_year = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get Trade-wise Profit and Loss Report Data
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_data_response_t*
TradeProfitAndLossAPI_getTradeWiseProfitAndLossData(apiClient_t *apiClient, char *segment, char *financial_year, int *page_number, int *page_size, char *from_date, char *to_date)
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
    char *localVarPath = strdup("/v2/trade/profit-loss/data");





    // query parameters
    char *keyQuery_from_date = NULL;
    char * valueQuery_from_date = NULL;
    keyValuePair_t *keyPairQuery_from_date = 0;
    if (from_date)
    {
        keyQuery_from_date = strdup("from_date");
        valueQuery_from_date = strdup((from_date));
        keyPairQuery_from_date = keyValuePair_create(keyQuery_from_date, valueQuery_from_date);
        list_addElement(localVarQueryParameters,keyPairQuery_from_date);
    }

    // query parameters
    char *keyQuery_to_date = NULL;
    char * valueQuery_to_date = NULL;
    keyValuePair_t *keyPairQuery_to_date = 0;
    if (to_date)
    {
        keyQuery_to_date = strdup("to_date");
        valueQuery_to_date = strdup((to_date));
        keyPairQuery_to_date = keyValuePair_create(keyQuery_to_date, valueQuery_to_date);
        list_addElement(localVarQueryParameters,keyPairQuery_to_date);
    }

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
    char *keyQuery_financial_year = NULL;
    char * valueQuery_financial_year = NULL;
    keyValuePair_t *keyPairQuery_financial_year = 0;
    if (financial_year)
    {
        keyQuery_financial_year = strdup("financial_year");
        valueQuery_financial_year = strdup((financial_year));
        keyPairQuery_financial_year = keyValuePair_create(keyQuery_financial_year, valueQuery_financial_year);
        list_addElement(localVarQueryParameters,keyPairQuery_financial_year);
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
    //    printf("%s\n","UDAPI1070 - The financial_year is required&lt;br&gt;UDAPI1071 - The page_number is required&lt;br&gt;UDAPI1072 - The page_size is required&lt;br&gt;UDAPI1067 - The &#39;&#39;segment&#39;&#39; is required&lt;br&gt;UDAPI1066 - The &#39;&#39;segment&#39;&#39; is invalid&lt;br&gt;UDAPI1073 - Financial year should have max length of 4&lt;br&gt;UDAPI1106 - The page_size should be greater than or equal to 1&lt;br&gt;UDAPI1107 - The page_size should be less than or equal to 5000&gt;br&gt;UDAPI1105 - The given dates are not in the mentioned financial year");
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
    get_trade_wise_profit_and_loss_data_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TradeProfitAndLossAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_trade_wise_profit_and_loss_data_response_parseFromJSON(TradeProfitAndLossAPIlocalVarJSON);
        cJSON_Delete(TradeProfitAndLossAPIlocalVarJSON);
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
    if(keyQuery_from_date){
        free(keyQuery_from_date);
        keyQuery_from_date = NULL;
    }
    if(valueQuery_from_date){
        free(valueQuery_from_date);
        valueQuery_from_date = NULL;
    }
    if(keyPairQuery_from_date){
        keyValuePair_free(keyPairQuery_from_date);
        keyPairQuery_from_date = NULL;
    }
    if(keyQuery_to_date){
        free(keyQuery_to_date);
        keyQuery_to_date = NULL;
    }
    if(valueQuery_to_date){
        free(valueQuery_to_date);
        valueQuery_to_date = NULL;
    }
    if(keyPairQuery_to_date){
        keyValuePair_free(keyPairQuery_to_date);
        keyPairQuery_to_date = NULL;
    }
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
    if(keyQuery_financial_year){
        free(keyQuery_financial_year);
        keyQuery_financial_year = NULL;
    }
    if(valueQuery_financial_year){
        free(valueQuery_financial_year);
        valueQuery_financial_year = NULL;
    }
    if(keyPairQuery_financial_year){
        keyValuePair_free(keyPairQuery_financial_year);
        keyPairQuery_financial_year = NULL;
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

// Get profit and loss meta data on trades
//
// This API gives the data of the realised Profit and Loss report requested by a user
//
get_trade_wise_profit_and_loss_meta_data_response_t*
TradeProfitAndLossAPI_getTradeWiseProfitAndLossMetaData(apiClient_t *apiClient, char *segment, char *financial_year, char *from_date, char *to_date)
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
    char *localVarPath = strdup("/v2/trade/profit-loss/metadata");





    // query parameters
    char *keyQuery_from_date = NULL;
    char * valueQuery_from_date = NULL;
    keyValuePair_t *keyPairQuery_from_date = 0;
    if (from_date)
    {
        keyQuery_from_date = strdup("from_date");
        valueQuery_from_date = strdup((from_date));
        keyPairQuery_from_date = keyValuePair_create(keyQuery_from_date, valueQuery_from_date);
        list_addElement(localVarQueryParameters,keyPairQuery_from_date);
    }

    // query parameters
    char *keyQuery_to_date = NULL;
    char * valueQuery_to_date = NULL;
    keyValuePair_t *keyPairQuery_to_date = 0;
    if (to_date)
    {
        keyQuery_to_date = strdup("to_date");
        valueQuery_to_date = strdup((to_date));
        keyPairQuery_to_date = keyValuePair_create(keyQuery_to_date, valueQuery_to_date);
        list_addElement(localVarQueryParameters,keyPairQuery_to_date);
    }

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
    char *keyQuery_financial_year = NULL;
    char * valueQuery_financial_year = NULL;
    keyValuePair_t *keyPairQuery_financial_year = 0;
    if (financial_year)
    {
        keyQuery_financial_year = strdup("financial_year");
        valueQuery_financial_year = strdup((financial_year));
        keyPairQuery_financial_year = keyValuePair_create(keyQuery_financial_year, valueQuery_financial_year);
        list_addElement(localVarQueryParameters,keyPairQuery_financial_year);
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
    //    printf("%s\n","UDAPI1070 - The financial_year is required&lt;br&gt;UDAPI1067 - The &#39;&#39;segment&#39;&#39; is required&lt;br&gt;UDAPI1066 - The &#39;&#39;segment&#39;&#39; is invalid&lt;br&gt;UDAPI1073 - Financial year should have max length of 4&lt;br&gt;UDAPI1068 - The start_date is required&lt;br&gt;UDAPI1069 - The end_date is required&lt;br&gt;UDAPI1105 - The provided dates do not fall within the specified financial year");
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
    get_trade_wise_profit_and_loss_meta_data_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *TradeProfitAndLossAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_trade_wise_profit_and_loss_meta_data_response_parseFromJSON(TradeProfitAndLossAPIlocalVarJSON);
        cJSON_Delete(TradeProfitAndLossAPIlocalVarJSON);
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
    if(keyQuery_from_date){
        free(keyQuery_from_date);
        keyQuery_from_date = NULL;
    }
    if(valueQuery_from_date){
        free(valueQuery_from_date);
        valueQuery_from_date = NULL;
    }
    if(keyPairQuery_from_date){
        keyValuePair_free(keyPairQuery_from_date);
        keyPairQuery_from_date = NULL;
    }
    if(keyQuery_to_date){
        free(keyQuery_to_date);
        keyQuery_to_date = NULL;
    }
    if(valueQuery_to_date){
        free(valueQuery_to_date);
        valueQuery_to_date = NULL;
    }
    if(keyPairQuery_to_date){
        keyValuePair_free(keyPairQuery_to_date);
        keyPairQuery_to_date = NULL;
    }
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
    if(keyQuery_financial_year){
        free(keyQuery_financial_year);
        keyQuery_financial_year = NULL;
    }
    if(valueQuery_financial_year){
        free(valueQuery_financial_year);
        valueQuery_financial_year = NULL;
    }
    if(keyPairQuery_financial_year){
        keyValuePair_free(keyPairQuery_financial_year);
        keyPairQuery_financial_year = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

