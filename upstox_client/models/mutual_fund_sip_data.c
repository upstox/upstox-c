#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mutual_fund_sip_data.h"



static mutual_fund_sip_data_t *mutual_fund_sip_data_create_internal(
    char *fund,
    char *status,
    char *created,
    char *frequency,
    long *instalments,
    char *sip_id,
    char *sip_reg_number,
    char *instrument_key,
    char *dividend_type,
    char *transaction_type,
    char *next_instalment,
    double *instalment_amount,
    char *last_instalment,
    long *pending_instalments,
    long *instalment_day,
    long *completed_instalments,
    double *trigger_price,
    char *sip_type
    ) {
    mutual_fund_sip_data_t *mutual_fund_sip_data_local_var = malloc(sizeof(mutual_fund_sip_data_t));
    if (!mutual_fund_sip_data_local_var) {
        return NULL;
    }
    memset(mutual_fund_sip_data_local_var, 0, sizeof(mutual_fund_sip_data_t));
    mutual_fund_sip_data_local_var->_library_owned = 1;
    mutual_fund_sip_data_local_var->fund = fund;
    mutual_fund_sip_data_local_var->status = status;
    mutual_fund_sip_data_local_var->created = created;
    mutual_fund_sip_data_local_var->frequency = frequency;
    mutual_fund_sip_data_local_var->instalments = instalments;
    mutual_fund_sip_data_local_var->sip_id = sip_id;
    mutual_fund_sip_data_local_var->sip_reg_number = sip_reg_number;
    mutual_fund_sip_data_local_var->instrument_key = instrument_key;
    mutual_fund_sip_data_local_var->dividend_type = dividend_type;
    mutual_fund_sip_data_local_var->transaction_type = transaction_type;
    mutual_fund_sip_data_local_var->next_instalment = next_instalment;
    mutual_fund_sip_data_local_var->instalment_amount = instalment_amount;
    mutual_fund_sip_data_local_var->last_instalment = last_instalment;
    mutual_fund_sip_data_local_var->pending_instalments = pending_instalments;
    mutual_fund_sip_data_local_var->instalment_day = instalment_day;
    mutual_fund_sip_data_local_var->completed_instalments = completed_instalments;
    mutual_fund_sip_data_local_var->trigger_price = trigger_price;
    mutual_fund_sip_data_local_var->sip_type = sip_type;
    return mutual_fund_sip_data_local_var;
}

mutual_fund_sip_data_t *mutual_fund_sip_data_create(
    char *fund,
    char *status,
    char *created,
    char *frequency,
    long *instalments,
    char *sip_id,
    char *sip_reg_number,
    char *instrument_key,
    char *dividend_type,
    char *transaction_type,
    char *next_instalment,
    double *instalment_amount,
    char *last_instalment,
    long *pending_instalments,
    long *instalment_day,
    long *completed_instalments,
    double *trigger_price,
    char *sip_type
    ) {
    long *instalments_copy = NULL;
    if (instalments) {
        instalments_copy = malloc(sizeof(long));
        if (instalments_copy) *instalments_copy = *instalments;
    }
    double *instalment_amount_copy = NULL;
    if (instalment_amount) {
        instalment_amount_copy = malloc(sizeof(double));
        if (instalment_amount_copy) *instalment_amount_copy = *instalment_amount;
    }
    long *pending_instalments_copy = NULL;
    if (pending_instalments) {
        pending_instalments_copy = malloc(sizeof(long));
        if (pending_instalments_copy) *pending_instalments_copy = *pending_instalments;
    }
    long *instalment_day_copy = NULL;
    if (instalment_day) {
        instalment_day_copy = malloc(sizeof(long));
        if (instalment_day_copy) *instalment_day_copy = *instalment_day;
    }
    long *completed_instalments_copy = NULL;
    if (completed_instalments) {
        completed_instalments_copy = malloc(sizeof(long));
        if (completed_instalments_copy) *completed_instalments_copy = *completed_instalments;
    }
    double *trigger_price_copy = NULL;
    if (trigger_price) {
        trigger_price_copy = malloc(sizeof(double));
        if (trigger_price_copy) *trigger_price_copy = *trigger_price;
    }
    mutual_fund_sip_data_t *result = mutual_fund_sip_data_create_internal (
        fund,
        status,
        created,
        frequency,
        instalments_copy,
        sip_id,
        sip_reg_number,
        instrument_key,
        dividend_type,
        transaction_type,
        next_instalment,
        instalment_amount_copy,
        last_instalment,
        pending_instalments_copy,
        instalment_day_copy,
        completed_instalments_copy,
        trigger_price_copy,
        sip_type
        );
    if (!result) {
        free(instalments_copy);
        free(instalment_amount_copy);
        free(pending_instalments_copy);
        free(instalment_day_copy);
        free(completed_instalments_copy);
        free(trigger_price_copy);
    }
    return result;
}

