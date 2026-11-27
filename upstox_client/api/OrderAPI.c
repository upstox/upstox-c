#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "OrderAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Cancel multi order
//
// API to cancel all the open or pending orders which can be applied to both AMO and regular orders.
//
cancel_or_exit_multi_order_response_t*
OrderAPI_cancelMultiOrder(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/multi/cancel");





    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1105 - Invalid segment&lt;br&gt;UDAPI1108 - No open or pending order available&lt;br&gt;UDAPI1109 - Available open or pending orders should not be more than limit");
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
    cancel_or_exit_multi_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cancel_or_exit_multi_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Cancel order
//
// Cancel order API can be used for two purposes: Cancelling an open order which could be an AMO or a normal order It is also used to EXIT a CO or OCO(bracket order)
//
cancel_order_response_t*
OrderAPI_cancelOrder(apiClient_t *apiClient, char *order_id, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/cancel");





    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


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
                    "DELETE");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1010 - Order id accepts only alphanumeric characters and &#39;-&#39;.&lt;br&gt;UDAPI1023 - Order id is required&lt;br&gt;UDAPI100010 - Unknown order id | order request rejected");
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
    cancel_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cancel_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
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

// Exit all positions
//
// This API provides the functionality to exit all the positions 
//
cancel_or_exit_multi_order_response_t*
OrderAPI_exitPositions(apiClient_t *apiClient, char *tag, char *segment, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/positions/exit");





    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


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
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI1105 - Invalid segment. &lt;br&gt;UDAPI1108 - No open position available to exit.&lt;br&gt;UDAPI1109 - Available open positions should not be more than limit.");
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
    cancel_or_exit_multi_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cancel_or_exit_multi_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get order book
//
// This API provides the list of orders placed by the user. The orders placed by the user is transient for a day and is cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.
//
get_order_book_response_t*
OrderAPI_getOrderBook(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v2/order/retrieve-all");




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
    //    printf("%s\n","Bad Request");
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
    get_order_book_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_order_book_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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

// Get order history
//
// This API provides the details of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session. This API returns all states of the orders, namely, open, pending, and filled ones.  The order history can be requested either using order_id or tag.  If both the options are passed, the history of the order which precisely matches both the order_id and tag will be returned in the response.  If only the tag is passed, the history of all the associated orders which matches the tag will be shared in the response.
//
get_order_response_t*
OrderAPI_getOrderDetails(apiClient_t *apiClient, char *order_id, char *tag)
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
    char *localVarPath = strdup("/v2/order/history");





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
    //    printf("%s\n","UDAPI1010 - Order id accepts only alphanumeric characters and &#39;-&#39;&lt;br&gt;UDAPI1023 - Order id is required&lt;br&gt;UDAPI100010 - Unknown order id | order request rejected");
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
    get_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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

// Get order details
//
// This API provides the recent detail of the particular order the user has placed. The orders placed by the user is transient for a day and are cleared by the end of the trading session.\\n\\nThe order details can be requested using order_id.  
//
get_order_details_response_t*
OrderAPI_getOrderStatus(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/order/details");





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
    //    printf("%s\n","UDAPI1010 - Order id accepts only alphanumeric characters and &#39;-&#39;&lt;br&gt;UDAPI1023 - Order id is required&lt;br&gt;UDAPI100010 - Unknown order id | order request rejected");
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
    get_order_details_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_order_details_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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

// Get trades
//
// Retrieve the trades executed for the day
//
get_trade_response_t*
OrderAPI_getTradeHistory(apiClient_t *apiClient)
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
    char *localVarPath = strdup("/v2/order/trades/get-trades-for-day");




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
    //    printf("%s\n","Bad Request");
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
    get_trade_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_trade_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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

// Get trades for order
//
// Retrieve the trades executed for an order
//
get_trade_response_t*
OrderAPI_getTradesByOrder(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/order/trades");





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
    //    printf("%s\n","UDAPI1010 - Order id accepts only alphanumeric characters and &#39;-&#39;.&lt;br&gt;UDAPI1023 - Order id is required&lt;br&gt;UDAPI100010 - Unknown order id | order request rejected");
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
    get_trade_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_trade_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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

// Modify order
//
// This API allows you to modify an order. For modification orderId is mandatory. With orderId you need to send the optional parameter which needs to be modified. In case the optional parameters aren't sent, the default will be considered from the original order
//
modify_order_response_t*
OrderAPI_modifyOrder(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/modify");





    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


    // Body Param
    cJSON *localVarSingleItemJSON_modify_order_request = NULL;
    if (modify_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_modify_order_request = modify_order_request_convertToJSON(modify_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_modify_order_request);
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
                    "PUT");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","UDAPI100010 - Unknown order id | order request rejected");
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
    modify_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = modify_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
    if (localVarSingleItemJSON_modify_order_request) {
        cJSON_Delete(localVarSingleItemJSON_modify_order_request);
        localVarSingleItemJSON_modify_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Place multi order
//
// This API allows you to place multiple orders to the exchange via Upstox.
//
multi_order_response_t*
OrderAPI_placeMultiOrder(apiClient_t *apiClient, list_t *multi_order_request, char *Origin, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/multi/place");





    // header parameters
    char *keyHeader_Origin = NULL;
    char * valueHeader_Origin = 0;
    keyValuePair_t *keyPairHeader_Origin = 0;
    if (Origin) {
        keyHeader_Origin = strdup("Origin");
        valueHeader_Origin = strdup((Origin));
        keyPairHeader_Origin = keyValuePair_create(keyHeader_Origin, valueHeader_Origin);
        list_addElement(localVarHeaderParameters,keyPairHeader_Origin);
    }


    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


    // Body Param
    //notstring
    cJSON *localVar_multi_order_request = NULL;
    cJSON *localVarItemJSON_multi_order_request = NULL;
    cJSON *localVarSingleItemJSON_multi_order_request = NULL;
    if (multi_order_request != NULL)
    {
        localVarItemJSON_multi_order_request = cJSON_CreateArray();
        localVarSingleItemJSON_multi_order_request = localVarItemJSON_multi_order_request;
        if (localVarSingleItemJSON_multi_order_request == NULL)
        {
            // nonprimitive container

            goto end;
        }
    }

    listEntry_t *multi_order_requestBodyListEntry;
    list_ForEach(multi_order_requestBodyListEntry, multi_order_request)
    {
        localVar_multi_order_request = multi_order_request_convertToJSON(multi_order_requestBodyListEntry->data);
        if(localVar_multi_order_request == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(localVarSingleItemJSON_multi_order_request, localVar_multi_order_request);
        localVar_multi_order_request = NULL;
    }
    if (localVarItemJSON_multi_order_request) {
        localVarBodyParameters = cJSON_PrintUnformatted(localVarItemJSON_multi_order_request);
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
    //    printf("%s\n","Bad Request");
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
    multi_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = multi_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyHeader_Origin) {
        free(keyHeader_Origin);
        keyHeader_Origin = NULL;
    }
    if (valueHeader_Origin) {
        free(valueHeader_Origin);
        valueHeader_Origin = NULL;
    }
    free(keyPairHeader_Origin);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
    if (localVarItemJSON_multi_order_request) {
        cJSON_Delete(localVarItemJSON_multi_order_request);
        localVarItemJSON_multi_order_request = NULL;
    }
    if (localVar_multi_order_request) {
        cJSON_Delete(localVar_multi_order_request);
        localVar_multi_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Place order
//
// This API allows you to place an order to the exchange via Upstox.
//
place_order_response_t*
OrderAPI_placeOrder(apiClient_t *apiClient, place_order_request_t *place_order_request, char *X_Algo_Name)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_createList();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;
    size_t     localVarBodyLength = 0;

    // clear the error code from the previous api call
    apiClient->response_code = 0;

    // create the path
    char *localVarPath = strdup("/v2/order/place");





    // header parameters
    char *keyHeader_X_Algo_Name = NULL;
    char * valueHeader_X_Algo_Name = 0;
    keyValuePair_t *keyPairHeader_X_Algo_Name = 0;
    if (X_Algo_Name) {
        keyHeader_X_Algo_Name = strdup("X-Algo-Name");
        valueHeader_X_Algo_Name = strdup((X_Algo_Name));
        keyPairHeader_X_Algo_Name = keyValuePair_create(keyHeader_X_Algo_Name, valueHeader_X_Algo_Name);
        list_addElement(localVarHeaderParameters,keyPairHeader_X_Algo_Name);
    }


    // Body Param
    cJSON *localVarSingleItemJSON_place_order_request = NULL;
    if (place_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_place_order_request = place_order_request_convertToJSON(place_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_place_order_request);
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
    //    printf("%s\n","Bad Request");
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
    place_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = place_order_response_parseFromJSON(OrderAPIlocalVarJSON);
        cJSON_Delete(OrderAPIlocalVarJSON);
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
    
    list_freeList(localVarHeaderParameters);
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (keyHeader_X_Algo_Name) {
        free(keyHeader_X_Algo_Name);
        keyHeader_X_Algo_Name = NULL;
    }
    if (valueHeader_X_Algo_Name) {
        free(valueHeader_X_Algo_Name);
        valueHeader_X_Algo_Name = NULL;
    }
    free(keyPairHeader_X_Algo_Name);
    if (localVarSingleItemJSON_place_order_request) {
        cJSON_Delete(localVarSingleItemJSON_place_order_request);
        localVarSingleItemJSON_place_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

