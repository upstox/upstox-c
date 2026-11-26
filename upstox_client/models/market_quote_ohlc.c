#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_ohlc.h"



static market_quote_ohlc_t *market_quote_ohlc_create_internal(
    ohlc_t *ohlc,
    double *last_price,
    char *instrument_token
    ) {
    market_quote_ohlc_t *market_quote_ohlc_local_var = malloc(sizeof(market_quote_ohlc_t));
    if (!market_quote_ohlc_local_var) {
        return NULL;
    }
    memset(market_quote_ohlc_local_var, 0, sizeof(market_quote_ohlc_t));
    market_quote_ohlc_local_var->_library_owned = 1;
    market_quote_ohlc_local_var->ohlc = ohlc;
    market_quote_ohlc_local_var->last_price = last_price;
    market_quote_ohlc_local_var->instrument_token = instrument_token;
    return market_quote_ohlc_local_var;
}

market_quote_ohlc_t *market_quote_ohlc_create(
    ohlc_t *ohlc,
    double *last_price,
    char *instrument_token
    ) {
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    market_quote_ohlc_t *result = market_quote_ohlc_create_internal (
        ohlc,
        last_price_copy,
        instrument_token
        );
    if (!result) {
        free(last_price_copy);
    }
    return result;
}

void market_quote_ohlc_free(market_quote_ohlc_t *market_quote_ohlc) {
    if(NULL == market_quote_ohlc){
        return ;
    }
    if(market_quote_ohlc->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_ohlc_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_ohlc->ohlc) {
        ohlc_free(market_quote_ohlc->ohlc);
        market_quote_ohlc->ohlc = NULL;
    }
    if (market_quote_ohlc->last_price) {
        free(market_quote_ohlc->last_price);
        market_quote_ohlc->last_price = NULL;
    }
    if (market_quote_ohlc->instrument_token) {
        free(market_quote_ohlc->instrument_token);
        market_quote_ohlc->instrument_token = NULL;
    }
    free(market_quote_ohlc);
}

cJSON *market_quote_ohlc_convertToJSON(market_quote_ohlc_t *market_quote_ohlc) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_ohlc->ohlc
    if(market_quote_ohlc->ohlc) {
    cJSON *ohlc_local_JSON = ohlc_convertToJSON(market_quote_ohlc->ohlc);
    if(ohlc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ohlc", ohlc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // market_quote_ohlc->last_price
    if(market_quote_ohlc->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_ohlc->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_ohlc->instrument_token
    if(market_quote_ohlc->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_ohlc->instrument_token) == NULL) {
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

market_quote_ohlc_t *market_quote_ohlc_parseFromJSON(cJSON *market_quote_ohlcJSON){

    market_quote_ohlc_t *market_quote_ohlc_local_var = NULL;

    // define the local variable for market_quote_ohlc->ohlc
    ohlc_t *ohlc_local_nonprim = NULL;

    // define the local variable for market_quote_ohlc->last_price
    double *last_price_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // market_quote_ohlc->ohlc
    cJSON *ohlc = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcJSON, "ohlc");
    if (cJSON_IsNull(ohlc)) {
        ohlc = NULL;
    }
    if (ohlc) { 
    ohlc_local_nonprim = ohlc_parseFromJSON(ohlc); //nonprimitive
    }

    // market_quote_ohlc->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcJSON, "last_price");
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

    // market_quote_ohlc->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_ohlcJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    market_quote_ohlc_local_var = market_quote_ohlc_create_internal (
        ohlc ? ohlc_local_nonprim : NULL,
        last_price_local_var,
        instrument_token_local_str
        );

    if (!market_quote_ohlc_local_var) {
        goto end;
    }

    return market_quote_ohlc_local_var;
end:
    if (ohlc_local_nonprim) {
        ohlc_free(ohlc_local_nonprim);
        ohlc_local_nonprim = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    return NULL;

}
