#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payment_history_data.h"



static payment_history_data_t *payment_history_data_create_internal(
    double *amount,
    char *mode,
    char *status,
    char *reason,
    char *currency,
    char *eta,
    char *last_updated_at,
    char *bank_name,
    char *transaction_id,
    double *total_charges,
    char *charges_category,
    char *created_at
    ) {
    payment_history_data_t *payment_history_data_local_var = malloc(sizeof(payment_history_data_t));
    if (!payment_history_data_local_var) {
        return NULL;
    }
    memset(payment_history_data_local_var, 0, sizeof(payment_history_data_t));
    payment_history_data_local_var->_library_owned = 1;
    payment_history_data_local_var->amount = amount;
    payment_history_data_local_var->mode = mode;
    payment_history_data_local_var->status = status;
    payment_history_data_local_var->reason = reason;
    payment_history_data_local_var->currency = currency;
    payment_history_data_local_var->eta = eta;
    payment_history_data_local_var->last_updated_at = last_updated_at;
    payment_history_data_local_var->bank_name = bank_name;
    payment_history_data_local_var->transaction_id = transaction_id;
    payment_history_data_local_var->total_charges = total_charges;
    payment_history_data_local_var->charges_category = charges_category;
    payment_history_data_local_var->created_at = created_at;
    return payment_history_data_local_var;
}

payment_history_data_t *payment_history_data_create(
    double *amount,
    char *mode,
    char *status,
    char *reason,
    char *currency,
    char *eta,
    char *last_updated_at,
    char *bank_name,
    char *transaction_id,
    double *total_charges,
    char *charges_category,
    char *created_at
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    double *total_charges_copy = NULL;
    if (total_charges) {
        total_charges_copy = malloc(sizeof(double));
        if (total_charges_copy) *total_charges_copy = *total_charges;
    }
    payment_history_data_t *result = payment_history_data_create_internal (
        amount_copy,
        mode,
        status,
        reason,
        currency,
        eta,
        last_updated_at,
        bank_name,
        transaction_id,
        total_charges_copy,
        charges_category,
        created_at
        );
    if (!result) {
        free(amount_copy);
        free(total_charges_copy);
    }
    return result;
}

void payment_history_data_free(payment_history_data_t *payment_history_data) {
    if(NULL == payment_history_data){
        return ;
    }
    if(payment_history_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payment_history_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payment_history_data->amount) {
        free(payment_history_data->amount);
        payment_history_data->amount = NULL;
    }
    if (payment_history_data->mode) {
        free(payment_history_data->mode);
        payment_history_data->mode = NULL;
    }
    if (payment_history_data->status) {
        free(payment_history_data->status);
        payment_history_data->status = NULL;
    }
    if (payment_history_data->reason) {
        free(payment_history_data->reason);
        payment_history_data->reason = NULL;
    }
    if (payment_history_data->currency) {
        free(payment_history_data->currency);
        payment_history_data->currency = NULL;
    }
    if (payment_history_data->eta) {
        free(payment_history_data->eta);
        payment_history_data->eta = NULL;
    }
    if (payment_history_data->last_updated_at) {
        free(payment_history_data->last_updated_at);
        payment_history_data->last_updated_at = NULL;
    }
    if (payment_history_data->bank_name) {
        free(payment_history_data->bank_name);
        payment_history_data->bank_name = NULL;
    }
    if (payment_history_data->transaction_id) {
        free(payment_history_data->transaction_id);
        payment_history_data->transaction_id = NULL;
    }
    if (payment_history_data->total_charges) {
        free(payment_history_data->total_charges);
        payment_history_data->total_charges = NULL;
    }
    if (payment_history_data->charges_category) {
        free(payment_history_data->charges_category);
        payment_history_data->charges_category = NULL;
    }
    if (payment_history_data->created_at) {
        free(payment_history_data->created_at);
        payment_history_data->created_at = NULL;
    }
    free(payment_history_data);
}

