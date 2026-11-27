#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "position_data.h"


char* position_data_exchange_ToString(upstox_client_position_data_EXCHANGE_e exchange) {
    char* exchangeArray[] =  { "NULL", "NSE", "NFO", "CDS", "BSE", "BFO", "BCD", "MCX", "NSCOM", "NSE_EG" };
    return exchangeArray[exchange];
}

upstox_client_position_data_EXCHANGE_e position_data_exchange_FromString(char* exchange){
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

static position_data_t *position_data_create_internal(
    upstox_client_position_data_EXCHANGE_e exchange,
    double *multiplier,
    double *value,
    double *pnl,
    char *product,
    char *instrument_token,
    double *average_price,
    double *buy_value,
    int *overnight_quantity,
    double *day_buy_value,
    double *day_buy_price,
    double *overnight_buy_amount,
    int *overnight_buy_quantity,
    int *day_buy_quantity,
    double *day_sell_value,
    double *day_sell_price,
    double *overnight_sell_amount,
    int *overnight_sell_quantity,
    int *day_sell_quantity,
    int *quantity,
    double *last_price,
    double *unrealised,
    double *realised,
    double *sell_value,
    char *tradingsymbol,
    char *trading_symbol,
    double *close_price,
    double *buy_price,
    double *sell_price
    ) {
    position_data_t *position_data_local_var = malloc(sizeof(position_data_t));
    if (!position_data_local_var) {
        return NULL;
    }
    memset(position_data_local_var, 0, sizeof(position_data_t));
    position_data_local_var->_library_owned = 1;
    position_data_local_var->exchange = exchange;
    position_data_local_var->multiplier = multiplier;
    position_data_local_var->value = value;
    position_data_local_var->pnl = pnl;
    position_data_local_var->product = product;
    position_data_local_var->instrument_token = instrument_token;
    position_data_local_var->average_price = average_price;
    position_data_local_var->buy_value = buy_value;
    position_data_local_var->overnight_quantity = overnight_quantity;
    position_data_local_var->day_buy_value = day_buy_value;
    position_data_local_var->day_buy_price = day_buy_price;
    position_data_local_var->overnight_buy_amount = overnight_buy_amount;
    position_data_local_var->overnight_buy_quantity = overnight_buy_quantity;
    position_data_local_var->day_buy_quantity = day_buy_quantity;
    position_data_local_var->day_sell_value = day_sell_value;
    position_data_local_var->day_sell_price = day_sell_price;
    position_data_local_var->overnight_sell_amount = overnight_sell_amount;
    position_data_local_var->overnight_sell_quantity = overnight_sell_quantity;
    position_data_local_var->day_sell_quantity = day_sell_quantity;
    position_data_local_var->quantity = quantity;
    position_data_local_var->last_price = last_price;
    position_data_local_var->unrealised = unrealised;
    position_data_local_var->realised = realised;
    position_data_local_var->sell_value = sell_value;
    position_data_local_var->tradingsymbol = tradingsymbol;
    position_data_local_var->trading_symbol = trading_symbol;
    position_data_local_var->close_price = close_price;
    position_data_local_var->buy_price = buy_price;
    position_data_local_var->sell_price = sell_price;
    return position_data_local_var;
}

position_data_t *position_data_create(
    upstox_client_position_data_EXCHANGE_e exchange,
    double *multiplier,
    double *value,
    double *pnl,
    char *product,
    char *instrument_token,
    double *average_price,
    double *buy_value,
    int *overnight_quantity,
    double *day_buy_value,
    double *day_buy_price,
    double *overnight_buy_amount,
    int *overnight_buy_quantity,
    int *day_buy_quantity,
    double *day_sell_value,
    double *day_sell_price,
    double *overnight_sell_amount,
    int *overnight_sell_quantity,
    int *day_sell_quantity,
    int *quantity,
    double *last_price,
    double *unrealised,
    double *realised,
    double *sell_value,
    char *tradingsymbol,
    char *trading_symbol,
    double *close_price,
    double *buy_price,
    double *sell_price
    ) {
    double *multiplier_copy = NULL;
    if (multiplier) {
        multiplier_copy = malloc(sizeof(double));
        if (multiplier_copy) *multiplier_copy = *multiplier;
    }
    double *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(double));
        if (value_copy) *value_copy = *value;
    }
    double *pnl_copy = NULL;
    if (pnl) {
        pnl_copy = malloc(sizeof(double));
        if (pnl_copy) *pnl_copy = *pnl;
    }
    double *average_price_copy = NULL;
    if (average_price) {
        average_price_copy = malloc(sizeof(double));
        if (average_price_copy) *average_price_copy = *average_price;
    }
    double *buy_value_copy = NULL;
    if (buy_value) {
        buy_value_copy = malloc(sizeof(double));
        if (buy_value_copy) *buy_value_copy = *buy_value;
    }
    int *overnight_quantity_copy = NULL;
    if (overnight_quantity) {
        overnight_quantity_copy = malloc(sizeof(int));
        if (overnight_quantity_copy) *overnight_quantity_copy = *overnight_quantity;
    }
    double *day_buy_value_copy = NULL;
    if (day_buy_value) {
        day_buy_value_copy = malloc(sizeof(double));
        if (day_buy_value_copy) *day_buy_value_copy = *day_buy_value;
    }
    double *day_buy_price_copy = NULL;
    if (day_buy_price) {
        day_buy_price_copy = malloc(sizeof(double));
        if (day_buy_price_copy) *day_buy_price_copy = *day_buy_price;
    }
    double *overnight_buy_amount_copy = NULL;
    if (overnight_buy_amount) {
        overnight_buy_amount_copy = malloc(sizeof(double));
        if (overnight_buy_amount_copy) *overnight_buy_amount_copy = *overnight_buy_amount;
    }
    int *overnight_buy_quantity_copy = NULL;
    if (overnight_buy_quantity) {
        overnight_buy_quantity_copy = malloc(sizeof(int));
        if (overnight_buy_quantity_copy) *overnight_buy_quantity_copy = *overnight_buy_quantity;
    }
    int *day_buy_quantity_copy = NULL;
    if (day_buy_quantity) {
        day_buy_quantity_copy = malloc(sizeof(int));
        if (day_buy_quantity_copy) *day_buy_quantity_copy = *day_buy_quantity;
    }
    double *day_sell_value_copy = NULL;
    if (day_sell_value) {
        day_sell_value_copy = malloc(sizeof(double));
        if (day_sell_value_copy) *day_sell_value_copy = *day_sell_value;
    }
    double *day_sell_price_copy = NULL;
    if (day_sell_price) {
        day_sell_price_copy = malloc(sizeof(double));
        if (day_sell_price_copy) *day_sell_price_copy = *day_sell_price;
    }
    double *overnight_sell_amount_copy = NULL;
    if (overnight_sell_amount) {
        overnight_sell_amount_copy = malloc(sizeof(double));
        if (overnight_sell_amount_copy) *overnight_sell_amount_copy = *overnight_sell_amount;
    }
    int *overnight_sell_quantity_copy = NULL;
    if (overnight_sell_quantity) {
        overnight_sell_quantity_copy = malloc(sizeof(int));
        if (overnight_sell_quantity_copy) *overnight_sell_quantity_copy = *overnight_sell_quantity;
    }
    int *day_sell_quantity_copy = NULL;
    if (day_sell_quantity) {
        day_sell_quantity_copy = malloc(sizeof(int));
        if (day_sell_quantity_copy) *day_sell_quantity_copy = *day_sell_quantity;
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
    double *unrealised_copy = NULL;
    if (unrealised) {
        unrealised_copy = malloc(sizeof(double));
        if (unrealised_copy) *unrealised_copy = *unrealised;
    }
    double *realised_copy = NULL;
    if (realised) {
        realised_copy = malloc(sizeof(double));
        if (realised_copy) *realised_copy = *realised;
    }
    double *sell_value_copy = NULL;
    if (sell_value) {
        sell_value_copy = malloc(sizeof(double));
        if (sell_value_copy) *sell_value_copy = *sell_value;
    }
    double *close_price_copy = NULL;
    if (close_price) {
        close_price_copy = malloc(sizeof(double));
        if (close_price_copy) *close_price_copy = *close_price;
    }
    double *buy_price_copy = NULL;
    if (buy_price) {
        buy_price_copy = malloc(sizeof(double));
        if (buy_price_copy) *buy_price_copy = *buy_price;
    }
    double *sell_price_copy = NULL;
    if (sell_price) {
        sell_price_copy = malloc(sizeof(double));
        if (sell_price_copy) *sell_price_copy = *sell_price;
    }
    position_data_t *result = position_data_create_internal (
        exchange,
        multiplier_copy,
        value_copy,
        pnl_copy,
        product,
        instrument_token,
        average_price_copy,
        buy_value_copy,
        overnight_quantity_copy,
        day_buy_value_copy,
        day_buy_price_copy,
        overnight_buy_amount_copy,
        overnight_buy_quantity_copy,
        day_buy_quantity_copy,
        day_sell_value_copy,
        day_sell_price_copy,
        overnight_sell_amount_copy,
        overnight_sell_quantity_copy,
        day_sell_quantity_copy,
        quantity_copy,
        last_price_copy,
        unrealised_copy,
        realised_copy,
        sell_value_copy,
        tradingsymbol,
        trading_symbol,
        close_price_copy,
        buy_price_copy,
        sell_price_copy
        );
    if (!result) {
        free(multiplier_copy);
        free(value_copy);
        free(pnl_copy);
        free(average_price_copy);
        free(buy_value_copy);
        free(overnight_quantity_copy);
        free(day_buy_value_copy);
        free(day_buy_price_copy);
        free(overnight_buy_amount_copy);
        free(overnight_buy_quantity_copy);
        free(day_buy_quantity_copy);
        free(day_sell_value_copy);
        free(day_sell_price_copy);
        free(overnight_sell_amount_copy);
        free(overnight_sell_quantity_copy);
        free(day_sell_quantity_copy);
        free(quantity_copy);
        free(last_price_copy);
        free(unrealised_copy);
        free(realised_copy);
        free(sell_value_copy);
        free(close_price_copy);
        free(buy_price_copy);
        free(sell_price_copy);
    }
    return result;
}

