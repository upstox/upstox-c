#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "exchange_timing_data.h"



static exchange_timing_data_t *exchange_timing_data_create_internal(
    char *exchange,
    long *start_time,
    long *end_time
    ) {
    exchange_timing_data_t *exchange_timing_data_local_var = malloc(sizeof(exchange_timing_data_t));
    if (!exchange_timing_data_local_var) {
        return NULL;
    }
    memset(exchange_timing_data_local_var, 0, sizeof(exchange_timing_data_t));
    exchange_timing_data_local_var->_library_owned = 1;
    exchange_timing_data_local_var->exchange = exchange;
    exchange_timing_data_local_var->start_time = start_time;
    exchange_timing_data_local_var->end_time = end_time;
    return exchange_timing_data_local_var;
}

exchange_timing_data_t *exchange_timing_data_create(
    char *exchange,
    long *start_time,
    long *end_time
    ) {
    long *start_time_copy = NULL;
    if (start_time) {
        start_time_copy = malloc(sizeof(long));
        if (start_time_copy) *start_time_copy = *start_time;
    }
    long *end_time_copy = NULL;
    if (end_time) {
        end_time_copy = malloc(sizeof(long));
        if (end_time_copy) *end_time_copy = *end_time;
    }
    exchange_timing_data_t *result = exchange_timing_data_create_internal (
        exchange,
        start_time_copy,
        end_time_copy
        );
    if (!result) {
        free(start_time_copy);
        free(end_time_copy);
    }
    return result;
}

void exchange_timing_data_free(exchange_timing_data_t *exchange_timing_data) {
    if(NULL == exchange_timing_data){
        return ;
    }
    if(exchange_timing_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "exchange_timing_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (exchange_timing_data->exchange) {
        free(exchange_timing_data->exchange);
        exchange_timing_data->exchange = NULL;
    }
    if (exchange_timing_data->start_time) {
        free(exchange_timing_data->start_time);
        exchange_timing_data->start_time = NULL;
    }
    if (exchange_timing_data->end_time) {
        free(exchange_timing_data->end_time);
        exchange_timing_data->end_time = NULL;
    }
    free(exchange_timing_data);
}

cJSON *exchange_timing_data_convertToJSON(exchange_timing_data_t *exchange_timing_data) {
    cJSON *item = cJSON_CreateObject();

    // exchange_timing_data->exchange
    if(exchange_timing_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", exchange_timing_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // exchange_timing_data->start_time
    if(exchange_timing_data->start_time) {
    if(cJSON_AddNumberToObject(item, "start_time", *exchange_timing_data->start_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // exchange_timing_data->end_time
    if(exchange_timing_data->end_time) {
    if(cJSON_AddNumberToObject(item, "end_time", *exchange_timing_data->end_time) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

exchange_timing_data_t *exchange_timing_data_parseFromJSON(cJSON *exchange_timing_dataJSON){

    exchange_timing_data_t *exchange_timing_data_local_var = NULL;

    char *exchange_local_str = NULL;

    // define the local variable for exchange_timing_data->start_time
    long *start_time_local_var = NULL;

    // define the local variable for exchange_timing_data->end_time
    long *end_time_local_var = NULL;

    // exchange_timing_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(exchange_timing_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // exchange_timing_data->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(exchange_timing_dataJSON, "start_time");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsNumber(start_time))
    {
    goto end; //Numeric
    }
    start_time_local_var = malloc(sizeof(long));
    if(!start_time_local_var)
    {
        goto end;
    }
    *start_time_local_var = start_time->valuedouble;
    }

    // exchange_timing_data->end_time
    cJSON *end_time = cJSON_GetObjectItemCaseSensitive(exchange_timing_dataJSON, "end_time");
    if (cJSON_IsNull(end_time)) {
        end_time = NULL;
    }
    if (end_time) { 
    if(!cJSON_IsNumber(end_time))
    {
    goto end; //Numeric
    }
    end_time_local_var = malloc(sizeof(long));
    if(!end_time_local_var)
    {
        goto end;
    }
    *end_time_local_var = end_time->valuedouble;
    }


    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);

    exchange_timing_data_local_var = exchange_timing_data_create_internal (
        exchange_local_str,
        start_time_local_var,
        end_time_local_var
        );

    if (!exchange_timing_data_local_var) {
        goto end;
    }

    return exchange_timing_data_local_var;
end:
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (start_time_local_var) {
        free(start_time_local_var);
        start_time_local_var = NULL;
    }
    if (end_time_local_var) {
        free(end_time_local_var);
        end_time_local_var = NULL;
    }
    return NULL;

}
