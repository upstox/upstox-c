#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instrument_data.h"



static instrument_data_t *instrument_data_create_internal(
    char *name,
    char *segment,
    char *exchange,
    char *isin,
    char *expiry,
    char *country,
    char *latency,
    char *description,
    char *currency,
    int *weekly,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    char *short_name,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    char *last_trading_date,
    double *strike_price,
    char *price_quote_unit,
    long *qty_multiplier,
    long *minimum_lot,
    char *start_time,
    char *end_time,
    char *week_days,
    double *general_denominator,
    double *general_numerator,
    double *price_numerator,
    double *price_denominator,
    int *mtf_enabled,
    double *mtf_bracket,
    char *security_type,
    int *cas_eligible
    ) {
    instrument_data_t *instrument_data_local_var = malloc(sizeof(instrument_data_t));
    if (!instrument_data_local_var) {
        return NULL;
    }
    memset(instrument_data_local_var, 0, sizeof(instrument_data_t));
    instrument_data_local_var->_library_owned = 1;
    instrument_data_local_var->name = name;
    instrument_data_local_var->segment = segment;
    instrument_data_local_var->exchange = exchange;
    instrument_data_local_var->isin = isin;
    instrument_data_local_var->expiry = expiry;
    instrument_data_local_var->country = country;
    instrument_data_local_var->latency = latency;
    instrument_data_local_var->description = description;
    instrument_data_local_var->currency = currency;
    instrument_data_local_var->weekly = weekly;
    instrument_data_local_var->instrument_key = instrument_key;
    instrument_data_local_var->exchange_token = exchange_token;
    instrument_data_local_var->trading_symbol = trading_symbol;
    instrument_data_local_var->short_name = short_name;
    instrument_data_local_var->tick_size = tick_size;
    instrument_data_local_var->lot_size = lot_size;
    instrument_data_local_var->instrument_type = instrument_type;
    instrument_data_local_var->freeze_quantity = freeze_quantity;
    instrument_data_local_var->underlying_key = underlying_key;
    instrument_data_local_var->underlying_type = underlying_type;
    instrument_data_local_var->underlying_symbol = underlying_symbol;
    instrument_data_local_var->last_trading_date = last_trading_date;
    instrument_data_local_var->strike_price = strike_price;
    instrument_data_local_var->price_quote_unit = price_quote_unit;
    instrument_data_local_var->qty_multiplier = qty_multiplier;
    instrument_data_local_var->minimum_lot = minimum_lot;
    instrument_data_local_var->start_time = start_time;
    instrument_data_local_var->end_time = end_time;
    instrument_data_local_var->week_days = week_days;
    instrument_data_local_var->general_denominator = general_denominator;
    instrument_data_local_var->general_numerator = general_numerator;
    instrument_data_local_var->price_numerator = price_numerator;
    instrument_data_local_var->price_denominator = price_denominator;
    instrument_data_local_var->mtf_enabled = mtf_enabled;
    instrument_data_local_var->mtf_bracket = mtf_bracket;
    instrument_data_local_var->security_type = security_type;
    instrument_data_local_var->cas_eligible = cas_eligible;
    return instrument_data_local_var;
}

