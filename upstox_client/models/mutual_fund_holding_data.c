#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mutual_fund_holding_data.h"



static mutual_fund_holding_data_t *mutual_fund_holding_data_create_internal(
    char *folio,
    char *fund,
    double *pnl,
    double *quantity,
    char *instrument_key,
    double *average_price,
    double *last_price,
    char *last_price_date,
    double *pledged_quantity
    ) {
    mutual_fund_holding_data_t *mutual_fund_holding_data_local_var = malloc(sizeof(mutual_fund_holding_data_t));
    if (!mutual_fund_holding_data_local_var) {
        return NULL;
    }
    memset(mutual_fund_holding_data_local_var, 0, sizeof(mutual_fund_holding_data_t));
    mutual_fund_holding_data_local_var->_library_owned = 1;
    mutual_fund_holding_data_local_var->folio = folio;
    mutual_fund_holding_data_local_var->fund = fund;
    mutual_fund_holding_data_local_var->pnl = pnl;
    mutual_fund_holding_data_local_var->quantity = quantity;
    mutual_fund_holding_data_local_var->instrument_key = instrument_key;
    mutual_fund_holding_data_local_var->average_price = average_price;
    mutual_fund_holding_data_local_var->last_price = last_price;
    mutual_fund_holding_data_local_var->last_price_date = last_price_date;
    mutual_fund_holding_data_local_var->pledged_quantity = pledged_quantity;
    return mutual_fund_holding_data_local_var;
}

mutual_fund_holding_data_t *mutual_fund_holding_data_create(
    char *folio,
    char *fund,
    double *pnl,
    double *quantity,
    char *instrument_key,
    double *average_price,
    double *last_price,
    char *last_price_date,
    double *pledged_quantity
    ) {
    double *pnl_copy = NULL;
    if (pnl) {
        pnl_copy = malloc(sizeof(double));
        if (pnl_copy) *pnl_copy = *pnl;
    }
    double *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(double));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    double *pledged_quantity_copy = NULL;
    if (pledged_quantity) {
        pledged_quantity_copy = malloc(sizeof(double));
        if (pledged_quantity_copy) *pledged_quantity_copy = *pledged_quantity;
    }
    mutual_fund_holding_data_t *result = mutual_fund_holding_data_create_internal (
        folio,
        fund,
        pnl_copy,
        quantity_copy,
        instrument_key,
        average_price_copy,
        last_price_copy,
        last_price_date,
        pledged_quantity_copy
        );
    if (!result) {
        free(pnl_copy);
        free(quantity_copy);
        free(average_price_copy);
        free(last_price_copy);
        free(pledged_quantity_copy);
    }
    return result;
}

void mutual_fund_holding_data_free(mutual_fund_holding_data_t *mutual_fund_holding_data) {
    if(NULL == mutual_fund_holding_data){
        return ;
    }
    if(mutual_fund_holding_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mutual_fund_holding_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mutual_fund_holding_data->folio) {
        free(mutual_fund_holding_data->folio);
        mutual_fund_holding_data->folio = NULL;
    }
    if (mutual_fund_holding_data->fund) {
        free(mutual_fund_holding_data->fund);
        mutual_fund_holding_data->fund = NULL;
    }
    if (mutual_fund_holding_data->pnl) {
        free(mutual_fund_holding_data->pnl);
        mutual_fund_holding_data->pnl = NULL;
    }
    if (mutual_fund_holding_data->quantity) {
        free(mutual_fund_holding_data->quantity);
        mutual_fund_holding_data->quantity = NULL;
    }
    if (mutual_fund_holding_data->instrument_key) {
        free(mutual_fund_holding_data->instrument_key);
        mutual_fund_holding_data->instrument_key = NULL;
    }
    if (mutual_fund_holding_data->average_price) {
        free(mutual_fund_holding_data->average_price);
        mutual_fund_holding_data->average_price = NULL;
    }
    if (mutual_fund_holding_data->last_price) {
        free(mutual_fund_holding_data->last_price);
        mutual_fund_holding_data->last_price = NULL;
    }
    if (mutual_fund_holding_data->last_price_date) {
        free(mutual_fund_holding_data->last_price_date);
        mutual_fund_holding_data->last_price_date = NULL;
    }
    if (mutual_fund_holding_data->pledged_quantity) {
        free(mutual_fund_holding_data->pledged_quantity);
        mutual_fund_holding_data->pledged_quantity = NULL;
    }
    free(mutual_fund_holding_data);
}

