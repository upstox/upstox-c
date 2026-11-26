#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "market_quote_option_greek_v3.h"



static market_quote_option_greek_v3_t *market_quote_option_greek_v3_create_internal(
    double *last_price,
    char *instrument_token,
    long *ltq,
    long *volume,
    double *cp,
    double *iv,
    double *vega,
    double *gamma,
    double *theta,
    double *delta,
    double *oi
    ) {
    market_quote_option_greek_v3_t *market_quote_option_greek_v3_local_var = malloc(sizeof(market_quote_option_greek_v3_t));
    if (!market_quote_option_greek_v3_local_var) {
        return NULL;
    }
    memset(market_quote_option_greek_v3_local_var, 0, sizeof(market_quote_option_greek_v3_t));
    market_quote_option_greek_v3_local_var->_library_owned = 1;
    market_quote_option_greek_v3_local_var->last_price = last_price;
    market_quote_option_greek_v3_local_var->instrument_token = instrument_token;
    market_quote_option_greek_v3_local_var->ltq = ltq;
    market_quote_option_greek_v3_local_var->volume = volume;
    market_quote_option_greek_v3_local_var->cp = cp;
    market_quote_option_greek_v3_local_var->iv = iv;
    market_quote_option_greek_v3_local_var->vega = vega;
    market_quote_option_greek_v3_local_var->gamma = gamma;
    market_quote_option_greek_v3_local_var->theta = theta;
    market_quote_option_greek_v3_local_var->delta = delta;
    market_quote_option_greek_v3_local_var->oi = oi;
    return market_quote_option_greek_v3_local_var;
}

market_quote_option_greek_v3_t *market_quote_option_greek_v3_create(
    double *last_price,
    char *instrument_token,
    long *ltq,
    long *volume,
    double *cp,
    double *iv,
    double *vega,
    double *gamma,
    double *theta,
    double *delta,
    double *oi
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
    double *iv_copy = NULL;
    if (iv) {
        iv_copy = malloc(sizeof(double));
        if (iv_copy) *iv_copy = *iv;
    }
    double *vega_copy = NULL;
    if (vega) {
        vega_copy = malloc(sizeof(double));
        if (vega_copy) *vega_copy = *vega;
    }
    double *gamma_copy = NULL;
    if (gamma) {
        gamma_copy = malloc(sizeof(double));
        if (gamma_copy) *gamma_copy = *gamma;
    }
    double *theta_copy = NULL;
    if (theta) {
        theta_copy = malloc(sizeof(double));
        if (theta_copy) *theta_copy = *theta;
    }
    double *delta_copy = NULL;
    if (delta) {
        delta_copy = malloc(sizeof(double));
        if (delta_copy) *delta_copy = *delta;
    }
    double *oi_copy = NULL;
    if (oi) {
        oi_copy = malloc(sizeof(double));
        if (oi_copy) *oi_copy = *oi;
    }
    market_quote_option_greek_v3_t *result = market_quote_option_greek_v3_create_internal (
        last_price_copy,
        instrument_token,
        ltq_copy,
        volume_copy,
        cp_copy,
        iv_copy,
        vega_copy,
        gamma_copy,
        theta_copy,
        delta_copy,
        oi_copy
        );
    if (!result) {
        free(last_price_copy);
        free(ltq_copy);
        free(volume_copy);
        free(cp_copy);
        free(iv_copy);
        free(vega_copy);
        free(gamma_copy);
        free(theta_copy);
        free(delta_copy);
        free(oi_copy);
    }
    return result;
}

