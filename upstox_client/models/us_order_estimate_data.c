#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "us_order_estimate_data.h"



static us_order_estimate_data_t *us_order_estimate_data_create_internal(
    double *brokerage,
    double *gst,
    double *trade_value,
    double *regulatory_fee,
    double *taf_fee,
    double *cat_fee,
    double *total_charges,
    double *estimated_total
    ) {
    us_order_estimate_data_t *us_order_estimate_data_local_var = malloc(sizeof(us_order_estimate_data_t));
    if (!us_order_estimate_data_local_var) {
        return NULL;
    }
    memset(us_order_estimate_data_local_var, 0, sizeof(us_order_estimate_data_t));
    us_order_estimate_data_local_var->_library_owned = 1;
    us_order_estimate_data_local_var->brokerage = brokerage;
    us_order_estimate_data_local_var->gst = gst;
    us_order_estimate_data_local_var->trade_value = trade_value;
    us_order_estimate_data_local_var->regulatory_fee = regulatory_fee;
    us_order_estimate_data_local_var->taf_fee = taf_fee;
    us_order_estimate_data_local_var->cat_fee = cat_fee;
    us_order_estimate_data_local_var->total_charges = total_charges;
    us_order_estimate_data_local_var->estimated_total = estimated_total;
    return us_order_estimate_data_local_var;
}

us_order_estimate_data_t *us_order_estimate_data_create(
    double *brokerage,
    double *gst,
    double *trade_value,
    double *regulatory_fee,
    double *taf_fee,
    double *cat_fee,
    double *total_charges,
    double *estimated_total
    ) {
    double *brokerage_copy = NULL;
    if (brokerage) {
        brokerage_copy = malloc(sizeof(double));
        if (brokerage_copy) *brokerage_copy = *brokerage;
    }
    double *gst_copy = NULL;
    if (gst) {
        gst_copy = malloc(sizeof(double));
        if (gst_copy) *gst_copy = *gst;
    }
    double *trade_value_copy = NULL;
    if (trade_value) {
        trade_value_copy = malloc(sizeof(double));
        if (trade_value_copy) *trade_value_copy = *trade_value;
    }
    double *regulatory_fee_copy = NULL;
    if (regulatory_fee) {
        regulatory_fee_copy = malloc(sizeof(double));
        if (regulatory_fee_copy) *regulatory_fee_copy = *regulatory_fee;
    }
    double *taf_fee_copy = NULL;
    if (taf_fee) {
        taf_fee_copy = malloc(sizeof(double));
        if (taf_fee_copy) *taf_fee_copy = *taf_fee;
    }
    double *cat_fee_copy = NULL;
    if (cat_fee) {
        cat_fee_copy = malloc(sizeof(double));
        if (cat_fee_copy) *cat_fee_copy = *cat_fee;
    }
    double *total_charges_copy = NULL;
    if (total_charges) {
        total_charges_copy = malloc(sizeof(double));
        if (total_charges_copy) *total_charges_copy = *total_charges;
    }
    double *estimated_total_copy = NULL;
    if (estimated_total) {
        estimated_total_copy = malloc(sizeof(double));
        if (estimated_total_copy) *estimated_total_copy = *estimated_total;
    }
    us_order_estimate_data_t *result = us_order_estimate_data_create_internal (
        brokerage_copy,
        gst_copy,
        trade_value_copy,
        regulatory_fee_copy,
        taf_fee_copy,
        cat_fee_copy,
        total_charges_copy,
        estimated_total_copy
        );
    if (!result) {
        free(brokerage_copy);
        free(gst_copy);
        free(trade_value_copy);
        free(regulatory_fee_copy);
        free(taf_fee_copy);
        free(cat_fee_copy);
        free(total_charges_copy);
        free(estimated_total_copy);
    }
    return result;
}