instrument_data_t *instrument_data_create(
    char *name,
    char *segment,
    char *exchange,
    char *isin,
    char *expiry,
    char *country,
    char *latency,
    char *description,
    char *currency,
    int *weekly,
    char *instrument_key,
    char *exchange_token,
    char *trading_symbol,
    char *short_name,
    double *tick_size,
    long *lot_size,
    char *instrument_type,
    double *freeze_quantity,
    char *underlying_key,
    char *underlying_type,
    char *underlying_symbol,
    char *last_trading_date,
    double *strike_price,
    char *price_quote_unit,
    long *qty_multiplier,
    long *minimum_lot,
    char *start_time,
    char *end_time,
    char *week_days,
    double *general_denominator,
    double *general_numerator,
    double *price_numerator,
    double *price_denominator,
    int *mtf_enabled,
    double *mtf_bracket,
    char *security_type,
    int *cas_eligible
    ) {
    int *weekly_copy = NULL;
    if (weekly) {
        weekly_copy = malloc(sizeof(int));
        if (weekly_copy) *weekly_copy = *weekly;
    }
    double *tick_size_copy = NULL;
    if (tick_size) {
        tick_size_copy = malloc(sizeof(double));
        if (tick_size_copy) *tick_size_copy = *tick_size;
    }
    long *lot_size_copy = NULL;
    if (lot_size) {
        lot_size_copy = malloc(sizeof(long));
        if (lot_size_copy) *lot_size_copy = *lot_size;
    }
    double *freeze_quantity_copy = NULL;
    if (freeze_quantity) {
        freeze_quantity_copy = malloc(sizeof(double));
        if (freeze_quantity_copy) *freeze_quantity_copy = *freeze_quantity;
    }
    double *strike_price_copy = NULL;
    if (strike_price) {
        strike_price_copy = malloc(sizeof(double));
        if (strike_price_copy) *strike_price_copy = *strike_price;
    }
    long *qty_multiplier_copy = NULL;
    if (qty_multiplier) {
        qty_multiplier_copy = malloc(sizeof(long));
        if (qty_multiplier_copy) *qty_multiplier_copy = *qty_multiplier;
    }
    long *minimum_lot_copy = NULL;
    if (minimum_lot) {
        minimum_lot_copy = malloc(sizeof(long));
        if (minimum_lot_copy) *minimum_lot_copy = *minimum_lot;
    }
    double *general_denominator_copy = NULL;
    if (general_denominator) {
        general_denominator_copy = malloc(sizeof(double));
        if (general_denominator_copy) *general_denominator_copy = *general_denominator;
    }
    double *general_numerator_copy = NULL;
    if (general_numerator) {
        general_numerator_copy = malloc(sizeof(double));
        if (general_numerator_copy) *general_numerator_copy = *general_numerator;
    }
    double *price_numerator_copy = NULL;
    if (price_numerator) {
        price_numerator_copy = malloc(sizeof(double));
        if (price_numerator_copy) *price_numerator_copy = *price_numerator;
    }
    double *price_denominator_copy = NULL;
    if (price_denominator) {
        price_denominator_copy = malloc(sizeof(double));
        if (price_denominator_copy) *price_denominator_copy = *price_denominator;
    }
    int *mtf_enabled_copy = NULL;
    if (mtf_enabled) {
        mtf_enabled_copy = malloc(sizeof(int));
        if (mtf_enabled_copy) *mtf_enabled_copy = *mtf_enabled;
    }
    double *mtf_bracket_copy = NULL;
    if (mtf_bracket) {
        mtf_bracket_copy = malloc(sizeof(double));
        if (mtf_bracket_copy) *mtf_bracket_copy = *mtf_bracket;
    }
    int *cas_eligible_copy = NULL;
    if (cas_eligible) {
        cas_eligible_copy = malloc(sizeof(int));
        if (cas_eligible_copy) *cas_eligible_copy = *cas_eligible;
    }
    instrument_data_t *result = instrument_data_create_internal (
        name,
        segment,
        exchange,
        isin,
        expiry,
        country,
        latency,
        description,
        currency,
        weekly_copy,
        instrument_key,
        exchange_token,
        trading_symbol,
        short_name,
        tick_size_copy,
        lot_size_copy,
        instrument_type,
        freeze_quantity_copy,
        underlying_key,
        underlying_type,
        underlying_symbol,
        last_trading_date,
        strike_price_copy,
        price_quote_unit,
        qty_multiplier_copy,
        minimum_lot_copy,
        start_time,
        end_time,
        week_days,
        general_denominator_copy,
        general_numerator_copy,
        price_numerator_copy,
        price_denominator_copy,
        mtf_enabled_copy,
        mtf_bracket_copy,
        security_type,
        cas_eligible_copy
        );
    if (!result) {
        free(weekly_copy);
        free(tick_size_copy);
        free(lot_size_copy);
        free(freeze_quantity_copy);
        free(strike_price_copy);
        free(qty_multiplier_copy);
        free(minimum_lot_copy);
        free(general_denominator_copy);
        free(general_numerator_copy);
        free(price_numerator_copy);
        free(price_denominator_copy);
        free(mtf_enabled_copy);
        free(mtf_bracket_copy);
        free(cas_eligible_copy);
    }
    return result;
}