void market_quote_option_greek_v3_free(market_quote_option_greek_v3_t *market_quote_option_greek_v3) {
    if(NULL == market_quote_option_greek_v3){
        return ;
    }
    if(market_quote_option_greek_v3->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "market_quote_option_greek_v3_free");
        return ;
    }
    listEntry_t *listEntry;
    if (market_quote_option_greek_v3->last_price) {
        free(market_quote_option_greek_v3->last_price);
        market_quote_option_greek_v3->last_price = NULL;
    }
    if (market_quote_option_greek_v3->instrument_token) {
        free(market_quote_option_greek_v3->instrument_token);
        market_quote_option_greek_v3->instrument_token = NULL;
    }
    if (market_quote_option_greek_v3->ltq) {
        free(market_quote_option_greek_v3->ltq);
        market_quote_option_greek_v3->ltq = NULL;
    }
    if (market_quote_option_greek_v3->volume) {
        free(market_quote_option_greek_v3->volume);
        market_quote_option_greek_v3->volume = NULL;
    }
    if (market_quote_option_greek_v3->cp) {
        free(market_quote_option_greek_v3->cp);
        market_quote_option_greek_v3->cp = NULL;
    }
    if (market_quote_option_greek_v3->iv) {
        free(market_quote_option_greek_v3->iv);
        market_quote_option_greek_v3->iv = NULL;
    }
    if (market_quote_option_greek_v3->vega) {
        free(market_quote_option_greek_v3->vega);
        market_quote_option_greek_v3->vega = NULL;
    }
    if (market_quote_option_greek_v3->gamma) {
        free(market_quote_option_greek_v3->gamma);
        market_quote_option_greek_v3->gamma = NULL;
    }
    if (market_quote_option_greek_v3->theta) {
        free(market_quote_option_greek_v3->theta);
        market_quote_option_greek_v3->theta = NULL;
    }
    if (market_quote_option_greek_v3->delta) {
        free(market_quote_option_greek_v3->delta);
        market_quote_option_greek_v3->delta = NULL;
    }
    if (market_quote_option_greek_v3->oi) {
        free(market_quote_option_greek_v3->oi);
        market_quote_option_greek_v3->oi = NULL;
    }
    free(market_quote_option_greek_v3);
}

