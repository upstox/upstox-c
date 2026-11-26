#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "o_auth_client_exception.h"



static o_auth_client_exception_t *o_auth_client_exception_create_internal(
    o_auth_client_exception_cause_t *cause,
    list_t *stack_trace,
    char *message,
    list_t *suppressed,
    char *localized_message
    ) {
    o_auth_client_exception_t *o_auth_client_exception_local_var = malloc(sizeof(o_auth_client_exception_t));
    if (!o_auth_client_exception_local_var) {
        return NULL;
    }
    memset(o_auth_client_exception_local_var, 0, sizeof(o_auth_client_exception_t));
    o_auth_client_exception_local_var->_library_owned = 1;
    o_auth_client_exception_local_var->cause = cause;
    o_auth_client_exception_local_var->stack_trace = stack_trace;
    o_auth_client_exception_local_var->message = message;
    o_auth_client_exception_local_var->suppressed = suppressed;
    o_auth_client_exception_local_var->localized_message = localized_message;
    return o_auth_client_exception_local_var;
}

o_auth_client_exception_t *o_auth_client_exception_create(
    o_auth_client_exception_cause_t *cause,
    list_t *stack_trace,
    char *message,
    list_t *suppressed,
    char *localized_message
    ) {
    o_auth_client_exception_t *result = o_auth_client_exception_create_internal (
        cause,
        stack_trace,
        message,
        suppressed,
        localized_message
        );
    if (!result) {
    }
    return result;
}

void o_auth_client_exception_free(o_auth_client_exception_t *o_auth_client_exception) {
    if(NULL == o_auth_client_exception){
        return ;
    }
    if(o_auth_client_exception->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "o_auth_client_exception_free");
        return ;
    }
    listEntry_t *listEntry;
    if (o_auth_client_exception->cause) {
        o_auth_client_exception_cause_free(o_auth_client_exception->cause);
        o_auth_client_exception->cause = NULL;
    }
    if (o_auth_client_exception->stack_trace) {
        list_ForEach(listEntry, o_auth_client_exception->stack_trace) {
            o_auth_client_exception_cause_stack_trace_inner_free(listEntry->data);
        }
        list_freeList(o_auth_client_exception->stack_trace);
        o_auth_client_exception->stack_trace = NULL;
    }
    if (o_auth_client_exception->message) {
        free(o_auth_client_exception->message);
        o_auth_client_exception->message = NULL;
    }
    if (o_auth_client_exception->suppressed) {
        list_ForEach(listEntry, o_auth_client_exception->suppressed) {
            o_auth_client_exception_cause_free(listEntry->data);
        }
        list_freeList(o_auth_client_exception->suppressed);
        o_auth_client_exception->suppressed = NULL;
    }
    if (o_auth_client_exception->localized_message) {
        free(o_auth_client_exception->localized_message);
        o_auth_client_exception->localized_message = NULL;
    }
    free(o_auth_client_exception);
}