void instrument_data_free(instrument_data_t *instrument_data) {
    if(NULL == instrument_data){
        return ;
    }
    if(instrument_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instrument_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instrument_data->name) {
        free(instrument_data->name);
        instrument_data->name = NULL;
    }
    if (instrument_data->segment) {
        free(instrument_data->segment);
        instrument_data->segment = NULL;
    }
    if (instrument_data->exchange) {
        free(instrument_data->exchange);
        instrument_data->exchange = NULL;
    }
    if (instrument_data->isin) {
        free(instrument_data->isin);
        instrument_data->isin = NULL;
    }
    if (instrument_data->expiry) {
        free(instrument_data->expiry);
        instrument_data->expiry = NULL;
    }
    if (instrument_data->country) {
        free(instrument_data->country);
        instrument_data->country = NULL;
    }
    if (instrument_data->latency) {
        free(instrument_data->latency);
        instrument_data->latency = NULL;
    }
    if (instrument_data->description) {
        free(instrument_data->description);
        instrument_data->description = NULL;
    }
    if (instrument_data->currency) {
        free(instrument_data->currency);
        instrument_data->currency = NULL;
    }
    if (instrument_data->weekly) {
        free(instrument_data->weekly);
        instrument_data->weekly = NULL;
    }
    if (instrument_data->instrument_key) {
        free(instrument_data->instrument_key);
        instrument_data->instrument_key = NULL;
    }
    if (instrument_data->exchange_token) {
        free(instrument_data->exchange_token);
        instrument_data->exchange_token = NULL;
    }
    if (instrument_data->trading_symbol) {
        free(instrument_data->trading_symbol);
        instrument_data->trading_symbol = NULL;
    }
    if (instrument_data->short_name) {
        free(instrument_data->short_name);
        instrument_data->short_name = NULL;
    }
    if (instrument_data->tick_size) {
        free(instrument_data->tick_size);
        instrument_data->tick_size = NULL;
    }
    if (instrument_data->lot_size) {
        free(instrument_data->lot_size);
        instrument_data->lot_size = NULL;
    }
    if (instrument_data->instrument_type) {
        free(instrument_data->instrument_type);
        instrument_data->instrument_type = NULL;
    }
    if (instrument_data->freeze_quantity) {
        free(instrument_data->freeze_quantity);
        instrument_data->freeze_quantity = NULL;
    }
    if (instrument_data->underlying_key) {
        free(instrument_data->underlying_key);
        instrument_data->underlying_key = NULL;
    }
    if (instrument_data->underlying_type) {
        free(instrument_data->underlying_type);
        instrument_data->underlying_type = NULL;
    }
    if (instrument_data->underlying_symbol) {
        free(instrument_data->underlying_symbol);
        instrument_data->underlying_symbol = NULL;
    }
    if (instrument_data->last_trading_date) {
        free(instrument_data->last_trading_date);
        instrument_data->last_trading_date = NULL;
    }
    if (instrument_data->strike_price) {
        free(instrument_data->strike_price);
        instrument_data->strike_price = NULL;
    }
    if (instrument_data->price_quote_unit) {
        free(instrument_data->price_quote_unit);
        instrument_data->price_quote_unit = NULL;
    }
    if (instrument_data->qty_multiplier) {
        free(instrument_data->qty_multiplier);
        instrument_data->qty_multiplier = NULL;
    }
    if (instrument_data->minimum_lot) {
        free(instrument_data->minimum_lot);
        instrument_data->minimum_lot = NULL;
    }
    if (instrument_data->start_time) {
        free(instrument_data->start_time);
        instrument_data->start_time = NULL;
    }
    if (instrument_data->end_time) {
        free(instrument_data->end_time);
        instrument_data->end_time = NULL;
    }
    if (instrument_data->week_days) {
        free(instrument_data->week_days);
        instrument_data->week_days = NULL;
    }
    if (instrument_data->general_denominator) {
        free(instrument_data->general_denominator);
        instrument_data->general_denominator = NULL;
    }
    if (instrument_data->general_numerator) {
        free(instrument_data->general_numerator);
        instrument_data->general_numerator = NULL;
    }
    if (instrument_data->price_numerator) {
        free(instrument_data->price_numerator);
        instrument_data->price_numerator = NULL;
    }
    if (instrument_data->price_denominator) {
        free(instrument_data->price_denominator);
        instrument_data->price_denominator = NULL;
    }
    if (instrument_data->mtf_enabled) {
        free(instrument_data->mtf_enabled);
        instrument_data->mtf_enabled = NULL;
    }
    if (instrument_data->mtf_bracket) {
        free(instrument_data->mtf_bracket);
        instrument_data->mtf_bracket = NULL;
    }
    if (instrument_data->security_type) {
        free(instrument_data->security_type);
        instrument_data->security_type = NULL;
    }
    if (instrument_data->cas_eligible) {
        free(instrument_data->cas_eligible);
        instrument_data->cas_eligible = NULL;
    }
    free(instrument_data);
}

