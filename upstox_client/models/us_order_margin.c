#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_margin.h"



static us_order_margin_t *us_order_margin_create_internal(
    double *brokerage,
    double *gst,
    char *instrument_key,
    char *transaction_type,
    double *trade_value,
    double *required_margin
    ) {
    us_order_margin_t *us_order_margin_local_var = malloc(sizeof(us_order_margin_t));
    if (!us_order_margin_local_var) {
        return NULL;
    }
    memset(us_order_margin_local_var, 0, sizeof(us_order_margin_t));
    us_order_margin_local_var->_library_owned = 1;
    us_order_margin_local_var->brokerage = brokerage;
    us_order_margin_local_var->gst = gst;
    us_order_margin_local_var->instrument_key = instrument_key;
    us_order_margin_local_var->transaction_type = transaction_type;
    us_order_margin_local_var->trade_value = trade_value;
    us_order_margin_local_var->required_margin = required_margin;
    return us_order_margin_local_var;
}

us_order_margin_t *us_order_margin_create(
    double *brokerage,
    double *gst,
    char *instrument_key,
    char *transaction_type,
    double *trade_value,
    double *required_margin
    ) {
    double *brokerage_copy = NULL;
    if (brokerage) {
        brokerage_copy = malloc(sizeof(double));
        if (brokerage_copy) *brokerage_copy = *brokerage;
    }
    double *gst_copy = NULL;
    if (gst) {
        gst_copy = malloc(sizeof(double));
        if (gst_copy) *gst_copy = *gst;
    }
    double *trade_value_copy = NULL;
    if (trade_value) {
        trade_value_copy = malloc(sizeof(double));
        if (trade_value_copy) *trade_value_copy = *trade_value;
    }
    double *required_margin_copy = NULL;
    if (required_margin) {
        required_margin_copy = malloc(sizeof(double));
        if (required_margin_copy) *required_margin_copy = *required_margin;
    }
    us_order_margin_t *result = us_order_margin_create_internal (
        brokerage_copy,
        gst_copy,
        instrument_key,
        transaction_type,
        trade_value_copy,
        required_margin_copy
        );
    if (!result) {
        free(brokerage_copy);
        free(gst_copy);
        free(trade_value_copy);
        free(required_margin_copy);
    }
    return result;
}

void us_order_margin_free(us_order_margin_t *us_order_margin) {
    if(NULL == us_order_margin){
        return ;
    }
    if(us_order_margin->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_margin_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_margin->brokerage) {
        free(us_order_margin->brokerage);
        us_order_margin->brokerage = NULL;
    }
    if (us_order_margin->gst) {
        free(us_order_margin->gst);
        us_order_margin->gst = NULL;
    }
    if (us_order_margin->instrument_key) {
        free(us_order_margin->instrument_key);
        us_order_margin->instrument_key = NULL;
    }
    if (us_order_margin->transaction_type) {
        free(us_order_margin->transaction_type);
        us_order_margin->transaction_type = NULL;
    }
    if (us_order_margin->trade_value) {
        free(us_order_margin->trade_value);
        us_order_margin->trade_value = NULL;
    }
    if (us_order_margin->required_margin) {
        free(us_order_margin->required_margin);
        us_order_margin->required_margin = NULL;
    }
    free(us_order_margin);
}

cJSON *us_order_margin_convertToJSON(us_order_margin_t *us_order_margin) {
    cJSON *item = cJSON_CreateObject();

    // us_order_margin->brokerage
    if(us_order_margin->brokerage) {
    if(cJSON_AddNumberToObject(item, "brokerage", *us_order_margin->brokerage) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_margin->gst
    if(us_order_margin->gst) {
    if(cJSON_AddNumberToObject(item, "gst", *us_order_margin->gst) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_margin->instrument_key
    if(us_order_margin->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", us_order_margin->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // us_order_margin->transaction_type
    if(us_order_margin->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", us_order_margin->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // us_order_margin->trade_value
    if(us_order_margin->trade_value) {
    if(cJSON_AddNumberToObject(item, "trade_value", *us_order_margin->trade_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_margin->required_margin
    if(us_order_margin->required_margin) {
    if(cJSON_AddNumberToObject(item, "required_margin", *us_order_margin->required_margin) == NULL) {
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

us_order_margin_t *us_order_margin_parseFromJSON(cJSON *us_order_marginJSON){

    us_order_margin_t *us_order_margin_local_var = NULL;

    // define the local variable for us_order_margin->brokerage
    double *brokerage_local_var = NULL;

    // define the local variable for us_order_margin->gst
    double *gst_local_var = NULL;

    char *instrument_key_local_str = NULL;

    char *transaction_type_local_str = NULL;

    // define the local variable for us_order_margin->trade_value
    double *trade_value_local_var = NULL;

    // define the local variable for us_order_margin->required_margin
    double *required_margin_local_var = NULL;

    // us_order_margin->brokerage
    cJSON *brokerage = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "brokerage");
    if (cJSON_IsNull(brokerage)) {
        brokerage = NULL;
    }
    if (brokerage) { 
    if(!cJSON_IsNumber(brokerage))
    {
    goto end; //Numeric
    }
    brokerage_local_var = malloc(sizeof(double));
    if(!brokerage_local_var)
    {
        goto end;
    }
    *brokerage_local_var = brokerage->valuedouble;
    }

    // us_order_margin->gst
    cJSON *gst = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "gst");
    if (cJSON_IsNull(gst)) {
        gst = NULL;
    }
    if (gst) { 
    if(!cJSON_IsNumber(gst))
    {
    goto end; //Numeric
    }
    gst_local_var = malloc(sizeof(double));
    if(!gst_local_var)
    {
        goto end;
    }
    *gst_local_var = gst->valuedouble;
    }

    // us_order_margin->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // us_order_margin->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // us_order_margin->trade_value
    cJSON *trade_value = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "trade_value");
    if (cJSON_IsNull(trade_value)) {
        trade_value = NULL;
    }
    if (trade_value) { 
    if(!cJSON_IsNumber(trade_value))
    {
    goto end; //Numeric
    }
    trade_value_local_var = malloc(sizeof(double));
    if(!trade_value_local_var)
    {
        goto end;
    }
    *trade_value_local_var = trade_value->valuedouble;
    }

    // us_order_margin->required_margin
    cJSON *required_margin = cJSON_GetObjectItemCaseSensitive(us_order_marginJSON, "required_margin");
    if (cJSON_IsNull(required_margin)) {
        required_margin = NULL;
    }
    if (required_margin) { 
    if(!cJSON_IsNumber(required_margin))
    {
    goto end; //Numeric
    }
    required_margin_local_var = malloc(sizeof(double));
    if(!required_margin_local_var)
    {
        goto end;
    }
    *required_margin_local_var = required_margin->valuedouble;
    }


    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);

    us_order_margin_local_var = us_order_margin_create_internal (
        brokerage_local_var,
        gst_local_var,
        instrument_key_local_str,
        transaction_type_local_str,
        trade_value_local_var,
        required_margin_local_var
        );

    if (!us_order_margin_local_var) {
        goto end;
    }

    return us_order_margin_local_var;
end:
    if (brokerage_local_var) {
        free(brokerage_local_var);
        brokerage_local_var = NULL;
    }
    if (gst_local_var) {
        free(gst_local_var);
        gst_local_var = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (trade_value_local_var) {
        free(trade_value_local_var);
        trade_value_local_var = NULL;
    }
    if (required_margin_local_var) {
        free(required_margin_local_var);
        required_margin_local_var = NULL;
    }
    return NULL;

}
