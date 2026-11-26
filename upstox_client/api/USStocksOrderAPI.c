#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "USStocksOrderAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Cancel US stocks order
//
// Cancels an open US stocks order.
//
us_order_response_t*
USStocksOrderAPI_cancelUsOrder(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/us/order/cancel");





    // query parameters
    char *keyQuery_order_id = NULL;
    char * valueQuery_order_id = NULL;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
    }
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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
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
    //if (apiClient->response_code == 410) {
    //    printf("%s\n","Gone");
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
    us_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *USStocksOrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = us_order_response_parseFromJSON(USStocksOrderAPIlocalVarJSON);
        cJSON_Delete(USStocksOrderAPIlocalVarJSON);
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
    if(keyQuery_order_id){
        free(keyQuery_order_id);
        keyQuery_order_id = NULL;
    }
    if(valueQuery_order_id){
        free(valueQuery_order_id);
        valueQuery_order_id = NULL;
    }
    if(keyPairQuery_order_id){
        keyValuePair_free(keyPairQuery_order_id);
        keyPairQuery_order_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Estimate US stocks order charges
//
// Returns the brokerage, GST and US fees for an order before it is placed; nothing is placed. A market order is estimated at the price sent.
//
us_order_estimate_response_t*
USStocksOrderAPI_estimateUsOrder(apiClient_t *apiClient, us_order_estimate_request_t *us_order_estimate_request)
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
    char *localVarPath = strdup("/v2/us/order/estimate");





    // Body Param
    cJSON *localVarSingleItemJSON_us_order_estimate_request = NULL;
    if (us_order_estimate_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_us_order_estimate_request = us_order_estimate_request_convertToJSON(us_order_estimate_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_us_order_estimate_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
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
    //if (apiClient->response_code == 410) {
    //    printf("%s\n","Gone");
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
    us_order_estimate_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *USStocksOrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = us_order_estimate_response_parseFromJSON(USStocksOrderAPIlocalVarJSON);
        cJSON_Delete(USStocksOrderAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_us_order_estimate_request) {
        cJSON_Delete(localVarSingleItemJSON_us_order_estimate_request);
        localVarSingleItemJSON_us_order_estimate_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get US stocks order book
//
// Returns the user's US stocks orders for the day, in every state; optionally only those with a tag.
//
us_order_book_response_t*
USStocksOrderAPI_getUsOrderBook(apiClient_t *apiClient, char *tag)
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
    char *localVarPath = strdup("/v2/us/order/retrieve-all");





    // query parameters
    char *keyQuery_tag = NULL;
    char * valueQuery_tag = NULL;
    keyValuePair_t *keyPairQuery_tag = 0;
    if (tag)
    {
        keyQuery_tag = strdup("tag");
        valueQuery_tag = strdup((tag));
        keyPairQuery_tag = keyValuePair_create(keyQuery_tag, valueQuery_tag);
        list_addElement(localVarQueryParameters,keyPairQuery_tag);
    }
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
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
    //if (apiClient->response_code == 410) {
    //    printf("%s\n","Gone");
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
    us_order_book_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *USStocksOrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = us_order_book_response_parseFromJSON(USStocksOrderAPIlocalVarJSON);
        cJSON_Delete(USStocksOrderAPIlocalVarJSON);
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
    if(keyQuery_tag){
        free(keyQuery_tag);
        keyQuery_tag = NULL;
    }
    if(valueQuery_tag){
        free(valueQuery_tag);
        valueQuery_tag = NULL;
    }
    if(keyPairQuery_tag){
        keyValuePair_free(keyPairQuery_tag);
        keyPairQuery_tag = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get US stocks order details
//
// Returns the latest state of one US stocks order.
//
us_order_details_response_t*
USStocksOrderAPI_getUsOrderDetails(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/us/order/details");





    // query parameters
    char *keyQuery_order_id = NULL;
    char * valueQuery_order_id = NULL;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
    }
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
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
    //if (apiClient->response_code == 410) {
    //    printf("%s\n","Gone");
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
    us_order_details_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *USStocksOrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = us_order_details_response_parseFromJSON(USStocksOrderAPIlocalVarJSON);
        cJSON_Delete(USStocksOrderAPIlocalVarJSON);
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
    if(keyQuery_order_id){
        free(keyQuery_order_id);
        keyQuery_order_id = NULL;
    }
    if(valueQuery_order_id){
        free(valueQuery_order_id);
        valueQuery_order_id = NULL;
    }
    if(keyPairQuery_order_id){
        keyValuePair_free(keyPairQuery_order_id);
        keyPairQuery_order_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Place US stocks order
//
// Places a market or limit order for a US stock, sized by quantity or by USD amount.
//
us_order_response_t*
USStocksOrderAPI_placeUsOrder(apiClient_t *apiClient, us_place_order_request_t *us_place_order_request)
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
    char *localVarPath = strdup("/v2/us/order/place");





    // Body Param
    cJSON *localVarSingleItemJSON_us_place_order_request = NULL;
    if (us_place_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_us_place_order_request = us_place_order_request_convertToJSON(us_place_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_us_place_order_request);
        localVarBodyLength = strlen(localVarBodyParameters);
    }
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
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad Request");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Unauthorized");
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
    //if (apiClient->response_code == 410) {
    //    printf("%s\n","Gone");
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
    us_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *USStocksOrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = us_order_response_parseFromJSON(USStocksOrderAPIlocalVarJSON);
        cJSON_Delete(USStocksOrderAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_us_place_order_request) {
        cJSON_Delete(localVarSingleItemJSON_us_place_order_request);
        localVarSingleItemJSON_us_place_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

