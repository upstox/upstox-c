#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "holdings_data.h"


char* holdings_data_exchange_ToString(upstox_client_holdings_data_EXCHANGE_e exchange) {
    char* exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangeArray[exchange];
}

upstox_client_holdings_data_EXCHANGE_e holdings_data_exchange_FromString(char* exchange){
    int stringToReturn = 0;
    char *exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    size_t sizeofArray = sizeof(exchangeArray) / sizeof(exchangeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(exchange, exchangeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static holdings_data_t *holdings_data_create_internal(
    char *isin,
    int *cnc_used_quantity,
    char *collateral_type,
    char *company_name,
    double *haircut,
    char *product,
    int *quantity,
    char *tradingsymbol,
    double *last_price,
    double *close_price,
    double *pnl,
    double *day_change,
    double *day_change_percentage,
    char *instrument_token,
    double *average_price,
    int *collateral_quantity,
    int *collateral_update_quantity,
    char *trading_symbol,
    int *t1_quantity,
    upstox_client_holdings_data_EXCHANGE_e exchange
    ) {
    holdings_data_t *holdings_data_local_var = malloc(sizeof(holdings_data_t));
    if (!holdings_data_local_var) {
        return NULL;
    }
    memset(holdings_data_local_var, 0, sizeof(holdings_data_t));
    holdings_data_local_var->_library_owned = 1;
    holdings_data_local_var->isin = isin;
    holdings_data_local_var->cnc_used_quantity = cnc_used_quantity;
    holdings_data_local_var->collateral_type = collateral_type;
    holdings_data_local_var->company_name = company_name;
    holdings_data_local_var->haircut = haircut;
    holdings_data_local_var->product = product;
    holdings_data_local_var->quantity = quantity;
    holdings_data_local_var->tradingsymbol = tradingsymbol;
    holdings_data_local_var->last_price = last_price;
    holdings_data_local_var->close_price = close_price;
    holdings_data_local_var->pnl = pnl;
    holdings_data_local_var->day_change = day_change;
    holdings_data_local_var->day_change_percentage = day_change_percentage;
    holdings_data_local_var->instrument_token = instrument_token;
    holdings_data_local_var->average_price = average_price;
    holdings_data_local_var->collateral_quantity = collateral_quantity;
    holdings_data_local_var->collateral_update_quantity = collateral_update_quantity;
    holdings_data_local_var->trading_symbol = trading_symbol;
    holdings_data_local_var->t1_quantity = t1_quantity;
    holdings_data_local_var->exchange = exchange;
    return holdings_data_local_var;
}

holdings_data_t *holdings_data_create(
    char *isin,
    int *cnc_used_quantity,
    char *collateral_type,
    char *company_name,
    double *haircut,
    char *product,
    int *quantity,
    char *tradingsymbol,
    double *last_price,
    double *close_price,
    double *pnl,
    double *day_change,
    double *day_change_percentage,
    char *instrument_token,
    double *average_price,
    int *collateral_quantity,
    int *collateral_update_quantity,
    char *trading_symbol,
    int *t1_quantity,
    upstox_client_holdings_data_EXCHANGE_e exchange
    ) {
    int *cnc_used_quantity_copy = NULL;
    if (cnc_used_quantity) {
        cnc_used_quantity_copy = malloc(sizeof(int));
        if (cnc_used_quantity_copy) *cnc_used_quantity_copy = *cnc_used_quantity;
    }
    double *haircut_copy = NULL;
    if (haircut) {
        haircut_copy = malloc(sizeof(double));
        if (haircut_copy) *haircut_copy = *haircut;
    }
    int *quantity_copy = NULL;
    if (quantity) {
        quantity_copy = malloc(sizeof(int));
        if (quantity_copy) *quantity_copy = *quantity;
    }
    double *last_price_copy = NULL;
    if (last_price) {
        last_price_copy = malloc(sizeof(double));
        if (last_price_copy) *last_price_copy = *last_price;
    }
    double *close_price_copy = NULL;
    if (close_price) {
        close_price_copy = malloc(sizeof(double));
        if (close_price_copy) *close_price_copy = *close_price;
    }
    double *pnl_copy = NULL;
    if (pnl) {
        pnl_copy = malloc(sizeof(double));
        if (pnl_copy) *pnl_copy = *pnl;
    }
    double *day_change_copy = NULL;
    if (day_change) {
        day_change_copy = malloc(sizeof(double));
        if (day_change_copy) *day_change_copy = *day_change;
    }
    double *day_change_percentage_copy = NULL;
    if (day_change_percentage) {
        day_change_percentage_copy = malloc(sizeof(double));
        if (day_change_percentage_copy) *day_change_percentage_copy = *day_change_percentage;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    int *collateral_quantity_copy = NULL;
    if (collateral_quantity) {
        collateral_quantity_copy = malloc(sizeof(int));
        if (collateral_quantity_copy) *collateral_quantity_copy = *collateral_quantity;
    }
    int *collateral_update_quantity_copy = NULL;
    if (collateral_update_quantity) {
        collateral_update_quantity_copy = malloc(sizeof(int));
        if (collateral_update_quantity_copy) *collateral_update_quantity_copy = *collateral_update_quantity;
    }
    int *t1_quantity_copy = NULL;
    if (t1_quantity) {
        t1_quantity_copy = malloc(sizeof(int));
        if (t1_quantity_copy) *t1_quantity_copy = *t1_quantity;
    }
    holdings_data_t *result = holdings_data_create_internal (
        isin,
        cnc_used_quantity_copy,
        collateral_type,
        company_name,
        haircut_copy,
        product,
        quantity_copy,
        tradingsymbol,
        last_price_copy,
        close_price_copy,
        pnl_copy,
        day_change_copy,
        day_change_percentage_copy,
        instrument_token,
        average_price_copy,
        collateral_quantity_copy,
        collateral_update_quantity_copy,
        trading_symbol,
        t1_quantity_copy,
        exchange
        );
    if (!result) {
        free(cnc_used_quantity_copy);
        free(haircut_copy);
        free(quantity_copy);
        free(last_price_copy);
        free(close_price_copy);
        free(pnl_copy);
        free(day_change_copy);
        free(day_change_percentage_copy);
        free(average_price_copy);
        free(collateral_quantity_copy);
        free(collateral_update_quantity_copy);
        free(t1_quantity_copy);
    }
    return result;
}

void holdings_data_free(holdings_data_t *holdings_data) {
    if(NULL == holdings_data){
        return ;
    }
    if(holdings_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "holdings_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (holdings_data->isin) {
        free(holdings_data->isin);
        holdings_data->isin = NULL;
    }
    if (holdings_data->cnc_used_quantity) {
        free(holdings_data->cnc_used_quantity);
        holdings_data->cnc_used_quantity = NULL;
    }
    if (holdings_data->collateral_type) {
        free(holdings_data->collateral_type);
        holdings_data->collateral_type = NULL;
    }
    if (holdings_data->company_name) {
        free(holdings_data->company_name);
        holdings_data->company_name = NULL;
    }
    if (holdings_data->haircut) {
        free(holdings_data->haircut);
        holdings_data->haircut = NULL;
    }
    if (holdings_data->product) {
        free(holdings_data->product);
        holdings_data->product = NULL;
    }
    if (holdings_data->quantity) {
        free(holdings_data->quantity);
        holdings_data->quantity = NULL;
    }
    if (holdings_data->tradingsymbol) {
        free(holdings_data->tradingsymbol);
        holdings_data->tradingsymbol = NULL;
    }
    if (holdings_data->last_price) {
        free(holdings_data->last_price);
        holdings_data->last_price = NULL;
    }
    if (holdings_data->close_price) {
        free(holdings_data->close_price);
        holdings_data->close_price = NULL;
    }
    if (holdings_data->pnl) {
        free(holdings_data->pnl);
        holdings_data->pnl = NULL;
    }
    if (holdings_data->day_change) {
        free(holdings_data->day_change);
        holdings_data->day_change = NULL;
    }
    if (holdings_data->day_change_percentage) {
        free(holdings_data->day_change_percentage);
        holdings_data->day_change_percentage = NULL;
    }
    if (holdings_data->instrument_token) {
        free(holdings_data->instrument_token);
        holdings_data->instrument_token = NULL;
    }
    if (holdings_data->average_price) {
        free(holdings_data->average_price);
        holdings_data->average_price = NULL;
    }
    if (holdings_data->collateral_quantity) {
        free(holdings_data->collateral_quantity);
        holdings_data->collateral_quantity = NULL;
    }
    if (holdings_data->collateral_update_quantity) {
        free(holdings_data->collateral_update_quantity);
        holdings_data->collateral_update_quantity = NULL;
    }
    if (holdings_data->trading_symbol) {
        free(holdings_data->trading_symbol);
        holdings_data->trading_symbol = NULL;
    }
    if (holdings_data->t1_quantity) {
        free(holdings_data->t1_quantity);
        holdings_data->t1_quantity = NULL;
    }
    free(holdings_data);
}

cJSON *holdings_data_convertToJSON(holdings_data_t *holdings_data) {
    cJSON *item = cJSON_CreateObject();

    // holdings_data->isin
    if(holdings_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", holdings_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->cnc_used_quantity
    if(holdings_data->cnc_used_quantity) {
    if(cJSON_AddNumberToObject(item, "cnc_used_quantity", *holdings_data->cnc_used_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->collateral_type
    if(holdings_data->collateral_type) {
    if(cJSON_AddStringToObject(item, "collateral_type", holdings_data->collateral_type) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->company_name
    if(holdings_data->company_name) {
    if(cJSON_AddStringToObject(item, "company_name", holdings_data->company_name) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->haircut
    if(holdings_data->haircut) {
    if(cJSON_AddNumberToObject(item, "haircut", *holdings_data->haircut) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->product
    if(holdings_data->product) {
    if(cJSON_AddStringToObject(item, "product", holdings_data->product) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->quantity
    if(holdings_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *holdings_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->tradingsymbol
    if(holdings_data->tradingsymbol) {
    if(cJSON_AddStringToObject(item, "tradingsymbol", holdings_data->tradingsymbol) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->last_price
    if(holdings_data->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *holdings_data->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->close_price
    if(holdings_data->close_price) {
    if(cJSON_AddNumberToObject(item, "close_price", *holdings_data->close_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->pnl
    if(holdings_data->pnl) {
    if(cJSON_AddNumberToObject(item, "pnl", *holdings_data->pnl) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->day_change
    if(holdings_data->day_change) {
    if(cJSON_AddNumberToObject(item, "day_change", *holdings_data->day_change) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->day_change_percentage
    if(holdings_data->day_change_percentage) {
    if(cJSON_AddNumberToObject(item, "day_change_percentage", *holdings_data->day_change_percentage) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->instrument_token
    if(holdings_data->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", holdings_data->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->average_price
    if(holdings_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *holdings_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->collateral_quantity
    if(holdings_data->collateral_quantity) {
    if(cJSON_AddNumberToObject(item, "collateral_quantity", *holdings_data->collateral_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->collateral_update_quantity
    if(holdings_data->collateral_update_quantity) {
    if(cJSON_AddNumberToObject(item, "collateral_update_quantity", *holdings_data->collateral_update_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->trading_symbol
    if(holdings_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", holdings_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // holdings_data->t1_quantity
    if(holdings_data->t1_quantity) {
    if(cJSON_AddNumberToObject(item, "t1_quantity", *holdings_data->t1_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // holdings_data->exchange
    if(holdings_data->exchange != upstox_client_holdings_data_EXCHANGE_NULL) {
    if(cJSON_AddStringToObject(item, "exchange", holdings_data_exchange_ToString(holdings_data->exchange)) == NULL)
    {
    goto fail; //Enum
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

holdings_data_t *holdings_data_parseFromJSON(cJSON *holdings_dataJSON){

    holdings_data_t *holdings_data_local_var = NULL;

    char *isin_local_str = NULL;

    // define the local variable for holdings_data->cnc_used_quantity
    int *cnc_used_quantity_local_var = NULL;

    char *collateral_type_local_str = NULL;

    char *company_name_local_str = NULL;

    // define the local variable for holdings_data->haircut
    double *haircut_local_var = NULL;

    char *product_local_str = NULL;

    // define the local variable for holdings_data->quantity
    int *quantity_local_var = NULL;

    char *tradingsymbol_local_str = NULL;

    // define the local variable for holdings_data->last_price
    double *last_price_local_var = NULL;

    // define the local variable for holdings_data->close_price
    double *close_price_local_var = NULL;

    // define the local variable for holdings_data->pnl
    double *pnl_local_var = NULL;

    // define the local variable for holdings_data->day_change
    double *day_change_local_var = NULL;

    // define the local variable for holdings_data->day_change_percentage
    double *day_change_percentage_local_var = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for holdings_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for holdings_data->collateral_quantity
    int *collateral_quantity_local_var = NULL;

    // define the local variable for holdings_data->collateral_update_quantity
    int *collateral_update_quantity_local_var = NULL;

    char *trading_symbol_local_str = NULL;

    // define the local variable for holdings_data->t1_quantity
    int *t1_quantity_local_var = NULL;

    // holdings_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // holdings_data->cnc_used_quantity
    cJSON *cnc_used_quantity = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "cnc_used_quantity");
    if (cJSON_IsNull(cnc_used_quantity)) {
        cnc_used_quantity = NULL;
    }
    if (cnc_used_quantity) { 
    if(!cJSON_IsNumber(cnc_used_quantity))
    {
    goto end; //Numeric
    }
    cnc_used_quantity_local_var = malloc(sizeof(int));
    if(!cnc_used_quantity_local_var)
    {
        goto end;
    }
    *cnc_used_quantity_local_var = cnc_used_quantity->valuedouble;
    }

    // holdings_data->collateral_type
    cJSON *collateral_type = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "collateral_type");
    if (cJSON_IsNull(collateral_type)) {
        collateral_type = NULL;
    }
    if (collateral_type) { 
    if(!cJSON_IsString(collateral_type) && !cJSON_IsNull(collateral_type))
    {
    goto end; //String
    }
    }

    // holdings_data->company_name
    cJSON *company_name = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "company_name");
    if (cJSON_IsNull(company_name)) {
        company_name = NULL;
    }
    if (company_name) { 
    if(!cJSON_IsString(company_name) && !cJSON_IsNull(company_name))
    {
    goto end; //String
    }
    }

    // holdings_data->haircut
    cJSON *haircut = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "haircut");
    if (cJSON_IsNull(haircut)) {
        haircut = NULL;
    }
    if (haircut) { 
    if(!cJSON_IsNumber(haircut))
    {
    goto end; //Numeric
    }
    haircut_local_var = malloc(sizeof(double));
    if(!haircut_local_var)
    {
        goto end;
    }
    *haircut_local_var = haircut->valuedouble;
    }

    // holdings_data->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }

    // holdings_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "quantity");
    if (cJSON_IsNull(quantity)) {
        quantity = NULL;
    }
    if (quantity) { 
    if(!cJSON_IsNumber(quantity))
    {
    goto end; //Numeric
    }
    quantity_local_var = malloc(sizeof(int));
    if(!quantity_local_var)
    {
        goto end;
    }
    *quantity_local_var = quantity->valuedouble;
    }

    // holdings_data->tradingsymbol
    cJSON *tradingsymbol = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "tradingsymbol");
    if (cJSON_IsNull(tradingsymbol)) {
        tradingsymbol = NULL;
    }
    if (tradingsymbol) { 
    if(!cJSON_IsString(tradingsymbol) && !cJSON_IsNull(tradingsymbol))
    {
    goto end; //String
    }
    }

    // holdings_data->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "last_price");
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

    // holdings_data->close_price
    cJSON *close_price = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "close_price");
    if (cJSON_IsNull(close_price)) {
        close_price = NULL;
    }
    if (close_price) { 
    if(!cJSON_IsNumber(close_price))
    {
    goto end; //Numeric
    }
    close_price_local_var = malloc(sizeof(double));
    if(!close_price_local_var)
    {
        goto end;
    }
    *close_price_local_var = close_price->valuedouble;
    }

    // holdings_data->pnl
    cJSON *pnl = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "pnl");
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

    // holdings_data->day_change
    cJSON *day_change = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "day_change");
    if (cJSON_IsNull(day_change)) {
        day_change = NULL;
    }
    if (day_change) { 
    if(!cJSON_IsNumber(day_change))
    {
    goto end; //Numeric
    }
    day_change_local_var = malloc(sizeof(double));
    if(!day_change_local_var)
    {
        goto end;
    }
    *day_change_local_var = day_change->valuedouble;
    }

    // holdings_data->day_change_percentage
    cJSON *day_change_percentage = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "day_change_percentage");
    if (cJSON_IsNull(day_change_percentage)) {
        day_change_percentage = NULL;
    }
    if (day_change_percentage) { 
    if(!cJSON_IsNumber(day_change_percentage))
    {
    goto end; //Numeric
    }
    day_change_percentage_local_var = malloc(sizeof(double));
    if(!day_change_percentage_local_var)
    {
        goto end;
    }
    *day_change_percentage_local_var = day_change_percentage->valuedouble;
    }

    // holdings_data->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // holdings_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "average_price");
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

    // holdings_data->collateral_quantity
    cJSON *collateral_quantity = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "collateral_quantity");
    if (cJSON_IsNull(collateral_quantity)) {
        collateral_quantity = NULL;
    }
    if (collateral_quantity) { 
    if(!cJSON_IsNumber(collateral_quantity))
    {
    goto end; //Numeric
    }
    collateral_quantity_local_var = malloc(sizeof(int));
    if(!collateral_quantity_local_var)
    {
        goto end;
    }
    *collateral_quantity_local_var = collateral_quantity->valuedouble;
    }

    // holdings_data->collateral_update_quantity
    cJSON *collateral_update_quantity = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "collateral_update_quantity");
    if (cJSON_IsNull(collateral_update_quantity)) {
        collateral_update_quantity = NULL;
    }
    if (collateral_update_quantity) { 
    if(!cJSON_IsNumber(collateral_update_quantity))
    {
    goto end; //Numeric
    }
    collateral_update_quantity_local_var = malloc(sizeof(int));
    if(!collateral_update_quantity_local_var)
    {
        goto end;
    }
    *collateral_update_quantity_local_var = collateral_update_quantity->valuedouble;
    }

    // holdings_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // holdings_data->t1_quantity
    cJSON *t1_quantity = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "t1_quantity");
    if (cJSON_IsNull(t1_quantity)) {
        t1_quantity = NULL;
    }
    if (t1_quantity) { 
    if(!cJSON_IsNumber(t1_quantity))
    {
    goto end; //Numeric
    }
    t1_quantity_local_var = malloc(sizeof(int));
    if(!t1_quantity_local_var)
    {
        goto end;
    }
    *t1_quantity_local_var = t1_quantity->valuedouble;
    }

    // holdings_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(holdings_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    upstox_client_holdings_data_EXCHANGE_e exchangeVariable;
    if (exchange) { 
    if(!cJSON_IsString(exchange))
    {
    goto end; //Enum
    }
    exchangeVariable = holdings_data_exchange_FromString(exchange->valuestring);
    }


    if (isin && !cJSON_IsNull(isin)) isin_local_str = strdup(isin->valuestring);
    if (collateral_type && !cJSON_IsNull(collateral_type)) collateral_type_local_str = strdup(collateral_type->valuestring);
    if (company_name && !cJSON_IsNull(company_name)) company_name_local_str = strdup(company_name->valuestring);
    if (product && !cJSON_IsNull(product)) product_local_str = strdup(product->valuestring);
    if (tradingsymbol && !cJSON_IsNull(tradingsymbol)) tradingsymbol_local_str = strdup(tradingsymbol->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);

    holdings_data_local_var = holdings_data_create_internal (
        isin_local_str,
        cnc_used_quantity_local_var,
        collateral_type_local_str,
        company_name_local_str,
        haircut_local_var,
        product_local_str,
        quantity_local_var,
        tradingsymbol_local_str,
        last_price_local_var,
        close_price_local_var,
        pnl_local_var,
        day_change_local_var,
        day_change_percentage_local_var,
        instrument_token_local_str,
        average_price_local_var,
        collateral_quantity_local_var,
        collateral_update_quantity_local_var,
        trading_symbol_local_str,
        t1_quantity_local_var,
        exchange ? exchangeVariable : upstox_client_holdings_data_EXCHANGE_NULL
        );

    if (!holdings_data_local_var) {
        goto end;
    }

    return holdings_data_local_var;
end:
    if (isin_local_str) {
        free(isin_local_str);
        isin_local_str = NULL;
    }
    if (cnc_used_quantity_local_var) {
        free(cnc_used_quantity_local_var);
        cnc_used_quantity_local_var = NULL;
    }
    if (collateral_type_local_str) {
        free(collateral_type_local_str);
        collateral_type_local_str = NULL;
    }
    if (company_name_local_str) {
        free(company_name_local_str);
        company_name_local_str = NULL;
    }
    if (haircut_local_var) {
        free(haircut_local_var);
        haircut_local_var = NULL;
    }
    if (product_local_str) {
        free(product_local_str);
        product_local_str = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (tradingsymbol_local_str) {
        free(tradingsymbol_local_str);
        tradingsymbol_local_str = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (close_price_local_var) {
        free(close_price_local_var);
        close_price_local_var = NULL;
    }
    if (pnl_local_var) {
        free(pnl_local_var);
        pnl_local_var = NULL;
    }
    if (day_change_local_var) {
        free(day_change_local_var);
        day_change_local_var = NULL;
    }
    if (day_change_percentage_local_var) {
        free(day_change_percentage_local_var);
        day_change_percentage_local_var = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (collateral_quantity_local_var) {
        free(collateral_quantity_local_var);
        collateral_quantity_local_var = NULL;
    }
    if (collateral_update_quantity_local_var) {
        free(collateral_update_quantity_local_var);
        collateral_update_quantity_local_var = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (t1_quantity_local_var) {
        free(t1_quantity_local_var);
        t1_quantity_local_var = NULL;
    }
    return NULL;

}
