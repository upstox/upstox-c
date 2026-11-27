#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "OrderV3API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21


// Cancel GTT order
//
// This API allows you to cancel GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_cancelGTTOrder(apiClient_t *apiClient, gtt_cancel_order_request_t *gtt_cancel_order_request, char *Origin, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/gtt/cancel");





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
    cJSON *localVarSingleItemJSON_gtt_cancel_order_request = NULL;
    if (gtt_cancel_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_gtt_cancel_order_request = gtt_cancel_order_request_convertToJSON(gtt_cancel_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_gtt_cancel_order_request);
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
                    "DELETE");

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
    gtt_trigger_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gtt_trigger_order_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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
    if (localVarSingleItemJSON_gtt_cancel_order_request) {
        cJSON_Delete(localVarSingleItemJSON_gtt_cancel_order_request);
        localVarSingleItemJSON_gtt_cancel_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

cancel_order_v3_response_t*
OrderV3API_cancelOrderV3(apiClient_t *apiClient, char *order_id, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/cancel");





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
    cancel_order_v3_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = cancel_order_v3_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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

// Get GTT order details
//
// GTT_ORDER_DESCRIPTION
//
get_gtt_order_response_t*
OrderV3API_getGttOrderDetails(apiClient_t *apiClient, char *gtt_order_id)
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
    char *localVarPath = strdup("/v3/order/gtt");





    // query parameters
    char *keyQuery_gtt_order_id = NULL;
    char * valueQuery_gtt_order_id = NULL;
    keyValuePair_t *keyPairQuery_gtt_order_id = 0;
    if (gtt_order_id)
    {
        keyQuery_gtt_order_id = strdup("gtt_order_id");
        valueQuery_gtt_order_id = strdup((gtt_order_id));
        keyPairQuery_gtt_order_id = keyValuePair_create(keyQuery_gtt_order_id, valueQuery_gtt_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_gtt_order_id);
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
    get_gtt_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = get_gtt_order_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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
    if(keyQuery_gtt_order_id){
        free(keyQuery_gtt_order_id);
        keyQuery_gtt_order_id = NULL;
    }
    if(valueQuery_gtt_order_id){
        free(valueQuery_gtt_order_id);
        valueQuery_gtt_order_id = NULL;
    }
    if(keyPairQuery_gtt_order_id){
        keyValuePair_free(keyPairQuery_gtt_order_id);
        keyPairQuery_gtt_order_id = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Modify GTT order
//
// This API allows you to modify GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_modifyGTTOrder(apiClient_t *apiClient, gtt_modify_order_request_t *gtt_modify_order_request, char *Origin, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/gtt/modify");





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
    cJSON *localVarSingleItemJSON_gtt_modify_order_request = NULL;
    if (gtt_modify_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_gtt_modify_order_request = gtt_modify_order_request_convertToJSON(gtt_modify_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_gtt_modify_order_request);
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
    gtt_trigger_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gtt_trigger_order_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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
    if (localVarSingleItemJSON_gtt_modify_order_request) {
        cJSON_Delete(localVarSingleItemJSON_gtt_modify_order_request);
        localVarSingleItemJSON_gtt_modify_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

modify_order_v3_response_t*
OrderV3API_modifyOrderV3(apiClient_t *apiClient, modify_order_request_t *modify_order_request, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/modify");





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
    //    printf("%s\n","OK");
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
    modify_order_v3_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = modify_order_v3_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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

// Place GTT order
//
// This API allows you to place GTT orders.
//
gtt_trigger_order_response_t*
OrderV3API_placeGTTOrder(apiClient_t *apiClient, gtt_place_order_request_t *gtt_place_order_request, char *Origin, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/gtt/place");





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
    cJSON *localVarSingleItemJSON_gtt_place_order_request = NULL;
    if (gtt_place_order_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_gtt_place_order_request = gtt_place_order_request_convertToJSON(gtt_place_order_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_gtt_place_order_request);
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
    gtt_trigger_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = gtt_trigger_order_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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
    if (localVarSingleItemJSON_gtt_place_order_request) {
        cJSON_Delete(localVarSingleItemJSON_gtt_place_order_request);
        localVarSingleItemJSON_gtt_place_order_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

place_order_v3_response_t*
OrderV3API_placeOrderV3(apiClient_t *apiClient, place_order_v3_request_t *place_order_v3_request, char *X_Algo_Name)
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
    char *localVarPath = strdup("/v3/order/place");





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
    cJSON *localVarSingleItemJSON_place_order_v3_request = NULL;
    if (place_order_v3_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_place_order_v3_request = place_order_v3_request_convertToJSON(place_order_v3_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_place_order_v3_request);
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
    place_order_v3_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *OrderV3APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = place_order_v3_response_parseFromJSON(OrderV3APIlocalVarJSON);
        cJSON_Delete(OrderV3APIlocalVarJSON);
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
    if (localVarSingleItemJSON_place_order_v3_request) {
        cJSON_Delete(localVarSingleItemJSON_place_order_v3_request);
        localVarSingleItemJSON_place_order_v3_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