cJSON *o_auth_client_exception_convertToJSON(o_auth_client_exception_t *o_auth_client_exception) {
    cJSON *item = cJSON_CreateObject();

    // o_auth_client_exception->cause
    if(o_auth_client_exception->cause) {
    cJSON *cause_local_JSON = o_auth_client_exception_cause_convertToJSON(o_auth_client_exception->cause);
    if(cause_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cause", cause_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // o_auth_client_exception->stack_trace
    if(o_auth_client_exception->stack_trace) {
    cJSON *stack_trace = cJSON_AddArrayToObject(item, "stackTrace");
    if(stack_trace == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *stack_traceListEntry;
    if (o_auth_client_exception->stack_trace) {
    list_ForEach(stack_traceListEntry, o_auth_client_exception->stack_trace) {
    cJSON *itemLocal = o_auth_client_exception_cause_stack_trace_inner_convertToJSON(stack_traceListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(stack_trace, itemLocal);
    }
    }
    }


    // o_auth_client_exception->message
    if(o_auth_client_exception->message) {
    if(cJSON_AddStringToObject(item, "message", o_auth_client_exception->message) == NULL) {
    goto fail; //String
    }
    }


    // o_auth_client_exception->suppressed
    if(o_auth_client_exception->suppressed) {
    cJSON *suppressed = cJSON_AddArrayToObject(item, "suppressed");
    if(suppressed == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *suppressedListEntry;
    if (o_auth_client_exception->suppressed) {
    list_ForEach(suppressedListEntry, o_auth_client_exception->suppressed) {
    cJSON *itemLocal = o_auth_client_exception_cause_convertToJSON(suppressedListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(suppressed, itemLocal);
    }
    }
    }


    // o_auth_client_exception->localized_message
    if(o_auth_client_exception->localized_message) {
    if(cJSON_AddStringToObject(item, "localizedMessage", o_auth_client_exception->localized_message) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

o_auth_client_exception_t *o_auth_client_exception_parseFromJSON(cJSON *o_auth_client_exceptionJSON){

    o_auth_client_exception_t *o_auth_client_exception_local_var = NULL;

    // define the local variable for o_auth_client_exception->cause
    o_auth_client_exception_cause_t *cause_local_nonprim = NULL;

    // define the local list for o_auth_client_exception->stack_trace
    list_t *stack_traceList = NULL;

    char *message_local_str = NULL;

    // define the local list for o_auth_client_exception->suppressed
    list_t *suppressedList = NULL;

    char *localized_message_local_str = NULL;

    // o_auth_client_exception->cause
    cJSON *cause = cJSON_GetObjectItemCaseSensitive(o_auth_client_exceptionJSON, "cause");
    if (cJSON_IsNull(cause)) {
        cause = NULL;
    }
    if (cause) { 
    cause_local_nonprim = o_auth_client_exception_cause_parseFromJSON(cause); //nonprimitive
    }

    // o_auth_client_exception->stack_trace
    cJSON *stack_trace = cJSON_GetObjectItemCaseSensitive(o_auth_client_exceptionJSON, "stackTrace");
    if (cJSON_IsNull(stack_trace)) {
        stack_trace = NULL;
    }
    if (stack_trace) { 
    cJSON *stack_trace_local_nonprimitive = NULL;
    if(!cJSON_IsArray(stack_trace)){
        goto end; //nonprimitive container
    }

    stack_traceList = list_createList();

    cJSON_ArrayForEach(stack_trace_local_nonprimitive,stack_trace )
    {
        if(!cJSON_IsObject(stack_trace_local_nonprimitive)){
            goto end;
        }
        o_auth_client_exception_cause_stack_trace_inner_t *stack_traceItem = o_auth_client_exception_cause_stack_trace_inner_parseFromJSON(stack_trace_local_nonprimitive);

        list_addElement(stack_traceList, stack_traceItem);
    }
    }

    // o_auth_client_exception->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(o_auth_client_exceptionJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // o_auth_client_exception->suppressed
    cJSON *suppressed = cJSON_GetObjectItemCaseSensitive(o_auth_client_exceptionJSON, "suppressed");
    if (cJSON_IsNull(suppressed)) {
        suppressed = NULL;
    }
    if (suppressed) { 
    cJSON *suppressed_local_nonprimitive = NULL;
    if(!cJSON_IsArray(suppressed)){
        goto end; //nonprimitive container
    }

    suppressedList = list_createList();

    cJSON_ArrayForEach(suppressed_local_nonprimitive,suppressed )
    {
        if(!cJSON_IsObject(suppressed_local_nonprimitive)){
            goto end;
        }
        o_auth_client_exception_cause_t *suppressedItem = o_auth_client_exception_cause_parseFromJSON(suppressed_local_nonprimitive);

        list_addElement(suppressedList, suppressedItem);
    }
    }

    // o_auth_client_exception->localized_message
    cJSON *localized_message = cJSON_GetObjectItemCaseSensitive(o_auth_client_exceptionJSON, "localizedMessage");
    if (cJSON_IsNull(localized_message)) {
        localized_message = NULL;
    }
    if (localized_message) { 
    if(!cJSON_IsString(localized_message) && !cJSON_IsNull(localized_message))
    {
    goto end; //String
    }
    }


    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (localized_message && !cJSON_IsNull(localized_message)) localized_message_local_str = strdup(localized_message->valuestring);

    o_auth_client_exception_local_var = o_auth_client_exception_create_internal (
        cause ? cause_local_nonprim : NULL,
        stack_trace ? stack_traceList : NULL,
        message_local_str,
        suppressed ? suppressedList : NULL,
        localized_message_local_str
        );

    if (!o_auth_client_exception_local_var) {
        goto end;
    }

    return o_auth_client_exception_local_var;
end:
    if (cause_local_nonprim) {
        o_auth_client_exception_cause_free(cause_local_nonprim);
        cause_local_nonprim = NULL;
    }
    if (stack_traceList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stack_traceList) {
            o_auth_client_exception_cause_stack_trace_inner_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stack_traceList);
        stack_traceList = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (suppressedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, suppressedList) {
            o_auth_client_exception_cause_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(suppressedList);
        suppressedList = NULL;
    }
    if (localized_message_local_str) {
        free(localized_message_local_str);
        localized_message_local_str = NULL;
    }
    return NULL;

}