void mutual_fund_sip_data_free(mutual_fund_sip_data_t *mutual_fund_sip_data) {
    if(NULL == mutual_fund_sip_data){
        return ;
    }
    if(mutual_fund_sip_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mutual_fund_sip_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mutual_fund_sip_data->fund) {
        free(mutual_fund_sip_data->fund);
        mutual_fund_sip_data->fund = NULL;
    }
    if (mutual_fund_sip_data->status) {
        free(mutual_fund_sip_data->status);
        mutual_fund_sip_data->status = NULL;
    }
    if (mutual_fund_sip_data->created) {
        free(mutual_fund_sip_data->created);
        mutual_fund_sip_data->created = NULL;
    }
    if (mutual_fund_sip_data->frequency) {
        free(mutual_fund_sip_data->frequency);
        mutual_fund_sip_data->frequency = NULL;
    }
    if (mutual_fund_sip_data->instalments) {
        free(mutual_fund_sip_data->instalments);
        mutual_fund_sip_data->instalments = NULL;
    }
    if (mutual_fund_sip_data->sip_id) {
        free(mutual_fund_sip_data->sip_id);
        mutual_fund_sip_data->sip_id = NULL;
    }
    if (mutual_fund_sip_data->sip_reg_number) {
        free(mutual_fund_sip_data->sip_reg_number);
        mutual_fund_sip_data->sip_reg_number = NULL;
    }
    if (mutual_fund_sip_data->instrument_key) {
        free(mutual_fund_sip_data->instrument_key);
        mutual_fund_sip_data->instrument_key = NULL;
    }
    if (mutual_fund_sip_data->dividend_type) {
        free(mutual_fund_sip_data->dividend_type);
        mutual_fund_sip_data->dividend_type = NULL;
    }
    if (mutual_fund_sip_data->transaction_type) {
        free(mutual_fund_sip_data->transaction_type);
        mutual_fund_sip_data->transaction_type = NULL;
    }
    if (mutual_fund_sip_data->next_instalment) {
        free(mutual_fund_sip_data->next_instalment);
        mutual_fund_sip_data->next_instalment = NULL;
    }
    if (mutual_fund_sip_data->instalment_amount) {
        free(mutual_fund_sip_data->instalment_amount);
        mutual_fund_sip_data->instalment_amount = NULL;
    }
    if (mutual_fund_sip_data->last_instalment) {
        free(mutual_fund_sip_data->last_instalment);
        mutual_fund_sip_data->last_instalment = NULL;
    }
    if (mutual_fund_sip_data->pending_instalments) {
        free(mutual_fund_sip_data->pending_instalments);
        mutual_fund_sip_data->pending_instalments = NULL;
    }
    if (mutual_fund_sip_data->instalment_day) {
        free(mutual_fund_sip_data->instalment_day);
        mutual_fund_sip_data->instalment_day = NULL;
    }
    if (mutual_fund_sip_data->completed_instalments) {
        free(mutual_fund_sip_data->completed_instalments);
        mutual_fund_sip_data->completed_instalments = NULL;
    }
    if (mutual_fund_sip_data->trigger_price) {
        free(mutual_fund_sip_data->trigger_price);
        mutual_fund_sip_data->trigger_price = NULL;
    }
    if (mutual_fund_sip_data->sip_type) {
        free(mutual_fund_sip_data->sip_type);
        mutual_fund_sip_data->sip_type = NULL;
    }
    free(mutual_fund_sip_data);
}

