#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_ohlcv3.h"



static market_quote_ohlcv3_t *market_quote_ohlcv3_create_internal(
    double *last_price,
    char *instrument_token,
    ohlc_v3_t *prev_ohlc,
    ohlc_v3_t *live_ohlc
    ) {
    market_quote_ohlcv3_t *market_quote_ohlcv3_local_var = malloc(sizeof(market_quote_ohlcv3_t));
    if (!market_quote_ohlcv3_local_var) {
        return NULL;
    }
    memset(market_quote_ohlcv3_local_var, 0, sizeof(market_quote_ohlcv3_t));
    market_quote_ohlcv3_local_var->_library_owned = 1;
    market_quote_ohlcv3_local_var->last_price = last_price;
    market_quote_ohlcv3_local_var->instrument_token = instrument_token;
    market_quote_ohlcv3_local_var->prev_ohlc = prev_ohlc;
    market_quote_ohlcv3_local_var->live_ohlc = live_ohlc;
    return market_quote_ohlcv3_local_var;
}

market_quote_ohlcv3_t *market_quote_ohlcv3_create(
    double *last_price,
    char *instrument_token,
    ohlc_v3_t *prev_ohlc,
    ohlc_v3_t *live_ohlc
    ) {
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    market_quote_ohlcv3_t *result = market_quote_ohlcv3_create_internal (
        last_price_copy,
        instrument_token,
        prev_ohlc,
        live_ohlc
        );
    if (!result) {
        free(last_price_copy);
    }
    return result;
}

void market_quote_ohlcv3_free(market_quote_ohlcv3_t *market_quote_ohlcv3) {
    if(NULL == market_quote_ohlcv3){
        return ;
    }
    if(market_quote_ohlcv3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_ohlcv3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_ohlcv3->last_price) {
        free(market_quote_ohlcv3->last_price);
        market_quote_ohlcv3->last_price = NULL;
    }
    if (market_quote_ohlcv3->instrument_token) {
        free(market_quote_ohlcv3->instrument_token);
        market_quote_ohlcv3->instrument_token = NULL;
    }
    if (market_quote_ohlcv3->prev_ohlc) {
        ohlc_v3_free(market_quote_ohlcv3->prev_ohlc);
        market_quote_ohlcv3->prev_ohlc = NULL;
    }
    if (market_quote_ohlcv3->live_ohlc) {
        ohlc_v3_free(market_quote_ohlcv3->live_ohlc);
        market_quote_ohlcv3->live_ohlc = NULL;
    }
    free(market_quote_ohlcv3);
}

cJSON *market_quote_ohlcv3_convertToJSON(market_quote_ohlcv3_t *market_quote_ohlcv3) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_ohlcv3->last_price
    if(market_quote_ohlcv3->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_ohlcv3->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_ohlcv3->instrument_token
    if(market_quote_ohlcv3->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_ohlcv3->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_ohlcv3->prev_ohlc
    if(market_quote_ohlcv3->prev_ohlc) {
    cJSON *prev_ohlc_local_JSON = ohlc_v3_convertToJSON(market_quote_ohlcv3->prev_ohlc);
    if(prev_ohlc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "prev_ohlc", prev_ohlc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_ohlcv3->live_ohlc
    if(market_quote_ohlcv3->live_ohlc) {
    cJSON *live_ohlc_local_JSON = ohlc_v3_convertToJSON(market_quote_ohlcv3->live_ohlc);
    if(live_ohlc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "live_ohlc", live_ohlc_local_JSON);
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

market_quote_ohlcv3_t *market_quote_ohlcv3_parseFromJSON(cJSON *market_quote_ohlcv3JSON){

    market_quote_ohlcv3_t *market_quote_ohlcv3_local_var = NULL;

    // define the local variable for market_quote_ohlcv3->last_price
    double *last_price_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for market_quote_ohlcv3->prev_ohlc
    ohlc_v3_t *prev_ohlc_local_nonprim = NULL;

    // define the local variable for market_quote_ohlcv3->live_ohlc
    ohlc_v3_t *live_ohlc_local_nonprim = NULL;

    // market_quote_ohlcv3->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcv3JSON, "last_price");
    if (cJSON_IsNull(last_price)) {
        last_price = NULL;
    }
    if (last_price) { 
    if(!cJSON_IsNumber(last_price))
    {
    goto end; //Numeric
    }
    last_price_local_var = malloc(sizeof(double));
    if(!last_price_local_var)
    {
        goto end;
    }
    *last_price_local_var = last_price->valuedouble;
    }

    // market_quote_ohlcv3->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcv3JSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // market_quote_ohlcv3->prev_ohlc
    cJSON *prev_ohlc = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcv3JSON, "prev_ohlc");
    if (cJSON_IsNull(prev_ohlc)) {
        prev_ohlc = NULL;
    }
    if (prev_ohlc) { 
    prev_ohlc_local_nonprim = ohlc_v3_parseFromJSON(prev_ohlc); //nonprimitive
    }

    // market_quote_ohlcv3->live_ohlc
    cJSON *live_ohlc = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcv3JSON, "live_ohlc");
    if (cJSON_IsNull(live_ohlc)) {
        live_ohlc = NULL;
    }
    if (live_ohlc) { 
    live_ohlc_local_nonprim = ohlc_v3_parseFromJSON(live_ohlc); //nonprimitive
    }


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    market_quote_ohlcv3_local_var = market_quote_ohlcv3_create_internal (
        last_price_local_var,
        instrument_token_local_str,
        prev_ohlc ? prev_ohlc_local_nonprim : NULL,
        live_ohlc ? live_ohlc_local_nonprim : NULL
        );

    if (!market_quote_ohlcv3_local_var) {
        goto end;
    }

    return market_quote_ohlcv3_local_var;
end:
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (prev_ohlc_local_nonprim) {
        ohlc_v3_free(prev_ohlc_local_nonprim);
        prev_ohlc_local_nonprim = NULL;
    }
    if (live_ohlc_local_nonprim) {
        ohlc_v3_free(live_ohlc_local_nonprim);
        live_ohlc_local_nonprim = NULL;
    }
    return NULL;

}