cJSON *instrument_data_convertToJSON(instrument_data_t *instrument_data) {
    cJSON *item = cJSON_CreateObject();

    // instrument_data->name
    if(instrument_data->name) {
    if(cJSON_AddStringToObject(item, "name", instrument_data->name) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->segment
    if(instrument_data->segment) {
    if(cJSON_AddStringToObject(item, "segment", instrument_data->segment) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->exchange
    if(instrument_data->exchange) {
    if(cJSON_AddStringToObject(item, "exchange", instrument_data->exchange) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->isin
    if(instrument_data->isin) {
    if(cJSON_AddStringToObject(item, "isin", instrument_data->isin) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->expiry
    if(instrument_data->expiry) {
    if(cJSON_AddStringToObject(item, "expiry", instrument_data->expiry) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instrument_data->country
    if(instrument_data->country) {
    if(cJSON_AddStringToObject(item, "country", instrument_data->country) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->latency
    if(instrument_data->latency) {
    if(cJSON_AddStringToObject(item, "latency", instrument_data->latency) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->description
    if(instrument_data->description) {
    if(cJSON_AddStringToObject(item, "description", instrument_data->description) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->currency
    if(instrument_data->currency) {
    if(cJSON_AddStringToObject(item, "currency", instrument_data->currency) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->weekly
    if(instrument_data->weekly) {
    if(cJSON_AddBoolToObject(item, "weekly", *instrument_data->weekly) == NULL) {
    goto fail; //Bool
    }
    }


    // instrument_data->instrument_key
    if(instrument_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", instrument_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->exchange_token
    if(instrument_data->exchange_token) {
    if(cJSON_AddStringToObject(item, "exchange_token", instrument_data->exchange_token) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->trading_symbol
    if(instrument_data->trading_symbol) {
    if(cJSON_AddStringToObject(item, "trading_symbol", instrument_data->trading_symbol) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->short_name
    if(instrument_data->short_name) {
    if(cJSON_AddStringToObject(item, "short_name", instrument_data->short_name) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->tick_size
    if(instrument_data->tick_size) {
    if(cJSON_AddNumberToObject(item, "tick_size", *instrument_data->tick_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->lot_size
    if(instrument_data->lot_size) {
    if(cJSON_AddNumberToObject(item, "lot_size", *instrument_data->lot_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->instrument_type
    if(instrument_data->instrument_type) {
    if(cJSON_AddStringToObject(item, "instrument_type", instrument_data->instrument_type) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->freeze_quantity
    if(instrument_data->freeze_quantity) {
    if(cJSON_AddNumberToObject(item, "freeze_quantity", *instrument_data->freeze_quantity) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->underlying_key
    if(instrument_data->underlying_key) {
    if(cJSON_AddStringToObject(item, "underlying_key", instrument_data->underlying_key) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->underlying_type
    if(instrument_data->underlying_type) {
    if(cJSON_AddStringToObject(item, "underlying_type", instrument_data->underlying_type) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->underlying_symbol
    if(instrument_data->underlying_symbol) {
    if(cJSON_AddStringToObject(item, "underlying_symbol", instrument_data->underlying_symbol) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->last_trading_date
    if(instrument_data->last_trading_date) {
    if(cJSON_AddStringToObject(item, "last_trading_date", instrument_data->last_trading_date) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instrument_data->strike_price
    if(instrument_data->strike_price) {
    if(cJSON_AddNumberToObject(item, "strike_price", *instrument_data->strike_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->price_quote_unit
    if(instrument_data->price_quote_unit) {
    if(cJSON_AddStringToObject(item, "price_quote_unit", instrument_data->price_quote_unit) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->qty_multiplier
    if(instrument_data->qty_multiplier) {
    if(cJSON_AddNumberToObject(item, "qty_multiplier", *instrument_data->qty_multiplier) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->minimum_lot
    if(instrument_data->minimum_lot) {
    if(cJSON_AddNumberToObject(item, "minimum_lot", *instrument_data->minimum_lot) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->start_time
    if(instrument_data->start_time) {
    if(cJSON_AddStringToObject(item, "start_time", instrument_data->start_time) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->end_time
    if(instrument_data->end_time) {
    if(cJSON_AddStringToObject(item, "end_time", instrument_data->end_time) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->week_days
    if(instrument_data->week_days) {
    if(cJSON_AddStringToObject(item, "week_days", instrument_data->week_days) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->general_denominator
    if(instrument_data->general_denominator) {
    if(cJSON_AddNumberToObject(item, "general_denominator", *instrument_data->general_denominator) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->general_numerator
    if(instrument_data->general_numerator) {
    if(cJSON_AddNumberToObject(item, "general_numerator", *instrument_data->general_numerator) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->price_numerator
    if(instrument_data->price_numerator) {
    if(cJSON_AddNumberToObject(item, "price_numerator", *instrument_data->price_numerator) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->price_denominator
    if(instrument_data->price_denominator) {
    if(cJSON_AddNumberToObject(item, "price_denominator", *instrument_data->price_denominator) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->mtf_enabled
    if(instrument_data->mtf_enabled) {
    if(cJSON_AddBoolToObject(item, "mtf_enabled", *instrument_data->mtf_enabled) == NULL) {
    goto fail; //Bool
    }
    }


    // instrument_data->mtf_bracket
    if(instrument_data->mtf_bracket) {
    if(cJSON_AddNumberToObject(item, "mtf_bracket", *instrument_data->mtf_bracket) == NULL) {
    goto fail; //Numeric
    }
    }


    // instrument_data->security_type
    if(instrument_data->security_type) {
    if(cJSON_AddStringToObject(item, "security_type", instrument_data->security_type) == NULL) {
    goto fail; //String
    }
    }


    // instrument_data->cas_eligible
    if(instrument_data->cas_eligible) {
    if(cJSON_AddBoolToObject(item, "cas_eligible", *instrument_data->cas_eligible) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instrument_data_t *instrument_data_parseFromJSON(cJSON *instrument_dataJSON){

    instrument_data_t *instrument_data_local_var = NULL;

    char *name_local_str = NULL;

    char *segment_local_str = NULL;

    char *exchange_local_str = NULL;

    char *isin_local_str = NULL;

    char *expiry_local_str = NULL;

    char *country_local_str = NULL;

    char *latency_local_str = NULL;

    char *description_local_str = NULL;

    char *currency_local_str = NULL;

    // define the local variable for instrument_data->weekly
    int *weekly_local_var = NULL;

    char *instrument_key_local_str = NULL;

    char *exchange_token_local_str = NULL;

    char *trading_symbol_local_str = NULL;

    char *short_name_local_str = NULL;

    // define the local variable for instrument_data->tick_size
    double *tick_size_local_var = NULL;

    // define the local variable for instrument_data->lot_size
    long *lot_size_local_var = NULL;

    char *instrument_type_local_str = NULL;

    // define the local variable for instrument_data->freeze_quantity
    double *freeze_quantity_local_var = NULL;

    char *underlying_key_local_str = NULL;

    char *underlying_type_local_str = NULL;

    char *underlying_symbol_local_str = NULL;

    char *last_trading_date_local_str = NULL;

    // define the local variable for instrument_data->strike_price
    double *strike_price_local_var = NULL;

    char *price_quote_unit_local_str = NULL;

    // define the local variable for instrument_data->qty_multiplier
    long *qty_multiplier_local_var = NULL;

    // define the local variable for instrument_data->minimum_lot
    long *minimum_lot_local_var = NULL;

    char *start_time_local_str = NULL;

    char *end_time_local_str = NULL;

    char *week_days_local_str = NULL;

    // define the local variable for instrument_data->general_denominator
    double *general_denominator_local_var = NULL;

    // define the local variable for instrument_data->general_numerator
    double *general_numerator_local_var = NULL;

    // define the local variable for instrument_data->price_numerator
    double *price_numerator_local_var = NULL;

    // define the local variable for instrument_data->price_denominator
    double *price_denominator_local_var = NULL;

    // define the local variable for instrument_data->mtf_enabled
    int *mtf_enabled_local_var = NULL;

    // define the local variable for instrument_data->mtf_bracket
    double *mtf_bracket_local_var = NULL;

    char *security_type_local_str = NULL;

    // define the local variable for instrument_data->cas_eligible
    int *cas_eligible_local_var = NULL;

    // instrument_data->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // instrument_data->segment
    cJSON *segment = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "segment");
    if (cJSON_IsNull(segment)) {
        segment = NULL;
    }
    if (segment) { 
    if(!cJSON_IsString(segment) && !cJSON_IsNull(segment))
    {
    goto end; //String
    }
    }

    // instrument_data->exchange
    cJSON *exchange = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "exchange");
    if (cJSON_IsNull(exchange)) {
        exchange = NULL;
    }
    if (exchange) { 
    if(!cJSON_IsString(exchange) && !cJSON_IsNull(exchange))
    {
    goto end; //String
    }
    }

    // instrument_data->isin
    cJSON *isin = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "isin");
    if (cJSON_IsNull(isin)) {
        isin = NULL;
    }
    if (isin) { 
    if(!cJSON_IsString(isin) && !cJSON_IsNull(isin))
    {
    goto end; //String
    }
    }

    // instrument_data->expiry
    cJSON *expiry = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "expiry");
    if (cJSON_IsNull(expiry)) {
        expiry = NULL;
    }
    if (expiry) { 
    if(!cJSON_IsString(expiry) && !cJSON_IsNull(expiry))
    {
    goto end; //DateTime
    }
    }

    // instrument_data->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // instrument_data->latency
    cJSON *latency = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "latency");
    if (cJSON_IsNull(latency)) {
        latency = NULL;
    }
    if (latency) { 
    if(!cJSON_IsString(latency) && !cJSON_IsNull(latency))
    {
    goto end; //String
    }
    }

    // instrument_data->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // instrument_data->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // instrument_data->weekly
    cJSON *weekly = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "weekly");
    if (cJSON_IsNull(weekly)) {
        weekly = NULL;
    }
    if (weekly) { 
    if(!cJSON_IsBool(weekly))
    {
    goto end; //Bool
    }
    weekly_local_var = malloc(sizeof(int));
    if(!weekly_local_var)
    {
        goto end;
    }
    *weekly_local_var = weekly->valueint;
    }

    // instrument_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // instrument_data->exchange_token
    cJSON *exchange_token = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "exchange_token");
    if (cJSON_IsNull(exchange_token)) {
        exchange_token = NULL;
    }
    if (exchange_token) { 
    if(!cJSON_IsString(exchange_token) && !cJSON_IsNull(exchange_token))
    {
    goto end; //String
    }
    }

    // instrument_data->trading_symbol
    cJSON *trading_symbol = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "trading_symbol");
    if (cJSON_IsNull(trading_symbol)) {
        trading_symbol = NULL;
    }
    if (trading_symbol) { 
    if(!cJSON_IsString(trading_symbol) && !cJSON_IsNull(trading_symbol))
    {
    goto end; //String
    }
    }

    // instrument_data->short_name
    cJSON *short_name = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "short_name");
    if (cJSON_IsNull(short_name)) {
        short_name = NULL;
    }
    if (short_name) { 
    if(!cJSON_IsString(short_name) && !cJSON_IsNull(short_name))
    {
    goto end; //String
    }
    }

    // instrument_data->tick_size
    cJSON *tick_size = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "tick_size");
    if (cJSON_IsNull(tick_size)) {
        tick_size = NULL;
    }
    if (tick_size) { 
    if(!cJSON_IsNumber(tick_size))
    {
    goto end; //Numeric
    }
    tick_size_local_var = malloc(sizeof(double));
    if(!tick_size_local_var)
    {
        goto end;
    }
    *tick_size_local_var = tick_size->valuedouble;
    }

    // instrument_data->lot_size
    cJSON *lot_size = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "lot_size");
    if (cJSON_IsNull(lot_size)) {
        lot_size = NULL;
    }
    if (lot_size) { 
    if(!cJSON_IsNumber(lot_size))
    {
    goto end; //Numeric
    }
    lot_size_local_var = malloc(sizeof(long));
    if(!lot_size_local_var)
    {
        goto end;
    }
    *lot_size_local_var = lot_size->valuedouble;
    }

    // instrument_data->instrument_type
    cJSON *instrument_type = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "instrument_type");
    if (cJSON_IsNull(instrument_type)) {
        instrument_type = NULL;
    }
    if (instrument_type) { 
    if(!cJSON_IsString(instrument_type) && !cJSON_IsNull(instrument_type))
    {
    goto end; //String
    }
    }

    // instrument_data->freeze_quantity
    cJSON *freeze_quantity = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "freeze_quantity");
    if (cJSON_IsNull(freeze_quantity)) {
        freeze_quantity = NULL;
    }
    if (freeze_quantity) { 
    if(!cJSON_IsNumber(freeze_quantity))
    {
    goto end; //Numeric
    }
    freeze_quantity_local_var = malloc(sizeof(double));
    if(!freeze_quantity_local_var)
    {
        goto end;
    }
    *freeze_quantity_local_var = freeze_quantity->valuedouble;
    }

    // instrument_data->underlying_key
    cJSON *underlying_key = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "underlying_key");
    if (cJSON_IsNull(underlying_key)) {
        underlying_key = NULL;
    }
    if (underlying_key) { 
    if(!cJSON_IsString(underlying_key) && !cJSON_IsNull(underlying_key))
    {
    goto end; //String
    }
    }

    // instrument_data->underlying_type
    cJSON *underlying_type = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "underlying_type");
    if (cJSON_IsNull(underlying_type)) {
        underlying_type = NULL;
    }
    if (underlying_type) { 
    if(!cJSON_IsString(underlying_type) && !cJSON_IsNull(underlying_type))
    {
    goto end; //String
    }
    }

    // instrument_data->underlying_symbol
    cJSON *underlying_symbol = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "underlying_symbol");
    if (cJSON_IsNull(underlying_symbol)) {
        underlying_symbol = NULL;
    }
    if (underlying_symbol) { 
    if(!cJSON_IsString(underlying_symbol) && !cJSON_IsNull(underlying_symbol))
    {
    goto end; //String
    }
    }

    // instrument_data->last_trading_date
    cJSON *last_trading_date = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "last_trading_date");
    if (cJSON_IsNull(last_trading_date)) {
        last_trading_date = NULL;
    }
    if (last_trading_date) { 
    if(!cJSON_IsString(last_trading_date) && !cJSON_IsNull(last_trading_date))
    {
    goto end; //DateTime
    }
    }

    // instrument_data->strike_price
    cJSON *strike_price = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "strike_price");
    if (cJSON_IsNull(strike_price)) {
        strike_price = NULL;
    }
    if (strike_price) { 
    if(!cJSON_IsNumber(strike_price))
    {
    goto end; //Numeric
    }
    strike_price_local_var = malloc(sizeof(double));
    if(!strike_price_local_var)
    {
        goto end;
    }
    *strike_price_local_var = strike_price->valuedouble;
    }

    // instrument_data->price_quote_unit
    cJSON *price_quote_unit = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "price_quote_unit");
    if (cJSON_IsNull(price_quote_unit)) {
        price_quote_unit = NULL;
    }
    if (price_quote_unit) { 
    if(!cJSON_IsString(price_quote_unit) && !cJSON_IsNull(price_quote_unit))
    {
    goto end; //String
    }
    }

    // instrument_data->qty_multiplier
    cJSON *qty_multiplier = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "qty_multiplier");
    if (cJSON_IsNull(qty_multiplier)) {
        qty_multiplier = NULL;
    }
    if (qty_multiplier) { 
    if(!cJSON_IsNumber(qty_multiplier))
    {
    goto end; //Numeric
    }
    qty_multiplier_local_var = malloc(sizeof(long));
    if(!qty_multiplier_local_var)
    {
        goto end;
    }
    *qty_multiplier_local_var = qty_multiplier->valuedouble;
    }

    // instrument_data->minimum_lot
    cJSON *minimum_lot = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "minimum_lot");
    if (cJSON_IsNull(minimum_lot)) {
        minimum_lot = NULL;
    }
    if (minimum_lot) { 
    if(!cJSON_IsNumber(minimum_lot))
    {
    goto end; //Numeric
    }
    minimum_lot_local_var = malloc(sizeof(long));
    if(!minimum_lot_local_var)
    {
        goto end;
    }
    *minimum_lot_local_var = minimum_lot->valuedouble;
    }

    // instrument_data->start_time
    cJSON *start_time = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "start_time");
    if (cJSON_IsNull(start_time)) {
        start_time = NULL;
    }
    if (start_time) { 
    if(!cJSON_IsString(start_time) && !cJSON_IsNull(start_time))
    {
    goto end; //String
    }
    }

    // instrument_data->end_time
    cJSON *end_time = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "end_time");
    if (cJSON_IsNull(end_time)) {
        end_time = NULL;
    }
    if (end_time) { 
    if(!cJSON_IsString(end_time) && !cJSON_IsNull(end_time))
    {
    goto end; //String
    }
    }

    // instrument_data->week_days
    cJSON *week_days = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "week_days");
    if (cJSON_IsNull(week_days)) {
        week_days = NULL;
    }
    if (week_days) { 
    if(!cJSON_IsString(week_days) && !cJSON_IsNull(week_days))
    {
    goto end; //String
    }
    }

    // instrument_data->general_denominator
    cJSON *general_denominator = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "general_denominator");
    if (cJSON_IsNull(general_denominator)) {
        general_denominator = NULL;
    }
    if (general_denominator) { 
    if(!cJSON_IsNumber(general_denominator))
    {
    goto end; //Numeric
    }
    general_denominator_local_var = malloc(sizeof(double));
    if(!general_denominator_local_var)
    {
        goto end;
    }
    *general_denominator_local_var = general_denominator->valuedouble;
    }

    // instrument_data->general_numerator
    cJSON *general_numerator = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "general_numerator");
    if (cJSON_IsNull(general_numerator)) {
        general_numerator = NULL;
    }
    if (general_numerator) { 
    if(!cJSON_IsNumber(general_numerator))
    {
    goto end; //Numeric
    }
    general_numerator_local_var = malloc(sizeof(double));
    if(!general_numerator_local_var)
    {
        goto end;
    }
    *general_numerator_local_var = general_numerator->valuedouble;
    }

    // instrument_data->price_numerator
    cJSON *price_numerator = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "price_numerator");
    if (cJSON_IsNull(price_numerator)) {
        price_numerator = NULL;
    }
    if (price_numerator) { 
    if(!cJSON_IsNumber(price_numerator))
    {
    goto end; //Numeric
    }
    price_numerator_local_var = malloc(sizeof(double));
    if(!price_numerator_local_var)
    {
        goto end;
    }
    *price_numerator_local_var = price_numerator->valuedouble;
    }

    // instrument_data->price_denominator
    cJSON *price_denominator = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "price_denominator");
    if (cJSON_IsNull(price_denominator)) {
        price_denominator = NULL;
    }
    if (price_denominator) { 
    if(!cJSON_IsNumber(price_denominator))
    {
    goto end; //Numeric
    }
    price_denominator_local_var = malloc(sizeof(double));
    if(!price_denominator_local_var)
    {
        goto end;
    }
    *price_denominator_local_var = price_denominator->valuedouble;
    }

    // instrument_data->mtf_enabled
    cJSON *mtf_enabled = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "mtf_enabled");
    if (cJSON_IsNull(mtf_enabled)) {
        mtf_enabled = NULL;
    }
    if (mtf_enabled) { 
    if(!cJSON_IsBool(mtf_enabled))
    {
    goto end; //Bool
    }
    mtf_enabled_local_var = malloc(sizeof(int));
    if(!mtf_enabled_local_var)
    {
        goto end;
    }
    *mtf_enabled_local_var = mtf_enabled->valueint;
    }

    // instrument_data->mtf_bracket
    cJSON *mtf_bracket = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "mtf_bracket");
    if (cJSON_IsNull(mtf_bracket)) {
        mtf_bracket = NULL;
    }
    if (mtf_bracket) { 
    if(!cJSON_IsNumber(mtf_bracket))
    {
    goto end; //Numeric
    }
    mtf_bracket_local_var = malloc(sizeof(double));
    if(!mtf_bracket_local_var)
    {
        goto end;
    }
    *mtf_bracket_local_var = mtf_bracket->valuedouble;
    }

    // instrument_data->security_type
    cJSON *security_type = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "security_type");
    if (cJSON_IsNull(security_type)) {
        security_type = NULL;
    }
    if (security_type) { 
    if(!cJSON_IsString(security_type) && !cJSON_IsNull(security_type))
    {
    goto end; //String
    }
    }

    // instrument_data->cas_eligible
    cJSON *cas_eligible = cJSON_GetObjectItemCaseSensitive(instrument_dataJSON, "cas_eligible");
    if (cJSON_IsNull(cas_eligible)) {
        cas_eligible = NULL;
    }
    if (cas_eligible) { 
    if(!cJSON_IsBool(cas_eligible))
    {
    goto end; //Bool
    }
    cas_eligible_local_var = malloc(sizeof(int));
    if(!cas_eligible_local_var)
    {
        goto end;
    }
    *cas_eligible_local_var = cas_eligible->valueint;
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (segment && !cJSON_IsNull(segment)) segment_local_str = strdup(segment->valuestring);
    if (exchange && !cJSON_IsNull(exchange)) exchange_local_str = strdup(exchange->valuestring);
    if (isin && !cJSON_IsNull(isin)) isin_local_str = strdup(isin->valuestring);
    if (expiry && !cJSON_IsNull(expiry)) expiry_local_str = strdup(expiry->valuestring);
    if (country && !cJSON_IsNull(country)) country_local_str = strdup(country->valuestring);
    if (latency && !cJSON_IsNull(latency)) latency_local_str = strdup(latency->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (exchange_token && !cJSON_IsNull(exchange_token)) exchange_token_local_str = strdup(exchange_token->valuestring);
    if (trading_symbol && !cJSON_IsNull(trading_symbol)) trading_symbol_local_str = strdup(trading_symbol->valuestring);
    if (short_name && !cJSON_IsNull(short_name)) short_name_local_str = strdup(short_name->valuestring);
    if (instrument_type && !cJSON_IsNull(instrument_type)) instrument_type_local_str = strdup(instrument_type->valuestring);
    if (underlying_key && !cJSON_IsNull(underlying_key)) underlying_key_local_str = strdup(underlying_key->valuestring);
    if (underlying_type && !cJSON_IsNull(underlying_type)) underlying_type_local_str = strdup(underlying_type->valuestring);
    if (underlying_symbol && !cJSON_IsNull(underlying_symbol)) underlying_symbol_local_str = strdup(underlying_symbol->valuestring);
    if (last_trading_date && !cJSON_IsNull(last_trading_date)) last_trading_date_local_str = strdup(last_trading_date->valuestring);
    if (price_quote_unit && !cJSON_IsNull(price_quote_unit)) price_quote_unit_local_str = strdup(price_quote_unit->valuestring);
    if (start_time && !cJSON_IsNull(start_time)) start_time_local_str = strdup(start_time->valuestring);
    if (end_time && !cJSON_IsNull(end_time)) end_time_local_str = strdup(end_time->valuestring);
    if (week_days && !cJSON_IsNull(week_days)) week_days_local_str = strdup(week_days->valuestring);
    if (security_type && !cJSON_IsNull(security_type)) security_type_local_str = strdup(security_type->valuestring);

    instrument_data_local_var = instrument_data_create_internal (
        name_local_str,
        segment_local_str,
        exchange_local_str,
        isin_local_str,
        expiry_local_str,
        country_local_str,
        latency_local_str,
        description_local_str,
        currency_local_str,
        weekly_local_var,
        instrument_key_local_str,
        exchange_token_local_str,
        trading_symbol_local_str,
        short_name_local_str,
        tick_size_local_var,
        lot_size_local_var,
        instrument_type_local_str,
        freeze_quantity_local_var,
        underlying_key_local_str,
        underlying_type_local_str,
        underlying_symbol_local_str,
        last_trading_date_local_str,
        strike_price_local_var,
        price_quote_unit_local_str,
        qty_multiplier_local_var,
        minimum_lot_local_var,
        start_time_local_str,
        end_time_local_str,
        week_days_local_str,
        general_denominator_local_var,
        general_numerator_local_var,
        price_numerator_local_var,
        price_denominator_local_var,
        mtf_enabled_local_var,
        mtf_bracket_local_var,
        security_type_local_str,
        cas_eligible_local_var
        );

    if (!instrument_data_local_var) {
        goto end;
    }

    return instrument_data_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (segment_local_str) {
        free(segment_local_str);
        segment_local_str = NULL;
    }
    if (exchange_local_str) {
        free(exchange_local_str);
        exchange_local_str = NULL;
    }
    if (isin_local_str) {
        free(isin_local_str);
        isin_local_str = NULL;
    }
    if (expiry_local_str) {
        free(expiry_local_str);
        expiry_local_str = NULL;
    }
    if (country_local_str) {
        free(country_local_str);
        country_local_str = NULL;
    }
    if (latency_local_str) {
        free(latency_local_str);
        latency_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (weekly_local_var) {
        free(weekly_local_var);
        weekly_local_var = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (exchange_token_local_str) {
        free(exchange_token_local_str);
        exchange_token_local_str = NULL;
    }
    if (trading_symbol_local_str) {
        free(trading_symbol_local_str);
        trading_symbol_local_str = NULL;
    }
    if (short_name_local_str) {
        free(short_name_local_str);
        short_name_local_str = NULL;
    }
    if (tick_size_local_var) {
        free(tick_size_local_var);
        tick_size_local_var = NULL;
    }
    if (lot_size_local_var) {
        free(lot_size_local_var);
        lot_size_local_var = NULL;
    }
    if (instrument_type_local_str) {
        free(instrument_type_local_str);
        instrument_type_local_str = NULL;
    }
    if (freeze_quantity_local_var) {
        free(freeze_quantity_local_var);
        freeze_quantity_local_var = NULL;
    }
    if (underlying_key_local_str) {
        free(underlying_key_local_str);
        underlying_key_local_str = NULL;
    }
    if (underlying_type_local_str) {
        free(underlying_type_local_str);
        underlying_type_local_str = NULL;
    }
    if (underlying_symbol_local_str) {
        free(underlying_symbol_local_str);
        underlying_symbol_local_str = NULL;
    }
    if (last_trading_date_local_str) {
        free(last_trading_date_local_str);
        last_trading_date_local_str = NULL;
    }
    if (strike_price_local_var) {
        free(strike_price_local_var);
        strike_price_local_var = NULL;
    }
    if (price_quote_unit_local_str) {
        free(price_quote_unit_local_str);
        price_quote_unit_local_str = NULL;
    }
    if (qty_multiplier_local_var) {
        free(qty_multiplier_local_var);
        qty_multiplier_local_var = NULL;
    }
    if (minimum_lot_local_var) {
        free(minimum_lot_local_var);
        minimum_lot_local_var = NULL;
    }
    if (start_time_local_str) {
        free(start_time_local_str);
        start_time_local_str = NULL;
    }
    if (end_time_local_str) {
        free(end_time_local_str);
        end_time_local_str = NULL;
    }
    if (week_days_local_str) {
        free(week_days_local_str);
        week_days_local_str = NULL;
    }
    if (general_denominator_local_var) {
        free(general_denominator_local_var);
        general_denominator_local_var = NULL;
    }
    if (general_numerator_local_var) {
        free(general_numerator_local_var);
        general_numerator_local_var = NULL;
    }
    if (price_numerator_local_var) {
        free(price_numerator_local_var);
        price_numerator_local_var = NULL;
    }
    if (price_denominator_local_var) {
        free(price_denominator_local_var);
        price_denominator_local_var = NULL;
    }
    if (mtf_enabled_local_var) {
        free(mtf_enabled_local_var);
        mtf_enabled_local_var = NULL;
    }
    if (mtf_bracket_local_var) {
        free(mtf_bracket_local_var);
        mtf_bracket_local_var = NULL;
    }
    if (security_type_local_str) {
        free(security_type_local_str);
        security_type_local_str = NULL;
    }
    if (cas_eligible_local_var) {
        free(cas_eligible_local_var);
        cas_eligible_local_var = NULL;
    }
    return NULL;

}