void us_order_estimate_data_free(us_order_estimate_data_t *us_order_estimate_data) {
    if(NULL == us_order_estimate_data){
        return ;
    }
    if(us_order_estimate_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "us_order_estimate_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (us_order_estimate_data->brokerage) {
        free(us_order_estimate_data->brokerage);
        us_order_estimate_data->brokerage = NULL;
    }
    if (us_order_estimate_data->gst) {
        free(us_order_estimate_data->gst);
        us_order_estimate_data->gst = NULL;
    }
    if (us_order_estimate_data->trade_value) {
        free(us_order_estimate_data->trade_value);
        us_order_estimate_data->trade_value = NULL;
    }
    if (us_order_estimate_data->regulatory_fee) {
        free(us_order_estimate_data->regulatory_fee);
        us_order_estimate_data->regulatory_fee = NULL;
    }
    if (us_order_estimate_data->taf_fee) {
        free(us_order_estimate_data->taf_fee);
        us_order_estimate_data->taf_fee = NULL;
    }
    if (us_order_estimate_data->cat_fee) {
        free(us_order_estimate_data->cat_fee);
        us_order_estimate_data->cat_fee = NULL;
    }
    if (us_order_estimate_data->total_charges) {
        free(us_order_estimate_data->total_charges);
        us_order_estimate_data->total_charges = NULL;
    }
    if (us_order_estimate_data->estimated_total) {
        free(us_order_estimate_data->estimated_total);
        us_order_estimate_data->estimated_total = NULL;
    }
    free(us_order_estimate_data);
}

