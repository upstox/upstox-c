#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_exchange_timing_data.h"



static us_exchange_timing_data_t *us_exchange_timing_data_create_internal(
    char *exchange,
    long *start_time,
    long *end_time,
    long *overnight_start_time,
    long *overnight_end_time
    ) {
    us_exchange_timing_data_t *us_exchange_timing_data_local_var = malloc(sizeof(us_exchange_timing_data_t));
    if (!us_exchange_timing_data_local_var) {
        return NULL;
    }
    memset(us_exchange_timing_data_local_var, 0, sizeof(us_exchange_timing_data_t));
    us_exchange_timing_data_local_var->_library_owned = 1;
    us_exchange_timing_data_local_var->exchange = exchange;
    us_exchange_timing_data_local_var->start_time = start_time;
    us_exchange_timing_data_local_var->end_time = end_time;
    us_exchange_timing_data_local_var->overnight_start_time = overnight_start_time;
    us_exchange_timing_data_local_var->overnight_end_time = overnight_end_time;
    return us_exchange_timing_data_local_var;
}

us_exchange_timing_data_t *us_exchange_timing_data_create(
    char *exchange,
    long *start_time,
    long *end_time,
    long *overnight_start_time,
    long *overnight_end_time
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
    long *overnight_start_time_copy = NULL;
    if (overnight_start_time) {
        overnight_start_time_copy = malloc(sizeof(long));
        if (overnight_start_time_copy) *overnight_start_time_copy = *overnight_start_time;
    }
    long *overnight_end_time_copy = NULL;
    if (overnight_end_time) {
        overnight_end_time_copy = malloc(sizeof(long));
        if (overnight_end_time_copy) *overnight_end_time_copy = *overnight_end_time;
    }
    us_exchange_timing_data_t *result = us_exchange_timing_data_create_internal (
        exchange,
        start_time_copy,
        end_time_copy,
        overnight_start_time_copy,
        overnight_end_time_copy
        );
    if (!result) {
        free(start_time_copy);
        free(end_time_copy);
        free(overnight_start_time_copy);
        free(overnight_end_time_copy);
    }
    return result;
}

void us_exchange_timing_data_free(us_exchange_timing_data_t *us_exchange_timing_data) {
    if(NULL == us_exchange_timing_data){
        return ;
    }
    if(us_exchange_timing_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_exchange_timing_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_exchange_timing_data->exchange) {
        free(us_exchange_timing_data->exchange);
        us_exchange_timing_data->exchange = NULL;
    }
    if (us_exchange_timing_data->start_time) {
        free(us_exchange_timing_data->start_time);
        us_exchange_timing_data->start_time = NULL;
    }
    if (us_exchange_timing_data->end_time) {
        free(us_exchange_timing_data->end_time);
        us_exchange_timing_data->end_time = NULL;
    }
    if (us_exchange_timing_data->overnight_start_time) {
        free(us_exchange_timing_data->overnight_start_time);
        us_exchange_timing_data->overnight_start_time = NULL;
    }
    if (us_exchange_timing_data->overnight_end_time) {
        free(us_exchange_timing_data->overnight_end_time);
        us_exchange_timing_data->overnight_end_time = NULL;
    }
    free(us_exchange_timing_data);
}

cJSON *us_exchange_timing_data_convertToJSON(us_exchange_timing_data_t *us_exchange_timing_data) {
    cJSON *item = cJSON_CreateObject();

    // us_exchange_timing_data->exchange
    if(us_exchange_timing_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", us_exchange_timing_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // us_exchange_timing_data->start_time
    if(us_exchange_timing_data->start_time) {
    if(cJSON_AddNumberToObject(item, "start_time", *us_exchange_timing_data->start_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_exchange_timing_data->end_time
    if(us_exchange_timing_data->end_time) {
    if(cJSON_AddNumberToObject(item, "end_time", *us_exchange_timing_data->end_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_exchange_timing_data->overnight_start_time
    if(us_exchange_timing_data->overnight_start_time) {
    if(cJSON_AddNumberToObject(item, "overnight_start_time", *us_exchange_timing_data->overnight_start_time) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_exchange_timing_data->overnight_end_time
    if(us_exchange_timing_data->overnight_end_time) {
    if(cJSON_AddNumberToObject(item, "overnight_end_time", *us_exchange_timing_data->overnight_end_time) == NULL) {
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

us_exchange_timing_data_t *us_exchange_timing_data_parseFromJSON(cJSON *us_exchange_timing_dataJSON){

    us_exchange_timing_data_t *us_exchange_timing_data_local_var = NULL;

    char *exchange_local_str = NULL;

    // define the local variable for us_exchange_timing_data->start_time
    long *start_time_local_var = NULL;

    // define the local variable for us_exchange_timing_data->end_time
    long *end_time_local_var = NULL;

    // define the local variable for us_exchange_timing_data->overnight_start_time
    long *overnight_start_time_local_var = NULL;

    // define the local variable for us_exchange_timing_data->overnight_end_time
    long *overnight_end_time_local_var = NULL;

    // us_exchange_timing_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(us_exchange_timing_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // us_exchange_timing_data->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(us_exchange_timing_dataJSON, "start_time");
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

    // us_exchange_timing_data->end_time
    cJSON *end_time = cJSON_GetObjectItemCaseSensitive(us_exchange_timing_dataJSON, "end_time");
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

    // us_exchange_timing_data->overnight_start_time
    cJSON *overnight_start_time = cJSON_GetObjectItemCaseSensitive(us_exchange_timing_dataJSON, "overnight_start_time");
    if (cJSON_IsNull(overnight_start_time)) {
        overnight_start_time = NULL;
    }
    if (overnight_start_time) { 
    if(!cJSON_IsNumber(overnight_start_time))
    {
    goto end; //Numeric
    }
    overnight_start_time_local_var = malloc(sizeof(long));
    if(!overnight_start_time_local_var)
    {
        goto end;
    }
    *overnight_start_time_local_var = overnight_start_time->valuedouble;
    }

    // us_exchange_timing_data->overnight_end_time
    cJSON *overnight_end_time = cJSON_GetObjectItemCaseSensitive(us_exchange_timing_dataJSON, "overnight_end_time");
    if (cJSON_IsNull(overnight_end_time)) {
        overnight_end_time = NULL;
    }
    if (overnight_end_time) { 
    if(!cJSON_IsNumber(overnight_end_time))
    {
    goto end; //Numeric
    }
    overnight_end_time_local_var = malloc(sizeof(long));
    if(!overnight_end_time_local_var)
    {
        goto end;
    }
    *overnight_end_time_local_var = overnight_end_time->valuedouble;
    }


    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);

    us_exchange_timing_data_local_var = us_exchange_timing_data_create_internal (
        exchange_local_str,
        start_time_local_var,
        end_time_local_var,
        overnight_start_time_local_var,
        overnight_end_time_local_var
        );

    if (!us_exchange_timing_data_local_var) {
        goto end;
    }

    return us_exchange_timing_data_local_var;
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
    if (overnight_start_time_local_var) {
        free(overnight_start_time_local_var);
        overnight_start_time_local_var = NULL;
    }
    if (overnight_end_time_local_var) {
        free(overnight_end_time_local_var);
        overnight_end_time_local_var = NULL;
    }
    return NULL;

}