void position_data_free(position_data_t *position_data) {
    if(NULL == position_data){
        return ;
    }
    if(position_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "position_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (position_data->multiplier) {
        free(position_data->multiplier);
        position_data->multiplier = NULL;
    }
    if (position_data->value) {
        free(position_data->value);
        position_data->value = NULL;
    }
    if (position_data->pnl) {
        free(position_data->pnl);
        position_data->pnl = NULL;
    }
    if (position_data->product) {
        free(position_data->product);
        position_data->product = NULL;
    }
    if (position_data->instrument_token) {
        free(position_data->instrument_token);
        position_data->instrument_token = NULL;
    }
    if (position_data->average_price) {
        free(position_data->average_price);
        position_data->average_price = NULL;
    }
    if (position_data->buy_value) {
        free(position_data->buy_value);
        position_data->buy_value = NULL;
    }
    if (position_data->overnight_quantity) {
        free(position_data->overnight_quantity);
        position_data->overnight_quantity = NULL;
    }
    if (position_data->day_buy_value) {
        free(position_data->day_buy_value);
        position_data->day_buy_value = NULL;
    }
    if (position_data->day_buy_price) {
        free(position_data->day_buy_price);
        position_data->day_buy_price = NULL;
    }
    if (position_data->overnight_buy_amount) {
        free(position_data->overnight_buy_amount);
        position_data->overnight_buy_amount = NULL;
    }
    if (position_data->overnight_buy_quantity) {
        free(position_data->overnight_buy_quantity);
        position_data->overnight_buy_quantity = NULL;
    }
    if (position_data->day_buy_quantity) {
        free(position_data->day_buy_quantity);
        position_data->day_buy_quantity = NULL;
    }
    if (position_data->day_sell_value) {
        free(position_data->day_sell_value);
        position_data->day_sell_value = NULL;
    }
    if (position_data->day_sell_price) {
        free(position_data->day_sell_price);
        position_data->day_sell_price = NULL;
    }
    if (position_data->overnight_sell_amount) {
        free(position_data->overnight_sell_amount);
        position_data->overnight_sell_amount = NULL;
    }
    if (position_data->overnight_sell_quantity) {
        free(position_data->overnight_sell_quantity);
        position_data->overnight_sell_quantity = NULL;
    }
    if (position_data->day_sell_quantity) {
        free(position_data->day_sell_quantity);
        position_data->day_sell_quantity = NULL;
    }
    if (position_data->quantity) {
        free(position_data->quantity);
        position_data->quantity = NULL;
    }
    if (position_data->last_price) {
        free(position_data->last_price);
        position_data->last_price = NULL;
    }
    if (position_data->unrealised) {
        free(position_data->unrealised);
        position_data->unrealised = NULL;
    }
    if (position_data->realised) {
        free(position_data->realised);
        position_data->realised = NULL;
    }
    if (position_data->sell_value) {
        free(position_data->sell_value);
        position_data->sell_value = NULL;
    }
    if (position_data->tradingsymbol) {
        free(position_data->tradingsymbol);
        position_data->tradingsymbol = NULL;
    }
    if (position_data->trading_symbol) {
        free(position_data->trading_symbol);
        position_data->trading_symbol = NULL;
    }
    if (position_data->close_price) {
        free(position_data->close_price);
        position_data->close_price = NULL;
    }
    if (position_data->buy_price) {
        free(position_data->buy_price);
        position_data->buy_price = NULL;
    }
    if (position_data->sell_price) {
        free(position_data->sell_price);
        position_data->sell_price = NULL;
    }
    free(position_data);
}

