#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "other_taxes.h"



static other_taxes_t *other_taxes_create_internal(
    double *transaction,
    double *clearing,
    double *ipft,
    double *sebi_turnover
    ) {
    other_taxes_t *other_taxes_local_var = malloc(sizeof(other_taxes_t));
    if (!other_taxes_local_var) {
        return NULL;
    }
    memset(other_taxes_local_var, 0, sizeof(other_taxes_t));
    other_taxes_local_var->_library_owned = 1;
    other_taxes_local_var->transaction = transaction;
    other_taxes_local_var->clearing = clearing;
    other_taxes_local_var->ipft = ipft;
    other_taxes_local_var->sebi_turnover = sebi_turnover;
    return other_taxes_local_var;
}

other_taxes_t *other_taxes_create(
    double *transaction,
    double *clearing,
    double *ipft,
    double *sebi_turnover
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
    double *sebi_turnover_copy = NULL;
    if (sebi_turnover) {
        sebi_turnover_copy = malloc(sizeof(double));
        if (sebi_turnover_copy) *sebi_turnover_copy = *sebi_turnover;
    }
    other_taxes_t *result = other_taxes_create_internal (
        transaction_copy,
        clearing_copy,
        ipft_copy,
        sebi_turnover_copy
        );
    if (!result) {
        free(transaction_copy);
        free(clearing_copy);
        free(ipft_copy);
        free(sebi_turnover_copy);
    }
    return result;
}

void other_taxes_free(other_taxes_t *other_taxes) {
    if(NULL == other_taxes){
        return ;
    }
    if(other_taxes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "other_taxes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (other_taxes->transaction) {
        free(other_taxes->transaction);
        other_taxes->transaction = NULL;
    }
    if (other_taxes->clearing) {
        free(other_taxes->clearing);
        other_taxes->clearing = NULL;
    }
    if (other_taxes->ipft) {
        free(other_taxes->ipft);
        other_taxes->ipft = NULL;
    }
    if (other_taxes->sebi_turnover) {
        free(other_taxes->sebi_turnover);
        other_taxes->sebi_turnover = NULL;
    }
    free(other_taxes);
}

cJSON *other_taxes_convertToJSON(other_taxes_t *other_taxes) {
    cJSON *item = cJSON_CreateObject();

    // other_taxes->transaction
    if(other_taxes->transaction) {
    if(cJSON_AddNumberToObject(item, "transaction", *other_taxes->transaction) == NULL) {
    goto fail; //Numeric
    }
    }


    // other_taxes->clearing
    if(other_taxes->clearing) {
    if(cJSON_AddNumberToObject(item, "clearing", *other_taxes->clearing) == NULL) {
    goto fail; //Numeric
    }
    }


    // other_taxes->ipft
    if(other_taxes->ipft) {
    if(cJSON_AddNumberToObject(item, "ipft", *other_taxes->ipft) == NULL) {
    goto fail; //Numeric
    }
    }


    // other_taxes->sebi_turnover
    if(other_taxes->sebi_turnover) {
    if(cJSON_AddNumberToObject(item, "sebi_turnover", *other_taxes->sebi_turnover) == NULL) {
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

other_taxes_t *other_taxes_parseFromJSON(cJSON *other_taxesJSON){

    other_taxes_t *other_taxes_local_var = NULL;

    // define the local variable for other_taxes->transaction
    double *transaction_local_var = NULL;

    // define the local variable for other_taxes->clearing
    double *clearing_local_var = NULL;

    // define the local variable for other_taxes->ipft
    double *ipft_local_var = NULL;

    // define the local variable for other_taxes->sebi_turnover
    double *sebi_turnover_local_var = NULL;

    // other_taxes->transaction
    cJSON *transaction = cJSON_GetObjectItemCaseSensitive(other_taxesJSON, "transaction");
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

    // other_taxes->clearing
    cJSON *clearing = cJSON_GetObjectItemCaseSensitive(other_taxesJSON, "clearing");
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

    // other_taxes->ipft
    cJSON *ipft = cJSON_GetObjectItemCaseSensitive(other_taxesJSON, "ipft");
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

    // other_taxes->sebi_turnover
    cJSON *sebi_turnover = cJSON_GetObjectItemCaseSensitive(other_taxesJSON, "sebi_turnover");
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



    other_taxes_local_var = other_taxes_create_internal (
        transaction_local_var,
        clearing_local_var,
        ipft_local_var,
        sebi_turnover_local_var
        );

    if (!other_taxes_local_var) {
        goto end;
    }

    return other_taxes_local_var;
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
    if (sebi_turnover_local_var) {
        free(sebi_turnover_local_var);
        sebi_turnover_local_var = NULL;
    }
    return NULL;

}
