#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "profit_and_loss_charges_data.h"



static profit_and_loss_charges_data_t *profit_and_loss_charges_data_create_internal(
    double *total,
    double *brokerage,
    profit_and_loss_charges_taxes_t *taxes,
    profit_and_loss_other_charges_taxes_t *charges
    ) {
    profit_and_loss_charges_data_t *profit_and_loss_charges_data_local_var = malloc(sizeof(profit_and_loss_charges_data_t));
    if (!profit_and_loss_charges_data_local_var) {
        return NULL;
    }
    memset(profit_and_loss_charges_data_local_var, 0, sizeof(profit_and_loss_charges_data_t));
    profit_and_loss_charges_data_local_var->_library_owned = 1;
    profit_and_loss_charges_data_local_var->total = total;
    profit_and_loss_charges_data_local_var->brokerage = brokerage;
    profit_and_loss_charges_data_local_var->taxes = taxes;
    profit_and_loss_charges_data_local_var->charges = charges;
    return profit_and_loss_charges_data_local_var;
}

profit_and_loss_charges_data_t *profit_and_loss_charges_data_create(
    double *total,
    double *brokerage,
    profit_and_loss_charges_taxes_t *taxes,
    profit_and_loss_other_charges_taxes_t *charges
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    double *brokerage_copy = NULL;
    if (brokerage) {
        brokerage_copy = malloc(sizeof(double));
        if (brokerage_copy) *brokerage_copy = *brokerage;
    }
    profit_and_loss_charges_data_t *result = profit_and_loss_charges_data_create_internal (
        total_copy,
        brokerage_copy,
        taxes,
        charges
        );
    if (!result) {
        free(total_copy);
        free(brokerage_copy);
    }
    return result;
}

void profit_and_loss_charges_data_free(profit_and_loss_charges_data_t *profit_and_loss_charges_data) {
    if(NULL == profit_and_loss_charges_data){
        return ;
    }
    if(profit_and_loss_charges_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "profit_and_loss_charges_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (profit_and_loss_charges_data->total) {
        free(profit_and_loss_charges_data->total);
        profit_and_loss_charges_data->total = NULL;
    }
    if (profit_and_loss_charges_data->brokerage) {
        free(profit_and_loss_charges_data->brokerage);
        profit_and_loss_charges_data->brokerage = NULL;
    }
    if (profit_and_loss_charges_data->taxes) {
        profit_and_loss_charges_taxes_free(profit_and_loss_charges_data->taxes);
        profit_and_loss_charges_data->taxes = NULL;
    }
    if (profit_and_loss_charges_data->charges) {
        profit_and_loss_other_charges_taxes_free(profit_and_loss_charges_data->charges);
        profit_and_loss_charges_data->charges = NULL;
    }
    free(profit_and_loss_charges_data);
}

cJSON *profit_and_loss_charges_data_convertToJSON(profit_and_loss_charges_data_t *profit_and_loss_charges_data) {
    cJSON *item = cJSON_CreateObject();

    // profit_and_loss_charges_data->total
    if(profit_and_loss_charges_data->total) {
    if(cJSON_AddNumberToObject(item, "total", *profit_and_loss_charges_data->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_charges_data->brokerage
    if(profit_and_loss_charges_data->brokerage) {
    if(cJSON_AddNumberToObject(item, "brokerage", *profit_and_loss_charges_data->brokerage) == NULL) {
    goto fail; //Numeric
    }
    }


    // profit_and_loss_charges_data->taxes
    if(profit_and_loss_charges_data->taxes) {
    cJSON *taxes_local_JSON = profit_and_loss_charges_taxes_convertToJSON(profit_and_loss_charges_data->taxes);
    if(taxes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "taxes", taxes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // profit_and_loss_charges_data->charges
    if(profit_and_loss_charges_data->charges) {
    cJSON *charges_local_JSON = profit_and_loss_other_charges_taxes_convertToJSON(profit_and_loss_charges_data->charges);
    if(charges_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "charges", charges_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

profit_and_loss_charges_data_t *profit_and_loss_charges_data_parseFromJSON(cJSON *profit_and_loss_charges_dataJSON){

    profit_and_loss_charges_data_t *profit_and_loss_charges_data_local_var = NULL;

    // define the local variable for profit_and_loss_charges_data->total
    double *total_local_var = NULL;

    // define the local variable for profit_and_loss_charges_data->brokerage
    double *brokerage_local_var = NULL;

    // define the local variable for profit_and_loss_charges_data->taxes
    profit_and_loss_charges_taxes_t *taxes_local_nonprim = NULL;

    // define the local variable for profit_and_loss_charges_data->charges
    profit_and_loss_other_charges_taxes_t *charges_local_nonprim = NULL;

    // profit_and_loss_charges_data->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_dataJSON, "total");
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

    // profit_and_loss_charges_data->brokerage
    cJSON *brokerage = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_dataJSON, "brokerage");
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

    // profit_and_loss_charges_data->taxes
    cJSON *taxes = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_dataJSON, "taxes");
    if (cJSON_IsNull(taxes)) {
        taxes = NULL;
    }
    if (taxes) { 
    taxes_local_nonprim = profit_and_loss_charges_taxes_parseFromJSON(taxes); //nonprimitive
    }

    // profit_and_loss_charges_data->charges
    cJSON *charges = cJSON_GetObjectItemCaseSensitive(profit_and_loss_charges_dataJSON, "charges");
    if (cJSON_IsNull(charges)) {
        charges = NULL;
    }
    if (charges) { 
    charges_local_nonprim = profit_and_loss_other_charges_taxes_parseFromJSON(charges); //nonprimitive
    }



    profit_and_loss_charges_data_local_var = profit_and_loss_charges_data_create_internal (
        total_local_var,
        brokerage_local_var,
        taxes ? taxes_local_nonprim : NULL,
        charges ? charges_local_nonprim : NULL
        );

    if (!profit_and_loss_charges_data_local_var) {
        goto end;
    }

    return profit_and_loss_charges_data_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (brokerage_local_var) {
        free(brokerage_local_var);
        brokerage_local_var = NULL;
    }
    if (taxes_local_nonprim) {
        profit_and_loss_charges_taxes_free(taxes_local_nonprim);
        taxes_local_nonprim = NULL;
    }
    if (charges_local_nonprim) {
        profit_and_loss_other_charges_taxes_free(charges_local_nonprim);
        charges_local_nonprim = NULL;
    }
    return NULL;

}
