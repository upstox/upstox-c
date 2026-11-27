#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "margin.h"



static margin_t *margin_create_internal(
    double *span_margin,
    double *exposure_margin,
    double *equity_margin,
    double *net_buy_premium,
    double *additional_margin,
    double *total_margin,
    double *tender_margin
    ) {
    margin_t *margin_local_var = malloc(sizeof(margin_t));
    if (!margin_local_var) {
        return NULL;
    }
    memset(margin_local_var, 0, sizeof(margin_t));
    margin_local_var->_library_owned = 1;
    margin_local_var->span_margin = span_margin;
    margin_local_var->exposure_margin = exposure_margin;
    margin_local_var->equity_margin = equity_margin;
    margin_local_var->net_buy_premium = net_buy_premium;
    margin_local_var->additional_margin = additional_margin;
    margin_local_var->total_margin = total_margin;
    margin_local_var->tender_margin = tender_margin;
    return margin_local_var;
}

margin_t *margin_create(
    double *span_margin,
    double *exposure_margin,
    double *equity_margin,
    double *net_buy_premium,
    double *additional_margin,
    double *total_margin,
    double *tender_margin
    ) {
    double *span_margin_copy = NULL;
    if (span_margin) {
        span_margin_copy = malloc(sizeof(double));
        if (span_margin_copy) *span_margin_copy = *span_margin;
    }
    double *exposure_margin_copy = NULL;
    if (exposure_margin) {
        exposure_margin_copy = malloc(sizeof(double));
        if (exposure_margin_copy) *exposure_margin_copy = *exposure_margin;
    }
    double *equity_margin_copy = NULL;
    if (equity_margin) {
        equity_margin_copy = malloc(sizeof(double));
        if (equity_margin_copy) *equity_margin_copy = *equity_margin;
    }
    double *net_buy_premium_copy = NULL;
    if (net_buy_premium) {
        net_buy_premium_copy = malloc(sizeof(double));
        if (net_buy_premium_copy) *net_buy_premium_copy = *net_buy_premium;
    }
    double *additional_margin_copy = NULL;
    if (additional_margin) {
        additional_margin_copy = malloc(sizeof(double));
        if (additional_margin_copy) *additional_margin_copy = *additional_margin;
    }
    double *total_margin_copy = NULL;
    if (total_margin) {
        total_margin_copy = malloc(sizeof(double));
        if (total_margin_copy) *total_margin_copy = *total_margin;
    }
    double *tender_margin_copy = NULL;
    if (tender_margin) {
        tender_margin_copy = malloc(sizeof(double));
        if (tender_margin_copy) *tender_margin_copy = *tender_margin;
    }
    margin_t *result = margin_create_internal (
        span_margin_copy,
        exposure_margin_copy,
        equity_margin_copy,
        net_buy_premium_copy,
        additional_margin_copy,
        total_margin_copy,
        tender_margin_copy
        );
    if (!result) {
        free(span_margin_copy);
        free(exposure_margin_copy);
        free(equity_margin_copy);
        free(net_buy_premium_copy);
        free(additional_margin_copy);
        free(total_margin_copy);
        free(tender_margin_copy);
    }
    return result;
}

void margin_free(margin_t *margin) {
    if(NULL == margin){
        return ;
    }
    if(margin->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "margin_free");
        return ;
    }
    listEntry_t *listEntry;
    if (margin->span_margin) {
        free(margin->span_margin);
        margin->span_margin = NULL;
    }
    if (margin->exposure_margin) {
        free(margin->exposure_margin);
        margin->exposure_margin = NULL;
    }
    if (margin->equity_margin) {
        free(margin->equity_margin);
        margin->equity_margin = NULL;
    }
    if (margin->net_buy_premium) {
        free(margin->net_buy_premium);
        margin->net_buy_premium = NULL;
    }
    if (margin->additional_margin) {
        free(margin->additional_margin);
        margin->additional_margin = NULL;
    }
    if (margin->total_margin) {
        free(margin->total_margin);
        margin->total_margin = NULL;
    }
    if (margin->tender_margin) {
        free(margin->tender_margin);
        margin->tender_margin = NULL;
    }
    free(margin);
}

