#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cash_margin_used.h"



static cash_margin_used_t *cash_margin_used_create_internal(
    double *total,
    double *mtf,
    loss_t *loss,
    double *span_exposure,
    double *cash_margin_var_elm,
    double *premium_present,
    delivery_margin_t *delivery_margin
    ) {
    cash_margin_used_t *cash_margin_used_local_var = malloc(sizeof(cash_margin_used_t));
    if (!cash_margin_used_local_var) {
        return NULL;
    }
    memset(cash_margin_used_local_var, 0, sizeof(cash_margin_used_t));
    cash_margin_used_local_var->_library_owned = 1;
    cash_margin_used_local_var->total = total;
    cash_margin_used_local_var->mtf = mtf;
    cash_margin_used_local_var->loss = loss;
    cash_margin_used_local_var->span_exposure = span_exposure;
    cash_margin_used_local_var->cash_margin_var_elm = cash_margin_var_elm;
    cash_margin_used_local_var->premium_present = premium_present;
    cash_margin_used_local_var->delivery_margin = delivery_margin;
    return cash_margin_used_local_var;
}

cash_margin_used_t *cash_margin_used_create(
    double *total,
    double *mtf,
    loss_t *loss,
    double *span_exposure,
    double *cash_margin_var_elm,
    double *premium_present,
    delivery_margin_t *delivery_margin
    ) {
    double *total_copy = NULL;
    if (total) {
        total_copy = malloc(sizeof(double));
        if (total_copy) *total_copy = *total;
    }
    double *mtf_copy = NULL;
    if (mtf) {
        mtf_copy = malloc(sizeof(double));
        if (mtf_copy) *mtf_copy = *mtf;
    }
    double *span_exposure_copy = NULL;
    if (span_exposure) {
        span_exposure_copy = malloc(sizeof(double));
        if (span_exposure_copy) *span_exposure_copy = *span_exposure;
    }
    double *cash_margin_var_elm_copy = NULL;
    if (cash_margin_var_elm) {
        cash_margin_var_elm_copy = malloc(sizeof(double));
        if (cash_margin_var_elm_copy) *cash_margin_var_elm_copy = *cash_margin_var_elm;
    }
    double *premium_present_copy = NULL;
    if (premium_present) {
        premium_present_copy = malloc(sizeof(double));
        if (premium_present_copy) *premium_present_copy = *premium_present;
    }
    cash_margin_used_t *result = cash_margin_used_create_internal (
        total_copy,
        mtf_copy,
        loss,
        span_exposure_copy,
        cash_margin_var_elm_copy,
        premium_present_copy,
        delivery_margin
        );
    if (!result) {
        free(total_copy);
        free(mtf_copy);
        free(span_exposure_copy);
        free(cash_margin_var_elm_copy);
        free(premium_present_copy);
    }
    return result;
}

void cash_margin_used_free(cash_margin_used_t *cash_margin_used) {
    if(NULL == cash_margin_used){
        return ;
    }
    if(cash_margin_used->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cash_margin_used_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cash_margin_used->total) {
        free(cash_margin_used->total);
        cash_margin_used->total = NULL;
    }
    if (cash_margin_used->mtf) {
        free(cash_margin_used->mtf);
        cash_margin_used->mtf = NULL;
    }
    if (cash_margin_used->loss) {
        loss_free(cash_margin_used->loss);
        cash_margin_used->loss = NULL;
    }
    if (cash_margin_used->span_exposure) {
        free(cash_margin_used->span_exposure);
        cash_margin_used->span_exposure = NULL;
    }
    if (cash_margin_used->cash_margin_var_elm) {
        free(cash_margin_used->cash_margin_var_elm);
        cash_margin_used->cash_margin_var_elm = NULL;
    }
    if (cash_margin_used->premium_present) {
        free(cash_margin_used->premium_present);
        cash_margin_used->premium_present = NULL;
    }
    if (cash_margin_used->delivery_margin) {
        delivery_margin_free(cash_margin_used->delivery_margin);
        cash_margin_used->delivery_margin = NULL;
    }
    free(cash_margin_used);
}