cJSON *mutual_fund_sip_data_convertToJSON(mutual_fund_sip_data_t *mutual_fund_sip_data) {
    cJSON *item = cJSON_CreateObject();

    // mutual_fund_sip_data->fund
    if(mutual_fund_sip_data->fund) {
    if(cJSON_AddStringToObject(item, "fund", mutual_fund_sip_data->fund) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->status
    if(mutual_fund_sip_data->status) {
    if(cJSON_AddStringToObject(item, "status", mutual_fund_sip_data->status) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->created
    if(mutual_fund_sip_data->created) {
    if(cJSON_AddStringToObject(item, "created", mutual_fund_sip_data->created) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->frequency
    if(mutual_fund_sip_data->frequency) {
    if(cJSON_AddStringToObject(item, "frequency", mutual_fund_sip_data->frequency) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->instalments
    if(mutual_fund_sip_data->instalments) {
    if(cJSON_AddNumberToObject(item, "instalments", *mutual_fund_sip_data->instalments) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->sip_id
    if(mutual_fund_sip_data->sip_id) {
    if(cJSON_AddStringToObject(item, "sip_id", mutual_fund_sip_data->sip_id) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->sip_reg_number
    if(mutual_fund_sip_data->sip_reg_number) {
    if(cJSON_AddStringToObject(item, "sip_reg_number", mutual_fund_sip_data->sip_reg_number) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->instrument_key
    if(mutual_fund_sip_data->instrument_key) {
    if(cJSON_AddStringToObject(item, "instrument_key", mutual_fund_sip_data->instrument_key) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->dividend_type
    if(mutual_fund_sip_data->dividend_type) {
    if(cJSON_AddStringToObject(item, "dividend_type", mutual_fund_sip_data->dividend_type) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->transaction_type
    if(mutual_fund_sip_data->transaction_type) {
    if(cJSON_AddStringToObject(item, "transaction_type", mutual_fund_sip_data->transaction_type) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->next_instalment
    if(mutual_fund_sip_data->next_instalment) {
    if(cJSON_AddStringToObject(item, "next_instalment", mutual_fund_sip_data->next_instalment) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->instalment_amount
    if(mutual_fund_sip_data->instalment_amount) {
    if(cJSON_AddNumberToObject(item, "instalment_amount", *mutual_fund_sip_data->instalment_amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->last_instalment
    if(mutual_fund_sip_data->last_instalment) {
    if(cJSON_AddStringToObject(item, "last_instalment", mutual_fund_sip_data->last_instalment) == NULL) {
    goto fail; //String
    }
    }


    // mutual_fund_sip_data->pending_instalments
    if(mutual_fund_sip_data->pending_instalments) {
    if(cJSON_AddNumberToObject(item, "pending_instalments", *mutual_fund_sip_data->pending_instalments) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->instalment_day
    if(mutual_fund_sip_data->instalment_day) {
    if(cJSON_AddNumberToObject(item, "instalment_day", *mutual_fund_sip_data->instalment_day) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->completed_instalments
    if(mutual_fund_sip_data->completed_instalments) {
    if(cJSON_AddNumberToObject(item, "completed_instalments", *mutual_fund_sip_data->completed_instalments) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->trigger_price
    if(mutual_fund_sip_data->trigger_price) {
    if(cJSON_AddNumberToObject(item, "trigger_price", *mutual_fund_sip_data->trigger_price) == NULL) {
    goto fail; //Numeric
    }
    }


    // mutual_fund_sip_data->sip_type
    if(mutual_fund_sip_data->sip_type) {
    if(cJSON_AddStringToObject(item, "sip_type", mutual_fund_sip_data->sip_type) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

mutual_fund_sip_data_t *mutual_fund_sip_data_parseFromJSON(cJSON *mutual_fund_sip_dataJSON){

    mutual_fund_sip_data_t *mutual_fund_sip_data_local_var = NULL;

    char *fund_local_str = NULL;

    char *status_local_str = NULL;

    char *created_local_str = NULL;

    char *frequency_local_str = NULL;

    // define the local variable for mutual_fund_sip_data->instalments
    long *instalments_local_var = NULL;

    char *sip_id_local_str = NULL;

    char *sip_reg_number_local_str = NULL;

    char *instrument_key_local_str = NULL;

    char *dividend_type_local_str = NULL;

    char *transaction_type_local_str = NULL;

    char *next_instalment_local_str = NULL;

    // define the local variable for mutual_fund_sip_data->instalment_amount
    double *instalment_amount_local_var = NULL;

    char *last_instalment_local_str = NULL;

    // define the local variable for mutual_fund_sip_data->pending_instalments
    long *pending_instalments_local_var = NULL;

    // define the local variable for mutual_fund_sip_data->instalment_day
    long *instalment_day_local_var = NULL;

    // define the local variable for mutual_fund_sip_data->completed_instalments
    long *completed_instalments_local_var = NULL;

    // define the local variable for mutual_fund_sip_data->trigger_price
    double *trigger_price_local_var = NULL;

    char *sip_type_local_str = NULL;

    // mutual_fund_sip_data->fund
    cJSON *fund = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "fund");
    if (cJSON_IsNull(fund)) {
        fund = NULL;
    }
    if (fund) { 
    if(!cJSON_IsString(fund) && !cJSON_IsNull(fund))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (created) { 
    if(!cJSON_IsString(created) && !cJSON_IsNull(created))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->frequency
    cJSON *frequency = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "frequency");
    if (cJSON_IsNull(frequency)) {
        frequency = NULL;
    }
    if (frequency) { 
    if(!cJSON_IsString(frequency) && !cJSON_IsNull(frequency))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->instalments
    cJSON *instalments = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "instalments");
    if (cJSON_IsNull(instalments)) {
        instalments = NULL;
    }
    if (instalments) { 
    if(!cJSON_IsNumber(instalments))
    {
    goto end; //Numeric
    }
    instalments_local_var = malloc(sizeof(long));
    if(!instalments_local_var)
    {
        goto end;
    }
    *instalments_local_var = instalments->valuedouble;
    }

    // mutual_fund_sip_data->sip_id
    cJSON *sip_id = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "sip_id");
    if (cJSON_IsNull(sip_id)) {
        sip_id = NULL;
    }
    if (sip_id) { 
    if(!cJSON_IsString(sip_id) && !cJSON_IsNull(sip_id))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->sip_reg_number
    cJSON *sip_reg_number = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "sip_reg_number");
    if (cJSON_IsNull(sip_reg_number)) {
        sip_reg_number = NULL;
    }
    if (sip_reg_number) { 
    if(!cJSON_IsString(sip_reg_number) && !cJSON_IsNull(sip_reg_number))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->instrument_key
    cJSON *instrument_key = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "instrument_key");
    if (cJSON_IsNull(instrument_key)) {
        instrument_key = NULL;
    }
    if (instrument_key) { 
    if(!cJSON_IsString(instrument_key) && !cJSON_IsNull(instrument_key))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->dividend_type
    cJSON *dividend_type = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "dividend_type");
    if (cJSON_IsNull(dividend_type)) {
        dividend_type = NULL;
    }
    if (dividend_type) { 
    if(!cJSON_IsString(dividend_type) && !cJSON_IsNull(dividend_type))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->transaction_type
    cJSON *transaction_type = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "transaction_type");
    if (cJSON_IsNull(transaction_type)) {
        transaction_type = NULL;
    }
    if (transaction_type) { 
    if(!cJSON_IsString(transaction_type) && !cJSON_IsNull(transaction_type))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->next_instalment
    cJSON *next_instalment = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "next_instalment");
    if (cJSON_IsNull(next_instalment)) {
        next_instalment = NULL;
    }
    if (next_instalment) { 
    if(!cJSON_IsString(next_instalment) && !cJSON_IsNull(next_instalment))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->instalment_amount
    cJSON *instalment_amount = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "instalment_amount");
    if (cJSON_IsNull(instalment_amount)) {
        instalment_amount = NULL;
    }
    if (instalment_amount) { 
    if(!cJSON_IsNumber(instalment_amount))
    {
    goto end; //Numeric
    }
    instalment_amount_local_var = malloc(sizeof(double));
    if(!instalment_amount_local_var)
    {
        goto end;
    }
    *instalment_amount_local_var = instalment_amount->valuedouble;
    }

    // mutual_fund_sip_data->last_instalment
    cJSON *last_instalment = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "last_instalment");
    if (cJSON_IsNull(last_instalment)) {
        last_instalment = NULL;
    }
    if (last_instalment) { 
    if(!cJSON_IsString(last_instalment) && !cJSON_IsNull(last_instalment))
    {
    goto end; //String
    }
    }

    // mutual_fund_sip_data->pending_instalments
    cJSON *pending_instalments = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "pending_instalments");
    if (cJSON_IsNull(pending_instalments)) {
        pending_instalments = NULL;
    }
    if (pending_instalments) { 
    if(!cJSON_IsNumber(pending_instalments))
    {
    goto end; //Numeric
    }
    pending_instalments_local_var = malloc(sizeof(long));
    if(!pending_instalments_local_var)
    {
        goto end;
    }
    *pending_instalments_local_var = pending_instalments->valuedouble;
    }

    // mutual_fund_sip_data->instalment_day
    cJSON *instalment_day = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "instalment_day");
    if (cJSON_IsNull(instalment_day)) {
        instalment_day = NULL;
    }
    if (instalment_day) { 
    if(!cJSON_IsNumber(instalment_day))
    {
    goto end; //Numeric
    }
    instalment_day_local_var = malloc(sizeof(long));
    if(!instalment_day_local_var)
    {
        goto end;
    }
    *instalment_day_local_var = instalment_day->valuedouble;
    }

    // mutual_fund_sip_data->completed_instalments
    cJSON *completed_instalments = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "completed_instalments");
    if (cJSON_IsNull(completed_instalments)) {
        completed_instalments = NULL;
    }
    if (completed_instalments) { 
    if(!cJSON_IsNumber(completed_instalments))
    {
    goto end; //Numeric
    }
    completed_instalments_local_var = malloc(sizeof(long));
    if(!completed_instalments_local_var)
    {
        goto end;
    }
    *completed_instalments_local_var = completed_instalments->valuedouble;
    }

    // mutual_fund_sip_data->trigger_price
    cJSON *trigger_price = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "trigger_price");
    if (cJSON_IsNull(trigger_price)) {
        trigger_price = NULL;
    }
    if (trigger_price) { 
    if(!cJSON_IsNumber(trigger_price))
    {
    goto end; //Numeric
    }
    trigger_price_local_var = malloc(sizeof(double));
    if(!trigger_price_local_var)
    {
        goto end;
    }
    *trigger_price_local_var = trigger_price->valuedouble;
    }

    // mutual_fund_sip_data->sip_type
    cJSON *sip_type = cJSON_GetObjectItemCaseSensitive(mutual_fund_sip_dataJSON, "sip_type");
    if (cJSON_IsNull(sip_type)) {
        sip_type = NULL;
    }
    if (sip_type) { 
    if(!cJSON_IsString(sip_type) && !cJSON_IsNull(sip_type))
    {
    goto end; //String
    }
    }


    if (fund && !cJSON_IsNull(fund)) fund_local_str = strdup(fund->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (created && !cJSON_IsNull(created)) created_local_str = strdup(created->valuestring);
    if (frequency && !cJSON_IsNull(frequency)) frequency_local_str = strdup(frequency->valuestring);
    if (sip_id && !cJSON_IsNull(sip_id)) sip_id_local_str = strdup(sip_id->valuestring);
    if (sip_reg_number && !cJSON_IsNull(sip_reg_number)) sip_reg_number_local_str = strdup(sip_reg_number->valuestring);
    if (instrument_key && !cJSON_IsNull(instrument_key)) instrument_key_local_str = strdup(instrument_key->valuestring);
    if (dividend_type && !cJSON_IsNull(dividend_type)) dividend_type_local_str = strdup(dividend_type->valuestring);
    if (transaction_type && !cJSON_IsNull(transaction_type)) transaction_type_local_str = strdup(transaction_type->valuestring);
    if (next_instalment && !cJSON_IsNull(next_instalment)) next_instalment_local_str = strdup(next_instalment->valuestring);
    if (last_instalment && !cJSON_IsNull(last_instalment)) last_instalment_local_str = strdup(last_instalment->valuestring);
    if (sip_type && !cJSON_IsNull(sip_type)) sip_type_local_str = strdup(sip_type->valuestring);

    mutual_fund_sip_data_local_var = mutual_fund_sip_data_create_internal (
        fund_local_str,
        status_local_str,
        created_local_str,
        frequency_local_str,
        instalments_local_var,
        sip_id_local_str,
        sip_reg_number_local_str,
        instrument_key_local_str,
        dividend_type_local_str,
        transaction_type_local_str,
        next_instalment_local_str,
        instalment_amount_local_var,
        last_instalment_local_str,
        pending_instalments_local_var,
        instalment_day_local_var,
        completed_instalments_local_var,
        trigger_price_local_var,
        sip_type_local_str
        );

    if (!mutual_fund_sip_data_local_var) {
        goto end;
    }

    return mutual_fund_sip_data_local_var;
end:
    if (fund_local_str) {
        free(fund_local_str);
        fund_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (created_local_str) {
        free(created_local_str);
        created_local_str = NULL;
    }
    if (frequency_local_str) {
        free(frequency_local_str);
        frequency_local_str = NULL;
    }
    if (instalments_local_var) {
        free(instalments_local_var);
        instalments_local_var = NULL;
    }
    if (sip_id_local_str) {
        free(sip_id_local_str);
        sip_id_local_str = NULL;
    }
    if (sip_reg_number_local_str) {
        free(sip_reg_number_local_str);
        sip_reg_number_local_str = NULL;
    }
    if (instrument_key_local_str) {
        free(instrument_key_local_str);
        instrument_key_local_str = NULL;
    }
    if (dividend_type_local_str) {
        free(dividend_type_local_str);
        dividend_type_local_str = NULL;
    }
    if (transaction_type_local_str) {
        free(transaction_type_local_str);
        transaction_type_local_str = NULL;
    }
    if (next_instalment_local_str) {
        free(next_instalment_local_str);
        next_instalment_local_str = NULL;
    }
    if (instalment_amount_local_var) {
        free(instalment_amount_local_var);
        instalment_amount_local_var = NULL;
    }
    if (last_instalment_local_str) {
        free(last_instalment_local_str);
        last_instalment_local_str = NULL;
    }
    if (pending_instalments_local_var) {
        free(pending_instalments_local_var);
        pending_instalments_local_var = NULL;
    }
    if (instalment_day_local_var) {
        free(instalment_day_local_var);
        instalment_day_local_var = NULL;
    }
    if (completed_instalments_local_var) {
        free(completed_instalments_local_var);
        completed_instalments_local_var = NULL;
    }
    if (trigger_price_local_var) {
        free(trigger_price_local_var);
        trigger_price_local_var = NULL;
    }
    if (sip_type_local_str) {
        free(sip_type_local_str);
        sip_type_local_str = NULL;
    }
    return NULL;

}
