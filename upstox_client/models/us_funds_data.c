#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_funds_data.h"



static us_funds_data_t *us_funds_data_create_internal(
    double *cash,
    double *available_to_trade,
    double *available_to_withdraw,
    double *unsettled_cash,
    double *exchange_rate,
    double *available_to_trade_inr,
    double *available_to_withdraw_inr,
    double *cash_inr,
    double *unsettled_cash_inr
    ) {
    us_funds_data_t *us_funds_data_local_var = malloc(sizeof(us_funds_data_t));
    if (!us_funds_data_local_var) {
        return NULL;
    }
    memset(us_funds_data_local_var, 0, sizeof(us_funds_data_t));
    us_funds_data_local_var->_library_owned = 1;
    us_funds_data_local_var->cash = cash;
    us_funds_data_local_var->available_to_trade = available_to_trade;
    us_funds_data_local_var->available_to_withdraw = available_to_withdraw;
    us_funds_data_local_var->unsettled_cash = unsettled_cash;
    us_funds_data_local_var->exchange_rate = exchange_rate;
    us_funds_data_local_var->available_to_trade_inr = available_to_trade_inr;
    us_funds_data_local_var->available_to_withdraw_inr = available_to_withdraw_inr;
    us_funds_data_local_var->cash_inr = cash_inr;
    us_funds_data_local_var->unsettled_cash_inr = unsettled_cash_inr;
    return us_funds_data_local_var;
}

us_funds_data_t *us_funds_data_create(
    double *cash,
    double *available_to_trade,
    double *available_to_withdraw,
    double *unsettled_cash,
    double *exchange_rate,
    double *available_to_trade_inr,
    double *available_to_withdraw_inr,
    double *cash_inr,
    double *unsettled_cash_inr
    ) {
    double *cash_copy = NULL;
    if (cash) {
        cash_copy = malloc(sizeof(double));
        if (cash_copy) *cash_copy = *cash;
    }
    double *available_to_trade_copy = NULL;
    if (available_to_trade) {
        available_to_trade_copy = malloc(sizeof(double));
        if (available_to_trade_copy) *available_to_trade_copy = *available_to_trade;
    }
    double *available_to_withdraw_copy = NULL;
    if (available_to_withdraw) {
        available_to_withdraw_copy = malloc(sizeof(double));
        if (available_to_withdraw_copy) *available_to_withdraw_copy = *available_to_withdraw;
    }
    double *unsettled_cash_copy = NULL;
    if (unsettled_cash) {
        unsettled_cash_copy = malloc(sizeof(double));
        if (unsettled_cash_copy) *unsettled_cash_copy = *unsettled_cash;
    }
    double *exchange_rate_copy = NULL;
    if (exchange_rate) {
        exchange_rate_copy = malloc(sizeof(double));
        if (exchange_rate_copy) *exchange_rate_copy = *exchange_rate;
    }
    double *available_to_trade_inr_copy = NULL;
    if (available_to_trade_inr) {
        available_to_trade_inr_copy = malloc(sizeof(double));
        if (available_to_trade_inr_copy) *available_to_trade_inr_copy = *available_to_trade_inr;
    }
    double *available_to_withdraw_inr_copy = NULL;
    if (available_to_withdraw_inr) {
        available_to_withdraw_inr_copy = malloc(sizeof(double));
        if (available_to_withdraw_inr_copy) *available_to_withdraw_inr_copy = *available_to_withdraw_inr;
    }
    double *cash_inr_copy = NULL;
    if (cash_inr) {
        cash_inr_copy = malloc(sizeof(double));
        if (cash_inr_copy) *cash_inr_copy = *cash_inr;
    }
    double *unsettled_cash_inr_copy = NULL;
    if (unsettled_cash_inr) {
        unsettled_cash_inr_copy = malloc(sizeof(double));
        if (unsettled_cash_inr_copy) *unsettled_cash_inr_copy = *unsettled_cash_inr;
    }
    us_funds_data_t *result = us_funds_data_create_internal (
        cash_copy,
        available_to_trade_copy,
        available_to_withdraw_copy,
        unsettled_cash_copy,
        exchange_rate_copy,
        available_to_trade_inr_copy,
        available_to_withdraw_inr_copy,
        cash_inr_copy,
        unsettled_cash_inr_copy
        );
    if (!result) {
        free(cash_copy);
        free(available_to_trade_copy);
        free(available_to_withdraw_copy);
        free(unsettled_cash_copy);
        free(exchange_rate_copy);
        free(available_to_trade_inr_copy);
        free(available_to_withdraw_inr_copy);
        free(cash_inr_copy);
        free(unsettled_cash_inr_copy);
    }
    return result;
}

