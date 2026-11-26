#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_other_charges_taxes.h"



static profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_create_internal(
    double *transaction,
    double *clearing,
    double *ipft,
    double *others,
    double *sebi_turnover,
    double *demat_transaction
    ) {
    profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_local_var = malloc(sizeof(profit_and_loss_other_charges_taxes_t));
    if (!profit_and_loss_other_charges_taxes_local_var) {
        return NULL;
    }
    memset(profit_and_loss_other_charges_taxes_local_var, 0, sizeof(profit_and_loss_other_charges_taxes_t));
    profit_and_loss_other_charges_taxes_local_var->_library_owned = 1;
    profit_and_loss_other_charges_taxes_local_var->transaction = transaction;
    profit_and_loss_other_charges_taxes_local_var->clearing = clearing;
    profit_and_loss_other_charges_taxes_local_var->ipft = ipft;
    profit_and_loss_other_charges_taxes_local_var->others = others;
    profit_and_loss_other_charges_taxes_local_var->sebi_turnover = sebi_turnover;
    profit_and_loss_other_charges_taxes_local_var->demat_transaction = demat_transaction;
    return profit_and_loss_other_charges_taxes_local_var;
}

profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_create(
    double *transaction,
    double *clearing,
    double *ipft,
    double *others,
    double *sebi_turnover,
    double *demat_transaction
    ) {
    double *transaction_copy = NULL;
    if (transaction) {
        transaction_copy = malloc(sizeof(double));
        if (transaction_copy) *transaction_copy = *transaction;
    }
    double *clearing_copy = NULL;
    if (clearing) {
        clearing_copy = malloc(sizeof(double));
        if (clearing_copy) *clearing_copy = *clearing;
    }
    double *ipft_copy = NULL;
    if (ipft) {
        ipft_copy = malloc(sizeof(double));
        if (ipft_copy) *ipft_copy = *ipft;
    }
    double *others_copy = NULL;
    if (others) {
        others_copy = malloc(sizeof(double));
        if (others_copy) *others_copy = *others;
    }
    double *sebi_turnover_copy = NULL;
    if (sebi_turnover) {
        sebi_turnover_copy = malloc(sizeof(double));
        if (sebi_turnover_copy) *sebi_turnover_copy = *sebi_turnover;
    }
    double *demat_transaction_copy = NULL;
    if (demat_transaction) {
        demat_transaction_copy = malloc(sizeof(double));
        if (demat_transaction_copy) *demat_transaction_copy = *demat_transaction;
    }
    profit_and_loss_other_charges_taxes_t *result = profit_and_loss_other_charges_taxes_create_internal (
        transaction_copy,
        clearing_copy,
        ipft_copy,
        others_copy,
        sebi_turnover_copy,
        demat_transaction_copy
        );
    if (!result) {
        free(transaction_copy);
        free(clearing_copy);
        free(ipft_copy);
        free(others_copy);
        free(sebi_turnover_copy);
        free(demat_transaction_copy);
    }
    return result;
}

void profit_and_loss_other_charges_taxes_free(profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes) {
    if(NULL == profit_and_loss_other_charges_taxes){
        return ;
    }
    if(profit_and_loss_other_charges_taxes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_other_charges_taxes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_other_charges_taxes->transaction) {
        free(profit_and_loss_other_charges_taxes->transaction);
        profit_and_loss_other_charges_taxes->transaction = NULL;
    }
    if (profit_and_loss_other_charges_taxes->clearing) {
        free(profit_and_loss_other_charges_taxes->clearing);
        profit_and_loss_other_charges_taxes->clearing = NULL;
    }
    if (profit_and_loss_other_charges_taxes->ipft) {
        free(profit_and_loss_other_charges_taxes->ipft);
        profit_and_loss_other_charges_taxes->ipft = NULL;
    }
    if (profit_and_loss_other_charges_taxes->others) {
        free(profit_and_loss_other_charges_taxes->others);
        profit_and_loss_other_charges_taxes->others = NULL;
    }
    if (profit_and_loss_other_charges_taxes->sebi_turnover) {
        free(profit_and_loss_other_charges_taxes->sebi_turnover);
        profit_and_loss_other_charges_taxes->sebi_turnover = NULL;
    }
    if (profit_and_loss_other_charges_taxes->demat_transaction) {
        free(profit_and_loss_other_charges_taxes->demat_transaction);
        profit_and_loss_other_charges_taxes->demat_transaction = NULL;
    }
    free(profit_and_loss_other_charges_taxes);
}

