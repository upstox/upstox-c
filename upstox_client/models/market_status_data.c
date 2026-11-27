#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_status_data.h"



static market_status_data_t *market_status_data_create_internal(
    char *exchange,
    char *status,
    long *last_updated,
    cas_eligible_status_data_t *cas_eligible_status
    ) {
    market_status_data_t *market_status_data_local_var = malloc(sizeof(market_status_data_t));
    if (!market_status_data_local_var) {
        return NULL;
    }
    memset(market_status_data_local_var, 0, sizeof(market_status_data_t));
    market_status_data_local_var->_library_owned = 1;
    market_status_data_local_var->exchange = exchange;
    market_status_data_local_var->status = status;
    market_status_data_local_var->last_updated = last_updated;
    market_status_data_local_var->cas_eligible_status = cas_eligible_status;
    return market_status_data_local_var;
}

market_status_data_t *market_status_data_create(
    char *exchange,
    char *status,
    long *last_updated,
    cas_eligible_status_data_t *cas_eligible_status
    ) {
    long *last_updated_copy = NULL;
    if (last_updated) {
        last_updated_copy = malloc(sizeof(long));
        if (last_updated_copy) *last_updated_copy = *last_updated;
    }
    market_status_data_t *result = market_status_data_create_internal (
        exchange,
        status,
        last_updated_copy,
        cas_eligible_status
        );
    if (!result) {
        free(last_updated_copy);
    }
    return result;
}

void market_status_data_free(market_status_data_t *market_status_data) {
    if(NULL == market_status_data){
        return ;
    }
    if(market_status_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_status_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_status_data->exchange) {
        free(market_status_data->exchange);
        market_status_data->exchange = NULL;
    }
    if (market_status_data->status) {
        free(market_status_data->status);
        market_status_data->status = NULL;
    }
    if (market_status_data->last_updated) {
        free(market_status_data->last_updated);
        market_status_data->last_updated = NULL;
    }
    if (market_status_data->cas_eligible_status) {
        cas_eligible_status_data_free(market_status_data->cas_eligible_status);
        market_status_data->cas_eligible_status = NULL;
    }
    free(market_status_data);
}

cJSON *market_status_data_convertToJSON(market_status_data_t *market_status_data) {
    cJSON *item = cJSON_CreateObject();

    // market_status_data->exchange
    if(market_status_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", market_status_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // market_status_data->status
    if(market_status_data->status) {
    if(cJSON_AddStringToObject(item, "status", market_status_data->status) == NULL) {
    goto fail; //String
    }
    }


    // market_status_data->last_updated
    if(market_status_data->last_updated) {
    if(cJSON_AddNumberToObject(item, "last_updated", *market_status_data->last_updated) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_status_data->cas_eligible_status
    if(market_status_data->cas_eligible_status) {
    cJSON *cas_eligible_status_local_JSON = cas_eligible_status_data_convertToJSON(market_status_data->cas_eligible_status);
    if(cas_eligible_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cas_eligible_status", cas_eligible_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

market_status_data_t *market_status_data_parseFromJSON(cJSON *market_status_dataJSON){

    market_status_data_t *market_status_data_local_var = NULL;

    char *exchange_local_str = NULL;

    char *status_local_str = NULL;

    // define the local variable for market_status_data->last_updated
    long *last_updated_local_var = NULL;

    // define the local variable for market_status_data->cas_eligible_status
    cas_eligible_status_data_t *cas_eligible_status_local_nonprim = NULL;

    // market_status_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(market_status_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // market_status_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(market_status_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // market_status_data->last_updated
    cJSON *last_updated = cJSON_GetObjectItemCaseSensitive(market_status_dataJSON, "last_updated");
    if (cJSON_IsNull(last_updated)) {
        last_updated = NULL;
    }
    if (last_updated) { 
    if(!cJSON_IsNumber(last_updated))
    {
    goto end; //Numeric
    }
    last_updated_local_var = malloc(sizeof(long));
    if(!last_updated_local_var)
    {
        goto end;
    }
    *last_updated_local_var = last_updated->valuedouble;
    }

    // market_status_data->cas_eligible_status
    cJSON *cas_eligible_status = cJSON_GetObjectItemCaseSensitive(market_status_dataJSON, "cas_eligible_status");
    if (cJSON_IsNull(cas_eligible_status)) {
        cas_eligible_status = NULL;
    }
    if (cas_eligible_status) { 
    cas_eligible_status_local_nonprim = cas_eligible_status_data_parseFromJSON(cas_eligible_status); //nonprimitive
    }


    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);

    market_status_data_local_var = market_status_data_create_internal (
        exchange_local_str,
        status_local_str,
        last_updated_local_var,
        cas_eligible_status ? cas_eligible_status_local_nonprim : NULL
        );

    if (!market_status_data_local_var) {
        goto end;
    }

    return market_status_data_local_var;
end:
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (last_updated_local_var) {
        free(last_updated_local_var);
        last_updated_local_var = NULL;
    }
    if (cas_eligible_status_local_nonprim) {
        cas_eligible_status_data_free(cas_eligible_status_local_nonprim);
        cas_eligible_status_local_nonprim = NULL;
    }
    return NULL;

}