void us_funds_data_free(us_funds_data_t *us_funds_data) {
    if(NULL == us_funds_data){
        return ;
    }
    if(us_funds_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_funds_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_funds_data->cash) {
        free(us_funds_data->cash);
        us_funds_data->cash = NULL;
    }
    if (us_funds_data->available_to_trade) {
        free(us_funds_data->available_to_trade);
        us_funds_data->available_to_trade = NULL;
    }
    if (us_funds_data->available_to_withdraw) {
        free(us_funds_data->available_to_withdraw);
        us_funds_data->available_to_withdraw = NULL;
    }
    if (us_funds_data->unsettled_cash) {
        free(us_funds_data->unsettled_cash);
        us_funds_data->unsettled_cash = NULL;
    }
    if (us_funds_data->exchange_rate) {
        free(us_funds_data->exchange_rate);
        us_funds_data->exchange_rate = NULL;
    }
    if (us_funds_data->available_to_trade_inr) {
        free(us_funds_data->available_to_trade_inr);
        us_funds_data->available_to_trade_inr = NULL;
    }
    if (us_funds_data->available_to_withdraw_inr) {
        free(us_funds_data->available_to_withdraw_inr);
        us_funds_data->available_to_withdraw_inr = NULL;
    }
    if (us_funds_data->cash_inr) {
        free(us_funds_data->cash_inr);
        us_funds_data->cash_inr = NULL;
    }
    if (us_funds_data->unsettled_cash_inr) {
        free(us_funds_data->unsettled_cash_inr);
        us_funds_data->unsettled_cash_inr = NULL;
    }
    free(us_funds_data);
}