cJSON *us_order_estimate_data_convertToJSON(us_order_estimate_data_t *us_order_estimate_data) {
    cJSON *item = cJSON_CreateObject();

    // us_order_estimate_data->brokerage
    if(us_order_estimate_data->brokerage) {
    if(cJSON_AddNumberToObject(item, "brokerage", *us_order_estimate_data->brokerage) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->gst
    if(us_order_estimate_data->gst) {
    if(cJSON_AddNumberToObject(item, "gst", *us_order_estimate_data->gst) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->trade_value
    if(us_order_estimate_data->trade_value) {
    if(cJSON_AddNumberToObject(item, "trade_value", *us_order_estimate_data->trade_value) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->regulatory_fee
    if(us_order_estimate_data->regulatory_fee) {
    if(cJSON_AddNumberToObject(item, "regulatory_fee", *us_order_estimate_data->regulatory_fee) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->taf_fee
    if(us_order_estimate_data->taf_fee) {
    if(cJSON_AddNumberToObject(item, "taf_fee", *us_order_estimate_data->taf_fee) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->cat_fee
    if(us_order_estimate_data->cat_fee) {
    if(cJSON_AddNumberToObject(item, "cat_fee", *us_order_estimate_data->cat_fee) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->total_charges
    if(us_order_estimate_data->total_charges) {
    if(cJSON_AddNumberToObject(item, "total_charges", *us_order_estimate_data->total_charges) == NULL) {
    goto fail; //Numeric
    }
    }


    // us_order_estimate_data->estimated_total
    if(us_order_estimate_data->estimated_total) {
    if(cJSON_AddNumberToObject(item, "estimated_total", *us_order_estimate_data->estimated_total) == NULL) {
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

us_order_estimate_data_t *us_order_estimate_data_parseFromJSON(cJSON *us_order_estimate_dataJSON){

    us_order_estimate_data_t *us_order_estimate_data_local_var = NULL;

    // define the local variable for us_order_estimate_data->brokerage
    double *brokerage_local_var = NULL;

    // define the local variable for us_order_estimate_data->gst
    double *gst_local_var = NULL;

    // define the local variable for us_order_estimate_data->trade_value
    double *trade_value_local_var = NULL;

    // define the local variable for us_order_estimate_data->regulatory_fee
    double *regulatory_fee_local_var = NULL;

    // define the local variable for us_order_estimate_data->taf_fee
    double *taf_fee_local_var = NULL;

    // define the local variable for us_order_estimate_data->cat_fee
    double *cat_fee_local_var = NULL;

    // define the local variable for us_order_estimate_data->total_charges
    double *total_charges_local_var = NULL;

    // define the local variable for us_order_estimate_data->estimated_total
    double *estimated_total_local_var = NULL;

    // us_order_estimate_data->brokerage
    cJSON *brokerage = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "brokerage");
    if (cJSON_IsNull(brokerage)) {
        brokerage = NULL;
    }
    if (brokerage) { 
    if(!cJSON_IsNumber(brokerage))
    {
    goto end; //Numeric
    }
    brokerage_local_var = malloc(sizeof(double));
    if(!brokerage_local_var)
    {
        goto end;
    }
    *brokerage_local_var = brokerage->valuedouble;
    }

    // us_order_estimate_data->gst
    cJSON *gst = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "gst");
    if (cJSON_IsNull(gst)) {
        gst = NULL;
    }
    if (gst) { 
    if(!cJSON_IsNumber(gst))
    {
    goto end; //Numeric
    }
    gst_local_var = malloc(sizeof(double));
    if(!gst_local_var)
    {
        goto end;
    }
    *gst_local_var = gst->valuedouble;
    }

    // us_order_estimate_data->trade_value
    cJSON *trade_value = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "trade_value");
    if (cJSON_IsNull(trade_value)) {
        trade_value = NULL;
    }
    if (trade_value) { 
    if(!cJSON_IsNumber(trade_value))
    {
    goto end; //Numeric
    }
    trade_value_local_var = malloc(sizeof(double));
    if(!trade_value_local_var)
    {
        goto end;
    }
    *trade_value_local_var = trade_value->valuedouble;
    }

    // us_order_estimate_data->regulatory_fee
    cJSON *regulatory_fee = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "regulatory_fee");
    if (cJSON_IsNull(regulatory_fee)) {
        regulatory_fee = NULL;
    }
    if (regulatory_fee) { 
    if(!cJSON_IsNumber(regulatory_fee))
    {
    goto end; //Numeric
    }
    regulatory_fee_local_var = malloc(sizeof(double));
    if(!regulatory_fee_local_var)
    {
        goto end;
    }
    *regulatory_fee_local_var = regulatory_fee->valuedouble;
    }

    // us_order_estimate_data->taf_fee
    cJSON *taf_fee = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "taf_fee");
    if (cJSON_IsNull(taf_fee)) {
        taf_fee = NULL;
    }
    if (taf_fee) { 
    if(!cJSON_IsNumber(taf_fee))
    {
    goto end; //Numeric
    }
    taf_fee_local_var = malloc(sizeof(double));
    if(!taf_fee_local_var)
    {
        goto end;
    }
    *taf_fee_local_var = taf_fee->valuedouble;
    }

    // us_order_estimate_data->cat_fee
    cJSON *cat_fee = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "cat_fee");
    if (cJSON_IsNull(cat_fee)) {
        cat_fee = NULL;
    }
    if (cat_fee) { 
    if(!cJSON_IsNumber(cat_fee))
    {
    goto end; //Numeric
    }
    cat_fee_local_var = malloc(sizeof(double));
    if(!cat_fee_local_var)
    {
        goto end;
    }
    *cat_fee_local_var = cat_fee->valuedouble;
    }

    // us_order_estimate_data->total_charges
    cJSON *total_charges = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "total_charges");
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

    // us_order_estimate_data->estimated_total
    cJSON *estimated_total = cJSON_GetObjectItemCaseSensitive(us_order_estimate_dataJSON, "estimated_total");
    if (cJSON_IsNull(estimated_total)) {
        estimated_total = NULL;
    }
    if (estimated_total) { 
    if(!cJSON_IsNumber(estimated_total))
    {
    goto end; //Numeric
    }
    estimated_total_local_var = malloc(sizeof(double));
    if(!estimated_total_local_var)
    {
        goto end;
    }
    *estimated_total_local_var = estimated_total->valuedouble;
    }



    us_order_estimate_data_local_var = us_order_estimate_data_create_internal (
        brokerage_local_var,
        gst_local_var,
        trade_value_local_var,
        regulatory_fee_local_var,
        taf_fee_local_var,
        cat_fee_local_var,
        total_charges_local_var,
        estimated_total_local_var
        );

    if (!us_order_estimate_data_local_var) {
        goto end;
    }

    return us_order_estimate_data_local_var;
end:
    if (brokerage_local_var) {
        free(brokerage_local_var);
        brokerage_local_var = NULL;
    }
    if (gst_local_var) {
        free(gst_local_var);
        gst_local_var = NULL;
    }
    if (trade_value_local_var) {
        free(trade_value_local_var);
        trade_value_local_var = NULL;
    }
    if (regulatory_fee_local_var) {
        free(regulatory_fee_local_var);
        regulatory_fee_local_var = NULL;
    }
    if (taf_fee_local_var) {
        free(taf_fee_local_var);
        taf_fee_local_var = NULL;
    }
    if (cat_fee_local_var) {
        free(cat_fee_local_var);
        cat_fee_local_var = NULL;
    }
    if (total_charges_local_var) {
        free(total_charges_local_var);
        total_charges_local_var = NULL;
    }
    if (estimated_total_local_var) {
        free(estimated_total_local_var);
        estimated_total_local_var = NULL;
    }
    return NULL;

}
