#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "option_strike_data.h"



static option_strike_data_t *option_strike_data_create_internal(
    char *expiry,
    double *pcr,
    double *strike_price,
    char *underlying_key,
    double *underlying_spot_price,
    put_call_option_chain_data_t *call_options,
    put_call_option_chain_data_t *put_options
    ) {
    option_strike_data_t *option_strike_data_local_var = malloc(sizeof(option_strike_data_t));
    if (!option_strike_data_local_var) {
        return NULL;
    }
    memset(option_strike_data_local_var, 0, sizeof(option_strike_data_t));
    option_strike_data_local_var->_library_owned = 1;
    option_strike_data_local_var->expiry = expiry;
    option_strike_data_local_var->pcr = pcr;
    option_strike_data_local_var->strike_price = strike_price;
    option_strike_data_local_var->underlying_key = underlying_key;
    option_strike_data_local_var->underlying_spot_price = underlying_spot_price;
    option_strike_data_local_var->call_options = call_options;
    option_strike_data_local_var->put_options = put_options;
    return option_strike_data_local_var;
}

option_strike_data_t *option_strike_data_create(
    char *expiry,
    double *pcr,
    double *strike_price,
    char *underlying_key,
    double *underlying_spot_price,
    put_call_option_chain_data_t *call_options,
    put_call_option_chain_data_t *put_options
    ) {
    double *pcr_copy = NULL;
    if (pcr) {
        pcr_copy = malloc(sizeof(double));
        if (pcr_copy) *pcr_copy = *pcr;
    }
    double *strike_price_copy = NULL;
    if (strike_price) {
        strike_price_copy = malloc(sizeof(double));
        if (strike_price_copy) *strike_price_copy = *strike_price;
    }
    double *underlying_spot_price_copy = NULL;
    if (underlying_spot_price) {
        underlying_spot_price_copy = malloc(sizeof(double));
        if (underlying_spot_price_copy) *underlying_spot_price_copy = *underlying_spot_price;
    }
    option_strike_data_t *result = option_strike_data_create_internal (
        expiry,
        pcr_copy,
        strike_price_copy,
        underlying_key,
        underlying_spot_price_copy,
        call_options,
        put_options
        );
    if (!result) {
        free(pcr_copy);
        free(strike_price_copy);
        free(underlying_spot_price_copy);
    }
    return result;
}

void option_strike_data_free(option_strike_data_t *option_strike_data) {
    if(NULL == option_strike_data){
        return ;
    }
    if(option_strike_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "option_strike_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (option_strike_data->expiry) {
        free(option_strike_data->expiry);
        option_strike_data->expiry = NULL;
    }
    if (option_strike_data->pcr) {
        free(option_strike_data->pcr);
        option_strike_data->pcr = NULL;
    }
    if (option_strike_data->strike_price) {
        free(option_strike_data->strike_price);
        option_strike_data->strike_price = NULL;
    }
    if (option_strike_data->underlying_key) {
        free(option_strike_data->underlying_key);
        option_strike_data->underlying_key = NULL;
    }
    if (option_strike_data->underlying_spot_price) {
        free(option_strike_data->underlying_spot_price);
        option_strike_data->underlying_spot_price = NULL;
    }
    if (option_strike_data->call_options) {
        put_call_option_chain_data_free(option_strike_data->call_options);
        option_strike_data->call_options = NULL;
    }
    if (option_strike_data->put_options) {
        put_call_option_chain_data_free(option_strike_data->put_options);
        option_strike_data->put_options = NULL;
    }
    free(option_strike_data);
}

