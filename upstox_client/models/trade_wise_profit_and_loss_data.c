#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trade_wise_profit_and_loss_data.h"



static trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_create_internal(
    double *quantity,
    char *isin,
    char *scrip_name,
    char *trade_type,
    char *buy_date,
    double *buy_average,
    char *sell_date,
    double *sell_average,
    double *buy_amount,
    double *sell_amount
    ) {
    trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_local_var = malloc(sizeof(trade_wise_profit_and_loss_data_t));
    if (!trade_wise_profit_and_loss_data_local_var) {
        return NULL;
    }
    memset(trade_wise_profit_and_loss_data_local_var, 0, sizeof(trade_wise_profit_and_loss_data_t));
    trade_wise_profit_and_loss_data_local_var->_library_owned = 1;
    trade_wise_profit_and_loss_data_local_var->quantity = quantity;
    trade_wise_profit_and_loss_data_local_var->isin = isin;
    trade_wise_profit_and_loss_data_local_var->scrip_name = scrip_name;
    trade_wise_profit_and_loss_data_local_var->trade_type = trade_type;
    trade_wise_profit_and_loss_data_local_var->buy_date = buy_date;
    trade_wise_profit_and_loss_data_local_var->buy_average = buy_average;
    trade_wise_profit_and_loss_data_local_var->sell_date = sell_date;
    trade_wise_profit_and_loss_data_local_var->sell_average = sell_average;
    trade_wise_profit_and_loss_data_local_var->buy_amount = buy_amount;
    trade_wise_profit_and_loss_data_local_var->sell_amount = sell_amount;
    return trade_wise_profit_and_loss_data_local_var;
}

trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_create(
    double *quantity,
    char *isin,
    char *scrip_name,
    char *trade_type,
    char *buy_date,
    double *buy_average,
    char *sell_date,
    double *sell_average,
    double *buy_amount,
    double *sell_amount
    ) {
    double *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(double));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *buy_average_copy = NULL;
    if (buy_average) {
        buy_average_copy = malloc(sizeof(double));
        if (buy_average_copy) *buy_average_copy = *buy_average;
    }
    double *sell_average_copy = NULL;
    if (sell_average) {
        sell_average_copy = malloc(sizeof(double));
        if (sell_average_copy) *sell_average_copy = *sell_average;
    }
    double *buy_amount_copy = NULL;
    if (buy_amount) {
        buy_amount_copy = malloc(sizeof(double));
        if (buy_amount_copy) *buy_amount_copy = *buy_amount;
    }
    double *sell_amount_copy = NULL;
    if (sell_amount) {
        sell_amount_copy = malloc(sizeof(double));
        if (sell_amount_copy) *sell_amount_copy = *sell_amount;
    }
    trade_wise_profit_and_loss_data_t *result = trade_wise_profit_and_loss_data_create_internal (
        quantity_copy,
        isin,
        scrip_name,
        trade_type,
        buy_date,
        buy_average_copy,
        sell_date,
        sell_average_copy,
        buy_amount_copy,
        sell_amount_copy
        );
    if (!result) {
        free(quantity_copy);
        free(buy_average_copy);
        free(sell_average_copy);
        free(buy_amount_copy);
        free(sell_amount_copy);
    }
    return result;
}

void trade_wise_profit_and_loss_data_free(trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data) {
    if(NULL == trade_wise_profit_and_loss_data){
        return ;
    }
    if(trade_wise_profit_and_loss_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trade_wise_profit_and_loss_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trade_wise_profit_and_loss_data->quantity) {
        free(trade_wise_profit_and_loss_data->quantity);
        trade_wise_profit_and_loss_data->quantity = NULL;
    }
    if (trade_wise_profit_and_loss_data->isin) {
        free(trade_wise_profit_and_loss_data->isin);
        trade_wise_profit_and_loss_data->isin = NULL;
    }
    if (trade_wise_profit_and_loss_data->scrip_name) {
        free(trade_wise_profit_and_loss_data->scrip_name);
        trade_wise_profit_and_loss_data->scrip_name = NULL;
    }
    if (trade_wise_profit_and_loss_data->trade_type) {
        free(trade_wise_profit_and_loss_data->trade_type);
        trade_wise_profit_and_loss_data->trade_type = NULL;
    }
    if (trade_wise_profit_and_loss_data->buy_date) {
        free(trade_wise_profit_and_loss_data->buy_date);
        trade_wise_profit_and_loss_data->buy_date = NULL;
    }
    if (trade_wise_profit_and_loss_data->buy_average) {
        free(trade_wise_profit_and_loss_data->buy_average);
        trade_wise_profit_and_loss_data->buy_average = NULL;
    }
    if (trade_wise_profit_and_loss_data->sell_date) {
        free(trade_wise_profit_and_loss_data->sell_date);
        trade_wise_profit_and_loss_data->sell_date = NULL;
    }
    if (trade_wise_profit_and_loss_data->sell_average) {
        free(trade_wise_profit_and_loss_data->sell_average);
        trade_wise_profit_and_loss_data->sell_average = NULL;
    }
    if (trade_wise_profit_and_loss_data->buy_amount) {
        free(trade_wise_profit_and_loss_data->buy_amount);
        trade_wise_profit_and_loss_data->buy_amount = NULL;
    }
    if (trade_wise_profit_and_loss_data->sell_amount) {
        free(trade_wise_profit_and_loss_data->sell_amount);
        trade_wise_profit_and_loss_data->sell_amount = NULL;
    }
    free(trade_wise_profit_and_loss_data);
}

