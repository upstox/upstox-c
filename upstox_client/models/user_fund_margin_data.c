#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "user_fund_margin_data.h"



static user_fund_margin_data_t *user_fund_margin_data_create_internal(
    double *used_margin,
    double *payin_amount,
    double *span_margin,
    double *adhoc_margin,
    double *notional_cash,
    double *available_margin,
    double *exposure_margin
    ) {
    user_fund_margin_data_t *user_fund_margin_data_local_var = malloc(sizeof(user_fund_margin_data_t));
    if (!user_fund_margin_data_local_var) {
        return NULL;
    }
    memset(user_fund_margin_data_local_var, 0, sizeof(user_fund_margin_data_t));
    user_fund_margin_data_local_var->_library_owned = 1;
    user_fund_margin_data_local_var->used_margin = used_margin;
    user_fund_margin_data_local_var->payin_amount = payin_amount;
    user_fund_margin_data_local_var->span_margin = span_margin;
    user_fund_margin_data_local_var->adhoc_margin = adhoc_margin;
    user_fund_margin_data_local_var->notional_cash = notional_cash;
    user_fund_margin_data_local_var->available_margin = available_margin;
    user_fund_margin_data_local_var->exposure_margin = exposure_margin;
    return user_fund_margin_data_local_var;
}

user_fund_margin_data_t *user_fund_margin_data_create(
    double *used_margin,
    double *payin_amount,
    double *span_margin,
    double *adhoc_margin,
    double *notional_cash,
    double *available_margin,
    double *exposure_margin
    ) {
    double *used_margin_copy = NULL;
    if (used_margin) {
        used_margin_copy = malloc(sizeof(double));
        if (used_margin_copy) *used_margin_copy = *used_margin;
    }
    double *payin_amount_copy = NULL;
    if (payin_amount) {
        payin_amount_copy = malloc(sizeof(double));
        if (payin_amount_copy) *payin_amount_copy = *payin_amount;
    }
    double *span_margin_copy = NULL;
    if (span_margin) {
        span_margin_copy = malloc(sizeof(double));
        if (span_margin_copy) *span_margin_copy = *span_margin;
    }
    double *adhoc_margin_copy = NULL;
    if (adhoc_margin) {
        adhoc_margin_copy = malloc(sizeof(double));
        if (adhoc_margin_copy) *adhoc_margin_copy = *adhoc_margin;
    }
    double *notional_cash_copy = NULL;
    if (notional_cash) {
        notional_cash_copy = malloc(sizeof(double));
        if (notional_cash_copy) *notional_cash_copy = *notional_cash;
    }
    double *available_margin_copy = NULL;
    if (available_margin) {
        available_margin_copy = malloc(sizeof(double));
        if (available_margin_copy) *available_margin_copy = *available_margin;
    }
    double *exposure_margin_copy = NULL;
    if (exposure_margin) {
        exposure_margin_copy = malloc(sizeof(double));
        if (exposure_margin_copy) *exposure_margin_copy = *exposure_margin;
    }
    user_fund_margin_data_t *result = user_fund_margin_data_create_internal (
        used_margin_copy,
        payin_amount_copy,
        span_margin_copy,
        adhoc_margin_copy,
        notional_cash_copy,
        available_margin_copy,
        exposure_margin_copy
        );
    if (!result) {
        free(used_margin_copy);
        free(payin_amount_copy);
        free(span_margin_copy);
        free(adhoc_margin_copy);
        free(notional_cash_copy);
        free(available_margin_copy);
        free(exposure_margin_copy);
    }
    return result;
}

