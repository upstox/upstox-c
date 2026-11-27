#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_symbol_ltp_v3.h"



static market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_create_internal(
    double *last_price,
    char *instrument_token,
    long *ltq,
    long *volume,
    double *cp
    ) {
    market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_local_var = malloc(sizeof(market_quote_symbol_ltp_v3_t));
    if (!market_quote_symbol_ltp_v3_local_var) {
        return NULL;
    }
    memset(market_quote_symbol_ltp_v3_local_var, 0, sizeof(market_quote_symbol_ltp_v3_t));
    market_quote_symbol_ltp_v3_local_var->_library_owned = 1;
    market_quote_symbol_ltp_v3_local_var->last_price = last_price;
    market_quote_symbol_ltp_v3_local_var->instrument_token = instrument_token;
    market_quote_symbol_ltp_v3_local_var->ltq = ltq;
    market_quote_symbol_ltp_v3_local_var->volume = volume;
    market_quote_symbol_ltp_v3_local_var->cp = cp;
    return market_quote_symbol_ltp_v3_local_var;
}

market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_create(
    double *last_price,
    char *instrument_token,
    long *ltq,
    long *volume,
    double *cp
    ) {
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    long *ltq_copy = NULL;
    if (ltq) {
        ltq_copy = malloc(sizeof(long));
        if (ltq_copy) *ltq_copy = *ltq;
    }
    long *volume_copy = NULL;
    if (volume) {
        volume_copy = malloc(sizeof(long));
        if (volume_copy) *volume_copy = *volume;
    }
    double *cp_copy = NULL;
    if (cp) {
        cp_copy = malloc(sizeof(double));
        if (cp_copy) *cp_copy = *cp;
    }
    market_quote_symbol_ltp_v3_t *result = market_quote_symbol_ltp_v3_create_internal (
        last_price_copy,
        instrument_token,
        ltq_copy,
        volume_copy,
        cp_copy
        );
    if (!result) {
        free(last_price_copy);
        free(ltq_copy);
        free(volume_copy);
        free(cp_copy);
    }
    return result;
}

void market_quote_symbol_ltp_v3_free(market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3) {
    if(NULL == market_quote_symbol_ltp_v3){
        return ;
    }
    if(market_quote_symbol_ltp_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_symbol_ltp_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_symbol_ltp_v3->last_price) {
        free(market_quote_symbol_ltp_v3->last_price);
        market_quote_symbol_ltp_v3->last_price = NULL;
    }
    if (market_quote_symbol_ltp_v3->instrument_token) {
        free(market_quote_symbol_ltp_v3->instrument_token);
        market_quote_symbol_ltp_v3->instrument_token = NULL;
    }
    if (market_quote_symbol_ltp_v3->ltq) {
        free(market_quote_symbol_ltp_v3->ltq);
        market_quote_symbol_ltp_v3->ltq = NULL;
    }
    if (market_quote_symbol_ltp_v3->volume) {
        free(market_quote_symbol_ltp_v3->volume);
        market_quote_symbol_ltp_v3->volume = NULL;
    }
    if (market_quote_symbol_ltp_v3->cp) {
        free(market_quote_symbol_ltp_v3->cp);
        market_quote_symbol_ltp_v3->cp = NULL;
    }
    free(market_quote_symbol_ltp_v3);
}

cJSON *market_quote_symbol_ltp_v3_convertToJSON(market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_symbol_ltp_v3->last_price
    if(market_quote_symbol_ltp_v3->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_symbol_ltp_v3->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_ltp_v3->instrument_token
    if(market_quote_symbol_ltp_v3->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_symbol_ltp_v3->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_symbol_ltp_v3->ltq
    if(market_quote_symbol_ltp_v3->ltq) {
    if(cJSON_AddNumberToObject(item, "ltq", *market_quote_symbol_ltp_v3->ltq) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_ltp_v3->volume
    if(market_quote_symbol_ltp_v3->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *market_quote_symbol_ltp_v3->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_symbol_ltp_v3->cp
    if(market_quote_symbol_ltp_v3->cp) {
    if(cJSON_AddNumberToObject(item, "cp", *market_quote_symbol_ltp_v3->cp) == NULL) {
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

market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_parseFromJSON(cJSON *market_quote_symbol_ltp_v3JSON){

    market_quote_symbol_ltp_v3_t *market_quote_symbol_ltp_v3_local_var = NULL;

    // define the local variable for market_quote_symbol_ltp_v3->last_price
    double *last_price_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for market_quote_symbol_ltp_v3->ltq
    long *ltq_local_var = NULL;

    // define the local variable for market_quote_symbol_ltp_v3->volume
    long *volume_local_var = NULL;

    // define the local variable for market_quote_symbol_ltp_v3->cp
    double *cp_local_var = NULL;

    // market_quote_symbol_ltp_v3->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_ltp_v3JSON, "last_price");
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

    // market_quote_symbol_ltp_v3->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_ltp_v3JSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // market_quote_symbol_ltp_v3->ltq
    cJSON *ltq = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_ltp_v3JSON, "ltq");
    if (cJSON_IsNull(ltq)) {
        ltq = NULL;
    }
    if (ltq) { 
    if(!cJSON_IsNumber(ltq))
    {
    goto end; //Numeric
    }
    ltq_local_var = malloc(sizeof(long));
    if(!ltq_local_var)
    {
        goto end;
    }
    *ltq_local_var = ltq->valuedouble;
    }

    // market_quote_symbol_ltp_v3->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_ltp_v3JSON, "volume");
    if (cJSON_IsNull(volume)) {
        volume = NULL;
    }
    if (volume) { 
    if(!cJSON_IsNumber(volume))
    {
    goto end; //Numeric
    }
    volume_local_var = malloc(sizeof(long));
    if(!volume_local_var)
    {
        goto end;
    }
    *volume_local_var = volume->valuedouble;
    }

    // market_quote_symbol_ltp_v3->cp
    cJSON *cp = cJSON_GetObjectItemCaseSensitive(market_quote_symbol_ltp_v3JSON, "cp");
    if (cJSON_IsNull(cp)) {
        cp = NULL;
    }
    if (cp) { 
    if(!cJSON_IsNumber(cp))
    {
    goto end; //Numeric
    }
    cp_local_var = malloc(sizeof(double));
    if(!cp_local_var)
    {
        goto end;
    }
    *cp_local_var = cp->valuedouble;
    }


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    market_quote_symbol_ltp_v3_local_var = market_quote_symbol_ltp_v3_create_internal (
        last_price_local_var,
        instrument_token_local_str,
        ltq_local_var,
        volume_local_var,
        cp_local_var
        );

    if (!market_quote_symbol_ltp_v3_local_var) {
        goto end;
    }

    return market_quote_symbol_ltp_v3_local_var;
end:
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (ltq_local_var) {
        free(ltq_local_var);
        ltq_local_var = NULL;
    }
    if (volume_local_var) {
        free(volume_local_var);
        volume_local_var = NULL;
    }
    if (cp_local_var) {
        free(cp_local_var);
        cp_local_var = NULL;
    }
    return NULL;

}