cJSON *margin_convertToJSON(margin_t *margin) {
    cJSON *item = cJSON_CreateObject();

    // margin->span_margin
    if(margin->span_margin) {
    if(cJSON_AddNumberToObject(item, "span_margin", *margin->span_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->exposure_margin
    if(margin->exposure_margin) {
    if(cJSON_AddNumberToObject(item, "exposure_margin", *margin->exposure_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->equity_margin
    if(margin->equity_margin) {
    if(cJSON_AddNumberToObject(item, "equity_margin", *margin->equity_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->net_buy_premium
    if(margin->net_buy_premium) {
    if(cJSON_AddNumberToObject(item, "net_buy_premium", *margin->net_buy_premium) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->additional_margin
    if(margin->additional_margin) {
    if(cJSON_AddNumberToObject(item, "additional_margin", *margin->additional_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->total_margin
    if(margin->total_margin) {
    if(cJSON_AddNumberToObject(item, "total_margin", *margin->total_margin) == NULL) {
    goto fail; //Numeric
    }
    }


    // margin->tender_margin
    if(margin->tender_margin) {
    if(cJSON_AddNumberToObject(item, "tender_margin", *margin->tender_margin) == NULL) {
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

margin_t *margin_parseFromJSON(cJSON *marginJSON){

    margin_t *margin_local_var = NULL;

    // define the local variable for margin->span_margin
    double *span_margin_local_var = NULL;

    // define the local variable for margin->exposure_margin
    double *exposure_margin_local_var = NULL;

    // define the local variable for margin->equity_margin
    double *equity_margin_local_var = NULL;

    // define the local variable for margin->net_buy_premium
    double *net_buy_premium_local_var = NULL;

    // define the local variable for margin->additional_margin
    double *additional_margin_local_var = NULL;

    // define the local variable for margin->total_margin
    double *total_margin_local_var = NULL;

    // define the local variable for margin->tender_margin
    double *tender_margin_local_var = NULL;

    // margin->span_margin
    cJSON *span_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "span_margin");
    if (cJSON_IsNull(span_margin)) {
        span_margin = NULL;
    }
    if (span_margin) { 
    if(!cJSON_IsNumber(span_margin))
    {
    goto end; //Numeric
    }
    span_margin_local_var = malloc(sizeof(double));
    if(!span_margin_local_var)
    {
        goto end;
    }
    *span_margin_local_var = span_margin->valuedouble;
    }

    // margin->exposure_margin
    cJSON *exposure_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "exposure_margin");
    if (cJSON_IsNull(exposure_margin)) {
        exposure_margin = NULL;
    }
    if (exposure_margin) { 
    if(!cJSON_IsNumber(exposure_margin))
    {
    goto end; //Numeric
    }
    exposure_margin_local_var = malloc(sizeof(double));
    if(!exposure_margin_local_var)
    {
        goto end;
    }
    *exposure_margin_local_var = exposure_margin->valuedouble;
    }

    // margin->equity_margin
    cJSON *equity_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "equity_margin");
    if (cJSON_IsNull(equity_margin)) {
        equity_margin = NULL;
    }
    if (equity_margin) { 
    if(!cJSON_IsNumber(equity_margin))
    {
    goto end; //Numeric
    }
    equity_margin_local_var = malloc(sizeof(double));
    if(!equity_margin_local_var)
    {
        goto end;
    }
    *equity_margin_local_var = equity_margin->valuedouble;
    }

    // margin->net_buy_premium
    cJSON *net_buy_premium = cJSON_GetObjectItemCaseSensitive(marginJSON, "net_buy_premium");
    if (cJSON_IsNull(net_buy_premium)) {
        net_buy_premium = NULL;
    }
    if (net_buy_premium) { 
    if(!cJSON_IsNumber(net_buy_premium))
    {
    goto end; //Numeric
    }
    net_buy_premium_local_var = malloc(sizeof(double));
    if(!net_buy_premium_local_var)
    {
        goto end;
    }
    *net_buy_premium_local_var = net_buy_premium->valuedouble;
    }

    // margin->additional_margin
    cJSON *additional_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "additional_margin");
    if (cJSON_IsNull(additional_margin)) {
        additional_margin = NULL;
    }
    if (additional_margin) { 
    if(!cJSON_IsNumber(additional_margin))
    {
    goto end; //Numeric
    }
    additional_margin_local_var = malloc(sizeof(double));
    if(!additional_margin_local_var)
    {
        goto end;
    }
    *additional_margin_local_var = additional_margin->valuedouble;
    }

    // margin->total_margin
    cJSON *total_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "total_margin");
    if (cJSON_IsNull(total_margin)) {
        total_margin = NULL;
    }
    if (total_margin) { 
    if(!cJSON_IsNumber(total_margin))
    {
    goto end; //Numeric
    }
    total_margin_local_var = malloc(sizeof(double));
    if(!total_margin_local_var)
    {
        goto end;
    }
    *total_margin_local_var = total_margin->valuedouble;
    }

    // margin->tender_margin
    cJSON *tender_margin = cJSON_GetObjectItemCaseSensitive(marginJSON, "tender_margin");
    if (cJSON_IsNull(tender_margin)) {
        tender_margin = NULL;
    }
    if (tender_margin) { 
    if(!cJSON_IsNumber(tender_margin))
    {
    goto end; //Numeric
    }
    tender_margin_local_var = malloc(sizeof(double));
    if(!tender_margin_local_var)
    {
        goto end;
    }
    *tender_margin_local_var = tender_margin->valuedouble;
    }



    margin_local_var = margin_create_internal (
        span_margin_local_var,
        exposure_margin_local_var,
        equity_margin_local_var,
        net_buy_premium_local_var,
        additional_margin_local_var,
        total_margin_local_var,
        tender_margin_local_var
        );

    if (!margin_local_var) {
        goto end;
    }

    return margin_local_var;
end:
    if (span_margin_local_var) {
        free(span_margin_local_var);
        span_margin_local_var = NULL;
    }
    if (exposure_margin_local_var) {
        free(exposure_margin_local_var);
        exposure_margin_local_var = NULL;
    }
    if (equity_margin_local_var) {
        free(equity_margin_local_var);
        equity_margin_local_var = NULL;
    }
    if (net_buy_premium_local_var) {
        free(net_buy_premium_local_var);
        net_buy_premium_local_var = NULL;
    }
    if (additional_margin_local_var) {
        free(additional_margin_local_var);
        additional_margin_local_var = NULL;
    }
    if (total_margin_local_var) {
        free(total_margin_local_var);
        total_margin_local_var = NULL;
    }
    if (tender_margin_local_var) {
        free(tender_margin_local_var);
        tender_margin_local_var = NULL;
    }
    return NULL;

}
