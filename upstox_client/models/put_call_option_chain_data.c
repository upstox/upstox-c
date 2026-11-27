#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "put_call_option_chain_data.h"



static put_call_option_chain_data_t *put_call_option_chain_data_create_internal(
    char *instrument_key,
    market_data_t *market_data,
    analytics_data_t *option_greeks
    ) {
    put_call_option_chain_data_t *put_call_option_chain_data_local_var = malloc(sizeof(put_call_option_chain_data_t));
    if (!put_call_option_chain_data_local_var) {
        return NULL;
    }
    memset(put_call_option_chain_data_local_var, 0, sizeof(put_call_option_chain_data_t));
    put_call_option_chain_data_local_var->_library_owned = 1;
    put_call_option_chain_data_local_var->instrument_key = instrument_key;
    put_call_option_chain_data_local_var->market_data = market_data;
    put_call_option_chain_data_local_var->option_greeks = option_greeks;
    return put_call_option_chain_data_local_var;
}

put_call_option_chain_data_t *put_call_option_chain_data_create(
    char *instrument_key,
    market_data_t *market_data,
    analytics_data_t *option_greeks
    ) {
    put_call_option_chain_data_t *result = put_call_option_chain_data_create_internal (
        instrument_key,
        market_data,
        option_greeks
        );
    if (!result) {
    }
    return result;
}

void put_call_option_chain_data_free(put_call_option_chain_data_t *put_call_option_chain_data) {
    if(NULL == put_call_option_chain_data){
        return ;
    }
    if(put_call_option_chain_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "put_call_option_chain_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (put_call_option_chain_data->instrument_key) {
        free(put_call_option_chain_data->instrument_key);
        put_call_option_chain_data->instrument_key = NULL;
    }
    if (put_call_option_chain_data->market_data) {
        market_data_free(put_call_option_chain_data->market_data);
        put_call_option_chain_data->market_data = NULL;
    }
    if (put_call_option_chain_data->option_greeks) {
        analytics_data_free(put_call_option_chain_data->option_greeks);
        put_call_option_chain_data->option_greeks = NULL;
    }
    free(put_call_option_chain_data);
}

cJSON *put_call_option_chain_data_convertToJSON(put_call_option_chain_data_t *put_call_option_chain_data) {
    cJSON *item = cJSON_CreateObject();

    // put_call_option_chain_data->instrument_key
    if(put_call_option_chain_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", put_call_option_chain_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // put_call_option_chain_data->market_data
    if(put_call_option_chain_data->market_data) {
    cJSON *market_data_local_JSON = market_data_convertToJSON(put_call_option_chain_data->market_data);
    if(market_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "market_data", market_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // put_call_option_chain_data->option_greeks
    if(put_call_option_chain_data->option_greeks) {
    cJSON *option_greeks_local_JSON = analytics_data_convertToJSON(put_call_option_chain_data->option_greeks);
    if(option_greeks_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "option_greeks", option_greeks_local_JSON);
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

put_call_option_chain_data_t *put_call_option_chain_data_parseFromJSON(cJSON *put_call_option_chain_dataJSON){

    put_call_option_chain_data_t *put_call_option_chain_data_local_var = NULL;

    char *instrument_key_local_str = NULL;

    // define the local variable for put_call_option_chain_data->market_data
    market_data_t *market_data_local_nonprim = NULL;

    // define the local variable for put_call_option_chain_data->option_greeks
    analytics_data_t *option_greeks_local_nonprim = NULL;

    // put_call_option_chain_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(put_call_option_chain_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // put_call_option_chain_data->market_data
    cJSON *market_data = cJSON_GetObjectItemCaseSensitive(put_call_option_chain_dataJSON, "market_data");
    if (cJSON_IsNull(market_data)) {
        market_data = NULL;
    }
    if (market_data) { 
    market_data_local_nonprim = market_data_parseFromJSON(market_data); //nonprimitive
    }

    // put_call_option_chain_data->option_greeks
    cJSON *option_greeks = cJSON_GetObjectItemCaseSensitive(put_call_option_chain_dataJSON, "option_greeks");
    if (cJSON_IsNull(option_greeks)) {
        option_greeks = NULL;
    }
    if (option_greeks) { 
    option_greeks_local_nonprim = analytics_data_parseFromJSON(option_greeks); //nonprimitive
    }


    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);

    put_call_option_chain_data_local_var = put_call_option_chain_data_create_internal (
        instrument_key_local_str,
        market_data ? market_data_local_nonprim : NULL,
        option_greeks ? option_greeks_local_nonprim : NULL
        );

    if (!put_call_option_chain_data_local_var) {
        goto end;
    }

    return put_call_option_chain_data_local_var;
end:
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (market_data_local_nonprim) {
        market_data_free(market_data_local_nonprim);
        market_data_local_nonprim = NULL;
    }
    if (option_greeks_local_nonprim) {
        analytics_data_free(option_greeks_local_nonprim);
        option_greeks_local_nonprim = NULL;
    }
    return NULL;

}