cJSON *cash_margin_used_convertToJSON(cash_margin_used_t *cash_margin_used) {
    cJSON *item = cJSON_CreateObject();

    // cash_margin_used->total
    if(cash_margin_used->total) {
    if(cJSON_AddNumberToObject(item, "total", *cash_margin_used->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_margin_used->mtf
    if(cash_margin_used->mtf) {
    if(cJSON_AddNumberToObject(item, "mtf", *cash_margin_used->mtf) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_margin_used->loss
    if(cash_margin_used->loss) {
    cJSON *loss_local_JSON = loss_convertToJSON(cash_margin_used->loss);
    if(loss_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "loss", loss_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cash_margin_used->span_exposure
    if(cash_margin_used->span_exposure) {
    if(cJSON_AddNumberToObject(item, "span_exposure", *cash_margin_used->span_exposure) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_margin_used->cash_margin_var_elm
    if(cash_margin_used->cash_margin_var_elm) {
    if(cJSON_AddNumberToObject(item, "cash_margin_var_elm", *cash_margin_used->cash_margin_var_elm) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_margin_used->premium_present
    if(cash_margin_used->premium_present) {
    if(cJSON_AddNumberToObject(item, "premium_present", *cash_margin_used->premium_present) == NULL) {
    goto fail; //Numeric
    }
    }


    // cash_margin_used->delivery_margin
    if(cash_margin_used->delivery_margin) {
    cJSON *delivery_margin_local_JSON = delivery_margin_convertToJSON(cash_margin_used->delivery_margin);
    if(delivery_margin_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "delivery_margin", delivery_margin_local_JSON);
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

cash_margin_used_t *cash_margin_used_parseFromJSON(cJSON *cash_margin_usedJSON){

    cash_margin_used_t *cash_margin_used_local_var = NULL;

    // define the local variable for cash_margin_used->total
    double *total_local_var = NULL;

    // define the local variable for cash_margin_used->mtf
    double *mtf_local_var = NULL;

    // define the local variable for cash_margin_used->loss
    loss_t *loss_local_nonprim = NULL;

    // define the local variable for cash_margin_used->span_exposure
    double *span_exposure_local_var = NULL;

    // define the local variable for cash_margin_used->cash_margin_var_elm
    double *cash_margin_var_elm_local_var = NULL;

    // define the local variable for cash_margin_used->premium_present
    double *premium_present_local_var = NULL;

    // define the local variable for cash_margin_used->delivery_margin
    delivery_margin_t *delivery_margin_local_nonprim = NULL;

    // cash_margin_used->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "total");
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

    // cash_margin_used->mtf
    cJSON *mtf = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "mtf");
    if (cJSON_IsNull(mtf)) {
        mtf = NULL;
    }
    if (mtf) { 
    if(!cJSON_IsNumber(mtf))
    {
    goto end; //Numeric
    }
    mtf_local_var = malloc(sizeof(double));
    if(!mtf_local_var)
    {
        goto end;
    }
    *mtf_local_var = mtf->valuedouble;
    }

    // cash_margin_used->loss
    cJSON *loss = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "loss");
    if (cJSON_IsNull(loss)) {
        loss = NULL;
    }
    if (loss) { 
    loss_local_nonprim = loss_parseFromJSON(loss); //nonprimitive
    }

    // cash_margin_used->span_exposure
    cJSON *span_exposure = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "span_exposure");
    if (cJSON_IsNull(span_exposure)) {
        span_exposure = NULL;
    }
    if (span_exposure) { 
    if(!cJSON_IsNumber(span_exposure))
    {
    goto end; //Numeric
    }
    span_exposure_local_var = malloc(sizeof(double));
    if(!span_exposure_local_var)
    {
        goto end;
    }
    *span_exposure_local_var = span_exposure->valuedouble;
    }

    // cash_margin_used->cash_margin_var_elm
    cJSON *cash_margin_var_elm = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "cash_margin_var_elm");
    if (cJSON_IsNull(cash_margin_var_elm)) {
        cash_margin_var_elm = NULL;
    }
    if (cash_margin_var_elm) { 
    if(!cJSON_IsNumber(cash_margin_var_elm))
    {
    goto end; //Numeric
    }
    cash_margin_var_elm_local_var = malloc(sizeof(double));
    if(!cash_margin_var_elm_local_var)
    {
        goto end;
    }
    *cash_margin_var_elm_local_var = cash_margin_var_elm->valuedouble;
    }

    // cash_margin_used->premium_present
    cJSON *premium_present = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "premium_present");
    if (cJSON_IsNull(premium_present)) {
        premium_present = NULL;
    }
    if (premium_present) { 
    if(!cJSON_IsNumber(premium_present))
    {
    goto end; //Numeric
    }
    premium_present_local_var = malloc(sizeof(double));
    if(!premium_present_local_var)
    {
        goto end;
    }
    *premium_present_local_var = premium_present->valuedouble;
    }

    // cash_margin_used->delivery_margin
    cJSON *delivery_margin = cJSON_GetObjectItemCaseSensitive(cash_margin_usedJSON, "delivery_margin");
    if (cJSON_IsNull(delivery_margin)) {
        delivery_margin = NULL;
    }
    if (delivery_margin) { 
    delivery_margin_local_nonprim = delivery_margin_parseFromJSON(delivery_margin); //nonprimitive
    }



    cash_margin_used_local_var = cash_margin_used_create_internal (
        total_local_var,
        mtf_local_var,
        loss ? loss_local_nonprim : NULL,
        span_exposure_local_var,
        cash_margin_var_elm_local_var,
        premium_present_local_var,
        delivery_margin ? delivery_margin_local_nonprim : NULL
        );

    if (!cash_margin_used_local_var) {
        goto end;
    }

    return cash_margin_used_local_var;
end:
    if (total_local_var) {
        free(total_local_var);
        total_local_var = NULL;
    }
    if (mtf_local_var) {
        free(mtf_local_var);
        mtf_local_var = NULL;
    }
    if (loss_local_nonprim) {
        loss_free(loss_local_nonprim);
        loss_local_nonprim = NULL;
    }
    if (span_exposure_local_var) {
        free(span_exposure_local_var);
        span_exposure_local_var = NULL;
    }
    if (cash_margin_var_elm_local_var) {
        free(cash_margin_var_elm_local_var);
        cash_margin_var_elm_local_var = NULL;
    }
    if (premium_present_local_var) {
        free(premium_present_local_var);
        premium_present_local_var = NULL;
    }
    if (delivery_margin_local_nonprim) {
        delivery_margin_free(delivery_margin_local_nonprim);
        delivery_margin_local_nonprim = NULL;
    }
    return NULL;

}
