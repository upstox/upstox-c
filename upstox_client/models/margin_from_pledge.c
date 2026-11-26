#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "margin_from_pledge.h"



static margin_from_pledge_t *margin_from_pledge_create_internal(
    double *total,
    double *equity,
    double *mutual_funds
    ) {
    margin_from_pledge_t *margin_from_pledge_local_var = malloc(sizeof(margin_from_pledge_t));
    if (!margin_from_pledge_local_var) {
        return NULL;
    }
    memset(margin_from_pledge_local_var, 0, sizeof(margin_from_pledge_t));
    margin_from_pledge_local_var->_library_owned = 1;
    margin_from_pledge_local_var->total = total;
    margin_from_pledge_local_var->equity = equity;
    margin_from_pledge_local_var->mutual_funds = mutual_funds;
    return margin_from_pledge_local_var;
}

margin_from_pledge_t *margin_from_pledge_create(
    double *total,
    double *equity,
    double *mutual_funds
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    double *equity_copy = NULL;
    if (equity) {
        equity_copy = malloc(sizeof(double));
        if (equity_copy) *equity_copy = *equity;
    }
    double *mutual_funds_copy = NULL;
    if (mutual_funds) {
        mutual_funds_copy = malloc(sizeof(double));
        if (mutual_funds_copy) *mutual_funds_copy = *mutual_funds;
    }
    margin_from_pledge_t *result = margin_from_pledge_create_internal (
        total_copy,
        equity_copy,
        mutual_funds_copy
        );
    if (!result) {
        free(total_copy);
        free(equity_copy);
        free(mutual_funds_copy);
    }
    return result;
}

void margin_from_pledge_free(margin_from_pledge_t *margin_from_pledge) {
    if(NULL == margin_from_pledge){
        return ;
    }
    if(margin_from_pledge->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "margin_from_pledge_free");
        return ;
    }
    listEntry_t *listEntry;
    if (margin_from_pledge->total) {
        free(margin_from_pledge->total);
        margin_from_pledge->total = NULL;
    }
    if (margin_from_pledge->equity) {
        free(margin_from_pledge->equity);
        margin_from_pledge->equity = NULL;
    }
    if (margin_from_pledge->mutual_funds) {
        free(margin_from_pledge->mutual_funds);
        margin_from_pledge->mutual_funds = NULL;
    }
    free(margin_from_pledge);
}

cJSON *margin_from_pledge_convertToJSON(margin_from_pledge_t *margin_from_pledge) {
    cJSON *item = cJSON_CreateObject();

    // margin_from_pledge->total
    if(margin_from_pledge->total) {
    if(cJSON_AddNumberToObject(item, "total", *margin_from_pledge->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin_from_pledge->equity
    if(margin_from_pledge->equity) {
    if(cJSON_AddNumberToObject(item, "equity", *margin_from_pledge->equity) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin_from_pledge->mutual_funds
    if(margin_from_pledge->mutual_funds) {
    if(cJSON_AddNumberToObject(item, "mutual_funds", *margin_from_pledge->mutual_funds) == NULL) {
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

margin_from_pledge_t *margin_from_pledge_parseFromJSON(cJSON *margin_from_pledgeJSON){

    margin_from_pledge_t *margin_from_pledge_local_var = NULL;

    // define the local variable for margin_from_pledge->total
    double *total_local_var = NULL;

    // define the local variable for margin_from_pledge->equity
    double *equity_local_var = NULL;

    // define the local variable for margin_from_pledge->mutual_funds
    double *mutual_funds_local_var = NULL;

    // margin_from_pledge->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(margin_from_pledgeJSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    total_local_var = malloc(sizeof(double));
    if(!total_local_var)
    {
        goto end;
    }
    *total_local_var = total->valuedouble;
    }

    // margin_from_pledge->equity
    cJSON *equity = cJSON_GetObjectItemCaseSensitive(margin_from_pledgeJSON, "equity");
    if (cJSON_IsNull(equity)) {
        equity = NULL;
    }
    if (equity) { 
    if(!cJSON_IsNumber(equity))
    {
    goto end; //Numeric
    }
    equity_local_var = malloc(sizeof(double));
    if(!equity_local_var)
    {
        goto end;
    }
    *equity_local_var = equity->valuedouble;
    }

    // margin_from_pledge->mutual_funds
    cJSON *mutual_funds = cJSON_GetObjectItemCaseSensitive(margin_from_pledgeJSON, "mutual_funds");
    if (cJSON_IsNull(mutual_funds)) {
        mutual_funds = NULL;
    }
    if (mutual_funds) { 
    if(!cJSON_IsNumber(mutual_funds))
    {
    goto end; //Numeric
    }
    mutual_funds_local_var = malloc(sizeof(double));
    if(!mutual_funds_local_var)
    {
        goto end;
    }
    *mutual_funds_local_var = mutual_funds->valuedouble;
    }



    margin_from_pledge_local_var = margin_from_pledge_create_internal (
        total_local_var,
        equity_local_var,
        mutual_funds_local_var
        );

    if (!margin_from_pledge_local_var) {
        goto end;
    }

    return margin_from_pledge_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (equity_local_var) {
        free(equity_local_var);
        equity_local_var = NULL;
    }
    if (mutual_funds_local_var) {
        free(mutual_funds_local_var);
        mutual_funds_local_var = NULL;
    }
    return NULL;

}