cJSON *option_strike_data_convertToJSON(option_strike_data_t *option_strike_data) {
    cJSON *item = cJSON_CreateObject();

    // option_strike_data->expiry
    if(option_strike_data->expiry) {
    if(cJSON_AddStringToObject(item, "expiry", option_strike_data->expiry) == NULL) {
    goto fail; //Date-Time
    }
    }


    // option_strike_data->pcr
    if(option_strike_data->pcr) {
    if(cJSON_AddNumberToObject(item, "pcr", *option_strike_data->pcr) == NULL) {
    goto fail; //Numeric
    }
    }


    // option_strike_data->strike_price
    if(option_strike_data->strike_price) {
    if(cJSON_AddNumberToObject(item, "strike_price", *option_strike_data->strike_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // option_strike_data->underlying_key
    if(option_strike_data->underlying_key) {
    if(cJSON_AddStringToObject(item, "underlying_key", option_strike_data->underlying_key) == NULL) {
    goto fail; //String
    }
    }


    // option_strike_data->underlying_spot_price
    if(option_strike_data->underlying_spot_price) {
    if(cJSON_AddNumberToObject(item, "underlying_spot_price", *option_strike_data->underlying_spot_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // option_strike_data->call_options
    if(option_strike_data->call_options) {
    cJSON *call_options_local_JSON = put_call_option_chain_data_convertToJSON(option_strike_data->call_options);
    if(call_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "call_options", call_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // option_strike_data->put_options
    if(option_strike_data->put_options) {
    cJSON *put_options_local_JSON = put_call_option_chain_data_convertToJSON(option_strike_data->put_options);
    if(put_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "put_options", put_options_local_JSON);
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

option_strike_data_t *option_strike_data_parseFromJSON(cJSON *option_strike_dataJSON){

    option_strike_data_t *option_strike_data_local_var = NULL;

    char *expiry_local_str = NULL;

    // define the local variable for option_strike_data->pcr
    double *pcr_local_var = NULL;

    // define the local variable for option_strike_data->strike_price
    double *strike_price_local_var = NULL;

    char *underlying_key_local_str = NULL;

    // define the local variable for option_strike_data->underlying_spot_price
    double *underlying_spot_price_local_var = NULL;

    // define the local variable for option_strike_data->call_options
    put_call_option_chain_data_t *call_options_local_nonprim = NULL;

    // define the local variable for option_strike_data->put_options
    put_call_option_chain_data_t *put_options_local_nonprim = NULL;

    // option_strike_data->expiry
    cJSON *expiry = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "expiry");
    if (cJSON_IsNull(expiry)) {
        expiry = NULL;
    }
    if (expiry) { 
    if(!cJSON_IsString(expiry) && !cJSON_IsNull(expiry))
    {
    goto end; //DateTime
    }
    }

    // option_strike_data->pcr
    cJSON *pcr = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "pcr");
    if (cJSON_IsNull(pcr)) {
        pcr = NULL;
    }
    if (pcr) { 
    if(!cJSON_IsNumber(pcr))
    {
    goto end; //Numeric
    }
    pcr_local_var = malloc(sizeof(double));
    if(!pcr_local_var)
    {
        goto end;
    }
    *pcr_local_var = pcr->valuedouble;
    }

    // option_strike_data->strike_price
    cJSON *strike_price = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "strike_price");
    if (cJSON_IsNull(strike_price)) {
        strike_price = NULL;
    }
    if (strike_price) { 
    if(!cJSON_IsNumber(strike_price))
    {
    goto end; //Numeric
    }
    strike_price_local_var = malloc(sizeof(double));
    if(!strike_price_local_var)
    {
        goto end;
    }
    *strike_price_local_var = strike_price->valuedouble;
    }

    // option_strike_data->underlying_key
    cJSON *underlying_key = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "underlying_key");
    if (cJSON_IsNull(underlying_key)) {
        underlying_key = NULL;
    }
    if (underlying_key) { 
    if(!cJSON_IsString(underlying_key) && !cJSON_IsNull(underlying_key))
    {
    goto end; //String
    }
    }

    // option_strike_data->underlying_spot_price
    cJSON *underlying_spot_price = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "underlying_spot_price");
    if (cJSON_IsNull(underlying_spot_price)) {
        underlying_spot_price = NULL;
    }
    if (underlying_spot_price) { 
    if(!cJSON_IsNumber(underlying_spot_price))
    {
    goto end; //Numeric
    }
    underlying_spot_price_local_var = malloc(sizeof(double));
    if(!underlying_spot_price_local_var)
    {
        goto end;
    }
    *underlying_spot_price_local_var = underlying_spot_price->valuedouble;
    }

    // option_strike_data->call_options
    cJSON *call_options = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "call_options");
    if (cJSON_IsNull(call_options)) {
        call_options = NULL;
    }
    if (call_options) { 
    call_options_local_nonprim = put_call_option_chain_data_parseFromJSON(call_options); //nonprimitive
    }

    // option_strike_data->put_options
    cJSON *put_options = cJSON_GetObjectItemCaseSensitive(option_strike_dataJSON, "put_options");
    if (cJSON_IsNull(put_options)) {
        put_options = NULL;
    }
    if (put_options) { 
    put_options_local_nonprim = put_call_option_chain_data_parseFromJSON(put_options); //nonprimitive
    }


    if (expiry && !cJSON_IsNull(expiry)) expiry_local_str = strdup(expiry->valuestring);
    if (underlying_key && !cJSON_IsNull(underlying_key)) underlying_key_local_str = strdup(underlying_key->valuestring);

    option_strike_data_local_var = option_strike_data_create_internal (
        expiry_local_str,
        pcr_local_var,
        strike_price_local_var,
        underlying_key_local_str,
        underlying_spot_price_local_var,
        call_options ? call_options_local_nonprim : NULL,
        put_options ? put_options_local_nonprim : NULL
        );

    if (!option_strike_data_local_var) {
        goto end;
    }

    return option_strike_data_local_var;
end:
    if (expiry_local_str) {
        free(expiry_local_str);
        expiry_local_str = NULL;
    }
    if (pcr_local_var) {
        free(pcr_local_var);
        pcr_local_var = NULL;
    }
    if (strike_price_local_var) {
        free(strike_price_local_var);
        strike_price_local_var = NULL;
    }
    if (underlying_key_local_str) {
        free(underlying_key_local_str);
        underlying_key_local_str = NULL;
    }
    if (underlying_spot_price_local_var) {
        free(underlying_spot_price_local_var);
        underlying_spot_price_local_var = NULL;
    }
    if (call_options_local_nonprim) {
        put_call_option_chain_data_free(call_options_local_nonprim);
        call_options_local_nonprim = NULL;
    }
    if (put_options_local_nonprim) {
        put_call_option_chain_data_free(put_options_local_nonprim);
        put_options_local_nonprim = NULL;
    }
    return NULL;

}