cJSON *market_quote_option_greek_v3_convertToJSON(market_quote_option_greek_v3_t *market_quote_option_greek_v3) {
    cJSON *item = cJSON_CreateObject();

    // market_quote_option_greek_v3->last_price
    if(market_quote_option_greek_v3->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *market_quote_option_greek_v3->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->instrument_token
    if(market_quote_option_greek_v3->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", market_quote_option_greek_v3->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // market_quote_option_greek_v3->ltq
    if(market_quote_option_greek_v3->ltq) {
    if(cJSON_AddNumberToObject(item, "ltq", *market_quote_option_greek_v3->ltq) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->volume
    if(market_quote_option_greek_v3->volume) {
    if(cJSON_AddNumberToObject(item, "volume", *market_quote_option_greek_v3->volume) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->cp
    if(market_quote_option_greek_v3->cp) {
    if(cJSON_AddNumberToObject(item, "cp", *market_quote_option_greek_v3->cp) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->iv
    if(market_quote_option_greek_v3->iv) {
    if(cJSON_AddNumberToObject(item, "iv", *market_quote_option_greek_v3->iv) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->vega
    if(market_quote_option_greek_v3->vega) {
    if(cJSON_AddNumberToObject(item, "vega", *market_quote_option_greek_v3->vega) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->gamma
    if(market_quote_option_greek_v3->gamma) {
    if(cJSON_AddNumberToObject(item, "gamma", *market_quote_option_greek_v3->gamma) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->theta
    if(market_quote_option_greek_v3->theta) {
    if(cJSON_AddNumberToObject(item, "theta", *market_quote_option_greek_v3->theta) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->delta
    if(market_quote_option_greek_v3->delta) {
    if(cJSON_AddNumberToObject(item, "delta", *market_quote_option_greek_v3->delta) == NULL) {
    goto fail; //Numeric
    }
    }


    // market_quote_option_greek_v3->oi
    if(market_quote_option_greek_v3->oi) {
    if(cJSON_AddNumberToObject(item, "oi", *market_quote_option_greek_v3->oi) == NULL) {
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

market_quote_option_greek_v3_t *market_quote_option_greek_v3_parseFromJSON(cJSON *market_quote_option_greek_v3JSON){

    market_quote_option_greek_v3_t *market_quote_option_greek_v3_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->last_price
    double *last_price_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for market_quote_option_greek_v3->ltq
    long *ltq_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->volume
    long *volume_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->cp
    double *cp_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->iv
    double *iv_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->vega
    double *vega_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->gamma
    double *gamma_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->theta
    double *theta_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->delta
    double *delta_local_var = NULL;

    // define the local variable for market_quote_option_greek_v3->oi
    double *oi_local_var = NULL;

    // market_quote_option_greek_v3->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "last_price");
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

    // market_quote_option_greek_v3->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // market_quote_option_greek_v3->ltq
    cJSON *ltq = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "ltq");
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

    // market_quote_option_greek_v3->volume
    cJSON *volume = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "volume");
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

    // market_quote_option_greek_v3->cp
    cJSON *cp = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "cp");
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

    // market_quote_option_greek_v3->iv
    cJSON *iv = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "iv");
    if (cJSON_IsNull(iv)) {
        iv = NULL;
    }
    if (iv) { 
    if(!cJSON_IsNumber(iv))
    {
    goto end; //Numeric
    }
    iv_local_var = malloc(sizeof(double));
    if(!iv_local_var)
    {
        goto end;
    }
    *iv_local_var = iv->valuedouble;
    }

    // market_quote_option_greek_v3->vega
    cJSON *vega = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "vega");
    if (cJSON_IsNull(vega)) {
        vega = NULL;
    }
    if (vega) { 
    if(!cJSON_IsNumber(vega))
    {
    goto end; //Numeric
    }
    vega_local_var = malloc(sizeof(double));
    if(!vega_local_var)
    {
        goto end;
    }
    *vega_local_var = vega->valuedouble;
    }

    // market_quote_option_greek_v3->gamma
    cJSON *gamma = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "gamma");
    if (cJSON_IsNull(gamma)) {
        gamma = NULL;
    }
    if (gamma) { 
    if(!cJSON_IsNumber(gamma))
    {
    goto end; //Numeric
    }
    gamma_local_var = malloc(sizeof(double));
    if(!gamma_local_var)
    {
        goto end;
    }
    *gamma_local_var = gamma->valuedouble;
    }

    // market_quote_option_greek_v3->theta
    cJSON *theta = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "theta");
    if (cJSON_IsNull(theta)) {
        theta = NULL;
    }
    if (theta) { 
    if(!cJSON_IsNumber(theta))
    {
    goto end; //Numeric
    }
    theta_local_var = malloc(sizeof(double));
    if(!theta_local_var)
    {
        goto end;
    }
    *theta_local_var = theta->valuedouble;
    }

    // market_quote_option_greek_v3->delta
    cJSON *delta = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "delta");
    if (cJSON_IsNull(delta)) {
        delta = NULL;
    }
    if (delta) { 
    if(!cJSON_IsNumber(delta))
    {
    goto end; //Numeric
    }
    delta_local_var = malloc(sizeof(double));
    if(!delta_local_var)
    {
        goto end;
    }
    *delta_local_var = delta->valuedouble;
    }

    // market_quote_option_greek_v3->oi
    cJSON *oi = cJSON_GetObjectItemCaseSensitive(market_quote_option_greek_v3JSON, "oi");
    if (cJSON_IsNull(oi)) {
        oi = NULL;
    }
    if (oi) { 
    if(!cJSON_IsNumber(oi))
    {
    goto end; //Numeric
    }
    oi_local_var = malloc(sizeof(double));
    if(!oi_local_var)
    {
        goto end;
    }
    *oi_local_var = oi->valuedouble;
    }


    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);

    market_quote_option_greek_v3_local_var = market_quote_option_greek_v3_create_internal (
        last_price_local_var,
        instrument_token_local_str,
        ltq_local_var,
        volume_local_var,
        cp_local_var,
        iv_local_var,
        vega_local_var,
        gamma_local_var,
        theta_local_var,
        delta_local_var,
        oi_local_var
        );

    if (!market_quote_option_greek_v3_local_var) {
        goto end;
    }

    return market_quote_option_greek_v3_local_var;
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
    if (iv_local_var) {
        free(iv_local_var);
        iv_local_var = NULL;
    }
    if (vega_local_var) {
        free(vega_local_var);
        vega_local_var = NULL;
    }
    if (gamma_local_var) {
        free(gamma_local_var);
        gamma_local_var = NULL;
    }
    if (theta_local_var) {
        free(theta_local_var);
        theta_local_var = NULL;
    }
    if (delta_local_var) {
        free(delta_local_var);
        delta_local_var = NULL;
    }
    if (oi_local_var) {
        free(oi_local_var);
        oi_local_var = NULL;
    }
    return NULL;

}
