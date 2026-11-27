#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_breakdown.h"



static cash_breakdown_t *cash_breakdown_create_internal(
    double *opening_balance,
    double *added_today,
    double *withdrawn_today,
    double *amount_from_stock_sale,
    double *unpaid_charges
    ) {
    cash_breakdown_t *cash_breakdown_local_var = malloc(sizeof(cash_breakdown_t));
    if (!cash_breakdown_local_var) {
        return NULL;
    }
    memset(cash_breakdown_local_var, 0, sizeof(cash_breakdown_t));
    cash_breakdown_local_var->_library_owned = 1;
    cash_breakdown_local_var->opening_balance = opening_balance;
    cash_breakdown_local_var->added_today = added_today;
    cash_breakdown_local_var->withdrawn_today = withdrawn_today;
    cash_breakdown_local_var->amount_from_stock_sale = amount_from_stock_sale;
    cash_breakdown_local_var->unpaid_charges = unpaid_charges;
    return cash_breakdown_local_var;
}

cash_breakdown_t *cash_breakdown_create(
    double *opening_balance,
    double *added_today,
    double *withdrawn_today,
    double *amount_from_stock_sale,
    double *unpaid_charges
    ) {
    double *opening_balance_copy = NULL;
    if (opening_balance) {
        opening_balance_copy = malloc(sizeof(double));
        if (opening_balance_copy) *opening_balance_copy = *opening_balance;
    }
    double *added_today_copy = NULL;
    if (added_today) {
        added_today_copy = malloc(sizeof(double));
        if (added_today_copy) *added_today_copy = *added_today;
    }
    double *withdrawn_today_copy = NULL;
    if (withdrawn_today) {
        withdrawn_today_copy = malloc(sizeof(double));
        if (withdrawn_today_copy) *withdrawn_today_copy = *withdrawn_today;
    }
    double *amount_from_stock_sale_copy = NULL;
    if (amount_from_stock_sale) {
        amount_from_stock_sale_copy = malloc(sizeof(double));
        if (amount_from_stock_sale_copy) *amount_from_stock_sale_copy = *amount_from_stock_sale;
    }
    double *unpaid_charges_copy = NULL;
    if (unpaid_charges) {
        unpaid_charges_copy = malloc(sizeof(double));
        if (unpaid_charges_copy) *unpaid_charges_copy = *unpaid_charges;
    }
    cash_breakdown_t *result = cash_breakdown_create_internal (
        opening_balance_copy,
        added_today_copy,
        withdrawn_today_copy,
        amount_from_stock_sale_copy,
        unpaid_charges_copy
        );
    if (!result) {
        free(opening_balance_copy);
        free(added_today_copy);
        free(withdrawn_today_copy);
        free(amount_from_stock_sale_copy);
        free(unpaid_charges_copy);
    }
    return result;
}

void cash_breakdown_free(cash_breakdown_t *cash_breakdown) {
    if(NULL == cash_breakdown){
        return ;
    }
    if(cash_breakdown->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_breakdown_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_breakdown->opening_balance) {
        free(cash_breakdown->opening_balance);
        cash_breakdown->opening_balance = NULL;
    }
    if (cash_breakdown->added_today) {
        free(cash_breakdown->added_today);
        cash_breakdown->added_today = NULL;
    }
    if (cash_breakdown->withdrawn_today) {
        free(cash_breakdown->withdrawn_today);
        cash_breakdown->withdrawn_today = NULL;
    }
    if (cash_breakdown->amount_from_stock_sale) {
        free(cash_breakdown->amount_from_stock_sale);
        cash_breakdown->amount_from_stock_sale = NULL;
    }
    if (cash_breakdown->unpaid_charges) {
        free(cash_breakdown->unpaid_charges);
        cash_breakdown->unpaid_charges = NULL;
    }
    free(cash_breakdown);
}

