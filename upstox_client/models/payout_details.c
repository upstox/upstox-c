#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "payout_details.h"



static payout_details_t *payout_details_create_internal(
    char *status,
    char *mode,
    double *amount,
    char *currency,
    char *eta,
    char *message,
    char *transaction_id,
    char *created_at,
    char *bank_name,
    char *transaction_fee
    ) {
    payout_details_t *payout_details_local_var = malloc(sizeof(payout_details_t));
    if (!payout_details_local_var) {
        return NULL;
    }
    memset(payout_details_local_var, 0, sizeof(payout_details_t));
    payout_details_local_var->_library_owned = 1;
    payout_details_local_var->status = status;
    payout_details_local_var->mode = mode;
    payout_details_local_var->amount = amount;
    payout_details_local_var->currency = currency;
    payout_details_local_var->eta = eta;
    payout_details_local_var->message = message;
    payout_details_local_var->transaction_id = transaction_id;
    payout_details_local_var->created_at = created_at;
    payout_details_local_var->bank_name = bank_name;
    payout_details_local_var->transaction_fee = transaction_fee;
    return payout_details_local_var;
}

payout_details_t *payout_details_create(
    char *status,
    char *mode,
    double *amount,
    char *currency,
    char *eta,
    char *message,
    char *transaction_id,
    char *created_at,
    char *bank_name,
    char *transaction_fee
    ) {
    double *amount_copy = NULL;
    if (amount) {
        amount_copy = malloc(sizeof(double));
        if (amount_copy) *amount_copy = *amount;
    }
    payout_details_t *result = payout_details_create_internal (
        status,
        mode,
        amount_copy,
        currency,
        eta,
        message,
        transaction_id,
        created_at,
        bank_name,
        transaction_fee
        );
    if (!result) {
        free(amount_copy);
    }
    return result;
}

void payout_details_free(payout_details_t *payout_details) {
    if(NULL == payout_details){
        return ;
    }
    if(payout_details->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "payout_details_free");
        return ;
    }
    listEntry_t *listEntry;
    if (payout_details->status) {
        free(payout_details->status);
        payout_details->status = NULL;
    }
    if (payout_details->mode) {
        free(payout_details->mode);
        payout_details->mode = NULL;
    }
    if (payout_details->amount) {
        free(payout_details->amount);
        payout_details->amount = NULL;
    }
    if (payout_details->currency) {
        free(payout_details->currency);
        payout_details->currency = NULL;
    }
    if (payout_details->eta) {
        free(payout_details->eta);
        payout_details->eta = NULL;
    }
    if (payout_details->message) {
        free(payout_details->message);
        payout_details->message = NULL;
    }
    if (payout_details->transaction_id) {
        free(payout_details->transaction_id);
        payout_details->transaction_id = NULL;
    }
    if (payout_details->created_at) {
        free(payout_details->created_at);
        payout_details->created_at = NULL;
    }
    if (payout_details->bank_name) {
        free(payout_details->bank_name);
        payout_details->bank_name = NULL;
    }
    if (payout_details->transaction_fee) {
        free(payout_details->transaction_fee);
        payout_details->transaction_fee = NULL;
    }
    free(payout_details);
}

