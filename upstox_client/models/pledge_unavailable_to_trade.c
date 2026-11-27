#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pledge_unavailable_to_trade.h"



static pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_create_internal(
    double *equity,
    double *mutual_funds
    ) {
    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_local_var = malloc(sizeof(pledge_unavailable_to_trade_t));
    if (!pledge_unavailable_to_trade_local_var) {
        return NULL;
    }
    memset(pledge_unavailable_to_trade_local_var, 0, sizeof(pledge_unavailable_to_trade_t));
    pledge_unavailable_to_trade_local_var->_library_owned = 1;
    pledge_unavailable_to_trade_local_var->equity = equity;
    pledge_unavailable_to_trade_local_var->mutual_funds = mutual_funds;
    return pledge_unavailable_to_trade_local_var;
}

pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_create(
    double *equity,
    double *mutual_funds
    ) {
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
    pledge_unavailable_to_trade_t *result = pledge_unavailable_to_trade_create_internal (
        equity_copy,
        mutual_funds_copy
        );
    if (!result) {
        free(equity_copy);
        free(mutual_funds_copy);
    }
    return result;
}

void pledge_unavailable_to_trade_free(pledge_unavailable_to_trade_t *pledge_unavailable_to_trade) {
    if(NULL == pledge_unavailable_to_trade){
        return ;
    }
    if(pledge_unavailable_to_trade->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pledge_unavailable_to_trade_free");
        return ;
    }
    listEntry_t *listEntry;
    if (pledge_unavailable_to_trade->equity) {
        free(pledge_unavailable_to_trade->equity);
        pledge_unavailable_to_trade->equity = NULL;
    }
    if (pledge_unavailable_to_trade->mutual_funds) {
        free(pledge_unavailable_to_trade->mutual_funds);
        pledge_unavailable_to_trade->mutual_funds = NULL;
    }
    free(pledge_unavailable_to_trade);
}

cJSON *pledge_unavailable_to_trade_convertToJSON(pledge_unavailable_to_trade_t *pledge_unavailable_to_trade) {
    cJSON *item = cJSON_CreateObject();

    // pledge_unavailable_to_trade->equity
    if(pledge_unavailable_to_trade->equity) {
    if(cJSON_AddNumberToObject(item, "equity", *pledge_unavailable_to_trade->equity) == NULL) {
    goto fail; //Numeric
    }
    }


    // pledge_unavailable_to_trade->mutual_funds
    if(pledge_unavailable_to_trade->mutual_funds) {
    if(cJSON_AddNumberToObject(item, "mutual_funds", *pledge_unavailable_to_trade->mutual_funds) == NULL) {
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

pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_parseFromJSON(cJSON *pledge_unavailable_to_tradeJSON){

    pledge_unavailable_to_trade_t *pledge_unavailable_to_trade_local_var = NULL;

    // define the local variable for pledge_unavailable_to_trade->equity
    double *equity_local_var = NULL;

    // define the local variable for pledge_unavailable_to_trade->mutual_funds
    double *mutual_funds_local_var = NULL;

    // pledge_unavailable_to_trade->equity
    cJSON *equity = cJSON_GetObjectItemCaseSensitive(pledge_unavailable_to_tradeJSON, "equity");
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

    // pledge_unavailable_to_trade->mutual_funds
    cJSON *mutual_funds = cJSON_GetObjectItemCaseSensitive(pledge_unavailable_to_tradeJSON, "mutual_funds");
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



    pledge_unavailable_to_trade_local_var = pledge_unavailable_to_trade_create_internal (
        equity_local_var,
        mutual_funds_local_var
        );

    if (!pledge_unavailable_to_trade_local_var) {
        goto end;
    }

    return pledge_unavailable_to_trade_local_var;
end:
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