cJSON *trade_wise_profit_and_loss_data_convertToJSON(trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data) {
    cJSON *item = cJSON_CreateObject();

    // trade_wise_profit_and_loss_data->quantity
    if(trade_wise_profit_and_loss_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *trade_wise_profit_and_loss_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_wise_profit_and_loss_data->isin
    if(trade_wise_profit_and_loss_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", trade_wise_profit_and_loss_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // trade_wise_profit_and_loss_data->scrip_name
    if(trade_wise_profit_and_loss_data->scrip_name) {
    if(cJSON_AddStringToObject(item, "scrip_name", trade_wise_profit_and_loss_data->scrip_name) == NULL) {
    goto fail; //String
    }
    }


    // trade_wise_profit_and_loss_data->trade_type
    if(trade_wise_profit_and_loss_data->trade_type) {
    if(cJSON_AddStringToObject(item, "trade_type", trade_wise_profit_and_loss_data->trade_type) == NULL) {
    goto fail; //String
    }
    }


    // trade_wise_profit_and_loss_data->buy_date
    if(trade_wise_profit_and_loss_data->buy_date) {
    if(cJSON_AddStringToObject(item, "buy_date", trade_wise_profit_and_loss_data->buy_date) == NULL) {
    goto fail; //String
    }
    }


    // trade_wise_profit_and_loss_data->buy_average
    if(trade_wise_profit_and_loss_data->buy_average) {
    if(cJSON_AddNumberToObject(item, "buy_average", *trade_wise_profit_and_loss_data->buy_average) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_wise_profit_and_loss_data->sell_date
    if(trade_wise_profit_and_loss_data->sell_date) {
    if(cJSON_AddStringToObject(item, "sell_date", trade_wise_profit_and_loss_data->sell_date) == NULL) {
    goto fail; //String
    }
    }


    // trade_wise_profit_and_loss_data->sell_average
    if(trade_wise_profit_and_loss_data->sell_average) {
    if(cJSON_AddNumberToObject(item, "sell_average", *trade_wise_profit_and_loss_data->sell_average) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_wise_profit_and_loss_data->buy_amount
    if(trade_wise_profit_and_loss_data->buy_amount) {
    if(cJSON_AddNumberToObject(item, "buy_amount", *trade_wise_profit_and_loss_data->buy_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // trade_wise_profit_and_loss_data->sell_amount
    if(trade_wise_profit_and_loss_data->sell_amount) {
    if(cJSON_AddNumberToObject(item, "sell_amount", *trade_wise_profit_and_loss_data->sell_amount) == NULL) {
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

trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_parseFromJSON(cJSON *trade_wise_profit_and_loss_dataJSON){

    trade_wise_profit_and_loss_data_t *trade_wise_profit_and_loss_data_local_var = NULL;

    // define the local variable for trade_wise_profit_and_loss_data->quantity
    double *quantity_local_var = NULL;

    char *isin_local_str = NULL;

    char *scrip_name_local_str = NULL;

    char *trade_type_local_str = NULL;

    char *buy_date_local_str = NULL;

    // define the local variable for trade_wise_profit_and_loss_data->buy_average
    double *buy_average_local_var = NULL;

    char *sell_date_local_str = NULL;

    // define the local variable for trade_wise_profit_and_loss_data->sell_average
    double *sell_average_local_var = NULL;

    // define the local variable for trade_wise_profit_and_loss_data->buy_amount
    double *buy_amount_local_var = NULL;

    // define the local variable for trade_wise_profit_and_loss_data->sell_amount
    double *sell_amount_local_var = NULL;

    // trade_wise_profit_and_loss_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(double));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // trade_wise_profit_and_loss_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // trade_wise_profit_and_loss_data->scrip_name
    cJSON *scrip_name = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "scrip_name");
    if (cJSON_IsNull(scrip_name)) {
        scrip_name = NULL;
    }
    if (scrip_name) { 
    if(!cJSON_IsString(scrip_name) && !cJSON_IsNull(scrip_name))
    {
    goto end; //String
    }
    }

    // trade_wise_profit_and_loss_data->trade_type
    cJSON *trade_type = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "trade_type");
    if (cJSON_IsNull(trade_type)) {
        trade_type = NULL;
    }
    if (trade_type) { 
    if(!cJSON_IsString(trade_type) && !cJSON_IsNull(trade_type))
    {
    goto end; //String
    }
    }

    // trade_wise_profit_and_loss_data->buy_date
    cJSON *buy_date = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "buy_date");
    if (cJSON_IsNull(buy_date)) {
        buy_date = NULL;
    }
    if (buy_date) { 
    if(!cJSON_IsString(buy_date) && !cJSON_IsNull(buy_date))
    {
    goto end; //String
    }
    }

    // trade_wise_profit_and_loss_data->buy_average
    cJSON *buy_average = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "buy_average");
    if (cJSON_IsNull(buy_average)) {
        buy_average = NULL;
    }
    if (buy_average) { 
    if(!cJSON_IsNumber(buy_average))
    {
    goto end; //Numeric
    }
    buy_average_local_var = malloc(sizeof(double));
    if(!buy_average_local_var)
    {
        goto end;
    }
    *buy_average_local_var = buy_average->valuedouble;
    }

    // trade_wise_profit_and_loss_data->sell_date
    cJSON *sell_date = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "sell_date");
    if (cJSON_IsNull(sell_date)) {
        sell_date = NULL;
    }
    if (sell_date) { 
    if(!cJSON_IsString(sell_date) && !cJSON_IsNull(sell_date))
    {
    goto end; //String
    }
    }

    // trade_wise_profit_and_loss_data->sell_average
    cJSON *sell_average = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "sell_average");
    if (cJSON_IsNull(sell_average)) {
        sell_average = NULL;
    }
    if (sell_average) { 
    if(!cJSON_IsNumber(sell_average))
    {
    goto end; //Numeric
    }
    sell_average_local_var = malloc(sizeof(double));
    if(!sell_average_local_var)
    {
        goto end;
    }
    *sell_average_local_var = sell_average->valuedouble;
    }

    // trade_wise_profit_and_loss_data->buy_amount
    cJSON *buy_amount = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "buy_amount");
    if (cJSON_IsNull(buy_amount)) {
        buy_amount = NULL;
    }
    if (buy_amount) { 
    if(!cJSON_IsNumber(buy_amount))
    {
    goto end; //Numeric
    }
    buy_amount_local_var = malloc(sizeof(double));
    if(!buy_amount_local_var)
    {
        goto end;
    }
    *buy_amount_local_var = buy_amount->valuedouble;
    }

    // trade_wise_profit_and_loss_data->sell_amount
    cJSON *sell_amount = cJSON_GetObjectItemCaseSensitive(trade_wise_profit_and_loss_dataJSON, "sell_amount");
    if (cJSON_IsNull(sell_amount)) {
        sell_amount = NULL;
    }
    if (sell_amount) { 
    if(!cJSON_IsNumber(sell_amount))
    {
    goto end; //Numeric
    }
    sell_amount_local_var = malloc(sizeof(double));
    if(!sell_amount_local_var)
    {
        goto end;
    }
    *sell_amount_local_var = sell_amount->valuedouble;
    }


    if (isin && !cJSON_IsNull(isin)) isin_local_str = strdup(isin->valuestring);
    if (scrip_name && !cJSON_IsNull(scrip_name)) scrip_name_local_str = strdup(scrip_name->valuestring);
    if (trade_type && !cJSON_IsNull(trade_type)) trade_type_local_str = strdup(trade_type->valuestring);
    if (buy_date && !cJSON_IsNull(buy_date)) buy_date_local_str = strdup(buy_date->valuestring);
    if (sell_date && !cJSON_IsNull(sell_date)) sell_date_local_str = strdup(sell_date->valuestring);

    trade_wise_profit_and_loss_data_local_var = trade_wise_profit_and_loss_data_create_internal (
        quantity_local_var,
        isin_local_str,
        scrip_name_local_str,
        trade_type_local_str,
        buy_date_local_str,
        buy_average_local_var,
        sell_date_local_str,
        sell_average_local_var,
        buy_amount_local_var,
        sell_amount_local_var
        );

    if (!trade_wise_profit_and_loss_data_local_var) {
        goto end;
    }

    return trade_wise_profit_and_loss_data_local_var;
end:
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (isin_local_str) {
        free(isin_local_str);
        isin_local_str = NULL;
    }
    if (scrip_name_local_str) {
        free(scrip_name_local_str);
        scrip_name_local_str = NULL;
    }
    if (trade_type_local_str) {
        free(trade_type_local_str);
        trade_type_local_str = NULL;
    }
    if (buy_date_local_str) {
        free(buy_date_local_str);
        buy_date_local_str = NULL;
    }
    if (buy_average_local_var) {
        free(buy_average_local_var);
        buy_average_local_var = NULL;
    }
    if (sell_date_local_str) {
        free(sell_date_local_str);
        sell_date_local_str = NULL;
    }
    if (sell_average_local_var) {
        free(sell_average_local_var);
        sell_average_local_var = NULL;
    }
    if (buy_amount_local_var) {
        free(buy_amount_local_var);
        buy_amount_local_var = NULL;
    }
    if (sell_amount_local_var) {
        free(sell_amount_local_var);
        sell_amount_local_var = NULL;
    }
    return NULL;

}