cJSON *payout_details_convertToJSON(payout_details_t *payout_details) {
    cJSON *item = cJSON_CreateObject();

    // payout_details->status
    if(payout_details->status) {
    if(cJSON_AddStringToObject(item, "status", payout_details->status) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->mode
    if(payout_details->mode) {
    if(cJSON_AddStringToObject(item, "mode", payout_details->mode) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->amount
    if(payout_details->amount) {
    if(cJSON_AddNumberToObject(item, "amount", *payout_details->amount) == NULL) {
    goto fail; //Numeric
    }
    }


    // payout_details->currency
    if(payout_details->currency) {
    if(cJSON_AddStringToObject(item, "currency", payout_details->currency) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->eta
    if(payout_details->eta) {
    if(cJSON_AddStringToObject(item, "eta", payout_details->eta) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->message
    if(payout_details->message) {
    if(cJSON_AddStringToObject(item, "message", payout_details->message) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->transaction_id
    if(payout_details->transaction_id) {
    if(cJSON_AddStringToObject(item, "transaction_id", payout_details->transaction_id) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->created_at
    if(payout_details->created_at) {
    if(cJSON_AddStringToObject(item, "created_at", payout_details->created_at) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->bank_name
    if(payout_details->bank_name) {
    if(cJSON_AddStringToObject(item, "bank_name", payout_details->bank_name) == NULL) {
    goto fail; //String
    }
    }


    // payout_details->transaction_fee
    if(payout_details->transaction_fee) {
    if(cJSON_AddStringToObject(item, "transaction_fee", payout_details->transaction_fee) == NULL) {
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

payout_details_t *payout_details_parseFromJSON(cJSON *payout_detailsJSON){

    payout_details_t *payout_details_local_var = NULL;

    char *status_local_str = NULL;

    char *mode_local_str = NULL;

    // define the local variable for payout_details->amount
    double *amount_local_var = NULL;

    char *currency_local_str = NULL;

    char *eta_local_str = NULL;

    char *message_local_str = NULL;

    char *transaction_id_local_str = NULL;

    char *created_at_local_str = NULL;

    char *bank_name_local_str = NULL;

    char *transaction_fee_local_str = NULL;

    // payout_details->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsString(status) && !cJSON_IsNull(status))
    {
    goto end; //String
    }
    }

    // payout_details->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (mode) { 
    if(!cJSON_IsString(mode) && !cJSON_IsNull(mode))
    {
    goto end; //String
    }
    }

    // payout_details->amount
    cJSON *amount = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "amount");
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

    // payout_details->currency
    cJSON *currency = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "currency");
    if (cJSON_IsNull(currency)) {
        currency = NULL;
    }
    if (currency) { 
    if(!cJSON_IsString(currency) && !cJSON_IsNull(currency))
    {
    goto end; //String
    }
    }

    // payout_details->eta
    cJSON *eta = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "eta");
    if (cJSON_IsNull(eta)) {
        eta = NULL;
    }
    if (eta) { 
    if(!cJSON_IsString(eta) && !cJSON_IsNull(eta))
    {
    goto end; //String
    }
    }

    // payout_details->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "message");
    if (cJSON_IsNull(message)) {
        message = NULL;
    }
    if (message) { 
    if(!cJSON_IsString(message) && !cJSON_IsNull(message))
    {
    goto end; //String
    }
    }

    // payout_details->transaction_id
    cJSON *transaction_id = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "transaction_id");
    if (cJSON_IsNull(transaction_id)) {
        transaction_id = NULL;
    }
    if (transaction_id) { 
    if(!cJSON_IsString(transaction_id) && !cJSON_IsNull(transaction_id))
    {
    goto end; //String
    }
    }

    // payout_details->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "created_at");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (created_at) { 
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //String
    }
    }

    // payout_details->bank_name
    cJSON *bank_name = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "bank_name");
    if (cJSON_IsNull(bank_name)) {
        bank_name = NULL;
    }
    if (bank_name) { 
    if(!cJSON_IsString(bank_name) && !cJSON_IsNull(bank_name))
    {
    goto end; //String
    }
    }

    // payout_details->transaction_fee
    cJSON *transaction_fee = cJSON_GetObjectItemCaseSensitive(payout_detailsJSON, "transaction_fee");
    if (cJSON_IsNull(transaction_fee)) {
        transaction_fee = NULL;
    }
    if (transaction_fee) { 
    if(!cJSON_IsString(transaction_fee) && !cJSON_IsNull(transaction_fee))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (mode && !cJSON_IsNull(mode)) mode_local_str = strdup(mode->valuestring);
    if (currency && !cJSON_IsNull(currency)) currency_local_str = strdup(currency->valuestring);
    if (eta && !cJSON_IsNull(eta)) eta_local_str = strdup(eta->valuestring);
    if (message && !cJSON_IsNull(message)) message_local_str = strdup(message->valuestring);
    if (transaction_id && !cJSON_IsNull(transaction_id)) transaction_id_local_str = strdup(transaction_id->valuestring);
    if (created_at && !cJSON_IsNull(created_at)) created_at_local_str = strdup(created_at->valuestring);
    if (bank_name && !cJSON_IsNull(bank_name)) bank_name_local_str = strdup(bank_name->valuestring);
    if (transaction_fee && !cJSON_IsNull(transaction_fee)) transaction_fee_local_str = strdup(transaction_fee->valuestring);

    payout_details_local_var = payout_details_create_internal (
        status_local_str,
        mode_local_str,
        amount_local_var,
        currency_local_str,
        eta_local_str,
        message_local_str,
        transaction_id_local_str,
        created_at_local_str,
        bank_name_local_str,
        transaction_fee_local_str
        );

    if (!payout_details_local_var) {
        goto end;
    }

    return payout_details_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (mode_local_str) {
        free(mode_local_str);
        mode_local_str = NULL;
    }
    if (amount_local_var) {
        free(amount_local_var);
        amount_local_var = NULL;
    }
    if (currency_local_str) {
        free(currency_local_str);
        currency_local_str = NULL;
    }
    if (eta_local_str) {
        free(eta_local_str);
        eta_local_str = NULL;
    }
    if (message_local_str) {
        free(message_local_str);
        message_local_str = NULL;
    }
    if (transaction_id_local_str) {
        free(transaction_id_local_str);
        transaction_id_local_str = NULL;
    }
    if (created_at_local_str) {
        free(created_at_local_str);
        created_at_local_str = NULL;
    }
    if (bank_name_local_str) {
        free(bank_name_local_str);
        bank_name_local_str = NULL;
    }
    if (transaction_fee_local_str) {
        free(transaction_fee_local_str);
        transaction_fee_local_str = NULL;
    }
    return NULL;

}
