#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "MutualFundAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Get mutual fund holdings
//
// Returns mutual fund holdings for the authenticated user.
//
get_mutual_fund_holdings_response_t*
MutualFundAPI_getMutualFundHoldings(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v2/mf/holdings");




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
    //    printf("%s\n","Business error");
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
    get_mutual_fund_holdings_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MutualFundAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_mutual_fund_holdings_response_parseFromJSON(MutualFundAPIlocalVarJSON);
        cJSON_Delete(MutualFundAPIlocalVarJSON);
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

// Get mutual fund order by id
//
// Returns a single mutual fund order by order id.
//
get_mutual_fund_order_details_response_t*
MutualFundAPI_getMutualFundOrder(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/mf/orders/{order_id}");

    if(!order_id)
        goto end;


    // Path Params
    long sizeOfPathParams_order_id = strlen(order_id)+3 + sizeof("{ order_id }") - 1;
    if(order_id == NULL) {
        goto end;
    }
    char* localVarToReplace_order_id = malloc(sizeOfPathParams_order_id);
    sprintf(localVarToReplace_order_id, "{%s}", "order_id");

    localVarPath = strReplace(localVarPath, localVarToReplace_order_id, order_id);


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
    //    printf("%s\n","Business error");
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
    get_mutual_fund_order_details_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MutualFundAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_mutual_fund_order_details_response_parseFromJSON(MutualFundAPIlocalVarJSON);
        cJSON_Delete(MutualFundAPIlocalVarJSON);
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
    free(localVarToReplace_order_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get mutual fund orders
//
// Returns mutual fund orders from the last 7 days for the authenticated user.
//
get_mutual_fund_orders_response_t*
MutualFundAPI_getMutualFundOrders(apiClient_t *apiClient, char *status, char *transaction_type, int *page_number, int *records)
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
    char *localVarPath = strdup("/v2/mf/orders");





    // query parameters
    char *keyQuery_status = NULL;
    char * valueQuery_status = NULL;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = strdup((status));
        keyPairQuery_status = keyValuePair_create(keyQuery_status, valueQuery_status);
        list_addElement(localVarQueryParameters,keyPairQuery_status);
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
    //    printf("%s\n","Business error");
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
    get_mutual_fund_orders_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MutualFundAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_mutual_fund_orders_response_parseFromJSON(MutualFundAPIlocalVarJSON);
        cJSON_Delete(MutualFundAPIlocalVarJSON);
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
    if(keyQuery_status){
        free(keyQuery_status);
        keyQuery_status = NULL;
    }
    if(valueQuery_status){
        free(valueQuery_status);
        valueQuery_status = NULL;
    }
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
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

// Get mutual fund SIPs
//
// Returns active and paused SIP orders for the authenticated user.
//
get_mutual_fund_sips_response_t*
MutualFundAPI_getMutualFundSips(apiClient_t *apiClient, int *page_number, int *records)
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
    char *localVarPath = strdup("/v2/mf/sips");





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
    //    printf("%s\n","Business error");
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
    get_mutual_fund_sips_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *MutualFundAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_mutual_fund_sips_response_parseFromJSON(MutualFundAPIlocalVarJSON);
        cJSON_Delete(MutualFundAPIlocalVarJSON);
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