cJSON *profit_and_loss_other_charges_taxes_convertToJSON(profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_other_charges_taxes->transaction
    if(profit_and_loss_other_charges_taxes->transaction) {
    if(cJSON_AddNumberToObject(item, "transaction", *profit_and_loss_other_charges_taxes->transaction) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_other_charges_taxes->clearing
    if(profit_and_loss_other_charges_taxes->clearing) {
    if(cJSON_AddNumberToObject(item, "clearing", *profit_and_loss_other_charges_taxes->clearing) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_other_charges_taxes->ipft
    if(profit_and_loss_other_charges_taxes->ipft) {
    if(cJSON_AddNumberToObject(item, "ipft", *profit_and_loss_other_charges_taxes->ipft) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_other_charges_taxes->others
    if(profit_and_loss_other_charges_taxes->others) {
    if(cJSON_AddNumberToObject(item, "others", *profit_and_loss_other_charges_taxes->others) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_other_charges_taxes->sebi_turnover
    if(profit_and_loss_other_charges_taxes->sebi_turnover) {
    if(cJSON_AddNumberToObject(item, "sebi_turnover", *profit_and_loss_other_charges_taxes->sebi_turnover) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_other_charges_taxes->demat_transaction
    if(profit_and_loss_other_charges_taxes->demat_transaction) {
    if(cJSON_AddNumberToObject(item, "demat_transaction", *profit_and_loss_other_charges_taxes->demat_transaction) == NULL) {
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

profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_parseFromJSON(cJSON *profit_and_loss_other_charges_taxesJSON){

    profit_and_loss_other_charges_taxes_t *profit_and_loss_other_charges_taxes_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->transaction
    double *transaction_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->clearing
    double *clearing_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->ipft
    double *ipft_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->others
    double *others_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->sebi_turnover
    double *sebi_turnover_local_var = NULL;

    // define the local variable for profit_and_loss_other_charges_taxes->demat_transaction
    double *demat_transaction_local_var = NULL;

    // profit_and_loss_other_charges_taxes->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "transaction");
    if (cJSON_IsNull(transaction)) {
        transaction = NULL;
    }
    if (transaction) { 
    if(!cJSON_IsNumber(transaction))
    {
    goto end; //Numeric
    }
    transaction_local_var = malloc(sizeof(double));
    if(!transaction_local_var)
    {
        goto end;
    }
    *transaction_local_var = transaction->valuedouble;
    }

    // profit_and_loss_other_charges_taxes->clearing
    cJSON *clearing = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "clearing");
    if (cJSON_IsNull(clearing)) {
        clearing = NULL;
    }
    if (clearing) { 
    if(!cJSON_IsNumber(clearing))
    {
    goto end; //Numeric
    }
    clearing_local_var = malloc(sizeof(double));
    if(!clearing_local_var)
    {
        goto end;
    }
    *clearing_local_var = clearing->valuedouble;
    }

    // profit_and_loss_other_charges_taxes->ipft
    cJSON *ipft = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "ipft");
    if (cJSON_IsNull(ipft)) {
        ipft = NULL;
    }
    if (ipft) { 
    if(!cJSON_IsNumber(ipft))
    {
    goto end; //Numeric
    }
    ipft_local_var = malloc(sizeof(double));
    if(!ipft_local_var)
    {
        goto end;
    }
    *ipft_local_var = ipft->valuedouble;
    }

    // profit_and_loss_other_charges_taxes->others
    cJSON *others = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "others");
    if (cJSON_IsNull(others)) {
        others = NULL;
    }
    if (others) { 
    if(!cJSON_IsNumber(others))
    {
    goto end; //Numeric
    }
    others_local_var = malloc(sizeof(double));
    if(!others_local_var)
    {
        goto end;
    }
    *others_local_var = others->valuedouble;
    }

    // profit_and_loss_other_charges_taxes->sebi_turnover
    cJSON *sebi_turnover = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "sebi_turnover");
    if (cJSON_IsNull(sebi_turnover)) {
        sebi_turnover = NULL;
    }
    if (sebi_turnover) { 
    if(!cJSON_IsNumber(sebi_turnover))
    {
    goto end; //Numeric
    }
    sebi_turnover_local_var = malloc(sizeof(double));
    if(!sebi_turnover_local_var)
    {
        goto end;
    }
    *sebi_turnover_local_var = sebi_turnover->valuedouble;
    }

    // profit_and_loss_other_charges_taxes->demat_transaction
    cJSON *demat_transaction = cJSON_GetObjectItemCaseSensitive(profit_and_loss_other_charges_taxesJSON, "demat_transaction");
    if (cJSON_IsNull(demat_transaction)) {
        demat_transaction = NULL;
    }
    if (demat_transaction) { 
    if(!cJSON_IsNumber(demat_transaction))
    {
    goto end; //Numeric
    }
    demat_transaction_local_var = malloc(sizeof(double));
    if(!demat_transaction_local_var)
    {
        goto end;
    }
    *demat_transaction_local_var = demat_transaction->valuedouble;
    }



    profit_and_loss_other_charges_taxes_local_var = profit_and_loss_other_charges_taxes_create_internal (
        transaction_local_var,
        clearing_local_var,
        ipft_local_var,
        others_local_var,
        sebi_turnover_local_var,
        demat_transaction_local_var
        );

    if (!profit_and_loss_other_charges_taxes_local_var) {
        goto end;
    }

    return profit_and_loss_other_charges_taxes_local_var;
end:
    if (transaction_local_var) {
        free(transaction_local_var);
        transaction_local_var = NULL;
    }
    if (clearing_local_var) {
        free(clearing_local_var);
        clearing_local_var = NULL;
    }
    if (ipft_local_var) {
        free(ipft_local_var);
        ipft_local_var = NULL;
    }
    if (others_local_var) {
        free(others_local_var);
        others_local_var = NULL;
    }
    if (sebi_turnover_local_var) {
        free(sebi_turnover_local_var);
        sebi_turnover_local_var = NULL;
    }
    if (demat_transaction_local_var) {
        free(demat_transaction_local_var);
        demat_transaction_local_var = NULL;
    }
    return NULL;

}