cJSON *payment_history_data_convertToJSON(payment_history_data_t *payment_history_data) {
    cJSON *item = cJSON_CreateObject();

    // payment_history_data->amount
    if(payment_history_data->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *payment_history_data->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // payment_history_data->mode
    if(payment_history_data->mode) {
    if(cJSON_AddStringToObject(item, "mode", payment_history_data->mode) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->status
    if(payment_history_data->status) {
    if(cJSON_AddStringToObject(item, "status", payment_history_data->status) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->reason
    if(payment_history_data->reason) {
    if(cJSON_AddStringToObject(item, "reason", payment_history_data->reason) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->currency
    if(payment_history_data->currency) {
    if(cJSON_AddStringToObject(item, "currency", payment_history_data->currency) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->eta
    if(payment_history_data->eta) {
    if(cJSON_AddStringToObject(item, "eta", payment_history_data->eta) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->last_updated_at
    if(payment_history_data->last_updated_at) {
    if(cJSON_AddStringToObject(item, "last_updated_at", payment_history_data->last_updated_at) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->bank_name
    if(payment_history_data->bank_name) {
    if(cJSON_AddStringToObject(item, "bank_name", payment_history_data->bank_name) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->transaction_id
    if(payment_history_data->transaction_id) {
    if(cJSON_AddStringToObject(item, "transaction_id", payment_history_data->transaction_id) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->total_charges
    if(payment_history_data->total_charges) {
    if(cJSON_AddNumberToObject(item, "total_charges", *payment_history_data->total_charges) == NULL) {
    goto fail; //Numeric
    }
    }


    // payment_history_data->charges_category
    if(payment_history_data->charges_category) {
    if(cJSON_AddStringToObject(item, "charges_category", payment_history_data->charges_category) == NULL) {
    goto fail; //String
    }
    }


    // payment_history_data->created_at
    if(payment_history_data->created_at) {
    if(cJSON_AddStringToObject(item, "created_at", payment_history_data->created_at) == NULL) {
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

payment_history_data_t *payment_history_data_parseFromJSON(cJSON *payment_history_dataJSON){

    payment_history_data_t *payment_history_data_local_var = NULL;

    // define the local variable for payment_history_data->amount
    double *amount_local_var = NULL;

    char *mode_local_str = NULL;

    char *status_local_str = NULL;

    char *reason_local_str = NULL;

    char *currency_local_str = NULL;

    char *eta_local_str = NULL;

    char *last_updated_at_local_str = NULL;

    char *bank_name_local_str = NULL;

    char *transaction_id_local_str = NULL;

    // define the local variable for payment_history_data->total_charges
    double *total_charges_local_var = NULL;

    char *charges_category_local_str = NULL;

    char *created_at_local_str = NULL;

    // payment_history_data->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "amount");
    if (cJSON_IsNull(amount)) {
        amount = NULL;
    }
    if (amount) { 
    if(!cJSON_IsNumber(amount))
    {
    goto end; //Numeric
    }
    amount_local_var = malloc(sizeof(double));
    if(!amount_local_var)
    {
        goto end;
    }
    *amount_local_var = amount->valuedouble;
    }

    // payment_history_data->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (mode) { 
    if(!cJSON_IsString(mode) && !cJSON_IsNull(mode))
    {
    goto end; //String
    }
    }

    // payment_history_data->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // payment_history_data->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }

    // payment_history_data->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // payment_history_data->eta
    cJSON *eta = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "eta");
    if (cJSON_IsNull(eta)) {
        eta = NULL;
    }
    if (eta) { 
    if(!cJSON_IsString(eta) && !cJSON_IsNull(eta))
    {
    goto end; //String
    }
    }

    // payment_history_data->last_updated_at
    cJSON *last_updated_at = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "last_updated_at");
    if (cJSON_IsNull(last_updated_at)) {
        last_updated_at = NULL;
    }
    if (last_updated_at) { 
    if(!cJSON_IsString(last_updated_at) && !cJSON_IsNull(last_updated_at))
    {
    goto end; //String
    }
    }

    // payment_history_data->bank_name
    cJSON *bank_name = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "bank_name");
    if (cJSON_IsNull(bank_name)) {
        bank_name = NULL;
    }
    if (bank_name) { 
    if(!cJSON_IsString(bank_name) && !cJSON_IsNull(bank_name))
    {
    goto end; //String
    }
    }

    // payment_history_data->transaction_id
    cJSON *transaction_id = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "transaction_id");
    if (cJSON_IsNull(transaction_id)) {
        transaction_id = NULL;
    }
    if (transaction_id) { 
    if(!cJSON_IsString(transaction_id) && !cJSON_IsNull(transaction_id))
    {
    goto end; //String
    }
    }

    // payment_history_data->total_charges
    cJSON *total_charges = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "total_charges");
    if (cJSON_IsNull(total_charges)) {
        total_charges = NULL;
    }
    if (total_charges) { 
    if(!cJSON_IsNumber(total_charges))
    {
    goto end; //Numeric
    }
    total_charges_local_var = malloc(sizeof(double));
    if(!total_charges_local_var)
    {
        goto end;
    }
    *total_charges_local_var = total_charges->valuedouble;
    }

    // payment_history_data->charges_category
    cJSON *charges_category = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "charges_category");
    if (cJSON_IsNull(charges_category)) {
        charges_category = NULL;
    }
    if (charges_category) { 
    if(!cJSON_IsString(charges_category) && !cJSON_IsNull(charges_category))
    {
    goto end; //String
    }
    }

    // payment_history_data->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(payment_history_dataJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }


    if (mode && !cJSON_IsNull(mode)) mode_local_str = strdup(mode->valuestring);
    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (eta && !cJSON_IsNull(eta)) eta_local_str = strdup(eta->valuestring);
    if (last_updated_at && !cJSON_IsNull(last_updated_at)) last_updated_at_local_str = strdup(last_updated_at->valuestring);
    if (bank_name && !cJSON_IsNull(bank_name)) bank_name_local_str = strdup(bank_name->valuestring);
    if (transaction_id && !cJSON_IsNull(transaction_id)) transaction_id_local_str = strdup(transaction_id->valuestring);
    if (charges_category && !cJSON_IsNull(charges_category)) charges_category_local_str = strdup(charges_category->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);

    payment_history_data_local_var = payment_history_data_create_internal (
        amount_local_var,
        mode_local_str,
        status_local_str,
        reason_local_str,
        currency_local_str,
        eta_local_str,
        last_updated_at_local_str,
        bank_name_local_str,
        transaction_id_local_str,
        total_charges_local_var,
        charges_category_local_str,
        created_at_local_str
        );

    if (!payment_history_data_local_var) {
        goto end;
    }

    return payment_history_data_local_var;
end:
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (mode_local_str) {
        free(mode_local_str);
        mode_local_str = NULL;
    }
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (eta_local_str) {
        free(eta_local_str);
        eta_local_str = NULL;
    }
    if (last_updated_at_local_str) {
        free(last_updated_at_local_str);
        last_updated_at_local_str = NULL;
    }
    if (bank_name_local_str) {
        free(bank_name_local_str);
        bank_name_local_str = NULL;
    }
    if (transaction_id_local_str) {
        free(transaction_id_local_str);
        transaction_id_local_str = NULL;
    }
    if (total_charges_local_var) {
        free(total_charges_local_var);
        total_charges_local_var = NULL;
    }
    if (charges_category_local_str) {
        free(charges_category_local_str);
        charges_category_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    return NULL;

}