cJSON *cash_breakdown_convertToJSON(cash_breakdown_t *cash_breakdown) {
    cJSON *item = cJSON_CreateObject();

    // cash_breakdown->opening_balance
    if(cash_breakdown->opening_balance) {
    if(cJSON_AddNumberToObject(item, "opening_balance", *cash_breakdown->opening_balance) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_breakdown->added_today
    if(cash_breakdown->added_today) {
    if(cJSON_AddNumberToObject(item, "added_today", *cash_breakdown->added_today) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_breakdown->withdrawn_today
    if(cash_breakdown->withdrawn_today) {
    if(cJSON_AddNumberToObject(item, "withdrawn_today", *cash_breakdown->withdrawn_today) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_breakdown->amount_from_stock_sale
    if(cash_breakdown->amount_from_stock_sale) {
    if(cJSON_AddNumberToObject(item, "amount_from_stock_sale", *cash_breakdown->amount_from_stock_sale) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_breakdown->unpaid_charges
    if(cash_breakdown->unpaid_charges) {
    if(cJSON_AddNumberToObject(item, "unpaid_charges", *cash_breakdown->unpaid_charges) == NULL) {
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

cash_breakdown_t *cash_breakdown_parseFromJSON(cJSON *cash_breakdownJSON){

    cash_breakdown_t *cash_breakdown_local_var = NULL;

    // define the local variable for cash_breakdown->opening_balance
    double *opening_balance_local_var = NULL;

    // define the local variable for cash_breakdown->added_today
    double *added_today_local_var = NULL;

    // define the local variable for cash_breakdown->withdrawn_today
    double *withdrawn_today_local_var = NULL;

    // define the local variable for cash_breakdown->amount_from_stock_sale
    double *amount_from_stock_sale_local_var = NULL;

    // define the local variable for cash_breakdown->unpaid_charges
    double *unpaid_charges_local_var = NULL;

    // cash_breakdown->opening_balance
    cJSON *opening_balance = cJSON_GetObjectItemCaseSensitive(cash_breakdownJSON, "opening_balance");
    if (cJSON_IsNull(opening_balance)) {
        opening_balance = NULL;
    }
    if (opening_balance) { 
    if(!cJSON_IsNumber(opening_balance))
    {
    goto end; //Numeric
    }
    opening_balance_local_var = malloc(sizeof(double));
    if(!opening_balance_local_var)
    {
        goto end;
    }
    *opening_balance_local_var = opening_balance->valuedouble;
    }

    // cash_breakdown->added_today
    cJSON *added_today = cJSON_GetObjectItemCaseSensitive(cash_breakdownJSON, "added_today");
    if (cJSON_IsNull(added_today)) {
        added_today = NULL;
    }
    if (added_today) { 
    if(!cJSON_IsNumber(added_today))
    {
    goto end; //Numeric
    }
    added_today_local_var = malloc(sizeof(double));
    if(!added_today_local_var)
    {
        goto end;
    }
    *added_today_local_var = added_today->valuedouble;
    }

    // cash_breakdown->withdrawn_today
    cJSON *withdrawn_today = cJSON_GetObjectItemCaseSensitive(cash_breakdownJSON, "withdrawn_today");
    if (cJSON_IsNull(withdrawn_today)) {
        withdrawn_today = NULL;
    }
    if (withdrawn_today) { 
    if(!cJSON_IsNumber(withdrawn_today))
    {
    goto end; //Numeric
    }
    withdrawn_today_local_var = malloc(sizeof(double));
    if(!withdrawn_today_local_var)
    {
        goto end;
    }
    *withdrawn_today_local_var = withdrawn_today->valuedouble;
    }

    // cash_breakdown->amount_from_stock_sale
    cJSON *amount_from_stock_sale = cJSON_GetObjectItemCaseSensitive(cash_breakdownJSON, "amount_from_stock_sale");
    if (cJSON_IsNull(amount_from_stock_sale)) {
        amount_from_stock_sale = NULL;
    }
    if (amount_from_stock_sale) { 
    if(!cJSON_IsNumber(amount_from_stock_sale))
    {
    goto end; //Numeric
    }
    amount_from_stock_sale_local_var = malloc(sizeof(double));
    if(!amount_from_stock_sale_local_var)
    {
        goto end;
    }
    *amount_from_stock_sale_local_var = amount_from_stock_sale->valuedouble;
    }

    // cash_breakdown->unpaid_charges
    cJSON *unpaid_charges = cJSON_GetObjectItemCaseSensitive(cash_breakdownJSON, "unpaid_charges");
    if (cJSON_IsNull(unpaid_charges)) {
        unpaid_charges = NULL;
    }
    if (unpaid_charges) { 
    if(!cJSON_IsNumber(unpaid_charges))
    {
    goto end; //Numeric
    }
    unpaid_charges_local_var = malloc(sizeof(double));
    if(!unpaid_charges_local_var)
    {
        goto end;
    }
    *unpaid_charges_local_var = unpaid_charges->valuedouble;
    }



    cash_breakdown_local_var = cash_breakdown_create_internal (
        opening_balance_local_var,
        added_today_local_var,
        withdrawn_today_local_var,
        amount_from_stock_sale_local_var,
        unpaid_charges_local_var
        );

    if (!cash_breakdown_local_var) {
        goto end;
    }

    return cash_breakdown_local_var;
end:
    if (opening_balance_local_var) {
        free(opening_balance_local_var);
        opening_balance_local_var = NULL;
    }
    if (added_today_local_var) {
        free(added_today_local_var);
        added_today_local_var = NULL;
    }
    if (withdrawn_today_local_var) {
        free(withdrawn_today_local_var);
        withdrawn_today_local_var = NULL;
    }
    if (amount_from_stock_sale_local_var) {
        free(amount_from_stock_sale_local_var);
        amount_from_stock_sale_local_var = NULL;
    }
    if (unpaid_charges_local_var) {
        free(unpaid_charges_local_var);
        unpaid_charges_local_var = NULL;
    }
    return NULL;

}