cJSON *mutual_fund_holding_data_convertToJSON(mutual_fund_holding_data_t *mutual_fund_holding_data) {
    cJSON *item = cJSON_CreateObject();

    // mutual_fund_holding_data->folio
    if(mutual_fund_holding_data->folio) {
    if(cJSON_AddStringToObject(item, "folio", mutual_fund_holding_data->folio) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_holding_data->fund
    if(mutual_fund_holding_data->fund) {
    if(cJSON_AddStringToObject(item, "fund", mutual_fund_holding_data->fund) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_holding_data->pnl
    if(mutual_fund_holding_data->pnl) {
    if(cJSON_AddNumberToObject(item, "pnl", *mutual_fund_holding_data->pnl) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_holding_data->quantity
    if(mutual_fund_holding_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *mutual_fund_holding_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_holding_data->instrument_key
    if(mutual_fund_holding_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", mutual_fund_holding_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_holding_data->average_price
    if(mutual_fund_holding_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *mutual_fund_holding_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_holding_data->last_price
    if(mutual_fund_holding_data->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *mutual_fund_holding_data->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_holding_data->last_price_date
    if(mutual_fund_holding_data->last_price_date) {
    if(cJSON_AddStringToObject(item, "last_price_date", mutual_fund_holding_data->last_price_date) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_holding_data->pledged_quantity
    if(mutual_fund_holding_data->pledged_quantity) {
    if(cJSON_AddNumberToObject(item, "pledged_quantity", *mutual_fund_holding_data->pledged_quantity) == NULL) {
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

mutual_fund_holding_data_t *mutual_fund_holding_data_parseFromJSON(cJSON *mutual_fund_holding_dataJSON){

    mutual_fund_holding_data_t *mutual_fund_holding_data_local_var = NULL;

    char *folio_local_str = NULL;

    char *fund_local_str = NULL;

    // define the local variable for mutual_fund_holding_data->pnl
    double *pnl_local_var = NULL;

    // define the local variable for mutual_fund_holding_data->quantity
    double *quantity_local_var = NULL;

    char *instrument_key_local_str = NULL;

    // define the local variable for mutual_fund_holding_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for mutual_fund_holding_data->last_price
    double *last_price_local_var = NULL;

    char *last_price_date_local_str = NULL;

    // define the local variable for mutual_fund_holding_data->pledged_quantity
    double *pledged_quantity_local_var = NULL;

    // mutual_fund_holding_data->folio
    cJSON *folio = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "folio");
    if (cJSON_IsNull(folio)) {
        folio = NULL;
    }
    if (folio) { 
    if(!cJSON_IsString(folio) && !cJSON_IsNull(folio))
    {
    goto end; //String
    }
    }

    // mutual_fund_holding_data->fund
    cJSON *fund = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "fund");
    if (cJSON_IsNull(fund)) {
        fund = NULL;
    }
    if (fund) { 
    if(!cJSON_IsString(fund) && !cJSON_IsNull(fund))
    {
    goto end; //String
    }
    }

    // mutual_fund_holding_data->pnl
    cJSON *pnl = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "pnl");
    if (cJSON_IsNull(pnl)) {
        pnl = NULL;
    }
    if (pnl) { 
    if(!cJSON_IsNumber(pnl))
    {
    goto end; //Numeric
    }
    pnl_local_var = malloc(sizeof(double));
    if(!pnl_local_var)
    {
        goto end;
    }
    *pnl_local_var = pnl->valuedouble;
    }

    // mutual_fund_holding_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "quantity");
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

    // mutual_fund_holding_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // mutual_fund_holding_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "average_price");
    if (cJSON_IsNull(average_price)) {
        average_price = NULL;
    }
    if (average_price) { 
    if(!cJSON_IsNumber(average_price))
    {
    goto end; //Numeric
    }
    average_price_local_var = malloc(sizeof(double));
    if(!average_price_local_var)
    {
        goto end;
    }
    *average_price_local_var = average_price->valuedouble;
    }

    // mutual_fund_holding_data->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "last_price");
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

    // mutual_fund_holding_data->last_price_date
    cJSON *last_price_date = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "last_price_date");
    if (cJSON_IsNull(last_price_date)) {
        last_price_date = NULL;
    }
    if (last_price_date) { 
    if(!cJSON_IsString(last_price_date) && !cJSON_IsNull(last_price_date))
    {
    goto end; //String
    }
    }

    // mutual_fund_holding_data->pledged_quantity
    cJSON *pledged_quantity = cJSON_GetObjectItemCaseSensitive(mutual_fund_holding_dataJSON, "pledged_quantity");
    if (cJSON_IsNull(pledged_quantity)) {
        pledged_quantity = NULL;
    }
    if (pledged_quantity) { 
    if(!cJSON_IsNumber(pledged_quantity))
    {
    goto end; //Numeric
    }
    pledged_quantity_local_var = malloc(sizeof(double));
    if(!pledged_quantity_local_var)
    {
        goto end;
    }
    *pledged_quantity_local_var = pledged_quantity->valuedouble;
    }


    if (folio && !cJSON_IsNull(folio)) folio_local_str = strdup(folio->valuestring);
    if (fund && !cJSON_IsNull(fund)) fund_local_str = strdup(fund->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (last_price_date && !cJSON_IsNull(last_price_date)) last_price_date_local_str = strdup(last_price_date->valuestring);

    mutual_fund_holding_data_local_var = mutual_fund_holding_data_create_internal (
        folio_local_str,
        fund_local_str,
        pnl_local_var,
        quantity_local_var,
        instrument_key_local_str,
        average_price_local_var,
        last_price_local_var,
        last_price_date_local_str,
        pledged_quantity_local_var
        );

    if (!mutual_fund_holding_data_local_var) {
        goto end;
    }

    return mutual_fund_holding_data_local_var;
end:
    if (folio_local_str) {
        free(folio_local_str);
        folio_local_str = NULL;
    }
    if (fund_local_str) {
        free(fund_local_str);
        fund_local_str = NULL;
    }
    if (pnl_local_var) {
        free(pnl_local_var);
        pnl_local_var = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (last_price_date_local_str) {
        free(last_price_date_local_str);
        last_price_date_local_str = NULL;
    }
    if (pledged_quantity_local_var) {
        free(pledged_quantity_local_var);
        pledged_quantity_local_var = NULL;
    }
    return NULL;

}
