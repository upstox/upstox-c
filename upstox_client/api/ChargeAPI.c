#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "ChargeAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Brokerage details
//
// Compute Brokerage Charges
//
get_brokerage_response_t*
ChargeAPI_getBrokerage(apiClient_t *apiClient, char *instrument_token, int *quantity, char *product, char *transaction_type, double price)
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
    char *localVarPath = strdup("/v2/charges/brokerage");





    // query parameters
    char *keyQuery_instrument_token = NULL;
    char * valueQuery_instrument_token = NULL;
    keyValuePair_t *keyPairQuery_instrument_token = 0;
    if (instrument_token)
    {
        keyQuery_instrument_token = strdup("instrument_token");
        valueQuery_instrument_token = strdup((instrument_token));
        keyPairQuery_instrument_token = keyValuePair_create(keyQuery_instrument_token, valueQuery_instrument_token);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_token);
    }

    // query parameters
    char *keyQuery_quantity = NULL;
    char * valueQuery_quantity = NULL;
    keyValuePair_t *keyPairQuery_quantity = 0;
    if (quantity)
    {
        keyQuery_quantity = strdup("quantity");
        valueQuery_quantity = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_quantity, MAX_NUMBER_LENGTH, "%d", *quantity);
        keyPairQuery_quantity = keyValuePair_create(keyQuery_quantity, valueQuery_quantity);
        list_addElement(localVarQueryParameters,keyPairQuery_quantity);
    }

    // query parameters
    char *keyQuery_product = NULL;
    char * valueQuery_product = NULL;
    keyValuePair_t *keyPairQuery_product = 0;
    if (product)
    {
        keyQuery_product = strdup("product");
        valueQuery_product = strdup((product));
        keyPairQuery_product = keyValuePair_create(keyQuery_product, valueQuery_product);
        list_addElement(localVarQueryParameters,keyPairQuery_product);
    }

    // query parameters
    char *keyQuery_transaction_type = NULL;
    char * valueQuery_transaction_type = NULL;
    keyValuePair_t *keyPairQuery_transaction_type = 0;
    if (transaction_type)
    {
        keyQuery_transaction_type = strdup("transaction_type");
        valueQuery_transaction_type = strdup((transaction_type));
        keyPairQuery_transaction_type = keyValuePair_create(keyQuery_transaction_type, valueQuery_transaction_type);
        list_addElement(localVarQueryParameters,keyPairQuery_transaction_type);
    }

    // query parameters
    char *keyQuery_price = NULL;
    char * valueQuery_price = NULL;
    keyValuePair_t *keyPairQuery_price = 0;
    {
        keyQuery_price = strdup("price");
        int s = snprintf(NULL, 0, "%.15g", price);
        if (s >= 0)
        {
            valueQuery_price = calloc(1,s+1);
            snprintf(valueQuery_price, s+1, "%.15g", price);
        }
        keyPairQuery_price = keyValuePair_create(keyQuery_price, valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
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
    //    printf("%s\n","UDAPI1060 - The quantity is required&lt;br&gt;UDAPI1061 - The price is required&lt;br&gt;UDAPI1062 - The transaction_type is required&lt;br&gt; UDAPI1063 - The product is required&lt;br&gt; UDAPI1064 - The quantity cannot be zero&lt;br&gt;UDAPI1065 - The price cannot be zero&lt;br&gt;UDAPI1059 - The instrument_token is of invalid format");
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
    get_brokerage_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ChargeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_brokerage_response_parseFromJSON(ChargeAPIlocalVarJSON);
        cJSON_Delete(ChargeAPIlocalVarJSON);
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
    if(keyQuery_instrument_token){
        free(keyQuery_instrument_token);
        keyQuery_instrument_token = NULL;
    }
    if(valueQuery_instrument_token){
        free(valueQuery_instrument_token);
        valueQuery_instrument_token = NULL;
    }
    if(keyPairQuery_instrument_token){
        keyValuePair_free(keyPairQuery_instrument_token);
        keyPairQuery_instrument_token = NULL;
    }
    if(keyQuery_quantity){
        free(keyQuery_quantity);
        keyQuery_quantity = NULL;
    }
    if(valueQuery_quantity){
        free(valueQuery_quantity);
        valueQuery_quantity = NULL;
    }
    if(keyPairQuery_quantity){
        keyValuePair_free(keyPairQuery_quantity);
        keyPairQuery_quantity = NULL;
    }
    if(keyQuery_product){
        free(keyQuery_product);
        keyQuery_product = NULL;
    }
    if(valueQuery_product){
        free(valueQuery_product);
        valueQuery_product = NULL;
    }
    if(keyPairQuery_product){
        keyValuePair_free(keyPairQuery_product);
        keyPairQuery_product = NULL;
    }
    if(keyQuery_transaction_type){
        free(keyQuery_transaction_type);
        keyQuery_transaction_type = NULL;
    }
    if(valueQuery_transaction_type){
        free(valueQuery_transaction_type);
        valueQuery_transaction_type = NULL;
    }
    if(keyPairQuery_transaction_type){
        keyValuePair_free(keyPairQuery_transaction_type);
        keyPairQuery_transaction_type = NULL;
    }
    if(keyQuery_price){
        free(keyQuery_price);
        keyQuery_price = NULL;
    }
    if(valueQuery_price){
        free(valueQuery_price);
        valueQuery_price = NULL;
    }
    if(keyPairQuery_price){
        keyValuePair_free(keyPairQuery_price);
        keyPairQuery_price = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Calculate Margin
//
// Compute Margin
//
post_margin_response_t*
ChargeAPI_postMargin(apiClient_t *apiClient, margin_request_t *margin_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/charges/margin");





    // Body Param
    cJSON *localVarSingleItemJSON_margin_request = NULL;
    if (margin_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_margin_request = margin_request_convertToJSON(margin_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_margin_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"*/*"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    localVarBodyLength,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1095 - The price must be greater than zero&lt;br&gt;UDAPI1096 - Quantity cannot be less than or equal to zero&lt;br&gt;UDAPI1097 - The quantity is required&lt;br&gt;UDAPI1098 - The instrument_token is of invalid format&lt;br&gt;UDAPI1099 - The instrument key is required&lt;br&gt;UDAPI1100 - The product is required&lt;br&gt;UDAPI1101 - The transaction_type is required&lt;br&gt;UDAPI1102 - The instrument limit has been exceeded&lt;br&gt;UDAPI1103 - Instrument key cannot be duplicated&lt;br&gt;UDAPI1104 - Quantity should be multiple of lot size");
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
    post_margin_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *ChargeAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = post_margin_response_parseFromJSON(ChargeAPIlocalVarJSON);
        cJSON_Delete(ChargeAPIlocalVarJSON);
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
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_margin_request) {
        cJSON_Delete(localVarSingleItemJSON_margin_request);
        localVarSingleItemJSON_margin_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