cJSON *position_data_convertToJSON(position_data_t *position_data) {
    cJSON *item = cJSON_CreateObject();

    // position_data->exchange
    if(position_data->exchange != upstox_client_position_data_EXCHANGE_NULL) {
    if(cJSON_AddStringToObject(item, "exchange", position_data_exchange_ToString(position_data->exchange)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // position_data->multiplier
    if(position_data->multiplier) {
    if(cJSON_AddNumberToObject(item, "multiplier", *position_data->multiplier) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->value
    if(position_data->value) {
    if(cJSON_AddNumberToObject(item, "value", *position_data->value) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->pnl
    if(position_data->pnl) {
    if(cJSON_AddNumberToObject(item, "pnl", *position_data->pnl) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->product
    if(position_data->product) {
    if(cJSON_AddStringToObject(item, "product", position_data->product) == NULL) {
    goto fail; //String
    }
    }


    // position_data->instrument_token
    if(position_data->instrument_token) {
    if(cJSON_AddStringToObject(item, "instrument_token", position_data->instrument_token) == NULL) {
    goto fail; //String
    }
    }


    // position_data->average_price
    if(position_data->average_price) {
    if(cJSON_AddNumberToObject(item, "average_price", *position_data->average_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->buy_value
    if(position_data->buy_value) {
    if(cJSON_AddNumberToObject(item, "buy_value", *position_data->buy_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->overnight_quantity
    if(position_data->overnight_quantity) {
    if(cJSON_AddNumberToObject(item, "overnight_quantity", *position_data->overnight_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_buy_value
    if(position_data->day_buy_value) {
    if(cJSON_AddNumberToObject(item, "day_buy_value", *position_data->day_buy_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_buy_price
    if(position_data->day_buy_price) {
    if(cJSON_AddNumberToObject(item, "day_buy_price", *position_data->day_buy_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->overnight_buy_amount
    if(position_data->overnight_buy_amount) {
    if(cJSON_AddNumberToObject(item, "overnight_buy_amount", *position_data->overnight_buy_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->overnight_buy_quantity
    if(position_data->overnight_buy_quantity) {
    if(cJSON_AddNumberToObject(item, "overnight_buy_quantity", *position_data->overnight_buy_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_buy_quantity
    if(position_data->day_buy_quantity) {
    if(cJSON_AddNumberToObject(item, "day_buy_quantity", *position_data->day_buy_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_sell_value
    if(position_data->day_sell_value) {
    if(cJSON_AddNumberToObject(item, "day_sell_value", *position_data->day_sell_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_sell_price
    if(position_data->day_sell_price) {
    if(cJSON_AddNumberToObject(item, "day_sell_price", *position_data->day_sell_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->overnight_sell_amount
    if(position_data->overnight_sell_amount) {
    if(cJSON_AddNumberToObject(item, "overnight_sell_amount", *position_data->overnight_sell_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->overnight_sell_quantity
    if(position_data->overnight_sell_quantity) {
    if(cJSON_AddNumberToObject(item, "overnight_sell_quantity", *position_data->overnight_sell_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->day_sell_quantity
    if(position_data->day_sell_quantity) {
    if(cJSON_AddNumberToObject(item, "day_sell_quantity", *position_data->day_sell_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->quantity
    if(position_data->quantity) {
    if(cJSON_AddNumberToObject(item, "quantity", *position_data->quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->last_price
    if(position_data->last_price) {
    if(cJSON_AddNumberToObject(item, "last_price", *position_data->last_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->unrealised
    if(position_data->unrealised) {
    if(cJSON_AddNumberToObject(item, "unrealised", *position_data->unrealised) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->realised
    if(position_data->realised) {
    if(cJSON_AddNumberToObject(item, "realised", *position_data->realised) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->sell_value
    if(position_data->sell_value) {
    if(cJSON_AddNumberToObject(item, "sell_value", *position_data->sell_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->tradingsymbol
    if(position_data->tradingsymbol) {
    if(cJSON_AddStringToObject(item, "tradingsymbol", position_data->tradingsymbol) == NULL) {
    goto fail; //String
    }
    }


    // position_data->trading_symbol
    if(position_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", position_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // position_data->close_price
    if(position_data->close_price) {
    if(cJSON_AddNumberToObject(item, "close_price", *position_data->close_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->buy_price
    if(position_data->buy_price) {
    if(cJSON_AddNumberToObject(item, "buy_price", *position_data->buy_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // position_data->sell_price
    if(position_data->sell_price) {
    if(cJSON_AddNumberToObject(item, "sell_price", *position_data->sell_price) == NULL) {
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

position_data_t *position_data_parseFromJSON(cJSON *position_dataJSON){

    position_data_t *position_data_local_var = NULL;

    // define the local variable for position_data->multiplier
    double *multiplier_local_var = NULL;

    // define the local variable for position_data->value
    double *value_local_var = NULL;

    // define the local variable for position_data->pnl
    double *pnl_local_var = NULL;

    char *product_local_str = NULL;

    char *instrument_token_local_str = NULL;

    // define the local variable for position_data->average_price
    double *average_price_local_var = NULL;

    // define the local variable for position_data->buy_value
    double *buy_value_local_var = NULL;

    // define the local variable for position_data->overnight_quantity
    int *overnight_quantity_local_var = NULL;

    // define the local variable for position_data->day_buy_value
    double *day_buy_value_local_var = NULL;

    // define the local variable for position_data->day_buy_price
    double *day_buy_price_local_var = NULL;

    // define the local variable for position_data->overnight_buy_amount
    double *overnight_buy_amount_local_var = NULL;

    // define the local variable for position_data->overnight_buy_quantity
    int *overnight_buy_quantity_local_var = NULL;

    // define the local variable for position_data->day_buy_quantity
    int *day_buy_quantity_local_var = NULL;

    // define the local variable for position_data->day_sell_value
    double *day_sell_value_local_var = NULL;

    // define the local variable for position_data->day_sell_price
    double *day_sell_price_local_var = NULL;

    // define the local variable for position_data->overnight_sell_amount
    double *overnight_sell_amount_local_var = NULL;

    // define the local variable for position_data->overnight_sell_quantity
    int *overnight_sell_quantity_local_var = NULL;

    // define the local variable for position_data->day_sell_quantity
    int *day_sell_quantity_local_var = NULL;

    // define the local variable for position_data->quantity
    int *quantity_local_var = NULL;

    // define the local variable for position_data->last_price
    double *last_price_local_var = NULL;

    // define the local variable for position_data->unrealised
    double *unrealised_local_var = NULL;

    // define the local variable for position_data->realised
    double *realised_local_var = NULL;

    // define the local variable for position_data->sell_value
    double *sell_value_local_var = NULL;

    char *tradingsymbol_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    // define the local variable for position_data->close_price
    double *close_price_local_var = NULL;

    // define the local variable for position_data->buy_price
    double *buy_price_local_var = NULL;

    // define the local variable for position_data->sell_price
    double *sell_price_local_var = NULL;

    // position_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    upstox_client_position_data_EXCHANGE_e exchangeVariable;
    if (exchange) { 
    if(!cJSON_IsString(exchange))
    {
    goto end; //Enum
    }
    exchangeVariable = position_data_exchange_FromString(exchange->valuestring);
    }

    // position_data->multiplier
    cJSON *multiplier = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "multiplier");
    if (cJSON_IsNull(multiplier)) {
        multiplier = NULL;
    }
    if (multiplier) { 
    if(!cJSON_IsNumber(multiplier))
    {
    goto end; //Numeric
    }
    multiplier_local_var = malloc(sizeof(double));
    if(!multiplier_local_var)
    {
        goto end;
    }
    *multiplier_local_var = multiplier->valuedouble;
    }

    // position_data->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(double));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;
    }

    // position_data->pnl
    cJSON *pnl = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "pnl");
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

    // position_data->product
    cJSON *product = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "product");
    if (cJSON_IsNull(product)) {
        product = NULL;
    }
    if (product) { 
    if(!cJSON_IsString(product) && !cJSON_IsNull(product))
    {
    goto end; //String
    }
    }

    // position_data->instrument_token
    cJSON *instrument_token = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "instrument_token");
    if (cJSON_IsNull(instrument_token)) {
        instrument_token = NULL;
    }
    if (instrument_token) { 
    if(!cJSON_IsString(instrument_token) && !cJSON_IsNull(instrument_token))
    {
    goto end; //String
    }
    }

    // position_data->average_price
    cJSON *average_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "average_price");
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

    // position_data->buy_value
    cJSON *buy_value = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "buy_value");
    if (cJSON_IsNull(buy_value)) {
        buy_value = NULL;
    }
    if (buy_value) { 
    if(!cJSON_IsNumber(buy_value))
    {
    goto end; //Numeric
    }
    buy_value_local_var = malloc(sizeof(double));
    if(!buy_value_local_var)
    {
        goto end;
    }
    *buy_value_local_var = buy_value->valuedouble;
    }

    // position_data->overnight_quantity
    cJSON *overnight_quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "overnight_quantity");
    if (cJSON_IsNull(overnight_quantity)) {
        overnight_quantity = NULL;
    }
    if (overnight_quantity) { 
    if(!cJSON_IsNumber(overnight_quantity))
    {
    goto end; //Numeric
    }
    overnight_quantity_local_var = malloc(sizeof(int));
    if(!overnight_quantity_local_var)
    {
        goto end;
    }
    *overnight_quantity_local_var = overnight_quantity->valuedouble;
    }

    // position_data->day_buy_value
    cJSON *day_buy_value = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_buy_value");
    if (cJSON_IsNull(day_buy_value)) {
        day_buy_value = NULL;
    }
    if (day_buy_value) { 
    if(!cJSON_IsNumber(day_buy_value))
    {
    goto end; //Numeric
    }
    day_buy_value_local_var = malloc(sizeof(double));
    if(!day_buy_value_local_var)
    {
        goto end;
    }
    *day_buy_value_local_var = day_buy_value->valuedouble;
    }

    // position_data->day_buy_price
    cJSON *day_buy_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_buy_price");
    if (cJSON_IsNull(day_buy_price)) {
        day_buy_price = NULL;
    }
    if (day_buy_price) { 
    if(!cJSON_IsNumber(day_buy_price))
    {
    goto end; //Numeric
    }
    day_buy_price_local_var = malloc(sizeof(double));
    if(!day_buy_price_local_var)
    {
        goto end;
    }
    *day_buy_price_local_var = day_buy_price->valuedouble;
    }

    // position_data->overnight_buy_amount
    cJSON *overnight_buy_amount = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "overnight_buy_amount");
    if (cJSON_IsNull(overnight_buy_amount)) {
        overnight_buy_amount = NULL;
    }
    if (overnight_buy_amount) { 
    if(!cJSON_IsNumber(overnight_buy_amount))
    {
    goto end; //Numeric
    }
    overnight_buy_amount_local_var = malloc(sizeof(double));
    if(!overnight_buy_amount_local_var)
    {
        goto end;
    }
    *overnight_buy_amount_local_var = overnight_buy_amount->valuedouble;
    }

    // position_data->overnight_buy_quantity
    cJSON *overnight_buy_quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "overnight_buy_quantity");
    if (cJSON_IsNull(overnight_buy_quantity)) {
        overnight_buy_quantity = NULL;
    }
    if (overnight_buy_quantity) { 
    if(!cJSON_IsNumber(overnight_buy_quantity))
    {
    goto end; //Numeric
    }
    overnight_buy_quantity_local_var = malloc(sizeof(int));
    if(!overnight_buy_quantity_local_var)
    {
        goto end;
    }
    *overnight_buy_quantity_local_var = overnight_buy_quantity->valuedouble;
    }

    // position_data->day_buy_quantity
    cJSON *day_buy_quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_buy_quantity");
    if (cJSON_IsNull(day_buy_quantity)) {
        day_buy_quantity = NULL;
    }
    if (day_buy_quantity) { 
    if(!cJSON_IsNumber(day_buy_quantity))
    {
    goto end; //Numeric
    }
    day_buy_quantity_local_var = malloc(sizeof(int));
    if(!day_buy_quantity_local_var)
    {
        goto end;
    }
    *day_buy_quantity_local_var = day_buy_quantity->valuedouble;
    }

    // position_data->day_sell_value
    cJSON *day_sell_value = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_sell_value");
    if (cJSON_IsNull(day_sell_value)) {
        day_sell_value = NULL;
    }
    if (day_sell_value) { 
    if(!cJSON_IsNumber(day_sell_value))
    {
    goto end; //Numeric
    }
    day_sell_value_local_var = malloc(sizeof(double));
    if(!day_sell_value_local_var)
    {
        goto end;
    }
    *day_sell_value_local_var = day_sell_value->valuedouble;
    }

    // position_data->day_sell_price
    cJSON *day_sell_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_sell_price");
    if (cJSON_IsNull(day_sell_price)) {
        day_sell_price = NULL;
    }
    if (day_sell_price) { 
    if(!cJSON_IsNumber(day_sell_price))
    {
    goto end; //Numeric
    }
    day_sell_price_local_var = malloc(sizeof(double));
    if(!day_sell_price_local_var)
    {
        goto end;
    }
    *day_sell_price_local_var = day_sell_price->valuedouble;
    }

    // position_data->overnight_sell_amount
    cJSON *overnight_sell_amount = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "overnight_sell_amount");
    if (cJSON_IsNull(overnight_sell_amount)) {
        overnight_sell_amount = NULL;
    }
    if (overnight_sell_amount) { 
    if(!cJSON_IsNumber(overnight_sell_amount))
    {
    goto end; //Numeric
    }
    overnight_sell_amount_local_var = malloc(sizeof(double));
    if(!overnight_sell_amount_local_var)
    {
        goto end;
    }
    *overnight_sell_amount_local_var = overnight_sell_amount->valuedouble;
    }

    // position_data->overnight_sell_quantity
    cJSON *overnight_sell_quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "overnight_sell_quantity");
    if (cJSON_IsNull(overnight_sell_quantity)) {
        overnight_sell_quantity = NULL;
    }
    if (overnight_sell_quantity) { 
    if(!cJSON_IsNumber(overnight_sell_quantity))
    {
    goto end; //Numeric
    }
    overnight_sell_quantity_local_var = malloc(sizeof(int));
    if(!overnight_sell_quantity_local_var)
    {
        goto end;
    }
    *overnight_sell_quantity_local_var = overnight_sell_quantity->valuedouble;
    }

    // position_data->day_sell_quantity
    cJSON *day_sell_quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "day_sell_quantity");
    if (cJSON_IsNull(day_sell_quantity)) {
        day_sell_quantity = NULL;
    }
    if (day_sell_quantity) { 
    if(!cJSON_IsNumber(day_sell_quantity))
    {
    goto end; //Numeric
    }
    day_sell_quantity_local_var = malloc(sizeof(int));
    if(!day_sell_quantity_local_var)
    {
        goto end;
    }
    *day_sell_quantity_local_var = day_sell_quantity->valuedouble;
    }

    // position_data->quantity
    cJSON *quantity = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "quantity");
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

    // position_data->last_price
    cJSON *last_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "last_price");
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

    // position_data->unrealised
    cJSON *unrealised = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "unrealised");
    if (cJSON_IsNull(unrealised)) {
        unrealised = NULL;
    }
    if (unrealised) { 
    if(!cJSON_IsNumber(unrealised))
    {
    goto end; //Numeric
    }
    unrealised_local_var = malloc(sizeof(double));
    if(!unrealised_local_var)
    {
        goto end;
    }
    *unrealised_local_var = unrealised->valuedouble;
    }

    // position_data->realised
    cJSON *realised = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "realised");
    if (cJSON_IsNull(realised)) {
        realised = NULL;
    }
    if (realised) { 
    if(!cJSON_IsNumber(realised))
    {
    goto end; //Numeric
    }
    realised_local_var = malloc(sizeof(double));
    if(!realised_local_var)
    {
        goto end;
    }
    *realised_local_var = realised->valuedouble;
    }

    // position_data->sell_value
    cJSON *sell_value = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "sell_value");
    if (cJSON_IsNull(sell_value)) {
        sell_value = NULL;
    }
    if (sell_value) { 
    if(!cJSON_IsNumber(sell_value))
    {
    goto end; //Numeric
    }
    sell_value_local_var = malloc(sizeof(double));
    if(!sell_value_local_var)
    {
        goto end;
    }
    *sell_value_local_var = sell_value->valuedouble;
    }

    // position_data->tradingsymbol
    cJSON *tradingsymbol = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "tradingsymbol");
    if (cJSON_IsNull(tradingsymbol)) {
        tradingsymbol = NULL;
    }
    if (tradingsymbol) { 
    if(!cJSON_IsString(tradingsymbol) && !cJSON_IsNull(tradingsymbol))
    {
    goto end; //String
    }
    }

    // position_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // position_data->close_price
    cJSON *close_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "close_price");
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

    // position_data->buy_price
    cJSON *buy_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "buy_price");
    if (cJSON_IsNull(buy_price)) {
        buy_price = NULL;
    }
    if (buy_price) { 
    if(!cJSON_IsNumber(buy_price))
    {
    goto end; //Numeric
    }
    buy_price_local_var = malloc(sizeof(double));
    if(!buy_price_local_var)
    {
        goto end;
    }
    *buy_price_local_var = buy_price->valuedouble;
    }

    // position_data->sell_price
    cJSON *sell_price = cJSON_GetObjectItemCaseSensitive(position_dataJSON, "sell_price");
    if (cJSON_IsNull(sell_price)) {
        sell_price = NULL;
    }
    if (sell_price) { 
    if(!cJSON_IsNumber(sell_price))
    {
    goto end; //Numeric
    }
    sell_price_local_var = malloc(sizeof(double));
    if(!sell_price_local_var)
    {
        goto end;
    }
    *sell_price_local_var = sell_price->valuedouble;
    }


    if (product && !cJSON_IsNull(product)) product_local_str = strdup(product->valuestring);
    if (instrument_token && !cJSON_IsNull(instrument_token)) instrument_token_local_str = strdup(instrument_token->valuestring);
    if (tradingsymbol && !cJSON_IsNull(tradingsymbol)) tradingsymbol_local_str = strdup(tradingsymbol->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);

    position_data_local_var = position_data_create_internal (
        exchange ? exchangeVariable : upstox_client_position_data_EXCHANGE_NULL,
        multiplier_local_var,
        value_local_var,
        pnl_local_var,
        product_local_str,
        instrument_token_local_str,
        average_price_local_var,
        buy_value_local_var,
        overnight_quantity_local_var,
        day_buy_value_local_var,
        day_buy_price_local_var,
        overnight_buy_amount_local_var,
        overnight_buy_quantity_local_var,
        day_buy_quantity_local_var,
        day_sell_value_local_var,
        day_sell_price_local_var,
        overnight_sell_amount_local_var,
        overnight_sell_quantity_local_var,
        day_sell_quantity_local_var,
        quantity_local_var,
        last_price_local_var,
        unrealised_local_var,
        realised_local_var,
        sell_value_local_var,
        tradingsymbol_local_str,
        trading_symbol_local_str,
        close_price_local_var,
        buy_price_local_var,
        sell_price_local_var
        );

    if (!position_data_local_var) {
        goto end;
    }

    return position_data_local_var;
end:
    if (multiplier_local_var) {
        free(multiplier_local_var);
        multiplier_local_var = NULL;
    }
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    if (pnl_local_var) {
        free(pnl_local_var);
        pnl_local_var = NULL;
    }
    if (product_local_str) {
        free(product_local_str);
        product_local_str = NULL;
    }
    if (instrument_token_local_str) {
        free(instrument_token_local_str);
        instrument_token_local_str = NULL;
    }
    if (average_price_local_var) {
        free(average_price_local_var);
        average_price_local_var = NULL;
    }
    if (buy_value_local_var) {
        free(buy_value_local_var);
        buy_value_local_var = NULL;
    }
    if (overnight_quantity_local_var) {
        free(overnight_quantity_local_var);
        overnight_quantity_local_var = NULL;
    }
    if (day_buy_value_local_var) {
        free(day_buy_value_local_var);
        day_buy_value_local_var = NULL;
    }
    if (day_buy_price_local_var) {
        free(day_buy_price_local_var);
        day_buy_price_local_var = NULL;
    }
    if (overnight_buy_amount_local_var) {
        free(overnight_buy_amount_local_var);
        overnight_buy_amount_local_var = NULL;
    }
    if (overnight_buy_quantity_local_var) {
        free(overnight_buy_quantity_local_var);
        overnight_buy_quantity_local_var = NULL;
    }
    if (day_buy_quantity_local_var) {
        free(day_buy_quantity_local_var);
        day_buy_quantity_local_var = NULL;
    }
    if (day_sell_value_local_var) {
        free(day_sell_value_local_var);
        day_sell_value_local_var = NULL;
    }
    if (day_sell_price_local_var) {
        free(day_sell_price_local_var);
        day_sell_price_local_var = NULL;
    }
    if (overnight_sell_amount_local_var) {
        free(overnight_sell_amount_local_var);
        overnight_sell_amount_local_var = NULL;
    }
    if (overnight_sell_quantity_local_var) {
        free(overnight_sell_quantity_local_var);
        overnight_sell_quantity_local_var = NULL;
    }
    if (day_sell_quantity_local_var) {
        free(day_sell_quantity_local_var);
        day_sell_quantity_local_var = NULL;
    }
    if (quantity_local_var) {
        free(quantity_local_var);
        quantity_local_var = NULL;
    }
    if (last_price_local_var) {
        free(last_price_local_var);
        last_price_local_var = NULL;
    }
    if (unrealised_local_var) {
        free(unrealised_local_var);
        unrealised_local_var = NULL;
    }
    if (realised_local_var) {
        free(realised_local_var);
        realised_local_var = NULL;
    }
    if (sell_value_local_var) {
        free(sell_value_local_var);
        sell_value_local_var = NULL;
    }
    if (tradingsymbol_local_str) {
        free(tradingsymbol_local_str);
        tradingsymbol_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (close_price_local_var) {
        free(close_price_local_var);
        close_price_local_var = NULL;
    }
    if (buy_price_local_var) {
        free(buy_price_local_var);
        buy_price_local_var = NULL;
    }
    if (sell_price_local_var) {
        free(sell_price_local_var);
        sell_price_local_var = NULL;
    }
    return NULL;

}