cJSON *us_funds_data_convertToJSON(us_funds_data_t *us_funds_data) {
    cJSON *item = cJSON_CreateObject();

    // us_funds_data->cash
    if(us_funds_data->cash) {
    if(cJSON_AddNumberToObject(item, "cash", *us_funds_data->cash) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->available_to_trade
    if(us_funds_data->available_to_trade) {
    if(cJSON_AddNumberToObject(item, "available_to_trade", *us_funds_data->available_to_trade) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->available_to_withdraw
    if(us_funds_data->available_to_withdraw) {
    if(cJSON_AddNumberToObject(item, "available_to_withdraw", *us_funds_data->available_to_withdraw) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->unsettled_cash
    if(us_funds_data->unsettled_cash) {
    if(cJSON_AddNumberToObject(item, "unsettled_cash", *us_funds_data->unsettled_cash) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->exchange_rate
    if(us_funds_data->exchange_rate) {
    if(cJSON_AddNumberToObject(item, "exchange_rate", *us_funds_data->exchange_rate) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->available_to_trade_inr
    if(us_funds_data->available_to_trade_inr) {
    if(cJSON_AddNumberToObject(item, "available_to_trade_inr", *us_funds_data->available_to_trade_inr) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->available_to_withdraw_inr
    if(us_funds_data->available_to_withdraw_inr) {
    if(cJSON_AddNumberToObject(item, "available_to_withdraw_inr", *us_funds_data->available_to_withdraw_inr) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->cash_inr
    if(us_funds_data->cash_inr) {
    if(cJSON_AddNumberToObject(item, "cash_inr", *us_funds_data->cash_inr) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_funds_data->unsettled_cash_inr
    if(us_funds_data->unsettled_cash_inr) {
    if(cJSON_AddNumberToObject(item, "unsettled_cash_inr", *us_funds_data->unsettled_cash_inr) == NULL) {
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

us_funds_data_t *us_funds_data_parseFromJSON(cJSON *us_funds_dataJSON){

    us_funds_data_t *us_funds_data_local_var = NULL;

    // define the local variable for us_funds_data->cash
    double *cash_local_var = NULL;

    // define the local variable for us_funds_data->available_to_trade
    double *available_to_trade_local_var = NULL;

    // define the local variable for us_funds_data->available_to_withdraw
    double *available_to_withdraw_local_var = NULL;

    // define the local variable for us_funds_data->unsettled_cash
    double *unsettled_cash_local_var = NULL;

    // define the local variable for us_funds_data->exchange_rate
    double *exchange_rate_local_var = NULL;

    // define the local variable for us_funds_data->available_to_trade_inr
    double *available_to_trade_inr_local_var = NULL;

    // define the local variable for us_funds_data->available_to_withdraw_inr
    double *available_to_withdraw_inr_local_var = NULL;

    // define the local variable for us_funds_data->cash_inr
    double *cash_inr_local_var = NULL;

    // define the local variable for us_funds_data->unsettled_cash_inr
    double *unsettled_cash_inr_local_var = NULL;

    // us_funds_data->cash
    cJSON *cash = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "cash");
    if (cJSON_IsNull(cash)) {
        cash = NULL;
    }
    if (cash) { 
    if(!cJSON_IsNumber(cash))
    {
    goto end; //Numeric
    }
    cash_local_var = malloc(sizeof(double));
    if(!cash_local_var)
    {
        goto end;
    }
    *cash_local_var = cash->valuedouble;
    }

    // us_funds_data->available_to_trade
    cJSON *available_to_trade = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "available_to_trade");
    if (cJSON_IsNull(available_to_trade)) {
        available_to_trade = NULL;
    }
    if (available_to_trade) { 
    if(!cJSON_IsNumber(available_to_trade))
    {
    goto end; //Numeric
    }
    available_to_trade_local_var = malloc(sizeof(double));
    if(!available_to_trade_local_var)
    {
        goto end;
    }
    *available_to_trade_local_var = available_to_trade->valuedouble;
    }

    // us_funds_data->available_to_withdraw
    cJSON *available_to_withdraw = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "available_to_withdraw");
    if (cJSON_IsNull(available_to_withdraw)) {
        available_to_withdraw = NULL;
    }
    if (available_to_withdraw) { 
    if(!cJSON_IsNumber(available_to_withdraw))
    {
    goto end; //Numeric
    }
    available_to_withdraw_local_var = malloc(sizeof(double));
    if(!available_to_withdraw_local_var)
    {
        goto end;
    }
    *available_to_withdraw_local_var = available_to_withdraw->valuedouble;
    }

    // us_funds_data->unsettled_cash
    cJSON *unsettled_cash = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "unsettled_cash");
    if (cJSON_IsNull(unsettled_cash)) {
        unsettled_cash = NULL;
    }
    if (unsettled_cash) { 
    if(!cJSON_IsNumber(unsettled_cash))
    {
    goto end; //Numeric
    }
    unsettled_cash_local_var = malloc(sizeof(double));
    if(!unsettled_cash_local_var)
    {
        goto end;
    }
    *unsettled_cash_local_var = unsettled_cash->valuedouble;
    }

    // us_funds_data->exchange_rate
    cJSON *exchange_rate = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "exchange_rate");
    if (cJSON_IsNull(exchange_rate)) {
        exchange_rate = NULL;
    }
    if (exchange_rate) { 
    if(!cJSON_IsNumber(exchange_rate))
    {
    goto end; //Numeric
    }
    exchange_rate_local_var = malloc(sizeof(double));
    if(!exchange_rate_local_var)
    {
        goto end;
    }
    *exchange_rate_local_var = exchange_rate->valuedouble;
    }

    // us_funds_data->available_to_trade_inr
    cJSON *available_to_trade_inr = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "available_to_trade_inr");
    if (cJSON_IsNull(available_to_trade_inr)) {
        available_to_trade_inr = NULL;
    }
    if (available_to_trade_inr) { 
    if(!cJSON_IsNumber(available_to_trade_inr))
    {
    goto end; //Numeric
    }
    available_to_trade_inr_local_var = malloc(sizeof(double));
    if(!available_to_trade_inr_local_var)
    {
        goto end;
    }
    *available_to_trade_inr_local_var = available_to_trade_inr->valuedouble;
    }

    // us_funds_data->available_to_withdraw_inr
    cJSON *available_to_withdraw_inr = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "available_to_withdraw_inr");
    if (cJSON_IsNull(available_to_withdraw_inr)) {
        available_to_withdraw_inr = NULL;
    }
    if (available_to_withdraw_inr) { 
    if(!cJSON_IsNumber(available_to_withdraw_inr))
    {
    goto end; //Numeric
    }
    available_to_withdraw_inr_local_var = malloc(sizeof(double));
    if(!available_to_withdraw_inr_local_var)
    {
        goto end;
    }
    *available_to_withdraw_inr_local_var = available_to_withdraw_inr->valuedouble;
    }

    // us_funds_data->cash_inr
    cJSON *cash_inr = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "cash_inr");
    if (cJSON_IsNull(cash_inr)) {
        cash_inr = NULL;
    }
    if (cash_inr) { 
    if(!cJSON_IsNumber(cash_inr))
    {
    goto end; //Numeric
    }
    cash_inr_local_var = malloc(sizeof(double));
    if(!cash_inr_local_var)
    {
        goto end;
    }
    *cash_inr_local_var = cash_inr->valuedouble;
    }

    // us_funds_data->unsettled_cash_inr
    cJSON *unsettled_cash_inr = cJSON_GetObjectItemCaseSensitive(us_funds_dataJSON, "unsettled_cash_inr");
    if (cJSON_IsNull(unsettled_cash_inr)) {
        unsettled_cash_inr = NULL;
    }
    if (unsettled_cash_inr) { 
    if(!cJSON_IsNumber(unsettled_cash_inr))
    {
    goto end; //Numeric
    }
    unsettled_cash_inr_local_var = malloc(sizeof(double));
    if(!unsettled_cash_inr_local_var)
    {
        goto end;
    }
    *unsettled_cash_inr_local_var = unsettled_cash_inr->valuedouble;
    }



    us_funds_data_local_var = us_funds_data_create_internal (
        cash_local_var,
        available_to_trade_local_var,
        available_to_withdraw_local_var,
        unsettled_cash_local_var,
        exchange_rate_local_var,
        available_to_trade_inr_local_var,
        available_to_withdraw_inr_local_var,
        cash_inr_local_var,
        unsettled_cash_inr_local_var
        );

    if (!us_funds_data_local_var) {
        goto end;
    }

    return us_funds_data_local_var;
end:
    if (cash_local_var) {
        free(cash_local_var);
        cash_local_var = NULL;
    }
    if (available_to_trade_local_var) {
        free(available_to_trade_local_var);
        available_to_trade_local_var = NULL;
    }
    if (available_to_withdraw_local_var) {
        free(available_to_withdraw_local_var);
        available_to_withdraw_local_var = NULL;
    }
    if (unsettled_cash_local_var) {
        free(unsettled_cash_local_var);
        unsettled_cash_local_var = NULL;
    }
    if (exchange_rate_local_var) {
        free(exchange_rate_local_var);
        exchange_rate_local_var = NULL;
    }
    if (available_to_trade_inr_local_var) {
        free(available_to_trade_inr_local_var);
        available_to_trade_inr_local_var = NULL;
    }
    if (available_to_withdraw_inr_local_var) {
        free(available_to_withdraw_inr_local_var);
        available_to_withdraw_inr_local_var = NULL;
    }
    if (cash_inr_local_var) {
        free(cash_inr_local_var);
        cash_inr_local_var = NULL;
    }
    if (unsettled_cash_inr_local_var) {
        free(unsettled_cash_inr_local_var);
        unsettled_cash_inr_local_var = NULL;
    }
    return NULL;

}