void user_fund_margin_data_free(user_fund_margin_data_t *user_fund_margin_data) {
    if(NULL == user_fund_margin_data){
        return ;
    }
    if(user_fund_margin_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "user_fund_margin_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (user_fund_margin_data->used_margin) {
        free(user_fund_margin_data->used_margin);
        user_fund_margin_data->used_margin = NULL;
    }
    if (user_fund_margin_data->payin_amount) {
        free(user_fund_margin_data->payin_amount);
        user_fund_margin_data->payin_amount = NULL;
    }
    if (user_fund_margin_data->span_margin) {
        free(user_fund_margin_data->span_margin);
        user_fund_margin_data->span_margin = NULL;
    }
    if (user_fund_margin_data->adhoc_margin) {
        free(user_fund_margin_data->adhoc_margin);
        user_fund_margin_data->adhoc_margin = NULL;
    }
    if (user_fund_margin_data->notional_cash) {
        free(user_fund_margin_data->notional_cash);
        user_fund_margin_data->notional_cash = NULL;
    }
    if (user_fund_margin_data->available_margin) {
        free(user_fund_margin_data->available_margin);
        user_fund_margin_data->available_margin = NULL;
    }
    if (user_fund_margin_data->exposure_margin) {
        free(user_fund_margin_data->exposure_margin);
        user_fund_margin_data->exposure_margin = NULL;
    }
    free(user_fund_margin_data);
}

