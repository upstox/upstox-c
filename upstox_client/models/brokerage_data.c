#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "brokerage_data.h"



static brokerage_data_t *brokerage_data_create_internal(
    double *total,
    double *brokerage,
    brokerage_taxes_t *taxes,
    other_taxes_t *other_taxes,
    other_taxes_t *other_charges,
    dp_plan_t *dp_plan
    ) {
    brokerage_data_t *brokerage_data_local_var = malloc(sizeof(brokerage_data_t));
    if (!brokerage_data_local_var) {
        return NULL;
    }
    memset(brokerage_data_local_var, 0, sizeof(brokerage_data_t));
    brokerage_data_local_var->_library_owned = 1;
    brokerage_data_local_var->total = total;
    brokerage_data_local_var->brokerage = brokerage;
    brokerage_data_local_var->taxes = taxes;
    brokerage_data_local_var->other_taxes = other_taxes;
    brokerage_data_local_var->other_charges = other_charges;
    brokerage_data_local_var->dp_plan = dp_plan;
    return brokerage_data_local_var;
}

brokerage_data_t *brokerage_data_create(
    double *total,
    double *brokerage,
    brokerage_taxes_t *taxes,
    other_taxes_t *other_taxes,
    other_taxes_t *other_charges,
    dp_plan_t *dp_plan
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
    brokerage_data_t *result = brokerage_data_create_internal (
        total_copy,
        brokerage_copy,
        taxes,
        other_taxes,
        other_charges,
        dp_plan
        );
    if (!result) {
        free(total_copy);
        free(brokerage_copy);
    }
    return result;
}

void brokerage_data_free(brokerage_data_t *brokerage_data) {
    if(NULL == brokerage_data){
        return ;
    }
    if(brokerage_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "brokerage_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (brokerage_data->total) {
        free(brokerage_data->total);
        brokerage_data->total = NULL;
    }
    if (brokerage_data->brokerage) {
        free(brokerage_data->brokerage);
        brokerage_data->brokerage = NULL;
    }
    if (brokerage_data->taxes) {
        brokerage_taxes_free(brokerage_data->taxes);
        brokerage_data->taxes = NULL;
    }
    if (brokerage_data->other_taxes) {
        other_taxes_free(brokerage_data->other_taxes);
        brokerage_data->other_taxes = NULL;
    }
    if (brokerage_data->other_charges) {
        other_taxes_free(brokerage_data->other_charges);
        brokerage_data->other_charges = NULL;
    }
    if (brokerage_data->dp_plan) {
        dp_plan_free(brokerage_data->dp_plan);
        brokerage_data->dp_plan = NULL;
    }
    free(brokerage_data);
}

cJSON *brokerage_data_convertToJSON(brokerage_data_t *brokerage_data) {
    cJSON *item = cJSON_CreateObject();

    // brokerage_data->total
    if(brokerage_data->total) {
    if(cJSON_AddNumberToObject(item, "total", *brokerage_data->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // brokerage_data->brokerage
    if(brokerage_data->brokerage) {
    if(cJSON_AddNumberToObject(item, "brokerage", *brokerage_data->brokerage) == NULL) {
    goto fail; //Numeric
    }
    }


    // brokerage_data->taxes
    if(brokerage_data->taxes) {
    cJSON *taxes_local_JSON = brokerage_taxes_convertToJSON(brokerage_data->taxes);
    if(taxes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "taxes", taxes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // brokerage_data->other_taxes
    if(brokerage_data->other_taxes) {
    cJSON *other_taxes_local_JSON = other_taxes_convertToJSON(brokerage_data->other_taxes);
    if(other_taxes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "otherTaxes", other_taxes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // brokerage_data->other_charges
    if(brokerage_data->other_charges) {
    cJSON *other_charges_local_JSON = other_taxes_convertToJSON(brokerage_data->other_charges);
    if(other_charges_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "other_charges", other_charges_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // brokerage_data->dp_plan
    if(brokerage_data->dp_plan) {
    cJSON *dp_plan_local_JSON = dp_plan_convertToJSON(brokerage_data->dp_plan);
    if(dp_plan_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "dp_plan", dp_plan_local_JSON);
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

brokerage_data_t *brokerage_data_parseFromJSON(cJSON *brokerage_dataJSON){

    brokerage_data_t *brokerage_data_local_var = NULL;

    // define the local variable for brokerage_data->total
    double *total_local_var = NULL;

    // define the local variable for brokerage_data->brokerage
    double *brokerage_local_var = NULL;

    // define the local variable for brokerage_data->taxes
    brokerage_taxes_t *taxes_local_nonprim = NULL;

    // define the local variable for brokerage_data->other_taxes
    other_taxes_t *other_taxes_local_nonprim = NULL;

    // define the local variable for brokerage_data->other_charges
    other_taxes_t *other_charges_local_nonprim = NULL;

    // define the local variable for brokerage_data->dp_plan
    dp_plan_t *dp_plan_local_nonprim = NULL;

    // brokerage_data->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "total");
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

    // brokerage_data->brokerage
    cJSON *brokerage = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "brokerage");
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

    // brokerage_data->taxes
    cJSON *taxes = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "taxes");
    if (cJSON_IsNull(taxes)) {
        taxes = NULL;
    }
    if (taxes) { 
    taxes_local_nonprim = brokerage_taxes_parseFromJSON(taxes); //nonprimitive
    }

    // brokerage_data->other_taxes
    cJSON *other_taxes = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "otherTaxes");
    if (cJSON_IsNull(other_taxes)) {
        other_taxes = NULL;
    }
    if (other_taxes) { 
    other_taxes_local_nonprim = other_taxes_parseFromJSON(other_taxes); //nonprimitive
    }

    // brokerage_data->other_charges
    cJSON *other_charges = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "other_charges");
    if (cJSON_IsNull(other_charges)) {
        other_charges = NULL;
    }
    if (other_charges) { 
    other_charges_local_nonprim = other_taxes_parseFromJSON(other_charges); //nonprimitive
    }

    // brokerage_data->dp_plan
    cJSON *dp_plan = cJSON_GetObjectItemCaseSensitive(brokerage_dataJSON, "dp_plan");
    if (cJSON_IsNull(dp_plan)) {
        dp_plan = NULL;
    }
    if (dp_plan) { 
    dp_plan_local_nonprim = dp_plan_parseFromJSON(dp_plan); //nonprimitive
    }



    brokerage_data_local_var = brokerage_data_create_internal (
        total_local_var,
        brokerage_local_var,
        taxes ? taxes_local_nonprim : NULL,
        other_taxes ? other_taxes_local_nonprim : NULL,
        other_charges ? other_charges_local_nonprim : NULL,
        dp_plan ? dp_plan_local_nonprim : NULL
        );

    if (!brokerage_data_local_var) {
        goto end;
    }

    return brokerage_data_local_var;
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
        brokerage_taxes_free(taxes_local_nonprim);
        taxes_local_nonprim = NULL;
    }
    if (other_taxes_local_nonprim) {
        other_taxes_free(other_taxes_local_nonprim);
        other_taxes_local_nonprim = NULL;
    }
    if (other_charges_local_nonprim) {
        other_taxes_free(other_charges_local_nonprim);
        other_charges_local_nonprim = NULL;
    }
    if (dp_plan_local_nonprim) {
        dp_plan_free(dp_plan_local_nonprim);
        dp_plan_local_nonprim = NULL;
    }
    return NULL;

}
