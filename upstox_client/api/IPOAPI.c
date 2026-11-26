#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "IPOAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define MAX_NUMBER_LENGTH_LONG 21

// Functions for enum STATUS for IPOAPI_getIpoListing

static char* getIpoListing_STATUS_ToString(upstox_client_getIpoListing_status_e STATUS){
    char *STATUSArray[] =  { "NULL", "open", "closed", "listed", "upcoming" };
    return STATUSArray[STATUS];
}

static upstox_client_getIpoListing_status_e getIpoListing_STATUS_FromString(char* STATUS){
    int stringToReturn = 0;
    char *STATUSArray[] =  { "NULL", "open", "closed", "listed", "upcoming" };
    size_t sizeofArray = sizeof(STATUSArray) / sizeof(STATUSArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(STATUS, STATUSArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function getIpoListing_STATUS_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *getIpoListing_STATUS_convertToJSON(upstox_client_getIpoListing_status_e STATUS) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "status", getIpoListing_STATUS_ToString(STATUS)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function getIpoListing_STATUS_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static upstox_client_getIpoListing_status_e getIpoListing_STATUS_parseFromJSON(cJSON* STATUSJSON) {
    upstox_client_getIpoListing_status_e STATUSVariable = 0;
    cJSON *STATUSVar = cJSON_GetObjectItemCaseSensitive(STATUSJSON, "status");
    if(!cJSON_IsString(STATUSVar) || (STATUSVar->valuestring == NULL))
    {
        goto end;
    }
    STATUSVariable = getIpoListing_STATUS_FromString(STATUSVar->valuestring);
    return STATUSVariable;
end:
    return 0;
}
*/

// Functions for enum ISSUETYPE for IPOAPI_getIpoListing

static char* getIpoListing_ISSUETYPE_ToString(upstox_client_getIpoListing_issue_type_e ISSUETYPE){
    char *ISSUETYPEArray[] =  { "NULL", "regular", "sme" };
    return ISSUETYPEArray[ISSUETYPE];
}

static upstox_client_getIpoListing_issue_type_e getIpoListing_ISSUETYPE_FromString(char* ISSUETYPE){
    int stringToReturn = 0;
    char *ISSUETYPEArray[] =  { "NULL", "regular", "sme" };
    size_t sizeofArray = sizeof(ISSUETYPEArray) / sizeof(ISSUETYPEArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(ISSUETYPE, ISSUETYPEArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

/*
// Function getIpoListing_ISSUETYPE_convertToJSON is not currently used,
// since conversion to JSON passes through the conversion of the model, and ToString. The function is kept for future reference.
//
static cJSON *getIpoListing_ISSUETYPE_convertToJSON(upstox_client_getIpoListing_issue_type_e ISSUETYPE) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "issue_type", getIpoListing_ISSUETYPE_ToString(ISSUETYPE)) == NULL) {
        goto fail;
    }
    return item;
    fail:
    cJSON_Delete(item);
    return NULL;
}

// Function getIpoListing_ISSUETYPE_parseFromJSON is not currently used,
// since conversion from JSON passes through the conversion of the model, and FromString. The function is kept for future reference.
//
static upstox_client_getIpoListing_issue_type_e getIpoListing_ISSUETYPE_parseFromJSON(cJSON* ISSUETYPEJSON) {
    upstox_client_getIpoListing_issue_type_e ISSUETYPEVariable = 0;
    cJSON *ISSUETYPEVar = cJSON_GetObjectItemCaseSensitive(ISSUETYPEJSON, "issue_type");
    if(!cJSON_IsString(ISSUETYPEVar) || (ISSUETYPEVar->valuestring == NULL))
    {
        goto end;
    }
    ISSUETYPEVariable = getIpoListing_ISSUETYPE_FromString(ISSUETYPEVar->valuestring);
    return ISSUETYPEVariable;
end:
    return 0;
}
*/


// Apply for IPO
//
// Places an IPO application for the authenticated user.
//
ipo_apply_response_t*
IPOAPI_applyForIpo(apiClient_t *apiClient, ipo_apply_request_t *ipo_apply_request)
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
    char *localVarPath = strdup("/v2/ipos/orders");





    // Body Param
    cJSON *localVarSingleItemJSON_ipo_apply_request = NULL;
    if (ipo_apply_request != NULL)
    {
        //not string, not binary
        localVarSingleItemJSON_ipo_apply_request = ipo_apply_request_convertToJSON(ipo_apply_request);
        localVarBodyParameters = cJSON_PrintUnformatted(localVarSingleItemJSON_ipo_apply_request);
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
    //    printf("%s\n","Invalid request payload.");
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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","IPO not found.");
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
    ipo_apply_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_apply_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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
    if (localVarSingleItemJSON_ipo_apply_request) {
        cJSON_Delete(localVarSingleItemJSON_ipo_apply_request);
        localVarSingleItemJSON_ipo_apply_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Cancel IPO Order
//
// Cancels/deletes an IPO order of the authenticated user by order id.
//
ipo_cancel_response_t*
IPOAPI_cancelIpoOrder(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/ipos/orders/{order_id}");

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
    //if (apiClient->response_code == 401) {
    //    printf("%s\n","Authorization Failure");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 403) {
    //    printf("%s\n","Forbidden");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found.");
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
    ipo_cancel_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_cancel_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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

// Get IPO Details
//
// Fetches detailed information for an IPO by its slug ID.
//
ipo_details_response_t*
IPOAPI_getIpoDetails(apiClient_t *apiClient, char *id)
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
    char *localVarPath = strdup("/v2/ipos/{id}");

    if(!id)
        goto end;


    // Path Params
    long sizeOfPathParams_id = strlen(id)+3 + sizeof("{ id }") - 1;
    if(id == NULL) {
        goto end;
    }
    char* localVarToReplace_id = malloc(sizeOfPathParams_id);
    sprintf(localVarToReplace_id, "{%s}", "id");

    localVarPath = strReplace(localVarPath, localVarToReplace_id, id);


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
    //    printf("%s\n","Invalid IPO ID.");
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
    ipo_details_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_details_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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
    free(localVarToReplace_id);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// Get IPO Listing
//
// Fetches list of IPOs filtered by status.
//
ipo_listing_response_t*
IPOAPI_getIpoListing(apiClient_t *apiClient, upstox_client_getIpoListing_status_e status, upstox_client_getIpoListing_issue_type_e issue_type, char *page_number, char *records)
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
    char *localVarPath = strdup("/v2/ipos");





    // query parameters
    char *keyQuery_status = NULL;
    upstox_client_getIpoListing_status_e valueQuery_status ;
    keyValuePair_t *keyPairQuery_status = 0;
    if (status)
    {
        keyQuery_status = strdup("status");
        valueQuery_status = (status);
        keyPairQuery_status = keyValuePair_create(keyQuery_status, strdup(getIpoListing_STATUS_ToString(
        valueQuery_status)));
        list_addElement(localVarQueryParameters,keyPairQuery_status);
    }

    // query parameters
    char *keyQuery_issue_type = NULL;
    upstox_client_getIpoListing_issue_type_e valueQuery_issue_type ;
    keyValuePair_t *keyPairQuery_issue_type = 0;
    if (issue_type)
    {
        keyQuery_issue_type = strdup("issue_type");
        valueQuery_issue_type = (issue_type);
        keyPairQuery_issue_type = keyValuePair_create(keyQuery_issue_type, strdup(getIpoListing_ISSUETYPE_ToString(
        valueQuery_issue_type)));
        list_addElement(localVarQueryParameters,keyPairQuery_issue_type);
    }

    // query parameters
    char *keyQuery_page_number = NULL;
    char * valueQuery_page_number = NULL;
    keyValuePair_t *keyPairQuery_page_number = 0;
    if (page_number)
    {
        keyQuery_page_number = strdup("page_number");
        valueQuery_page_number = strdup((page_number));
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
        valueQuery_records = strdup((records));
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
    //    printf("%s\n","Invalid status or issue_type.");
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
    ipo_listing_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_listing_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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
    if(keyPairQuery_status){
        keyValuePair_free(keyPairQuery_status);
        keyPairQuery_status = NULL;
    }
    if(keyQuery_issue_type){
        free(keyQuery_issue_type);
        keyQuery_issue_type = NULL;
    }
    if(keyPairQuery_issue_type){
        keyValuePair_free(keyPairQuery_issue_type);
        keyPairQuery_issue_type = NULL;
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

// Get IPO Order
//
// Fetches a single IPO order of the authenticated user by order id.
//
ipo_order_detail_response_t*
IPOAPI_getIpoOrderById(apiClient_t *apiClient, char *order_id)
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
    char *localVarPath = strdup("/v2/ipos/orders/{order_id}");

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
    //    printf("%s\n","Bad Request");
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
    //if (apiClient->response_code == 404) {
    //    printf("%s\n","Order not found.");
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
    ipo_order_detail_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_order_detail_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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

// Get IPO Orders
//
// Fetches the authenticated user's IPO orders/applications.
//
ipo_order_response_t*
IPOAPI_getIpoOrders(apiClient_t *apiClient, char *page_number, char *records)
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
    char *localVarPath = strdup("/v2/ipos/orders");





    // query parameters
    char *keyQuery_page_number = NULL;
    char * valueQuery_page_number = NULL;
    keyValuePair_t *keyPairQuery_page_number = 0;
    if (page_number)
    {
        keyQuery_page_number = strdup("page_number");
        valueQuery_page_number = strdup((page_number));
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
        valueQuery_records = strdup((records));
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
    //    printf("%s\n","Invalid pagination parameters.");
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
    ipo_order_response_t *elementToReturn = NULL;
    if(apiClient->response_code >= 200 && apiClient->response_code < 300) {
        cJSON *IPOAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
        elementToReturn = ipo_order_response_parseFromJSON(IPOAPIlocalVarJSON);
        cJSON_Delete(IPOAPIlocalVarJSON);
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