cJSON *user_fund_margin_data_convertToJSON(user_fund_margin_data_t *user_fund_margin_data) {
    cJSON *item = cJSON_CreateObject();

    // user_fund_margin_data->used_margin
    if(user_fund_margin_data->used_margin) {
    if(cJSON_AddNumberToObject(item, "used_margin", *user_fund_margin_data->used_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->payin_amount
    if(user_fund_margin_data->payin_amount) {
    if(cJSON_AddNumberToObject(item, "payin_amount", *user_fund_margin_data->payin_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->span_margin
    if(user_fund_margin_data->span_margin) {
    if(cJSON_AddNumberToObject(item, "span_margin", *user_fund_margin_data->span_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->adhoc_margin
    if(user_fund_margin_data->adhoc_margin) {
    if(cJSON_AddNumberToObject(item, "adhoc_margin", *user_fund_margin_data->adhoc_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->notional_cash
    if(user_fund_margin_data->notional_cash) {
    if(cJSON_AddNumberToObject(item, "notional_cash", *user_fund_margin_data->notional_cash) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->available_margin
    if(user_fund_margin_data->available_margin) {
    if(cJSON_AddNumberToObject(item, "available_margin", *user_fund_margin_data->available_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // user_fund_margin_data->exposure_margin
    if(user_fund_margin_data->exposure_margin) {
    if(cJSON_AddNumberToObject(item, "exposure_margin", *user_fund_margin_data->exposure_margin) == NULL) {
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

user_fund_margin_data_t *user_fund_margin_data_parseFromJSON(cJSON *user_fund_margin_dataJSON){

    user_fund_margin_data_t *user_fund_margin_data_local_var = NULL;

    // define the local variable for user_fund_margin_data->used_margin
    double *used_margin_local_var = NULL;

    // define the local variable for user_fund_margin_data->payin_amount
    double *payin_amount_local_var = NULL;

    // define the local variable for user_fund_margin_data->span_margin
    double *span_margin_local_var = NULL;

    // define the local variable for user_fund_margin_data->adhoc_margin
    double *adhoc_margin_local_var = NULL;

    // define the local variable for user_fund_margin_data->notional_cash
    double *notional_cash_local_var = NULL;

    // define the local variable for user_fund_margin_data->available_margin
    double *available_margin_local_var = NULL;

    // define the local variable for user_fund_margin_data->exposure_margin
    double *exposure_margin_local_var = NULL;

    // user_fund_margin_data->used_margin
    cJSON *used_margin = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "used_margin");
    if (cJSON_IsNull(used_margin)) {
        used_margin = NULL;
    }
    if (used_margin) { 
    if(!cJSON_IsNumber(used_margin))
    {
    goto end; //Numeric
    }
    used_margin_local_var = malloc(sizeof(double));
    if(!used_margin_local_var)
    {
        goto end;
    }
    *used_margin_local_var = used_margin->valuedouble;
    }

    // user_fund_margin_data->payin_amount
    cJSON *payin_amount = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "payin_amount");
    if (cJSON_IsNull(payin_amount)) {
        payin_amount = NULL;
    }
    if (payin_amount) { 
    if(!cJSON_IsNumber(payin_amount))
    {
    goto end; //Numeric
    }
    payin_amount_local_var = malloc(sizeof(double));
    if(!payin_amount_local_var)
    {
        goto end;
    }
    *payin_amount_local_var = payin_amount->valuedouble;
    }

    // user_fund_margin_data->span_margin
    cJSON *span_margin = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "span_margin");
    if (cJSON_IsNull(span_margin)) {
        span_margin = NULL;
    }
    if (span_margin) { 
    if(!cJSON_IsNumber(span_margin))
    {
    goto end; //Numeric
    }
    span_margin_local_var = malloc(sizeof(double));
    if(!span_margin_local_var)
    {
        goto end;
    }
    *span_margin_local_var = span_margin->valuedouble;
    }

    // user_fund_margin_data->adhoc_margin
    cJSON *adhoc_margin = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "adhoc_margin");
    if (cJSON_IsNull(adhoc_margin)) {
        adhoc_margin = NULL;
    }
    if (adhoc_margin) { 
    if(!cJSON_IsNumber(adhoc_margin))
    {
    goto end; //Numeric
    }
    adhoc_margin_local_var = malloc(sizeof(double));
    if(!adhoc_margin_local_var)
    {
        goto end;
    }
    *adhoc_margin_local_var = adhoc_margin->valuedouble;
    }

    // user_fund_margin_data->notional_cash
    cJSON *notional_cash = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "notional_cash");
    if (cJSON_IsNull(notional_cash)) {
        notional_cash = NULL;
    }
    if (notional_cash) { 
    if(!cJSON_IsNumber(notional_cash))
    {
    goto end; //Numeric
    }
    notional_cash_local_var = malloc(sizeof(double));
    if(!notional_cash_local_var)
    {
        goto end;
    }
    *notional_cash_local_var = notional_cash->valuedouble;
    }

    // user_fund_margin_data->available_margin
    cJSON *available_margin = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "available_margin");
    if (cJSON_IsNull(available_margin)) {
        available_margin = NULL;
    }
    if (available_margin) { 
    if(!cJSON_IsNumber(available_margin))
    {
    goto end; //Numeric
    }
    available_margin_local_var = malloc(sizeof(double));
    if(!available_margin_local_var)
    {
        goto end;
    }
    *available_margin_local_var = available_margin->valuedouble;
    }

    // user_fund_margin_data->exposure_margin
    cJSON *exposure_margin = cJSON_GetObjectItemCaseSensitive(user_fund_margin_dataJSON, "exposure_margin");
    if (cJSON_IsNull(exposure_margin)) {
        exposure_margin = NULL;
    }
    if (exposure_margin) { 
    if(!cJSON_IsNumber(exposure_margin))
    {
    goto end; //Numeric
    }
    exposure_margin_local_var = malloc(sizeof(double));
    if(!exposure_margin_local_var)
    {
        goto end;
    }
    *exposure_margin_local_var = exposure_margin->valuedouble;
    }



    user_fund_margin_data_local_var = user_fund_margin_data_create_internal (
        used_margin_local_var,
        payin_amount_local_var,
        span_margin_local_var,
        adhoc_margin_local_var,
        notional_cash_local_var,
        available_margin_local_var,
        exposure_margin_local_var
        );

    if (!user_fund_margin_data_local_var) {
        goto end;
    }

    return user_fund_margin_data_local_var;
end:
    if (used_margin_local_var) {
        free(used_margin_local_var);
        used_margin_local_var = NULL;
    }
    if (payin_amount_local_var) {
        free(payin_amount_local_var);
        payin_amount_local_var = NULL;
    }
    if (span_margin_local_var) {
        free(span_margin_local_var);
        span_margin_local_var = NULL;
    }
    if (adhoc_margin_local_var) {
        free(adhoc_margin_local_var);
        adhoc_margin_local_var = NULL;
    }
    if (notional_cash_local_var) {
        free(notional_cash_local_var);
        notional_cash_local_var = NULL;
    }
    if (available_margin_local_var) {
        free(available_margin_local_var);
        available_margin_local_var = NULL;
    }
    if (exposure_margin_local_var) {
        free(exposure_margin_local_var);
        exposure_margin_local_var = NULL;
    }
    return NULL;

}
